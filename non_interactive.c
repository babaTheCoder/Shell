#include "shell.h"
#define MAX_ARGS 10 /* Maximum number of arguments for the command */

/**
* run_non_interactive_mode - Execute the program in non-interactive mode.
* @filename: The name of the file to process
*
* Description: This function handles the execution of the program
* in non-interactive mode based on the provided argument.
**/

void run_non_interactive_mode(const char *filename)
{
	FILE *file;
	char *line;
	size_t len = 0;

	file = open_file(filename);
	if (file == NULL)
	{
		return;
	}

	while ((line = process_line(line, len, file)) != NULL)
	{
		execute_nonint_command(line);
	}

	free(line);
	fclose(file);
}
/**
 * execute_nonint_command - runs commands in non-interactive mode
 * @line: command to run
 *
 * Return: nothing
 */

void execute_nonint_command(char *line)
{
	char *command;
	char *args[MAX_ARGS + 1];
	int arg_count;
	int status;
	pid_t pid;

	/* Tokenize the line into command and arguments */
	command = strtok(line, " \t");
	arg_count = 0;
	while (command != NULL && arg_count < MAX_ARGS)
	{
		args[arg_count++] = command;
		command = strtok(NULL, " \t");
	}
	args[arg_count] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

/**
 * process_line - reads user input
 *
 * @line: user input
 * @len: size of user input
 * @file: file to read
 * Return: array of characters
 */

char *process_line(char *line, size_t len, FILE *file)
{
	ssize_t read = getline(&line, &len, file);

	if (read == -1)
	{
		return (NULL);
	}

	null_after_comment(line, custom_strlen(line));
	if (line[read - 1] == '\0')
	{
		write(STDOUT_FILENO, "\n", 1);
		return (NULL);
	}
	/* Remove the trailing newline character, if any */
	if (line[read - 1] == '\n')
		line[read - 1] = '\0';

	/*nullify*/
	nullify_after_comment(line);
	if (custom_strcmp(line, "/bin/echo ") == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (NULL);
	}

	return (line);
}

/**
 * open_file - opens a file to read commands from
 *
 * @filename: name of file to open
 *
 * Return: an open file
 */

FILE *open_file(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		perror("fopen");
		return (NULL);
	}
	return (file);
}

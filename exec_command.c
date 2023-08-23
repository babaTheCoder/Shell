#include "shell.h"

#define MAX_ARGS 10 /* Maximum number of arguments for the command */
/**
 * execute_exit_command - exit the shell when user inputs 'exit'
 *
 * @args: user input
 *
 * Return: -1 on failure or exits the shell on success
 */

int execute_exit_command(char **args)
{
	if (custom_strcmp(args[0], "exit") == 0)
	{
		return (execute_exit(args));
	}

	return (-1);
}
/**
 * nullify_command - Nullify the line after the '#' character
 *
 * @command: entered command or user input
 * Return: nothing
 */

void nullify_command(char *command)
{
	nullify_after_comment(command);

	if (command[0] == '\0')
	{
		return;
	}

	null_after_comment(command, custom_strlen(command));
}

/**
 * echo_command - checks whether entered command is 'echo'
 *
 * @command: user input
 *
 * Return: -1 if command is not echo
 */

int echo_command(char *command)
{
	if (custom_strncmp(command, "/bin/echo #", 11) == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (0);
	}

	return (-1);
}

/**
 * execute_absolute_path_command - runs command when absolute path is given
 *
 * @command: user command
 * @args: arguments passed to command
 *
 * Return: -1 on success or 1 on failure
 */

int execute_absolute_path_command(char *command, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0)
	{
		execve(command, args, environ);
		perror("Absolute path");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (-1);
}

/**
 * execute_relative_path_command - runs commands without absolute path
 *
 * @command: user command entered
 * @args: arguments passed to command
 * Return: 1 on failure or -1 on success
 */

int execute_relative_path_command(char *command, char **args)
{
	pid_t pid;
	int status;
	char *command_path;

	if (!command_exists(command))
	{
		perror("command");
		return (1);
	}

	command_path = resolve_command_path(command);
	if (command_path == NULL)
	{
		perror("command");
		return (1);
	}
	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		free(command_path);
		return (1);
	}
	else if (pid == 0)
	{
		execve(command_path, args, environ);
		perror("execve");
		free(command_path);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		free(command_path);
	}

	return (-1);
}

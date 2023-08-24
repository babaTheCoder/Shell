#include "shell.h"

#define MAX_ARGS 10 /* Maximum number of arguments for the command */


/**
* display_prompt - Display the shell prompt
**/
void display_prompt(void)
{
	int is_interactive;

	is_interactive = 0;/* Flag to indicate interactive mode */
	if (is_interactive)
		write(STDOUT_FILENO, "Mark>> ", 7);
}

/**
 * null_after_comment - nullifies an input after the '#' sign
 *
 * @str: input
 * @length: length of string
 */
void null_after_comment(char *str, size_t length)
{
	/* Locate the '#' symbol */
	char *comment_pos;
	size_t comment_index;

	comment_pos = custom_strchr(str, '#');
	if (comment_pos != NULL)
	{
		/* Nullify the rest of the string after the '#' symbol */
		comment_index = comment_pos - str;
		if (comment_index < length)
		{
			str[comment_index] = '\0';
		}
	}
}


/**
* execute_interactive_mode - Execute the program in interactive mode.
*
* Description: This function handles the execution of the program
* in interactive mode, allowing user interaction and input.
**/

void execute_interactive_mode(void)
{
	char *input = NULL;
	size_t bufsize = 0;
	char *args[MAX_ARGS + 2]; /* Array to hold the command and its arguments */
	int i = 0;
	int is_interactive;

	while (1)
	{
		is_interactive = 0;
		/* Flag to indicate interactive mode */
		if (is_interactive)
			write(STDOUT_FILENO, "Mark>> ", 7);
		/*display_prompt();*/
		read_input(&input, &bufsize);

		if (is_empty_input(input))
			continue;

		if (compareStrings(input, "env") == 0)
		{
			print_environment_variables();
			continue;
		}

		i = 0;
		args[i] = strtok(input, " \t");

		while (args[i] != NULL && i < MAX_ARGS)
			args[++i] = strtok(NULL, " \t");
		args[i] = NULL;
		execute_command(args[0], args);
	}
	/* Free dynamically allocated memory, if any */
	free(input);
}

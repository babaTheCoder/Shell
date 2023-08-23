#include "shell.h"

/**
 * execute_command - runs user inputs
 *
 * @command: user command entered
 * @args: command arguments
 *
 * Return: 0 on success | -1 on failure
 */

int execute_command(char *command, char **args)
{
	if (execute_exit_command(args) == 0)
	{
		return (0);
	}

	nullify_command(command);

	if (echo_command(command) == 0)
	{
		return (0);
	}

	if (command[0] == '/')
	{
		return (execute_absolute_path_command(command, args));
	}
	else
	{
		return (execute_relative_path_command(command, args));
	}

	return (-1);
}

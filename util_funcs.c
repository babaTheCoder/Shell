#include "shell.h"


/**
 * path_exists - Check if a path exists.
 * @path: The path to check.
 *
 * Return: 1 if the path exists, 0 otherwise.
 */

int path_exists(const char *path)
{
	if (access(path, F_OK) != -1)
		return (1); /* Path exists */
	else
		return (0); /* Path does not exist */
}


/**
 * execute_exit - Executes the "exit" command to terminate the shell.
 * @args: List of arguments, where args[0] is "exit" command and
 * args[1] (if present) is the exit status.
 *
 * Return: None.
 */

int execute_exit(char **args)
{
	int exit_status;

	if (args[1] != NULL)
	{
		exit_status = custom_atoi(args[1]);
		exit(exit_status);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}

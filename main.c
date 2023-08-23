#include "shell.h"

#define MAX_ARGS 10 /* Maximum number of arguments for the command */
#define MAX_FILENAME_LENGTH 256

/**
* main - Entry point of the program
* @argc: The number of command-line arguments
* @argv: An array of strings containing the arguments
*
* Return: Always 0 (indicating successful execution)
**/

int main(int argc, char **argv)
{
int is_interactive;
const char *filename;

if (argc == 1)
{
/* Interactive mode */
execute_interactive_mode();
}
else if (argc == 2)
{
/* Non-interactive mode */
is_interactive = 0;
/* Flag to indicate interactive mode */
if (is_interactive)
write(STDOUT_FILENO, "Mark>> ", 7);

filename = argv[1];
run_non_interactive_mode(filename);
}
else
{
perror("non-interactive mode");
return (EXIT_FAILURE);
}

return (EXIT_SUCCESS);
}


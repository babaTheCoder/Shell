#include "shell.h"

/**
* custom_strchr - Locate character in string
* @str: The string to search
* @c: The character to find
*
* Return: Pointer to the first occurrence of the character in the string,
*         or NULL if the character is not found
*/
char *custom_strchr(const char *str, int c)
{
while (*str != '\0')
{
if (*str == c)
return (char *)str
str++;
}
return (NULL);
}

/**
* nullify_after_comment - Nullify the portion of the string after a comment
* @str: The string to modify
*
* Description:
*   This function finds the occurrence of '#' character in the string and
*   nullifies the portion of the string after the '#' character, effectively
*   removing the comment.
*/
void nullify_after_comment(char *str)
{
char *comment_pos;

comment_pos = custom_strchr(str, '#');

if (comment_pos != NULL)
*comment_pos = '\0';
}

/**
 * compareStrings - Compare two strings and return the result.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: The result of the string comparison.
 */

int compareStrings(const char *str1, const char *str2)
{
while (*str1 && *str2)
{
if (*str1 != *str2)
return (*str1 - *str2);

str1++;
str2++;
}
return (*str1 - *str2);
}

/**
 * calculateLength - Calculate the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */

size_t calculateLength(const char *str)
{
size_t length = 0;
while (*str)
{
length++;
str++;
}
return (length);
}

/**
 * command_exists - Check if a command exists.
 * @command: The command to check.
 *
 * Return: 1 if the command exists, 0 otherwise.
 */

int command_exists(const char *command)
{
/* Resolve the command path */
char *command_path = resolve_command_path(command);
if (command_path == NULL)
return (0); /* Command not found */

/* Free the allocated memory */
free(command_path);
return (1); /* Command exists */
}

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

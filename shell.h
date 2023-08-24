#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern char **environ; /* Access the environment variables */

/**
 * is_empty_input - Check if the input string is empty.
 * @input: The input string.
 *
 * Return: 1 if the input is empty, 0 otherwise.
 */
int is_empty_input(const char *input);

/**
 * resolve_command_path - Resolve the full path of a command.
 * @command: The command to resolve.
 *
 * Return: A pointer to the resolved command path on success
 * or NULL on failure.
 */
char *resolve_command_path(const char *command);

/**
 * search_command_path - Search for the full path of a command.
 * @command: The command to resolve.
 * @path: The path
 * Return: A pointer to the resolved command path on success
 * or NULL on failure.
 */
char *search_command_path(const char *command, const char *path);

/**
 * custom_getenv - Retrieves the value of the specified environment variable.
 *
 * @name: The name of the environment variable.
 * Return: The value of the environment variable if found, NULL otherwise.
 */
char *custom_getenv(const char *name);

/**
 * create_command_path - Full path of a command.
 * @command: The command to resolve.
 * @directory: The directory
 *
 * Return: A pointer to the resolved command path on success
 * or NULL on failure.
 **/
char *create_command_path(const char *directory, const char *command);

/**
 * build_command_path - Build the command path by
 * concatenating directory and command.
 * @directory: The directory to concatenate.
 * @command: The command to concatenate.
 *
 * Return: A pointer to the concatenated command path on success
 * or NULL on failure.
 **/
char *build_command_path(const char *directory, const char *command);

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void);

/**
 * read_user_input - Read user input from stdin.
 * @input: Pointer to the input buffer.
 * @bufsize: Pointer to the buffer size.
 * Return: The number of characters read.
 */
ssize_t read_user_input(char **input, size_t *bufsize);

/**
 * is_exit_command - Check if the input is the "exit" command.
 * @input: The input string.
 * Return: 1 if the input is the "exit" command, 0 otherwise.
 */
int is_exit_command(const char *input);


/**
 * is_env_command - Check if the input is the "env" command.
 * @input: The input string.
 * Return: 1 if the input is the "env" command, 0 otherwise.
 */
int is_env_command(const char *input);


/**
 * print_environment_variables - Print environment variables.
 */
void print_environment_variables(void);


/**
 * parse_input - Parse the user input into command and arguments.
 * @input: The user input string.
 * @args: The array to hold the command and arguments.
 * Return: The number of arguments parsed.
 */
void parse_input(char *input, char *args[]);

/**
 * path_exists - Check if a path exists.
 * @path: The path to check.
 *
 * Return: 1 if the path exists, 0 otherwise.
 */

int path_exists(const char *path);

/**
 * command_exists - Check if a command exists.
 * @command: The command to check.
 *
 * Return: 1 if the command exists, 0 otherwise.
 */

int command_exists(const char *command);

/**
 * calculateLength - Calculate the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */

size_t calculateLength(const char *str);

/**
 * compareStrings - Compare two strings and return the result.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: The result of the string comparison.
 */

int compareStrings(const char *str1, const char *str2);


void read_input(char **input, size_t *bufsize);


void print_environment_variables(void);

void check_and_execute_absolute_path(char *command, char *args[]);

void display_prompt(void);

int execute_command(char *command, char **args);

int execute_relative_path_command(char *command, char **args);

int execute_absolute_path_command(char *command, char **args);

int echo_command(char *command);

void nullify_command(char *command);

int execute_exit_command(char **args);

int path_exists(const char *path);

int execute_exit(char **args);

void run_non_interactive_mode(const char *filename);

void execute_nonint_command(char *line);

char *process_line(char *line, size_t len, FILE *file);

FILE *open_file(const char *filename);

/**
 * custom_strlen - Calculate the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
size_t custom_strlen(const char *str);

/**
 * custom_strcmp - Compare two strings.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: An integer less than, equal to
 * or greater than zero if str1 is found,
 * respectively, to be less than, to match, or be greater than str2.
 */
int custom_strcmp(const char *str1, const char *str2);

/**
 * custom_strdup - Duplicate a string.
 * @str: The input string.
 *
 * Return: A pointer to the newly allocated duplicate string.
 */
char *custom_strdup(const char *str);

/**
 * custom_strcat - Concatenate two strings.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: A pointer to the newly allocated string
 * containing the concatenated strings.
 */
char *custom_strcat(const char *str1, const char *str2);

/**
 * custom_strncmp - Compare at most n characters of two strings
 * @str1: The first string to compare
 * @str2: The second string to compare
 * @n: The maximum number of characters to compare
 *
 * Return: 0 if the strings are equal, a negative value if str1 is less than
 * str2, or a positive value if str1 is greater than str2
 */
int custom_strncmp(const char *str1, const char *str2, size_t n);

void execute_interactive_mode(void);


void run_non_interactive_mode(const char *filename);

int execute_command(char *command, char **args);

int custom_atoi(const char *str);

char *custom_strchr(const char *str, int c);

void nullify_after_comment(char *str);

void null_after_comment(char *str, size_t length);

int execute_exit(char **args);


#endif /* SHELL_H */

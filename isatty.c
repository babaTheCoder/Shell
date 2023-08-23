#include "shell.h"

#define MAX_ARGS 10 /* Maximum number of arguments for the command */


/**
* display_prompt - Display the shell prompt
**/
void display_prompt(void)

{
int is_interactive;
is_interactive = 0;  /* Flag to indicate interactive mode */
if (is_interactive)
write(STDOUT_FILENO, "Mark>> ", 7);
}


void null_after_comment(char *str, size_t length) 
{
	/* Locate the '#' symbol */
	char *comment_pos;
	size_t comment_index;

	comment_pos = custom_strchr(str, '#');
	if (comment_pos != NULL) {
		/* Nullify the rest of the string after the '#' symbol */
		comment_index = comment_pos - str;
		if (comment_index < length)
			str[comment_index] = '\0';
	}

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
* run_non_interactive_mode - Execute the program in non-interactive mode.
* @filename: The name of the file to process
*
* Description: This function handles the execution of the program
* in non-interactive mode based on the provided argument.
**/
void run_non_interactive_mode(const char *filename)
{
char *line;
size_t len;
ssize_t read;
FILE *file;
char *command;
char *args[MAX_ARGS + 1];
int arg_count;
int status;
pid_t pid;
int is_interactive;
is_interactive = 0;
/* Flag to indicate interactive mode */
if (is_interactive)
write(STDOUT_FILENO, "Mark>> ", 7);

file = fopen(filename, "r");
if (file == NULL)
{
perror("fopen");
return;
}

line = NULL;
len = 0;

while ((read = getline(&line, &len, file)) != -1)
{
null_after_comment(line, custom_strlen(line));
if (line[read - 1] == '\0')
{write(STDOUT_FILENO, "\n", 1);
return;
}

/* Remove the trailing newline character, if any */
if (line[read - 1] == '\n')
line[read - 1] = '\0';

/*nullify*/
nullify_after_comment(line);
if (custom_strcmp(line, "/bin/echo ") == 0)
{
write(STDOUT_FILENO, "\n", 1);
return;
}

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
return;
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

free(line);
fclose(file);
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


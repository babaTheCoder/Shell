The Simple Shell program is a basic implementation of a shell created with C code. It provides a fundamental command-line user interface that permits executing commands, handling integrated commands, and controlling environment variables.

Capabilities
The custom shell implementation offers the following capabilities:

Interactive Usage: The shell can be utilized interactively by displaying a prompt and accepting user inputs.

Command Performance: The shell is able to carry out external commands by generating a child process and using the execve system call. The shell is capable of executing external commands either by supplying the full absolute path or by searching for the command in the directories detailed in the PATH environment variable.

Integrated Commands: The shell backs a few built-in commands, like exit to terminate the shell and env to print the environment variables.

PATH Resolution: The shell can solve command paths using the PATH environment variable, allowing executing commands by their names without specifying the full path.

Input Handling: The shell can read user inputs using the getline function, allowing typing commands and arguments interactively.

Environment Variables: The shell can access and modify environment variables using the environ variable, offering data about the present environment.

Getting Started
To build and run the shell, follow these steps:

Clone the repository: git clone https://github.com/babaTheCoder/simple_shell.git ↗

Change to the project directory: cd simple_shell

Compile the source code: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Run the shell: ./hsh

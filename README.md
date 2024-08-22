# Simple Shell

This is a simple shell implementation in C,
designed to mimic basic functionality of Unix-like command-line interfaces.

## Files

main.c: Contains the main loop of the shell, which reads user input and manages command execution.

handle_commands.c: Manages command tokenization, executable search, and execution of external commands.

builtins.c: Contains the logic for built-in commands like exit.

header.h: Header file with function declarations and global variables.

## Compilation

Compile the shell using the following command:

```bash

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


USAGE

Interactive Mode

Run the shell in interactive mode :

./hsh

You will see a prompt ('($)') where you can enter commands. To exit the shell, type 'exit'.

NON-INTERACTIVE Mode

You can also pipe commands into the shell:

echo "/bin/ls" | ./hsh

This will execute the command /bin/ls and display the output.

Features

Prompt: Displays a prompt ('($)') for user input.
Built-in Commands: Supports exit to quit the shell and env to display environment variables.
Command Execution: Executes commands using 'execve' and handles errors.
Arguments: Supports commands with arguments.
EOF Handling: Gracefully exits on EOF (Ctrl+D).

Limitations

Does not support advanced features like pipes, redirections, or special characters.

Authors
Mieuzet Frédéric 9344@holbertstudents.com
Mehdi Zemihi 8837@holbertonstudents.com

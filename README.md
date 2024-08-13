# Simple Shell

This is a simple shell implementation in C,
designed to mimic basic functionality of Unix-like command-line interfaces.

## Compilation

Compile the shell using the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

USAGE

Interactive Mode

Run the shell in interactive mode :

./hsh

You will see a prompt (($)) where you can enter commands. To exit the shell, type exit.

NON-INTERACTIVE Mode

You can also pipe commands into the shell:

echo "/bin/ls" | ./hsh

This will execute the command /bin/ls and display the output.

Features

Prompt: Displays a prompt (($)) for user input.
Built-in Commands: Supports exit to quit the shell and env to display environment variables.
Command Execution: Executes commands using execve and handles errors.
EOF Handling: Gracefully exits on EOF (Ctrl+D).
Limitations
Only handles commands without arguments.
Does not support advanced features like pipes, redirections, or special characters.

Authors
Mieuzet Frédéric 9344@holbertstudents.com
Mehdi Zemihi 8837@holbertonstudents.com

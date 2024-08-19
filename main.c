#include "header.h"
/**
 * main - Entry point of the simple shell program.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: Always returns 0.
 */
int main(int argc, char **argv)
{
	(void)argc; /* Nous n'utilisons pas argc, mais nous devons l'accepter */
	prompt(argv[0]); /* Passer le nom du programme à prompt */
	return (0);
}




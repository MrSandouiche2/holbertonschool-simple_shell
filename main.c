#include "header.h"

int main(int argc, char **argv)
{
	if (argc > 0)
	{
		prompt(argv[0]);
	}
	else
	{
		fprintf(stderr, "Erreur : Pas de nom de programme disponible.\n");
		return 1;
	}

	return 0;
}

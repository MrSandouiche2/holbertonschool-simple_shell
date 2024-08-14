#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *caractere = NULL;
	size_t taille = 0;
	typedef long ssize_t;
	ssize_t longueur;

	while (1)
	{
		printf("$ ");
		longueur = getline(&caractere, &taille, stdin);

		if (longueur == -1)
		{
			if (feof(stdin))
			{
				break;
			}
			else
			{
				printf("Erreur lors de la lecture de la ligne.\n");
				break;
			}
		}

		printf("%s", caractere);
	}

	free(caractere);
	return 0;
}

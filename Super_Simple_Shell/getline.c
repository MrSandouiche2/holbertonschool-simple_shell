#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *caractere = NULL;
	size_t taille = 0;

	printf("$");

	ssize_t longueur = getline(&caractere, &taille, stdin);

	if (longueur != -1)
	{
		printf("%s", caractere);
	}
	else
	{
		printf("Erreur lors de la lecture de la ligne.\n");
	}
	free(caractere);
	return (0);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **split_string(char *str);

int main(void)
{

char **vide;
vide = NULL;
int compteur;
char chaine[] = "Bonjour à tous Laval";

vide = split_string(chaine);

if (vide == NULL)
{
	printf("Aucun mot trouvé.\n");
	return (1);
}

for (compteur = 0; vide[compteur] != NULL; compteur++)
{
	printf("%s\n",vide[compteur]);
}
for (compteur = 0; vide[compteur] != NULL; compteur++)
{
	free(vide[compteur]);
}
free(vide);

return (0);

}
char **split_string(char *str)
{
	int initial_size = 10; /*alloue de la mémoire pour 10 mots*/
	char **tableau = malloc(sizeof(char *) * initial_size);
	int compteur = 0;

	/*Vérification de l'argument*/
	if (str == NULL || strlen(str) == 0)
		{
			return (NULL);
		}

	const char *delimiteurs = " ,;!?\n";

	char *mot = strtok(str, delimiteurs);
	while (mot != NULL)/*Vérifier si la mémoire est suffisante*/
		{
			if (compteur >= initial_size)
			{
				initial_size *= 2;/*double la taille*/
				tableau = realloc(tableau, sizeof(char*) * initial_size);
				if (tableau == NULL)
				{
					return (NULL);
				}
			}
			/*allocation pour le mot*/
			tableau[compteur] = malloc(strlen(mot) + 1);
			if (tableau[compteur] == NULL)
			{
				return (NULL);
			}
			strcpy(tableau[compteur], mot);/*copie le mot*/
			compteur++;/*incrémente le compteur*/

			/*recupere le mot suivant*/
			mot = strtok(NULL, delimiteurs);
		}
	/*terminer le tableau avec NULL*/
		tableau[compteur] = NULL;

	return (tableau);
}


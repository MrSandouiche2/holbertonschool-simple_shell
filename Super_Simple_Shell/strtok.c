#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **split_string(char *str);

int main(void)
{


char *chaine;
char **vide;
vide = NULL;
int compteur;
chaine = "valeur par defaut";

vide = split_string(chaine);

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
	char **tableau;
	char *mot;
	int nombre_de_mots = 0;
}	int compteur = 0;

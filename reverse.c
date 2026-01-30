#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string(char str[])
{
    int i = 0; /*Initialisation du compteur pour parcourir la chaîne de caracères*/
    while (str[i]!='\0') /*Parcours de la chaîne pour obtenir sa longueur*/
    {
        i++;
    }
    int k; /*Compteur pour 2e parcours*/
    for (k=0; k<=i/2-1; k++) /*k varie de 0 jusqu'à la moitié de la longueur*/
    {
        char c = str[i-1-k]; /*Stockage de la dernière lettre*/
        str[i-1-k] = str[k]; /*Remplacement de la dernière lettre par la première*/
        str[k] = c; /*Remplacement de la première lettre par la dernière*/
    }
    return;
}

int main()
{
    char *str = (char *) malloc(50*sizeof(char));
    strcpy(str, "Coucou tout le monde");
    reverse_string(str);
    printf("%s\n", str);
    free(str);
    return 0;
}

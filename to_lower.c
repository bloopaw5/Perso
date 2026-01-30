#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void to_lower(char str[])
{
    if (str == NULL) return; /*Test de la chaîne nulle*/
    int i = 0; /*Compteur de caractère initialisé à 0*/
    while (str[i]!='\0') /*Boucle sur tout le mot jusqu'au caractère de fin de chaîne*/
    {
        if ((str[i]>=65)&&(str[i]<=90)) str[i] += 32; /*Comparaison du caractère avec la table ASCII*/
        i++; /*Incrémentation du compteur pour passer au caractère suivant*/
    }
    return;
}

int main()
{
    char *mot = (char *) malloc(50*sizeof(char));
    strcpy(mot, "MAAAAAAAAAAAAANgeer");
    printf("%s\t", mot);
    to_lower(mot);
    printf("%s\n", mot);
    free(mot);
    return 0;
}

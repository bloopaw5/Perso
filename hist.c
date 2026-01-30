#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char histogram(char str[], int hist[26])
{
    if ((str == NULL)||(str[0]=='\0')) return '\0'; /*Test de la chaîne nulle ou vide*/
    int i = 0;
    while (str[i]!='\0') /*Parcours de la chaîne jusqu'au dernier caractère*/
    {
        if ((str[i]>='a')&&(str[i]<='z')) /*Détermine si le caractère est une lettre minuscule à l'aide du tableau ASCII*/
        {
            hist[(int)str[i]-'a']++; /*Incrémentation de la case du tableau correspondante si c'est le cas*/
        }
        i++; /*Passage au caractère suivant*/
    }
    int max = hist[0]; /*Création d'un max valant la première case du tableau (le nombre ditérations de la lettre 'a')*/
    int j; /*Compteur pour le tableau hist*/
    for (j=1; j<26; j++) /*Parcours du tableau hist à partir de la 2e case*/
    {
        if (hist[j]>max) max = hist[j]; /*Le max prend la valeur de la nouvelle case si il est inférieur à son contenu*/
    }
    j = 0;
    while (hist[j]!=max) j++; /*Parcours du tableau jusqu'à rencontrer le (premier) max*/
    j = j + 'a'; /*Conversion de la position de la lettre dans l'alphabet en nombre décimal ASCII*/
    return (char)j; /*Retourne la lettre grâce à un cast local*/
}

int main()
{
    int *tab = (int *)malloc(26*sizeof(int));
    int i;
    for (i=0; i<26; i++)
    {
        tab[i] = 0;
    }
    char *mot = (char *)malloc(100*sizeof(char));
    char *vide = NULL;
    strcpy(mot, "abcdefgghijklllmnoppqrsssstuvvvvwxyyz");
    printf("mot : %s, lettre la plus fréquente : %c\n", mot, histogram(mot, tab));
    printf("Chaîne vide : %c\n", histogram(vide, tab));
    free(tab);
    free(mot);
    return 0;
}

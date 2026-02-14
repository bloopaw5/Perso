#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *join_strings(char *strings[], int count)
{
    if (strings==NULL) return NULL;
    int i;
    int len = 0;
    for (i=0; i<count; i++)
    {
        int j = 0;
        while (strings[i][j]!='\0')
        {
            j++;
            len++;
        }
    }
    char *res = (char *) malloc((len + count)*sizeof(char));
    int new_len = 0;
    for (i=0; i<count; i++)
    {
        int l = 0;
        while (strings[i][l]!='\0')
        {
            res[new_len] = strings[i][l];
            new_len++;
            l++;
        }
        free(strings[i]);
        if (i<count)
        {
            res[new_len] = ' ';
            new_len++;
        }
    }
    res[new_len] = '\0';
    return res;
}

int main()
{
    int nb = 3;
    char **mots = malloc(nb * sizeof(char *));
    mots[0] = strdup("Libération");
    mots[1] = strdup("de");
    mots[2] = strdup("mémoire");
    printf("Avant appel : %s %s %s\n", mots[0], mots[1], mots[2]);
    char *resultat = join_strings(mots, nb);
    if (resultat)
    {
        printf("Résultat : %s\n", resultat);
        free(resultat);
    }
    return 0;
}
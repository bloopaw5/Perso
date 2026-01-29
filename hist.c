#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char histogram(char str[], int hist[26])
{
    if (str == NULL) return '\0';
    int i = 0;
    while (str[i]!='\0')
    {
        if ((str[i]>='a')&&(str[i]<='z'))
        {
            hist[(int)str[i]-'a']++;
        }
        i++;
    }
    int max = 0;
    int j;
    for (j=0; j<26; j++)
    {
        if (hist[j]>max) max = hist[j];
    }
    j = 0;
    while (hist[j]!=max) j++;
    j = j + 'a';
    return (char)j;
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
    strcpy(mot, "hvbuioarthvapzioryvaôa evzipbzyevrp");
    printf("mot : %s, lettre la plus fréquente : %c\n", mot, histogram(mot, tab));
    free(tab);
    free(mot);
    return 0;
}

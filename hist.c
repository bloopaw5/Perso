#include <stdio.h>
#include <stdlib.h>

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
    char *mot = (char *)malloc(10*sizeof(char));
    mot[0] = 'r';
    mot[1] = 'r';
    mot[2] = 'r';
    mot[3] = 'm';
    mot[4] = 'm';
    mot[5] = 'm';
    mot[6] = '\0';
    printf("%c\n", histogram(mot, tab));
    free(tab);
    free(mot);
    return 0;
}
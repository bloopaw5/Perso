#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rle(char str[])
{
    int i = 0;
    int cpt = 0;
    char *res = (char *) malloc(50*sizeof(char));
    int r = 0;
    while (str[i]!='\0')
    {
        if (str[i+1]!=str[i])
        {
            res[r] = cpt+49;
            res[r+1] = str[i];
            cpt = 0;
            r+=2;
        }
        cpt++;
        i++;
    }
    res[r] = '\0';
    printf("%s\n", res);
    free(res);
}

int main()
{
    char *str = (char *) malloc(50*sizeof(char));
    strcpy(str, "ccccccchhh");
    printf("Chaîne de base : %s\n", str);
    rle(str);
    free(str);
    return 0;
}
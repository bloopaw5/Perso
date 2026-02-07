#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rle(char str[])
{
    int l = 0;
    while (str[l]!='\0')
    {
        l++;
    }
    int i = 0;
    int cpt = 1;
    char res[2*l];
    int r = 0;
    while (str[i]!='\0')
    {
        if (str[i+1]!=str[i]) /*Si le caractère est identique au suivant*/
        {
            while (cpt>=10) /*Si le nombre d'occurrences du caractère excède 10*/
            {
                cpt -= 9;
                res[r] = 57; /*Code ASCII de 9*/
                res[r+1] = str[i];
                r+=2;
            }
            res[r] = cpt+48;
            res[r+1] = str[i];
            cpt = 0;
            r+=2;
        }
        cpt++;
        i++;
    }
    res[r] = '\0';
    printf("%s\n", res);
}

int main()
{
    char str[] = "hey maaan";
    printf("Chaîne de base : %s\n", str);
    rle(str);
    return 0;
}
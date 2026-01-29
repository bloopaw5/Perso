#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void to_lower(char str[])
{
    if (str == NULL) return;
    int i = 0;;
    while (str[i]!='\0')
    {
        if ((str[i]>=65)&&(str[i]<=90)) str[i] += 32;
        i++;
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

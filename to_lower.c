#include <stdio.h>
#include <stdlib.h>

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
    char *mot = (char *) malloc(10*sizeof(char));
    mot[0] = 'M';
    mot[1] = 'a';
    mot[2] = 'N';
    mot[3] = 'g';
    mot[4] = 'E';
    mot[5] = 'r';
    mot[6] = '\0';
    to_lower(mot);
    printf("%s\n", mot);
    free(mot);
    return 0;
}
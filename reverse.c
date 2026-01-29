#include <stdio.h>
#include <stdlib.h>

void reverse_string(char str[])
{
    int i = 0;
    while (str[i]!='\0')
    {
        i++;
    }
    int k;
    for (k=0; k<=i/2-1; k++)
    {
        char c = str[i-1-k];
        str[i-1-k] = str[k];
        str[k] = c;
    }
    return;
}

int main()
{
    char *str = (char *) malloc(10*sizeof(char));
    str[0] = 'C';
    str[1] = 'O';
    str[2] = 'U';
    str[3] = 'C';
    str[4] = 'O';
    str[5] = 'U';
    str[6] = 'K';
    str[7] = '\0';
    reverse_string(str);
    printf("%s\n", str);
    free(str);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char *str = (char *) malloc(50*sizeof(char));
    strcpy(str, "Coucou tout le monde");
    reverse_string(str);
    printf("%s\n", str);
    free(str);
    return 0;
}

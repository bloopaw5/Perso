#include <stdio.h>
#include <stdlib.h>

void fibo(int n, int res[n+1])
{
    if (n<0) return;
    if (n==0)
    {
        res[0] = 0;
        return;
    }
    res[0] = 0;
    res[1] = 1;
    int i = 2;
    while (i<=n)
    {
        res[i] = res[i-1] + res[i-2];
        i++;
    }
}

int main()
{
    int n = 0;
    int *tab = (int*) malloc((n+1)*sizeof(int));
    fibo(n,tab);
    int i;
    for (i=0; i<n+1; i++)
    {
        printf("%d\t", tab[i]);
    }
    printf("\n");
    free(tab);
    return 0;
}
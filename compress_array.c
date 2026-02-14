#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *compress_array(const int *input, int n, int *out_size)
{
    if (n<=0)
    {
        *out_size = 0;
        return NULL;
    }
    int i;
    int runs = 1;
    for (i=0; i<n-1; i++)
    {
        if (input[i]!=input[i+1]) /*Si le nombre est différent du suivant*/
        {
            runs++;
        }
    }
    int *res = (int *) malloc(2*runs*sizeof(int));
    int r = 0;
    int cpt = 1;
    for (i=0; i<n; i++)
    {
        if (i == n-1 || input[i]!=input[i+1]) /*Si le nombre est différent du suivant*/
        {
            res[r++] = input[i];
            res[r++] = cpt;
            cpt = 1;
        }
        else
        {
            cpt++;
        }
    }
    *out_size = 2*runs;
    return res;
}

int main()
{
    int n = 9;
    int out_size;
    int input[] = {3, 3, 3, 1, 1, 5, 5, 5, 5};
    int *res = compress_array(input, n, &out_size);
    printf("%d\n", out_size);
    int i;
    printf("{%d", res[0]);
    for (i=1; i<out_size; i++)
    {
        printf(", %d", res[i]);
    }
    printf("}\n");
    free(res);
    return 0;
}
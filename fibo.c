#include <stdio.h>
#include <stdlib.h>

void fibo(int n, int res[n+1])
{
    if (n<0) return; /*Si n est négatif, le programme n'a pas de sens*/
    if (n==0) /*Test de n=0 pour ne remplir qu'une case du tableau*/
    {
        res[0] = 0;
        return;
    }
    res[0] = 0; /*Initialisation des conditions initiales F1 = 0 */
    res[1] = 1; /*Et F2 = 1*/
    int i = 2; /*Compteur commençant à 2 (3e terme)*/
    while (i<=n) /*Parcours du tableau jusqu'à la dernière case*/
    {
        res[i] = res[i-1] + res[i-2]; /*Calcul de la case courante avec la formule de récurrence*/
        i++; /*Passage à la case suivante*/
    }
}

int main()
{
    int n = 10;
    int *tab = (int *) malloc((n+1)*sizeof(int));
    fibo(n, tab);
    int i;
    printf("[%d", tab[0]);
    for (i=1; i<n+1; i++)
    {
        printf(", %d", tab[i]);
    }
    printf("]\n");
    free(tab);
    return 0;
}
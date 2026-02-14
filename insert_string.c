#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **insert_string(char **strings_array, int *array_size, char *insert_str, int index)
{
    if (strings_array == NULL) return NULL;
    char **res = (char **) malloc((*array_size+1)*sizeof(char *));
    if ((index<=0)||(index>=*array_size))
    {
        res[0] = insert_str;
        int i;
        for (i=1; i<*array_size+1; i++)
        {
            res[i] = strings_array[i-1];
        }
    }
    else
    {
        int i;
        for (i=0; i<index; i++)
        {
            res[i] = strings_array[i];
        }
        res[index] = insert_str;
        for (i=index+1; i<*array_size+1; i++)
        {
            res[i] = strings_array[i-1];
        }
    }
    (*array_size)++;
    return res;
}

int main()
{
    int size = 3;
    char **mon_tableau = malloc(size * sizeof(char *));
    mon_tableau[0] = "Pomme";
    mon_tableau[1] = "Banane";
    mon_tableau[2] = "Orange";
    printf("Avant insertion (taille %d) :\n", size);
    for(int i=0; i<size; i++) printf("- %s\n", mon_tableau[i]);
    int nouvelle_taille = size;
    char **nouveau_tab = insert_string(mon_tableau, &nouvelle_taille, "Fraise", 1);
    if (nouveau_tab) {
        printf("\nAprès insertion de 'Fraise' à l'index 1 (taille %d) :\n", nouvelle_taille);
        for (int i = 0; i < nouvelle_taille; i++) {
            printf("%d: %s\n", i, nouveau_tab[i]);
        }
        free(nouveau_tab);
    }
    free(mon_tableau);
    return 0;
}
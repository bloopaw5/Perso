#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void affiche_mat(int x, int y, int mat[x][y])
{
    int i;
    int j;
    for (i=0; i<x; i++)
    {
        for (j=0; j<y; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int check_zone(int map_h, int map_w, int map[map_h][map_w], int x, int y, int rect_h, int rect_w)
{
    if ((map==NULL)||(x < 0)||(y < 0)||(map_h<rect_h+x)||(map_w<rect_w+y)) return 0; /*Si la map pointe vers NULL ou si la taille du bâtiment excède la taille de la carte - la coordonnée de son coin gauche, ne rien faire*/
    int i;
    int j;
    for (i=x; i<rect_h+x; i++) /*Vérifie si aucun obstacle ne se trouve dans la zone du bâtiment*/
    {
        for (j=y; j<rect_w+y; j++)
        {
            if (map[i][j] == 1) return 0; /*Renvoie 0 dès qu'un obstacle est trouvé*/
        }
    }
    for (i=x; i<rect_h+x; i++) /*Si la zone est constructible, la remplir la 2*/
    {
        for (j=y; j<rect_w+y; j++)
        {
            map[i][j] = 2;
        }
    }
    return 1;
}

int main()
{
    srand(time(NULL));
    int map_h = 6;
    int map_w = 6;
    int map[map_h][map_w];
    int i;
    int j;
    for (i=0; i<map_h; i++)
    {
        for (j=0; j<map_w; j++)
        {
            map[i][j] = rand()%2;
        }
    }
    int x = 1;
    int y = 3;
    int rect_h = 2;
    int rect_w = 2;
    affiche_mat(map_h, map_w, map);
    check_zone(map_h, map_w, map, x, y, rect_h, rect_w);
    affiche_mat(map_h, map_w, map);
    return 0;
}

#include <stdio.h>

void Regular(int mat[4][4])
{
    int i, j, s[4]={0, 0, 0,0};
    for (i = 0; i < 4; i++)
    {
        for (j=0; j < 4; j++)
        {
            s[i] = s[i] + mat[i][j];
        }
    }
    for (i = 0; i < 4; i++)
    {
        printf("%d ", s[i]);
    }
    if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3])
    {
        printf("\nO grafo é regular");
    }
    else
    {
        printf("\nO grafo NÃO é regular");
    }
}


int main()
{
    int i, j, resul;
    int Matriz[4][4] = {
        {0, 3, 3, 0},
        {3, 1, 1, 0},
        {1, 1, 1, 2},
        {4, 0, 1, 0},
    };
    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            printf("%d ", Matriz[i][j]);
        }
        printf("\n");
    }

    Regular(Matriz);

    return 0;
}
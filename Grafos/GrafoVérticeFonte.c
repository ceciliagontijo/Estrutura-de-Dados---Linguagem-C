#include <stdio.h>

void Fonte(int mat[4][4])
{
    int i, j, resul;
    for (i = 0; i < 4; i++)
    {
        resul=0;
        for (j=0; j < 4; j++)
        {
            if (mat[j][i] != 0)
            {
                resul = 1;
            }
        }
        if (resul == 0)
        {
            printf("\nO vértice %d é um vértice fonte.", i+1);
        }
    }
}


int main()
{
    int i, j;
    int Matriz[4][4] = {
        {0, 3, 3, 0},
        {3, 1, 1, 0},
        {1, 1, 1, 0},
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

    Fonte(Matriz);

    return 0;
}

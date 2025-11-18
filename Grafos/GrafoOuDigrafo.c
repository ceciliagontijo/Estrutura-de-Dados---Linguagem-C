#include <stdio.h>

int Verifica(int mat[4][4])
{
    int i, j, resul=1;
    for (i = 0; i < 4; i++)
    {
        for (j=i+1; j < 4; j++)
        {
            if (mat[i][j] != mat[j][i])
            {
                resul = 0;
            }
        }
    }
    return resul;
}


int main()
{
    int i, j, resul;
    int Matriz[4][4] = {
        {0, 3, 2, 0},
        {3, 0, 1, 0},
        {1, 1, 1, 1},
        {0, 0, 1, 0},
    };
    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            printf("%d ", Matriz[i][j]);
        }
        printf("\n");
    }

    resul = Verifica(Matriz);
    if (resul == 0)
    {
        printf("\nA matriz analisada representa um dígrafo direcionado (não é triangular)");
    }
    else
    {
        printf("\nA matriz analisada representa um grafo não direcionado (é triangular)");
    }

    return 0;
}
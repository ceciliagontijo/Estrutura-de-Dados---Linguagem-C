#include <stdio.h>

int Verifica(int mat[4][4])
{
    int i, j, resul=0;
    for (i = 0; i < 4; i++)
    {
        for (j=0; j < 4; j++)
        {
            if (mat[i][j] != 0 && mat[i][j] != 1)
            {
                resul = 1;
            }
        }
    }
    return resul;
}

int main()
{
    int i, j, resul;
    int Matriz[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {1, 1, 1, 1},
        {0, 0, 2, 0},
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
        printf("\nA matriz analisada representa um grafo simples");
    }
    else
    {
        printf("\nA matriz analisada representa um multigrafo");
    }

    return 0;
}
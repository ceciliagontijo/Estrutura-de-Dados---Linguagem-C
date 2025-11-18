#include <stdio.h>

int Semidouro(int mat[4][4])
{
    int i, j, resul_linha, resul_coluna, cont=0;
    for (i = 0; i < 4; i++)
    {
        resul_linha = 0;
        resul_coluna = 0;
        for (j=0; j < 4; j++)
        {
            if (mat[i][j] != 0)
            {
                resul_linha = 1;
            }
        }
        for (j=0; j < 4; j++)
        {
            if (mat[j][i] != 0)
            {
                resul_coluna = 1;
            }
        }
        if (resul_linha == 1 && resul_coluna == 1)
        {
            cont++;
        }
    }
    return cont;
}


int main()
{
    int i, j, cont;
    int Matriz[4][4] = {
        {0, 3, 3, 0},
        {3, 1, 1, 0},
        {0, 0, 0, 0},
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

    cont = Semidouro(Matriz);
    printf("\nQuantidade de vértices semidouro = %d", cont);

    return 0;
}

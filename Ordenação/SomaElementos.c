#include <stdio.h>

int VerificaSoma(int v[], int x, int n)
{
    int i=0, j=0;
    for (i=0; i < n; i++)
    {
        for (j=i+1; j < n; j++)
        {
            if (v[i]+v[j]==x)
            {
                printf("\n%d + %d = %d\n", v[i], v[j], x);
                return 0;
            }
        }
    }
    printf("\nNão há 2 elementos que somados resultam em %d", x);
    return 0;
}

int main()
{
    int n, v[n], i=0, x, cont, resul;

    printf("Quantidade de elementos: ");
    scanf("%d", &n);
    cont = n;
    while (cont>0)
    {
        printf("V[%d]: ", i+1);
        scanf("%d", &v[i]);
        i++;
        cont--;
    }
    printf("Elemento x: ");
    scanf("%d", &x);
    resul = VerificaSoma(v, x, n);
    return 0;
}
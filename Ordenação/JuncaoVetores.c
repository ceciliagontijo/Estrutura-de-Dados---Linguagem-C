#include <stdio.h>
#define max 50

void juncao(int v[], int v2[], int n) 
{
    int resul[max];
    int i=0, j=0, k=0;
    while (i<n && j<n)
    {

        if (v[i] == v2[j])
        {
            resul[k] = v[i];
            i++;
            j++;
            k++;
        }
        else
        {
            if (v[i] < v2[j])
            {
                resul[k] = v[i];
                i++;
                k++;
            }
            else
            {
                if (v[i]>v2[j])
                {
                    resul[k] = v2[j];
                    j++;
                    k++;
                }
            }

        }
    }
    if (i < n)
    {
        while (i < n)
        {
            resul[k] = v[i];
            i++;
            k++;
        }
    }
    if (j < n)
    {
        while (j < n)
        {
            resul[k] = v2[j];
            j++;
            k++;
        }
    }
    i=0;
    while (k>0)
    {
        printf("%d ", resul[i]);
        i++;
        k--;
    }
}

int main()
{
    int v[4], v2[4];
    int i=0, cont=4;
    while (cont>0)
    {
        printf("V[%d] = ", i+1);
        scanf("%d", &v[i]);
        cont--;
        i++;
    }
    i=0;
    cont=4;
    while (cont>0)
    {
        printf("V2[%d] = ", i+1);
        scanf("%d", &v2[i]);
        cont--;
        i++;
    }
    juncao (v, v2, 4);
    return 0;
}
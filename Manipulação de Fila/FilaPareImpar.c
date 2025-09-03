#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    struct no *prox;
    int info;
}No;

typedef struct lista
{
    No* ini;
    No* fim;
}Fila;

Fila* CriaFila(void)
{
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

void imprime(Fila *f)
{
    No* aux = f->ini;
    while (aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}

No* ins_fim(No *fim, int v)
{
    No* novo = (No*)malloc(sizeof(No));
    novo->info = v;
    novo->prox = NULL;
    if (fim != NULL)
    {
        fim->prox = novo;
    }
    return novo;
}

void insere(Fila *f, int v)
{
    f->fim = ins_fim(f->fim, v);
    if (f->ini == NULL)
    {
        f->ini = f->fim;
    }
}

Fila* par(Fila *f, Fila *fp)
{
    No* aux = f->ini;
    while (aux!=NULL)
    {
        if (aux->info % 2 == 0)
        {
            insere(fp, aux->info);
        }

        aux = aux->prox;
    }
    return fp;
}

Fila* impar(Fila *f, Fila *fi)
{
    No* aux = f->ini;
    while (aux!=NULL)
    {
        if (aux->info % 2 != 0)
        {
            insere(fi, aux->info);
        }

        aux = aux->prox;
    }
    return fi;
}

int main()
{
    Fila* f;
    Fila* fi;
    Fila* fp;
    int qnt, valor;
    f = CriaFila();
    fi = CriaFila();
    fp = CriaFila();
    printf("Quantos elementos deseja inserir? \n");
    scanf("%d",&qnt);
    while (qnt > 0)
    {
        printf("\nValor = ");
        scanf("%d",&valor);
        insere(f, valor);
        qnt--;
    }
    printf("\nPilha = ");
    imprime(f);


    fp = par(f, fp);
    printf("\nPilha par = ");
    imprime(fp);

    fi = impar(f, fi);
    printf("\nPilha ímpar = ");
    imprime(fi);

    return 0;
}
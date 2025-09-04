#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    struct no *prox;
    int info;
}No;

typedef struct fila
{
    No *ini;
    No *fim;
}Fila;

Fila* CriaFila(void)
{
    Fila *f;
    f = (Fila*)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
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

void imprime(Fila *f)
{
    No* aux = f->ini;
    while (aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}

void remove_ele(Fila *f)
{
    Fila *fn;
    int v=15;
    fn = CriaFila();
    No* aux = f->ini;
    while (aux != NULL)
    {
        if (aux->info != v)
        {
            insere(fn, aux->info);
        }
        aux = aux->prox;
    }
    imprime(fn);
}

int main()
{
    Fila *f;
    f = CriaFila();
    int qnt, valor;
    printf("Quantos elementos deseja adicionar na fila? \n");
    scanf("%d", &qnt);
    while (qnt > 0)
    {
        printf("\nValor = ");
        scanf("%d", &valor);
        insere(f, valor);
        qnt--;
    }
    printf("\nFila original = ");
    imprime(f);
    printf("\nFila nova = ");
    remove_ele(f);
    return 0;
}
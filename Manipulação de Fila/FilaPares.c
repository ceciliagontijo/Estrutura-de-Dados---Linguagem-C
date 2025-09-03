#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    struct no* prox;
    int info;
}No;

typedef struct fila
{
    No* ini;
    No* fim;
}Fila;

Fila* CriaFila(void)
{
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f -> ini = NULL;
    f -> fim = NULL;
    return f;
}

No* ins_fim(No* fim, int v)
{
    No* novo = (No*)malloc(sizeof(No));
    novo -> info = v;
    novo -> prox = NULL;
    if (fim != NULL )
    {
        fim -> prox = novo;
    }
    return novo;
}

void insere(Fila* f, int v)
{
    f -> fim = ins_fim(f->fim, v);
    if (f->ini == NULL)
    {
        f->ini = f->fim;
    }
}

No* ret_ini(No* ini)
{
    No *p = ini -> prox;
    free(ini);
    return p;
}

int retira(Fila *f)
{
    int v;
    v = f->ini->info;
    f->ini = ret_ini(f->ini);
    if (f->ini == NULL)
    {
        f->fim = NULL;
    }
    return v;
}

Fila* remove_ele(Fila *f)
{
    No* aux = f->ini;
    No* aux2;
    while (aux != NULL)
    {
        if (aux -> info == 15)
        {
            aux2 = aux->prox;
            free(aux);
            aux = aux2;
            return f;
        }
        aux = aux -> prox;
    }
    return f;
}

void imprime(Fila *f)
{
    No* aux = f->ini;
    while (aux != NULL)
    {
        printf("%d ", aux -> info);
        aux = aux -> prox;
    }
}

int pares(Fila* f)
{
    No* aux = f -> ini;
    int cont=0;
    while (aux != NULL)
    {
        if (aux->info % 2 == 0)
        {
            cont++;
            aux = aux -> prox;
        }
        else
        {
            aux = aux -> prox;
        }
    }
    return cont;
}

int main()
{
    Fila *F1;
    F1 = CriaFila();
    int qnt, valor;
    int par;
    printf("Quantos elementos deseja inserir na fila? \n");
    scanf("%d", &qnt);
    while (qnt > 0)
    {
        printf("\nValor = ");
        scanf("%d", &valor);
        insere(F1, valor);
        qnt--;
    }
    par = pares(F1);
    printf("\nQuantidade de pares = %d\n", par);
    imprime(F1);
    F1 = remove_ele(F1);
    imprime(F1);
    return 0;
}
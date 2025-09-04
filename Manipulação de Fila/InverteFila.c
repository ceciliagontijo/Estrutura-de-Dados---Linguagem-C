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

typedef struct pilha
{
    No* topo;
} Pilha;

int vaziaPilha(Pilha* p)
{
    if (p->topo == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Fila* CriaFila(void)
{
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

Pilha* CriaPilha(void)
{
    Pilha *p;
    p=(Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

No* insere_pilha(No* p, int v)
{
    No* aux = (No*) malloc(sizeof(No));
    aux->info = v;
    aux->prox = p;
    return aux;
}
void push(Pilha* p, int v)
{
    p->topo = insere_pilha(p->topo, v);
}

No* retira_pilha(No* p)
{
    No* aux = p->prox;
    free(p);
    return aux;
}

int pop(Pilha* p)
{
    int v;
    if (vaziaPilha(p))
    {
        printf("\nPILHA VAZIA");
        exit(1);
    }
    else
    {
        v = p->topo->info;
        p->topo = retira_pilha(p->topo);
        return v;
    }
}

No* ins_ini(No *fim, int v)
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
    f->fim = ins_ini(f->fim, v);
    if (f->ini == NULL)
    {
        f->ini = f->fim;
    }
}

void imprime(Fila *f)
{
    No *aux = f->ini;
    while (aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}

void inverte(Fila *f)
{
    Fila *f2 = CriaFila();
    Pilha *p = CriaPilha();
    No *aux = f->ini;
    while (aux != NULL)
    {
        push(p, aux->info);
        aux = aux->prox;
    }
    while (vaziaPilha(p) == 0)
    {
        insere(f2, pop(p));
    }
    free(p);
    imprime(f2);
}

int main()
{
    Fila *f = CriaFila();
    int qnt, valor;
    printf("Quantidade de elementos: \n");
    scanf("%d", &qnt);
    while (qnt > 0)
    {
        printf("\nValor = ");
        scanf("%d", &valor);
        insere(f, valor);
        qnt--;
    }
    printf("\nPilha original = ");
    imprime(f);
    printf("\nPilha invertida = ");
    inverte(f);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    struct no *prox;
    int info;
}No;

typedef struct pilha
{
    No *topo;
}Pilha;

Pilha* CriaPilha(void)
{
    Pilha* p;
    p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

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

No* insere(No* p, int v)
{
    No* novo;
    novo = (No*) malloc(sizeof(No));
    novo->info = v;
    novo->prox = p;
    return novo;
}

void push(Pilha* p, int v)
{
    p->topo = insere(p->topo, v);
}

No* retira(No* p)
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
        p->topo = retira(p->topo);
        return v;
    }
}

void imprime(Pilha* p)
{
    No *aux = p->topo;
    if (vaziaPilha(p))
    {
        printf("\nPILHA VAZIA");
        exit(1);
    }
    else
    {
        while (aux != NULL)
        {
            printf("%d ", aux->info);
            aux = aux->prox;
        }
    }
}

Pilha* inverte(Pilha* p)
{
    int v;
    Pilha* p2;
    p2 = CriaPilha();
    No* aux = p->topo;
    No* aux2;
    while (aux != NULL)
    {
        aux2 = aux->prox;
        v = pop(p);
        push(p2, v);
        aux = aux2;
    }
    return p2;
}

Pilha* copia(Pilha* p1, Pilha* p2)
{
    No *aux = p1->topo;
    while (aux != NULL)
    {
        push(p2, aux->info);
        aux = aux->prox;
    }
    p2 = inverte(p2);
    return p2;
}

int main()
{
    Pilha* p;
    Pilha* p2;
    p = CriaPilha();
    p2 = CriaPilha();
    int qnt, valor;
    printf("Quantos elementos na pilha = \n");
    scanf("%d",&qnt);
    while (qnt > 0)
    {
        printf("\nValor = ");
        scanf("%d", &valor);
        push(p, valor);
        qnt--;
    }
    p2 = copia(p, p2);
    printf("\nPilha original = ");
    imprime(p);
    printf("\nPilha copia = ");
    imprime(p2);

    return 0;
}
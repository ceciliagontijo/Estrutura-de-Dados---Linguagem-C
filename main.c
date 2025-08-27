#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int info;
    struct no *prox;
}No;

typedef struct pilha
{
    No *Topo;
}Pilha;

int vaziaPilha(Pilha *p)
{
    if (p->Topo == NULL)
    {
        return 1;
    }
    return 0;
}

Pilha* CriaPilha (void)
{
    Pilha *p;
    p=(Pilha*)malloc(sizeof(Pilha));
    p->Topo = NULL;
    return p;
}

No* ins_ini (No* t, int a)
{
    No* aux = (No*) malloc(sizeof(No));
    aux->info = a;
    aux->prox = t;
    return aux;
}

void push (Pilha* p, int v)
{
    p->Topo = ins_ini(p->Topo,v);
}

No* ret_ini (No* aux)
{
    No* p = aux->prox;
    free(aux);
    return p;
}

int pop (Pilha *p)
{
    int v;
    if (vaziaPilha(p))
    {
        printf("\n\n\t==> Pilha VAZIA, IMPOSSIVEL CONTINUAR.\b\n");
        exit(1);
    }
    v = p->Topo->info;
    p->Topo = ret_ini(p->Topo);
    return v;
}



void imprime (Pilha *p)
{
    No *aux = p -> Topo;
    if (vaziaPilha(p))
    {
        printf("\nPilha vazia!!!");
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

int main()
{
    Pilha *p;
    int inteiro, resultado;
    p = CriaPilha();
    printf("\nNúmero inteiro = ");
    scanf("%d",&inteiro);
    while (inteiro > 0)
    {
        resultado = inteiro % 10;
        push(p, resultado);
        inteiro = inteiro / 10;
    }
    imprime(p);

    return 0;
}
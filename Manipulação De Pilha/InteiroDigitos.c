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
    No* aux = p->topo;
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
    Pilha* pi;
    int v;
    pi = CriaPilha();
    No* aux =p->topo;
    No* aux2;
    while (aux != NULL)
    {
        aux2 = aux->prox;
        v = pop(p);
        push(pi,v);
        aux = aux2;
    }
    return pi;
}

int quantidade(Pilha* p)
{
    No* aux = p->topo;
    int cont=0;
    while (aux != NULL)
    {
        cont++;
        aux = aux-> prox;
    }
    return cont;
}

int inteiro(Pilha* p, int qnt)
{
    int v, resultado=0;
    for (qnt=qnt; qnt>0; qnt--)
    {
        resultado = resultado * 10;
        v = pop(p);
        resultado = resultado + v;
    }
    return resultado;
}

int main()
{
    Pilha* p;
    int elem, qnt, v, num;
    p = CriaPilha();
    printf("\nQuantos dígitos tem o inteiro = ");
    scanf("%d", &elem);
    while (elem>0)
    {
        printf("\nDígito = ");
        scanf("%d", &v);
        push(p, v);
        elem--;
    }
    qnt = quantidade(p);
    printf("\nQuantidade = %d\n", qnt);
    p = inverte(p);
    imprime(p);
    num = inteiro(p, qnt);

    printf("\nInteiro = %d", num);
    return 0;
}
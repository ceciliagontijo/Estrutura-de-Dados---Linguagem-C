#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int info;
    struct No* prox;
} No;

typedef struct Pilha
{
    No* topo;
} Pilha;

Pilha* CriaPilha(void)
{
    Pilha *p;
    p=(Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}
int verificaVazio(Pilha* p)
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
No* insere(Pilha* p, int v)
{
    No* aux = (No*) malloc(sizeof(No));
    aux->info = v;
    aux->prox = p;
    return aux;
}
void push(Pilha* p, int v)
{
    p->topo = insere(p->topo, v);
}
void imprime(Pilha* p)
{
    No *aux=p->topo;
    if (verificaVazio(p))
    {
        printf("\nA pilha está vazia!!!");
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

int compara(Pilha* p1, Pilha* p2)
{
    int cont1=0, cont2=0;
    No* aux1 = p1->topo;
    No* aux2 = p2->topo;
    while (aux1 != NULL)
    {
        cont1++;
        aux1 = aux1->prox;
    }
    while (aux2 != NULL)
    {
        cont2++;
        aux2 = aux2->prox;
    }
    if (cont1 > cont2)
    {
        return 1;
    }
    if (cont2 > cont1)
    {
        return 2;
    }
    if (cont1 == cont2)
    {
        return 0;
    }
}

int main()
{
    Pilha* p1;
    Pilha* p2;
    p1 = CriaPilha();
    p2 = CriaPilha();
    int qnt1, qnt2, valor, resultado;
    printf("Quantos elementos deseja adicionar na pilha 1? \n");
    scanf("%d",&qnt1);
    while (qnt1 > 0)
    {
        printf("\nValor = ");
        scanf("%d", &valor);
        push(p1, valor);
        qnt1--;
    }
    printf("Quantos elementos deseja adicionar na pilha 2? \n");
    scanf("%d",&qnt2);
    while (qnt2 > 0)
    {
        printf("\nValor = ");
        scanf("%d", &valor);
        push(p2, valor);
        qnt2--;
    }
    printf("\nPilha 1 = ");
    imprime(p1);
    printf("\nPilha 2 = ");
    imprime(p2);
    resultado = compara(p1, p2);
    if (resultado == 1)
    {
        printf("\nPilha 1 é maior que Pilha 2");
    }
    if (resultado == 2)
    {
        printf("\nPilha 2 é maior que Pilha 1");
    }
    if (resultado == 0)
    {
        printf("\nAs pilhas tem o mesmo tamanho");
    }

    return 0;
}
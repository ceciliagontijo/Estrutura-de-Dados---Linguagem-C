#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int info;
    struct NO *prox;
} No;
typedef No Lista;

Lista* inicializa()
{
    return NULL;
}

Lista* insere_final (Lista* l, int valor)
{
    Lista *novo;
    Lista *aux;
    novo = (Lista*) malloc (sizeof(Lista));
    novo -> info = valor;
    novo -> prox = NULL;
    aux = l;
    if (l == NULL)
    {
        return novo;
    }
    else
    {
        while (aux -> prox != NULL)
        {
            aux = aux -> prox;
        }
        aux -> prox = novo;
        return l;
    }
}


void imprime (Lista* aux)
{
    if (aux == NULL)
    {
        printf("\nA lista está vazia!!!");
    }
    else
        printf("\nLista = ");
    while (aux!=NULL)
    {
        printf("%d ", aux -> info);
        aux = aux -> prox;
    }
}



void busca(Lista *l, int pos1, pos2)
{
    int elem, cont = 1;
    Lista *aux = l;
    Lista *aux2 = l;
    while (aux != NULL && cont < pos1)
    {
        aux = aux -> prox;
        cont++;
    }
    cont=1;
    while (aux2 != NULL && cont < pos2)
    {
        aux2 = aux2 -> prox;
        cont++;
    }
    if (aux == NULL || aux2 == NULL)
    {
        printf("\nEssa posição não existe");
    }
    else
    {
        elem = aux -> info;
        aux -> info = aux2 -> info;
        aux2 -> info = elem;
    }
}

int main()
{
    Lista *inicio;
    inicio = inicializa();
    int qnt, valor, pos1, pos2, elem1, elem2;
    printf("Quantidade de elementos na fila = ");
    scanf("%d", &qnt);
    while (qnt > 0)
    {
        printf("\nElemento = ");
        scanf("%d", &valor);
        inicio = insere_final(inicio, valor);
        qnt--;
    }

    imprime(inicio);

    printf("\nInforme a posição dos elementos que deseja trocar: ");
    printf("\nPosição 1 = ");
    scanf("%d", &pos1);
    printf("\nPosição 2 = ");
    scanf("%d", &pos2);
    busca(inicio, pos1, pos2);
    imprime(inicio);
    return 0;
}
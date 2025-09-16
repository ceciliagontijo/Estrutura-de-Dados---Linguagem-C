#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
//inserir valor no comeco e no final, apagar valor do inicio da lista, imprimir a lista, buscar um valor

typedef struct NO
{
    int info;
    struct NO *prox;
} NO;
typedef NO Lista;

Lista* inicializa()
{
    return NULL;
}

Lista* insere (Lista* recebida, int valor)
{
    Lista *novo;
    novo = (Lista*) malloc (sizeof(Lista));
    novo -> info = valor;
    novo -> prox = recebida;
    return novo;
}

Lista* insere_final (Lista* inicio, int valor)
{
    Lista *novo;
    Lista *aux;
    novo = (Lista*) malloc (sizeof(Lista));
    novo -> info = valor;
    novo -> prox = NULL;
    aux = inicio;
    if (inicio == NULL)
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
        return inicio;
    }
}

Lista* apaga_final (Lista* inicio)
{
    Lista *aux;
    aux = inicio;
    while (aux->prox->prox != NULL)
    {
        aux = aux -> prox;
    }
    free(aux->prox);
    aux -> prox = NULL;
    return inicio;
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

int busca(Lista* aux, int valor)
{
    while (aux!=NULL)
    {
        if (aux->info == valor)
        {
            return 1;
        }
        else
        aux = aux->prox;
    }
    return 0;
}

Lista* apaga_comeco(Lista* aux)
{
    Lista* aux2;
    aux2 = aux->prox;
    free(aux);

    return aux2;
}

Lista* apaga_lista(Lista* aux)
{
    Lista* aux2;
    while (aux!=NULL)
        {
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    return aux;
}

void quantidade(Lista* aux)
{
    int qnt=0;
    while (aux!=NULL)
    {
        qnt++;
        aux = aux->prox;
    }
    printf("Quantidade de elementos: %d\n", qnt);
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    Lista *inicio;
    int valor, valor2, resposta, qnt, num;

    inicio = inicializa();

    do {
        do {
            printf("\t\t\tMENU\n");
            printf("-----------------------------------------------------\n\n");
            printf("1. Incluir um valor no começo da lista.\n\n");
            printf("2. Apagar um valor no começo da lista.\n\n");
            printf("3. Incluir um valor no final da lista.\n\n");
            printf("4. Apagar um valor no final da lista.\n\n");
            printf("5. Buscar um valor na lista. \n\n");
            printf("6. Imprimir a lista. \n\n");
            printf("7. Verificar a quantidade de elementos na lista. \n\n");
            printf("8. Apagar todos os elementos da lista. \n\n");
            printf("9. Sair do sistema.\n\n");
            printf("-----------------------------------------------------\n\n");
            printf("Insira sua opção: ");
            scanf("%d", &num);
        } while (num<1 || num>9);
        switch (num) {
            case 1:
                printf("\nDigite o valor que deseja inserir no início da lista: ");
                scanf("%d", &valor);
                inicio = insere(inicio, valor);
                break;
            case 2:
                inicio = apaga_comeco(inicio);
                break;
            case 3:
                printf("\nDigite o valor que deseja inserir no final da lista: ");
                scanf("%d", &valor);
                inicio = insere_final(inicio, valor);
                break;
            case 4:
                inicio = apaga_final(inicio);
                break;
            case 5:
                printf("\nQual valor você deseja procurar na lista: ");
                scanf("%d", &valor2);
                resposta = busca(inicio, valor2);
                if (resposta == 1)
                {
                    printf("\nO valor %d se encontra na lista.", valor2);
                }
                else
                    printf("\nO valor %d NÃO se encontra na lista.", valor2);
                break;
            case 6:
                imprime(inicio);
                break;
            case 7:
                quantidade(inicio);
                break;
            case 8:
                inicio = apaga_lista(inicio);
        }
    } while (num!=9);

    return 0;

}
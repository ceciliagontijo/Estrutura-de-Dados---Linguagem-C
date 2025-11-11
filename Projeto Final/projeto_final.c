#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct dados
{
    int id;
    char cliente[50];
    char vendedor[50];
    Data trans;
    float valor;
}Dados;

typedef struct NoArvore
{
    int info;
    struct NoArvore *dir;
    struct NoArvore *esq;
}NoArv;

typedef struct Arvore
{
    NoArv *raiz;
}Arv;

Arv* CriaArvore(void)
{
    Arv *aux;
    aux = (Arv*) malloc(sizeof(Arv));
    aux->raiz = NULL;
    return aux;
}

int ArvVazia(Arv *arv)
{
    if (arv->raiz == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void insere(Arv *a1, Dados d)
{
    NoArv *novo;
    NoArv *pai=a1->raiz;
    int flag=0;
    novo = (NoArv*) malloc(sizeof(NoArv));
    novo->info = d.id;
    novo->dir = NULL;
    novo->esq = NULL;
    if (a1->raiz == NULL)
    {
        a1->raiz = novo;
        return;
    }
    else
    {
        while (flag==0)
        {
            if (d.id > pai->info)
            {
                if (pai->dir != NULL)
                {
                    pai = pai->dir;
                }
                else
                {
                    pai->dir = novo;
                    flag=1;
                }
            }
            else
            {
                if (pai->esq != NULL)
                {
                    pai = pai->esq;
                }
                else
                {
                    pai->esq = novo;
                    flag=1;
                }
            }
        }
    }
}

void imprime(Dados pai)
{
    printf("%d ", pai->info.id);
    printf("%s | ", pai->info.vendedor);
    printf("%s | ", pai->info.cliente);
    printf("%d/%d/%d | ", pai->info.trans.dia, pai->info.trans.mes, pai->info.trans.ano);
    printf("%d ", pai->info.valor);
}

void Preorder(NoArv *pai)
{
    if (pai->dir != NULL)
    {
        Preorder(pai->dir);
    }
    imprime(pai->info);
    if (pai->esq != NULL)
    {
        Preorder(pai->esq);
    }
}

int gera (void)
{
    return rand() % 900 + 100;
}

int main ()
{
    //setlocale(LC_ALL, "portuguese");
    Arv *a1;
    a1 = CriaArvore();
    Dados A;
    int num;

     do {
            do {
                printf("\n-----------------------------------------------------\n");
                printf("\t\t\tMENU\n");
                printf("-----------------------------------------------------\n\n");
                printf("1. Insira uma nova venda.\n\n");
                printf("2. Imprimir todas as vendas.\n\n");
                printf("3. Buscar um pet.\n\n");
                printf("4. Imprimir relatorio dos pets na fila.\n\n");
                printf("5. Imprimir proximo pet a ser atendido. \n\n");
                printf("6. Imprimir todos os pets que ja foram atendidos. \n\n");
                printf("7. Finalizar o sistema. \n\n");
                printf("-----------------------------------------------------\n\n");
                printf("Insira sua opcao: ");
                scanf("%d", &num);
                limpa();
                } while (num<1 || num>7);

        switch (num) {
            case 1:
                printf("-----------------------------------------------------");
                printf("\n\t\tFicha de cadastro\n");
                printf("-----------------------------------------------------");


                A.id = gera();
                printf("\nID da venda: %d", A.id);

                printf("\n\nNome do cliente: ");
                scanf("%s", A.cliente);

                printf("\n\nNome do vendedor: ");
                scanf("%s", A.vendedor);

                printf("\nData da transação: ");
                printf("\n Dia: ");
                scanf("%d", &A.trans.dia);
                while (A.trans.dia < 1 || A.trans.dia > 31)
                {
                    printf(" Valor invalido, digite novamente: ");
                    scanf("%d", &A.trans.dia);
                }
                printf(" Mes: ");
                scanf("%d", &A.trans.mes);
                while (A.trans.mes < 1 || A.trans.mes > 12)
                {
                    printf(" Valor invalido, digite novamente: ");
                    scanf("%d", &A.trans.mes);
                }
                printf(" Ano: ");
                scanf("%d", &A.trans.ano);
                while (A.trans.ano > 2025)
                {
                    printf(" Valor invalido, digite novamente: ");
                    scanf("%d", &A.trans.ano);
                }

                printf("\nValor da transação: ");
                scanf("%d", &A.valor);


                insere(a1, A);

                break;

            case 2:

                break;

            case 3:
                do
                {
                printf("\nComo deseja buscar? [1: ID | 2: Nome]: ");
                    scanf("%d", &b);
                        if(b==1)
                        {
                            printf(" ID do animal que deseja buscar: ");
                            scanf("%d", &buscado1);
                            busca_resul = buscaid(geral, buscado1);
                        }
                        else if(b==2)
                        {
                            printf(" Nome do animal que deseja buscar: ");
                            scanf("%s", buscado);
                            busca_resul = buscanome(geral, buscado);
                        }
                        else
                        {
                            printf("Opcao invalida, digite novamente: ");
                        }
                } while(b<1 || b>2);

                if (busca_resul == 0)
                {
                    printf("\nO animal procurado nao esta cadastrado.");
                }
                fflush(stdin);
                getchar();
                limpa();
                break;

            case 4:
                printf("Relatorio dos pets");
                printf("\n------------------------------------------------------");

                if(vaziaFila(emerg)==1)
                {
                    printf("\nNao ha pets na fila de emergencia ;)");
                }
                else
                {
                    imprime(emerg);
                }
                printf("\n");
                if(vaziaFila(normal)==1)
                {
                    printf("\nNao ha pets na fila normal ;)");
                }
                else
                {
                    imprime(normal);
                }
                limpa();
                break;

            case 5:
                if (vaziaFila(emerg)==1)
                {
                    imprime_prox(normal);
                }
                else
                {
                    imprime_prox(emerg);
                }
                limpa();
                break;
            case 6:
                if (vaziaFila(atendidos)==1)
                {
                    printf("Nenhum pet foi atendido.");
                }
                else
                {
                    imprime(atendidos);
                }
                limpa();
                break;

        }
    } while (num!=7);
    return 0;
}

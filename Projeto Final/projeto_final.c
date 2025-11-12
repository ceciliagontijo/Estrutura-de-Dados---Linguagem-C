#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    Dados info;
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
    novo->info = d;
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
            if (d.id > pai->info.id)
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

void imprime(Dados d)
{
    printf("\n\n");
    printf("%d ", d.id);
    printf("%s | ", d.vendedor);
    printf("%s | ", d.cliente);
    printf("%d/%d/%d | ", d.trans.dia, d.trans.mes, d.trans.ano);
    printf("%.2f ", d.valor);
}

void BuscaVendas(NoArv *pai, char vendedor[50])
{
    if (pai->dir != NULL)
    {
        BuscaVendas(pai->dir, vendedor);
    }
    if (pai->esq != NULL)
    {
        BuscaVendas(pai->esq, vendedor);
    }
    if(strcmp(pai->info.vendedor, vendedor)==0)
    {
        printf("\n\n");
        printf("%d ", pai->info.id);
        printf("%s | ", pai->info.cliente);
        printf("%d/%d/%d | ", pai->info.trans.dia, pai->info.trans.mes, pai->info.trans.ano);
        printf("%.2f ", pai->info.valor);
    }
}

void InOrder(NoArv *pai)
{
      if (pai->dir != NULL)
    {
        InOrder(pai->dir);
    }
    imprime(pai->info);
    if (pai->esq != NULL)
    {
        InOrder(pai->esq);
    }
}

void ValoresAbaixo(NoArv *pai, float num)
{
     if (pai->dir != NULL)
    {
        ValoresAbaixo(pai->dir, num);
    }
    if (pai->esq != NULL)
    {
        ValoresAbaixo(pai->esq, num);
    }
    if(pai->info.valor < num)
    {
        printf("\n\n");
        printf("%d ", pai->info.id);
        printf("%s | ", pai->info.vendedor);
        printf("%s | ", pai->info.cliente);
        printf("%d/%d/%d | ", pai->info.trans.dia, pai->info.trans.mes, pai->info.trans.ano);
        printf("%.2f ", pai->info.valor);
    }
}

void ValoresAcima(NoArv *pai, float num)
{
     if (pai->dir != NULL)
    {
        ValoresAcima(pai->dir, num);
    }
    if (pai->esq != NULL)
    {
        ValoresAcima(pai->esq, num);
    }
    if(pai->info.valor > num)
    {
        printf("\n\n");
        printf("%d ", pai->info.id);
        printf("%s | ", pai->info.vendedor);
        printf("%s | ", pai->info.cliente);
        printf("%d/%d/%d | ", pai->info.trans.dia, pai->info.trans.mes, pai->info.trans.ano);
        printf("%.2f ", pai->info.valor);
    }
}

int TotalVendas (NoArv *pai)
{
    int cont = 1;
    if(pai == NULL)
    {
        return 0;
    }
    if (pai->dir != NULL)
    {
        cont = cont + TotalVendas(pai->dir);
    }
    if(pai->esq != NULL)
    {
        cont = cont + TotalVendas(pai->esq);
    }
    return cont;
}

float TotalFaturamento (NoArv *pai)
{
    float soma = pai->info.valor;
    if(pai == NULL)
    {
        return 0;
    }
    if(pai->dir != NULL)
    {
        soma = soma + TotalFaturamento(pai->dir);
    }
    if(pai->esq != NULL)
    {
        soma = soma + TotalFaturamento(pai->esq);
    }
    return soma;
}

int gera (void)
{
    return rand() % 900 + 100;
}

int main ()
{
    Arv *a1;
    a1 = CriaArvore();
    Dados A;
    int num, num2, total_vendas;
    float valor, faturamento;
    char buscado[50];

     do {
            do {
                printf("\n-----------------------------------------------------\n");
                printf("\t\t\tMENU\n");
                printf("-----------------------------------------------------\n\n");
                printf("1. Insira uma nova venda.\n\n");
                printf("2. Imprimir todas as vendas.\n\n");
                printf("3. Buscar as vendas de um determinado vendedor.\n\n");
                printf("4. Visualizar as vendas acima ou abaixo de um determinado valor.\n\n");
                printf("5. Visualizar estatisticas das vendas. \n\n");
                printf("6. Remover uma venda. \n\n");
                printf("7. Finalizar o sistema. \n\n");
                printf("-----------------------------------------------------\n\n");
                printf("Insira sua opcao: ");
                scanf("%d", &num);
                } while (num<1 || num>7);

        switch (num) {
            case 1:
                printf("-----------------------------------------------------");
                printf("\n\t\tFicha de cadastro\n");
                printf("-----------------------------------------------------");


                A.id = gera();
                printf("\nID da venda: %d", A.id);

                printf("\n\nNome do vendedor: ");
                scanf("%s", A.vendedor);

                printf("\n\nNome do cliente: ");
                scanf("%s", A.cliente);

                printf("\nData da transacao: ");
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
                    printf("Valor invalido, digite novamente: ");
                    scanf("%d", &A.trans.ano);
                }

                printf("\nValor da transacao: ");
                scanf("%f", &A.valor);


                insere(a1, A);

                break;

            case 2:
                InOrder(a1->raiz);
                break;

            case 3: // imprimir mensagem quando o vendedor nao tem nenhuma venda
                printf("Nome do vendedor que deseja buscar as vendas: ");
                scanf("%s", buscado);
                BuscaVendas(a1->raiz, buscado);
                break;

            case 4: // imprimir mensagem quando nao tem nenhuma venda abaixo ou acima
                printf("Digite o valor: ");
                scanf("%f", &valor);
                printf("Qual lista deseja visualizar:");
                printf("\n1 - Lista de vendas abaixo do valor");
                printf("\n2 - Lista de vendas acima do valor\n");
                scanf("%d", &num2);
                // fazer do while pra só conseguir responder 1 e 2
                if(num2==1)
                {
                    ValoresAbaixo(a1->raiz, valor);
                }
                else
                {
                    ValoresAcima(a1->raiz, valor);
                }

                break;

            case 5:
                total_vendas = TotalVendas(a1->raiz);
                printf("\nNumero total de vendas = %d", total_vendas);
                faturamento = TotalFaturamento(a1->raiz);
                printf("\nSoma total do faturamento = %.2f", faturamento);

        }
    } while (num!=7);
    return 0;
}

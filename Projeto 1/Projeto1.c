#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "biblioteca_projeto1.h"
#include <ctype.h>
#include <conio.h>
#include<time.h>//necessário p/ função time()

#include <unistd.h>

int main ()
{
    setlocale(LC_ALL, "portuguese");
    Fila* emerg;
    Fila* normal;
    Fila* atendidos;
    Fila* geral;
    emerg = CriaFila();
    normal = CriaFila();
    atendidos = CriaFila();
    geral = CriaFila();
    int num, id, idade, prior, dia, mes, ano, busca_resul;
    char nome[50], buscado[50];
    char especie[30];

            printf("\n");
            printf("          /^ ^\\\n");
            printf("         / 0 0 \\\n");
            printf("         V\\ Y /V\n");
            printf("          / - \\\n");
            printf("         /     \\\n");
            printf("        V__) (__V\n");
            printf("\n");

    do {
        do {


            printf("\n\n-----------------------------------------------------\n");
            printf("\t\t\tMENU\n");
            printf("-----------------------------------------------------\n\n");
            printf("1. Insira um pet na fila de atendimento.\n\n");
            printf("2. Atender um pet.\n\n");
            printf("3. Buscar um pet.\n\n");
            printf("4. Imprimir relatorio dos pets na fila.\n\n");
            printf("5. Imprimir proximo pet a ser atendido. \n\n");
            printf("6. Imprimir todos os pets que ja foram atendidos. \n\n");
            printf("7. Finalizar o sistema. \n\n");
            printf("-----------------------------------------------------\n\n");
            printf("Insira sua opcao: ");
            scanf("%d", &num);
            //system("cls");
        } while (num<1 || num>7);
        switch (num) {
            case 1:
                // Dados A;
                printf("-----------------------------------------------------");
                printf("\n\t\tFicha de cadastro\n");
                printf("-----------------------------------------------------");

                id = gera();
                printf("\nID do pet: %d", id);

                printf("\nNome do pet: ");
                scanf("%s", nome);

                printf("\nIdade do pet: ");
                scanf("%d", &idade);

                while (idade < 0 || idade > 25)
                {
                    printf("Valor inválido, digite novamente: ");
                    scanf("%d", &idade);
                }

                printf("\nEspecie do pet: ");
                scanf("%s", especie);

                printf("\nData de nascimento: ");
                printf("\n Dia: ");
                scanf("%d", &dia);
                while (dia < 1 || dia > 31)
                {
                    printf(" Valor invalido, digite novamente: ");
                    scanf("%d", &dia);
                }
                printf(" Mês: ");
                scanf("%d", &mes);
                while (mes < 1 || mes > 12)
                {
                    printf(" Valor invalido, digite novamente: ");
                    scanf("%d", &mes);
                }

                printf(" Ano: ");
                scanf("%d", &ano);
                while (ano < 2000 || ano > 2025)
                {
                    printf(" Valor invalido, digite novamente: ");
                    scanf("%d", &ano);
                }

                printf("\nPrioridade do pet [0: Emergencia | 1: Normal]: ");
                scanf("%d", &prior);


                if (prior==0)
                {
                    insere_pet(emerg, nome, idade, especie, prior, dia, mes, ano, id);
                }
                else
                {
                    insere_pet(normal, nome, idade, especie, prior, dia, mes, ano, id);
                }
                    insere_pet(geral, nome, idade, especie, prior, dia, mes, ano, id);

                break;

            case 2:
                if (vaziaFila(emerg)==1)
                {
                    atende(normal, atendidos, geral);
                }
                else
                {
                    atende(emerg, atendidos, geral);
                }
                printf("\n------------------------------------------------------");
                printf("\n\t\tPet Atendido\n");
                //system("cls");
                break;

            case 3:
                printf("\nComo deseja buscar? (1 - ID / 2 - Nome)");
                scanf("%d", &b);
                if(b==1)
                {
                printf("\nID do animal que deseja buscar: ");
                scanf("%s", buscado);
                busca_resul = buscaid(geral, buscado);
                }
                else
                {
                printf("\nNome do animal que deseja buscar: ");
                scanf("%s", buscado);
                busca_resul = buscanome(geral, buscado);
                }

                if (busca_resul == 0)
                {
                    printf("\nO animal procurado não está cadastrado.");
                }


                break;

            case 4:
                printf("Emergencia: ");
                imprime(emerg);
                printf("\n");
                printf("\nAtendimento normal: ");
                imprime(normal);
                /*fflush(stdin);
                getchar();
                system("cls");*/
                //system("cls");
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
                //system("cls");
               // getchar();
               // getchar();
                break;
            case 6:
                 imprime(atendidos);
                // system("cls");
                 break;
        }
    } while (num!=7);
    return 0;
}

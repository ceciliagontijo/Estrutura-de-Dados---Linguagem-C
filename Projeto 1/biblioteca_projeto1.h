#ifndef lib_h_include
#define lib_h_included

#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include<time.h>//necessário p/ função time()

typedef struct data
{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct dados
{
    char nome[50];
    int idade;
    int id;
    char especie[30];
    int atendido;
    int prior;
    Data aniv;
}Dados;

typedef struct no
{
    struct no *prox;
    Dados info;
}No;

typedef struct lista
{
    No* ini;
    No* fim;
}Fila;

Fila* CriaFila(void)
{
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

int vaziaFila(Fila* f)
{
    if (f->ini == NULL) return 1;
    else return 0;
}

No* ins_fim(No *fim, char nome[50], char idade, char especie[30], int prior, int dia, int mes, int ano, int id)
{
    //No* ins_fim(No *fim, Dados A)
    No* novo = (No*)malloc(sizeof(No));
    //novo->info=A
    strcpy(novo->info.nome, nome);
    novo->info.idade = idade;
    strcpy(novo->info.especie, especie);
    novo->info.prior = prior;
    novo->info.aniv.dia = dia;
    novo->info.aniv.mes = mes;
    novo->info.aniv.ano = ano;
    novo->info.id = id;
    novo->info.atendido = 0;
    novo->prox = NULL;
    if (fim != NULL)
    {
        fim->prox = novo;
    }
    return novo;
}

void insere_pet(Fila *f, char nome[50], int idade, char especie[30], int prior, int dia, int mes, int ano, int id)
{
    f->fim = ins_fim(f->fim, nome, idade, especie, prior, dia, mes, ano, id);
    if (f->ini == NULL)
    {
        f->ini = f->fim;
    }
}

int gera (void)
{
    int j;

    srand(time(NULL));

    j=rand() % 900 + 100;
    //printf("%d ", j);
    return j;
}


void transferencia(Fila *atendidos, Fila *f)
{
    No *aux = f->ini;
    f->ini = aux->prox;
    if (f->ini == NULL) {
        f->fim = NULL;
    }
    aux->prox = NULL;
    if (atendidos->ini == NULL) {
        atendidos->ini = aux;
        atendidos->fim = atendidos->ini;
    }
    else {
        atendidos->fim->prox = aux;
        atendidos->fim = aux;
    }
}


void atende(Fila *f, Fila *atendidos, Fila *geral)
{
    No* aux = f->ini;
    No* g = geral->ini;
    while (g != NULL)
    {
        if (strcmp(g->info.nome, aux->info.nome) == 0)
        {
            g->info.atendido = 1;   // marca no geral
        }
            g = g->prox;
    }
    transferencia(atendidos, f);
}

void imprime_prox(Fila *f)
{
    No* aux = f->ini;
    if(vaziaFila(f)==1)
    {
        printf("\nNao ha nenhum pet na fila de atendimento.");
    }
    else
    {
        printf("\n%s | ", aux->info.nome);
        printf("%s | ", aux->info.especie);
        if (aux->info.prior==1)
        {
            printf("Atendimento normal | ");
        }
        else
        {
            printf("Atendimento emergencial | ");
        }
    }
}

int buscaid(Fila *f, int id)
{
    No* aux = f->ini;
    while (aux != NULL)
    {
        if (aux->info.id == id)
        {
            printf("\nO animal buscado está cadastrado!");
            printf("\n%d |", aux-> info.id);
            printf("%s | ", aux->info.nome);
            printf("%s | ", aux->info.especie);
            if (aux->info.prior==1)
            {
                printf("Atendimento normal | ");
            }
            else
            {
                printf("Atendimento emergencial | ");
            }
            if (aux->info.atendido == 0)
            {
                printf("Não foi atendido");
            }
            else
            {
                printf("Já foi atendido");
            }
            return 1;
        }
        else
        {
            aux = aux->prox;
        }
    }
    return 0;
}

int buscanome(Fila *f, char nome[50])
{
    No* aux = f->ini;
    while (aux != NULL)
    {
        if (strcmp(aux->info.nome, nome)==0)
        {
            printf("\nO animal buscado está cadastrado!");
            printf("\n%d |", aux-> info.id);
            printf("%s | ", aux->info.nome);
            printf("%s | ", aux->info.especie);
            if (aux->info.prior==1)
            {
                printf("Atendimento normal | ");
            }
            else
            {
                printf("Atendimento emergencial | ");
            }
            if (aux->info.atendido == 0)
            {
                printf("Não foi atendido");
            }
            else
            {
                printf("Já foi atendido");
            }
            return 1;
        }
        else
        {
            aux = aux->prox;
        }
    }
    return 0;
}

void imprime(Fila *f)
{
    No* aux = f->ini;
    while (aux != NULL)
    {
        printf("\n%d | ", aux->info.id);
        printf("%s | ", aux->info.nome);
        printf("%s | ", aux->info.especie);
        printf("%d | ", aux->info.idade);
        printf("%d/%d/%d | ", aux->info.aniv.dia, aux->info.aniv.mes, aux->info.aniv.ano);
        if (aux->info.prior==1)
        {
            printf("Atendimento normal");
        }
        else
        {
            printf("Atendimento emergencial");
        }
        aux = aux->prox;
    }
}

#endif // fila_h_include

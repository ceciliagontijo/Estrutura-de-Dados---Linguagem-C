#include <stdio.h>
#include <stdlib.h>

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

void insere(Arv *a1, int num)
{
    NoArv *novo;
    NoArv *pai=a1->raiz;
    int flag=0;
    novo = (NoArv*) malloc(sizeof(NoArv));
    novo->info = num;
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
            if (num > pai->info)
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

void imprime(int num)
{
    printf("%d ", num);
}

int Busca(NoArv *pai, int num)
{
    if (pai->info == num)
    {
        return 1;
    }
    else
    {
        if (num > pai->info)
        {
            if (pai->dir != NULL)
            {
                return Busca(pai->dir, num);
            }
            else
            {
                return 0;
            }
        }
        if (num < pai->info)
        {
            if (pai->esq != NULL)
            {
                return Busca(pai->esq, num);
            }
            else
            {
                return 0;
        }
        }
    }
}

int Soma(NoArv *pai)
{
    int S = pai->info;
    if (pai->dir != NULL)
    {
        S = S + Soma(pai->dir);
    }
    if (pai->esq != NULL)
    {
        S = S + Soma(pai->esq);
    }
    return S;
}

int MenorElemento (NoArv *pai, int menor)
{
    if (pai->info < menor)
    {
        menor = pai->info;
    }
    if (pai->dir != NULL)
    {
        menor = MenorElemento(pai->dir, menor);
    }
    if (pai->esq != NULL)
    {
        menor = MenorElemento(pai->esq, menor);
    }
    return menor;
}

void Preorder(NoArv *pai)
{
    imprime(pai->info);
    if (pai->dir != NULL)
    {
        Preorder(pai->dir);
    }
    if (pai->esq != NULL)
    {
        Preorder(pai->esq);
    }
}

int No(NoArv *pai, int num)
{
    if (Busca(pai,num)==0)
    {
        printf("Elemento não existe na árvore\n");
        return 0;
    }
    else
    {
        if (pai->info == num)
        {
            printf("\nElemento escolhido é a raíz\n");
            return pai->info;
        }
        if (pai->dir != NULL && pai->dir->info == num || pai->esq != NULL && pai->esq->info == num)
        {
            return pai->info;
        }
        else
        {
            if (pai->dir != NULL)
            {
                return No(pai->dir, num);
            }
            if (pai->esq != NULL)
            {
                return No(pai->esq, num);
            }
            return 0;
        }
    }
}

int Maior(NoArv *pai, int num)
{
    int soma;
        if (pai->info > num)
        {
            soma = 1;
            if (pai->dir!=NULL)
            {
                soma = soma + Maior(pai->dir, num);
            }
            if (pai->esq!=NULL)
            {
                soma = soma + Maior(pai->esq, num);
            }
            return soma;
        }
        else
        {
            soma = 0;
            if (pai->dir!=NULL)
            {
                soma = soma + Maior(pai->dir, num);
            }
            if (pai->esq!=NULL)
            {
                soma = soma + Maior(pai->esq, num);
            }
            return soma;
        }

}

int main()
{
    Arv *a1;
    a1 = CriaArvore();
    int num, valor, busca, resul, maiores, menor, soma, pai, no;
    printf("Quantidade de elementos: ");
    scanf("%d", &num);
    while (num>0)
    {
        printf("\nElemento = ");
        scanf("%d", &valor);
        insere(a1, valor);
        num--;
    }
    Preorder(a1->raiz);
    printf("\nElemento que deseja buscar: ");
    scanf("%d", &busca);
    resul = Busca(a1->raiz, busca);
    if (resul == 1)
    {
        printf("\nElemento encontrado!");
    }
    else
    {
        printf("\nElemento não encontrado!");
    }

    printf("\nElemento que deseja verificar quantos nós são maiores: ");
    scanf("%d", &busca);
    maiores = Maior(a1->raiz, busca);
    printf("\nQuantidade de maiores = %d", maiores);

    menor = MenorElemento(a1->raiz, 100);
    printf("\nMenor elemento = %d", menor);

    soma = Soma(a1->raiz);
    printf("\nSoma = %d", soma);

    printf("\nNó = ");
    scanf("%d", &no);
    pai = No(a1->raiz, no);
    printf("Pai = %d", pai);

    return 0;
}
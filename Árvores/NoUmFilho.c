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

int Busca(NoArv *pai, int num) // recursiva
{
    if (pai->info == num)
    {
        return 1;
    }
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

int NoUm(NoArv *pai, int cont)
{
    if (pai->dir != NULL)
    {
        cont = NoUm(pai->dir, cont);
    }
    if (pai->esq != NULL)
    {
        cont = NoUm(pai->esq, cont);
    }
    if ((pai->dir != NULL && pai->esq == NULL) || (pai->dir == NULL && pai->esq != NULL))
    {
        cont++;
    }
    return cont;
}



int main()
{
    Arv *a1;
    a1 = CriaArvore();
    int num, valor, cont=0;
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
    cont = NoUm(a1->raiz, cont);
    printf("\nQuantidade de nós com só um filho: %d", cont);

    return 0;
}
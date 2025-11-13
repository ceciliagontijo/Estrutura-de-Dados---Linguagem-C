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

int buscaele(NoArv *pai, int num)
{
    while (1)
    {
        if (pai->info == num)
        {
            return 1;
        }
        if (num > pai->info)
        {
            if (pai->dir != NULL)
            {
                pai = pai->dir;
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
                pai = pai->esq;
            }
            else
            {
                return 0;
            }
        }
    }
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

int conta(NoArv *pai, int cont)
{
    cont = 1;
    if (pai->dir != NULL)
    {
        cont = cont + conta(pai->dir, cont);
    }
    if (pai->esq != NULL)
    {
        cont = cont + conta(pai->esq, cont);
    }
    return cont;
}

int quant (NoArv *pai, int num)
{
    int cont = 0;
    if (buscaele(pai, num)==0)
    {
        printf("\nO nó não existe.");
        return 0;
    }
    else
    {
        while (pai->info != num)
        {
            if (num > pai->info)
            {
                pai = pai->dir;
            }
            if (num < pai->info)
            {
                pai = pai->esq;
            }
        }
        cont = conta(pai->dir, cont);
    }
    return cont;

}
int main()
{
    Arv *a1;
    a1 = CriaArvore();
    int N, num, valor, qnt;
    printf("Quantidade de elementos: ");
    scanf("%d", &N);
    while (N>0)
    {
        printf("\nElemento = ");
        scanf("%d", &valor);
        insere(a1, valor);
        N--;
    }
    Preorder(a1->raiz);

    printf("\nNó: ");
    scanf("%d", &num);

    qnt = quant(a1->raiz, num);

    printf("\nQuantidade de nós maior que %d = %d", num, qnt);
return 0;
}
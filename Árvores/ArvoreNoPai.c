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
                return 0;
            }
        if (num < pai->info)
        {
            if (pai->esq != NULL)
            {
                return Busca(pai->esq, num);
            }
                return 0;
            }
    }
}

void No(NoArv *pai, NoArv *aux, int num) // recursiva
{
    if (pai->info == num)
    {
        if (aux == NULL)
        {
            printf("\nElemento escolhido é a raíz\n");
        }
        else
        {
            printf("\nPai = %d\n", aux->info);
        }
    }
    else
    {
        if (num > pai->info)
        {
            if (pai->dir != NULL)
            {
                No(pai->dir, pai, num);
            }
            else
            {
                printf("\nElemento não existe na árvore.");
            }
        }
        if (num < pai->info)
        {
            if (pai->esq != NULL)
            {
                No(pai->esq, pai, num);
            }
            else
            {
                printf("\nElemento não existe na árvore.");
            }
        }
    }
}

int BuscaPai(NoArv *pai, NoArv *aux, int num) // iterativa
{
    if (pai->info == num)
    {
        if (aux == NULL)
        {
            printf("\nElemento escolhido é a raíz\n");
        }
    }
    if (Busca(pai, num)==0)
    {
        printf("\nElemento não existe na árvore");
        return 0;
    }
    else
    {
        while (pai->info != num)
        {
            if (num > pai->info)
            {
                if (pai->dir != NULL)
                {
                    aux = pai;
                    pai = pai->dir;
                }
            }
            if (num < pai->info)
            {
                if (pai->esq != NULL)
                {
                    aux = pai;
                    pai = pai->esq;
                }
            }
        }
    }
    return aux->info;
}

int main()
{
    Arv *a1;
    a1 = CriaArvore();
    int num, valor, pai, no;
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
    printf("\nNó = ");
    scanf("%d", &no);
    NoArv *aux = NULL;
    No(a1->raiz, aux, no);
    aux = NULL;
    pai = BuscaPai(a1->raiz, aux, no);
    printf("Pai = %d", pai);
}
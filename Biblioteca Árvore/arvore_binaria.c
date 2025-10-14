#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ARVORE.h"

int main()
{
    setlocale(LC_ALL, "portuguese");
    Arv *a1;
    a1 = CriaArvore();
    int qnt, valor, busca, resul;
    printf("\nQuantidade de elementos: ");
    scanf("%d", &qnt);
    while (qnt > 0)
    {
        printf("Elemento = ");
        scanf("%d", &valor);
        insere(a1, valor);
        qnt--;
    }
    PreOrder(a1->raiz);
    printf("\nElemento que deseja buscar: ");
    scanf("%d", &busca);
    resul = Busca(a1->raiz, busca);
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "PILHA.h"

int main()
{
    setlocale(LC_ALL, "portuguese");
    Pilha* p;
    int valor, vazia;
    p = CriaPilha();
    push(p, 8);
    push(p, 2);
    imprime(p);
    valor = pop(p);
    printf("\nValor removido = %d\n", valor);
    imprime(p);
    vazia = vaziaPilha(p);
    if (vazia==1)
    {
        printf("\nA pilha está vazia!");
    }
    else
    {
         printf("\nA pilha não está vazia!");
    }


    p = liberaPilha(p);
    if (p==NULL)
    {
        printf("\nA pilha foi apagada \n");
    }

    return 0;

}

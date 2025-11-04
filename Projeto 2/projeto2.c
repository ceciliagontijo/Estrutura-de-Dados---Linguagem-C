#include <stdlib.h>  // rand, srand
#include <time.h>    // time

#include <stdio.h>
#include <time.h>

typedef struct {
    int chave;
    double valor;
}item;


void geraVetorAleatorio(item vetor[], int tamanho, int sem) {
    srand(sem);

    // Gera a primeira chave aleatória entre 100000 e 300000
    vetor[0].chave = 100000 + rand() % 200001;

    // Gera o valor correspondente (aleatório entre 100000 e 300000)
    vetor[0].valor = 100000.0f + ((float)rand() / RAND_MAX) * 200000.0f;

    // A partir do segundo elemento, incrementa 100 na chave
    for (int i = 1; i < tamanho; i++) {
        vetor[i].chave = vetor[i - 1].chave + 100;

        // Valor continua aleatório (se quiser, pode seguir outro padrão)
        vetor[i].valor = 100000.0f + ((float)rand() / RAND_MAX) * 200000.0f;
    }
}


void troca(item *a, item *b) {
    item temp = *a;
    *a = *b;
    *b = temp;

}



void insercao(item *v, int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        for (j=i;j>0;j--){
            if (v[j - 1].chave < v[j].chave) {
                // ordem decrescente
                troca(&v[j - 1], &v[j]);
            }
        }
    }
}


int particao(item *v, int LI, int LS)
{
    int aux, pivo, e=LI, d=LS;
    pivo=v[e].chave;
    while(e < d)
    {
        while((v[e].chave>=pivo)&& (e<LS)) { e++;}
        while((v[d].chave<pivo)&&(d>LI)) {d--;}
        if(e<d)
        {
            aux = v[e].chave; v[e].chave=v[d].chave; v[d].chave=aux;
        }
    }
    aux = v[LI].chave; v[LI].chave=v[d].chave; v[d].chave=aux;
    return d;
}

void quicksort(item *v, int LI, int LS)
{
    if(LI<LS)
    {
        int p,i;
        p = particao(v,LI,LS);
        quicksort(v,LI,p-1);
        quicksort(v,p+1,LS);
    }
}



int main()
{
    int i;
    int TAM=15;
    item *vetor = malloc(TAM * sizeof *vetor);
    clock_t inicio, fim;
    double tempo_insercao, tempo_quick;

    geraVetorAleatorio(vetor, TAM, 800);

    insercao(vetor,TAM);
    quicksort(vetor,0,TAM-1);
    printf("\n\n\n\n");
    for (i = 0; i < TAM; i++) {
        printf("Chave %d: %d\n",i, vetor[i].chave);
    }
    free(vetor);
    vetor = NULL;
    return 0;
}


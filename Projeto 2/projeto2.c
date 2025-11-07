#include <stdlib.h>  // rand, srand
#include <time.h>    // time

#include <stdio.h>


typedef struct {
    int chave;
    double valor;
}item;

void geraCrescente(item vetor[], int tamanho, int sem) {
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




void geraAleatorio(item v[], int n, int seed) {
    srand(seed); // usa a mesma semente para repetir o mesmo conjunto

    for (int i = 0; i < n; i++) {
        v[i].chave = 100000 + rand() % 200001;               // entre 100000 e 300000
        v[i].valor = 100000.0 + ((double)rand() / RAND_MAX) * 200000.0; // entre 100000 e 300000
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
        while((v[e].chave>=pivo)&& (e<LS))
            {
                e++;
            }
        while((v[d].chave<pivo)&&(d>LI))
        {
            d--;
        }
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

int particaoLS(item *v, int LI, int LS)
{
    int aux, pivo, e = LI, d = LS;
    pivo = v[d].chave;  // pivô é o último elemento

    while (e < d)
    {
        while ((v[e].chave > pivo) && (e < LS))
        {
                e++;
        }
        while ((v[d].chave <= pivo) && (d > LI))
        {
            d--;
        }

        if (e < d)
        {
            aux = v[e].chave;
            v[e].chave = v[d].chave;
            v[d].chave= aux;
        }
    }

    aux = v[LS].chave;
    v[LS].chave = v[e].chave;
    v[e].chave = aux;

    return e;  // retorna a posição do pivô
}

int particaoM(item *v, int LI, int LS)
{
    int aux, pivo, e = LI, d = LS;
    pivo = v[(LS + LI) / 2].chave;  // pivô central

    while (e < d)
    {
        while ((v[e].chave > pivo) && (e < LS))
        {
            e++;
        }
        while ((v[d].chave < pivo) && (d > LI))
        {
                d--;
        }

        if (e < d)
        {
            aux = v[e].chave;
            v[e].chave = v[d].chave;
            v[d].chave = aux;
            e++;
            d--;
        }
    }

    return e;
}


void quicksortLS(item *v, int LI, int LS)
{
    if(LI<LS)
    {
        int p,i;
        p = particaoLS(v,LI,LS);
        quicksortLS(v,LI,p-1);
        quicksortLS(v,p+1,LS);
    }
}


void quicksortM(item *v, int LI, int LS)
{
    if(LI<LS)
    {
        int p,i;
        p = particaoM(v,LI,LS);
        quicksortM(v,LI,p-1);
        quicksortM(v,p+1,LS);
    }
}



int main()
{
    int i;
    int TAM=500000;
    item *vetor = malloc(TAM * sizeof *vetor);
    clock_t inicio, fim;
    float tempo_insercao, tempo_quick;
    geraAleatorio(vetor, TAM,1260);
    inicio = clock();
    insercao(vetor, TAM);
    fim = clock();
    tempo_insercao = (float)(fim - inicio) / CLOCKS_PER_SEC;
    /*for (i = 0; i < TAM; i++) {
        printf("Chave %d: %d\n",i, vetor[i].chave);
    }*/

    printf("Tempo de execução: %.10f segundos\n", tempo_insercao);
    free(vetor);
    vetor = NULL;
    return 0;
}



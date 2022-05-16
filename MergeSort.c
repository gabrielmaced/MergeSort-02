#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100000

void mergeInt(int v[], int inicio, int fim, int aux[]) {
    int meio = (inicio + fim) / 2;
    int i = inicio;
    int j = meio + 1;
    int k = 0;
    while (i <= meio || j <= fim) {
        if (i <= meio && (j > fim || v[i] < v[j])) {
            aux[k] = v[i];
            i++;
        } else {
            aux[k] = v[j];
            j++;
        }
        k++;
    }
}
 
void mergeSortInt(int v[], int inicio, int fim, int aux[]) {
    int meio = (inicio + fim) / 2;
 
    if (inicio < fim) {
        mergeSortInt(v, inicio, meio, aux);
        mergeSortInt(v, meio + 1, fim, aux);
        mergeInt(v, inicio, fim, aux);
 
        for (int l = 0; l < fim - inicio + 1; l++) {
            v[inicio + l] = aux[l];
        }
    }
}
 
void mergeSort(int v[], int tamanho) {
    int *aux = malloc(sizeof(int) * tamanho);
    mergeSortInt(v, 0, tamanho, aux);
    free(aux);
}
 
int main() {
    int vet[TAM];
    int i;
    int j = 0;
    clock_t tempo;
    srand(time(NULL));
    
    for(i = TAM; i>0; i--){
        vet[j] = i;
        j++;
    }
    
    //for(i= 0; i<TAM; i++){ VETOR ORDEM CRESCENTE
   //     vet[i] = i+1;
    //}
   
   //for(i=0; i<TAM;i++){  VETOR ALEATORIO
   //    vet[i] = rand()%N;
   //}
    printf("\n\n ");
    tempo = clock();
    mergeSort(vet, TAM);
    tempo = clock() - tempo;
    printf("Tempo Execução : %f", ((float)tempo)/CLOCKS_PER_SEC);
    
}

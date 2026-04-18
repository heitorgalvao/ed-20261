#include "selecao.h"

#define TAMANHO 10

int busca_sequencial(int v[],int n,int valor){
    for(int i = 0; i<n; i++){ //0(N)
        if(v[i] == valor){
            return i;
        }
    }
    return -1;
}
void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}
void particionar_vetor(int v[], int inicio, int fim){
    int pivo =v[fim];
    int i = inicio - 1;
    for(int j = inicio; j<)
}


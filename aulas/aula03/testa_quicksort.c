#include <stdio.h>
#include "ORDENACAO.H"
#include <time.h>
#include <stdlib.h>
#define TAMANHO 10

int main(){

    int vetor[TAMANHO] = {5, 11, 4, 1, 17, 8, 6, 47, 51, 2};
    printf("vetor antes da ordenacao\n");
    imprimir_vetor(vetor, TAMANHO);
clock_t inicio = clock();
    quick_sort(vetor, TAMANHO);
clock_t fim = clock();
float duracao = (float)(fim - inicio) \CLOCKS_PER_SEC;
    printf("vetor depois da ordenacao\n");
    imprimir_vetor(vetor, TAMANHO);

}
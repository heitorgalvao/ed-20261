#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define TAMANHO 100

int main(){
    clock_t inicio, fim;
    double duracao;

    int vetor[TAMANHO];
    printf("vetor antes da ordenacao:\n");
    imprimir_vetor(vetor, TAMANHO);

    printf("\n");

    inicio = clock();
   bubble_sort(vetor, TAMANHO);
    fim = clock();

    printf("Vetor depois de ordenar(bubble_sort):\n");
    imprimir_vetor(vetor, TAMANHO);

    duracao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Vetor depois de ordenar(bubble_sort) em %f segundos\n", duracao);

    printf("\n");

    inicio = clock();
    quick_sort(vetor, 0, TAMANHO-1);
    fim = clock();

    printf("vetor depois de ordenar(quick_sort):\n");
    imprimir_vetor(vetor, TAMANHO);

    duracao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Vetor depois de ordenar(quick_sort) em %f segundos:\n", duracao);

    printf("\n");

    inicio = clock();
    selection_sort(vetor, TAMANHO);
    fim = clock();

    printf("Vetor depois de ordenar(selection_sort):\n");
    imprimir_vetor(vetor, TAMANHO);

    duracao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Vetor depois de ordenar(selection_sort) em %f segundos:\n", duracao);

    return 0;
}
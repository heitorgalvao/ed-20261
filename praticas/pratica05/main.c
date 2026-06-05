#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAMANHO 100

int main() {
    clock_t inicio_tempo, final_tempo;
    int v[TAMANHO];
    srand(time(NULL)); // Inicializa a semente aleatória

    printf("[ ");
    for (int i = 0; i < TAMANHO; i++) {
        v[i] = rand() % TAMANHO;
        printf("%i ", v[i]); // Corrigido de 'vetor' para 'v'
    }
    printf("]\n\n");

    printf("Primeiro = %i, Ultimo = %i\n", v[0], v[TAMANHO - 1]);

    int valor;
    printf("Entre com um numero para a Busca Linear e quick: ");
    if (scanf("%i", &valor) != 1) return 1;

    inicio_tempo = clock();
    int resultado_linear = linear_search(v, TAMANHO, valor);
    final_tempo = clock();
    double tempo_linear = (double)(final_tempo - inicio_tempo) / CLOCKS_PER_SEC;

    inicio_tempo = clock();
    int resultado_quick = quick_select(v, 0, TAMANHO - 1, TAMANHO / 2);
    final_tempo = clock();
    double tempo_quick = (double)(final_tempo - inicio_tempo) / CLOCKS_PER_SEC;

    if (resultado_linear != -1) {
        printf("\nBusca Linear: Valor %i encontrado na posicao %i\n", valor, resultado_linear);
    } else {
        printf("\nBusca Linear: Valor %i nao encontrado.\n", valor);
    }

    printf("Quick Select: O elemento que ficaria na posicao %i eh o %i\n", TAMANHO / 2, resultado_quick);
    
    printf("\n--- Performance ---\n");
    printf("Linear Search: %.8f segundos\n", tempo_linear);
    printf("Quick Select:  %.8f segundos\n", tempo_quick);

    return 0;
}

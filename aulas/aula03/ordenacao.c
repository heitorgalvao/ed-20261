#include <stdio.h>
#include "ordenacao.h"

// Função para imprimir o vetor
void imprimir_vetor(int v[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%i, ", v[i]);
    }
    printf("%i] \n", v[n-1]);
}

// Função para particionar o vetor usando o método de partição do Quick Sort
int particionar_vetor(int v[], int inicio, int fim) {

    // Escolhe o último elemento como pivô
    int pivo = v[fim];

    // Índice do "lado dos menores"
    int i = inicio - 1;

    // Percorre o vetor do início até antes do pivô
    for (int j = inicio; j < fim; j++) {

        // Se o elemento atual for menor que o pivô
        if (v[j] < pivo) {

            // Avança o índice dos menores
            i++;

            // Coloca esse elemento na parte dos menores
            troca(&v[i], &v[j]);
        }
    }

    // Coloca o pivô na posição correta (entre menores e maiores)
    troca(&v[i + 1], &v[fim]);

    // Retorna a posição final do pivô
    return i + 1;
}

void troca(int *a, int *b) {
    // Guarda temporariamente o valor atual
    int aux = *a;

    // Move o próximo valor para a posição atual
    *a = *b;

    // Coloca o valor guardado na próxima posição
    *b = aux;
}

void bubble_sort(int v[], int n) { //O(n)
    // Repete o processo várias vezes
    for (int i = 0; i < n - 1; i++) {

        // Percorre a parte ainda não ordenada do vetor
        for (int j = i+1; j < n; j++) {

            // Se o elemento atual for maior que o próximo, troca-os
            if (v[i] > v[j]) {

                // Troca os elementos
                troca(&v[i], &v[j]);
            }
        }
    }
}

void selection_sort(int v[], int inicio, int fim) {
    // Percorre o vetor da posição inicial até a final
    for (int i = inicio; i < fim; i++) {

        // Assume que o menor elemento está na posição atual (i)
        int min = i;

        // Procura o menor elemento no restante do vetor
        for (int j = i + 1; j <= fim; j++) {

            // Se encontrar um valor menor que o atual mínimo
            if (v[j] < v[min]) {

                // Atualiza a posição do menor elemento
                min = j;
            }
        }

        // Troca o menor elemento encontrado com a posição atual
        troca(&v[i], &v[min]);
    }
}

void quick_sort(int v[], int inicio, int fim) {
    // Caso base: só executa se ainda houver elementos para ordenar
    if (inicio < fim) {

        // Particiona o vetor e pega a posição final do pivô
        int pivo = particionar_vetor(v, inicio, fim);

        // Ordena a parte esquerda do pivô
        quick_sort(v, inicio, pivo - 1);

        // Ordena a parte direita do pivô
        quick_sort(v, pivo + 1, fim);
    }

}
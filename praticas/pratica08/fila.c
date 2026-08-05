#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

struct fila_t {
    no_t *inicio;
    no_t *fim;
};

Fila *fila_criar() {
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    
    if (fila != NULL) {
        fila->inicio = NULL;
        fila->fim = NULL;
    }
    return fila;
}

int fila_esta_vazia(Fila *fila) {
    return (fila == NULL || fila->inicio == NULL);
}

void fila_enfileirar(Fila *fila, int valor) {
    if (fila == NULL) return;

    no_t *novo = (no_t *)malloc(sizeof(no_t));
    if (novo == NULL) return; 

    novo->valor = valor;
    novo->proximo = NULL;
    if (fila_esta_vazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

void fila_desenfileirar(Fila *fila) {
    if (fila == NULL || fila_esta_vazia(fila)) return;

    no_t *aux = fila->inicio;

    fila->inicio = fila->inicio->proximo;

    free(aux);

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
}

int fila_inicio(Fila *fila) {
    if (fila != NULL && !fila_esta_vazia(fila)) {
        return fila->inicio->valor;
    }

    printf("Erro: Tentativa de espiar uma fila vazia.\n");
    return -1; 
}

void lista_exibir(Fila *fila) {
    if (fila == NULL || fila_esta_vazia(fila)) {
        printf("Fila vazia.\n");
        return;
    }

    no_t *atual = fila->inicio;

    while (atual != NULL) {
        printf("[%i] -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void fila_destruir(Fila *fila) {
    if (fila == NULL) return;

    while (!fila_esta_vazia(fila)) {
        fila_desenfileirar(fila);
    }

    free(fila);
}
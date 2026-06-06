#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no {
    struct no* anterior;
    int valor;
    struct no* proximo;
} no_t;

struct lista {
    no_t* primeiro;
    no_t* ultimo;
};

Lista lista_criar() {
    Lista l = (Lista)malloc(sizeof(struct lista));
    if (l == NULL) {
        return NULL;
    }
    l->primeiro = NULL;
    l->ultimo = NULL;
    return l;
}

int lista_inserir(Lista l, int elemento, int posicao) {
    if (l == NULL || posicao < 0) {
        return 0;
    }

    no_t* novo = (no_t*)malloc(sizeof(no_t));
    if (novo == NULL) {
        return 0;
    }
    novo->valor = elemento;
    novo->anterior = NULL;
    novo->proximo = NULL;

    /* CASO 1: Lista Vazia */
    if (l->primeiro == NULL) {
        if (posicao == 0) {
            l->primeiro = novo;
            l->ultimo = novo;
            return 1;
        }
        free(novo);
        return 0;
    }

    /* CASO 2: Inserção no Início */
    if (posicao == 0) {
        novo->proximo = l->primeiro;
        l->primeiro->anterior = novo;
        l->primeiro = novo;
        return 1;
    }

    /* Caminhar para encontrar a posição */
    no_t* atual = l->primeiro;
    int i = 0;
    while (atual != NULL && i < posicao) {
        atual = atual->proximo;
        i++;
    }

    /* CASO 3: Inserção no Fim */
    if (atual == NULL) {
        if (i == posicao) {
            novo->anterior = l->ultimo;
            l->ultimo->proximo = novo;
            l->ultimo = novo;
            return 1;
        }
        free(novo);
        return 0;
    }

    /* CASO 4: Inserção no Meio (Garantindo simetria perfeita) */
    novo->proximo = atual;
    novo->anterior = atual->anterior;
    
    if (atual->anterior != NULL) {
        atual->anterior->proximo = novo;
    }
    atual->anterior = novo;
    
    return 1;
}

int lista_remover(Lista l, int posicao) {
    if (l == NULL || l->primeiro == NULL || posicao < 0) {
        return 0;
    }

    no_t* atual = l->primeiro;
    int i = 0;
    while (atual != NULL && i < posicao) {
        atual = atual->proximo;
        i++;
    }

    if (atual == NULL) {
        return 0;
    }

    if (atual == l->primeiro) {
        l->primeiro = atual->proximo;
    } else {
        atual->anterior->proximo = atual->proximo;
    }

    if (atual == l->ultimo) {
        l->ultimo = atual->anterior;
    } else {
        atual->proximo->anterior = atual->anterior;
    }

    free(atual);
    return 1;
}

int lista_buscar(Lista l, int elemento) {
    if (l == NULL || l->primeiro == NULL) {
        return -1;
    }
    no_t* atual = l->primeiro;
    int indice = 0;
    while (atual != NULL) {
        if (atual->valor == elemento) {
            return indice;
        }
        atual = atual->proximo;
        indice++;
    }
    return -1;
}

int lista_exibir(Lista l) {
    if (l == NULL) {
        return 0;
    }
    no_t* atual = l->primeiro;
    printf("[");
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->proximo != NULL) {
            printf(", ");
        }
        atual = atual->proximo;
    }
    printf("]\n");
    return 1;
}

int lista_esta_vazia(Lista l) {
    if (l == NULL) {
        return -1;
    }
    return (l->primeiro == NULL) ? 1 : 0;
}

int lista_destruir(Lista l) {
    if (l == NULL) {
        return 0;
    }
    no_t* atual = l->primeiro;
    no_t* proximo_no = NULL;
    while (atual != NULL) {
        proximo_no = atual->proximo;
        free(atual);
        atual = proximo_no;
    }
    free(l);
    return 1;
}
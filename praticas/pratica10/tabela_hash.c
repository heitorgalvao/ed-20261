#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

struct tabelahash_t {
    no_t **tabela; 
    int tamanho;
};

 int funcao_hash(int chave, int tamanho) {
    int indice = chave % tamanho;
    if (indice < 0) {
        indice += tamanho;
    }
    return indice;
}

TabelaHash *hash_criar(int tamanho) {
    if (tamanho <= 0) {
        return NULL;
    }

    TabelaHash *nova_tabela = (TabelaHash *)malloc(sizeof(TabelaHash));
    if (nova_tabela == NULL) {
        return NULL;
    }

    nova_tabela->tabela = (no_t **)malloc(tamanho * sizeof(no_t *));
    if (nova_tabela->tabela == NULL) {
        free(nova_tabela);
        return NULL;
    }

    for (int i = 0; i < tamanho; i++) {
        nova_tabela->tabela[i] = NULL;
    }

    nova_tabela->tamanho = tamanho;
    return nova_tabela;
}

int hash_inserir(TabelaHash *hash, int valor) {
    if (hash == NULL) {
        return 0;
    }

    int indice = funcao_hash(valor, hash->tamanho);

    no_t *novo_no = (no_t *)malloc(sizeof(no_t));
    if (novo_no == NULL) {
        return 0; 
    }

    novo_no->valor = valor;
    
    novo_no->proximo = hash->tabela[indice];
    hash->tabela[indice] = novo_no;

    return 1;
}

void hash_exibir(TabelaHash *hash) {
    if (hash == NULL) {
        printf("Tabela Hash inexistente.\n");
        return;
    }

    for (int i = 0; i < hash->tamanho; i++) {
        printf("[%d]: ", i);
        no_t *atual = hash->tabela[i];
        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}

int hash_buscar(TabelaHash *hash, int valor) {
    if (hash == NULL) {
        return 0;
    }

    int indice = funcao_hash(valor, hash->tamanho);
    no_t *atual = hash->tabela[indice];

    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1;
        }
        atual = atual->proximo;
    }

    return 0;
}

int hash_remover(TabelaHash *hash, int valor) {
    if (hash == NULL) {
        return 0;
    }

    int indice = funcao_hash(valor, hash->tamanho);
    no_t *atual = hash->tabela[indice];
    no_t *anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                hash->tabela[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return 1; 
        }
        anterior = atual;
        atual = atual->proximo;
    }

    return 0; 
}

int hash_esta_vazia(TabelaHash *hash) {
    if (hash == NULL) {
        return 1;
    }

    for (int i = 0; i < hash->tamanho; i++) {
        if (hash->tabela[i] != NULL) {
            return 0;
        }
    }
    return 1;
}

void hash_destruir(TabelaHash *hash) {
    if (hash == NULL) {
        return;
    }

    for (int i = 0; i < hash->tamanho; i++) {
        no_t *atual = hash->tabela[i];
        while (atual != NULL) {
            no_t *auxiliar = atual;
            atual = atual->proximo;
            free(auxiliar);
        }
    }

    free(hash->tabela);
    free(hash);
}
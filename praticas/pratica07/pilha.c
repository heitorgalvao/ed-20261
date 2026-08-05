#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

struct pilha_t {
    no_t* topo;
};

Pilha pilha_criar(){
    Pilha p = (Pilha)malloc(sizeof(struct pilha_t));
    if(p != NULL){
        p->topo = NULL;
    }
    return p;
}

int pilha_esta_vazia(Pilha p) {
    if (p == NULL || p->topo == NULL) {
        return 1; 
    }
    return 0;
}

int pilha_empilhar(Pilha p, int valor){
    if (p == NULL) return 0;
    no_t *novo_no = (no_t *)malloc(sizeof(no_t));
    if (novo_no == NULL) return 0;
    novo_no->valor = valor;
    novo_no->proximo = p->topo;
    p->topo = novo_no;

    return 1;
}

int pilha_desempilhar(Pilha p, int *valor_saida){
    if (pilha_esta_vazia(p)) return 0;

    no_t *no_removido = p->topo;
    if(valor_saida != NULL) {
    *valor_saida = no_removido->valor;
}

p->topo = no_removido->proximo;
free(no_removido);

return 1;
}

int pilha_topo(Pilha p, int* valor_saida){
    if (pilha_esta_vazia(p)) return 0;
    
    if (valor_saida != NULL) {
        *valor_saida = p->topo->valor;
    }
    return 1;
}

void pilha_exibir(Pilha p) {
    if (pilha_esta_vazia(p)) {
        printf("Pilha vazia\n");
        return;
    }

no_t *atual = p->topo;
    printf("Topo -> ");
    while (atual != NULL) {
        printf("[%d] ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void pilha_destruir(Pilha p) {
    if (p == NULL) return;

    no_t* atual = p->topo;
    while (atual != NULL) {
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(p);
}

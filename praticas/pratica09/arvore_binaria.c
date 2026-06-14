#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no_t{
    int valor;
    struct no_t *esquerda;
    struct no_t *direita;
}no_t;

struct arvore_t{
    no_t *raiz;
};

no_t *criar_no(int valor){
    no_t *novo = (no_t *)malloc(sizeof(no_t));
    if (novo != NULL) {
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
    }
    return novo;
}

no_t *inserir_simples(no_t *raiz_atual, int valor){
    if (raiz_atual == NULL){
        return criar_no(valor);
    }
    if (raiz_atual->esquerda == NULL){
        raiz_atual->esquerda = criar_no(valor);
    }
    else if (raiz_atual->direita == NULL){
        raiz_atual->direita = criar_no(valor);
    }
    else{
        raiz_atual->esquerda = inserir_simples(raiz_atual->esquerda, valor);
    }
    return raiz_atual;
}

void destruir_recursivo(no_t *raiz_atual) {
    if (raiz_atual == NULL) return;
    destruir_recursivo(raiz_atual->esquerda);
    destruir_recursivo(raiz_atual->direita);
    free(raiz_atual);
}

void pre_ordem_recursivo(no_t *raiz_atual) {
    if (raiz_atual == NULL) return;
    printf("[%i] ", raiz_atual->valor);
    pre_ordem_recursivo(raiz_atual->esquerda);
    pre_ordem_recursivo(raiz_atual->direita);
}

void em_ordem_recursivo(no_t *raiz_atual) {
    if (raiz_atual == NULL) return;
    em_ordem_recursivo(raiz_atual->esquerda);
    printf("[%i] ", raiz_atual->valor);
    em_ordem_recursivo(raiz_atual->direita);
}

void pos_ordem_recursivo(no_t *raiz_atual) {
    if (raiz_atual == NULL) return;
    pos_ordem_recursivo(raiz_atual->esquerda);
    pos_ordem_recursivo(raiz_atual->direita);
    printf("[%i] ", raiz_atual->valor);
}

Arvore *arvore_criar(){
    Arvore *arvore = (Arvore *)malloc(sizeof(arvore));
    if (arvore != NULL) {
        arvore->raiz = NULL;
    }
    return arvore;
}

int arvore_esta_vazia(Arvore *arvore){
    return (arvore == NULL || arvore->raiz == NULL);
}

void arvore_inserir(Arvore *arvore, int valor){
    if (arvore == NULL) return;
    arvore->raiz = inserir_simples(arvore->raiz, valor);
}

void arvore_exibir_pre_ordem(Arvore *arvore) {
    if (arvore_esta_vazia(arvore)) {
        printf("Arvore vazia.\n");
        return;
    }
    pre_ordem_recursivo(arvore->raiz);
    printf("\n");
}

void arvore_exibir_em_ordem(Arvore *arvore) {
    if (arvore_esta_vazia(arvore)) {
        printf("Arvore vazia.\n");
        return;
    }
    em_ordem_recursivo(arvore->raiz);
    printf("\n");
}

void arvore_exibir_pos_ordem(Arvore *arvore) {
    if (arvore_esta_vazia(arvore)) {
        printf("Arvore vazia.\n");
        return;
    }
    pos_ordem_recursivo(arvore->raiz);
    printf("\n");
}

void arvore_destruir(Arvore *arvore) {
    if (arvore == NULL) return;
    destruir_recursivo(arvore->raiz);
    free(arvore);
}



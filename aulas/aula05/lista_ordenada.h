#ifndef LISTA_ORDENADA_H
#define LISTA_ORDENADA_H

typedef struct{
    int dado;
    No *proximo;
}No;

typedef struct{
    No *primeiro;
    No *ultimo;
    int quantidade;
}ListaEncadeada;

ListaEncadeada *criar();
void destruir(ListaEncadeada *lista);
void adicionar_final(ListaEncadeada *lista, int valor);
No *buscar(ListaEncadeada *lista, int valor);
void remover(ListaEncadeada *lista, int valor);
int lista_vazia(ListaEncadeada *lista);
#endif

#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H

typedef struct lista* Lista;
Lista lista_criar();
int lista_inserir(Lista l, int elemento, int posicao);
int lista_remover(Lista l, int posicao);
int lista_buscar(Lista l, int elemento);
int lista_exibir(Lista l);
int lista_esta_vazia(Lista l);
int lista_destruir(Lista l);

#endif
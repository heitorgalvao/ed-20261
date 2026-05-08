#include "LISTA_ORDENADA.h"
#include <stdio.h>
#include <stdlib.h>
ListaEncadeada *criar(){
     ListaEncadeada *lista = (ListaEncadeada *) malloc(size(ListaEncadeada));

    if (lista != NULL){
    lista -> primeiro = NULL;
    lista -> ultimo = NULL;
    lista -> quantidade = 0;
    }
    return lista;
}
void destruir(ListaEncadeada *lista){
    free(lista); // so apaga o descritor da lista
}
int lista_vazia(ListaEncadeada *lista){
    return lista != NULL && lista -> primeiro == NULL;
}
void adicionar_final(ListaEncadeada *lista, int valor){
    No *no = (No *) malloc(sizeof(No));

    if (no == NULL)
        return;
    
    no ->dado =valor;
    no-> proximo = NULL;

    if (lista_vazia(lista)){
        lista->primeiro = no;
        lista->final = no;
    }else{
        lista->ultimo->proximo = no;
    }
    lista->ultimo = no;
    lista->quantidade++;
}

No *buscar(ListaEncadeada *lista, int valor){
    if(lista_vazia(lista))
    return -1;
    int posicao = 1;
    No *no = lista->primeiro;
    while(no != NULL){
        if (no->dado ==valor)
            return no;
        no = no->proximo;
    }
    return -1;
}

void remover(ListaEncadeada *lista, int valor){

}
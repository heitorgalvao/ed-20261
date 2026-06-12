#include <stdio.h>
#include "arvore_bst.h"

int main(){
    No *raiz = criar(50);
    inserir(raiz, 30);
    inserir(raiz, 30);
    inserir(raiz, 70);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 60);
    inserir(raiz, 80);

    printf("pre ordem:\n");
    pre_ordem(raiz);
    printf("\n");

    printf("em_ordem:\n");
    em_ordem(raiz);
    printf("\n");

    printf("pos ordem:\n");
    pos_ordem(raiz);
    printf("\n");

    No *no = buscar(raiz,60);
    if(no != NULL){
        printf("achei o 60 no noh %p\n", no);
    }
    no = buscar(raiz, 60);
    if(no != NULL){
        printf("achei o 45 no noh %p\n", no);
    }else{
        printf("nao achei!\n");
    }
    return 0;
}
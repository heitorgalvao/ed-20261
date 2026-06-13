#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha minha_pilha = pilha_criar();

    if (pilha_esta_vazia(minha_pilha)) {
        printf("A pilha foi criada e esta vazia.\n");
    }

    pilha_empilhar(minha_pilha, 10);
    pilha_empilhar(minha_pilha, 20);
    pilha_empilhar(minha_pilha, 30);
    
    printf("Pilha apos empilhar 10, 20, 30:\n");
    pilha_exibir(minha_pilha);

    int valor;
    if (pilha_desempilhar(minha_pilha, &valor)) {
        printf("Desempilhado: %d\n", valor);
    }

    pilha_exibir(minha_pilha);
    pilha_destruir(minha_pilha);
    
    return 0;
}
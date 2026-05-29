#include <stdio.h>
#include "lista_encadeada.h"

int main() {
    ListaEncadeada *lista = criar();

    adicionar_final(lista, 50);
    adicionar_final(lista, 25);
    adicionar_final(lista, 10);
    adicionar_final(lista, 60);
    adicionar_final(lista, 5);
    adicionar_final(lista, 41);
    adicionar_final(lista, 9);

    printf("A lista em %i nos\n", lista->quantidade);
    No *no = lista->primeiro;
    while (no != NULL) {
        printf("%i ", no->dado);
        no = no->proximo;
    }
remover(lista, 50);
// remover(lista, 10);
// remover(lista, 9);

printf()
    return 0;
}
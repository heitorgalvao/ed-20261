#include <stdio.h>
#include "lista_linear.h"

int main() {
    printf("=== INICIANDO TESTES DO TAD LISTA LINEAR ===\n\n");
    Lista minha_lista = lista_criar();
    if (minha_lista == NULL) {
        printf("Erro crítico: Não foi possível criar a lista.\n");
        return 1;
    }
    printf("Lista criada com sucesso.\n");
    if (lista_esta_vazia(minha_lista) == 1) {
        printf("Confirmado: A lista está inicialmente vazia.\n");
    }
    printf("\n--- Testando Inserções ---\n");
    if (lista_inserir(minha_lista, 10, 0)) {
        printf("Inserido 10 na posicao 0.\n");
    }
    if (lista_inserir(minha_lista, 30, 1)) {
        printf("Inserido 30 na posicao 1.\n");
    }
    if (lista_inserir(minha_lista, 20, 1)) {
        printf("Inserido 20 na posicao 1.\n");
    }
    if (lista_inserir(minha_lista, 5, 0)) {
        printf("Inserido 5 na posicao 0.\n");
    }
    if (!lista_inserir(minha_lista, 100, 10)) {
        printf("Sucesso no teste de erro: Insercao na posicao 10 foi rejeitada corretamente.\n");
    }
    printf("Estado atual da lista: ");
    lista_exibir(minha_lista);
    printf("\n--- Testando Buscas ---\n");
    int elemento_procurado = 20;
    int pos = lista_buscar(minha_lista, elemento_procurado);
    if (pos != -1) {
        printf("Elemento %d encontrado na posicao: %d\n", elemento_procurado, pos);
    } else {
        printf("Erro: Elemento %d deveria existir na lista.\n", elemento_procurado);
    }

    elemento_procurado = 99;
    pos = lista_buscar(minha_lista, elemento_procurado);
    if (pos == -1) {
        printf("Sucesso no teste: Elemento %d nao encontrado (retornou -1).\n", elemento_procurado);
    }
    printf("\n--- Testando Remoções ---\n");
    if (lista_remover(minha_lista, 0)) {
        printf("Removido o elemento da posicao 0 (inicio).\n");
    }
    if (lista_remover(minha_lista, 1)) {
        printf("Removido o elemento da posicao 1 (meio).\n");
    }
    printf("Estado atual da lista: ");
    lista_exibir(minha_lista);
    printf("\n--- Finalizando e Liberando Memoria ---\n");
    if (lista_destruir(minha_lista)) {
        printf("Memoria da lista liberada com sucesso.\n");
    }
    printf("\n=== TODOS OS TESTES CONCLUÍDOS COM SUCESSO ===\n");
    return 0;
}
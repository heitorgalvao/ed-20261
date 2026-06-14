#include <stdio.h>
#include "tabela_hash.h"

int main() {
    int tamanho_tabela = 7;
    TabelaHash *minha_tabela = hash_criar(tamanho_tabela);

    if (minha_tabela == NULL) {
        printf("Erro ao criar a tabela hash.\n");
        return 1;
    }

    printf("--- Testando Estado Inicial ---\n");
    if (hash_esta_vazia(minha_tabela)) {
        printf("A tabela hash esta vazia.\n\n");
    }

    printf("--- Inserindo Elementos ---\n");

    hash_inserir(minha_tabela, 15);
    hash_inserir(minha_tabela, 8);
    hash_inserir(minha_tabela, 22);
    hash_inserir(minha_tabela, 10);
    hash_inserir(minha_tabela, 5);
    hash_inserir(minha_tabela, 47); 

    hash_exibir(minha_tabela);
    printf("\n");

    printf("--- Testando Estado Apos Insercoes ---\n");
    if (!hash_esta_vazia(minha_tabela)) {
        printf("A tabela hash nao esta mais vazia.\n\n");
    }

    printf("--- Testando a Busca ---\n");
    int valor_busca = 8;
    if (hash_buscar(minha_tabela, valor_busca)) {
        printf("O valor %d foi ENCONTRADO na tabela.\n", valor_busca);
    } else {
        printf("O valor %d NAO foi encontrado na tabela.\n", valor_busca);
    }

    valor_busca = 99;
    if (hash_buscar(minha_tabela, valor_busca)) {
        printf("O valor %d foi ENCONTRADO na tabela.\n", valor_busca);
    } else {
        printf("O valor %d NAO foi encontrado na tabela.\n", valor_busca);
    }
    printf("\n");

    printf("--- Testando a Remocao ---\n");
    printf("Removendo o valor 8...\n");
    hash_remover(minha_tabela, 8);
    hash_exibir(minha_tabela);
    printf("\n");

    printf("Removendo o valor 22 (cabeca da lista do indice 1)...\n");
    hash_remover(minha_tabela, 22);
    hash_exibir(minha_tabela);
    printf("\n");

    printf("Tentando remover o valor 99 (inexistente)...\n");
    if (!hash_remover(minha_tabela, 99)) {
        printf("Nao foi possivel remover: valor 99 nao encontrado.\n\n");
    }

    printf("--- Destruindo a Tabela ---\n");
    hash_destruir(minha_tabela);
    printf("Memoria liberada com sucesso.\n");

    return 0;
}
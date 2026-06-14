#include <stdio.h>
#include "fila.h"

int main() {
    printf("=== INICIANDO TESTES DO TDA FILA ===\n\n");

    Fila *f = fila_criar();

    printf("A fila esta vazia? %s\n", fila_esta_vazia(f) ? "Sim" : "Nao");
    lista_exibir(f);
    printf("------------------------------------\n");

    printf("Enfileirando os elementos: 10, 20 e 30...\n");
    fila_enfileirar(f, 10);
    fila_enfileirar(f, 20);
    fila_enfileirar(f, 30);
    
    printf("Estado atual da fila:\n");
    lista_exibir(f);
    printf("A fila esta vazia? %s\n", fila_esta_vazia(f) ? "Sim" : "Nao");
    printf("------------------------------------\n");

    printf("Quem esta no inicio da fila atualmente? %i\n", fila_inicio(f));
    printf("------------------------------------\n");

    printf("Chamando fila_desenfileirar()...\n");
    fila_desenfileirar(f);
    
    printf("Estado atual da fila:\n");
    lista_exibir(f);
    printf("Novo elemento no inicio: %i\n", fila_inicio(f));
    printf("------------------------------------\n");

    printf("Enfileirando o elemento 40...\n");
    fila_enfileirar(f, 40);
    lista_exibir(f);
    printf("------------------------------------\n");

    printf("Finalizando o programa e destruindo a fila com seguranca...\n");
    fila_destruir(f);

    printf("=== TESTES CONCLUIDOS COM SUCESSO ===\n");
    return 0;
}
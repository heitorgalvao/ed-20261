#include <stdio.h>
#include "arvore_binaria.h"

int main(){
    printf("=== TESTES ARVORE BINARIA SIMPLES ===\n\n");

    Arvore *a = arvore_criar();

    arvore_inserir(a, 10);
    arvore_inserir(a, 20);
    arvore_inserir(a, 30);
    arvore_inserir(a, 40);
    arvore_inserir(a, 50);

    printf("Exibicao PRE-ORDEM:\n");
    arvore_exibir_pre_ordem(a);
    printf("\n");

    printf("Exibicao EM-ORDEM:\n");
    arvore_exibir_em_ordem(a);
    printf("\n");

    printf("Exibicao POS-ORDEM:\n");
    arvore_exibir_pos_ordem(a);
    printf("\n");

    arvore_destruir(a);

    printf("=== FIM DOS TESTES ===\n");
    return 0;
}

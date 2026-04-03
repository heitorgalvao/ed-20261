#include <stdio.h>
#include <string.h>

struct Cedulas{
    int notas;
    int quantidade;
};

int main(){
    int saque;
    struct Cedulas caixa[7] ={
    {200, 0}, {100, 0}, {50, 0}, {20, 0}, {10, 0}, {5, 0}, {2,0} 
    };
    printf("Digite o valor do saque (Máx R$ 1000): ");
    scanf("%d", &saque);

    if (saque <= 0 || saque > 1000) {
        printf("Valor inválido!\n");
        return 0;
    }
    int restante = saque; 
    for (int i = 0; i < 7; i++) {
        caixa[i].quantidade = restante / caixa[i].notas;
        restante = restante % caixa[i].notas;
    }
    printf("\nNotas entregues para R$ %d:\n", saque);
    for (int i = 0; i < 7; i++) {
        if (caixa[i].quantidade > 0) {
            printf("%d nota(s) de R$ %d\n", caixa[i].quantidade, caixa[i].notas);
        }
    }
    if (restante > 0) {
        printf("Atenção: Sobrou R$ %d que não pode ser sacado com estas notas.\n", restante);
    }
    return 0;
}

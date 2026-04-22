#include <stdio.h>


int main() {
    float num, resultado = 1;
    int potencia;

    // Valores de teste1
    num = 2; potencia = 3; resultado = 1;
    for (int i = 0; i < potencia; i++) {
        resultado *= num;
    }
    printf("1 Teste: %.2f\n", resultado);

    // Valores de teste2
    num = 7; potencia = 6; resultado = 1;
    for (int i = 0; i < potencia; i++) {
        resultado *= num;
    }
    printf("2 Teste: %.2f\n", resultado);
    
    return 0;
}
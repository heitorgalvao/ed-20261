#include <stdio.h>

float calcular_media(int n_numeros) {
    float soma = 0;
    float valor_digitado;

    for (int i = 0; i < n_numeros; i++) {
        printf("Digite o %d o numero: ", i + 1);
        scanf("%f", &valor_digitado);
        soma = soma + valor_digitado;
    }

    return soma / n_numeros;
}

int main() {
    int n;

    printf("Digite a quantidade de numeros (1 a 100): ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Quantidade invalida!\n");
    } else {
        float res = calcular_media(n);
        printf("A media final e: %.2f\n", res);
    }

    return 0;
}
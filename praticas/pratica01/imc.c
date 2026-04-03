#include <stdio.h>

float calcular_imc(float altura, float peso) {
    if (altura <= 0.0f || peso <= 0.0f) {
        return 0.0f;
    }
    return peso / (altura * altura);
}

int main() {
    float imc = 0.0f;
    
    imc = calcular_imc(0.0f, 50.0f);
    printf("altura = 0 , peso = 50 , imc = %.1f => %i\n", imc, imc == 0);

    imc = calcular_imc(1.75f, 0.0f);
    printf("altura = 1.75 , peso = 0 , imc = %.1f => %i\n", imc, imc == 0);

    imc = calcular_imc(1.75f, 50.0f);
    printf("altura = 1.75 , peso = 50.0 , imc = %.1f => %i\n", imc, imc < 18.5f);

    imc = calcular_imc(1.75f, 65.0f);
    printf("altura = 1.75 , peso = 65.0 , imc = %.1f => %i\n", imc, imc > 18.5f && imc < 25);

    imc = calcular_imc(1.75f, 85.0f);

    printf("altura = 1.75 , peso = 85.0 , imc = %.1f => %i\n", imc, imc >= 25 && imc < 30);

    imc = calcular_imc(1.75f, 95.0f);
    printf("altura = 1.75 , peso = 95.0 , imc = %.1f => %i\n", imc, imc >= 30);

    return 0;
}
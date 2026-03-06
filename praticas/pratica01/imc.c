#include <stdio.h>

    float peso;
    float altura;
    float imc;
    float imc = peso/(altura*altura);

int main (){
    printf("insira seu peso: \n");
    scanf("%f", &peso);

    printf("insira sua altura:\n");
    scanf("%f", &altura);

    printf("seu imc:%i",imc);



    

    return 0;
}
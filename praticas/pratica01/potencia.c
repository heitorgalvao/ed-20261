#include <stdio.h>
int potencia(int base , int expoente){
    if(expoente == 0 ){
        return 1;
    };
    if(base == 0){
    return 0;
    };
    int resultado = 1;
    for(int i = 0; i < expoente; i++){
        resultado = resultado*base;
    }
    return resultado;
}

int main(){
    int base , expoente;

    printf("Digite a base (inteiro): ");
    scanf("%d", &base);
    
    printf("Digite o expoente (inteiro positivo): ");
    scanf("%d", &expoente);

    int res = potencia(base, expoente);
        printf("Resultado: %d\n", res);

    return 0;
}
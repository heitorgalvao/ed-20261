#include <stdio.h>
#include <time.h>

int buscar_vetor(int vetor[100], int busca){ //complexidade linear 0(N)
    int achou = -1;
    for (int i = 0; i < 100; i++) {
        if (vetor[i] == busca) {
        achou = i;
        break;
        }
    }
    return achou;
}
int main(){
    clock_t tempo_inicial, tempo_final;
    double tempo_para_achar_vetor;

    int procurar_numero;
    int resultado;
    int vetor[100];
    for(int i = 0; i<100; i++){
        vetor[i] = i + 1;
    }
    printf("qual valor quer encontrar:");
    scanf("%d", &procurar_numero);

    tempo_inicial = clock();
    resultado = buscar_vetor(vetor, procurar_numero);
    if (resultado == -1){
        printf("vetor não encontrado.");
    }
    else{
        printf("o valor esta na posicao:%d\n", resultado);
    }
    tempo_final = clock();
    tempo_para_achar_vetor = (double)(tempo_final - tempo_inicial) /  CLOCKS_PER_SEC;

    printf("tempo para encontrar o vetor foi de: %f", tempo_para_achar_vetor);
    return 0;
}
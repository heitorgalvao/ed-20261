#include <stdio.h>
#include <time.h>

void percorrer_matriz_2for(int matriz[10][10]){ // complexidade 0(N^2)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++){ 
            
            int valor = matriz[i][j];
        }
    }
}
void percorrer_matriz_1for(int matriz[10][10]){ //complexidade complexidade - 0(N^2) 
    int *ptr = &matriz[0][0];
    for (int i = 0; i < 100; i++){
        int valor = ptr[i];
    }
}
int main(){
    int matriz[10][10];
    clock_t inicio, fim;

    for(int i=0; i<10; i++) for(int j=0; j<10; j++) matriz[i][j] = i + j;

    
    inicio = clock();
    percorrer_matriz_2for(matriz);
    fim = clock();
    printf("Tempo para percorrer matriz com 2 lacos: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    inicio = clock();
    percorrer_matriz_1for(matriz);
    fim = clock();
    printf("Tempo para percorrer matriz com 1 Laco: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}
#include <stdio.h>
#include <time.h>

long long fatorial_rep(int n){ // complexidade  linear - 0(N)
    long long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
};
long long fatorial_rec(int n) { // complexidade linear - 0(N)
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fatorial_rec(n - 1);
};
int main(){
    int n;

    clock_t tempo_inicial, tempo_final;
    double tempo_iterativo, tempo_recursivo;


    printf("insira um numero para calcular o fatorial: ");
    scanf("%d", &n);

    tempo_inicial = clock();
    int res = fatorial_rep(n);
        printf("resultado do fatorial iterativo = %d\n", res);
    tempo_final = clock();
    tempo_iterativo = (double)(tempo_final - tempo_inicial) / CLOCKS_PER_SEC;

    tempo_inicial = clock();
    int res2 = fatorial_rec(n);
        printf("resultado do fatorial recursivo: %d\n", res2);
    tempo_final = clock();
    tempo_recursivo = (double)(tempo_final - tempo_inicial) / CLOCKS_PER_SEC;

    printf("tempo para executar fatorial iterativo: %f segundos\n", tempo_iterativo);
    printf("tempo para executar fatorial recursivo: %f segundos", tempo_recursivo);

    return 0;
}
#include "selecao.h"


static int particionar(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio;
    for (int j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
        }
    }
    int temp = v[i];
    v[i] = v[fim];
    v[fim] = temp;
    return i;
}

int linear_search(int v[], int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (v[i] == valor) {
            return i;
        }
    }
    return -1;
}

int quick_select(int v[], int inicio, int fim, int k) {
    if (inicio <= fim) {
        int indice_pivo = particionar(v, inicio, fim);

        if (indice_pivo == k) return v[indice_pivo];
        
        if (k < indice_pivo) 
            return quick_select(v, inicio, indice_pivo - 1, k);
            
        return quick_select(v, indice_pivo + 1, fim, k);
    }
    return -1;
}
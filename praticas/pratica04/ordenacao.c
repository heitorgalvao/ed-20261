#include <stdio.h>
#include "ordenacao.h"

void imprimir_vetor(int v[], int n){
     printf("[");
      for (int i = 0; i < n; i++) {
        printf("%i, ", v[i]);
    }
    printf("%i] \n", v[n-1]);
}
void troca(int *a, int *b){
     int auxiliar = *a;
     *a = *b;
     *b = auxiliar;
}
void bubble_sort(int v[], int n){
   for(int i = 0; i < n-1; i++) {
       for(int j = 0; j < n-i-1; j++) {
           if(v[j] > v[j+1])
               troca(&v[j], &v[j+1]);
       }
   }
}
int particionar_v(int v[], int start, int end){
     int pivo = v[end];
     int i = start - 1;
     for (int j = start; j < end; j++) {
       if (v[j] <= pivo) {
           i++;
           troca(&v[i], &v[j]);
       }
   }
   troca(&v[i + 1], &v[end]);
   return i + 1;
}
void quick_sort(int v[], int start, int end){
     if (start < end) {
       int pivo = particionar_v(v, start, end);
       quick_sort(v, start, pivo - 1);
       quick_sort(v, pivo + 1, end);
     }
}
void selection_sort(int v[], int n){
     for(int i = 0; i < n - 1; i++) {
       int min = i;
       for(int j = i + 1; j < n; j++) {
           if(v[j] < v[min])
               min = j;
       }
       if(min != i)
           troca(&v[i], &v[min]);
   }
}
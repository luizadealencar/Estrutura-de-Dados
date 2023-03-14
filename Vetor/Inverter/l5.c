#include <stdio.h>
#include <stdlib.h>
#include "l5.h"

void imprime(int **matriz) {
  for (int i=0;i<2;i++){
    for (int j=0;j<2;j++){
      printf("%d\t", matriz[i][j]);
    }
    printf("\n");
  }
}

void inverter_linha(int **matriz){
  int **aux;
  aux=(int**)malloc(2*sizeof(int));
  for (int i=0;i<2;i++){
    aux[i]=(int*)malloc(2*sizeof(int));
  }
  aux[0][0]=matriz[1][0];
  matriz[1][0]=matriz[0][0];
  matriz[0][0]=aux[0][0];
  aux[0][1]=matriz[1][1];
  matriz[1][1]=matriz[0][1];
  matriz[0][1]=aux[0][1];
  imprime(matriz);
}

void imprime_matriz(int l, int c, int **matriz) {
  for (int i=0;i<l;i++){
    for (int j=0;j<c;j++){
      printf("%d\t", matriz[i][j]);
    }
    printf("\n");
  }
}

void imprime_vetor(int tam, int *vetor) {
  for (int i=0;i<tam;i++){
    printf("%d\n", vetor[i]);
  }
}

void intperfeito(int n){
  int soma=0;
  for (int i=1;i<n;i++){
    if (n%i==0){
      soma+=i;
    }
  }
  if (n==soma){
    printf("O número é perfeito.\n");
  }else{
    printf("O número não é perfeito.\n");
  }
}

float notaaluno(float nota){
  scanf("%f", &nota);
  return nota;
}
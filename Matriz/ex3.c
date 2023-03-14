#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"

int main(){
  int *vetor, tam;
  printf("Qual o tamanho do vetor? ");
  scanf("%d", &tam);
  vetor=malloc(sizeof(int)*tam);
  for(int i=0;i<tam;i++){
    scanf("%d", &vetor[i]);
  }
  trocar(vetor, tam);
  printf("\n");
  for(int i=0;i<tam;i++){
    printf("%d\n", vetor[i]);
  }
  return 0;
}

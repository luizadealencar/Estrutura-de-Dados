#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"

void trocar(int *vetor, int tam){
  for(int i=0;i<tam;i++){
    for(int j=0;j<tam-1;j++){
      if (vetor[j]==0 && vetor[j+1]!=0){
        vetor[j]=vetor[j+1];
        vetor[j+1]=0;
      }
    }
  }
}
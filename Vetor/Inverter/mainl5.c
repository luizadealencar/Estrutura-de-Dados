#include <stdio.h>
#include "l5.h"

int main(){
  float nota;
  printf("Exercicio 1:\nDigite a nota do aluno:\n");
  printf("A nota do aluno é: %.2f\n", notaaluno(nota));

  int n;
  printf("\nExercicio 2:\nDigite algum número: ");
  scanf("%d", &n);
  printf("Esse número é perfeito?\n");
  intperfeito(n);

  int *vetor, tam;
  printf("\nExercicio 3:\nDigite a quantidade de elementos no vetor: ");
  scanf("%d", &tam);
  vetor=(int*)malloc(tam*sizeof(int));
  for (int i=0;i<tam;i++){
    scanf("%d", &vetor[i]);
  }
  printf("\n");
  imprime_vetor(tam, vetor);

  int **mat, l, c;
  printf("\nExercicio 4:\nDigite a quantidade de linha: ");
  scanf("%d", &l);
  printf("Digite a quantidade de coluna: ");
  scanf("%d", &c);
  mat=(int**)malloc(l*sizeof(int));
  for (int i=0;i<l;i++){
    mat[i]=(int*)malloc(c*sizeof(int));
  }
  for (int i=0;i<l;i++){
    for (int j=0;j<c;j++){
      scanf("%d", &mat[i][j]);
    }
  }
  imprime_matriz(l, c, mat);

  int **matriz;
  printf("\nExercicio 5:\nDigite 4 elementos inteiros:\n");
  matriz=(int**)malloc(2*sizeof(int));
  for (int i=0;i<2;i++){
    matriz[i]=(int*)malloc(2*sizeof(int));
  }
  for (int i=0;i<2;i++){
    for (int j=0;j<2;j++){
      scanf("%d", &matriz[i][j]);
    }
  }
  inverter_linha(matriz);
}
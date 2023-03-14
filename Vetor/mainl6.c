#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "l6.h"

int main(){
  String *s=cria_vetor();
  char *c;

  printf("Exercicio de 1 ao 6:\n\nEntre com o tamanho do vetor: ");
  scanf("%d", &s->tam);

  c=(char*)malloc(s->tam*sizeof(char));

  fill(s, c, s->tam);
  printf("\n");
  imprime_vetor(s);
  free_vetor(s);
  printf("\n");

  char *str1, *str2, *str3;
  int tam1, tam2;

  printf("\nExercicio 7:\n\nEntre com o tamanho do vetor 1: ");
  scanf("%d", &tam1);
  printf("\nEntre com o tamanho do vetor 2: ");
  scanf("%d", &tam2);

  str1=(char*)malloc(tam1*sizeof(char));
  str2=(char*)malloc(tam2*sizeof(char));
  str3=(char*)malloc(tam1+tam2*sizeof(char));

  printf("\nQuais elementos do vetor 1?\n");
  for (int i=0;i<tam1;++i){
    scanf("%s", &str1[i]);
  }
  printf("\n");
  printf("Quais elementos do vetor 2?\n");
  for (int i=0;i<tam2;++i){
    scanf("%s", &str2[i]);
  }
  
  concatenarStrings(str1, tam1, str2, tam2, str3);

  printf("\n");
  for(int i=0;i<tam1+tam2;i++){
    printf("%c", str3[i]);
  }
  printf("\n");
  return 0;
}
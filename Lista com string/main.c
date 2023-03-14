#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_str.h"

int main(){
  String *s1=cria_vetor();
  char *c1;

  printf("\nEntre com o tamanho do vetor 1: ");
  scanf("%d", &s1->tam);

  c1=(char*)malloc(s1->tam*sizeof(char));

	printf("\nQuais elementos do vetor 1?\n");

  fill(s1, c1, s1->tam);
  printf("\n");
  imprime_vetor(s1);

	String *s2=cria_vetor();
  char *c2;

  printf("\nEntre com o tamanho do vetor 2: ");
  scanf("%d", &s2->tam);

  c2=(char*)malloc(s2->tam*sizeof(char));

  printf("\nQuais elementos do vetor 2?\n");
  fill(s2, c2, s2->tam);
  
	String *s3=cria_vetor();
	char *c3;

	s3->tam=s2->tam+s1->tam;

	c3=(char*)malloc(s2->tam+s1->tam*sizeof(char));

  concatenarStrings(c1, s1->tam, c2, s2->tam, c3, s3);
  printf("\n");
	imprime_vetor(s3);

	free_vetor(s1);
	free_vetor(s2);
	free_vetor(s3);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "l6.h"

String* cria_vetor(){
  String *nova=(String*)malloc(sizeof(String));
  return nova;
}

void fill(String *s, char *c, int tam){
  char *aux=(char*)malloc(tam+1*sizeof(char));
  for (int i=0;i<tam;++i){
    scanf("%s", &c[i]);
  }
  strcpy(aux, c);
  s->vet=aux;
}

void imprime_vetor(String *s){
  for (int i=0;i<s->tam;++i){
    printf("%c ", s->vet[i]);
  }
  printf("\n");
}

void free_vetor(String *s){
  free(s);
}

void concatenarStrings(char *str1, int tam1, char *str2, int tam2, char *str3){
  for (int i=0;i<tam1;i++){
    str3[i]=str1[i];
  }
  for (int j=0;j<tam2;j++){
    str3[tam1+j]=str2[j];
  }
}
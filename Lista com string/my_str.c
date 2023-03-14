#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_str.h"

//Exercecio 3 - A funcao cria (aloca dinamicamente) uma nova string vazia
String* cria_vetor(){
  String *nova=(String*)malloc(sizeof(String)); //aloca 
  return nova;
}

//Exercecio 4 - A funcao preenche uma nova string a partir de um vetor de char e o seu tamanho
void fill(String *s, char *c, int tam){
  char *aux=(char*)malloc(tam+1*sizeof(char)); //abre uma variavel de char
  for (int i=0;i<tam;++i){
    printf("%dº elemento: ", i+1);
    scanf("%s", &c[i]); //pega os elementos
  }
  strcpy(aux, c); //o aux recebe os elementos
  s->vet=aux; //os elementos sao colocados na string
}

//Exercecio 5 - A funcao exibe a sua nova estrutura de string na tela
void imprime_vetor(String *s){
  printf("Impressao: \n");
  for (int i=0;i<s->tam;++i){
    printf("%c", s->vet[i]);
  }
  printf("\n");
}

//Exercecio 6 - A funcao destroi um ponteiro para seu tipo string
void free_vetor(String *s){
  free(s);
}

//Exercecio 7 - A funcao concatena duas strings
void concatenarStrings(char *str1, int tam1, char *str2, int tam2, char *str3, String *s){
  for (int i=0;i<tam1;i++){
    str3[i]=str1[i];
  }
  for (int j=0;j<tam2;j++){
    str3[tam1+j]=str2[j];
  }
  char *aux=(char*)malloc(s->tam+1*sizeof(char)); //abre uma variavel de char
  strcpy(aux, str3); //o aux recebe os elementos
  s->vet=aux; //os elementos sao colocados na string
}
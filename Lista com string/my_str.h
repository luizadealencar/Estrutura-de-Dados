#include <stdio.h>

//Exercicio 1 - Struct com vetor de char de tamanho variavel e o seu tamanho atual
struct palavra{
  char *vet;
  int tam;
};

//Exercicio 2 - Typedef
typedef struct palavra String;

String* cria_vetor(); //A funcao cria (aloca dinamicamente) uma nova string vazia
void fill(String *s, char *c, int tam); //A funcao preenche uma nova string a partir de um vetor de char e o seu tamanho
void imprime_vetor(String *s); //A funcao exibe a sua nova estrutura de string na tela
void concatenarStrings(char *str1, int tam1, char *str2, int tam2, char *str3, String *s); //A funcao concatena duas strings
void free_vetor(String *s); //A funcao destroi um ponteiro para seu tipo string
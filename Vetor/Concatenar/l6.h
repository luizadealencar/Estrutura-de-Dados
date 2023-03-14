#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct palavra{
  char *vet;
  int tam;
};

typedef struct palavra String;

String* cria_vetor();
void fill(String *s, char *c, int tam);
void imprime_vetor(String *s);
void free_vetor(String *s);
void concatenarStrings(char *str1, int tam1, char *str2, int tam2, char *str3);
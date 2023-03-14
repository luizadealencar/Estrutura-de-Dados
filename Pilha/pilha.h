#include <stdio.h>
#include <stdlib.h>

typedef int info;

typedef struct pilha
{
  int n;
  info *pino;
}Pilha;

Pilha* Create(); //Criação (alocação) de pilhas vazias
info size(Pilha *p);//Tamanho da pilha
void Push(Pilha *p, info v); //Inserir um elemento no topo da pilha
info Pop(Pilha *p); //Remover o elemento do topo da pilha
info Peek(Pilha *p); //Inspecionar o elemento do topo da pilha mas sem remover
void Print(Pilha *A); //Imprimir o conteudo da pilha no terminal
void libera(Pilha *p); //Libera a pilha
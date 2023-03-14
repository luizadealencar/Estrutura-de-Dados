#include <stdio.h>
#include <stdlib.h>

typedef int info;

typedef struct pilha
{
  int n;
  info *pino;
}Pilha;

Pilha* Create(); //Criação (alocação) de pilhas vazias
void preencher(Pilha *A, info n); //Prenche as pilhas
info size(Pilha *p);//Tamanho da pilha
void Push(Pilha *p, info v); //Inserir um elemento no topo da pilha
info Pop(Pilha *p); //Remover o elemento do topo da pilha
info Peek(Pilha *p); //Inspecionar o elemento do topo da pilha mas sem remover
void impressaoAB(Pilha *A, Pilha *B); //Impressão dos pinos A e B
void impressaoAC(Pilha *A, Pilha *C); //Impressão dos pinos A e C
void impressaoBC(Pilha *B, Pilha *C); //Impressão dos pinos B e C
void semimpressao(Pilha *pino1, Pilha *pino2);
void move(Pilha *pino1, Pilha *pino2); //movendo os pinos
void Print(Pilha *A, Pilha *B, Pilha *C); //Imprimir o conteudo da pilha no terminal
void libera(Pilha *p); //Libera a pilha
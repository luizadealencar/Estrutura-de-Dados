#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define MAX 150

//Criação (alocação) de pilhas vazias
Pilha* Create()
{
  Pilha *p=(Pilha*)malloc(sizeof(Pilha));
  p->pino=(info*)malloc(MAX*sizeof(info));
  p->n=0;
  return p;
}

//Tamanho da pilha
info size(Pilha *p)
{
  return p->n;
}

//Inserir um elemento no topo da pilha
void Push(Pilha *p, info v)
{
  if (size(p)==MAX)
  {
    printf("Capacidade da pilha estourou.\n");
    exit(1);
  }

  p->pino[p->n]=v;
  p->n++;
}

//Remover o elemento do topo da pilha
info Pop(Pilha *p)
{
  info v;

  if (size(p)==0)
  {
    printf("Pilha vazia.\n");
    return -1;
  }

  v=p->pino[p->n-1];
  p->n--;
  
  return v;
}

//Inspecionar o elemento do topo da pilha mas sem remover
info Peek(Pilha *p)
{
  return p->pino[p->n-1];
}

//Imprimir o conteudo da pilha no terminal
void Print(Pilha *A)
{
  printf("A: ");
  for (int i=0;i<A->n;i++)
  {
    printf("%d ", A->pino[i]);
  } 

  printf("\n");
}

//Libera a pilha
void libera(Pilha *p)
{
  free(p);
}
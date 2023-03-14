#include <stdio.h>
#include <stdlib.h>
#include "torredehanoi.h"
#define MAX 150

//Criação (alocação) de pilhas vazias
Pilha* Create()
{
  Pilha *p=(Pilha*)malloc(sizeof(Pilha));
  p->pino=(info*)malloc(MAX*sizeof(info));
  p->n=0;
  return p;
}

//Preenche a pilha
void preencher(Pilha *A, info n)
{
  for (info i=n;i>=1;i--)
  {
    Push(A, i);
  }
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

//impressao A e B
void impressaoAB(Pilha *A, Pilha *B){
  if(A->n==0)
  {
    move(A,B);
    printf("Move disk %d from B to A\n", Peek(A));
  }
  else if(B->n==0)
  {
    move(B,A);
    printf("Move disk %d from A to B\n", Peek(B));
  }
  else if(Peek(A)<Peek(B))
  {
    move(B, A);
    printf("Move disk %d from A to B\n", Peek(B));
  }
  else if(Peek(B)<Peek(A))
  {
    move(A, B);
    printf("Move disk %d from B to A\n", Peek(A));
  } 
}

//impressao A e C
void impressaoAC(Pilha *A, Pilha *C){
  if(A->n==0)
  {
    move(A, C);
    printf("Move disk %d from C to A\n", Peek(A));
  }
  else if(C->n==0)
  {
    move(C, A);
    printf("Move disk %d from A to C\n", Peek(C));
  }
  else if(Peek(A)<Peek(C))
  {
    move(C, A);
    printf("Move disk %d from A to C\n", Peek(C));
  }
  else if(Peek(C)<Peek(A))
  {
    move(A, C);
    printf("Move disk %d from C to A\n", Peek(A));
  }
}

//impressao B e C
void impressaoBC(Pilha *B, Pilha *C){
  if(C->n==0)
  {
    move(C, B);
    printf("Move disk %d from B to C\n", Peek(C));
  }
  else if(B->n==0)
  {
    move(B, C);
    printf("Move disk %d from C to B\n", Peek(B));
  }
  else if(Peek(C)<Peek(B))
  {
    move(B, C);
    printf("Move disk %d from C to B\n", Peek(B));
  }
  else if(Peek(B)<Peek(C))
  {
    move(C, B);
    printf("Move disk %d from B to C\n", Peek(C));
  }
}

void semimpressao(Pilha *pino1, Pilha *pino2){
  if(pino2->n==0)
  {
    move(pino2, pino1);
  }
  else if(pino1->n==0)
  {
    move(pino1, pino2);
  }
  else if(Peek(pino2)<Peek(pino1))
  {
    move(pino1, pino2);
  }
  else if(Peek(pino1)<Peek(pino2))
  {
    move(pino2, pino1);
  }
}

//movendo os pinos
void move(Pilha *pino1, Pilha *pino2)
{
  Push(pino1, Pop(pino2));
}

//Imprimir o conteudo da pilha no terminal
void Print(Pilha *A, Pilha *B, Pilha *C)
{
  printf("A: ");
  for (int i=0;i<A->n;i++)
  {
    printf("%d ", A->pino[i]);
  }
  
  printf("\nB: ");
  for (int i=0;i<B->n;i++)
  {
    printf("%d ", B->pino[i]);
  }

  printf("\nC: ");
  for (int i=0;i<C->n;i++)
  {
    printf("%d ", C->pino[i]);
  }
  

  printf("\n");
}

//Libera a pilha
void libera(Pilha *p)
{
  free(p);
}
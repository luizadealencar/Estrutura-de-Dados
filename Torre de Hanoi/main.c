#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "torredehanoi.h"
#define MAX 150

int main(int argc, char **argv)
{
  info N=atoi(argv[1]);

  Pilha *A=Create(), *B=Create(), *C=Create();

  preencher(A, N);

  if(argc==3)
  {
    printf("=> Solving the Tower of Hanoi with %d disks.\n", N);

    printf("=> Initial configuration:\n");
    Print(A, B, C);

    printf("=>Moves:\n");
    if((N%2)==0)
    {
      while(C->n<N)
      {
        impressaoAB(A, B);
        if(C->n==N) break;
        impressaoAC(A, C);
        if(C->n==N) break;
        impressaoBC(B, C);
      }
    }
    else
    {
      while(C->n<N)
      {
        impressaoAB(A, C);
        if(C->n==N) break;
        impressaoAC(A, B);
        if(C->n==N) break;
        impressaoBC(B, C);
      }
    }
    printf("=> Final configuration:\n");
    Print(A, B, C);
  }
    
  
  if(argc==2)
  {
    if((N%2)==0)
    {
      while(C->n<N)
      {
        semimpressao(A, B);
        if(C->n==N) break;
        semimpressao(A, C);
        if(C->n==N) break;
        semimpressao(B, C);
      }
    }
    else
    {
      while(C->n<N)
      {
        semimpressao(A, C);
        if(C->n==N) break;
        semimpressao(A, B);
        if(C->n==N) break;
        semimpressao(B, C);
      }
    }
  }
  
  libera(A);
  libera(B);
  libera(C);
  
  return 0;
}
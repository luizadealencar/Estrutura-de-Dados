#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define MAX 150

int main()
{
  Pilha *A=Create();
	Push(A, 1);
	Print(A);
	Peek(A);
	Pop(A);
  libera(A);
  return 0;
}
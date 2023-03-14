#include <stdio.h>
#include <stdlib.h>

typedef float elem;

typedef struct cell{
	elem valor;
	int i, j; //posição i-linha posição j-coluna 
	struct cell *prox_lin, *prox_col;
}celula;

celula *criar_celula(int i, int j, elem valor); //inicia celula
int geti(celula *aux); //retorna o i da celula
int getj(celula *aux); //retorna o j da celula
celula *getprox_col(celula *aux); //retorna o proximo coluna da celula
celula *getprox_lin(celula *aux); //retorna o proxima linha da celula
void setprox_col(celula *aux, celula *aux2); //o proximo coluna da celula 1, recebe a celula 2
void setprox_lin(celula *aux, celula *aux2); //o proximo linha da celula 1, recebe a celula 2
elem getvalor(celula *aux); //retorna o valor da celula
void setvalor(celula *aux, elem valor); //a celula 1, recebe um valor
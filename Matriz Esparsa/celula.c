#include <stdio.h>
#include <stdlib.h>
#include "celula.h"

//inicia a celula
celula *criar_celula(int i, int j, elem valor){
	celula *novo=(celula*)malloc(sizeof(celula));
	novo->valor=valor;
	novo->i=i;
	novo->j=j;
	novo->prox_lin=novo->prox_col=NULL;
	return novo;
}

//retorna o i da celula
int geti(celula *aux){
	return aux->i;
}

//retorna o j da celula
int getj(celula *aux){
	return aux->j;
}

//retorna o proximo coluna da celula
celula *getprox_col(celula *aux){
	return aux->prox_col;
}

//retorna o proxima linha da celula
celula *getprox_lin(celula *aux){
	return aux->prox_lin;
}

//o proximo coluna da celula 1, recebe a celula 2
void setprox_col(celula *aux, celula *aux2){
	aux->prox_col=aux2;
}

//o proximo linha da celula 1, recebe a celula 2
void setprox_lin(celula *aux, celula *aux2){
	aux->prox_lin=aux2;
}

//retorna o valor da celula
elem getvalor(celula *aux){
	return aux->valor;
}

//a celula 1, recebe um valor
void setvalor(celula *aux, elem valor){
	aux->valor=valor;
}
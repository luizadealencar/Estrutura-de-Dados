#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"
#define N 120

struct fila{
	tipo *v;
	int ini, fim;
};

Fila *fila_cria(){
	int size=N;
	Fila *q;
	q=(Fila*)malloc(sizeof(Fila));
	q->v=(tipo*)malloc(size*sizeof(tipo));
	q->ini=q->fim=N/2;
	return q;
}

void fila_insere(Fila *q, tipo elem){
	q->v[q->fim]=elem;
	q->fim=(q->fim+1) % N;
}

tipo fila_retira(Fila *q){
	tipo x;
	x=q->v[q->ini];
	q->ini=(q->ini+1)%N;
	return x;
}

int fila_vazia(Fila *q){
	return q->fim==q->ini;
}

int fila_cheia(Fila *q){
	return (q->fim+1)%N==q->ini;
}

void fila_imprime(Fila *q){
	if(q->ini<=q->fim){
		for(int i=q->ini;i<q->fim;i++){
			printf("%d ", q->v[i]);
		}
	}else{
		for(int i=q->ini;i<N;i++){
			printf("%d ", q->v[i]);
		}
		for (int i=0;i<q->fim;i++){
			printf("%d ", q->v[i]);
		}
	}
	printf("\n");
}

int fila_tamanho(Fila *q){
	if(q->ini<=q->fim){
		return q->fim-q->ini;
	}
	return(N-q->ini)+(q->fim-0);
}

Fila *fila_libera(Fila *q){
	free(q->v);
	free(q);
	return NULL;
}
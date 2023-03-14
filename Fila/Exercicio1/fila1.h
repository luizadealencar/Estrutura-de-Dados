#include <stdio.h>
#include <stdlib.h>

typedef float tipoElemFila; /* tipo elemento: float */

typedef struct fila Fila;

Fila *fila_cria(void);
void fila_insere(Fila *f, tipoElemFila v);
tipoElemFila fila_retira(Fila *f);
int fila_vazia(Fila *f);
void fila_libera(Fila *f);
void fila_imprime(Fila *f);
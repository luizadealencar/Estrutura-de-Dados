#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"

int main(){
    Fila *f=fila_cria();
    fila_insere(f, 1);
    fila_insere(f, 2);
    fila_retira(f);
    fila_insere(f, 3);
    fila_insere(f, 4);
    fila_retira(f);
    fila_insere(f, 5);
    fila_insere(f, 6);
    fila_retira(f);
    fila_imprime(f);
    fila_libera(f);
    return 0;
}
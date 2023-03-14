#include <stdio.h>
#include <stdlib.h>
#include "fila1.h"

int main(){
    Fila *f=fila_cria();
    fila_insere(f, 5.2);
    fila_insere(f, 5.5);
    fila_retira(f);
    fila_imprime(f);
    fila_libera(f);
    return 0;
}
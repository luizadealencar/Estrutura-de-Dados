#include <stdio.h>
#include <stdlib.h>

typedef int elemento;

struct no{
    elemento num;
    struct no *prox;
};

typedef struct no Cell;

Cell* create_cell(elemento info); //retorna uma nova celula alocada dinamicamente com o parametro info armazenado 
void print_cell(Cell *c); //Recebe como parametro uma celula da lista e imprime o numero armazenado nela
void setprox(Cell *aux1, Cell *aux2);
Cell *getprox(Cell *aux1);
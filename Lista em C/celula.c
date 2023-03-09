#include <stdio.h>
#include <stdlib.h>
#include "celula.h"

//retorna uma nova celula alocada dinamicamente com o parametro info armazenado
Cell* create_cell(elemento info){
    Cell *nova_celula=(Cell*)malloc(sizeof(Cell)); //cria uma celula nova
    nova_celula->num=info; //insere a informacao na celula
    nova_celula->prox=NULL; //o ultimo fica como NULL
    return nova_celula;
}

//Recebe como parametro uma celula da lista e imprime o numero armazenado nela 
void print_cell(Cell *c){
    printf("%d", c->num);
}

void setprox(Cell *aux1, Cell *aux2){
    aux1->prox=aux2;
}

Cell *getprox(Cell *aux1){
    return aux1->prox;
}
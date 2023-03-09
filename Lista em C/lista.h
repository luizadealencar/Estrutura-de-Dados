#include <stdio.h>
#include <stdlib.h>
#include "celula.h"

struct lista{
    Cell *prim, *ulti; 
    int tam;
};

typedef struct lista List;

List* create_list(); /*cria uma lista */
int size_list(List *lst); /* retorna o tamanho da lista */
void insert_list(List *lst, elemento info, int pos); /* insere na posicao POS da lista LST o elemento INFO , se for uma POS abaixo de 1 , deve ser inserida antes da primeira posicao, se for acima do tamanho atual da lista, deve ser inserida apos a ultima posicao */
void remove_list(List *lst, int pos); /* remove o elemento na posicao POS da lista , caso nao exista a posicao POS, deve ser usado 'printf("posicao nao encontrada");' */
void print_list(List *lst); /* imprime todos os nodos da lista, se a lista estiver vazia nao deve imprimir NADA */
void free_list(List *lst); /*libera a lista completamente liberando todos os nodos internos da mesma */
#include <stdio.h>
#include <stdlib.h>

//Exercicio 1 - Estrutura opaca
typedef int info_t;

//Exercicio 1 - Struct com tamanho e ponteiro para um vetor
typedef struct lista{
    info_t *vet;
    int tam;
}List;

List* create_list();//Cria uma lista nova
int size_list(List *lst);//Retorna o tamanho da lista
void insert_list(List *lst, info_t info, int pos);//Insere o elemento na posicao dada
void remove_list(List *lst, int pos);//Remove o elemento da posicao dada
info_t get_elem_list(List *lst, int pos);//Retorna o elemento da posicao dada
int get_pos_list(List *lst, info_t info);//Retorna a posicao do elemento dado
void print_list(List *lst);//Imprime a lista
void free_list(List *lst);//Libera a lista
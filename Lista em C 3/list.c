#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#include "list.h"

//Exercicio 2 - Cria uma lista nova
List* create_list(){
    List *nova=(List*)malloc(sizeof(struct lista));
    nova->vet=(info_t*)malloc(MAX*sizeof(info_t));
    nova->tam=0;
    return nova;
}

//Exercicio 3 - Retorna o tamanho da lista
int size_list(List *lst){
    return lst->tam;
}

//Exercicio 4 - Insere o elemento na posicao dada
void insert_list(List *lst, info_t info, int pos){
    if (size_list(lst)>=MAX){
        printf("Lista cheia.");
        exit(1);
    }
    if (pos<0){//se posicao for menor que 0, insere no inicio
      lst->vet[pos]=info;
    }
    if(pos>size_list(lst)){//se posicao for maior que o tamanho, insere no final
      lst->vet[size_list(lst)]=info;
    }
    for(int i=size_list(lst);i>pos;i--){
        lst->vet[i]=lst->vet[i-1];
    }
    lst->vet[pos]=info;
    lst->tam++;
}

//Exercicio 5 - Remove o elemento da posicao dada
void remove_list(List *lst, int pos){
    if(lst!=NULL){
        if (pos==0 || pos<=size_list(lst)){//se posicao for igual a 0 ou se existir
            for (int i=pos;i<size_list(lst);++i) {
                lst->vet[i]=lst->vet[i+1];
            }
        }else{
            printf("Não existe essa posição.");
            exit(1);
        }
    }else{
        printf("Lista vazia.");
        exit(1);
    }
    lst->tam--;
}

//Exercicio 6 - Retorna o elemento da posicao dada
info_t get_elem_list(List *lst, int pos){
    if(lst!=NULL){
        if (pos==0 || pos<=size_list(lst)){//se posicao for igual a 0 ou se existir
            return lst->vet[pos];
        }else{
            printf("Não existe essa posição.");
            exit(1);
        }
    }else{
        printf("Lista vazia.");
        exit(1);
    }
}

//Exercicio 7 - Retorna a posicao do elemento dado
int get_pos_list(List *lst, info_t info){
    for(int i=0;i<size_list(lst);i++){
        if(lst->vet[i]==info){
            return i;
        }
    }
    return -1;
}

//Exercicio 8 - Imprime a lista
void print_list(List *lst){
    for (int i=0;i<lst->tam;++i){
        printf("%d ", lst->vet[i]);
    }
    printf("\n");
}

//Exercicio 9 - Libera a lista
void free_list(List *lst){
    free(lst);
}
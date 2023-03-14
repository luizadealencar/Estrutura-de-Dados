#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#include "l7ex1.h"
#include "l7ex2.h"
#include "l7ex3.h"
#include "l7ex4.h"

void insert_list(List *lst, info_t info, int pos){
    if (lst->tam>=MAX){
        printf("Lista cheia.");
        exit(1);
    }
    if (pos>MAX){
        printf("Opção invalida");
        exit(1);
    }
    for(int i=size_list(lst);i>pos;i--){
        lst->vet[i]=lst->vet[i-1];
    }
    lst->vet[pos]=info;
    lst->tam++;
}
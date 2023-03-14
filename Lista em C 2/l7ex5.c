#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#include "l7ex1.h"
#include "l7ex2.h"
#include "l7ex3.h"
#include "l7ex4.h"
#include "l7ex5.h"

void remove_list(List *lst, int pos){
    if(lst!=NULL){
        if (pos==0 || pos<=size_list(lst)){
            for (int i=pos;i<size_list(lst);++i) {
                lst->vet[i]=lst->vet[i+1];
            }
        }else{
            exit(1);
        }
    }else{
        printf("Lista vazia.");
        exit(1);
    }
    lst->tam=lst->tam-1;
}
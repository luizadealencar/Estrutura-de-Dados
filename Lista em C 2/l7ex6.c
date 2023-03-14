#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#include "l7ex1.h"
#include "l7ex2.h"
#include "l7ex3.h"
#include "l7ex4.h"
#include "l7ex5.h"
#include "l7ex6.h"

info_t get_elem_list(List *lst, int pos){
    if(lst!=NULL){
        if (pos==0 || pos<=size_list(lst)){
            return lst->vet[pos];
        }else{
            exit(1);
        }
    }else{
        printf("Lista vazia.");
        exit(1);
    }
}
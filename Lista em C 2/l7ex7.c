#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#include "l7ex1.h"
#include "l7ex2.h"
#include "l7ex3.h"
#include "l7ex4.h"
#include "l7ex5.h"
#include "l7ex6.h"
#include "l7ex7.h"

int get_pos_list(List *lst, info_t info){
    int i;
    for(i=0;i<size_list(lst);i++){
        if(lst->vet[i]==info){
            return i;
        }
    }
    return -1;
}
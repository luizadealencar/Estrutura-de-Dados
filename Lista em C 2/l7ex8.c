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
#include "l7ex8.h"

void print_list(List *lst){
    for (int i=0;i<lst->tam;++i){
        printf("%d ", lst->vet[i]);
    }
    printf("\n");
}
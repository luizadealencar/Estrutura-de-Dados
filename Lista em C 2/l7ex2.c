#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#include "l7ex1.h"
#include "l7ex2.h"

List* create_list(){
    List *nova=(List*)malloc(sizeof(struct lista));
    nova->vet=(info_t*)malloc(MAX*sizeof(info_t));
    nova->tam=0;
    return nova;
}
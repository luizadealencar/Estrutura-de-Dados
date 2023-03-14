#include <stdio.h>
#include <stdlib.h>
#include "fila1.h"

struct elemFila{
    tipoElemFila info;
    struct elemFila *prox;
};

typedef struct elemFila ElemFila;

struct fila{
    ElemFila *ini, *fim;
};

//1 - A
Fila *fila_cria(void){
    Fila *f=(Fila*)malloc(sizeof(Fila));
    f->ini=f->fim=NULL;
    return f;
}

int fila_vazia(Fila *f){
    return (f->ini==NULL);
}

//1 - B
void fila_insere(Fila *f, tipoElemFila v){
    ElemFila *n=(ElemFila*)malloc(sizeof(ElemFila));
    if (n==NULL) { 
        printf("sem memoria\n"); 
        exit(1); 
    }
    n->info=v; // armazena informacao
    n->prox=NULL; // novo nó passa a ser o íltimo
    if (!fila_vazia(f)){ // verifica se lista nao é vazia
        f->fim->prox=n;
    }else{ // fila estava vazia
        f->ini=n;
    }
    f->fim=n; // fila aponta para novo elemento
}

//1 - C
tipoElemFila fila_retira(Fila *f){
    ElemFila *t;
    tipoElemFila v;
    if (fila_vazia(f)){
        printf("Fila vazia.\n"); 
        exit(1);
    }
    t=f->ini;
    v=t->info;
    f->ini=t->prox;
    if (f->ini==NULL){ //verifica se fila ficou vazia
        f->fim=NULL;
    }
    free(t);
    return v;
}

//1 - D
void fila_imprime(Fila *f){
    ElemFila *p;
    if (fila_vazia(f)) return;
    for (p=f->ini;p!=NULL;p=p->prox){
        printf("%.2f ", p->info);
    }
    printf("\n");
}

//1 - E
void fila_libera(Fila *f){
    ElemFila *q=f->ini, *t;
    while (q!=NULL){
        t=q->prox;
        free(q);
        q=t;
    }
    free(f);
}
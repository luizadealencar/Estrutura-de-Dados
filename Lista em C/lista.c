#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*cria uma lista */
List* create_list(){
    List *lst=(List*)malloc(sizeof(List));
    lst->prim=lst->ulti=NULL;
    lst->tam=0;
    return lst;
}

/* retorna o tamanho da lista */
int size_list(List *lst){
    return lst->tam;
}

/* insere na posicao POS da lista LST o elemento INFO , se for uma POS abaixo de 1 , deve ser inserida antes da primeira posicao, se for acima do tamanho atual da lista, deve ser inserida apos a ultima posicao */
void insert_list(List *lst, elemento info, int pos){
    Cell *novo=create_cell(info); //cria uma nova celula para guadar o elemento
    if (pos<=0){ //se pos for menor ou igual a 0, a celula nova é inserida no inicio
        if(size_list(lst)==0){ //se o tamanho for igual a 0
            lst->prim=novo; //o primeiro da lista se torna a celula nova
            lst->ulti=novo;
        }else{
            setprox(novo, lst->prim); //o prox do novo recebe o primeiro da lista
            lst->prim=novo; //e o primeiro se torna o novo
        }
    }else if(pos>=(size_list(lst))){ //se pos for maior ou igual o tamanho da lista, a celula é inserida no final
        if(size_list(lst)==0){ //se o tamanho for igual a 0
            lst->prim=novo; //o primeiro da lista se torna a celula nova
            lst->ulti=novo;
        }else{ //se nao
            Cell *aux=lst->prim; //aux recebe o primeiro da lista
            while(getprox(aux)!=NULL){
                aux=getprox(aux); //caminha pela lista até achar o NULL no prox
            }
            setprox(aux, novo); //quando achar, encaixa a celula nova
            lst->ulti=novo;
        }
    }else{ //se for qualquer pos
        if(size_list(lst)==0){ //se o tamanho for igual a 0
            lst->prim=novo; //o primeiro da lista se torna a celula nova
            lst->ulti=novo;
        }else{
            Cell *ante=lst->prim; 
            for(int i=1;i<pos;i++){
                ante=getprox(ante);
            }
            setprox(novo, getprox(ante)); //o prox do novo recebe o prox da celula anterior
            setprox(ante, novo);
        }
    }
    lst->tam++;
}

/* remove o elemento na posicao POS da lista , caso nao exista a posicao POS, deve ser usado 'printf("posicao nao encontrada");' */
void remove_list(List *lst, int pos){	
    if (pos<0 || pos>=(size_list(lst))){ //se posição for maior que o tamanho ou menor do que 0
        printf("\nposicao nao encontrada\n");
        return;
    }
    if (pos==0){
        if(size_list(lst)==1){ //tamanho igual a 1
            lst->prim=NULL;
        }else{
            lst->prim=getprox(lst->prim); //tamanho maior que 1
        }
    }
    if(pos>0){
        Cell *aux=lst->prim, *prev;
        int count=0;
        while(aux){ //verifica se aux não chegou ao fim e percorre a posicao
            prev=aux; //prev guarda valor o elemento que vai remover
            aux=getprox(aux);
            count++;
            if(aux && count==pos){ //se aux percorrer e o count for igual a posicao dada
                setprox(prev, getprox(aux)); //o prev guarda o elemento prox
                free(aux);
            }
        }
    }
    lst->tam--;
}

/* imprime todos os nodos da lista, se a lista estiver vazia nao deve imprimir NADA */
void print_list(List *lst){
    Cell *aux=lst->prim;
    while(aux!=NULL){
        print_cell(aux); //imprime a celula
        aux=getprox(aux); //pula para o proximo
        if (aux!=NULL){
            printf(", ");
        }
    }
    printf("\n");
}

/*libera a lista completamente liberando todos os nodos internos da mesma */
void free_list(List *lst){
    Cell* aux=lst->prim;
    while(aux!=NULL){
        Cell* aux2=getprox(aux); 
        free(aux); 
        aux=aux2;
    }
}
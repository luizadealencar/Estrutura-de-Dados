#include <stdio.h>
#include <stdlib.h>
#include "celula.h"
#include "matriz.h"

//inicia a matriz
Matriz* iniciar_mat(){
    Matriz *mat=(Matriz*)malloc(sizeof(Matriz));
    mat->l=mat->c=0;
    mat->linha=mat->coluna=NULL;
    return mat;
}

//preenche uma matriz
void preencher_mat(Matriz *mat, char fn[]){
    FILE *arq;
    int i=0, j=0, tamanho=0;
    elem valor;
    arq=fopen(fn, "rt");

    if (arq!=NULL){
        fscanf(arq, "%d", &tamanho);
        mat->l=mat->c=tamanho;
        mat->linha=malloc(mat->l*sizeof(celula*));
        mat->coluna=malloc(mat->c*sizeof(celula*));
        for(int i=0;i<mat->l;i++){
            mat->linha[i]=mat->coluna[i]=NULL;
        }
        if (!fscanf(arq, "\n")){
            while (!feof(arq)){
                fscanf(arq, "%d;%d;%g", &i, &j, &valor);
                inserir(mat, i, j, valor);
            }
        }
    }
    fclose(arq);
}

//verifica se existe alguma matriz na lista da linha
celula* existecel(Matriz *mat, int i, int j){
    celula *percorrer=mat->linha[i-1];
    while(percorrer!=NULL){
        if(i==geti(percorrer) && j==getj(percorrer)){
            return percorrer; //retorna a celula da posição i e j
        }
        percorrer=getprox_col(percorrer);
    }
    return NULL; //se não tiver nada na lista, retorna NULL
}

void inserir(Matriz *mat, int i, int j, elem valor){
    celula *cel=existecel(mat, i, j); //verifica se existe alguma celula nas posições i e j
    if(cel!=NULL){ //se houver existir a celula i e j, vai apenas trocar o valor
        setvalor(cel, valor);
    }
    if(cel==NULL){
        celula *novo=criar_celula(i, j, valor);
        celula *aux1=NULL, *coluna=mat->coluna[j-1];
        while(coluna!=NULL){ //se essa coluna não estiver vazia
            if(geti(coluna)<i){ //se a célula nova for linha maior, ela vai ser encaixada após a anterior(com o i menor)
                aux1=coluna; //aux1 recebe a anterior
                coluna=getprox_lin(coluna); //anda na coluna até encontrar o ultimo da lista coluna (que seria o anterior do nova)
            }else{ //se a célula nova for linha menor, ela vai ser encaixada antes da anterior(com o i maior)
                if(aux1==NULL){ //se anterior(aux1) não tiver nada
                    mat->coluna[j-1]=novo;
                }else{ //se tiver alguma celula
                    setprox_lin(aux1, novo); //insere o novo no proximo linha do anterior da mesma coluna
                }
                break;
            }
        }
        if(coluna==NULL){ //se a coluna estiver vazia
            if(aux1==NULL){ //se não tiver nada na coluna a celula nova é inserida na primeira posição da lista da coluna
                mat->coluna[j-1]=novo;
            }else{ //se tiver alguma celula dentro da coluna, a celula nova eh inserida na proxima linha do anterior
                setprox_lin(aux1, novo);
            }
        }
        celula *linha=mat->linha[i-1];
        aux1=NULL;
        while(linha!=NULL){//se essa linha não estiver vazia
            if(getj(linha)<j){ //se a célula nova tiver a coluna maior, ela vai ser encaixada após a anterior(com o j menor)
                aux1=linha; //aux1 recebe a anterior
                linha=getprox_col(linha); //anda na linha até encontrar o ultimo da lista linha (que seria o anterior do nova)
            }else{ //se a célula nova for linha menor, ela vai ser encaixada antes da anterior(com o i maior)
                if(aux1==NULL){ //se anterior(aux1) não tiver nada
                    mat->linha[i-1]=novo;
                }else{ //se tiver alguma celula
                    setprox_col(aux1, novo); //insere o novo no proximo coluna do anterior da mesma linha
                }
                break;
            }
        }
        if(linha==NULL){ //se a linha estiver vazia
            if(aux1==NULL){ //se não tiver nada na linha a celula nova é inserida na primeira posição da lista da linha
                mat->linha[i-1]=novo;
            }else{ //se tiver alguma celula dentro da linha , a celula nova eh inserida na proxima coluna do anterior
                setprox_col(aux1, novo);
            }
        }
    }
    if(valor==0.0){ //se o valor é igual a 0.0 ou 0, a celula eh removida
        deleta_elemento(mat, i, j);
    }
}

//remove celula
void deleta_elemento(Matriz *mat, int i, int j){
    celula *ant=NULL, *atual=mat->linha[i-1];
    while (atual!=NULL && getj(atual)<j){ //vai andar na linha até encontrar a celula inserida aqui
        ant=atual;
        atual=getprox_col(atual);
    }
    free(atual);
    if(ant==NULL){ //se não tiver outras celulas na linha vai inserir o proximo coluna da atual
        mat->linha[i-1]=getprox_col(atual);
    }else{ //se tiver alguma celula na lista, a anterior da celula inserida aqui vai receber no proximo coluna da atual
        setprox_col(ant, getprox_col(atual));
    }
}

Matriz* soma_matriz(Matriz *mat1, Matriz *mat2){
    Matriz *mat3=iniciar_mat();
    mat3->l=mat3->c=mat1->l;
    mat3->linha=malloc(mat3->l*sizeof(celula*));
    mat3->coluna=malloc(mat3->c*sizeof(celula*));
    for(int i=0;i<mat3->l;i++){
        mat3->linha[i]=mat3->coluna[i]=NULL;
    }
	for(int i=0;i<mat1->l;i++){
        celula *linha1=mat1->linha[i], *linha2=mat2->linha[i];
        while(linha1!=NULL && linha2!=NULL){
            inserir(mat3, geti(linha1), getj(linha1), getvalor(linha1));
            inserir(mat3, geti(linha2), getj(linha2), getvalor(linha2));
            if(geti(linha1)==geti(linha2) && getj(linha1)==getj(linha2)){
                inserir(mat3, geti(linha1), getj(linha1), getvalor(linha1)+getvalor(linha2));
            }else{
                inserir(mat3, geti(linha1), getj(linha1), getvalor(linha1));
                inserir(mat3, geti(linha2), getj(linha2), getvalor(linha2));
            }
            linha1=getprox_col(linha1);
            linha2=getprox_col(linha2);
        }
        while(linha1!=NULL){
            inserir(mat3, geti(linha1), getj(linha1), getvalor(linha1));
            linha1=getprox_col(linha1);
        }
        while(linha2!=NULL){
            inserir(mat3, geti(linha2), getj(linha2), getvalor(linha2));
            linha2=getprox_col(linha2);
        }
        celula *coluna1=mat1->coluna[i], *coluna2=mat2->coluna[i];
        while(coluna1!=NULL && coluna2!=NULL){
            if(geti(coluna1)==geti(coluna2) && getj(coluna1)==getj(coluna2)){
                inserir(mat3, geti(coluna1), getj(coluna1), getvalor(coluna1)+getvalor(coluna2));
            }else{
                inserir(mat3, geti(coluna1), getj(coluna1), getvalor(coluna1));
                inserir(mat3, geti(coluna2), getj(coluna2), getvalor(coluna2));
            }
            coluna1=getprox_lin(coluna1);
            coluna2=getprox_lin(coluna2);
        }
    }
    return mat3;
}

void imprimir(Matriz *mat){
    printf("%d\n", mat->l);
    for (int i=0;i<mat->l;i++){
        celula *aux=mat->linha[i];
        while (aux!=NULL){
            printf("%d;%d;%g\n", geti(aux), getj(aux), getvalor(aux));
            aux=getprox_col(aux);
        }
    }
}

void desalocar(Matriz *mat){
    for(int i=0;i<mat->l;i++){
        celula *cel=mat->linha[i];
        while(cel!=NULL){
            free(cel);
            cel=getprox_col(cel);
        }
    }
    free(mat);
}
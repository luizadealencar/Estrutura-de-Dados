#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int l, c; //tamanho de linhas e colunas da matriz
	celula **linha, **coluna; //lista da linha e coluna
}Matriz;

Matriz* iniciar_mat(); //inicia matriz
void preencher_mat(Matriz *mat, char fn[]); //preenche uma matriz
celula* existecel(Matriz *mat, int i, int j); //verifica se existe alguma matriz na lista da linha
void inserir(Matriz *mat, int i, int j, elem valor);
void deleta_elemento(Matriz *mat, int i, int j); //remove celula
Matriz* soma_matriz(Matriz *mat1, Matriz *mat2);
void imprimir(Matriz *mat);
void desalocar(Matriz *mat);
#include <stdio.h>
#include <stdlib.h>
#include "celula.h"
#include "matriz.h"

int main(int argc, char **argv){
	Matriz *mat1=iniciar_mat(), *mat2=iniciar_mat();

	preencher_mat(mat1, argv[1]);
	preencher_mat(mat2, argv[2]);

	Matriz *mat3=soma_matriz(mat1, mat2);
	imprimir(mat3);
	
	desalocar(mat1);
	desalocar(mat2);
	desalocar(mat3);
	return 0;
}
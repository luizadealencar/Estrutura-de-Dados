#include <stdio.h>

int main(){
  int matriz[4][2], aux;
  for (int x=0;x<4;x++){
    for (int y=0;y<2;y++){
			printf("Matriz[%d][%d]: ", x, y);
      scanf("%d", &matriz[x][y]);
    }
  }
  aux=matriz[0][0];
  matriz[0][0]=matriz[1][0];
  matriz[1][0]=aux;
  aux=matriz[0][1];
  matriz[0][1]=matriz[1][1];
  matriz[1][1]=aux;
  aux=matriz[2][0];
  matriz[2][0]=matriz[3][0];
  matriz[3][0]=aux;
  aux=matriz[2][1];
  matriz[2][1]=matriz[3][1];
  matriz[3][1]=aux;
	printf("\nMatriz resultante:\n");
  for (int x=0;x<4;x++){
    for (int y=0;y<2;y++){
      printf("%d\t", matriz[x][y]);
    }
    printf("\n");
  }
}
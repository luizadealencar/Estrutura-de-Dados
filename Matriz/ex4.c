#include <stdio.h>

int main(){
  double maior;
  double matriz[3][3];
  for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
			printf("Numero: ");
      scanf("%lf", &matriz[i][j]);
    }
  }
  maior=matriz[0][0];
  for (int h=0;h<3;h++){
  	for (int k=0;k<3;k++){
  		if (matriz[h][k]>=maior){
  			maior=matriz[h][k]; 
  		}
  	}
  }
  for (int h=0;h<3;h++){
  	for (int k=0;k<3;k++){
  		matriz[h][k]=matriz[h][k]/maior;
   	}
  }
	printf("\nMatriz dividida por %.2lf\n\n", maior);
  for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
      printf("%.20lf\t", matriz[i][j]);
    }
    printf("\n");
  } 
}
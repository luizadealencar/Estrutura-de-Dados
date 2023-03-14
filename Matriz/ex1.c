#include <stdio.h>

int main(){
  int qtd;
  char nome[100];
  float notas, soma=0, media;
	printf("Nome: ");
  scanf("%[^\n]", nome);
	printf("Quantas provas foram feitas: ");
  scanf("%d", &qtd);
	printf("\n");
  for (int i=1;i<=qtd;i++){
		printf("%dª Nota: ", i);
    scanf("%f", &notas);
    soma+=notas;
  }
  media=soma/qtd;
	printf("\n");
  printf("Nome: %s\n", nome);
  printf("Media das Notas: %.2f\n", media);
}
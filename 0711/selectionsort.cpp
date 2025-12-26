#include <stdio.h>

void imprimir(int vetor[], int tam){
	
	for (int i = 0; i < tam; i++)
		printf("%4d", vetor[i]);

	printf("\n");
}

void selection_sort (int vetor[],int max) {
  int i, j, min, aux;
  
  for (i = 0; i < (max - 1); i++) {
    /* O minimo é o primeiro numero nao ordenado ainda */
    min = i;

    printf("%do iteracao: ", i+1);
    for (j = i+1; j < max; j++) {
      /* Caso tenha algum numero menor ele faz a troca do minimo*/
      if (vetor[j] < vetor[min]) {
	min = j;
      }
    }
    /* Se o minimo for diferente do primeiro numero nao ordenado ele faz a troca para ordena-los*/
    if (i != min) {
      aux = vetor[i];
      vetor[i] = vetor[min];
      vetor[min] = aux;
    }
    imprimir(vetor, max);
  }
}

main () {
  int max, i;
  /* indica o maximo de elementos do vetor*/
  scanf ("%d",&max);
  
  int  vetor[max];
  /* preenche o vetor */
  for (i = 0; i < max; i++) {
    scanf ("%d",&vetor[i]);
  }
  printf("Vetor lido: ");
  imprimir(vetor, max);
  selection_sort (vetor, max);
  
}
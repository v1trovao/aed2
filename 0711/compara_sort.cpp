#include <stdio.h>
#define TAMANHO 5

void menu_app();
void bubble();
void insert();
void selection();
void imprimir(int vetor[]);

int vet[TAMANHO], vet_bubble[TAMANHO], vet_insert[TAMANHO], vet_selection[TAMANHO];
int cont_bubble=0, cont_insert=0, cont_selection=0;

void imprimir(int vetor[]){
	
	for (int i = 0; i < TAMANHO; i++)
		printf("%4d", vetor[i]);

	printf("\n");
}

void bubble()
{	
	int copia;

	for (int i = 0; i < TAMANHO-1; i++)
	{
		for (int j = 0; j < TAMANHO - i - 1; j++) 
		{
			if (vet_bubble[j] > vet_bubble[j + 1])
			{	
				copia = vet_bubble[j];
				vet_bubble[j] = vet_bubble[j + 1];
				vet_bubble[j + 1] = copia;
				cont_bubble++;
			}
            imprimir(vet_bubble);
		}	
	}
}

void insert()
{	
	int copia, indice;

	for(int i = 1; i < TAMANHO; i++)
	{
      copia = vet_insert[i];
      indice = i;

      while(indice > 0 && vet_insert[indice - 1] > copia)
	  {
		vet_insert[indice] = vet_insert[indice - 1];
        cont_insert++;
		indice--;
      }
      vet_insert[indice] = copia;
      imprimir(vet_insert);
    }
}

void selection(){
    int i, j, min, aux;
  
    for (i = 0; i < (TAMANHO - 1); i++) {
    
        /* O minimo é o primeiro numero nao ordenado ainda */
        min = i;
        for (j = i+1; j < TAMANHO; j++) 
        {
            /* Caso tenha algum numero menor ele faz a troca do minimo*/
            if (vet_selection[j] < vet_selection[min])
                min = j;
        }
        /* Se o minimo for diferente do primeiro numero nao ordenado ele faz a troca para ordena-los*/
        if (i != min) 
        {
            aux = vet_selection[i];
            vet_selection[i] = vet_selection[min];
            vet_selection[min] = aux;
            cont_selection++;
        }
        imprimir(vet_selection);
    }
}
int main()
{	
	//entrada de dados
	printf("Entre com os valores: \n");
	for (int i = 0; i < TAMANHO; i++){
		printf("%do ", i+1);
		scanf("%d", &vet[i]);
	}
	for (int i = 0; i < TAMANHO; i++){
		vet_bubble[i] = vet[i];
		vet_insert[i] = vet[i];
        vet_selection[i] = vet[i];
	}
	//imprimir o vetor 
	printf("Vetor lido: ");
    imprimir(vet);
	
	//insert sort
	printf(" -- INSERT -- \n ");
	insert();
	imprimir(vet_insert);
	printf("\n Qtd. de trocas: %d \n", cont_insert);
	printf("\n");

	//bubble sort
	printf(" -- BUBBLE -- \n");
	bubble();
	imprimir(vet_bubble);
	printf("\n Qtd. de trocas: %d \n", cont_bubble);
	printf("\n");

    //selection sort
    printf(" -- SELECTION -- \n");
    selection();
    imprimir(vet_selection);
    printf("\n Qtd. de trocas: %d \n", cont_selection);
    printf("\n");

    return 0;
}

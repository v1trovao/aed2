#include "labirinto.h"
#include <stdio.h>

int main() {
  char labirinto[SIZE][SIZE];

  // Ler o labirinto do arquivo
  if (!ler_labirinto("labirinto.txt", labirinto)) {
    return 1;
  }

  int entrada_x = -1;
  int entrada_y = -1;

  // Encontrar a posição da entrada
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (labirinto[i][j] == '0') {
        entrada_x = i;
        entrada_y = j;
        break; // Parar quando encontrar o primeiro zero
      }
    }
    if (entrada_x != -1 && entrada_y != -1) {
      break; // Parar quando encontrar o primeiro zero
    }
  }

  if (entrada_x == -1 || entrada_y == -1) {
    printf("Labirinto nao possui entrada valida.\n");
    return 1;
  }

  // Imprimir labirinto inicial
  printf("Labirinto inicial:\n");
  imprimir_labirinto(labirinto, entrada_x, entrada_y);

  // Tentar encontrar o caminho
  if (encontrar_caminho(labirinto, entrada_x, entrada_y)) {
    printf("\nLabirinto solucionado:\n");
    imprimir_labirinto(labirinto, entrada_x, entrada_y);
  } else {
    printf("\nLabirinto nao possui solucao.\n");
    imprimir_labirinto(labirinto, entrada_x, entrada_y);
  }

  return 0;
}

#include <stdio.h>
#include "maze.c"

int main() {
    char maze[LINHAS][COLUNAS];
    FILE *arquivo;

    /* Leitura do Arquivo */
    arquivo = fopen("../labirinto.txt", "r");

    if (arquivo == NULL) {
        printf("Erro, se liga, retorna 1 aí");
        return 1;
    }

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            fscanf(arquivo, " %c", &maze[i][j]);
        }
    }

    // Imprimindo o labirinto lido

    printf("Lab: ");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    fclose(arquivo);

    resolve_maze(maze, LINHAS, COLUNAS);
}
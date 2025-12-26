#include <stdio.h>
#define LINHAS 4
#define COLUNAS 4

void add_edge(int matriz[LINHAS][COLUNAS], int a, int b) {
    matriz[a][b] = 1;
    matriz[b][a] = 1;
}

void imprimir_matriz(int matriz[LINHAS][COLUNAS], int num_linhas, int num_colunas)
{
    for (int i = 0; i < num_linhas; i++)
    {
        for (int j = 0; j < num_colunas; j++) 
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

int resolve_maze(char maze[LINHAS][COLUNAS], int num_linhas, int num_colunas)
{
    int matriz_maze[num_linhas][num_colunas];
    int i, j;

    for (i = 0; i < num_linhas; i++)
    {
        for (j = 0; j < num_colunas; j++) 
            matriz_maze[i][j] = 0;
    }

    printf("Matriz de adj: \n");
    imprimir_matriz(matriz_maze, num_linhas, num_colunas);
    
    // Percorre o labirinto e cria arestas
    for (i = 0; i < num_linhas; i++) {
        for (j = 0; j < num_colunas; j++) {
            // Verifica se o vértice é um caminho ('0')
            if (maze[i][j] == '0') {
                int id = i * num_colunas + j;

                // Verifica os vértices adjacentes, marcando os caminhos válidos
                if ( i > 0 && maze[i - 1][j] == '0' )
                    add_edge(matriz_maze, id, (i - 1) * num_colunas + j); // Vértice acima
                if ( i < num_linhas - 1 && maze[i + 1][j] == '0' )
                    add_edge(matriz_maze, id, (i+1) * num_colunas + j); // Vértice abaixo
                if (j > 0 && maze[i][j - 1] == '0')
                    add_edge(matriz_maze, id, i * num_colunas + (j-1)); // Vértice à esquerda
                if (j < num_colunas - 1 && maze[i][j + 1] == '0')
                    add_edge(matriz_maze, id, i * num_colunas + (i+1)); // Vértice à direita
            }
        }
    } 

    printf("matriz de adj: \n");
    imprimir_matriz(matriz_maze, num_linhas, num_colunas);

    return 0;
}
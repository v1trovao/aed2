#ifndef LABIRINTO_H
#define LABIRINTO_H

#define SIZE 10

void imprimir_labirinto(char labirinto[SIZE][SIZE], int entrada_x,
                        int entrada_y);
int encontrar_caminho(char labirinto[SIZE][SIZE], int x, int y);
int ler_labirinto(const char *arquivo, char labirinto[SIZE][SIZE]);

#endif

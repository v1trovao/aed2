#include <stdio.h>
#include <stdlib.h>
#define TAM 8

void imprimeTabuleiro( int rainhas[] ) {
    int i, j;

    printf("Tabuleiro: \n");

    for( i = 0; i < TAM; i++ ) {
        for( j = 0; j < TAM; j++ ) {
            if ( j == rainhas[ i ] )
                printf( "%3c", 'R' );
            else 
                printf( "%3c", '*' );
        }
        printf( "\n" );
    }
    printf("\n");
}

int verificaCaptura( int rainhas[], int n ) {

    // x1, y1 = posicao da rainha inicial
    // x2, y2 = posicao da nova rainha
    // x3, y3 = possíveis movimentos da rainha inicial
    int y1, y2, x1, x2, x3, y3;

    for( y1 = 0; y1 <= n; y1++ ) {
        for( y2 = y1+1; y2 <= n; y2++ ) {

            // Verifica se as rainhas estão na mesma coluna
            if ( y1 == y2 )
                continue;

            x1 = rainhas[ y1 ];
            x2 = rainhas[ y2 ];

            // Verifica se as rainhas estão na mesma linha
            if ( x1 == x2 )
                return 1;


            // Verifica se a rainha está na diagonal superior esquerda
            x3 = x1-1;
            y3 = y1-1;

            while( x3 >= 0 && y3 >= 0 ) {
                if ( x3 == x2 && y3 == y2 )
                    return 1;
                x3--;
                y3--;
            }

            // Verifica se a rainha está na diagonal inferior esquerda
            x3 = x1-1;
            y3 = y1+1;

            while( x3 >= 0 && y1 < TAM ) {
                if ( x3 == x2 && y3 == y2 )
                    return 1;
                x3--;
                y3++;
            }

            // Verifica se a rainha está na diagonal superior direita
            x3 = x1+1;
            y3 = y1-1;

            while( x3 < TAM && y3 >= 0 ) {
                if ( x3 == x2 && y3 == y2 )
                    return 1;

                x3++;
                y3--;
            }

            // Verifica se a rainha está na diagonal inferior direita 
            x3 = x1+1;
            y3 = y1+1;
            
            while( x3 < TAM && y3 < TAM ) {
                if ( x3 == x2 && y3 == y2 )
                    return 1;

                x3++;
                y3++;
            }
        }
    }
    // Passou nos testes
    return 0;
}

int backtracking(int rainhas[], int i ) {
    int ok = 0;
    int j = 0;

    if ( i > TAM-1 )
        return 1;

    for( j = 0; ok == 0 && j < TAM; j++ ) {
        rainhas[ i ] = j;

        imprimeTabuleiro(rainhas);

        if ( verificaCaptura( rainhas, i ) == 0 )
            ok = backtracking( rainhas, i+1 );
    }

    return ok;
}

int main()
{
    int rainhas[ TAM ];

    for (int i = 0; i < TAM; i++)
        rainhas[i] = -1;

    backtracking( rainhas, 0 );
    imprimeTabuleiro( rainhas );

    return 0;
}
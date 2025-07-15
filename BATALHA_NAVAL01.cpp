  #include <stdio.h>
#include <stdlib.h>

// Função para imprimir uma matriz genérica
void imprimirMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

 // ========================
    // Nível Novato
    // ========================
    printf("Nível Novato - Tabuleiro 5x5 com dois navios\n");

    int novato[5][5] = {0};

    // Navio 1 - vertical na coluna 1 (linha 0 a 2)
    for (int i = 0; i < 3; i++) {
        novato[i][1] = 3;
        printf("Navio vertical em (%d,1)\n", i);
    }

    // Navio 2 - horizontal na linha 4 (coluna 0 a 3)
    for (int j = 0; j < 4; j++) {
        novato[4][j] = 3;
        printf("Navio horizontal em (4,%d)\n", j);
    }

    printf("\nTabuleiro Novato:\n");
    imprimirMatriz(5, 5, novato);


    // ========================
    // Nível Aventureiro
    // ========================
    printf("\nNível Aventureiro - Tabuleiro 10x10 com 4 navios\n");

    int aventureiro[10][10] = {0};

    // Navio 1 - horizontal na linha 2 (coluna 1 a 4)
    for (int j = 1; j <= 4; j++) {
        aventureiro[2][j] = 3;
    }

    // Navio 2 - vertical na coluna 6 (linha 5 a 8)
    for (int i = 5; i <= 8; i++) {
        aventureiro[i][6] = 3;
    }

    // Navio 3 - diagonal principal (linha == coluna)
    for (int i = 0; i < 4; i++) {
        aventureiro[i][i] = 3;
    }

    // Navio 4 - diagonal secundária (linha + coluna == 9)
    for (int i = 0; i < 4; i++) {
        aventureiro[i][9 - i] = 3;
    }

    printf("\nTabuleiro Aventureiro:\n");
    imprimirMatriz(10, 10, aventureiro);


    // ========================
    // Nível Mestre
    // ========================
    printf("\nNível Mestre - Habilidades Especiais\n");

    // Habilidade: Cone
    int cone[3][5] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 2 - i; j <= 2 + i; j++) {
            cone[i][j] = 1;
        }
    }
    printf("\nCone:\n");
    imprimirMatriz(3, 5, cone);

    // Habilidade: Cruz
    int cruz[3][5] = {0};
    for (int i = 0; i < 3; i++) cruz[i][2] = 1;
    for (int j = 0; j < 5; j++) cruz[1][j] = 1;
    printf("\nCruz:\n");
    imprimirMatriz(3, 5, cruz);

    // Habilidade: Octaedro
    int octaedro[3][5] = {0};
    int cx = 1, cy = 2; // centro da forma
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - cx) + abs(j - cy) <= 1) {
                octaedro[i][j] = 1;
            }
        }
    }
    printf("\nOctaedro:\n");
    imprimirMatriz(3, 5, octaedro);

    return 0;
}

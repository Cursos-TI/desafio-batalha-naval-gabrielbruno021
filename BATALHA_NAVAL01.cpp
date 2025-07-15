#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Tamanho do tabuleiro e quantidade de navios
#define TAM 5
#define NAVIOS 3

// Função que inicializa o tabuleiro com um símbolo (ex: '~')
void inicializarTabuleiro(char tabuleiro[TAM][TAM], char simbolo) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = simbolo;
        }
    }
}

// Função que exibe o tabuleiro na tela
// Se ocultarNavios for 1, os navios 'N' não serão mostrados
void exibirTabuleiro(char tabuleiro[TAM][TAM], int ocultarNavios) {
    printf("  0 1 2 3 4\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM; j++) {
            if (ocultarNavios && tabuleiro[i][j] == 'N') {
                printf("~ ");
            } else {
                printf("%c ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
}

// Função que posiciona os navios aleatoriamente no tabuleiro
void posicionarNavios(char tabuleiro[TAM][TAM]) {
    int colocados = 0;
    while (colocados < NAVIOS) {
        int x = rand() % TAM;
        int y = rand() % TAM;
        if (tabuleiro[x][y] != 'N') {
            tabuleiro[x][y] = 'N';
            colocados++;
        }
    }
}

// Função que processa um tiro no tabuleiro
int atirar(int x, int y, char tabuleiro[TAM][TAM]) {
    if (tabuleiro[x][y] == 'N') {
        tabuleiro[x][y] = 'X'; // Acerto
        return 1;
    } else if (tabuleiro[x][y] == '~') {
        tabuleiro[x][y] = 'O'; // Erro
    }
    return 0;
}

int main() {
    char tabuleiroJogador[TAM][TAM];
    char tabuleiroComputador[TAM][TAM];
    int x, y;
    int acertosJogador = 0, acertosComputador = 0;

    // Semente para gerar números aleatórios
    srand(time(NULL));

    // Inicializa os tabuleiros
    inicializarTabuleiro(tabuleiroJogador, '~');
    inicializarTabuleiro(tabuleiroComputador, '~');

    // Posiciona os navios nos tabuleiros
    printf("Posicionando navios...\n");
    posicionarNavios(tabuleiroJogador);
    posicionarNavios(tabuleiroComputador);

    // Loop principal do jogo
    while (acertosJogador < NAVIOS && acertosComputador < NAVIOS) {
        // Exibe os tabuleiros
        printf("\n--- Seu tabuleiro ---\n");
        exibirTabuleiro(tabuleiroJogador, 0);
        printf("\n--- Tabuleiro do computador ---\n");
        exibirTabuleiro(tabuleiroComputador, 1);

        // Jogador atira
        printf("\nSua vez! Digite as coordenadas (linha e coluna): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= TAM || y < 0 || y >= TAM) {
            printf("Coordenadas inválidas. Tente novamente.\n");
            continue;
        }

        if (tabuleiroComputador[x][y] == 'X' || tabuleiroComputador[x][y] == 'O') {
            printf("Você já atirou aqui. Escolha outra posição.\n");
            continue;
        }

        if (atirar(x, y, tabuleiroComputador)) {
            printf("?? Você acertou um navio!\n");
            acertosJogador++;
        } else {
            printf("?? Você errou o tiro.\n");
        }

        // Verifica se o jogador venceu
        if (acertosJogador == NAVIOS) break;

        // Vez do computador
        printf("\nAgora é a vez do computador...\n");
        do {
            x = rand() % TAM;
            y = rand() % TAM;
        } while (tabuleiroJogador[x][y] == 'X' || tabuleiroJogador[x][y] == 'O');

        if (atirar(x, y, tabuleiroJogador)) {
            printf("?? O computador acertou na posição (%d, %d)!\n", x, y);
            acertosComputador++;
        } else {
            printf("?? O computador errou na posição (%d, %d).\n", x, y);
        }
    }

    // Fim do jogo
    printf("\n--- Fim de Jogo ---\n");
    if (acertosJogador == NAVIOS) {
        printf("?? Parabéns! Você venceu!\n");
    } else {
        printf("?? O computador venceu! Tente novamente.\n");
    }

    // Exibe o tabuleiro final do computador (sem esconder navios)
    printf("\nTabuleiro final do computador:\n");
    exibirTabuleiro(tabuleiroComputador, 0);

    return 0;
}

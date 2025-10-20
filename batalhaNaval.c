#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // Coordenadas iniciais dos navios
    int linha_horizontal = 2;   // linha 3 (índice começa em 0)
    int coluna_horizontal = 4;  // coluna E

    int linha_vertical = 5;     // linha 6
    int coluna_vertical = 7;    // coluna H

    // Validação de limites
    if (coluna_horizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        linha_vertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: navio fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Validação de sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] == NAVIO ||
            tabuleiro[linha_vertical + i][coluna_vertical] == NAVIO) {
            printf("Erro: navios sobrepostos.\n");
            return 1;
        }
    }

    // Posiciona navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
    }

    // Posiciona navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
    }

    // Exibe cabeçalho do tabuleiro
    printf("TABULEIRO BATALHA NAVAL\n");
    printf("  A B C D E F G H I J\n");

    // Exibe linhas numeradas com conteúdo
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        printf("%2d ", linha + 1); // numeração de 1 a 10
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
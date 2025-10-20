#include <stdio.h>
#include <stdlib.h>

#define N 10
#define H 5

void inicializarTabuleiro(int tab[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tab[i][j] = 0;

    // Navios (mesmo padrão da imagem)
    tab[1][3] = 3;
    tab[2][1] = 3; tab[2][2] = 3; tab[2][3] = 3; tab[2][4] = 3; tab[2][5] = 3;
    tab[3][2] = 3;
    tab[4][2] = 3;
}

void imprimirTabuleiro(int tab[N][N]) {
    printf("  ");
    for (int j = 0; j < N; j++) printf("%d ", j);
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", i);
        for (int j = 0; j < N; j++) printf("%d ", tab[i][j]);
        printf("\n");
    }
}

void criarCone(int cone[H][H]) {
    int meio = 0; // topo no canto esquerdo da matriz
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (j <= i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

void criarCruz(int cruz[H][H]) {
    int meio = H / 2;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < H; j++)
            cruz[i][j] = (i == meio || j == meio) ? 1 : 0;
}

void aplicarHabilidade(int tab[N][N], int hab[H][H], int origemLinha, int origemColuna, int valor) {
    int meio = H / 2;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            int linha = origemLinha - meio + i;
            int coluna = origemColuna - meio + j;

            if (linha >= 0 && linha < N && coluna >= 0 && coluna < N) {
                if (hab[i][j] == 1 && tab[linha][coluna] == 0)
                    tab[linha][coluna] = valor;
            }
        }
    }
}

int main() {
    int tabuleiro[N][N];
    int cone[H][H], cruz[H][H];

    inicializarTabuleiro(tabuleiro);
    criarCone(cone);
    criarCruz(cruz);

    // Posição da imagem:
    // Cone no canto inferior esquerdo
    aplicarHabilidade(tabuleiro, cone, 7, 1, 1);
    // Cruz no canto direito
    aplicarHabilidade(tabuleiro, cruz, 5, 7, 2);

    imprimirTabuleiro(tabuleiro);
    return 0;
}

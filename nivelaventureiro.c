#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para verificar se o navio está dentro dos limites do tabuleiro
bool dentroDosLimites(int linha, int coluna, int direcao_linha, int direcao_coluna) {
    int linha_final = linha + (TAMANHO_NAVIO - 1) * direcao_linha;
    int coluna_final = coluna + (TAMANHO_NAVIO - 1) * direcao_coluna;

    return linha_final >= 0 && linha_final < TAMANHO_TABULEIRO &&
           coluna_final >= 0 && coluna_final < TAMANHO_TABULEIRO;
}

// Função para verificar se há sobreposição de navios
bool haSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                    int linha, int coluna, int direcao_linha, int direcao_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * direcao_linha;
        int c = coluna + i * direcao_coluna;
        if (tabuleiro[l][c] == NAVIO) {
            return true;
        }
    }
    return false;
}

// Função para posicionar navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                     int linha, int coluna, int direcao_linha, int direcao_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * direcao_linha;
        int c = coluna + i * direcao_coluna;
        tabuleiro[l][c] = NAVIO;
    }
}

int main() {
    // Declaração e inicialização do tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // Estrutura para representar um navio com posição inicial e direção
    struct Navio {
        int linha;
        int coluna;
        int direcao_linha;
        int direcao_coluna;
    };

    // Definição dos 4 navios com posições seguras (sem sobreposição e dentro dos limites)
    struct Navio navios[4] = {
        {0, 0, 0, 1},  // horizontal (linha 1, colunas A–C)
        {3, 2, 1, 0},  // vertical (coluna C, linhas 4–6)
        {6, 0, 1, 1},  // diagonal ↘ (linhas 7–9, colunas A–C)
        {0, 9, 1, -1}  // diagonal ↙ (linhas 1–3, colunas J–H)
    };

    // Posicionamento dos navios com validação
    for (int i = 0; i < 4; i++) {
        int l = navios[i].linha;
        int c = navios[i].coluna;
        int dl = navios[i].direcao_linha;
        int dc = navios[i].direcao_coluna;

        if (!dentroDosLimites(l, c, dl, dc)) {
            printf("Erro: navio %d fora dos limites do tabuleiro.\n", i + 1);
            return 1;
        }

        if (haSobreposicao(tabuleiro, l, c, dl, dc)) {
            printf("Erro: navio %d sobreposto a outro navio.\n", i + 1);
            return 1;
        }

        posicionarNavio(tabuleiro, l, c, dl, dc);
    }

    // Exibição do tabuleiro com cabeçalho
    printf("TABULEIRO BATALHA NAVAL\n");
    printf("   A B C D E F G H I J\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        printf("%2d ", linha + 1);
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
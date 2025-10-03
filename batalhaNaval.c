#include <stdio.h>

#define TAM 10   // tamanho do tabuleiro 10x10
#define NAVIO 3  // valor para representar navio
#define AGUA 0   // valor para representar água

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializando tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // -------------------------
    // Definição dos navios
    // -------------------------
    int navioH[3] = {NAVIO, NAVIO, NAVIO}; // navio horizontal (3 posições)
    int navioV[3] = {NAVIO, NAVIO, NAVIO}; // navio vertical (3 posições)

    // Coordenadas iniciais escolhidas (linha, coluna)
    int linhaH = 2, colunaH = 4; // início do navio horizontal
    int linhaV = 5, colunaV = 7; // início do navio vertical

    // -------------------------
    // Validação do navio horizontal
    // -------------------------
    if (colunaH + 3 <= TAM) {
        int sobreposicao = 0;
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaH][colunaH + i] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linhaH][colunaH + i] = navioH[i];
            }
        } else {
            printf("Erro: Navio horizontal sobreposto!\n");
        }
    } else {
        printf("Erro: Navio horizontal fora do limite!\n");
    }

    // -------------------------
    // Validação do navio vertical
    // -------------------------
    if (linhaV + 3 <= TAM) {
        int sobreposicao = 0;
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaV + i][colunaV] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linhaV + i][colunaV] = navioV[i];
            }
        } else {
            printf("Erro: Navio vertical sobreposto!\n");
        }
    } else {
        printf("Erro: Navio vertical fora do limite!\n");
    }

    // -------------------------
    // Exibir tabuleiro
    // -------------------------
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}


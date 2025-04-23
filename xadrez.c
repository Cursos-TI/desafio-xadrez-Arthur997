#include <stdio.h>

#define CASAS_TORRE 5
#define CASAS_BISPO 5
#define CASAS_RAINHA 8
#define MOVIMENTOS_CAVALO 3

// Torre - movimentação recursiva para a direita
void moverTorre(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

// Bispo - recursivo + loops aninhados
void moverBispoRecursivo(int linha, int coluna, int max) {
    if (linha >= max || coluna >= max) return;
    printf("Cima Direita\n");
    moverBispoRecursivo(linha + 1, coluna + 1, max);
}

void moverBispoComLoops(int max) {
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            if (i == j) {
                printf("Cima Direita\n");
            }
        }
    }
}

// Rainha - recursiva para a esquerda
void moverRainha(int casas) {
    if (casas == 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// Cavalo - movimentos complexos: duas para cima, uma para direita
void moverCavalo() {
    int i, j;
    for (i = 0; i < MOVIMENTOS_CAVALO; i++) {
        j = 0;
        while (j < MOVIMENTOS_CAVALO) {
            if ((i + 2 <= MOVIMENTOS_CAVALO) && (j + 1 <= MOVIMENTOS_CAVALO)) {
                printf("Cima\n");
                printf("Cima\n");
                printf("Direita\n");
                break;
            }
            j++;
        }
    }
}

int main() {
    printf("Movimento da Torre:\n");
    moverTorre(CASAS_TORRE);

    printf("\nMovimento do Bispo (Recursivo):\n");
    moverBispoRecursivo(0, 0, CASAS_BISPO);

    printf("\nMovimento do Bispo (Loops):\n");
    moverBispoComLoops(CASAS_BISPO);

    printf("\nMovimento da Rainha:\n");
    moverRainha(CASAS_RAINHA);

    printf("\nMovimento do Cavalo:\n");
    moverCavalo();

    return 0;
}

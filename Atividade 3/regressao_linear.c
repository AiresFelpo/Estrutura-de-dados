#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    float y;
} Ponto;

void calcularRegressaoLinear(Ponto *pontos, int quantidade) {
    int somaX = 0;
    float somaY = 0;
    float somaXY = 0;
    int somaXQuadrado = 0;

    for (int i = 0; i < quantidade; i++) {
        somaX += pontos[i].x;
        somaY += pontos[i].y;
        somaXY += pontos[i].x * pontos[i].y;
        somaXQuadrado += pontos[i].x * pontos[i].x;
    }

    float mediaX = (float)somaX / quantidade;
    float mediaY = somaY / quantidade;

    float inclinacao = (somaXY - quantidade * mediaX * mediaY) / (somaXQuadrado - quantidade * mediaX * mediaX);

    float intercepto = mediaY - inclinacao * mediaX;

    printf("y = %.2fx + %.2f\n", inclinacao, intercepto);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo.csv>\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    int quantidadeRegistros = 0;
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        quantidadeRegistros++;
    }

    Ponto *pontos = (Ponto *)malloc(quantidadeRegistros * sizeof(Ponto));

    fseek(arquivo, 0, SEEK_SET);

    for (int i = 0; i < quantidadeRegistros; i++) {
        fscanf(arquivo, "%d,%f", &(pontos[i].x), &(pontos[i].y));
    }

    calcularRegressaoLinear(pontos, quantidadeRegistros);

    fclose(arquivo);
    free(pontos);

    return 0;
}

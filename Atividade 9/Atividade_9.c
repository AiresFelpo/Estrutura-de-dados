#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No {
    float valor;
    struct No* prox;
} No;

void lista_inserir_no_ordenado(No* L, No* no) {
    // Implemente a lógica para inserir o nó na lista de forma ordenada
}

void lista_inserir_no_final(No* L, No* no) {
    while (L->prox != NULL) {
        L = L->prox;
    }
    L->prox = no;
    no->prox = NULL;
}

int main() {
    FILE *file;
    char filename[] = "1kk_rand_float.csv";
    No *lista_nao_ordenada = NULL;
    No *lista_ordenada = NULL;

    // Abre o arquivo
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    // Lê o arquivo e insere valores nas listas
    float valor;
    while (fscanf(file, "%f\n", &valor) == 1) {
        // Cria dois nós com o valor lido
        No *n1 = (No*)malloc(sizeof(No));
        n1->valor = valor;
        n1->prox = NULL;

        No *n2 = (No*)malloc(sizeof(No));
        n2->valor = valor;
        n2->prox = NULL;

        // Insere n1 na lista não ordenada
        if (lista_nao_ordenada == NULL) {
            lista_nao_ordenada = n1;
        } else {
            lista_inserir_no_final(lista_nao_ordenada, n1);
        }

        // Insere n2 na lista ordenada
        if (lista_ordenada == NULL) {
            lista_ordenada = n2;
        } else {
            lista_inserir_no_ordenado(lista_ordenada, n2);
        }
    }

    // Fecha o arquivo
    fclose(file);

    // Calcule o tempo médio de inserção em cada lista
    // Use clock() ou time.h para medir o tempo

    // Comparação de tempos e resultados

    return 0;
}

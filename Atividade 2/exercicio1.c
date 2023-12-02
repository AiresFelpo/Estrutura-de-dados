#include <stdio.h>

int soma_array(int array[], int tamanho) {
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }

    return soma;
}

int main() {
    int numeros[] = {5, 7, 9, 6};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    int resultado = soma_array(numeros, tamanho);

    printf("Saída: %d\n", resultado);

    return 0;
}

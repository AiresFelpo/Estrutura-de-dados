#include <stdio.h>
#include <stdlib.h>

// Função para verificar se um número é primo
int ehPrimo(int num) {
    if (num <= 1) {
        return 0; // Números menores ou iguais a 1 não são primos
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Se for divisível por algum número entre 2 e a raiz quadrada, não é primo
        }
    }

    return 1; // Se não foi divisível por nenhum número, é primo
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }

    int numero = atoi(argv[1]); // Converte o argumento para inteiro

    if (ehPrimo(numero)) {
        printf("1 - O número %d é primo.\n", numero);
    } else {
        printf("0 - O número %d não é primo.\n", numero);
    }

    return 0;
}

#include <stdio.h>
#include "lista.h"

int main() {
    No* lista = lista_criar();
    
    lista_inserir(lista, 'A');
    lista_inserir(lista, 'B');
    lista_inserir(lista, 'C');
    lista_inserir(lista, 'B');
    
    lista_imprimir(lista);
    printf("\n");

    printf("Verificar existência de 'C': %d\n", lista_verificar_existencia(lista, 'C'));
    printf("Quantidade de ocorrencias de 'B': %d\n", lista_verificar_ocorrencias(lista, 'B'));
    
    printf("Imprimir lista inversa: ");
    lista_imprimir_inversa(lista->prox); // Note que passamos lista->prox para evitar a impressão do nó cabeça
    printf("\n");

    lista_inserir_no_i(lista, 2, 'D');
    printf("Lista após inserção na posição 2: ");
    lista_imprimir(lista);
    printf("\n");

    lista_remover_no_i(lista, 1);
    printf("Lista após remoção da posição 1: ");
    lista_imprimir(lista);
    printf("\n");

    lista_remover_no(lista, 'B');
    printf("Lista após remoção de 'B': ");
    lista_imprimir(lista);
    printf("\n");

    lista_destruir(lista);
    
    return 0;
}

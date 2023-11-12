#include <stdio.h>
#include "tabela_hash.h"

int main() {
    // Adicionando valores à tabela hash
    hash_table_put("chave1", "dados1");
    hash_table_put("chave2", "dados2");

    // Verificando se uma chave está na tabela
    printf("A chave 'chave1' está na tabela? %s\n", hash_table_contains("chave1") ? "Sim" : "Não");
    printf("A chave 'chave3' está na tabela? %s\n", hash_table_contains("chave3") ? "Sim" : "Não");

    // Obtendo valores da tabela
    printf("Valor para 'chave1': %s\n", hash_table_get("chave1"));
    printf("Valor para 'chave2': %s\n", hash_table_get("chave2"));

    // Removendo um valor da tabela
    hash_table_remove("chave1");
    printf("A chave 'chave1' está na tabela depois de removê-la? %s\n", hash_table_contains("chave1") ? "Sim" : "Não");

    return 0;
}

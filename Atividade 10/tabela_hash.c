#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

static char* hash_table[TABLE_SIZE];

int hash(char* chave) {
    // Função de hash simples para este exemplo
    int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash += chave[i];
    }
    return hash % TABLE_SIZE;
}

void hash_table_put(char* chave, char* dado) {
    int index = hash(chave);
    hash_table[index] = dado;
}

char* hash_table_get(char* chave) {
    int index = hash(chave);
    return hash_table[index];
}

int hash_table_contains(char* chave) {
    int index = hash(chave);
    return (hash_table[index] != NULL);
}

void hash_table_remove(char* chave) {
    int index = hash(chave);
    hash_table[index] = NULL;
}

#include "territory.h"
#include <stdio.h>
#include <string.h>

// Inicializa um território com os dados fornecidos
void inicializarTerritorio(Territorio *t, const char *nome, const char *cor, int tropas) {
    strncpy(t->nome, nome, sizeof(t->nome) - 1);
    t->nome[sizeof(t->nome) - 1] = '\0';
    strncpy(t->cor, cor, sizeof(t->cor) - 1);
    t->cor[sizeof(t->cor) - 1] = '\0';
    t->tropas = tropas;
}

// Imprime os dados de um território
void imprimirTerritorio(const Territorio *t) {
    printf("Território: %s, Cor: %s, Tropas: %d\n", t->nome, t->cor, t->tropas);
}

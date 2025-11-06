#ifndef TERRITORY_H
#define TERRITORY_H

// Estrutura para representar um Território
typedef struct {
    char nome[50];
    char cor[20];
    int tropas;
} Territorio;

// Protótipos das funções
void inicializarTerritorio(Territorio *t, const char *nome, const char *cor, int tropas);
void imprimirTerritorio(const Territorio *t);
int atacarTerritorio(Territorio *atacante, Territorio *defensor);

#endif // TERRITORY_H

#ifndef WAR_H
#define WAR_H

#include "territory.h"

// Estrutura para representar uma Missão
typedef struct {
    char descricao[100];
    int tipo; // 1: Conquistar X territórios, 2: Conquistar Y continentes, etc.
    char cor_alvo[20]; // Para missões de eliminar um jogador
} Missao;

// Protótipos das funções
int rolarDado();
void simularBatalha(Territorio *atacante, Territorio *defensor);
int verificarVitoria(const Territorio mapa[], int num_territorios, const Missao *missao);

#endif // WAR_H

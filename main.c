#include <stdio.h>
#include "territory.h"
#include "war.h"
#include <stdlib.h>
#include <string.h>

#define MAX_TERRITORIES 10

int main() {
    Territorio mapa[MAX_TERRITORIES];
    int num_territorios = 0;

    printf("--- Sistema de Cadastro de Territórios War ---\n\n");

    // Cadastrando alguns territórios de exemplo da Ásia e América do Sul
    printf("Cadastrando territórios iniciais...\n");
    inicializarTerritorio(&mapa[num_territorios++], "Brasil", "Verde", 5);
    inicializarTerritorio(&mapa[num_territorios++], "Argentina", "Azul", 3);
    inicializarTerritorio(&mapa[num_territorios++], "Peru", "Verde", 2);
    inicializarTerritorio(&mapa[num_territorios++], "China", "Vermelho", 8);
    inicializarTerritorio(&mapa[num_territorios++], "Japão", "Branco", 4);
    inicializarTerritorio(&mapa[num_territorios++], "Índia", "Vermelho", 6);

    printf("\n--- Territórios Cadastrados ---\n");
    for (int i = 0; i < num_territorios; i++) {
        imprimirTerritorio(&mapa[i]);
    }
    printf("\n");

    printf("--- Simulação de Ataque ---\n");
// Simulação de ataque: Brasil (índice 0) ataca Argentina (índice 1)
simularBatalha(&mapa[0], &mapa[1]);

printf("\n--- Situação Após o Ataque ---\n");
for (int i = 0; i < num_territorios; i++) {
    imprimirTerritorio(&mapa[i]);
}

// --- Implementação da Missão e Verificação de Vitória (Alocação Dinâmica) ---

// Alocação dinâmica para a Missão
Missao *missao_atual = (Missao *)malloc(sizeof(Missao));
if (missao_atual == NULL) {
    printf("Erro de alocação de memória para a missão.\n");
    return 1;
}

// Inicialização da Missão
strncpy(missao_atual->descricao, "Conquistar 4 territórios.", sizeof(missao_atual->descricao) - 1);
missao_atual->descricao[sizeof(missao_atual->descricao) - 1] = '\0';
missao_atual->tipo = 1; // Tipo 1: Conquistar X territórios
strncpy(missao_atual->cor_alvo, "Verde", sizeof(missao_atual->cor_alvo) - 1);
missao_atual->cor_alvo[sizeof(missao_atual->cor_alvo) - 1] = '\0';

// Verificação da condição de vitória
if (verificarVitoria(mapa, num_territorios, missao_atual)) {
    printf("\n*** PARABÉNS! MISSÃO CUMPRIDA! ***\n");
} else {
    printf("\n*** MISSÃO PENDENTE. Continue a batalha! ***\n");
}

// Liberação da memória alocada dinamicamente
free(missao_atual);
missao_atual = NULL;

printf("\nO projeto está completo com as funcionalidades de cadastro, ataque e missões.\n");

    return 0;
}

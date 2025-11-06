#include "war.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Função para rolar um dado de 6 faces
int rolarDado() {
    return (rand() % 6) + 1;
}

// Simula uma batalha entre dois territórios
void simularBatalha(Territorio *atacante, Territorio *defensor) {
    printf("\n--- Início da Batalha ---\n");
    printf("%s (Tropas: %d) ataca %s (Tropas: %d)\n", atacante->nome, atacante->tropas, defensor->nome, defensor->tropas);

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Lógica simplificada de batalha: 1 dado para cada lado
    int dado_ataque = rolarDado();
    int dado_defesa = rolarDado();

    printf("Dado de Ataque: %d\n", dado_ataque);
    printf("Dado de Defesa: %d\n", dado_defesa);

    if (dado_ataque > dado_defesa) {
        printf("Vitória do Atacante! O defensor perdeu uma tropa.\n");
        defensor->tropas--;
        if (defensor->tropas == 0) {
            printf("%s foi conquistado por %s!\n", defensor->nome, atacante->nome);
            // Uso de ponteiros para simular a mudança de posse (alocação dinâmica não é estritamente necessária aqui, mas o ponteiro é usado)
            // O requisito de alocação dinâmica será melhor atendido na fase 4 com as missões.
            strncpy(defensor->cor, atacante->cor, sizeof(defensor->cor) - 1);
            defensor->cor[sizeof(defensor->cor) - 1] = '\0';
            defensor->tropas = 1; // Deixa 1 tropa no território conquistado
            atacante->tropas--; // O atacante perde uma tropa ao mover para o novo território
        }
    } else {
        printf("Vitória do Defensor! O atacante perdeu uma tropa.\n");
        atacante->tropas--;
    }

    printf("--- Fim da Batalha ---\n");
}

// Verifica se a condição de vitória da missão foi atingida
int verificarVitoria(const Territorio mapa[], int num_territorios, const Missao *missao) {
    printf("\n--- Verificando Condição de Vitória ---\n");
    printf("Missão: %s\n", missao->descricao);

    // Exemplo de lógica de vitória: Conquistar 4 territórios
    if (missao->tipo == 1) {
        int territorios_conquistados = 0;
        for (int i = 0; i < num_territorios; i++) {
            // Supondo que o jogador "Verde" é o jogador atual
            if (strcmp(mapa[i].cor, "Verde") == 0) {
                territorios_conquistados++;
            }
        }

        printf("Territórios controlados pelo jogador Verde: %d\n", territorios_conquistados);

        if (territorios_conquistados >= 4) {
            return 1; // Vitória
        }
    }
    
    // Outras lógicas de missão podem ser adicionadas aqui (tipo 2, 3, etc.)

    return 0; // Não venceu
}

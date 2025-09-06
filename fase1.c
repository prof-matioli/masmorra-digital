// Arquivo: fase1.c
// Missão: O Corredor das Armadilhas
// Objetivo: Aprender a declarar, percorrer e modificar vetores.

#include <stdio.h>

int main() {
    // Vetor que representa o corredor. 0 = seguro, 1 = armadilha.
    int corredor[10] = {0, 1, 1, 0, 0, 1, 0, 1, 0, 0};
    int i; // Variável contadora para os laços

    printf("--- FASE 1: O CORREDOR DAS ARMADILHAS ---\n\n");

    // --- Desafio 1.1: Mapeando o Perigo ---
    printf("Desafio 1.1: Verificando o caminho pela primeira vez...\n");

    for (i = 0; i < 10; i++) {
        // Acessa o elemento na posição 'i' do vetor
        if (corredor[i] == 0) {
            printf("Posicao [%d]: Passo SEGURO.\n", i);
        } else {
            printf("Posicao [%d]: ARMADILHA!\n", i);
        }
    }

    printf("\n------------------------------------------------\n\n");

    // --- Desafio 1.2: Desarmando o Caminho ---
    printf("Desafio 1.2: Desarmando todas as armadilhas...\n");

    for (i = 0; i < 10; i++) {
        // Se encontrarmos uma armadilha (valor 1), nós a desarmamos.
        if (corredor[i] == 1) {
            printf("Armadilha na posicao [%d] desarmada!\n", i);
            // Modificamos o valor naquela posição do vetor para 0.
            corredor[i] = 0;
        }
    }

    printf("\nVerificando o caminho novamente apos desarmar:\n");
    for (i = 0; i < 10; i++) {
        if (corredor[i] == 0) {
            printf("Posicao [%d]: Caminho agora esta seguro.\n", i);
        }
    }

    printf("\nParabens! Voce ganhou a conquista: 'Explorador de Corredores'!\n");

    return 0;
}
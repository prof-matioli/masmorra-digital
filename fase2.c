// Arquivo: fase2.c
// Missão: O Saco de Artefatos
// Objetivo: Aprender a preencher um vetor com dados do usuário e manipular essas informações.

#include <stdio.h>

int main() {
    // Vetor para 8 artefatos, inicializado com 0.
    int saco_de_artefatos[8] = {0};
    int i;
    int artefatos_para_coletar = 5;

    printf("--- FASE 2: O SACO DE ARTEFATOS ---\n\n");

    // --- Desafio 2.1: Coleta de Itens ---
    printf("Desafio 2.1: Voce encontrou %d artefatos! Digite o poder de cada um.\n", artefatos_para_coletar);

    for (i = 0; i < artefatos_para_coletar; i++) {
        printf("Poder do artefato %d: ", i + 1);
        scanf("%d", &saco_de_artefatos[i]);
    }

    printf("\nColeta finalizada! Artefatos no saco: ");
    for (i = 0; i < 8; i++) {
        printf("%d ", saco_de_artefatos[i]);
    }

    printf("\n\n------------------------------------------------\n\n");

    // --- Desafio 2.2: Avaliando o Tesouro ---
    printf("Desafio 2.2: Analisando os artefatos coletados...\n");

    int poder_total = 0;
    // Assume que o primeiro artefato é o mais poderoso inicialmente.
    int mais_poderoso = saco_de_artefatos[0];

    for (i = 0; i < 8; i++) {
        // 1. Soma o poder de cada artefato ao total.
        poder_total += saco_de_artefatos[i];

        // 2. Verifica se o artefato atual é mais poderoso que o maior já encontrado.
        if (saco_de_artefatos[i] > mais_poderoso) {
            mais_poderoso = saco_de_artefatos[i];
        }
    }

    printf("Poder total de todos os artefatos: %d\n", poder_total);
    printf("O artefato mais poderoso tem %d de poder.\n", mais_poderoso);

    // 3. Busca específica
    int valor_buscado;
    int contagem = 0;
    printf("\nDigite um poder para buscar no saco: ");
    scanf("%d", &valor_buscado);

    for (i = 0; i < 8; i++) {
        if (saco_de_artefatos[i] == valor_buscado) {
            contagem++;
        }
    }
    printf("Voce tem %d artefato(s) com poder %d.\n", contagem, valor_buscado);

    printf("\nParabens! Voce ganhou a conquista: 'Mestre dos Artefatos'!\n");

    return 0;
}
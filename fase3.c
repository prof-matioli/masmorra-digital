// Arquivo: fase3.c
// Missão: A Sala do Mapa
// Objetivo: Aprender a declarar, inicializar, imprimir e acessar elementos de uma matriz.

#include <stdio.h>

int main() {
    // Matriz 5x5 que representa a sala.
    // '#' = Parede, ' ' = Chão, 'C' = Chave
    char mapa[5][5] = {
        {'#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', 'C', '#'},
        {'#', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#'}
    };
    int linha, coluna;

    printf("--- FASE 3: A SALA DO MAPA ---\n\n");

    // --- Desafio 3.1: Desenhando o Mapa ---
    printf("Desafio 3.1: O mapa da sala foi revelado!\n\n");

    // Laço aninhado para percorrer a matriz
    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {
            // Imprime o caractere na posição [linha][coluna]
            printf("%c ", mapa[linha][coluna]);
        }
        // Pula para a próxima linha no console ao final de cada linha da matriz
        printf("\n");
    }

    printf("\n------------------------------------------------\n\n");

    // --- Desafio 3.2: Usando Coordenadas ---
    printf("Desafio 3.2: Investigue um ponto no mapa.\n");
    printf("Digite uma coordenada (linha e coluna, de 0 a 4).\n");

    printf("Linha: ");
    scanf("%d", &linha);
    printf("Coluna: ");
    scanf("%d", &coluna);

    // Validação para garantir que o usuário não digitou coordenadas fora do mapa
    if (linha >= 0 && linha < 5 && coluna >= 0 && coluna < 5) {
        char item_encontrado = mapa[linha][coluna];

        printf("\nInvestigando a posicao [%d][%d]...\n", linha, coluna);

        switch (item_encontrado) {
            case ' ':
                printf("Voce investigou o chao. Nada aqui.\n");
                break;
            case '#':
                printf("Voce bateu na parede.\n");
                break;
            case 'C':
                printf("PARABENS! Voce encontrou a chave!\n");
                break;
            default:
                printf("Ha algo estranho aqui...\n");
                break;
        }
    } else {
        printf("Coordenadas invalidas! A masmorra so vai de 0 a 4.\n");
    }

    printf("\nParabens! Voce ganhou a conquista: 'Cartografo Real'!\n");

    return 0;
}
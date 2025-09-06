// Arquivo: fase4.c
// Missão: A Fuga da Masmorra
// Objetivo: Usar uma matriz para criar um ambiente interativo com movimentação e lógica de jogo.

#include <stdio.h>
#include <stdlib.h> // Para a função system()

int main() {
    // Mapa com o Herói ('H') e a Saída ('S')
    char mapa[5][5] = {
        {'#', '#', '#', '#', '#'},
        {'#', 'H', ' ', ' ', '#'},
        {'#', ' ', '#', 'S', '#'},
        {'#', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#'}
    };

    // Posição inicial do herói
    int linhaHeroi = 1;
    int colunaHeroi = 1;
    char movimento;

    printf("--- FASE 4: A FUGA DA MASMORRA ---\n");
    printf("Use as teclas w(cima), s(baixo), a(esquerda), d(direita) e aperte Enter para se mover.\n");
    printf("Seu objetivo e chegar ate a Saida ('S').\n\n");

    // Game Loop - o jogo continua rodando até o jogador vencer.
    while (1) {
        // Desafio 4.1: Mostrar o mapa
        // system("cls"); // No Windows. Use "clear" no Linux/Mac.
        // system("clear");
        
        printf("--- MAPA ATUAL ---\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%c ", mapa[i][j]);
            }
            printf("\n");
        }

        // Desafio 4.2: Movimentação
        printf("\nSeu proximo movimento: ");
        // O espaço antes de %c ignora quebras de linha ou espaços anteriores.
        scanf(" %c", &movimento);

        int proximaLinha = linhaHeroi;
        int proximaColuna = colunaHeroi;

        // Calcula a próxima posição com base no comando
        switch (movimento) {
            case 'w': proximaLinha--; break;
            case 's': proximaLinha++; break;
            case 'a': proximaColuna--; break;
            case 'd': proximaColuna++; break;
            default:
                printf("Comando invalido!\n");
                continue; // Pula o resto do loop e começa de novo
        }

        // --- Verificações de Movimento ---

        // 1. Verificar se o movimento é para fora do mapa
        if (proximaLinha < 0 || proximaLinha >= 5 || proximaColuna < 0 || proximaColuna >= 5) {
            printf("Voce nao pode sair do mapa!\n");
            continue;
        }

        // 2. Verificar se o movimento é contra uma parede
        if (mapa[proximaLinha][proximaColuna] == '#') {
            printf("Voce bateu na parede!\n");
            continue;
        }

        // 3. Verificar condição de vitória
        if (mapa[proximaLinha][proximaColuna] == 'S') {
            printf("\nVOCE ENCONTROU A SAIDA! A masmorra foi conquistada!\n");
            break; // Sai do loop while(1), terminando o jogo
        }

        // --- Atualizar Posição do Herói ---
        // Se o movimento foi válido, atualiza o mapa
        mapa[linhaHeroi][colunaHeroi] = ' '; // Apaga o herói da posição antiga
        linhaHeroi = proximaLinha;           // Atualiza a coordenada do herói
        colunaHeroi = proximaColuna;         // Atualiza a coordenada do herói
        mapa[linhaHeroi][colunaHeroi] = 'H'; // Coloca o herói na nova posição
    }

    printf("\nParabens! Voce ganhou a conquista suprema: 'Guardiao da Masmorra Digital'!\n");

    return 0;
}
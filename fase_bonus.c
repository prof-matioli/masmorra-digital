// Arquivo: fase_bonus.c
// Missão: Desafios dos Desbravadores
// Objetivo: Implementar funcionalidades avançadas como inimigos,
//           itens coletáveis e geração procedural de mapas.

#include <stdio.h>
#include <stdlib.h> // Para as funções rand() e srand()
#include <time.h>   // Para a função time()

int main() {
    // --- GERAÇÃO DO MAPA ALEATÓRIO ---

    // Inicializa o gerador de números aleatórios com uma "semente" baseada no tempo atual.
    // Isso garante que o mapa seja diferente a cada vez que o programa é executado.
    srand(time(NULL));

    char mapa[7][10]; // Mapa um pouco maior para mais variedade
    int linhas = 7;
    int colunas = 10;
    int i, j;

    // 1. Preenche todo o mapa com chão (' ')
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            mapa[i][j] = ' ';
        }
    }

    // 2. Cria as paredes da borda ('#')
    for (i = 0; i < linhas; i++) {
        mapa[i][0] = '#';
        mapa[i][colunas - 1] = '#';
    }
    for (j = 0; j < colunas; j++) {
        mapa[0][j] = '#';
        mapa[linhas - 1][j] = '#';
    }

    // 3. Posiciona o Herói ('H') em um local fixo
    int linhaHeroi = 1;
    int colunaHeroi = 1;
    mapa[linhaHeroi][colunaHeroi] = 'H';

    // 4. Posiciona outros elementos aleatoriamente
    int num_paredes_internas = 8;
    int num_moedas = 5;
    int num_inimigos = 3;

    // Função para posicionar um item aleatoriamente em um espaço vazio
    // Usamos um laço do-while para garantir que a posição sorteada esteja vazia.
    for (i = 0; i < num_paredes_internas; i++) {
        int r, c;
        do {
            r = rand() % linhas;
            c = rand() % colunas;
        } while (mapa[r][c] != ' ');
        mapa[r][c] = '#';
    }

    for (i = 0; i < num_moedas; i++) {
        int r, c;
        do {
            r = rand() % linhas;
            c = rand() % colunas;
        } while (mapa[r][c] != ' ');
        mapa[r][c] = 'M';
    }
    
    for (i = 0; i < num_inimigos; i++) {
        int r, c;
        do {
            r = rand() % linhas;
            c = rand() % colunas;
        } while (mapa[r][c] != ' ');
        mapa[r][c] = 'I';
    }

    // Posiciona a Saída ('S') aleatoriamente
    int r, c;
    do {
        r = rand() % linhas;
        c = rand() % colunas;
    } while (mapa[r][c] != ' ');
    mapa[r][c] = 'S';

    // --- LÓGICA DO JOGO ---

    char movimento;
    int moedasColetadas = 0;

    printf("--- FASE BONUS: A MASMORRA MUTAVEL ---\n");
    printf("Colete as moedas ('M'), evite os inimigos ('I') e encontre a saida ('S')!\n\n");

    while (1) {
        // system("cls"); // Para Windows
        // system("clear"); // Para Linux/Mac

        printf("--- MAPA ATUAL ---\n");
        printf("Moedas: %d\n", moedasColetadas);
        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                printf("%c ", mapa[i][j]);
            }
            printf("\n");
        }

        printf("\nSeu proximo movimento (w/a/s/d): ");
        scanf(" %c", &movimento);

        int proximaLinha = linhaHeroi;
        int proximaColuna = colunaHeroi;

        switch (movimento) {
            case 'w': proximaLinha--; break;
            case 's': proximaLinha++; break;
            case 'a': proximaColuna--; break;
            case 'd': proximaColuna++; break;
            default: printf("Comando invalido!\n"); continue;
        }

        // --- Verificações de Movimento ---
        if (mapa[proximaLinha][proximaColuna] == '#') {
            printf("Voce bateu na parede!\n");
            continue;
        }
        
        // BÔNUS 1: VERIFICAR INIMIGO
        if (mapa[proximaLinha][proximaColuna] == 'I') {
            printf("Um inimigo bloqueia o caminho!\n");
            continue;
        }

        // BÔNUS 2: COLETAR MOEDA
        if (mapa[proximaLinha][proximaColuna] == 'M') {
            moedasColetadas++;
            printf("Voce coletou uma moeda! Total: %d\n", moedasColetadas);
        }

        if (mapa[proximaLinha][proximaColuna] == 'S') {
            printf("\nVOCE ENCONTROU A SAIDA! Voce escapou com %d moedas!\n", moedasColetadas);
            break;
        }

        // --- Atualizar Posição do Herói ---
        mapa[linhaHeroi][colunaHeroi] = ' ';
        linhaHeroi = proximaLinha;
        colunaHeroi = proximaColuna;
        mapa[linhaHeroi][colunaHeroi] = 'H';
    }

    printf("\nFim de jogo. Voce e um verdadeiro Desbravador!\n");

    return 0;
}
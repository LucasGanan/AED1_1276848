/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Lucas Gabriel Ganan de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 28/08/2026
Objetivo    : Escrever um programa que verifica se uma matriz preenchida é ou não uma solução para o problema. Sudoku.
Dificuldade : Entender a lógica, principalmente de verificar os blocos
Uso de IA   : Sim, usei para entender a lógica, verificação dos blocos e organização
-------------------------------------------------------------------------- */

#include <stdio.h>

// Verifica se existe algum número repetido nas linhas
int verifica_linha(int sudoku[9][9]) {
    int i, j, k, ref;

    // Percorre as 9 linhas
    for (i = 0; i < 9; i++) {

        // Escolhe um número da linha como referência
        for (k = 0; k < 9; k++) {
            ref = sudoku[i][k];

            // Compara a referência com os números que vêm depois dela
            for (j = k + 1; j < 9; j++) {
                if (ref == sudoku[i][j]) {
                    return 0; // Encontrou número repetido
                }
            }
        }
    }

    return 1; // Nenhuma repetição encontrada
}


// Verifica se existe algum número repetido nas colunas
int verifica_coluna(int sudoku[9][9]) {
    int i, j, k, ref;

    // Percorre as 9 colunas
    for (j = 0; j < 9; j++) {

        // Escolhe um número da coluna como referência
        for (k = 0; k < 9; k++) {
            ref = sudoku[k][j];

            // Compara a referência com os números abaixo dela
            for (i = k + 1; i < 9; i++) {
                if (ref == sudoku[i][j]) {
                    return 0; // Encontrou número repetido
                }
            }
        }
    }

    return 1; // Nenhuma repetição encontrada
}


// Verifica se existe algum número repetido nos blocos 3x3
int verifica_bloco(int sudoku[9][9]) {
    int i, j, k, n, a, b, c, d;

    // b e c indicam onde começa cada bloco 3x3
    for (c = 0; c < 9; c += 3) {
        for (b = 0; b < 9; b += 3) {

            // Percorre os 9 números do bloco
            for (i = b; i < b + 3; i++) {
                for (j = c; j < c + 3; j++) {

                    // Escolhe um número do bloco como referência
                    n = sudoku[i][j];

                    // Procura o mesmo número dentro do bloco
                    for (k = b; k < b + 3; k++) {
                        for (a = c; a < c + 3; a++) {

                            // Verifica se encontrou o mesmo número
                            // em uma posição diferente
                            if (n == sudoku[k][a] && !(k == i && a == j)) {
                                return 0; // Número repetido
                            }
                        }
                    }
                }
            }
        }
    }

    return 1; // Nenhuma repetição encontrada
}


// Verifica as linhas, colunas e blocos
int verifica_sudoku(int sudoku[9][9]) {

    // Se alguma das verificações falhar, o Sudoku é inválido
    if (!verifica_linha(sudoku)) {
        return 0;
    }

    if (!verifica_coluna(sudoku)) {
        return 0;
    }

    if (!verifica_bloco(sudoku)) {
        return 0;
    }

    return 1; // Todas as verificações passaram
}


// Lê os números do Sudoku e depois verifica se ele é válido
int preenche_verifica(int sudoku[9][9]) {
    int i, j;

    // Preenche a matriz 9x9
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%d", &sudoku[i][j]);

            // Os valores devem estar entre 1 e 9
            if (sudoku[i][j] < 1 || sudoku[i][j] > 9) {
                return 0;
            }
        }
    }

    // Depois de preencher, verifica o Sudoku
    return verifica_sudoku(sudoku);
}


int main() {
    int i, n;
    int sudoku[9][9];

    // Lê a quantidade de Sudokus que serão analisados
    scanf("%d", &n);

    // Repete para cada instância
    for (i = 1; i <= n; i++) {

        // Lê o Sudoku e verifica se ele é válido
        printf("Instancia %d\n", i);

        if (preenche_verifica(sudoku)) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    return 0;
}

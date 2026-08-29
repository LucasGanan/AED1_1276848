/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Lucas Gabriel Ganan de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 28/08/2026
Objetivo    : Escrever um programa que verifica se uma matriz preenchida é ou não uma solução para o problema. Sudoku.
Dificuldade : Entender a lógica 
Uso de IA   : Sim, usei para entender a lógica e a verificação dos blocos 
-------------------------------------------------------------------------- */

#include <stdio.h>

int verifica(int v[9]) {
    int usado[10] = {0};

    for (int i = 0; i < 9; i++) {
        if (v[i] < 1 || v[i] > 9) {
            return 0;
        }

        if (usado[v[i]] == 1) {
            return 0;
        }

        usado[v[i]] = 1;
    }

    return 1;
}

int main() {

    int n;
    scanf("%d", &n);

    for (int instancia = 1; instancia <= n; instancia++) {

        int sudoku[9][9];
        int valido = 1;

        // Lê a matriz
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        // Verifica as linhas
        for (int i = 0; i < 9; i++) {
            int v[9];

            for (int j = 0; j < 9; j++) {
                v[j] = sudoku[i][j];
            }

            if (!verifica(v)) {
                valido = 0;
            }
        }

        // Verifica as colunas
        for (int j = 0; j < 9; j++) {
            int v[9];

            for (int i = 0; i < 9; i++) {
                v[i] = sudoku[i][j];
            }

            if (!verifica(v)) {
                valido = 0;
            }
        }

        // Verifica as regiões 3x3
        for (int linha = 0; linha < 9; linha += 3) {
            for (int coluna = 0; coluna < 9; coluna += 3) {

                int v[9];
                int k = 0;

                for (int i = linha; i < linha + 3; i++) {
                    for (int j = coluna; j < coluna + 3; j++) {
                        v[k] = sudoku[i][j];
                        k++;
                    }
                }

                if (!verifica(v)) {
                    valido = 0;
                }
            }
        }

        printf("Instancia %d\n", instancia);

        if (valido) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    return 0;
}

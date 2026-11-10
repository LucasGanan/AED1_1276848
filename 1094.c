/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Lucas Gabriel Ganan de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1094
Data        : 04/11/2026
Objetivo    : Utilizar laços de repetição e condicionais para contabilizar diferentes tipos de cobaias e calcular o percentual de cada tipo em relação ao total utilizado.
Dificuldade : Entender a lógica.
Uso de IA   : Sim, usei para corrigir minha lógica
-------------------------------------------------------------------------- */

#include <stdio.h>
int main() {
    int N, quantia;
    int coelhos = 0, ratos = 0, sapos = 0;
    int total = 0;
    char tipo;
    // Lê a quantidade de experimentos
    scanf("%d", &N);
    // Percorre todos os experimentos
    for (int i = 0; i < N; i++) {
        // Lê a quantidade e o tipo de cobaia
        scanf("%d %c", &quantia, &tipo);
        // Soma a quantidade ao tipo correspondente
        if (tipo == 'C') {
            coelhos += quantia;
        }
        else if (tipo == 'R') {
            ratos += quantia;
        }
        else if (tipo == 'S') {
            sapos += quantia;
        }
        // Atualiza o total de cobaias
        total += quantia;
    }
    // Calcula a porcentagem de cada tipo
    double percCoelhos = (coelhos * 100.0) / total;
    double percRatos = (ratos * 100.0) / total;
    double percSapos = (sapos * 100.0) / total;
    // Apresenta os resultados
    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", coelhos);
    printf("Total de ratos: %d\n", ratos);
    printf("Total de sapos: %d\n", sapos);
    printf("Percentual de coelhos: %.2f %%\n", percCoelhos);
    printf("Percentual de ratos: %.2f %%\n", percRatos);
    printf("Percentual de sapos: %.2f %%\n", percSapos);
    return 0;
}

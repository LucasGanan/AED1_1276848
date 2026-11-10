/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Lucas Gabriel Ganan de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1095
Data        : 04/11/2026
Objetivo    : Utilizar um laço for para imprimir uma sequência numérica com duas variáveis, uma crescente e outra decrescente, seguindo intervalos definidos.
Dificuldade : Entender a lógica.
Uso de IA   : Não.
-------------------------------------------------------------------------- */


#include <stdio.h>
int main() {
    int i, j;
    // Inicializa I com 1 e J com 60
    // I aumenta de 3 em 3 e J diminui de 5 em 5
    for (i = 1, j = 60; j >= 0; i += 3, j -= 5) {
        printf("I=%d J=%d\n", i, j);
    }
    return 0;
}

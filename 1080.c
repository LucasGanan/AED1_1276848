/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Lucas Gabriel Ganan de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 23/08/2026
Objetivo    : Leia 100 valores inteiros. Apresente então o maior valor lido e a posição dentre os 100 valores lidos.
Dificuldade : Perceber que precisava de dois "for" e entender qual devia ser a posição inicial.
Uso de IA   : A princípio fiz todo o exercício sozinho e usei a IA para corrigir, ela me explicou os erros, incluindo que eu tinha usado apenas um for, então consegui corrigir e deu certo.
-------------------------------------------------------------------------- */

#include <stdio.h>

int main() {

    int v[100];

    // Lê os 100 valores e guarda cada um no vetor
    for (int i = 0; i < 100; i++) {
        scanf("%d", &v[i]);
    }

    // Considera o primeiro valor como o maior inicialmente
    // A posição começa em 1, pois a questão considera posições de 1 a 100
    int posicao = 1;
    int maior = v[0];

    // Percorre o restante do vetor procurando um valor maior
    for (int i = 1; i < 100; i++) {

        // Se encontrar um valor maior que o maior atual,
        // atualiza o maior valor e sua posição
        if (v[i] > maior) {
            maior = v[i];
            posicao = i + 1;
        }
    }

    // Mostra o maior valor encontrado e sua posição
    printf("%d\n%d\n", maior, posicao);

    return 0;
}

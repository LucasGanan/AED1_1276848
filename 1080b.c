/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Lucas Gabriel Ganan de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 30/08/2026
Objetivo    : Leia 100 valores inteiros. Apresente então o maior valor lido e a posição dentre os 100 valores lidos. Usando alocação dinâmica de vetores.
Dificuldade : Entender alocação dinâmica
Uso de IA   : Usei para entender alocação dinâmica e fazer comentários no código
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h> //biblioteca do malloc e free

int main() {

    // Cria um ponteiro que vai guardar o endereço
    // do espaço reservado para o vetor
    int *v;

    // Aloca espaço na memória para 100 inteiros
    v = malloc(100 * sizeof(int)); // 100 × tamanho de um int
    //tbm poderia ser v = (int *) malloc(100 * sizeof(int));

    // Lê os 100 valores e guarda cada um no vetor
    for (int i = 0; i < 100; i++) {
        scanf("%d", &v[i]);
    }

    // Considera o primeiro valor como o maior inicialmente
    // A posição começa em 1, pois a posição de entrada começa em 1
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

    // Mostra o maior valor e sua posição
    printf("%d\n%d\n", maior, posicao);

    // Libera o espaço que foi reservado para o vetor
    free(v);

    return 0;
}

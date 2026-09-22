/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Lucas Gabriel Ganan de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 15/09/2026
Objetivo    : O objetivo do exercício é simular o descarte e a movimentação de cartas em uma pilha, utilizando uma lista encadeada, até que reste apenas uma carta. 
Ao final, deve-se apresentar a sequência de cartas descartadas e a carta restante para cada valor de entrada, encerrando o processamento quando for informado o número 0.
Dificuldade : Entender a lista encadeada
Uso de IA   : Sim, usei para corrigir minha lógica
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

// Estrutura de cada nó da lista
typedef struct No {
    int valor;
    struct No *prox;
} No;

// Insere uma carta no final da lista
void inserirFinal(No **inicio, No **fim, int valor) {

    // Cria um novo nó na memória
    No *novo = (No *) malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = NULL;

    // Se a lista estiver vazia,
    // o novo nó será início e fim
    if (*inicio == NULL) {
        *inicio = novo;
        *fim = novo;
    } else {
        // O antigo fim aponta para o novo nó
        (*fim)->prox = novo;

        // O novo nó passa a ser o fim
        *fim = novo;
    }
}

// Remove a primeira carta da lista
int removerInicio(No **inicio, No **fim) {

    No *aux = *inicio;
    int valor = aux->valor;

    // O início passa a ser o próximo nó
    *inicio = aux->prox;

    // Se a lista ficou vazia,
    // o fim também deve ser NULL
    if (*inicio == NULL) {
        *fim = NULL;
    }

    // Libera a memória do nó removido
    free(aux);

    return valor;
}

int main() {

    int n;

    // Lê vários casos até encontrar 0
    while (scanf("%d", &n) == 1 && n != 0) {

        No *inicio = NULL;
        No *fim = NULL;

        // Cria a lista com as cartas de 1 até n
        for (int i = 1; i <= n; i++) {
            inserirFinal(&inicio, &fim, i);
        }

        printf("Discarded cards:");

        int primeira = 1;

        // Continua enquanto houver mais de uma carta
        while (inicio != fim) {

            // 1. Descarta a carta do topo
            int descartada = removerInicio(&inicio, &fim);

            // Controla a vírgula na saída
            if (primeira == 1) {
                printf(" %d", descartada);
                primeira = 0;
            } else {
                printf(", %d", descartada);
            }

            // 2. Move a próxima carta para a base
            int movida = removerInicio(&inicio, &fim);

            inserirFinal(&inicio, &fim, movida);
        }

        // Imprime a carta que sobrou
        printf("\nRemaining card: %d\n", inicio->valor);

        // Libera a última carta
        free(inicio);
    }

    return 0;
}

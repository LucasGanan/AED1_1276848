/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Lucas Gabriel Ganan de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 27/09/2026
Objetivo    : Calcular o tempo total das entregas, usando **busca binária** para encontrar a posição de cada casa e somando as distâncias percorridas entre elas.
Dificuldade : Entender busca binária.
Uso de IA   : Sim, usei para corrigir minha lógica
-------------------------------------------------------------------------- */
#include <stdio.h>
// Função de busca binária
// Retorna o índice onde está a casa x
int buscaBinaria(int x, int n, int v[]) {
    int e = 0; // início da busca
    int d = n - 1; // fim da busca
    while (e <= d) {
        // Calcula a posição do meio
        int m = (e + d) / 2;
        if (v[m] == x) {
            // Encontramos a casa
            return m;
        }
        else if (v[m] < x) {
            // x está à direita do meio
            e = m + 1;
        }
        else {
            // x está à esquerda do meio
            d = m - 1;
        }
    }
    return -1; // Não deveria acontecer, pois a encomenda sempre existe
}

int main() {
    int N, M;
    // N = quantidade de casas
    // M = quantidade de encomendas
    scanf("%d %d", &N, &M);
    int casas[N];
    // Lê os números das casas em ordem crescente
    for (int i = 0; i < N; i++) {
        scanf("%d", &casas[i]);
    }
    // O carteiro começa na primeira casa
    int posicaoAtual = 0;
    // Acumulador do tempo total
    int tempo = 0;
    // Processa as encomendas na ordem em que chegaram
    for (int i = 0; i < M; i++) {
        int encomenda;
        // Lê o número da casa onde deve entregar
        scanf("%d", &encomenda);
        // Usa busca binária para descobrir
        // em qual posição do vetor está essa casa
        int novaPosicao = buscaBinaria(encomenda, N, casas);
        // A distância é a diferença entre as posições
        // das duas casas no vetor
        if (novaPosicao > posicaoAtual)
            tempo += novaPosicao - posicaoAtual;
        else
            tempo += posicaoAtual - novaPosicao;
        // O carteiro agora está na casa da encomenda
        posicaoAtual = novaPosicao;
    }
    // Mostra o tempo total
    printf("%d\n", tempo);
    return 0;
}

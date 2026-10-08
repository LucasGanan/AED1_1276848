/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Lucas Gabriel Ganan de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 03/10/2026
Objetivo    : Verificar se é possível reorganizar os vagões em uma determinada ordem usando uma **pilha (LIFO)**.
Dificuldade : Entender essa pilha.
Uso de IA   : Sim, usei para corrigir minha lógica
-------------------------------------------------------------------------- */

#include <stdio.h>

void push(int pilha[], int *topo, int valor) {
    (*topo)++;
    pilha[*topo] = valor;
}

int pop(int pilha[], int *topo) {
    int valor = pilha[*topo];
    (*topo)--;
    return valor;
}

int podeFormar(int N, int saida[]) {
    int pilha[1000];
    int topo = -1;
    int proximo = 1;
    for (int i = 0; i < N; i++) {
        // Coloca vagões na pilha até encontrar o desejado
        while (proximo <= N && (topo == -1 || pilha[topo] != saida[i])) {
            push(pilha, &topo, proximo);
            proximo++;
        }
        // Se o vagão desejado está no topo, retira
        if (topo >= 0 && pilha[topo] == saida[i])
            pop(pilha, &topo);
        else
            return 0;
    }
    return 1;
}

int main() {
    int N;
    while (scanf("%d", &N) && N != 0) {
        int saida[1000];
        while (1) {
            scanf("%d", &saida[0]);
            // 0 indica o fim das sequências
            if (saida[0] == 0)
                break;
            // Lê o restante da sequência
            for (int i = 1; i < N; i++)
                scanf("%d", &saida[i]);
            if (podeFormar(N, saida))
                printf("Yes\n");
            else
                printf("No\n");
        }
        printf("\n");
    }
    return 0;
}

/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Lucas Gabriel Ganan de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 17/11/2026
Objetivo    : 
Dificuldade : 
Uso de IA   : Sim, usei para corrigir minha lógica
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        // Lista de adjacencia
        int *head = malloc((N + 1) * sizeof(int));
        int *to = malloc(M * sizeof(int));
        int *next = malloc(M * sizeof(int));
        // Estado de cada vertice:
        // 0 = nao visitado
        // 1 = sendo visitado
        // 2 = ja finalizado
        int *estado = calloc(N + 1, sizeof(int));
        // Pilha utilizada pela DFS
        int *pilha = malloc((N + 1) * sizeof(int));
        int *proxAresta = malloc((N + 1) * sizeof(int));
        // Inicializa as listas de adjacencia
        for (int i = 1; i <= N; i++) {
            head[i] = -1;
        }
        // Le as dependencias e monta o grafo
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            // A depende de B: aresta A -> B
            to[i] = B;
            next[i] = head[A];
            head[A] = i;
        }
        int ciclo = 0;
        // Percorre todos os vertices
        for (int inicio = 1; inicio <= N && !ciclo; inicio++) {
            if (estado[inicio] != 0) {
                continue;
            }
            int topo = 0;
            // Inicia a DFS
            pilha[topo] = inicio;
            proxAresta[topo] = head[inicio];
            estado[inicio] = 1;
            while (topo >= 0 && !ciclo) {
                int v = pilha[topo];
                int aresta = proxAresta[topo];
                // Todas as arestas foram exploradas
                if (aresta == -1) {
                    estado[v] = 2;
                    topo--;
                    continue;
                }
                // Avanca para a proxima aresta
                proxAresta[topo] = next[aresta];
                int vizinho = to[aresta];
                // Encontrou um vertice que esta na DFS atual
                if (estado[vizinho] == 1) {
                    ciclo = 1;
                }
                // Se ainda nao foi visitado, continua a DFS
                else if (estado[vizinho] == 0) {
                    topo++;
                    pilha[topo] = vizinho;
                    proxAresta[topo] = head[vizinho];
                    estado[vizinho] = 1;
                }
            }
        }
        // Imprime o resultado
        if (ciclo) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        // Libera a memoria
        free(head);
        free(to);
        free(next);
        free(estado);
        free(pilha);
        free(proxAresta);
    }
    return 0;
}

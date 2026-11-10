/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Lucas Gabriel Ganan de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1466
Data        : 08/11/2026
Objetivo    : Implementar uma Árvore Binária de Busca e realizar seu percurso por nível (BFS), utilizando uma fila para visitar os nós na ordem FIFO.
Dificuldade : Entender essa árvore binária.
Uso de IA   : Sim, usei para corrigir minha lógica
-------------------------------------------------------------------------- */


#include <stdio.h>
#include <stdlib.h>

// Estrutura de cada nó da árvore
typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;
// Estrutura da fila
typedef struct {
    No *itens[500];
    int inicio;
    int fim;
} Fila;
// Cria um novo nó
No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}
// Insere um elemento na árvore binária de busca
No* inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    // Valores menores vão para a esquerda
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    }
    // Valores maiores vão para a direita
    else {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}
// Inicializa a fila
void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}
// Verifica se a fila está vazia
int vazia(Fila *f) {
    return f->inicio == f->fim;
}
// Insere um elemento no final da fila
void enfileirar(Fila *f, No *valor) {
    f->itens[f->fim++] = valor;
}
// Remove e retorna o primeiro elemento da fila
No* desenfileirar(Fila *f) {
    return f->itens[f->inicio++];
}
// Percorre a árvore por nível (BFS)
void percursoNivel(No *raiz) {
    Fila f;
    inicializar(&f);
    // Insere a raiz na fila
    if (raiz != NULL) {
        enfileirar(&f, raiz);
    }
    int primeiro = 1;

    // Continua enquanto houver elementos na fila
    while (!vazia(&f)) {
        // Remove o primeiro nó da fila
        No *atual = desenfileirar(&f);
        // Imprime o valor do nó
        if (primeiro == 0) {
            printf(" ");
        }
        printf("%d", atual->valor);
        primeiro = 0;
        // Insere o filho esquerdo na fila
        if (atual->esq != NULL) {
            enfileirar(&f, atual->esq);
        }
        // Insere o filho direito na fila
        if (atual->dir != NULL) {
            enfileirar(&f, atual->dir);
        }
    }
    printf("\n");
}

// Libera a memória da árvore
void liberar(No *raiz) {
    if (raiz != NULL) {
        liberar(raiz->esq);
        liberar(raiz->dir);
        free(raiz);
    }
}

int main() {
    int C, N, valor;
    scanf("%d", &C);
    // Percorre todos os casos de teste
    for (int caso = 1; caso <= C; caso++) {
        No *raiz = NULL;
        scanf("%d", &N);
        // Lê os valores e insere na árvore
        for (int i = 0; i < N; i++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }
        // Imprime o número do caso
        printf("Case %d:\n", caso);
        // Realiza o percurso por nível
        percursoNivel(raiz);
        // Linha em branco após cada caso
        printf("\n");
        liberar(raiz);
    }
    return 0;
}

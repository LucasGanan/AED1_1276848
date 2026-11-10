/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Lucas Gabriel Ganan de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 05/11/2026
Objetivo    : Implementar uma Árvore Binária de Busca utilizando alocação dinâmica e recursividade, permitindo inserir, pesquisar e percorrer os elementos nas ordens infixa, prefixa e posfixa.
Dificuldade : Entender a lógica.
Uso de IA   : Sim, usei para corrigir pequenos erros
-------------------------------------------------------------------------- */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de cada nó da árvore
typedef struct No {
    char valor;
    struct No *esq;
    struct No *dir;
} No;

// Cria um novo nó
No* criarNo(char valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Insere um elemento na árvore
No* inserir(No *raiz, char valor) {
    // Se a posição estiver vazia, cria um novo nó
    if (raiz == NULL) {
        return criarNo(valor);
    }
    // Se o valor for menor, vai para a esquerda
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    }
    // Se o valor for maior, vai para a direita
    else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

// Percurso INFIXO: esquerda, raiz, direita
void infixa(No *raiz, int *primeiro) {
    if (raiz != NULL) {
        infixa(raiz->esq, primeiro);
        if (*primeiro == 0) {
            printf(" ");
        }
        printf("%c", raiz->valor);
        *primeiro = 0;
        infixa(raiz->dir, primeiro);
    }
}

// Percurso PREFIXO: raiz, esquerda, direita
void prefixa(No *raiz, int *primeiro) {
    if (raiz != NULL) {
        if (*primeiro == 0) {
            printf(" ");
        }
        printf("%c", raiz->valor);
        *primeiro = 0;
        prefixa(raiz->esq, primeiro);
        prefixa(raiz->dir, primeiro);
    }
}

// Percurso POSFIXO: esquerda, direita, raiz
void posfixa(No *raiz, int *primeiro) {
    if (raiz != NULL) {
        posfixa(raiz->esq, primeiro);
        posfixa(raiz->dir, primeiro);
        if (*primeiro == 0) {
            printf(" ");
        }
        printf("%c", raiz->valor);
        *primeiro = 0;
    }
}

// Pesquisa um elemento na árvore
int pesquisar(No *raiz, char valor) {
    // Se chegar em uma posição vazia, não encontrou
    if (raiz == NULL) {
        return 0;
    }
    // Se encontrou o valor, retorna 1
    if (raiz->valor == valor) {
        return 1;
    }
    // Procura na esquerda ou na direita
    if (valor < raiz->valor) {
        return pesquisar(raiz->esq, valor);
    }
    else {
        return pesquisar(raiz->dir, valor);
    }
}

// Libera a memória utilizada pela árvore
void liberar(No *raiz) {
    if (raiz != NULL) {
        liberar(raiz->esq);
        liberar(raiz->dir);
        free(raiz);
    }
}

int main() {
    No *raiz = NULL;
    char comando[10];
    char valor;
    // Lê os comandos até o final da entrada (EOF)
    while (scanf("%s", comando) != EOF) {
        // Comando de inserção
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &valor);
            raiz = inserir(raiz, valor);
        }
        // Comando de percurso infixo
        else if (strcmp(comando, "INFIXA") == 0) {
            int primeiro = 1;
            infixa(raiz, &primeiro);
            printf("\n");
        }
        // Comando de percurso prefixo
        else if (strcmp(comando, "PREFIXA") == 0) {
            int primeiro = 1;
            prefixa(raiz, &primeiro);
            printf("\n");
        }
        // Comando de percurso posfixo
        else if (strcmp(comando, "POSFIXA") == 0) {
            int primeiro = 1;
            posfixa(raiz, &primeiro);
            printf("\n");
        }
        // Comando de pesquisa
        else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &valor);
            if (pesquisar(raiz, valor)) {
                printf("%c existe\n", valor);
            }
            else {
                printf("%c nao existe\n", valor);
            }
        }
    }
    // Libera toda a memória da árvore
    liberar(raiz);
    return 0;
}

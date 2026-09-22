/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Lucas Gabriel Ganan de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 15/09/2026
Objetivo    : Validar o balanceamento de parênteses em expressões matemáticas, garantindo que todo ( tenha um ) correspondente na ordem correta e exibindo correct ou incorrect para cada linha.
Dificuldade : Entender pilha.
Uso de IA   : Sim, usei para corrigir minha lógica
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 1005

// Estrutura para representar a pilha
typedef struct {
    char itens[TAM_MAX];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

// Função para verificar se a pilha está vazia
int estaVazia(Pilha *p) {
    return p->topo == -1;
}

// Função para empilhar (push) um caractere
void empilhar(Pilha *p, char c) {
    p->topo++;
    p->itens[p->topo] = c;
}

// Função para desempilhar (pop) um caractere
void desempilhar(Pilha *p) {
    if (!estaVazia(p)) {
        p->topo--;
    }
}

// Função para verificar se a expressão tem parênteses válidos
int verificarExpressao(const char *expressao) {
    Pilha pilha;
    inicializarPilha(&pilha);

    for (int i = 0; expressao[i] != '\0'; i++) {
        // Se encontrar um parêntese de abertura '(', empilha
        if (expressao[i] == '(') {
            empilhar(&pilha, '(');
        } 
        // Se encontrar um parêntese de fechamento ')'
        else if (expressao[i] == ')') {
            // Se a pilha estiver vazia, significa que há um ')' sem um '(' correspondente
            if (estaVazia(&pilha)) {
                return 0; // Incorreto
            }
            // Se houver um '(' na pilha, desempilha para fazer o par
            desempilhar(&pilha);
        }
    }

    // Se a pilha estiver vazia no final, todos os '(' foram fechados corretamente
    return estaVazia(&pilha);
}

int main() {
    char expressao[TAM_MAX];

    // Lê as expressões linha a linha até o final do arquivo (EOF)
    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        // Remove a quebra de linha (\n ou \r) do final da string, se houver
        expressao[strcspn(expressao, "\r\n")] = '\0';

        // Ignora linhas totalmente vazias
        if (strlen(expressao) == 0) {
            continue;
        }

        // Verifica a validade e exibe "correct" ou "incorrect"
        if (verificarExpressao(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}

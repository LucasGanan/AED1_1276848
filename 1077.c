/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Lucas Gabriel Ganan de Souza
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 27/09/2026
Objetivo    : Converter uma expressão infixa para pós-fixa, usando uma pilha feita com lista encadeada para organizar os operadores conforme sua prioridade.
Dificuldade : Entender infixa e posfixa.
Uso de IA   : Sim, usei para corrigir minha lógica
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//criação do nó
typedef struct No {
    char valor;
    struct No *prox;
} No;
// Insere no topo da pilha
void push(No **topo, char x) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = x;
    novo->prox = *topo;
    *topo = novo;
}
// Remove do topo da pilha
char pop(No **topo) {
    No *temp = *topo;
    char x = temp->valor;
    *topo = temp->prox;
    free(temp);
    return x;
}
// Retorna a prioridade do operador
int prioridade(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}
int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        char expressao[301];
        scanf("%s", expressao);
        No *topo = NULL;
        for (int i = 0; expressao[i] != '\0'; i++) {
            char c = expressao[i];
            // Letras e números vão direto para a saída
            if (isalnum(c)) {
                printf("%c", c);
            }
            // Abre parêntese: coloca na pilha
            else if (c == '(') {
                push(&topo, c);
            }
            // Fecha parêntese: tira até encontrar '('
            else if (c == ')') {
                while (topo != NULL && topo->valor != '(') {
                    printf("%c", pop(&topo));
                }
                if (topo != NULL)
                    pop(&topo); // Remove o '('
            }
            // Operador: tira os de maior ou igual prioridade e depois coloca o atual
            else {
                while (topo != NULL && topo->valor != '(' &&
                       prioridade(topo->valor) >= prioridade(c)) {
                    printf("%c", pop(&topo));
                }
                push(&topo, c);
            }
        }
        // No final, tira todos os operadores restantes
        while (topo != NULL) {
            printf("%c", pop(&topo));
        }
        printf("\n");
    }
    return 0;
}

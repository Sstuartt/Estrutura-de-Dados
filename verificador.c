#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int empilhar(Pilha *p, char c) {
    if (p->topo == MAX-1) {
        return 0;
    }
    p->topo++;
    p->dados[p->topo] = c;
    return 1;
}

int desempilhar(Pilha *p) {
    if (p->topo == -1) {
        return 0;
    }
    p->topo--;
    return 1;
}

int verificarParenteses(char expr[]) {
    Pilha p;
    inicializar(&p);
    
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            empilhar(&p, '(');
        } else if (expr[i] == ')') {
            if (!desempilhar(&p)) {
                return 0; // parêntese fechando sem abrir
            }
        }
    }
    
    return (p.topo == -1); // pilha vazia = balanceado
}

int main() {
    char expr[MAX];
    
    printf("Digite uma expressão matemática: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0'; // remove newline
    
    if (verificarParenteses(expr)) {
        printf("Os parênteses estão balanceados!\n");
    } else {
        printf("Os parênteses NÃO estão balanceados!\n");
    }
    
    return 0;
}

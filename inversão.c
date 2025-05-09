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

char desempilhar(Pilha *p) {
    if (p->topo == -1) {
        return '\0';
    }
    char c = p->dados[p->topo];
    p->topo--;
    return c;
}

void inverterPalavra(char palavra[]) {
    Pilha p;
    inicializar(&p);
    int i;
    
    // Empilha cada caractere
    for (i = 0; palavra[i] != '\0'; i++) {
        empilhar(&p, palavra[i]);
    }
    
    // Desempilha para inverter
    for (i = 0; palavra[i] != '\0'; i++) {
        palavra[i] = desempilhar(&p);
    }
}

int main() {
    char palavra[MAX];
    
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    
    inverterPalavra(palavra);
    printf("Palavra invertida: %s\n", palavra);
    
    return 0;
}

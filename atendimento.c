#include <stdio.h>
#define TAMANHO 5

typedef struct {
    int senhas[TAMANHO];
    int inicio, fim;
} Fila;

void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
}

int enfileirar(Fila *f, int senha) {
    if (f->fim == TAMANHO-1) {
        return 0; // fila cheia
    }
    f->fim++;
    f->senhas[f->fim] = senha;
    return 1;
}

int desenfileirar(Fila *f) {
    if (f->inicio > f->fim) {
        return -1; // fila vazia
    }
    int senha = f->senhas[f->inicio];
    f->inicio++;
    return senha;
}

int main() {
    Fila atendimento;
    inicializar(&atendimento);
    
    // Gerando 5 senhas
    for (int i = 1; i <= TAMANHO; i++) {
        enfileirar(&atendimento, i);
        printf("Senha gerada: %d\n", i);
    }
    
    printf("\nIniciando atendimento:\n");
    int senha;
    while (senha = desenfileirar(&atendimento)) {
        if (senha == -1) break;
        printf("Atendendo senha %d\n", senha);
    }
    
    return 0;
}

#include <stdio.h>
#define TAMANHO 10

typedef struct {
    int idades[TAMANHO];
    char nomes[TAMANHO][50];
    int inicio, fim;
} Fila;

void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
}

int enfileirar(Fila *f, char nome[], int idade) {
    if (f->fim == TAMANHO-1) {
        return 0; // fila cheia
    }
    f->fim++;
    strcpy(f->nomes[f->fim], nome);
    f->idades[f->fim] = idade;
    return 1;
}

int desenfileirar(Fila *f, char nome[], int *idade) {
    if (f->inicio > f->fim) {
        return 0; // fila vazia
    }
    strcpy(nome, f->nomes[f->inicio]);
    *idade = f->idades[f->inicio];
    f->inicio++;
    return 1;
}

void atenderComPrioridade(Fila *f) {
    Fila preferencial, normal;
    inicializar(&preferencial);
    inicializar(&normal);
    char nome[50];
    int idade;
    
    // Separando em filas
    while (desenfileirar(f, nome, &idade)) {
        if (idade >= 60) {
            enfileirar(&preferencial, nome, idade);
        } else {
            enfileirar(&normal, nome, idade);
        }
    }
    
    // Atendendo preferenciais
    printf("Atendimento preferencial:\n");
    while (desenfileirar(&preferencial, nome, &idade)) {
        printf("Atendendo: %s (%d anos)\n", nome, idade);
    }
    
    // Atendendo normais
    printf("\nAtendimento normal:\n");
    while (desenfileirar(&normal, nome, &idade)) {
        printf("Atendendo: %s (%d anos)\n", nome, idade);
    }
}

int main() {
    Fila fila;
    inicializar(&fila);
    
    // Cadastrando pessoas (exemplo)
    enfileirar(&fila, "João", 25);
    enfileirar(&fila, "Maria", 65);
    enfileirar(&fila, "Carlos", 30);
    enfileirar(&fila, "Ana", 70);
    enfileirar(&fila, "Pedro", 40);
    
    atenderComPrioridade(&fila);
    
    return 0;
}

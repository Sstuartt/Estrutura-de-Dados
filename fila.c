#include <stdio.h>
#define TAMANHO 4

typedef struct {
    char documentos[TAMANHO][50];
    int inicio, fim;
    int contador;
} FilaCircular;

void inicializar(FilaCircular *f) {
    f->inicio = 0;
    f->fim = -1;
    f->contador = 0;
}

int enfileirar(FilaCircular *f, char documento[]) {
    if (f->contador == TAMANHO) {
        return 0; // fila cheia
    }
    
    f->fim = (f->fim + 1) % TAMANHO;
    strcpy(f->documentos[f->fim], documento);
    f->contador++;
    return 1;
}

int desenfileirar(FilaCircular *f, char documento[]) {
    if (f->contador == 0) {
        return 0; // fila vazia
    }
    
    strcpy(documento, f->documentos[f->inicio]);
    f->inicio = (f->inicio + 1) % TAMANHO;
    f->contador--;
    return 1;
}

int main() {
    FilaCircular impressora;
    char doc[50];
    
    inicializar(&impressora);
    
    // Adicionando documentos iniciais
    for (int i = 1; i <= TAMANHO; i++) {
        sprintf(doc, "Documento%d", i);
        enfileirar(&impressora, doc);
        printf("Adicionado: %s\n", doc);
    }
    
    printf("\nSimulando impressão:\n");
    for (int i = 0; i < 6; i++) { // 6 iterações de exemplo
        if (desenfileirar(&impressora, doc)) {
            printf("Imprimindo: %s\n", doc);
        }
        
        sprintf(doc, "NovoDoc%d", i+1);
        if (enfileirar(&impressora, doc)) {
            printf("Adicionado à fila: %s\n", doc);
        }
    }
    
    return 0;
}

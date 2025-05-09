#include <stdio.h>
#include <string.h>
#define MAX 5
#define TAM_URL 50

typedef struct {
    char urls[MAX][TAM_URL];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int empilhar(Pilha *p, char url[]) {
    if (p->topo == MAX-1) {
        return 0; // pilha cheia
    }
    p->topo++;
    strcpy(p->urls[p->topo], url);
    return 1;
}

int desempilhar(Pilha *p, char url[]) {
    if (p->topo == -1) {
        return 0; // pilha vazia
    }
    strcpy(url, p->urls[p->topo]);
    p->topo--;
    return 1;
}

int main() {
    Pilha navegador;
    char url[TAM_URL];
    int i;
    
    inicializar(&navegador);
    
    printf("Digite 5 URLs visitadas:\n");
    for (i = 0; i < MAX; i++) {
        printf("URL %d: ", i+1);
        scanf("%s", url);
        empilhar(&navegador, url);
    }
    
    printf("\nVoltando às páginas anteriores:\n");
    while (desempilhar(&navegador, url)) {
        printf("Voltando para: %s\n", url);
    }
    
    return 0;
}

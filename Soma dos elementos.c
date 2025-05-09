#include <stdio.h>

#define TAMANHO 10

int main() {
    int numeros[TAMANHO];
    int soma = 0;

    for (int i = 0; i< TAMANHO; i++) {
        printf("Digite o %dº número inteiro: ", i + 1);
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }
    printf("A soma dos elementos é: %d\n", soma);
    return 0;
}

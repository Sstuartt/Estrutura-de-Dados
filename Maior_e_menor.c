#include <stdio.h>

#define TAMANHO 6

int main() {
    int numeros[TAMANHO];
    
    // Recebendo os valores do usuário
    for (int i = 0; i < TAMANHO; i++) {
        printf("Digite o %dº número inteiro: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    // Encontrando o maior e menor valor e suas posições
    int maior = numeros[0];
    int menor = numeros[0];
    int posMaior = 0;
    int posMenor = 0;
    
    for (int i = 1; i < TAMANHO; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
            posMaior = i;
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
            posMenor = i;
        }
    }
    
    printf("Maior valor: %d (posição: %d)\n", maior, posMaior);
    printf("Menor valor: %d (posição: %d)\n", menor, posMenor);
    
    return 0;
}

#include <stdio.h>

#define MAX 10  // Definido para 10 para armazenar 10 valores

int pilha[MAX];
int topo = -1;

void empilhar(int valor) {
    if (topo < MAX - 1) {
        topo++;
        pilha[topo] = valor;
        printf("Você empilhou: %d\n", valor);
    } else {
        printf("A pilha está cheia\n");
    }
}

void desempilhar() {
    if (topo >= 0) {
        printf("Você desempilhou %d\n", pilha[topo]);
        topo--;
    } else {
        printf("A pilha está vazia\n");
    }
}

void exibirPilha() {
    if (topo >= 0) {
        printf("Na pilha tem: ");
        for (int i = 0; i <= topo; i++) {
            printf("%d ", pilha[i]);
        }
        printf("\n");
    } else {
        printf("Pilha está vazia\n");
    }
}

void ordenarPilha() {
    int aux[MAX];
    int temp;
    int n = topo + 1;

    // Copia os elementos da pilha para um array auxiliar
    for (int i = 0; i < n; i++) {
        aux[i] = pilha[i];
    }

    // Ordena o array auxiliar usando um algoritmo simples, como bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (aux[j] > aux[j + 1]) {
                temp = aux[j];
                aux[j] = aux[j + 1];
                aux[j + 1] = temp;
            }
        }
    }

    // Copia o array ordenado de volta para a pilha
    for (int i = 0; i < n; i++) {
        pilha[i] = aux[i];
    }

    printf("Pilha ordenada em ordem crescente!\n");
}

int main() {
    int valor;

    printf("Digite 10 valores para empilhar:\n");
    for (int i = 0; i < 10; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        empilhar(valor);
    }

    printf("\nPilha antes da ordenação:\n");
    exibirPilha();

    ordenarPilha();

    printf("\nPilha após a ordenação:\n");
    exibirPilha();

    return 0;
}
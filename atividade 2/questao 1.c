#include <stdio.h>

#define MAX 3

int pilha[MAX];
int topo = -1;

void empilhar(int valor) {
    if (topo < MAX - 1) {
        topo++;
        pilha[topo] = valor;
        printf("voce empilhou: %d\n", valor);
    } else {
        printf("a pilha esta cheia\n");
    }
}

void desempilhar() {
    if (topo >= 0) {
        printf("voce desempilhou %d\n", pilha[topo]);
        topo--;
    } else {
        printf("a pilha esta vazia\n");
    }
}

void exibirPilha() {
    if (topo >= 0) {
        printf("na pilha tem: ");
        for (int i = 0; i <= topo; i++) {
            printf("%d ", pilha[i]);
        }
        printf("\n");
    } else {
        printf("pilha ta vazia\n");
    }
}

int main() {
    int opcao, valor;

    do {
        printf("\n1. Empilhar\n2. Desempilhar\n3. Mostrar pilha\n4. Sair\n");
        printf("escolhe ai: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("valor pra empilhar: ");
                scanf("%d", &valor);
                empilhar(valor);
                break;
            case 2:
                desempilhar();
                break;
            case 3:
                exibirPilha();
                break;
            case 4:
                printf("falou\n");
                break;
            default:
                printf("opcao invalida tenta de novo\n");
        }
    } while (opcao != 4);

    return 0;
}
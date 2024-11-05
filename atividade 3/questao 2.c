#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
};

struct No* criarNo(int valor) {
    struct No *novo = (struct No*)malloc(sizeof(struct No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

struct No* inserir(struct No *raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

void mostrarArvore(struct No *raiz) {
    if (raiz != NULL) {
        mostrarArvore(raiz->esquerda);
        printf("%d ", raiz->valor);
        mostrarArvore(raiz->direita);
    }
}

void espelho(struct No *raiz) {
    if (raiz != NULL) {
        struct No *temp = raiz->esquerda;
        raiz->esquerda = raiz->direita;
        raiz->direita = temp;
        espelho(raiz->esquerda);
        espelho(raiz->direita);
    }
}

int main() {
    struct No *raiz = NULL;
    int numeros[10], i, numero;

    printf("insira 10 numeros inteiros:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
        raiz = inserir(raiz, numeros[i]);
    }

    printf("arvore binaria na ordem:\n");
    mostrarArvore(raiz);
    printf("\n");

    espelho(raiz);

    printf("arvroer binaria espelhada:\n");
    mostrarArvore(raiz);
    printf("\n");

    return 0;
}
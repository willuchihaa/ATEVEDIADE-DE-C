#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
};

void mostrarArvore(struct No *raiz) {
    if (raiz != NULL) {
        mostrarArvore(raiz->esquerda);
        printf("%d ", raiz->valor);
        mostrarArvore(raiz->direita);
    }
}

struct No* criarNo(int valor) {
    struct No *novo = (struct No*)malloc(sizeof(struct No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

struct No* inicializaArvore() {
    return NULL;
}

struct No* buscar(struct No *raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }
    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    }
    return buscar(raiz->direita, valor);
}

int taVazia(struct No *raiz) {
    return raiz == NULL;
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

struct No* remover(struct No *raiz, int valor) {
    if (raiz == NULL) return NULL;
    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        }
    }
    return raiz;
}

int main() {
    struct No *raiz = inicializaArvore();
    int numeros[10], i, numero;

    printf("digite 10 numeros inteiros para inserir:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
        raiz = inserir(raiz, numeros[i]);
    }

    printf("arvore binaria na ordem:\n");
    mostrarArvore(raiz);
    printf("\n");

    printf("digite um numero pra buscar:\n");
    scanf("%d", &numero);
    struct No *encontrado = buscar(raiz, numero);
    if (encontrado) {
        printf("Numero %d encontrado.\n", numero);
    } else {
        printf("Numero %d nao encontrado.\n", numero);
    }

    printf("digite um numero pra retirar (so se for folha):\n");
    scanf("%d", &numero);
    raiz = remover(raiz, numero);

    printf("esta arvore binaria depois da remocao:\n");
    mostrarArvore(raiz);
    printf("\n");

    return 0;
}
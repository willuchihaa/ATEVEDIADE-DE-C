#include <stdio.h>
#include <stdlib.h>


struct Nodo {
    int valor; 
    struct Nodo *esq, *dir; 
};

struct Nodo* inserir(struct Nodo* a, int x) {
    if (a == NULL) {
        struct Nodo* novo = (struct Nodo*)malloc(sizeof(struct Nodo)); 
        novo->valor = x;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (x < a->valor)
        a->esq = inserir(a->esq, x); 
    else
        a->dir = inserir(a->dir, x); 
    return a;
}

struct Nodo* busca(struct Nodo* a, int x) {
    if (a == NULL || a->valor == x)
        return a;
    if (x < a->valor)
        return busca(a->esq, x); 
    return busca(a->dir, x); 
}

struct Nodo* menor(struct Nodo* a) {
    struct Nodo* temp = a;
    while (temp && temp->esq != NULL)
        temp = temp->esq;
    return temp;
}

struct Nodo* removeNodo(struct Nodo* a, int x) {
    if (a == NULL) return a;

    if (x < a->valor)
        a->esq = removeNodo(a->esq, x); 
    else if (x > a->valor)
        a->dir = removeNodo(a->dir, x); 
    else {
        if (a->esq == NULL) {
            struct Nodo* temp = a->dir; 
            free(a);
            return temp;
        }
        else if (a->dir == NULL) {
            struct Nodo* temp = a->esq; 
            free(a);
            return temp;
        }

        struct Nodo* temp = menor(a->dir); 
        a->valor = temp->valor; 
        a->dir = removeNodo(a->dir, temp->valor); 
    }
    return a;
}


void imprimir(struct Nodo* a) {
    if (a != NULL) {
        imprimir(a->esq); 
        printf("%d ", a->valor); 
        imprimir(a->dir); 
    }
}

int main() {
    struct Nodo* raiz = NULL;
    int opcao, valor;

    do {
        printf("\n1. inserir numero\n2. buscar numero\n3. remover numeri\n4. imprimir arvore\n5. Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("digite o valor: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            break;
        case 2:
            printf("dejea buscar qual valor? ");
            scanf("%d", &valor);
            if (busca(raiz, valor) != NULL)
                printf("valor %d encontrado.\n", valor);
            else
                printf("esse valor nao existe %d.\n", valor);
            break;
        case 3:
            printf("deseja remover qual valor? ");
            scanf("%d", &valor);
            raiz = removeNodo(raiz, valor); 
            break;
        case 4:
            printf("arvore completa: ");
            imprimir(raiz); 
            printf("\n");
            break;
        case 5:
            printf("voce saiu\n");
            break;
        default:
            printf("insira uma opcao valida\n");
        }
    } while (opcao != 5);

    return 0;
}

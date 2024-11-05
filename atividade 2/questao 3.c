#include <stdio.h>
#include <string.h>

#define MAX_VINHOS 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int safra;
} Vinho;

typedef struct {
    Vinho vinhos[MAX_VINHOS];
    int total;
} Adega;

void inicializarAdega(Adega *adega) {
    adega->total = 0;
}

void adicionarVinho(Adega *adega) {
    if (adega->total < MAX_VINHOS) {
        printf("digite o nome do vinho: ");
        fgets(adega->vinhos[adega->total].nome, MAX_NOME, stdin);
        adega->vinhos[adega->total].nome[strcspn(adega->vinhos[adega->total].nome, "\n")] = '\0';
        
        printf("gigite a safra do vinho: ");
        scanf("%d", &adega->vinhos[adega->total].safra);
        getchar(); // Limpa o buffer do teclado
        
        adega->total++;
    } else {
        printf("a adega esta cheia não é possível adicionar mais vinhos.\n");
    }
}

void vinhoParaOcasiãoEspecial(Adega *adega) {
    if (adega->total > 0) {
        Vinho *v = &adega->vinhos[adega->total - 1];
        printf("o vinho para a ocasião especial é: %s (safra %d)\n", v->nome, v->safra);
    } else {
        printf("não há vinhos na adega!\n");
    }
}

void listarCincoMaisAntigos(Adega *adega) {
    printf("ainco vinhos mais antigos:\n");
    for (int i = 0; i < 5 && i < adega->total; i++) {
        printf("%s (safra %d)\n", adega->vinhos[i].nome, adega->vinhos[i].safra);
    }
}

int main() {
    Adega adega;
    inicializarAdega(&adega);

    int opcao;
    do {
        printf("\n1. adicionar vinho\n");
        printf("2. ver vinho para ocasião especial\n");
        printf("3. listar cinco vinhos mais antigos\n");
        printf("4. sair\n");
        printf("escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch(opcao) {
            case 1:
                adicionarVinho(&adega);
                break;
            case 2:
                vinhoParaOcasiãoEspecial(&adega);
                break;
            case 3:
                listarCincoMaisAntigos(&adega);
                break;
            case 4:
                printf("saindo...\n");
                break;
            default:
                printf("opção inválida! tente novamente.\n");
        }
    } while(opcao != 4);

    return 0;
}
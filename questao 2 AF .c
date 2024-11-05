#include <stdio.h>
#include <string.h>

#define MAX_VEICULOS 25
#define PLACA_TAMANHO 8

char estacionamento[MAX_VEICULOS][PLACA_TAMANHO];
int total_veiculos = 0; 

void mostra_veiculos(); 

void entrar_veiculo() {
    if (total_veiculos >= MAX_VEICULOS) {
        printf("d estacionamento esta cheio!\n");
    } else {
        char placa[PLACA_TAMANHO];
        printf("digite a placa do veiculo (7 letras/numeros): ");
        scanf(" %s", placa);

        strcpy(estacionamento[total_veiculos], placa);
        total_veiculos++;
        printf("veiculo com placa %s foi guardado com sucesso\n", placa);
    }
}

void remove_veiculo() {
    if (total_veiculos == 0) {
        printf("o estacionamento nao possui carrios\n");
        return;
    }

    char placa_remover[PLACA_TAMANHO];
    printf("qual a placa do carro deseja tirar? ");
    scanf("%s", placa_remover);

    int achei = 0;
    for (int i = 0; i < total_veiculos; i++) {
        if (strcmp(estacionamento[i], placa_remover) == 0) {
            achei = 1;
            for (int j = i; j < total_veiculos - 1; j++) {
                strcpy(estacionamento[j], estacionamento[j + 1]);
            }
            total_veiculos--;
            printf("veiculo com placa %s removido com sucesso\n", placa_remover);
            break;
        }
    }

    if (!achei) {
        printf("veiculo com placa %s nao disponivel no estacionamento\n", placa_remover);
    }
}

void mostra_veiculos() { 
    if (total_veiculos == 0) {
        printf("o estacionamento esta vazio\n");
    } else {
        printf("veiculos totais (o ultimo mais proximo do portao):\n");
        for (int i = total_veiculos - 1; i >= 0; i--) {
            printf("%d. %s\n", total_veiculos - i, estacionamento[i]);
        }
    }
}

int main() {
    int opcao; 

    do {
        printf("\n------- Menu de opçoes-------\n");
        printf("1. Entrar novo carro\n");
        printf("2. Ver carros no estacionamento\n");
        printf("3. Tirar um carro\n");
        printf("4. Sair\n");
        printf("Escolhe uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                entrar_veiculo();
                break;
            case 2:
                mostra_veiculos();
                break;
            case 3:
                remove_veiculo();
                break;
            case 4:
                printf("Ate logo, volte sempre!\n");
                break;
            default:
                printf("Opcao incorreta, tenta novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}

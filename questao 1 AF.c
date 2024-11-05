#include <stdio.h>
#include <string.h>

#define TOTAL_CANDIDATOS 60
#define AMPLA_CONCORRENCIA 45
#define PCD 3
#define NEGROS 12

int main() {
    
    int ac_indice = 0, pcd_indice = 0, negro_indice = 0, convocacao_indice = 0;
    int i;

    char ampla_concorencia[AMPLA_CONCORRENCIA][50];
    char pcd[PCD][50];
    char negro[NEGROS][50];
    char ordem_convocacao[TOTAL_CANDIDATOS][50];
    
    printf("Insira o nome dso 45 candidatos de ampla concorrencia:\n");
    for (i = 0; i < AMPLA_CONCORRENCIA; i++) {
        printf("Canditado %d: ", i + 1);
        scanf(" %[^\n]%*c", ampla_concorencia[i]); 
    }

    printf("\nInsira os nome dos 3 candidatos (PCD):\n");
    for (i = 0; i < PCD; i++) {
        printf("Candidato PCD %d: ", i + 1);
        scanf(" %[^\n]%*c", pcd[i]);
    }

    printf("\nInsira os 12 nomes dos candidatos negros:\n");
    for (i = 0; i < NEGROS; i++) {
        printf("Candidato negro %d: ", i + 1);
        scanf(" %[^\n]%*c", negro[i]);
    }

    for (i = 1; i <= TOTAL_CANDIDATOS; i++) {
        if (i == 5 || (i > 5 && (i - 5) % 20 == 0)) {
            if (pcd_indice < PCD) {
                strcpy(ordem_convocacao[convocacao_indice++], pcd[pcd_indice++]);
            } else {
                strcpy(ordem_convocacao[convocacao_indice++], ampla_concorencia[ac_indice++]);
            }
        } else if (i == 3 || (i > 3 && (i - 3) % 5 == 0)) {
            if (negro_indice < NEGROS) {
                strcpy(ordem_convocacao[convocacao_indice++], negro[negro_indice++]);
            } else {
                strcpy(ordem_convocacao[convocacao_indice++], ampla_concorencia[ac_indice++]);
            }
        } else {
            strcpy(ordem_convocacao[convocacao_indice++], ampla_concorencia[ac_indice++]);
        }
    }

    printf("\nA ordem de chamada sera:\n");
    for (i = 0; i < TOTAL_CANDIDATOS; i++) {
        printf("%d. %s\n", i + 1, ordem_convocacao[i]);
    }

    return 0;
}

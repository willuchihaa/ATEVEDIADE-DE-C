#include <stdio.h>

int main() {
  int jogadores = 15;

  int oitavas = jogadores;
  int quartas = jogadores - 8;
  int semiFinais = quartas - 4;
  int finais = semiFinais - 2;

  int i;

  for (i = 0; i < jogadores; i++) {
    int escolha;

    printf("Digite a categoria que deseja ver:\n1 - Oitavas\n2 - Quartas\n3 - Semi-finais\n4 - Finais\n");
    scanf("%d", &escolha);

    switch (escolha) {
      case 1:
        if (oitavas) {
          printf("Zhao e Liu ganham de seus oponentes.\n");
        } else {
          printf("Categoria inválida.\n");
        }
        break;
      case 2:
        if (quartas) {
          printf("Zhao e Liu ganham novamente.\n");
        } else {
          printf("Categoria inválida.\n");
        }
        break;
      case 3:
        if (semiFinais) {
          printf("O grande confronto dos 2 maiores começa, Zhao vs Liu!\n");
        } else {
          printf("Categoria inválida.\n");
        }
        break;
      case 4:
        if (finais) {
          printf("Não sei quem ganha...\n");
        } else {
          printf("Categoria inválida.\n");
        }
        break;
      default:
        printf("Digite uma categoria válida.\n");
        break;
    }
  }

  return 0;
}
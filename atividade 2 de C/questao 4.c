#include <stdio.h>

int main() {
  int candidatos = 4;
  int votosCandidatos[candidatos];
  int votoNulo[3];
  int votoBranco[3];
  int totalVotos = 0;
  int nulosEbrancos = 0;

  for (int i = 0; i < candidatos; i++) {
    int voto;
    printf("1, 2, 3, 4: Votos para os candidatos\n5: para votar nulo\n6: para votar em branco\nOque voce vai fazer? ");
    scanf("%d", &voto);
    if (voto >= 1 && voto <= 4) {
      printf("voce votou no candidato %d!\n", voto);
      votosCandidatos[i]++;
      totalVotos++;
    } else if (voto == 5) {
      printf("voce votou nulo.\n");
      totalVotos++;
    } else if (voto == 6) {
      printf("voce votou em branco.\n");
      votoBranco[nulosEbrancos]++;
      totalVotos++;
    } else {
      printf("\033[31mOPÇÃO INVÁLIDA\nVOSE VAI VOTAR SIM!\n");
    }
  }
  nulosEbrancos = (votoNulo[0] + votoBranco[0]);
  printf("os votos dos candidatos são: ");
  for (int i = 0; i < candidatos; i++) {
    printf("%d ", votosCandidatos[i]);
  }
  printf("\n");
  printf("os votos nulos são: %d\n", votoNulo[0]);
  printf("a porcentagem de votos nulos e brancos é: %d%%\n", nulosEbrancos);

  return 0;
}

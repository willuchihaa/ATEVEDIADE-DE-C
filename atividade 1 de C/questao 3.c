#include <stdio.h>

int main()
{
#include <stdio.h>

int main() {
  int quadra1pt = 1;
  int quadra2pt = 2;
  int quadra3pt = 3;
  int distancia = 3;
  int i;

  for (i = 0; i < distancia; i++) {
    int perg;

    printf("Digite a distância para marcar: ");
    scanf("%d", &perg);

    if (perg == quadra1pt) {
      printf("Você fez 1 ponto...");
    } 
    else if (perg == quadra2pt) 
    {
      printf("Você fez 2 pontos!");
    } 
    else if (perg == quadra3pt) {
      printf("Você fez 3 pontos!\n");
    } 
    else {
      printf("Você acertou na tabela!\n");
    }
  }

  return 0;
}


    return 0;
}
#include <stdio.h>

int main() {
  float chico = 1.50;
  float ze = 1.10;
  float crescimentoDochico = 0.02;
  float crescimentoDoZe = 0.03;
  float diferencaDeAltura = chico - ze;
  int anosNecessarios = (int)(diferencaDeAltura / (crescimentoDoZe - crescimentoDochico));
  printf("Zé fica maior que Chico em %d anos\n", anosNecessarios);
  return 0;
}
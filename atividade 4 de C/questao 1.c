#include <stdio.h>

void descobrirIdade() {
  int aaa = 4;
  int i;

  for (i = 0; i < aaa; i++) {
    int idade;

    printf("digite sua idade e daremos sua categoria: ");
    scanf("%d", &idade);

    if (idade <= 4) {
      printf("a idade minima é 5 anos\n");
    } 
    else if (idade >= 5 && idade < 8) {
      printf("sua categoria é infantil A\n");
    } 
    else if (idade >= 8 && idade < 11) {
      printf("sua categoria é infantil B\n");
    } 
    else if (idade >= 10 && idade < 14) {
      printf("sua categoria é juvenil A\n");
    } 
    else if (idade >= 14 && idade < 18) {
      printf("sua categoria é juvenil B\n");
    } 
    else if (idade >= 18) {
      printf("tu é véi... brincadeira, sua categoria é adulto\n");
    } 
    else {
      printf("digite somente valores validos\n");
    }
  }
}
int main() {
  descobrirIdade();
  return 0;
}
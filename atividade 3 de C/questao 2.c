#include <stdio.h>

int main() {
  int i, aaa = 3;
  char palavra[100], texto_invertido[100];

  for (i = 0; i < aaa; i++) {
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    int e, len = strlen(palavra);
    for (e = 0; e < len; e++) {
      texto_invertido[e] = palavra[len - e - 1];
    }
    texto_invertido[len] = '\0';
    if (strcmp(palavra, texto_invertido) == 0) {
      printf("%s é palíndromo\n", palavra);
    } else {
      printf("%s não é palíndromo\n", palavra);
    }
  }

  return 0;
}

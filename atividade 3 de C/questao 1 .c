#include <stdio.h>

char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";

char codificarCaractere(char letra, int n) {
  int posicaoLetra = strchr(alfabeto, letra) - alfabeto;
  int novaPosicao = (posicaoLetra + n) % strlen(alfabeto);
  return alfabeto[novaPosicao];
}

char *codificarTexto(char *texto, int n) {
  char *textoCodificado = malloc(strlen(texto) + 1);
  int i;
  for (i = 0; i < strlen(texto); i++) {
    if (strchr(alfabeto, texto[i])) {
      textoCodificado[i] = codificarCaractere(texto[i], n);
    } else {
      textoCodificado[i] = texto[i];
    }
  }
  textoCodificado[i] = '\0';
  return textoCodificado;
}

int main() {
  char frase[100];
  int n = 3;

  printf("Digite uma frase: ");
  scanf("%s", frase);

  char *textoCodificado;

 textoCodificado = codificarTexto(frase, n);

  printf("Frase original: %s\n", frase);
  printf("Frase codificada: %s\n", textoCodificado);

  free(textoCodificado);

  return 0;
}
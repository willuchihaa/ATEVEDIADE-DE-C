#include <stdio.h>

int main() {

  float vista = 0;
  float prazo = 0;
  float total = 0;
  float primeiraPrestacao = 0;

  for (int i = 1; i <= 15; i++) {
    char codigo[2];
    float valor;
    printf("a compra sera em (P)prazo ou (V)vista? %d ", i);
    scanf("%s", codigo);
    printf("Digite o valor da transação %d: R$ ", i);
    scanf("%f", &valor);


    if (codigo[0] == 'V') {
      vista += valor;
    }
      else if (codigo[0] == 'P') {
      prazo += valor;
      primeiraPrestacao += valor / 3.0f;
  }

  total = vista + prazo;
  printf("compras à vista: R$ %.2f\n ", vista);
  printf("compras a prazo: R$ %.2f\n ", prazo);
  printf("total das compras: R$ %.2f\n ", total);
  printf("valor da primeira prestação: R$ %.2f\n ", primeiraPrestacao);

  return 0;
  }
}
questao2.c
Exibindo questao2.c…
Atividade 2 - Estruturas de Repetição
Raphael Torres Santos Carvalho
•
8 de fev. (editado: 8 de fev.)
35
/100
35 pontos de 100 possíveis
Data de entrega: 15 de fev.

Atividade 2 - Exercícios básicos - Estrutura de Repetição.pdf
PDF
Comentários da turma

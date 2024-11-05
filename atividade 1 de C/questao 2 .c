
#include <stdio.h>
#include <stdlib.h>

int main() {
  int valorCompra;
  int pergCompras;
  int valorTotal;
  float valorParcelas;

  printf("qual o valor da compra? ");
  scanf("%d", &valorCompra);

  printf(" quer parcelar em quantas vezes? ");
  scanf("%d", &pergCompras);

  if (pergCompras < 1 || pergCompras > 18) {
    printf("diga um valor de parcels valido \n");
    return 1;
  }
  
  valorTotal = valorCompra + pergCompras;
  valorParcelas = (float) valorTotal / pergCompras;

  printf("a parcela ficou de %.2f\n", valorParcelas);
  return 0;
}
#include <stdio.h>

void descobir(float alt, char sexo) {
    float pesoF, pesoM;
    
    pesoF = (62.1 * alt) - 44.7;
    pesoM = (72.7 * alt) - 58;

    if (sexo == 'M') {
        printf("o peso ideal do home é: %.2f quilos\n", pesoM);
    } 
    else if (sexo == 'F') {
        printf("o peso ideal da mulher é: %.2f quilos\n", pesoF);
    }
    else {
      printf("diga um valor valido");
    }
}

int main() {
    descobir(1.60, 'F');
    return 0;
}
#include <stdio.h>

void receberNota(float nota1, float nota2, float nota3) {
    float resultadoA, resultadoP;
    resultadoA = (nota1 + nota2 + nota3) / 3;
    resultadoP = ((5 * nota1) + (3 * nota2) + (2 * nota3)) / (5 + 3 + 2);

    char subRotina;
    printf("Qqual é a sua classe? (A ou B): ");
    scanf(" %c", &subRotina);

    if (subRotina == 'A') {
        printf("a media aritimetica é: %.2f\n", resultadoA);
    } 
    else if (subRotina == 'B') {
        printf("a media ponderada é: %.2f\n", resultadoP);
    } 
    else {
        printf("digitw um valor valido...\n");
    }
}
int main() {
    receberNota(6.3, 5.5, 8.5); 
    return 0;
}
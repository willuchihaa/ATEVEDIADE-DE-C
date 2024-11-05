#include <stdio.h>

int funcRecursiva(int k, int n) {
    int Resultado = 1;

    for (int i = 0; i < n; i++) {
        Resultado *= k;
    }
    return Resultado;
}
int main() {
    int resultado = funcRecursiva(5, 2);
    printf(" %d\n", resultado);
    return 0;
}

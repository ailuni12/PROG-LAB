#include <stdio.h>

void pedirdatos();

int main() {

    printf("Ingrese un valor: ");
    pedirdatos();

    return 0;
}

void pedirdatos() {
    int valor;
    
    scanf("%d",&valor);
    printf("Valor ingresado: %d", valor);
}


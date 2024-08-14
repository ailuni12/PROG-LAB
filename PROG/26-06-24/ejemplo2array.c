#include <stdio.h>

int main() {
    char nombre[30];

    printf("Ingrese su nombre:\n");
    scanf("%s",&nombre[0]);
    printf("Hola, %s", nombre);

    return 0;
}
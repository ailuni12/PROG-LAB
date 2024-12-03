#include <stdio.h>
#include <string.h>

#define MAX_CHAR 50

int main (void) {
    char txt[MAX_CHAR];
    int cantidadLetras=0;

    printf("Ingrese un texto:\n");
    scanf("%s",txt);

    cantidadLetras=strlen(txt);

    printf("Texto ingresado: %s\n",txt);
    printf("Cantidad de caracteres ingresados: %d",cantidadLetras);

    return 0;
}
#include <stdio.h>
#define MAX_CHAR 50

int cuentaLetras(char []); //no hace falta el nombre del vector, con indicar las llaves alcanza

int main (void) {
    char txt[MAX_CHAR];
    int cantidadLetras=0;

    printf("Ingrese un texto:\n");
    scanf("%s",txt);

    cantidadLetras=cuentaLetras(txt);

    printf("Texto ingresado: %s\n",txt);
    printf("Cantidad de caracteres ingresados: %d",cantidadLetras);

    return 0;
}

int cuentaLetras(char palabra[]){
    int i = 0;

    for(i=0;palabra[i]!='\0';i++);

    return i;
}
#include <stdio.h>
#include "saludar.h"

// gcc nombredearchivo.c -o nombredearchivo.exe
// compila el archivo c en el archivo exe especificado
// .\programa.exe ejecuta el archivo dentro de VSC

// gcc -c archivo.c
// gcc -o archivo.exe archivo.o archivo2.o

//#ifdef condicion
//#elif
//#endif

//static void funcion(void): encapsula la funcion
//static int variable: mantiene el contenido de la variable,
//pero encapsulada dentro de la funcion donde se encuentra
//(no se puede utilizar fuera de la funcion)

//extern int variable; : variable definida en un archivo aparte,
//y no se puede modificar su contenido, solo leerlo.

void contar(void);

int main(void){
    contar();
    contar();
    contar();
    contar();

    return 0;
}

void contar(void){
    static int var=0;

    var++;
    printf("%d\n",var);
}
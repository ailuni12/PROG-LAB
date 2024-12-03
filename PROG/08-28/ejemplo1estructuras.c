#include <stdio.h>

#define MAX_CHAR 30

//una estructura no genera
//ningun nuevo espacio en
//la memoria, solo es una
//plantilla a rellenar.
struct puntos {
    int coordX;
    int coordY;
    char nombre[MAX_CHAR];
    int dist;
    int color;
    char simbolo;
}punto1={10,40,"punto1",3,6,'x'},punto2;

int main (void){
    printf("Valor guardado en coordX de punto1: %d",punto1.coordX);
    printf("Valor guardado en coordX de punto2: %d",punto2.coordX);

    return 0;
}
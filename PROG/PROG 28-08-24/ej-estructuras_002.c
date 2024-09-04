#include <stdio.h>

#define MAX_CHAR 30

typedef char caractercito;
typedef unsigned char uint8_t;
typedef int unNumero_t;

//encapsular informacion:
typedef struct {
    int coordX;
    int coordY;
    char nombre[MAX_CHAR];
    int dist;
    int color;
    char simbolo;
}punto_t;
//el nombre hace referencia a la estructura

int main (void){
    punto_t p001;
    //genera un nuevo punto, asi que solo
    //con "punto_t" se puede generar un elemento
    //a partir de la estructura declarada

    printf("Coordenada X de p001: %d",p001.coordX);

    return 0;
}
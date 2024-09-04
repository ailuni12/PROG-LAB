#include <stdio.h>

#define MAX_CHAR 30

typedef char caractercito;
typedef unsigned char uint8_t;
typedef int unNumero_t;

//encapsular informacion:
typedef struct {
    int simbolo;
}simbolo_t;

typedef struct {
    int coordX;
    int coordY;
    char nombre[MAX_CHAR];
    struct {
        int red;
        int green;
        int blue;
    } color;
    simbolo_t simbolo;
}punto_t;
//el nombre hace referencia a la estructura

int main (void){
    punto_t p001={10,5,"Punto 001",{255,255,255},{1}};

    printf("Coordenada X de p001: %d\n",p001.coordX);
    printf("valor rgb para color rojo: %d\n",p001.color.red);
    printf("Simbolo de p001: %c\n",p001.simbolo.simbolo);

    return 0;
}
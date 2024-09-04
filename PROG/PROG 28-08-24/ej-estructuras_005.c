#include <stdio.h>

#define MAX_CHAR 30

typedef char caractercito;
typedef unsigned char uint8_t;
typedef int unNumero_t;

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

void mostrar_punto(punto_t);
void cargar_punto(punto_t);
//recibe una copia de la estructura

int main (void){
    punto_t p001={10,5,"Punto 001",{255,255,255},{1}};

    punto_t puntos[200];
    //un vector con 200 elementos a partir de la estructura

    mostrar_punto(p001);
    mostrar_punto(puntos[1]);

    return 0;
}

void mostrar_punto(punto_t punto){
    
    printf("Coordenada X de p001: %d\n",punto.coordX);
    printf("valor rgb para color rojo: %d\n",punto.color.red);
    printf("Simbolo de p001: %c\n",punto.simbolo.simbolo);
}


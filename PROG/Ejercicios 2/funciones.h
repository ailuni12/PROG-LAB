#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VALUE 10
#define MIN_VALUE 0
#define TOPE 10

typedef enum{
    INICIO=0,
    SUMATORIA,
    SUSTRACCION,
    PRODUCTO_PUNTO,
    SALIDA
}opcion_t;

typedef struct{
    int coordX;
    int coordY;
}coordenadas_t;

typedef struct{
    char nombre[2];
    coordenadas_t coord_A;
    coordenadas_t coord_B;
}vector_t;


int numero_aleatorio (int, int);
int ordenar_vector (int[]);

int numero_aleatorio (int max, int min){
    int resultado=0;

    srand(time(NULL));
    resultado=rand()%(max-min+1)+min;

    return resultado;
}

int ordenar_vector (int vector[]){
    //ordena de mayor a menor
    int i, j, aux;

    for(i=0;i<TOPE;i++){
        for(j=0;j<TOPE-i-1;j++){
            if(vector[j]<vector[j+1]){
                aux=vector[j];
                vector[j]=vector[j+1];
                vector[j+1]=aux;
            }
        }
    }

    return 0;
}


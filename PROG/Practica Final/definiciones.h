#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int numero_aleatorio (int, int);

typedef struct {
    uint16_t codigo;
    char nombre[50];
    //uint16_t cantidad;
    //float precio;
}producto_t;

typedef enum{
    INGRESO=1,
    SALIDA
}menu_t;

int numero_aleatorio(int max, int min){
    return rand()%(max-min+1)+min;
}

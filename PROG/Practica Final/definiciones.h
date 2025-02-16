#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_CLI 3
#define MAX_ROW 3
#define MAX_COL 3

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



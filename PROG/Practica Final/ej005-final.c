#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "herramientas.h"
#include "estructuras.h"

void menu(alumno_t [][MAX_COL]);

int main(void){
    alumno_t alumnos[MIN_ROW][MAX_COL];

    srand(time(NULL));

    return 0;
}

void menu(alumno_t alumnos[][MAX_COL]){
    int op=0;
    int input_usuario=0;

    do{
        printf("\n||| REGISTRO DE ALUMNOS |||\n");
        printf("\nSeleccione una opcion:");
        printf("\n[1] Mostrar lista.");
        printf("\n[2] Registrar alumno nuevo.");
        printf("\n[3] Borrar alumno.");
        printf("\n[4] Ordenar lista.");
        printf("\n[%d] Finalizar.",salida);
        scanf("%d",&op);

        
    }while(op!=salida);
}
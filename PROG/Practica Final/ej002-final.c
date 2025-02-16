#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "definiciones.h"

#define MAX_CLI 3
#define MAX_ROW 3
#define MAX_COL 3
#define min 1000
#define max 3000

void fill_array(producto_t [][MAX_COL]);
void mostrar_estanteria(producto_t [][MAX_COL]);
void mostrar_tabla(producto_t [][MAX_COL]);

int main(void){
    srand(time(NULL)); //always call srand in main to refresh seed properly
    producto_t inventario[MAX_ROW][MAX_COL];

    fill_array(inventario);
    mostrar_estanteria(inventario);
    mostrar_tabla(inventario);

    return 0;
}

void fill_array(producto_t inventario[][MAX_COL]){

    for(int i=0;i<MAX_ROW;i++){
        for(int j=0;j<MAX_COL;j++){
            inventario[i][j].codigo=(numero_aleatorio(max,min));
            strcpy(inventario[i][j].nombre,"N/A");
        }
    }
    
}

void mostrar_estanteria(producto_t inventario[][MAX_COL]){

    printf("\n|  UBICACION | CODIGO | PRODUCTO      |\n");
    for(int i=0;i<MAX_ROW;i++){
        for(int j=0;j<MAX_COL;j++){
            printf("|   [%d][%d]   ",(i+1),(j+1));
            printf("| %6d ",inventario[i][j].codigo);
            printf("| %-13s |\n",inventario[i][j].nombre);
        }
    }
}

void mostrar_tabla(producto_t inventario[][MAX_COL]){
    printf("\n  |       1       |       2       |       3       |\n");
    printf("  --------------------------------------------------\n");
    for(int i=0;i<MAX_ROW;i++){
        printf("%d",(i+1));
        for(int j=0;j<MAX_COL;j++){
            printf(" |   %6d     ",inventario[i][j].codigo);
        }
        printf(" |\n");
        for(int h=0;h<MAX_COL;h++){
            printf("  | %-11s ",inventario[i][h].nombre);
        }
        printf("  |\n");
        printf("  --------------------------------------------------\n");
    }

}
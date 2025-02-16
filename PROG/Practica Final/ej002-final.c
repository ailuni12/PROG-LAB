#include <stdio.h>
#include <stdint.h>
#include "definiciones.h"

void fill_array(producto_t [][MAX_COL]);
void display_array(producto_t [][MAX_COL]);

int main(void){
    producto_t inventario[MAX_ROW][MAX_COL];

    fill_array(inventario);
    display_array(inventario);

    return 0;
}

void fill_array(producto_t inventario[][MAX_COL]){

    for(int i=0;i<MAX_ROW;i++){
        for(int j=0;j<MAX_COL;j++){
            inventario[i][j].codigo=0;
            strcpy(inventario[i][j].nombre,"N/A");
        }
    }
    
}

void display_array(producto_t inventario[][MAX_COL]){

    for(int i=0;i<MAX_ROW;i++){
        for(int j=0;j<MAX_COL;j++){
            printf("Fila %d Columna %d\n",i,j);
            printf("Codigo: %d\n",inventario[i][j].codigo);
            printf("Nombre: %s\n",inventario[i][j].nombre);
        }
    }
}
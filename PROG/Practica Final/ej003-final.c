#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include "herramientas.h"
#include "estructuras.h"

void menu(estructura_t [][MAX_COL],int *);
void fill_array(estructura_t [][MAX_COL]);
void print_array(estructura_t [][MAX_COL]);


int main(void){
    srand(time(NULL)); //time seed tiene que estar en main
    estructura_t array[MAX_ROW][MAX_COL];
    int counter=0;
    
    fill_array(array);
    menu(array,&counter);

    return 0;
}

void menu(estructura_t array[][MAX_COL],int *counter){
    int opcion=0;
    int opcion_submenu=0;
    int input_usuario=0;

    do{
        printf("\n***MENU DE NAVEGACION***\n");
        printf("\nSeleccione la opcion que desea:\n");
        printf("[1] Mostrar datos.\n");
        printf("[2] Generar datos nuevos.\n");
        printf("[3] Opcion 3.\n");
        printf("[4] Salir.\n");
        printf("\nOpcion: ");
        scanf("%d",&opcion);

        switch(opcion){
        case opcion1:
            print_array(array);
            break;
        case opcion2:
            fill_array(array);
            printf("\n***DATOS GENERADOS OK***\n");
            break;
        case opcion3:
            printf("\nOpcion 3.\n");
            standby();
            break;
        case salida:
            despedida();
            break;
        default:
            printf("\nIngreso una opcion invalida.");
            printf("\nIngrese nuevamente\n");
            printf("\nOpcion: ");
            scanf("%d",&opcion);

            if(opcion==4){
                despedida();
            }
            break;
        }
    } while(opcion!=salida);

}

void fill_array(estructura_t array[][MAX_COL]){
    for(int i=0;i<MAX_ROW;i++){
        for(int j=0;j<MAX_COL;j++){
            array[i][j].integer=numero_aleatorio(MAX_RAND,MIN_RAND);
            strcpy(array[i][j].string,"N/A");
            array[i][j].float_num=numero_aleatorio(MAX_RAND,MIN_RAND);
        }
    }
}

void print_array(estructura_t array[][MAX_COL]){
    printf("\n***DATOS GENERADOS***\n");
    printf("| ROW | COL | CODIGO | FLOAT   | ITEM |\n");
    printf("---------------------------------------\n");
    for(int i=0;i<MAX_ROW;i++){
        for(int j=0;j<MAX_COL;j++){
            printf("|  %d  |  %d  |  %04d  | %07.2f | %s  |\n",i,j,array[i][j].integer,array[i][j].float_num,array[i][j].string);
        }
        printf("---------------------------------------\n");
    }
    standby();
}


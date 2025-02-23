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
void save_item(estructura_t [][MAX_COL]);


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
        printf("[3] Guardar un item.\n");
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
            do{
                save_item(array);
                printf("\nDesea Guardar otro item?\nSI-1 NO-0: ");
                scanf("%d",&input_usuario);
            }while(input_usuario!=0);
            break;
        case salida:
            despedida();
            break;
        default:
            printf("\nIngreso una opcion invalida.");
            printf("\nIngrese nuevamente\n");
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
    printf("| ROW | COL | CODIGO | FLOAT   | ITEM\n");
    printf("---------------------------------------\n");
    for(int i=0;i<MAX_ROW;i++){
        for(int j=0;j<MAX_COL;j++){
            printf("|  %d  |  %d  |  %04d  | %07.2f | %s\n",i,j,array[i][j].integer,array[i][j].float_num,array[i][j].string);
        }
        printf("---------------------------------------\n");
    }
    standby();
}

void save_item(estructura_t array[][MAX_COL]){
    int row=0, col=0;

    do{
        printf("\nFila (%d a %d): ",MIN_ROW,MAX_ROW);
        scanf("%d",&row);

        if(row>MAX_ROW || row<MIN_ROW){
            printf("\nNumero invalido.\n");
        }
    }while(row>MAX_ROW || row<MIN_ROW);

    do{
        printf("\nColumna (%d a %d): ",MIN_COL,MAX_COL);
        scanf("%d",&col);

        if(col>MAX_COL || col<MIN_COL){
            printf("\nNumero invalido.\n");
        }
    }while(col>MAX_COL || col<MIN_COL);

    row-=1;
    col-=1;

    printf("\nNombre del item: ");
    fflush(stdin);
    fgets(array[row][col].string,sizeof(array[row][col].string),stdin);
    array[row][col].string[strcspn(array[row][col].string,"\n")]='\0';

    printf("\n***DATOS INGRESADOS***\n");
    printf("\n| Ubicacion: %d - %d | Item: %s\n",row+1,col+1,array[row][col].string);
}
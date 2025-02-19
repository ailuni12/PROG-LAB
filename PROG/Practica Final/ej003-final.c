#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include "herramientas.h"
#include "estructuras.h"

void menu();

int main(void){
    srand(time(NULL)); //time seed tiene que estar en main
    
    menu();

    return 0;
}

void menu(){
    int opcion=0;

    do{
        printf("\n***MENU DE NAVEGACION***\n");
        printf("\nSeleccione la opcion que desea:\n");
        printf("[1] Opcion 1.\n");
        printf("[2] Opcion 2.\n");
        printf("[3] Opcion 3.\n");
        printf("[4] Salir.\n");
        printf("\nOpcion: ");
        scanf("%d",&opcion);

        switch(opcion){
        case opcion1:
            printf("\nOpcion 1.\n");
            standby();
            break;
        case opcion2:
            printf("\nOpcion 2.\n");
            standby();
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


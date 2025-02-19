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

    printf("\n***MENU DE NAVEGACION***\n");
    printf("\nSeleccione la opcion que desea:\n");
    printf("[1] Opcion 1.\n");
    printf("[2] Opcion 2.\n");
    printf("[3] Opcion 3.\n");
    printf("[4] Salir.\n");
    printf("\nOpcion: ");
    scanf("%d",&opcion);

    do{
        switch(opcion){
        case 1:
            printf("\nOpcion 1.\n");
            standby();
            break;
        case 2:
            printf("\nOpcion 2.\n");
            standby();
            break;
        case 3:
            printf("\nOpcion 3.\n");
            standby();
            break;
        case 4:
            printf("\nGracias por usar la herramienta.");
            printf("\nPresione Enter para finalizar.\n");
            fflush(stdin);
            getchar();
            break;
        default:
            printf("\nIngreso una opcion invalida.\n");
            printf("\nIngrese nuevamente\n");
            printf("\nOpcion: ");
            scanf("%d",&opcion);
            break;
        }
    } while(opcion!=salida);

}


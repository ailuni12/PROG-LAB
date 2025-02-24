#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

#define MIN_FILA 1
#define MAX_FILA 3
#define MIN_COL 1
#define MAX_COL 3

typedef enum{
    opcion1=1,
    opcion2,
    opcion3,
    opcion4,
    salida
}menu_t;

typedef struct{
    int integer;
    char string[30];
    float float_num;  
}estructura_t;

int numero_aleatorio (int, int);
void standby(void);
void despedida(void);
void valor_incorrecto(void);
void menu(estructura_t [][MAX_COL]);

int numero_aleatorio(int min, int max){
    return rand()%(max-min+1)+min;
}

void standby(void){
    printf("\nPresione Enter para continuar.\n");
    fflush(stdin);
    getchar();
}

void despedida(void){
    printf("\nGracias por usar la herramienta.");
    printf("\nPresione Enter para finalizar.\n");
    fflush(stdin);
    getchar();
}

void valor_incorrecto(void){
    printf("\nIngreso un valor incorrecto.");
    printf("\nIngreselo nuevamente\n");
}

void menu(estructura_t matriz[][MAX_COL]){
    int opcion=0;
    int input_usuario=0;

    do{
        printf("\n***MENU DE NAVEGACION***\n");
        printf("\nSeleccione la opcion que desea:\n");
        printf("[1] Opcion 1.\n");
        printf("[2] Opcion 2.\n");
        printf("[3] Opcion 3.\n");
        printf("[3] Opcion 4.\n");
        printf("[%d] Salir.\n",salida);
        printf("\nOpcion: ");
        scanf("%d",&opcion);

        switch(opcion){
        case opcion1:
            break;
        case opcion2:
            break;
        case opcion3:
            break;
        case salida:
            despedida();
            break;
        default:
            valor_incorrecto();
            break;
        }
    } while(opcion!=salida);

}
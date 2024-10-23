#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"

#define MAX_V 2

int menu(void);
int sumatoria_vectores(vector_t[]);

int main(void){
    opcion_t opcion;
    vector_t vectores[MAX_V];

    printf("\n-------------OPERACIONES BASICAS CON VECTORES R2-------------\n");
    printf("\nAqui una introduccion.\n");

    do{
        opcion=menu();
        switch (opcion){
        case SUMATORIA:
            sumatoria_vectores(vectores);
            break;
        case SUSTRACCION:
            printf("\tfuncion resta vectores\n");
            break;
        case PRODUCTO_PUNTO:
            printf("\tproducto escalar entre vectores\n");
            break;
        case SALIDA:
            printf("\nGracias por utilizar la herramienta, presione Enter para finalizar.\n");
            fflush(stdin);
            getchar();
            break;
        default:
            printf("\nError. Ingrese un numero valido.\n");
            break;
        }
    }while(opcion!=SALIDA);

    return 0;
}

int menu(void){
    int op;

    printf("\n--------------------------------------------\n");
    printf("\nSeleccione la operacion que quiere realizar:\n");
    printf("\t[1] Sumar dos Vectores.\n");
    printf("\t[2] Restar dos Vectores.\n");
    printf("\t[3] Producto Escalar entre dos Vectores.\n");
    printf("\t[4] Finalizar\n");
    printf("Opcion seleccionada: ");
    scanf("%d",&op);

    return op;
}

int sumatoria_vectores(vector_t vectores[]){
    int i=0;
    int input=0;
    coordenadas_t vectorA, vectorB, resultado;

    printf("\nNombre del vector 1 (Ingrese una sola letra o numero): ");
    scanf("%1s",vectores[i].nombre);

    printf("\nIngrese las coord. X e Y del punto inicio.\n");
    printf("X: ");
    scanf("%d",&input);
    vectores[i].coord_A.coordX=input;
    printf("Y: ");
    scanf("%d",&input);
    vectores[i].coord_A.coordY=input;

    printf("\nIngrese las coord. X e Y del punto final.\n");
    printf("X: ");
    scanf("%d",&input);
    vectores[i].coord_B.coordX=input;
    printf("Y: ");
    scanf("%d",&input);
    vectores[i].coord_B.coordY=input;

    vectorA.coordX=vectores[i].coord_B.coordX-vectores[i].coord_A.coordX;
    vectorA.coordY=vectores[i].coord_B.coordY-vectores[i].coord_A.coordY;

    printf("\nNombre del vector 2 (Ingrese una sola letra o numero): ");
    scanf("%1s",vectores[i+1].nombre);

    printf("\nIngrese las coord. X e Y del punto inicio.\n");
    printf("X: ");
    scanf("%d",&input);
    vectores[i+1].coord_A.coordX=input;
    printf("Y: ");
    scanf("%d",&input);
    vectores[i+1].coord_A.coordY=input;

    printf("\nIngrese las coord. X e Y del punto final.\n");
    printf("X: ");
    scanf("%d",&input);
    vectores[i+1].coord_B.coordX=input;
    printf("Y: ");
    scanf("%d",&input);
    vectores[i+1].coord_B.coordY=input;

    vectorB.coordX=vectores[i+1].coord_B.coordX-vectores[i+1].coord_A.coordX;
    vectorB.coordY=vectores[i+1].coord_B.coordY-vectores[i+1].coord_A.coordY;

    printf("\nLos resultados son:\n");
    printf("Coordenadas del Vector %s: (%d,%d)\n",vectores[i].nombre,vectorA.coordX,vectorA.coordY);
    printf("Coordenadas del Vector %s: (%d,%d)\n",vectores[i+1].nombre,vectorB.coordX,vectorB.coordY);
    resultado.coordX=vectorA.coordX+vectorB.coordX;
    resultado.coordY=vectorA.coordY+vectorB.coordY;

    printf("\nResultado de la suma entre los vectores:\n");
    printf("Vector: (%d,%d)\n",resultado.coordX,resultado.coordY);

    return 0;
}


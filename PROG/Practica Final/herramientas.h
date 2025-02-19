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

int numero_aleatorio (int, int);
void standby(void);
void despedida(void);
void imprimir_matriz(int [][MAX_COL]);

int numero_aleatorio(int max, int min){
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

void imprimir_matriz(int matriz[][MAX_COL]){
    for(int i=0;i<MAX_FILA;i++){
        for(int j=0;j<MAX_COL;j++){
            printf("|   [%d][%d]   ",(i+1),(j+1));
            printf("|   %04d ",matriz[i][j]);
            printf("| %-13s ",matriz[i][j]);
            printf("|    %03d ",matriz[i][j]);
            printf("| %8.2f  |\n",matriz[i][j]);
        }
        printf("------------------------------------------------------------\n");
    }
}
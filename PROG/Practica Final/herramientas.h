#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

int numero_aleatorio (int, int);
void standby(void);

int numero_aleatorio(int max, int min){
    return rand()%(max-min+1)+min;
}

void standby(void){
    printf("\nPresione Enter para continuar.\n");
    fflush(stdin);
    getchar();
}
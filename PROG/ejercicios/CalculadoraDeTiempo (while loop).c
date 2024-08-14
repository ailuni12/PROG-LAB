#include <stdio.h>
#include <stdbool.h>

#define si true
#define no false
#define salir false

int main() {
    int segundos,horas,minutos;

    printf("Calculadora de Tiempo\n");
    printf ("Presione enter para continuar: ");
    fflush (stdout);
    getchar();

    printf("Por favor ingrese una cantidad de segundos que no sea mayor a 86400:");
    scanf("%d",&segundos);
    if (segundos >= 86400 || segundos < 0){
        printf("El numero ingresado no es valido. Por favor ingreselo nuevamente");
    }else{
        horas=segundos/3600;
        minutos=(segundos%3600)/60;
        segundos=segundos%60;

        printf("El numero ingresado equivale a: %d", horas);
        if (horas == 1) {printf(" hora");}else{printf(" horas");};
        printf(", %d", minutos);
        if (minutos == 1) {printf(" minuto");}else{printf(" minutos");};
        printf(" y %d", segundos);
        if (segundos == 1) {printf(" segundo");}else{printf(" segundos");};
    }
}
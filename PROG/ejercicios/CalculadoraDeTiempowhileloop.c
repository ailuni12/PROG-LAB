#include <stdio.h>

#define TRUE 1
#define FALSE 0

const int segundosPorHora = 3600;
const int minutosPorHora = 60;

int main() {
    int segundos,horas,minutos;
    int salir=FALSE;

    do{
    printf("Calculadora de Tiempo\n");
    printf("Indique '1' para continuar, '0' para finalizar el programa: ");
    scanf("%d",&salir);

    }while(salir==FALSE);{
    printf("Por favor ingrese una cantidad de segundos que no sea mayor a 86400: ");
    scanf("%d",&segundos);
    if (segundos >= 86400 || segundos < 0){
        printf("El numero ingresado no es valido. Por favor ingreselo nuevamente");
    }else{
        horas=segundos/segundosPorHora;
        minutos=(segundos%segundosPorHora)/minutosPorHora;
        segundos=segundos%minutosPorHora;

        printf("El numero ingresado equivale a: %d", horas);
        if (horas == 1) {printf(" hora");}else{printf(" horas");};
        printf(", %d", minutos);
        if (minutos == 1) {printf(" minuto");}else{printf(" minutos");};
        printf(" y %d", segundos);
        if (segundos == 1) {printf(" segundo");}else{printf(" segundos");};
    }
    }
}
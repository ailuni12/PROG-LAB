#include <stdio.h>

int main (void){
    //contadores globales
    int diaDelMes=1;
    float tempMaxDia=0;
    float tempMinDia=0;

    //contadores individuales y promedio
    int contadorTemps=0;
    int totalTempsIngresadas=0;
    float promedioTempsDelMes=0;

    //rankings
    float mayorTempMes=0;
    float menorTempMes=0;
    int diaMayorTemp=0;
    int diaMenorTemp=0;

    printf("Registro Mensual de Temperaturas\n");
    printf("A continuacion ingrese el Dia del Mes que quiere registrar (1 a 31), la temperatura Maxima y la Minima del dia. Para finalizar el programa y ver los resultados ingrese 0.\n");

    do{
        printf("Ingrese el Dia:\n");
        scanf("%d",&diaDelMes);
        printf("Ingrese la Temperatura Maxima:\n");
        scanf("%f",&tempMaxDia);
        printf("Ingrese la Temperatura Minima:\n");
        scanf("%f",&tempMinDia);


        if(1<=diaDelMes && diaDelMes<=31){
            contadorTemps++;
            totalTempsIngresadas=totalTempsIngresadas+tempMaxDia+tempMinDia;

            if(contadorTemps==1 || tempMaxDia>mayorTempMes){
            mayorTempMes=tempMaxDia;
            diaMayorTemp=diaDelMes;
            }

            if(contadorTemps==1 || tempMinDia<menorTempMes){
            menorTempMes=tempMinDia;
            diaMenorTemp=diaDelMes;
            }

        }else if(diaDelMes==0){
            promedioTempsDelMes=totalTempsIngresadas/(contadorTemps*2);
            
            printf("Mayor Temperatura del Mes: %.2f el dia %d\n",mayorTempMes,diaMayorTemp);
            printf("Menor Temperatura del Mes: %.2f el dia %d\n",menorTempMes,diaMenorTemp);
            printf("Promedio de las Temperaturas ingresadas: %.2f\n",promedioTempsDelMes);

            printf("Puede presionar cualquier tecla para finalizar\n");
            fflush(stdin);
            getchar();
        }else{
                printf("Ingreso algun dato incorrecto. Debe ingresar un dia en el rango valido (1 a 31), y la Temperatura Maxima no puede ser Menor a la Minima.\n");
        }

    }while(diaDelMes!=0);

    return 0;
}
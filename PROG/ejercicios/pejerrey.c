/*En esta época del año comienza la pesca del Pejerrey. Se determinó realizar un concurso de pesca muy exclusivo en donde participan solamente 3 pescadores. El ganador de concurso será el que más haya pescado durante el concurso y además se dará el premio a la pieza más grande.
Se deberá realizar un programa en el que se ingresarán las cantidades y longitudes de las piezas extraídas por cada pescador. Esta tarea será realizada por una persona que se ocupará del ingreso de los datos a medida que los pescadores vayan extrayendo los peces del agua. Los pescadores serán identificados por números del 1 al 3. En caso de querer cargarle al pescador 0 (valor que no corresponde a ninguno de los 3 pescadores) se dará por finalizado el concurso.
Cuando el programa finalice, deberá indicar:
El pescador con mayor cantidad de piezas extraídas.
El pescador con la pieza mayor (y su longitud).
El total de piezas extraídas del agua.
El promedio de las longitudes de los peces extraidos.
Pautas de corrección:
El programa deber compilar y funcionar correctamente.
Deberá respetar los estilos de programación mencionados en clase
Recuerde sostener la identación adecuada.
Se valorará la validación de información: no permitir ingresar pescadores que no existen, longitudes de peces negativas, etc.
Se valorarán los comentarios pertinentes en el codigo que ayuden a su comprensión (recordar siempre comentar por qué en las líneas necesarias, no en todo el código).*/

#include <stdio.h>

int main(void){
    int pescadorN;
    int piezasObtenidas;
    int pescador1;
    float piezaMayor;
    float promedioPiezas;
    float tamanioPieza;
    float tamanioTotal;

    pescadorN=1;
    piezasObtenidas=0;
    tamanioPieza=0;
    tamanioTotal=0;

    printf("Concurso de Pezca Pejerrey.\n");

    do{
        printf("Ingreso del numero de participante. Ingrese 0 finalizar el programa:\n");
        scanf("%d",&pescadorN);
        printf("Tamanio de la pieza pescada:\n");
        scanf("%f",&tamanioPieza);

        if(pescadorN==1 || pescadorN==2 || pescadorN==3){
            switch (pescadorN)
            {
            case 1:
                pescador1=pescadorN;
                tamanioTotal=tamanioTotal+tamanioPieza;
                piezasObtenidas++;
                if(piezasObtenidas==1 || tamanioPieza > piezaMayor){
                    piezaMayor=tamanioPieza;
                }
                break;
            }


        }else if(pescadorN==0){
            printf("Pescador %d pezco %d piezas con un tamano promedio de: %.2f\n",pescador1,piezasObtenidas,promedioPiezas=tamanioTotal/piezasObtenidas);
            printf("La pieza de mayor tamano fue de %.2f cm\n",piezaMayor);
            printf("Presione cualquier tecla para terminar.");
            fflush(stdin);
            getchar();
        }else{
            printf("Ingreso un participante que no existe. Debe ingresar un numero correcto (1, 2 o 3).\n");
        }

    }while(pescadorN!=0);

    return 0;
}


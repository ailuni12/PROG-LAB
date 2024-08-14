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
    //contadores globales
    int pescadorN=1; //ini en 1 porq sino el prog entra en un loop
    float piezaMayor=0;
    float promedioPiezas=0;
    float tamanioPieza=0;
    float tamanioTotal=0;
    int pescadorGanador=0;
    int totalPiezasObtenidas=0;

    //contadores individuales
    int piezasObtenidas1=0;
    int pescador1=0;
    int piezasObtenidas2=0;
    int pescador2=0;
    int piezasObtenidas3=0;   
    int pescador3=0;

    printf("Concurso de Pezca Pejerrey.\n");

    do{
        printf("Ingrese el numero de participante. Ingrese 0 para ver los resultados y finalizar:\n");
        scanf("%d",&pescadorN);
        printf("Tamanio de la pieza pescada:\n");
        scanf("%f",&tamanioPieza);

        //validacion participante
        if(pescadorN==1 || pescadorN==2 || pescadorN==3){
            //contadores individuales
            switch (pescadorN){
            case 1:
                pescador1=pescadorN;
                tamanioTotal=tamanioTotal+tamanioPieza;
                piezasObtenidas1++;
                break;
            case 2:
                pescador2=pescadorN;
                tamanioTotal=tamanioTotal+tamanioPieza;
                piezasObtenidas2++;
                break;
            case 3:
                pescador3=pescadorN;
                tamanioTotal=tamanioTotal+tamanioPieza;
                piezasObtenidas3++;
                break;
            }

            //registro de la mayor pieza hasta el momento
            if(tamanioPieza>piezaMayor){
                piezaMayor=tamanioPieza;
                pescadorGanador=pescadorN;
             }
        }else if(pescadorN==0){
            //print resultados y despedida
            totalPiezasObtenidas=piezasObtenidas1+piezasObtenidas2+piezasObtenidas3;
            printf("Pescador %d pezco %d piezas\n",pescador1,piezasObtenidas1);
            printf("Pescador %d pezco %d piezas\n",pescador2,piezasObtenidas2);
            printf("Pescador %d pezco %d piezas\n",pescador3,piezasObtenidas3);
            printf("La pieza de mayor tamano fue de %.2f cm, atrapada por el Participante %d\n",piezaMayor,pescadorGanador);
            printf("Total de piezas atrapadas: %d\n",totalPiezasObtenidas);
            printf("Tamano promedio de todas las piezas: %.2f cm\n",tamanioTotal/totalPiezasObtenidas);
            printf("Baibai. Presione cualquier tecla para terminar.\n");
            fflush(stdin);
            getchar();
        }else{
            //warning
            printf("Ingreso un participante que no existe. Debe ingresar un numero correcto (1, 2 o 3).\n");
        }

    }while(pescadorN!=0);

    return 0;
}
#include <stdio.h>
#include <math.h> //biblioteca de funciones matematicas
#define PI 3.14 /*donde encuentre la palabra "PI" en el codigo, lo va a reemplazar por el numero indicado*/
    
    /*tambien se puede declarar una constante dentro de la funcion como:
    const float PI=3.14;
    nombre de constantes siempre en mayus por convencion*/

int main() {
    float radio,area;/*declarar el tipo de variable y el nombre*/
    printf("Bienvenido al programa\n");
    printf("Por favor ingrese el radio de la circunferencia:");
    scanf /*pide al usuario que ingrese un dato*/("%f"/*float*/,&radio/*indica la variable donde va a guardar el dato ingresado*/);
    if (radio <= 0) {
        printf("Debe ingresar un numero valido");
        return 0;
    }else{
        area=radio*radio*PI;
        printf("%f",area);
        return 0;
    }
}


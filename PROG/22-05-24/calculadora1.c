#include <stdio.h>

//prototipos de funciones
int ingresar_dato(void);
int sumar(int,int);
void mostrar_resultado(int valor);

int main (){
    int operando1,operando2,resultado;

    operando1=ingresar_dato();
    operando2=ingresar_dato();
    resultado=sumar(operando1,operando2);
    mostrar_resultado(resultado);

    return 0;
}

int ingresar_dato(void){
    int aux;
    printf("Ingrese un valor\n");
    scanf("%d",&aux);
    return aux;
}

int sumar(int op1,int op2){
    return(op1+op2);
}

void mostrar_resultado(int valor){
    printf("El resultado de la suma es: %d",valor);
}
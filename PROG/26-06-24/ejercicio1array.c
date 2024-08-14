/*Escribir una función que reciba como parámetro un vector de enteros y el tamaño definido por Uds. y calcule la suma de todos los elementos del vector. ( Utilizar Funciones)

Escribir una función que reciba como parámetro un vector de enteros y el tamaño definido por Uds. y calcule la suma de todos los elementos del vector. ( Utilizar Funciones)
*/

#include <stdio.h>
#include <stdlib.h>
#define TOPE 10

int sumaListaNum(int);

int main (void) {
    int i = 0;
    int listaNum[TOPE];
    int numrand=0;

    for (i=0;i<TOPE;i++){
        listaNum[i]=rand()%(100-20+1)+20;
        printf("[%d]: %d\n",i+1,listaNum[i]);
    }

    sumaListaNum(numrand);
    
    return 0;
}


int sumaListaNum(int numrand){
    int a=0;

    for (a=0;a<TOPE;a++){
        printf("[%d]: %d\n",a+1,numrand);
    }

}

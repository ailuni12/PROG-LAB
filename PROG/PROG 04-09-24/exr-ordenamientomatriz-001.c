/*1.	Ingresar una matriz, de NxN valores 
en forma aleatoria, entre 1 y 30, donde N es 5, 
informar el valor máximo y su ubicación.*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 5
#define COL 5

#define RANDMAX 30
#define RANDMIN 1

void generarNumeros(int n[ROW][COL]);
void imprimirNumeros(int n[ROW][COL]);
void mostrarMayor(int n[ROW][COL]);
void mostrarRepetidos(int n[ROW][COL]);

int main(void) {
    //seed para que rand genere numeros
    //distintos cada vez que se compila.
    //hay que incluir time.h en las declaraciones
    //del principio para utilizar esta funcion
    srand(time(0));
    int listaNum[ROW][COL];

    generarNumeros(listaNum);
    imprimirNumeros(listaNum);
    mostrarMayor(listaNum);
    mostrarRepetidos(listaNum);

    return 0;
}

void generarNumeros(int listaNum[][COL]){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            listaNum[i][j]=(rand()%(RANDMAX-RANDMIN+1)+RANDMIN);
        }
    }
}

void imprimirNumeros(int listaNum[][COL]){

    printf("Lista de numeros generados:\n");
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            printf("Posicion [%d][%d]: %d\n",i,j,listaNum[i][j]);
        }
    }
}

void mostrarMayor(int listaNum[][COL]){
    int fila,columna,numero;
    numero=0;
    
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if (listaNum[i][j]>numero){
                numero=listaNum[i][j];
                fila=i;
                columna=j;
            }
        }
    }

    printf("El mayor digito encontrado es %d en la posicion [%d][%d]\n",numero,fila,columna);
    printf("\n");
}

void mostrarRepetidos(int listaNum[][COL]){
    int numerosRepetidos[ROW][COL];
    int numero=0;
    int contador=0;

    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if (listaNum[i][j]>numero){
                numero=listaNum[i][j];
            }
        }
    }

    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(listaNum[i][j]==numero){
                numerosRepetidos[i][j]=numero;
                contador++;
            }else{
                numerosRepetidos[i][j]=0;
            }
        }
    }

    if(contador>1){
        printf("El numero se repite en las posiciones:\n");

        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(numerosRepetidos[i][j]==numero){
                    printf("[%d][%d]\n",i,j);
                }
            }
        }
    }

}
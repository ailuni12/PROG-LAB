/*1.	Ingresar una matriz, de NxN valores 
en forma aleatoria, entre 1 y 30, donde N es 5, 
informar el valor máximo y su ubicación.*/

#include <stdio.h>
#include<time.h>
#include<stdlib.h> 

#define ROW 5
#define COL 5

#define RANDMAX 30
#define RANDMIN 1


int main(void) {
    int i, j;
    int listaNum[ROW][COL];

    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            listaNum[i][j]=(rand()%(RANDMAX-RANDMIN+1)+RANDMIN);
        }
    }

    return 0;
}
#include <stdio.h>
#define MIN 0
#define MAX 10
#define LIMITE (MAX+1)

int main (void) {

    int N,var=MIN,res;
    printf("Bienvenido\n");
    printf("Ingrese el numero de tabla\n");
    scanf("%d",&N);
    while(var<LIMITE){
        res=N*var;
        printf("%d x %d = %d\n",N,var,res);
        var++;
        }
    return 0;
}
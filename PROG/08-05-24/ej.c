#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MIN 0
#define MAX 10
#define LIMITE (MAX+1)

int main (void) {

    uint32_t N,var=MIN,res;
    printf("Bienvenido\n");
    printf("Ingrese el numero de tabla\n");
    scanf("%d",&N);
    while(var!=LIMITE){
        if(var==7)
        res=N*var;
        printf("%d x %d = %d\n",N,var,res);
        var++;
    }
    return 0;
}
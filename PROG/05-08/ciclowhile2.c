#include <stdio.h>
#define MIN 0
#define MAX 10
#define LIMITE (MAX+1)

int main (void) {

/*     int N,var=MIN, res;
    printf("Bienvenido\n");
    printf("Ingrese el numero de tabla\n");
    scanf("%d",&N);
    while(var!=(MAX+1)){
        res=N*var;
        printf("%d x %d = %d\n",N,var,res);
        var++;
    }
     */
/*     int N,var=MIN;
    printf("Bienvenido\n");
    printf("Ingrese el numero de tabla\n");
    scanf("%d",&N);
    while(var<LIMITE){
        printf("%d x %d = %d\n",N,var,(N*var));
        var++;
    } */

    int N,var=MIN;
    int salir;
    printf("Bienvenido\n");
    do{
    printf("Ingrese el numero de tabla\n");
    scanf("%d",&N);
    var=MIN;
    while(N!=0){
        printf("%d x %d = %d\n",N,var,(N*var));
        var++;
        }
    printf("0 para continuar 1 para salir\n");
    scanf("%d",&salir);
    }while(salir!=FALSO);
    return 0;
}
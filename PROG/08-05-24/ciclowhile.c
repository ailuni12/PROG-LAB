#include <stdio.h>
#define FALSO 0
#define VERDADERO 1
#define LIMITE 10
#define MAX 10
#define MIN 5

int main (void) {
    int salir=FALSO;
    
    printf("Bienvenido\n");

    /*
    while(!salir){
        printf("calculadora\n");
        printf("Ingrese 0 para continuar o 1 para salir\n");
        scanf("%d", &salir);
    }
    */
   //do while garantiza que el codigo se ejecutara al menos una vez
    /*
    do{
        printf("calculadora\n");
        printf("Ingrese 0 para continuar o 1 para salir\n");
        scanf("%d",&salir);
    }while{salir==FALSO};
    */

    int var=0;

/*    while(var!=LIMITE){
    printf("%d\n",var);
    var=var+1;
   } */

/*    while(var!=LIMITE){
    printf("%d\n",++var);
   }
    */

/*    while(var!=LIMITE)printf("%d\n",var++); */

    while(var!=MAX)
       var=var+1;
    printf("%d\n",var);
    return 0;
}
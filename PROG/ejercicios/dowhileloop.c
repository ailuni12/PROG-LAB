#include <stdio.h>

int main (){
    int num;
    
    printf("hola, querido usuario.\n"); //msj de bienvenida mejor que este fuera del loop para que aparezca solo una vez

    do{
        printf("Ingrese un valor, cualquier valor. Ingrese el valor que usted quiera. Ingrese 0 para terminar el programa:\n");
        scanf("%d",&num);
        printf("numero ingresado: %d\n",num);
        
        if(num==0){
            printf("baibai\n");
            fflush(stdin); //limpia el buffer
            getchar(); //espera que presione una tecla y termina
        }
    }while(num!=0);

    return 0;
}
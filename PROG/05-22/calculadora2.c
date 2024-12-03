#include <stdio.h>

//prototipos de funciones
void funcion(int valor);

int main(){
    int val=0;
    printf("Ingrese un valor:\n");
    scanf("%d",&val);
    funcion(val);

    return 0;
}

void funcion(int valor){
    valor=valor+1;
    printf("%d\n",valor);
}

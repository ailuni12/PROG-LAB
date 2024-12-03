#include <stdio.h>

int ordenarMenor(int* v1, int* v2, int* v3);
int main (void){
    int a = 50, b = 100, c =10;
    ordenarMenor(&a, &b, &c);
    printf("El mayor es: %d\n", a);
    printf("El valor del medio es: %d\n", b);
    printf("El menor valor es: %d\n", c);
    return 0;
}

int ordenarMenor(int* v1, int* v2, int* v3){
    int mayor,medio,menor;
    if(((*v1)>(*v2)) && ((*v1)>(*v3))){
        mayor = *v1;
        if(*v2>*v3){
            medio=*v2;
            menor=*v3;
        }else{
            medio=*v3;
            menor=*v2;    
        }
    }else{
        if(((*v2)>(*v1)) && ((*v2)>(*v3))) {
            mayor = *v2;
            if(*v3>*v1){
                medio=*v3;
                menor=*v1;
            }else{
                medio=*v1;
                menor=*v3;
            }
        }else{
            mayor = *v3;
            if(*v1>*v2){
                medio=*v1;
                menor=*v2;
            }else{
                medio=*v2;
                menor=*v1;
            }
        }
    }
    *v1=mayor;
    *v2=medio;
    *v3=menor;
}
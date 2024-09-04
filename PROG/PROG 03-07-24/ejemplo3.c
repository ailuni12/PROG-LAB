#include <stdio.h>
#include <stdio.h>

#define MAX_CHAR 50

int main (void) {
    char txt1[]="rrrr";
    char txt2[]="rrrr";

    if(txt1==txt2){
        printf("igual");
    }else{
        printf("distinto");
    }

    //no devuelve que son iguales porque esta comparando las
    //posiciones de memoria que son distintas, no el contenido del array

    return 0;
}
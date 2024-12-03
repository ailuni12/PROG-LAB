#include <stdio.h>

int main() {
    int i=0;
    char txt[4]="Hola\0";

    for(i=0;txt[i]!=0;i++){
        printf("%c",txt[i]);
    }

    return 0;
}
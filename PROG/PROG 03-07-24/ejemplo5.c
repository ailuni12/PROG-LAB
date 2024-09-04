#include <stdio.h>
#include <string.h>

#define IGUALES 0
#define DISTINTOS 1

int comparaPalabras(char [],char []);
int cuentaLetras(char []);

char aMayu(char);
char aMinu(char);

int main (void) {
    char txt1[]="rrrr";
    char txt2[]="TTTr";

    int resultado;

    resultado=comparaPalabras(txt1,txt2);

    if(resultado==IGUALES){
        printf("igual");
    }else{
        printf("distinto");
    }

    return 0;
}

int comparaPalabras(char txt1[],char txt2[]){
    int resultado=IGUALES;
    int longTxt1;
    int longTxt2;

    longTxt1=cuentaLetras(txt1);
    longTxt2=cuentaLetras(txt2);

    if(longTxt1==longTxt2){
        for(int i=0;txt2[i]!='\0';i++){
            if(txt1[i]!=txt2[i]){
                resultado=DISTINTOS;
            }else{
                resultado=IGUALES;
            }
        }
    }

    return resultado;
}

int cuentaLetras(char palabra[]){
    int i = 0;

    for(i=0;palabra[i]!='\0';i++);

    return i;
}

char aMayu(char letra){
    if(letra>='a' && letra<='z'){
        letra+='a'-'A';
        return letra;
    }
}

char aMinu(char letra){
}
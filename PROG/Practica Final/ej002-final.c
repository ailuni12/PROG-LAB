#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "definiciones.h"

#define MIN_ROW 1
#define MIN_COL 1
#define MAX_ROW 3
#define MAX_COL 3
#define min 1000
#define max 3000

void fill_array(producto_t [][MAX_COL]);
void mostrar_inventario(producto_t [][MAX_COL]);
void mostrar_tabla(producto_t [][MAX_COL]);
void search_code(producto_t [][MAX_COL]);
void menu(producto_t [][MAX_COL]);
void mostrar_row(producto_t [][MAX_COL]);
void registrar_item(producto_t [][MAX_COL]);
bool validar_codigo(int, producto_t [][MAX_COL]);
bool validar_lugar(int, int, producto_t [][MAX_COL]);

int main(void){
    producto_t inventario[MAX_ROW][MAX_COL];

    fill_array(inventario);
    menu(inventario);

    return 0;
}

void menu(producto_t inventario[][MAX_COL]){
    int opcion=0;
    int input_usuario=-1;
    do{
        printf("\n*** MENU DE INVENTARIO ***\n");
        printf("< 1 >. Registrar producto.\n");
        printf("< 2 >. Mostrar inventario.\n");
        printf("< 3 >. Calcular precios.\n");
        printf("< 4 >. Buscar codigo.\n");
        printf("< 5 >. Salir.\n");
        printf("\nIngrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion){
        case 1:
            registrar_item(inventario);
            break;
        case 2:
            mostrar_inventario(inventario);
            break;
        case 3:
            break;
        case 4:
            search_code(inventario);
            break;
        case 5:
            printf("\nGracias por utilizar la herramienta.\n");
            printf("Presione Enter para finalizar.\n");
            fflush(stdin);
            getchar();
            break;
        default:
            printf("ERROR. Opcion invalida.\n");
            printf("\nIngrese una opcion: ");
            scanf("%d",&opcion);
            break;
        }
    } while (opcion!=SALIDA);
    
}

void fill_array(producto_t inventario[][MAX_COL]){

    for(int i=0;i<MAX_ROW;i++){
        for(int j=0;j<MAX_COL;j++){
            inventario[i][j].codigo=0;
            strcpy(inventario[i][j].nombre,"N/A");
            inventario[i][j].cantidad=0;
            inventario[i][j].precio=0;
        }
    }
    
}

void mostrar_inventario(producto_t inventario[][MAX_COL]){

    printf("\n|  UBICACION | CODIGO | PRODUCTO      |\n");
    for(int i=0;i<MAX_ROW;i++){
        for(int j=0;j<MAX_COL;j++){
            printf("|   [%d][%d]   ",(i+1),(j+1));
            printf("| %6d ",inventario[i][j].codigo);
            printf("| %-13s |\n",inventario[i][j].nombre);
        }
    }
    mostrar_tabla(inventario);
}

void mostrar_tabla(producto_t inventario[][MAX_COL]){
    printf("\n  |       1       |       2       |       3       |\n");
    printf("  --------------------------------------------------\n");
    for(int i=0;i<MAX_ROW;i++){
        printf("%d",(i+1));
        for(int j=0;j<MAX_COL;j++){
            printf(" |   %6d     ",inventario[i][j].codigo);
        }
        printf(" |\n");
        for(int h=0;h<MAX_COL;h++){
            printf("  | %-11s ",inventario[i][h].nombre);
        }
        printf("  |\n");
        printf("  --------------------------------------------------\n");
    }

}

void search_code(producto_t inventario[][MAX_COL]){
    int codigo_input=0;
    int row=-1;
    int col=-1;
    printf("\n\tBUSQUEDA POR CODIGO\n");
    printf("\tIngrese el codigo que desea buscar: ");
    scanf("%d",&codigo_input);

    for(int i=0;i<MAX_ROW;i++){
        for(int j=0;j<MAX_COL;j++){

            if(inventario[i][j].codigo==codigo_input){
                row=i;
                col=j;
            }
        }
    }

    if(inventario[row][col].codigo==codigo_input){
        printf("\n| Codigo: %d | Producto: %s | Ubicacion: [%d][%d] |\n",inventario[row][col].codigo,inventario[row][col].nombre,row+1,col+1);
    }else{
        printf("\nEl codigo no existe.\n");
    }
}

void registrar_item(producto_t inventario[][MAX_COL]){
    int input_usuario=1;
    int codigo=-1;
    int fila=MIN_ROW;
    int col=MIN_COL;

    printf("\nDesea ingresar un producto nuevo? <SI = 1><NO = 0>: ");
    scanf("%d",&input_usuario);

    do{
        while(input_usuario!=false){
            printf("\nIngrese un codigo de item.\n");
            printf("El codigo de ser de hasta 4 digitos y mayor que 0.\n");
            printf("Codigo: ");
            scanf("%d",&codigo);

            while(codigo>9999 || codigo<1 || validar_codigo(codigo,inventario)){
                if(validar_codigo(codigo,inventario)){
                    printf("\nEl codigo ya existe, ingrese otro numero pls.\n");
                }else{
                    printf("\nCodigo invalido, ingrese nuevamente.\n");
                }
                printf("Codigo: ");
                scanf("%d",&codigo);
            }

            printf("\nIngrese la ubicacion donde desea guardar el item. El numero de fila no puede ser menor que 1 ni mayor que %d. El numero de columna no puede ser menor que 1 ni mayor que %d",MAX_ROW,MAX_COL);
            printf("\nEn que ubicacion desea guardar el item?\n");

            printf("Fila: ");
            scanf("%d",&fila);
            printf("Columna: ");
            scanf("%d",&col);

            do{
                while(fila<MIN_ROW || fila>(MAX_ROW)){
                    printf("\nEl numero de fila no puede ser mayor que %d y no puede ser menor que %d. Ingrese nuevamente.\n",MAX_ROW,MIN_ROW);
                    printf("Fila: ");
                    scanf("%d",&fila);
                }
    
                while(col<MIN_COL || col>(MAX_COL)){
                    printf("\nEl numero de columna no puede ser mayor que %d y no puede ser menor que %d. Ingrese nuevamente.\n",MAX_COL,MIN_COL);
                    printf("Columna: ");
                    scanf("%d",&col);
                }
    
                while(validar_lugar(fila,col,inventario)){
                    printf("\nYa existe un item en esa ubicacion. Ingrese otra.\n");
                    printf("\nEn que ubicacion desea guardar el item?\n");

                    printf("Fila: ");
                    scanf("%d",&fila);
                    printf("Columna: ");
                    scanf("%d",&col);
                }
            } while (validar_lugar(fila,col,inventario));

            fila-=1;
            col-=1;
            inventario[fila][col].codigo=codigo;
    
            printf("\nDatos ingresados:\n");
            printf("\n|  UBICACION | CODIGO | PRODUCTO      | STOCK  | PRECIO   | \n");
            printf("|   [%d][%d]   ",fila+1,col+1);
            printf("| %6d ",inventario[fila][col].codigo);
            printf("| %-13s ",inventario[fila][col].nombre);
            printf("| %6d ",inventario[fila][col].cantidad);
            printf("| %7.2f  |\n",inventario[fila][col].precio);

            printf("\nDesea ingresar un producto nuevo? <SI = 1><NO = 0>: ");
            scanf("%d",&input_usuario);
        }

    }while(input_usuario!=false);
  
}

bool validar_codigo(int codigo,producto_t inventario[][MAX_COL]){
    for(int i=0;i<MAX_ROW;i++){
        for(int j=0;j<MAX_COL;j++){
            if(inventario[i][j].codigo==codigo){
                return true;
            }
        }
    }
    return false;
}

bool validar_lugar(int fila, int col, producto_t inventario[][MAX_COL]){

    if(inventario[fila-1][col-1].codigo!=0){
        return true;
    }else{
        return false;
    }

}
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "definiciones.h"

int main(void){
    opcion_t opcion;
    cliente_t clientes[MAX_CLI];
    int cantidadClientes=0;



    do{
        opcion=menu();
        switch (opcion){
            case INGRESAR:
                cargarCliente(clientes,&cantidadClientes);
                break;
            case BUSCAR:
                //pedir codigo de cliente ()
                buscarCliente(clientes,codigo);
                mostrarClientePorCodigo(clientes,codigo);
                break;
            case LIST_CODIGOS:
                ordenarClientesPorCodigo(clientes,cantidadClientes);
                break;
            case LIST_APELLIDOS:
                ordenarClientesPorApellido(clientes,cantidadClientes);
                break;
            default: printf("Error.\n");
        }
    }while(opcion!=SALIR);

    return 0;
}

void pausa(void){
    printf("\nPresione Enter para continuar...");
    fflush(stdin); // aqui si va porque puede quedar el /n
    getchar();
}

opcion_t menu(void){
    int op;
    
    do{
        system("cls");
        printf("\n\t\t\t MENU DE OPCIONES DE CLIENTES\n");
        printf("\n\n\t\t\t - Ingresar Datos <1>\n");
        printf("\n\n\t\t\t Buscar un cliente <2>\n");
        printf("\n\n\t\t\t Listado de Cliente Ordenado por Codigo <3>\n");
        printf("\n\n\t\t\t Listado de Clientes Ordenado Por Apellido <4>\n");
        printf("\n\n\t\t\t - Salir <5>\n");
        printf("\n\n\t\t\t Ingrese Opcion [1-5] : ");
        scanf("%d", &op);
    } while (op < INGRESAR || op > SALIR);
    
    return op;
}

void cargarCliente(cliente_t clientes[], int * indice){

}

void mostrarCliente(cliente_t clientes[], int indice){

}

void ordenarClientesPorCodigo(cliente_t clientes[], int codigo){

}

void ordenarClientesPorApellido(cliente_t clientes[], int clientesCargados){

}

void mostrarClientePorCodigo(cliente_t clientes[], int codigo){

}

int buscarCliente(cliente_t clientes[], int codigo){

}

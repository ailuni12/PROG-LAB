#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "definiciones.h"

int main(void){
    opcion_t opcion;
    cliente_t clientes[MAX_CLI];
    int cantidadClientes=0;
    int codigo=0;

    printf("\n-------------------------\nBASE DE DATOS DE CLIENTES\n-------------------------\n");
    printf("Con este gestor puede crear un perfil de cliente, buscar clientes por su codigo, o tambien visualizar la lista completa ordenada por codigo o apellidos.\n");
    pausa();

    do{
        opcion=menu();
        switch (opcion){
            case INGRESAR:
                cargarCliente(clientes);
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
            case SALIR:
                printf("Gracias por utilizar esta herramienta. Presione Enter para finalizar:\n");
                fflush(stdin);
                getchar();
                break;
            default: printf("Error, por favor ingrese un numero valido [1 a 5].\n");
        }
    }while(opcion!=SALIR);

    return 0;
}

void pausa(void){
    printf("Presione Enter para continuar: ");
    fflush(stdin);
    getchar();
}

opcion_t menu(void){
    int op;
    
    do{
        printf("\nMENU DE OPCIONES DE CLIENTES\n");
        printf("\tIngresar Datos <1>\n");
        printf("\tBuscar un cliente <2>\n");
        printf("\tListado de Cliente Ordenado por Codigo <3>\n");
        printf("\tListado de Clientes Ordenado Por Apellido <4>\n");
        printf("\tSalir <5>\n");
        printf("Ingrese Opcion [1-5]: ");
        scanf("%d", &op);
    } while (op < INGRESAR || op > SALIR);
    
    return op;
}

void cargarCliente(cliente_t clientes[]){
    int finalizar=FALSE;
    int i=0;
    uint16_t codigo=0;
    fecha_t dob;
    char nombre[MAX_CHAR];
    char apellido[MAX_CHAR];


    printf("Datos de cliente nuevo (por favor ingrese unicamente datos validos)\n");

    do{
        printf("Puede ingresar hasta 3 digitos del 1 al 999 para el ID de Cliente\n");
        printf("ID: ");
        scanf("%d",&codigo);
        //el ampersand siempre para int y float (puntero)

        while (codigo>999 || codigo<1){
            printf("Debe ingresar un numero valido, intente nuevamente:\n");
            printf("ID: ");
            scanf("%d",&codigo);
        }
        clientes[i].codigo=codigo;

        printf("Ingrese el Nombre: ");
        scanf("%49s",nombre);
        //no incluye el ampersand porque char nombre ya se comporta
        //como un puntero, que indica la primera letra del string
        strcpy(clientes[i].nombre,nombre);

        printf("Ingrese el Apellido: ");
        scanf("%49s",apellido);
        //%49s - previene buffer overload.
        //no importa la cantidad de caracteres que
        //ingrese el usuario, va a parar de leerlos
        //en 49, dejando el espacio 50 para el \0
        strcpy(clientes[i].apellido,apellido);
        //strcpy es una funcion que copia strings

        printf("Ingrese la Fecha de Nacimiento:\n");
        printf("Dia: ");
        scanf("%d",&dob.dia);
        clientes[i].fechaNacimiento.dia=dob.dia;
        printf("Mes: ");
        scanf("%d",&dob.mes);
        clientes[i].fechaNacimiento.mes=dob.mes;
        printf("Anio: ");
        scanf("%d",&dob.anio);
        clientes[i].fechaNacimiento.anio=dob.anio;

        printf("Datos Ingresados:\n");
        printf("Codigo: %d\n",clientes[i].codigo);
        printf("Nombre Completo: %s %s\n",clientes[i].nombre,clientes[i].apellido);
        printf("Fecha de Nacimiento: %d/%d/%d\n",clientes[i].fechaNacimiento.dia,clientes[i].fechaNacimiento.mes,clientes[i].fechaNacimiento.anio);

        i++;

        printf("Finalizar la carga? (1 FIN - 0 CONTINUAR): ");
        scanf("%d",&finalizar);
    }while(finalizar!=TRUE);

    if(i<=1){
        printf("\nEl perfil de cliente se creo correctamente.\n");
    }else if(i>1){
        printf("\nSe crearon %d perfiles de cliente correctamente.\n",i++);
    }else{
        printf("\nOcurrio un error.\n");
    }
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
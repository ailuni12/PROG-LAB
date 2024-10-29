#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#define Art 6           // maxima cantidad de Articulos
#define Cli 5           // maxima cantidad de clientes
#define MaxFacturas 100 // maxima cantidad de lugares para poder facturar
#define SALIDA 0

// Estructura para clientes
typedef struct
{
    int cod;      // Código del cliente
    char nom[30]; // Nombre del Cliente
    float fac;    // Total facturado por cliente
} regcli;

// Estructura para artículos
typedef struct
{
    int cod;      // Código del artículo
    char nom[30]; // Denominación del artículo
    float pre;    // Precio por litro del artículo
    int sto;      // Stock disponible del artículo
    int vendidos; // Cantidad total de litros vendidos
} articulo;

// Estructura para facturas
typedef struct
{
    int numFactura; // Número de factura
    int codCliente; // Código del cliente
    float total;    // Total facturado en esa factura
} factura;

void inicializacion(regcli[Cli], articulo[Art]);    //  Inicializa los datos de los clientes y los artículos
void facturar(regcli[Cli], articulo[Art], factura facturas[], int *); //  función para facturar( paso clientes, articulo,  facturas, &contador de facturas)
void mostrarClientes(regcli[Cli]);                                // aqui paso  la estructura de clientes
void mostrarArticulos(articulo[Art]);                             // aqui paso  la estructura de articulos
void mostrarFacturas(factura facturas[], int);                    // aqui paso la  estructura de facturas y el contador de facturas
void tecla(void);                                                 // Función para leer una tecla y esperar
void linea(int);                                                  // Función para dibujar una línea de asteriscos
void menu(regcli[Cli], articulo[Art], factura facturas[], int *); // aqui paso la estructura de clientes, articulos, facturas y el contador de facturas
bool validar_codigo(factura facturas[],int,int);

int main()
{
    regcli clientes[Cli];
    articulo articulos[Art];
    factura facturas[MaxFacturas];
    int contfact = 0; // contador  de facturas
    inicializacion(clientes, articulos);
    menu(clientes, articulos, facturas, &contfact);
    return 0;
}

void menu(regcli clientes[], articulo articulos[], factura facturas[], int *contfact)
{
    int opcion;
    do
    {
        printf("\n*** MENU DE FACTURACION ***\n");
        printf("< 1 >. Facturar productos\n");
        printf("< 2 >. Mostrar clientes\n");
        printf("< 3 >. Mostrar articulos\n");
        printf("< 4 >. Mostrar facturas\n");
        printf("< 0 >. Salir\n");
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            facturar(clientes,articulos,facturas,contfact);
            break;
        case 2:
            mostrarClientes(clientes);
            break;
        case 3:
            mostrarArticulos(articulos);
            break;
        case 4:
            mostrarFacturas(facturas, *contfact);
            break;
        case 0:
            printf("\n...Saliendo...\n");
            break;
        default:
            printf("Opcion invalida.\n");
        }
        tecla();
    } while (opcion != SALIDA);
}

void inicializacion(regcli clientes[], articulo articulos[])
{
    regcli clientes_init[Cli] = {
        {1, "Julian LOPEZ", 0},
        {2, "Marcelo RIOS", 0},
        {3, "Alvaro CARPIO", 0},
        {4, "Facundo PAREDES", 0},
        {5, "Roberto MALDONADO", 0}};

    articulo articulos_init[Art] = {
        {1, "COCA COLA", 1500, 73, 0},
        {2, "FANTA POMELO", 1000, 120, 0},
        {3, "FANTA NARANJA", 1100, 76, 0},
        {4, "SPRITE", 1200, 34, 0},
        {5, "AGUA VILLA DEL SUR", 1100, 77, 0},
        {6, "MANAOS", 1100, 98, 0}};

    for (int i = 0; i < Cli; i++)
    {
        clientes[i] = clientes_init[i];
    }
    for (int i = 0; i < Art; i++)
    {
        articulos[i] = articulos_init[i];
    }
}

void facturar(regcli clientes[Cli], articulo articulos[Art], factura facturas[], int *contfact)
{
    int litros, cod_cliente, cod_articulo;
    int input_usuario;

    printf("value stored in address: %d\n",*contfact);
    printf("pointer's address: %d\n",&contfact);
    printf("address pointer points to: %d\n",contfact);

    do{
        printf("\nIngrese el codigo del cliente (1 a 5):\n");
        scanf("%d",&cod_cliente);

        while(cod_cliente>5 || cod_cliente<1){
            printf("\nError. Ingrese un codigo valido.\n");
            scanf("%d",&cod_cliente);
        }

        printf("\nIngrese un codigo nuevo para la Factura. Ingrese 0 para finalizar la carga.\n");
    scanf("%d",&input_usuario);

        if(validar_codigo(facturas,input_usuario,*contfact)==true){
            printf("\nEl codigo ya existe, debe ingresar uno nuevo.\n");
            scanf("%d",&input_usuario);
        }else{
            facturas[*contfact].numFactura=input_usuario;
        }

        do{
            printf("\nIngrese el codigo del articulo (1 a 6). Ingrese 0 para finalizar la carga.\n");
            scanf("%d",&cod_articulo);

            printf("\nIngrese los cantidad de litros a facturar.\n");
            scanf("%d",&litros);

            if(litros>articulos[cod_articulo-1].sto){
                printf("\nNo hay mas stock de ese articulo.\n");
            }else{
                clientes[cod_cliente-1].fac+=(litros*articulos[cod_articulo-1].pre);
                articulos[cod_articulo-1].sto-=litros;
            }

        }while(cod_articulo!=SALIDA);

        (*contfact)++;

    }while(input_usuario!=SALIDA);

    printf("\nTotal de facturas: %d \n",*contfact);
    printf("\nFACTURA NRO %d \n",facturas[cod_cliente].numFactura);
    printf("NOMBRE DEL CLIENTE: %s\n",clientes[cod_cliente-1].nom);
    printf("CODIGO DEL CLIENTE: %d\n",clientes[cod_cliente-1].cod);
    printf("TOTAL FACTURADO: %.3f\n",clientes[cod_cliente-1].fac);
}

void mostrarClientes(regcli clientes[])
{
    printf("\n*** INFORME DE CLIENTES ***\n");
    printf("COD. CLIENTE | NOMBRE DEL CLIENTE            | TOTAL FACTURADO\n");
    linea(50);
    for (int i = 0; i < Cli; i++)
    {
        printf("%12d | %-30s | %14.2f\n",
               clientes[i].cod, clientes[i].nom, clientes[i].fac);
    }
}

void mostrarArticulos(articulo articulos[])
{
    printf("\n*** INFORME DE ARTICULOS ***\n");
    printf("COD. ARTICULO | DENOMINACION         | STOCK | LITROS VENDIDOS\n");
    linea(50);
    for (int i = 0; i < Art; i++)
    {
        printf("%13d | %-20s | %5d | %14d\n",
               articulos[i].cod, articulos[i].nom, articulos[i].sto, articulos[i].vendidos);
    }
}

void mostrarFacturas(factura facturas[], int cantfac)
{
    if (cantfac == 0)
    {
        printf("\nNo se han realizado facturas.\n");
        return;
    }

    printf("\n*** INFORME DE FACTURAS ***\n");
    printf("NUM. FACTURA | COD. CLIENTE | TOTAL FACTURADO\n");
    linea(50);
    for (int i = 0; i < cantfac; i++)
    {
        printf("%12d | %12d | %14.2f\n",
               facturas[i].numFactura, facturas[i].codCliente, facturas[i].total);
    }
}
// esta funcion solo  imprime una linea de asteriscos de longitud n
void linea(int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("*");
    }
    printf("\n");
}
// este funcion espera  a que el usuario ingrese un caracter

void tecla(void)
{
    printf("\n\n...PRESIONE CUALQUIER TECLA PARA CONTINUAR...\n");
    getch();
}

bool validar_codigo(factura facturas[],int codigo,int contfact)
{
    for(int i=0;i<contfact;i++){
        if(facturas[i].numFactura==codigo){
            return true;
        }else{
        return false;
        }
    }
}
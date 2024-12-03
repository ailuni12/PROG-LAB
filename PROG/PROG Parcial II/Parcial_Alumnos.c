#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define Art 6           // maxima cantidad de Articulos
#define Cli 5           // maxima cantidad de clientes
#define MaxFacturas 100 // maxima cantidad de lugares para poder facturar

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
        system("cls");
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
            // aqui tenes que llamar a la funcion para poder facturar
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
    } while (opcion != 0);
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
    // aqui realizaras el codigo pedido
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

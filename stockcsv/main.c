#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "productos.h"
#include "ventas.h"

int main()
{
    int opc;
    int modo;
    do{
    printf("Bienvenido\n");
    printf("Elija una opcion");
    printf("\n1. Generar productos.bin\n");
    printf("2. Mostrar top 10 productos\n");
    printf("3. Agregar venta\n");
    printf("4. Procesar ventas\n");
    printf("0. Salir\n");
    printf("Opcion: ");
    fflush(stdin);scanf("%d", &opc);
    switch(opc){
    case 1:
        generar_binario_productos("productos.csv", "productos.bin");
        printf("\narchivo generado");
        break;
    case 2:
        printf("1. Top 10 más caros\n");
        printf("2. Top 10 más baratos\n");
        printf("Seleccione: ");
        fflush(stdin);scanf("%d", &modo);
        mostrar_top_10("productos.bin", modo == 1);
        break;
    case 3:
        agregar_venta("ventas.bin", "productos.bin");
        break;
    case 4:
        procesar_ventas("ventas.bin", "productos.bin");
        break;
    case 0:
        printf("Saliendo del programa...\n");
        break;
    default:
        printf("Elija una opcion valida");

    }


    }while(opc!=0);

    return 0;
}


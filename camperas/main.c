#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    int opc;

    do
    {
        printf("\n~~~Fabrica de camperas~~~\n");
        printf("1. Carga Stock.\n");
        printf("2. Mostrar Stock.\n");
        printf("3. Mostrar pedidos.\n");
        printf("4. Actualizar Stock.\n");
        printf("0. Salir\n");
        printf("Ingrese su opcion:");
        fflush(stdin);
        scanf("%d", &opc);

        switch(opc){

        case 1:
           cargaStock("stock.txt", "stock.bin"); break;

        case 2:
            mostrarStock("stock.bin");break;

        case 3:
            mostrarPedidos("pedidos.txt");break;

        case 4:
            actualizarStock("stock.bin", "pedidos.txt");break;

        case 0:
            printf("\nSaliendo del programa... \n"); break;

        default:
            printf("Elija una opcion valida.");

            }
    }while(opc!=0);
    return 0;
}

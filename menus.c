#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "manipularTxt.h"
#include "manipularBin.h"

void menuManipularTexto(){
     int opcTexto;
     const char *datos="datos.txt";
     int totalLineas= contarLineasTxt(datos);
    do
    {
        printf("|||Manipular Txt: |||\n");
        printf("Seleccione la opcion de manipular texto. \n");
        printf("1)Contar lineas. \n");
        printf("2)Buscar palabra en el txt. \n");
        printf("0) Volver al menu principal.\n");
        fflush(stdin);
        scanf("%d", &opcTexto);
        switch(opcTexto){
        case 1:
            if (totalLineas>=0){
                printf("El archivo tiene %d lineas. \n", totalLineas);
            } break;
        case 2:

            buscarPalabraTxt("datos.txt");break;

        case 0:
            printf("Volviendo al menu principal... \n");break;
        default:
            printf("Opcion incorrecta, intente nuevamente."); break;
        }

    }
    while(opcTexto!=0);

}
void menuManipularBin(){
    int opcBin;
    do
    {
        printf("|||Manipular productos.dat: |||\n");
        printf("Seleccione la opcion de manipular texto. \n");
        printf("1)Agregar productos.\n");
        printf("2)Mostrar todos los productos. \n");
        printf("0) Volver al menu principal.\n");
        fflush(stdin);
        scanf("%d", &opcBin);
        switch(opcBin){
        case 1:
            agregarProducto("productos.dat"); break;

        case 2:
            mostrarProducto("productos.dat");break;

        case 0:
            printf("Volviendo al menu principal... \n");break;
        default:
            printf("Opcion incorrecta, intente nuevamente."); break;
        }

    }
    while(opcBin!=0);

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "manipularTxt.h"
#include "manipularBin.h"

int main()
{

    int opcPrincipal;
    do
    {
        printf("MENU DE PROGRAMAS: \n");
        printf("Seleccione el programa al que quiere acceder. \n");
        printf("1)Manipulacion archivos de texto. \n");
        printf("2)Manipulacion archivos binarios. \n");
        printf("0)Salir. \n");
        fflush(stdin);
        scanf("%d", &opcPrincipal);
        switch(opcPrincipal){
        case 1:
            menuManipularTexto();
            break;

        case 2:
           menuManipularBin();break;

        case 0:
            printf("Cerrando el programa... \n");break;
        default:
            printf("Opcion incorrecta, intente nuevamente.\n");
        }

    }
    while(opcPrincipal!=0);
    return 0;
}

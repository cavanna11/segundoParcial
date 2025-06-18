#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "manipularTxt.h"
#include "manipularBin.h"

void agregarProducto(const char *productos){
    FILE *dat= fopen(productos, "ab");
    if (dat==NULL){
        perror("No se pudo abrir el archivo");
        return -1;
    }
    Tproducto p;

    printf("Ingrese nombre del producto:");
    fflush(stdin); scanf("%[^\n]", p.nombre);

    printf("Ingrese el precio:");
    fflush(stdin); scanf("%f", &p.precio);

    printf("Ingrese la cantidad:");
    fflush(stdin); scanf("%d", &p.cantidad);

    fwrite(&p, sizeof(Tproducto),1,dat);
    printf("Guardado -> Nombre: %s, Precio: %.2f, Cantidad: %d\n", p.nombre, p.precio, p.cantidad);
    fclose(dat);
    printf("\nProducto agregado correctamente.\n");

}

void mostrarProducto(const char *productos){
    FILE *dat=fopen(productos, "rb");
    if (dat==NULL){
        perror("No se pudo abrir el archivo");
        return;
    }
    Tproducto p;

    printf("\nProductos: \n");

    while(fread(&p,sizeof(Tproducto),1,dat)==1){
        printf("NOMBRE: %s\n", p.nombre);
        printf("PRECIO: %.2f\n", p.precio);
        printf("CANTIDAD: %d\n", p.cantidad);
        printf("------------------\n");
    }
    fclose(dat);
}

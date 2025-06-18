#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


void cargaStock(const char* txt_stock, const char* bin_stock){
    FILE* txt = fopen(txt_stock, "r");
    FILE* bin = fopen(bin_stock, "ab");
    if (!txt || !bin){
        perror("Error abriendo archivos");
        return;
    }
    char linea[128];
    while(fgets(linea, sizeof(linea),txt)){
        Tprenda p;
        if (sscanf(linea, "%d %c %d", &p.codigo, &p.talle, &p.cantidad)==3){
            printf("Leido: %d\n %c\n %d\n", p.codigo, p.talle, p.cantidad);
            fwrite(&p, sizeof(Tprenda), 1, bin);
        }else{
        printf("Linea invalida: %s", linea);
        }
    }

    fclose(txt);
    fclose(bin);
    printf("Stock cargado correctamente. \n");

}

void mostrarStock(const char* bin_stock){
    FILE* bin=fopen(bin_stock, "rb");
    if (!bin){
        perror("Error abriendo archivos binarios");
        return;
    }
    Tprenda p;

    printf("\nStock actual\n");
    while(fread(&p, sizeof(Tprenda),1,bin)){
        printf("Codigo: %d || Talle: %c || Cantidad: %d \n", p.codigo, p.talle, p.cantidad);
    }
    fclose(bin);
}
//YA FUNCIONA
void mostrarPedidos(const char* pedidos_txt){
    FILE* txt = fopen(pedidos_txt, "r");
    if (!txt){
        perror("Error abriendo archivo");
        return;
    }
    char linea[128];
    printf("Pedidos\n");
    while(fgets(linea, sizeof(linea),txt)){
        int codigo, cantidad;
        char talle;
        sscanf(linea, "%d %c %d", &codigo, &talle, &cantidad);
        printf("Codigo: %d || Talle: %c || Cantidad: %d \n", codigo, talle, cantidad);
    }
    fclose(txt);
}
//TO DO
void actualizarStock(const char* bin_stock, const char* pedidos_txt){
    FILE* pedidos= fopen(pedidos_txt, "r");
       if (!pedidos){
        perror("Error abriendo archivo");
        return;
    }
    Tprenda pedidos_array[100];
    int n_pedidos = 0;

    while(fscanf(pedidos, "%d %c %d", &pedidos_array[n_pedidos].codigo, &pedidos_array[n_pedidos].talle,&pedidos_array[n_pedidos].cantidad)==3){
        n_pedidos++;
    }
    fclose(pedidos);

    FILE* bin= fopen(bin_stock, "rb+");
    if (!bin){
        perror("Error abriendo archivo");
        return;
    }

    Tprenda p;
    for (int i=0; i< n_pedidos; i++){
        rewind(bin);
        int encontrado=0;
        long pos;

    }

};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "manipularTxt.h"

int contarLineasTxt(const char *datos){
    FILE *archivo= fopen(datos, "r");
    if (archivo==NULL){
        perror("No se pudo abrir el archivo");
        return -1;
    }
    int lineas=0;
    char c;
    while((c=fgetc(archivo)) !=EOF){
        if(c=='\n'){
            lineas++;
        }
    }
    fclose(archivo);
    return lineas;
}

int buscarPalabraTxt(const char *datos){
    FILE *archivo = fopen(datos, "r");
        if (archivo==NULL){
        perror("No se pudo abrir el archivo");
        return -1;
    }
    char palabra[100];
    printf("Ingrese la palabra a buscar: ");
    fflush(stdin); scanf("%s", palabra);

    char palabraArchivo[100];
    int cantPalabra=0;

    while(fscanf(archivo, "%s",palabraArchivo)==1){
        if(strcmp(palabra, palabraArchivo)==0){

        cantPalabra++;
        }
    }
    printf("La palabra | %s  |, aparece %d veces\n", palabra, cantPalabra);
    fclose(archivo);
    return cantPalabra;
}

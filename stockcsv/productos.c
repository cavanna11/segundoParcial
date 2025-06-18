#include "productos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generar_binario_productos(const char* csv_filename, const char* bin_filename)
{
    FILE* csv = fopen(csv_filename, "r");
    FILE* bin = fopen(bin_filename, "wb");
    if (!csv || !bin)
    {
        perror("Error abriendo archivos");
        return;
    }
    char linea[512];
    fgets(linea, sizeof(linea), csv); // Saltar encabezado
    while (fgets(linea, sizeof(linea), csv))
    {
        Producto p;
        char* token;

        // Saltar los primeros 3 campos
        token = strtok(linea, "|"); // id_comercio
        if (!token) continue;
        token = strtok(NULL, "|");  // id_bandera
        if (!token) continue;
        token = strtok(NULL, "|");  // id_sucursal
        if (!token) continue;

        token = strtok(NULL, "|");  // id_producto
        if (!token) continue;
        p.id_producto = atoi(token);  // long long por si es EAN o código largo

        token = strtok(NULL, "|"); // productos_ean (lo ignoramos)
        if (!token) continue;

        token = strtok(NULL, "|"); // descripcion
        if (!token) continue;
        strncpy(p.descripcion, token, 99);
        p.descripcion[99] = '\0';

        token = strtok(NULL, "|"); // cantidad_presentacion
        if (!token) continue;
        p.cantidad_presentacion = atoi(token);

        token = strtok(NULL, "|"); // unidad_medida
        if (!token) continue;
        strncpy(p.unidad_medida, token, 19);
        p.unidad_medida[19] = '\0';

        token = strtok(NULL, "|"); // marca
        if (!token) continue;
        strncpy(p.marca, token, 49);
        p.marca[49] = '\0';

        token = strtok(NULL, "|"); // precio_lista
        if (!token) continue;
        token[strcspn(token, "\r\n")] = 0;  // limpiar salto de línea
        p.precio_lista = atof(token);

        p.cantidad = 100;

        printf("Producto: %d | %s | %d | %s | %s | %.2f | %d\n", &p.id_producto, p.descripcion,p.cantidad_presentacion,p.unidad_medida,p.marca, p.precio_lista, p.cantidad);

        fwrite(&p, sizeof(Producto), 1, bin);
    }


    fclose(csv);
    fclose(bin);
}



int comparar_caros(const void* a, const void* b)
{
    Producto* pa = (Producto*)a;
    Producto* pb = (Producto*)b;
    return pb->precio_lista - pa->precio_lista;
}

int comparar_baratos(const void* a, const void* b)
{
    Producto* pa = (Producto*)a;
    Producto* pb = (Producto*)b;
    return pa->precio_lista - pb->precio_lista;
}

void mostrar_top_10(const char* bin_filename, int modo)
{
    FILE* bin = fopen(bin_filename, "rb");
    if (!bin)
    {
        perror("Error abriendo binario");
        return;
    }

    Producto productos[10000]; // asumiendo que no hay más de 10k
    int count = 0;
    while (fread(&productos[count], sizeof(Producto), 1, bin))
    {
        count++;
    }

    if (modo)
        qsort(productos, count, sizeof(Producto), comparar_caros);
    else
        qsort(productos, count, sizeof(Producto), comparar_baratos);

    for (int i = 0; i < 10 && i < count; i++)
    {
        printf("ID: %d - %s - $%.2f\n", productos[i].id_producto, productos[i].descripcion, productos[i].precio_lista);
    }

    fclose(bin);
}


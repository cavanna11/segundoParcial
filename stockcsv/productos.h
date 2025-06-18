#ifndef PRODUCTOS_H
#define PRODUCTOS_H

typedef struct {
    long long id_producto;
    char descripcion[100];
    int cantidad_presentacion;
    char unidad_medida[20];
    char marca[50];
    float precio_lista;
    int cantidad; // stock inicial
} Producto;


void generar_binario_productos(const char* csv_filename, const char* bin_filename);
void mostrar_top_10(const char* bin_filename, int modo); // 1: caros, 0: baratos

#endif

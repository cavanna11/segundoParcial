#ifndef VENTAS_H
#define VENTAS_H

typedef struct {
    int id_producto;
    int cantidad;
} ItemVenta;

typedef struct {
    int id_venta;
    ItemVenta productos[100];
    int total_items;
} Venta;

void agregar_venta(const char* ventas_filename, const char* productos_filename);
void procesar_ventas(const char* ventas_filename, const char* productos_filename);

#endif

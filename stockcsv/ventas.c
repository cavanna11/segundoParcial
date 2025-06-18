#include "ventas.h"
#include "productos.h"
#include <stdio.h>
#include <stdlib.h>

void agregar_venta(const char* ventas_filename, const char* productos_filename) {
    Venta v;
    static int id_counter = 1;
    v.id_venta = id_counter++;
    v.total_items = 0;

    int codigo, cantidad;
    char opcion;

    do {
        printf("Ingrese ID de producto: ");
        scanf("%d", &codigo);
        printf("Ingrese cantidad: ");
        scanf("%d", &cantidad);

        int encontrado = 0;
        for (int i = 0; i < v.total_items; i++) {
            if (v.productos[i].id_producto == codigo) {
                v.productos[i].cantidad += cantidad;
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            v.productos[v.total_items].id_producto = codigo;
            v.productos[v.total_items].cantidad = cantidad;
            v.total_items++;
        }

        printf("¿Agregar otro producto? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's');

    FILE* bin = fopen(ventas_filename, "ab");
    if (!bin) {
        perror("Error abriendo archivo de ventas");
        return;
    }

    fwrite(&v, sizeof(Venta), 1, bin);
    fclose(bin);
}

void procesar_ventas(const char* ventas_filename, const char* productos_filename) {
    FILE* ventas = fopen(ventas_filename, "rb");
    FILE* productos = fopen(productos_filename, "rb+");
    if (!ventas || !productos) {
        perror("Error abriendo archivos");
        return;
    }

    Producto lista_productos[10000];
    int count = 0;

    while (fread(&lista_productos[count], sizeof(Producto), 1, productos)) {
        count++;
    }

    rewind(ventas);
    Venta venta;
    while (fread(&venta, sizeof(Venta), 1, ventas)) {
        char filename[50];
        sprintf(filename, "pedido_%d.txt", venta.id_venta);
        FILE* detalle = fopen(filename, "w");

        fprintf(detalle, "Pedido ID: %d\n", venta.id_venta);

        for (int i = 0; i < venta.total_items; i++) {
            int id = venta.productos[i].id_producto;
            int cant = venta.productos[i].cantidad;
            int encontrado = 0;

            for (int j = 0; j < count; j++) {
                if (lista_productos[j].id_producto == id) {
                    encontrado = 1;
                    fprintf(detalle, "Producto: %s - Cantidad Pedida: %d\n", lista_productos[j].descripcion, cant);
                    if (lista_productos[j].cantidad >= cant) {
                        lista_productos[j].cantidad -= cant;
                        fprintf(detalle, "Pedido completo.\n\n");
                    } else {
                        fprintf(detalle, "NO hay stock suficiente. Faltan: %d\n\n", cant - lista_productos[j].cantidad);
                        lista_productos[j].cantidad = 0;
                    }
                    break;
                }
            }

            if (!encontrado) {
                fprintf(detalle, "Producto ID %d no encontrado\n", id);
            }
        }

        fclose(detalle);
    }

    // Reescribir archivo de productos con stock actualizado
    freopen(productos_filename, "wb", productos);
    fwrite(lista_productos, sizeof(Producto), count, productos);

    fclose(ventas);
    fclose(productos);
}


#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct Prenda{
    int codigo;
    char talle;
    int cantidad;
}Tprenda;

void cargaStock(const char* txt_stock, const char* bin_stock);
void mostrarStock(const char* bin_stock);
void actualizarStock(const char* bin_stock, const char* pedidos_txt);
void mostrarPedidos(const char* pedidos_txt);

#endif // FUNCIONES_H_INCLUDED

#ifndef MANIPULARBIN_H_INCLUDED
#define MANIPULARBIN_H_INCLUDED

/*Ejercicio 2: Manipulación de Archivos Binarios
Descripción: Crea un programa en C que permita gestionar una lista de productos mediante un archivo
binario "productos.dat". Cada producto tiene la siguiente estructura:
char nombre[50];
float precio;
int cantidad;
1. Agregar producto: Implementa una función que permita ingresar datos de un nuevo producto y
añadirlo al archivo binario.
Ejemplo de Ejecución: Después de ejecutar el programa y elegir la opción de agregar un
producto, se debería solicitar al usuario ingresar el nombre, precio y cantidad del producto. Luego
de ingresar los datos, el producto debería ser almacenado correctamente en el archivo binario.
2. Mostrar todos los productos: Implementa una función que lea y muestre todos los productos
almacenados en el archivo "productos.dat"
Ejemplo de Ejecución: Al seleccionar la opción de mostrar todos los productos, el programa
debería imprimir en pantalla todos los productos existentes en el archivo "productos.dat",
mostrando su nombre, precio y cantidad.*/

typedef struct producto{

    char nombre[50];
    float precio;
    int cantidad;


}Tproducto;

void agregarProducto(const char *productos);
void mostrarProducto(const char *productos);


#endif // MANIPULARBIN_H_INCLUDED

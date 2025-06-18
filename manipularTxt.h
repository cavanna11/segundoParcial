#ifndef MANIPULARTXT_H_INCLUDED
#define MANIPULARTXT_H_INCLUDED

/*Ejercicio 1: Manipulación de Archivos de Texto
Descripción: Escribe un programa en C que realice las siguientes funciones sobre un archivo de texto
llamado "datos.txt":
1. Contar líneas: Implementa una función que cuente y devuelva la cantidad de líneas que contiene
el archivo "datos.txt".
Ejemplo de Ejecución: Al ejecutar el programa con "datos.txt" como entrada, se debería mostrar
en pantalla el número total de líneas que contiene el archivo.
2. Buscar palabra: Implementa una función que reciba como parámetro una palabra y cuente
cuántas veces aparece en el archivo "datos.txt".
Ejemplo de Ejecución: Si el usuario ingresa una palabra específica como parámetro, el
programa debería contar cuántas veces esa palabra aparece en el archivo "datos.txt". */
int contarLineasTxt(const char *datos);
int buscarPalabraTxt(const char *datos);



#endif // MANIPULARTXT_H_INCLUDED

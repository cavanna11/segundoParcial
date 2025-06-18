#ifndef MANIPULARTXT_H_INCLUDED
#define MANIPULARTXT_H_INCLUDED

/*Ejercicio 1: Manipulaci�n de Archivos de Texto
Descripci�n: Escribe un programa en C que realice las siguientes funciones sobre un archivo de texto
llamado "datos.txt":
1. Contar l�neas: Implementa una funci�n que cuente y devuelva la cantidad de l�neas que contiene
el archivo "datos.txt".
Ejemplo de Ejecuci�n: Al ejecutar el programa con "datos.txt" como entrada, se deber�a mostrar
en pantalla el n�mero total de l�neas que contiene el archivo.
2. Buscar palabra: Implementa una funci�n que reciba como par�metro una palabra y cuente
cu�ntas veces aparece en el archivo "datos.txt".
Ejemplo de Ejecuci�n: Si el usuario ingresa una palabra espec�fica como par�metro, el
programa deber�a contar cu�ntas veces esa palabra aparece en el archivo "datos.txt". */
int contarLineasTxt(const char *datos);
int buscarPalabraTxt(const char *datos);



#endif // MANIPULARTXT_H_INCLUDED

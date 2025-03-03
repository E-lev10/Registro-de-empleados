#ifndef ACCESO_H // Comprueba si ACCESO_H no ha sido definido previamente.
#define ACCESO_H // Define ACCESO_H para evitar inclusiones m�ltiples del mismo archivo.

#include "registro.h" // Incluye el archivo de cabecera "registro.h", que probablemente contiene la definici�n de la estructura Registro y otras declaraciones necesarias.
#include <fstream> // Incluye la biblioteca <fstream> para realizar operaciones de entrada/salida de archivos, como leer o escribir en archivos.

void leerArchivo(); // Declaraci�n de la funci�n leerArchivo, que se encargar� de leer registros desde un archivo.
void buscarPorID(int idBuscado); // Declaraci�n de la funci�n buscarPorID, que toma un ID como argumento y buscar� el registro correspondiente en los datos.

#endif // Fin del bloque de inclusi�n�para�ACCESO_H
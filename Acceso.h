#ifndef ACCESO_H // Comprueba si ACCESO_H no ha sido definido previamente.
#define ACCESO_H // Define ACCESO_H para evitar inclusiones múltiples del mismo archivo.

#include "registro.h" // Incluye el archivo de cabecera "registro.h", que probablemente contiene la definición de la estructura Registro y otras declaraciones necesarias.
#include <fstream> // Incluye la biblioteca <fstream> para realizar operaciones de entrada/salida de archivos, como leer o escribir en archivos.

void leerArchivo(); // Declaración de la función leerArchivo, que se encargará de leer registros desde un archivo.
void buscarPorID(int idBuscado); // Declaración de la función buscarPorID, que toma un ID como argumento y buscará el registro correspondiente en los datos.

#endif // Fin del bloque de inclusión para ACCESO_H
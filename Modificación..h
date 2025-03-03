#ifndef MODIFICACION_H // Comprueba si MODIFICACION_H no ha sido definido previamente.
#define MODIFICACION_H // Define MODIFICACION_H para evitar inclusiones múltiples del mismo archivo.

#include "modificacion.h" // Incluye el archivo de cabecera "modificacion.h" donde probablemente se declare la estructura Registro y otras funciones relacionadas.
#include <fstream> // Incluye la biblioteca <fstream> para manejar operaciones de entrada/salida de archivos.

void modificarRegistro(const Registro& reg); // Declaración de la función modificarRegistro, que toma un registro como referencia constante para permitir la modificación del registro sin copiarlo.
void eliminarRegistro(int ideliminar); // Declaración de la función eliminarRegistro, que toma un ID de registro como argumento para eliminar el registro correspondiente

#endif // Fin del bloque de inclusión para MODIFICACION_H

#pragma once // Directiva que también previene inclusiones múltiples, aunque no es necesaria si ya se ha usado #ifndef.
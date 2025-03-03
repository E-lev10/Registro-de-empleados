#ifndef MODIFICACION_H // Comprueba si MODIFICACION_H no ha sido definido previamente.
#define MODIFICACION_H // Define MODIFICACION_H para evitar inclusiones m�ltiples del mismo archivo.

#include "modificacion.h" // Incluye el archivo de cabecera "modificacion.h" donde probablemente se declare la estructura Registro y otras funciones relacionadas.
#include <fstream> // Incluye la biblioteca <fstream> para manejar operaciones de entrada/salida de archivos.

void modificarRegistro(const Registro& reg); // Declaraci�n de la funci�n modificarRegistro, que toma un registro como referencia constante para permitir la modificaci�n del registro sin copiarlo.
void eliminarRegistro(int ideliminar); // Declaraci�n de la funci�n eliminarRegistro, que toma un ID de registro como argumento para eliminar el registro correspondiente

#endif // Fin del bloque de inclusi�n para MODIFICACION_H

#pragma once // Directiva que tambi�n previene inclusiones m�ltiples, aunque no es necesaria si ya se ha�usado�#ifndef.
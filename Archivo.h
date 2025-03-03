#include "registro.h" // Incluye la cabecera 'registro.h' que probablemente contiene la definición de la estructura Registro y otras declaraciones necesarias.

void insertarRegistro(Registro nuevo);// Función para insertar un nuevo registro en algún lugar 
void leerArchivo(); // Función para leer registros desde un archivo.
void busccarPorID(int idBuscador); // Función para buscar un registro por su ID.
void modificarRegistro(const Registro& reg); // Función para modificar un registro existente, pasando el registro como referencia constante para evitar copias innecesarias.
void eliminarRegistro(int ideliminar); // Función para eliminar un registro dado su ID.
#include "registro.h" // Incluye la cabecera 'registro.h' que probablemente contiene la definici�n de la estructura Registro y otras declaraciones necesarias.

void insertarRegistro(Registro nuevo);// Funci�n para insertar un nuevo registro en alg�n lugar 
void leerArchivo(); // Funci�n para leer registros desde un archivo.
void busccarPorID(int idBuscador); // Funci�n para buscar un registro por su ID.
void modificarRegistro(const Registro& reg); // Funci�n para modificar un registro existente, pasando el registro como referencia constante para evitar copias innecesarias.
void eliminarRegistro(int ideliminar); // Funci�n para eliminar un registro�dado�su�ID.
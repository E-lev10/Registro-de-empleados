#include "insersion.h" // Incluye el archivo de cabecera 'insersion.h', que probablemente contiene declaraciones relacionadas con la inserción de registros

#include <fstream> // Incluye la biblioteca fstream para poder trabajar con archivos de entrada y salida

using namespace std; // Permite utilizar las entidades del espacio de nombres 'std' sin necesidad de prefixarlas con 'std::'


// Función que inserta un nuevo registro en el archivo 'datos.dat'.
void insertarRegistro(Registro nuevo) { // Toma un registro nuevo como argumento.

	ofstream archivo("datos.dat", ios::binary | ios::app); // Abre el archivo 'datos.dat' en modo binario y en modo de adición (append)
	if (!archivo.is_open()) { // Verifica si el archivo se ha abierto correctamente
		cerr << "Error abriendo archivo!"; // Si no se pudo abrir, muestra un mensaje de error en la salida de error
		return; // Sale de la función si el archivo no se abre
	}
	archivo.write((char*)&nuevo, sizeof(Registro)); // obtiene la dirección de memoria de la variable y convierte esa dirección a un puntero de tipo char*.
	archivo.close(); // Cierra el archivo después de escribir el registro.
	cout << "Registro insertado correctamente!" << endl; // Muestra un mensaje indicando que el registro se insertó con éxito
}
}
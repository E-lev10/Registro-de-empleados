#include "eliminacion.h" // Incluye el archivo de cabecera 'eliminacion.h', que probablemente contiene declaraciones relacionadas con la eliminación de registros
#include "registro.h" // Incluye la cabecera 'registro.h', que contiene la definición de la estructura Registro y otras declaraciones necesarias
#include <fstream> // Incluye la biblioteca fstream para trabajar con archivos
#include <cstdio> // Incluye la biblioteca cstdio para poder utilizar funciones como remove y rename
#include "modificacion.h" // Incluye el archivo de cabecera 'modificacion.h', que probablemente contiene declaraciones relacionadas con la modificación de registros

using namespace std; // Permite utilizar las entidades del espacio de nombres 'std' sin necesidad de prefixarlas con 'std::'

void modificarRegistro(const Registro& reg) // Función que modifica un registro dado, pero no está implementada
{
}

void eliminarRegistro(int idEliminar) { // Función que elimina un registro dado su ID.
	ifstream entrada("datos.dat", ios::binary); // Abre el archivo 'datos.dat' en modo binario para lectura
	if (!entrada.is_open()) { // Verifica si el archivo se ha abierto correctamente
		cerr << "Error abriendo archivo!"; // Si no se pudo abrir, muestra un mensaje de error en la salida de error
		return; // Sale de la función si el archivo no se abre
	}

	ofstream salida("temp.dat", ios::binary); // Abre un archivo temporal 'temp.dat' en modo binario para escritura
	Registro reg; // Variable donde se almacenará temporalmente cada registro leído del archivo
	bool eliminado = false; // Inicializa una variable booleana para indicar si se ha eliminado el registro

	//Lee un registro completo desde el archivo de entrada y lo almacena en la variable reg.
	while (entrada.read((char*)&reg, sizeof(Registro))) { // Lee un registro del archivo de entrada en cada iteración
		if (reg.id != idEliminar) { // Verifica si el ID del registro leído no coincide con el ID a eliminar
			salida.write((char*)&reg, sizeof(Registro)); // Si no coincide, escribe el registro en el archivo temporal
		}
		else { // Si coincide con el ID a eliminar
			eliminado = true; // Cambia el estado de 'eliminado' a true, indicando que se encontró el registro a eliminar
		}
	}

	entrada.close(); // Cierra el archivo de entrada después de haber leído todos los registros
	salida.close();	// Cierra el archivo temporal después de haber escrito los registros que no se eliminaron	

	remove("datos.dat"); // Elimina el archivo original 'datos.dat'.
	rename(R"(temp.dat)", R"(datos.dat)"); // Renombra el archivo temporal 'temp.dat' a 'datos.dat', haciendo efectivo el cambio.

	if (eliminado) // Verifica si se eliminó un registro.
		cout << "Registro eliminado!" << endl; // Muestra un mensaje indicando que se eliminó el registro.
	else  cout << "Registro no encontrado!" << endl; // Si no se eliminó, muestra un mensaje indicando que no se encontró el registro.
}
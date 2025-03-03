#include "eliminacion.h" // Incluye el archivo de cabecera 'eliminacion.h', que probablemente contiene declaraciones relacionadas con la eliminaci�n de registros
#include "registro.h" // Incluye la cabecera 'registro.h', que contiene la definici�n de la estructura Registro y otras declaraciones necesarias
#include <fstream> // Incluye la biblioteca fstream para trabajar con archivos
#include <cstdio> // Incluye la biblioteca cstdio para poder utilizar funciones como remove y rename
#include "modificacion.h" // Incluye el archivo de cabecera 'modificacion.h', que probablemente contiene declaraciones relacionadas con la modificaci�n de registros

using namespace std; // Permite utilizar las entidades del espacio de nombres 'std' sin necesidad de prefixarlas con 'std::'

void modificarRegistro(const Registro& reg) // Funci�n que modifica un registro dado, pero no est� implementada
{
}

void eliminarRegistro(int idEliminar) { // Funci�n que elimina un registro dado su ID.
	ifstream entrada("datos.dat", ios::binary); // Abre el archivo 'datos.dat' en modo binario para lectura
	if (!entrada.is_open()) { // Verifica si el archivo se ha abierto correctamente
		cerr << "Error abriendo archivo!"; // Si no se pudo abrir, muestra un mensaje de error en la salida de error
		return; // Sale de la funci�n si el archivo no se abre
	}

	ofstream salida("temp.dat", ios::binary); // Abre un archivo temporal 'temp.dat' en modo binario para escritura
	Registro reg; // Variable donde se almacenar� temporalmente cada registro le�do del archivo
	bool eliminado = false; // Inicializa una variable booleana para indicar si se ha eliminado el registro

	//Lee un registro completo desde el archivo de entrada y lo almacena en la variable reg.
	while (entrada.read((char*)&reg, sizeof(Registro))) { // Lee un registro del archivo de entrada en cada iteraci�n
		if (reg.id != idEliminar) { // Verifica si el ID del registro le�do no coincide con el ID a eliminar
			salida.write((char*)&reg, sizeof(Registro)); // Si no coincide, escribe el registro en el archivo temporal
		}
		else { // Si coincide con el ID a eliminar
			eliminado = true; // Cambia el estado de 'eliminado' a true, indicando que se encontr� el registro a eliminar
		}
	}

	entrada.close(); // Cierra el archivo de entrada despu�s de haber le�do todos los registros
	salida.close();	// Cierra el archivo temporal despu�s de haber escrito los registros que no se eliminaron	

	remove("datos.dat"); // Elimina el archivo original 'datos.dat'.
	rename(R"(temp.dat)", R"(datos.dat)"); // Renombra el archivo temporal 'temp.dat' a 'datos.dat', haciendo efectivo el cambio.

	if (eliminado) // Verifica si se elimin� un registro.
		cout << "Registro eliminado!" << endl; // Muestra un mensaje indicando que se elimin� el registro.
	else  cout << "Registro no encontrado!" << endl; // Si no se elimin�, muestra un mensaje indicando que no se encontr�el�registro.
}
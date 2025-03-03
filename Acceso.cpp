#include "acceso.h" // Incluye el archivo de cabecera 'acceso.h', que probablemente contiene declaraciones relacionadas con el acceso a datos
#include <iostream> // Incluye la biblioteca est�ndar de entrada/salida de C++ para poder utilizar cout y cerr
#include "registro.h"// Incluye la cabecera 'registro.h' que probablemente contiene la definici�n de la estructura Registro y otras declaraciones necesarias
#include "archivo.h" // Incluye el archivo de cabecera 'archivo.h', que puede contener funciones relacionadas con la manipulaci�n de archivos

using namespace std; // Permite utilizar las entidades del espacio de nombres 'std' sin necesidad de prefixarlas con 'std::'.

void leerArchivo() { // Funci�n que lee los registros de un archivo binario 'datos.dat'.
	ifstream archivo("datos.dat", ios::binary); // Abre el archivo 'datos.dat' en modo binario para lectura.
	if (!archivo.is_open()) { // Verifica si el archivo se ha abierto correctamente.
		cerr << "error abriendo archivo!"; // Si no se pudo abrir, muestra un mensaje de error en la salida de error.
		return; // Sale de la funci�n.
	}

	Registro reg; // Declara una variable de tipo Registro para almacenar temporalmente los datos le�dos del archivo
	while (archivo.read(reinterpret_cast<char*>(&reg), sizeof(Registro))) { // Lee registros del archivo hasta que no haya m�s datos
		cout << "\nID: " << reg.id // Muestra el ID del registro le�do.
			<< "\nNombre: " << reg.nombre // Muestra el nombre del registro le�do
			<< "\nSalario: " << reg.salario << endl; // Muestra el salario del registro le�do
	}
	archivo.close(); // Cierra el archivo despu�s de haber le�do todos los registros
}

void buscarPorID(int idBuscado) // Funci�n que busca un registro por ID, pero no est� implementada
{
}

void busccarPorID(int idBuscador) // Funci�n que tambi�n busca un registro por ID, pero tiene un nombre incorrecto
{
}

void bucarPorID(int idBuscado) { // Funci�n que busca un registro por ID, implementada correctamente
	ifstream archivo("datos.dat", ios::binary); // Abre el archivo 'datos.dat' en modo binario para lectura
	if (!archivo.is_open()) { // Verifica si el archivo se ha abierto correctamente
		cerr << "Error abriendo archivo!"; // Si no se pudo abrir, muestra un mensaje de error en la salida de error
		return; // Sale de la funci�n.
	}
	Registro reg; // Declara una variable de tipo Registro para almacenar temporalmente los datos le�dos del archivo
	bool encontrado = false; // Inicializa una variable booleana para indicar si se encontr� el registro
	while (archivo.read(reinterpret_cast<char*>(&reg), sizeof(Registro)) && !encontrado) { // Lee registros del archivo hasta que se encuentre el registro buscado o no haya m�s datos
		if (reg.id == idBuscado) { // Verifica si el ID del registro le�do coincide con el ID buscado

			cout << "\nRegistro encontrado:" // Muestra un mensaje indicando que se encontr� el registro
				<< "\nNombre: " << reg.nombre // Muestra el nombre del registro encontrado
				<< "\nSalario: " << reg.salario << endl; // Muestra el salario del registro encontrado
			encontrado = true; // Cambia el estado de 'encontrado' a true, indicando que el registro fue encontrado
		}
	}
	if (!encontrado) cout << "Registro no encontrado!" << endl; // Si no se encontr� el registro, muestra un mensaje correspondiente.
	archivo.close(); // Cierra el archivo despu�s de haber buscado�el�registro.
}
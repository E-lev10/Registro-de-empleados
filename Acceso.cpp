#include "acceso.h" // Incluye el archivo de cabecera 'acceso.h', que probablemente contiene declaraciones relacionadas con el acceso a datos
#include <iostream> // Incluye la biblioteca estándar de entrada/salida de C++ para poder utilizar cout y cerr
#include "registro.h"// Incluye la cabecera 'registro.h' que probablemente contiene la definición de la estructura Registro y otras declaraciones necesarias
#include "archivo.h" // Incluye el archivo de cabecera 'archivo.h', que puede contener funciones relacionadas con la manipulación de archivos

using namespace std; // Permite utilizar las entidades del espacio de nombres 'std' sin necesidad de prefixarlas con 'std::'.

void leerArchivo() { // Función que lee los registros de un archivo binario 'datos.dat'.
	ifstream archivo("datos.dat", ios::binary); // Abre el archivo 'datos.dat' en modo binario para lectura.
	if (!archivo.is_open()) { // Verifica si el archivo se ha abierto correctamente.
		cerr << "error abriendo archivo!"; // Si no se pudo abrir, muestra un mensaje de error en la salida de error.
		return; // Sale de la función.
	}

	Registro reg; // Declara una variable de tipo Registro para almacenar temporalmente los datos leídos del archivo
	while (archivo.read(reinterpret_cast<char*>(&reg), sizeof(Registro))) { // Lee registros del archivo hasta que no haya más datos
		cout << "\nID: " << reg.id // Muestra el ID del registro leído.
			<< "\nNombre: " << reg.nombre // Muestra el nombre del registro leído
			<< "\nSalario: " << reg.salario << endl; // Muestra el salario del registro leído
	}
	archivo.close(); // Cierra el archivo después de haber leído todos los registros
}

void buscarPorID(int idBuscado) // Función que busca un registro por ID, pero no está implementada
{
}

void busccarPorID(int idBuscador) // Función que también busca un registro por ID, pero tiene un nombre incorrecto
{
}

void bucarPorID(int idBuscado) { // Función que busca un registro por ID, implementada correctamente
	ifstream archivo("datos.dat", ios::binary); // Abre el archivo 'datos.dat' en modo binario para lectura
	if (!archivo.is_open()) { // Verifica si el archivo se ha abierto correctamente
		cerr << "Error abriendo archivo!"; // Si no se pudo abrir, muestra un mensaje de error en la salida de error
		return; // Sale de la función.
	}
	Registro reg; // Declara una variable de tipo Registro para almacenar temporalmente los datos leídos del archivo
	bool encontrado = false; // Inicializa una variable booleana para indicar si se encontró el registro
	while (archivo.read(reinterpret_cast<char*>(&reg), sizeof(Registro)) && !encontrado) { // Lee registros del archivo hasta que se encuentre el registro buscado o no haya más datos
		if (reg.id == idBuscado) { // Verifica si el ID del registro leído coincide con el ID buscado

			cout << "\nRegistro encontrado:" // Muestra un mensaje indicando que se encontró el registro
				<< "\nNombre: " << reg.nombre // Muestra el nombre del registro encontrado
				<< "\nSalario: " << reg.salario << endl; // Muestra el salario del registro encontrado
			encontrado = true; // Cambia el estado de 'encontrado' a true, indicando que el registro fue encontrado
		}
	}
	if (!encontrado) cout << "Registro no encontrado!" << endl; // Si no se encontró el registro, muestra un mensaje correspondiente.
	archivo.close(); // Cierra el archivo después de haber buscado el registro.
}
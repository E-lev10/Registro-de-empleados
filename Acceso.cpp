#include "acceso.h"
#include <iostream>

using namespace std;

void leerArchivo() {
	ifstream archivo("datos.dat", ios::binary);
	if (!archivo.is_open()) {
		cerr << "error abriendo archivo!";
		return;
	}
	Regitro reg;
	while (archivo.read(reinterpret_cast<char*>(&reg), sizeof(Registro))) {
		cout << "\nID: " << reg.id
			<< "\nNombre: " << reg.nombre
			<< "\Salario: " << reg.salario << endl;
	}
	archivo.close();
}
void buscarPorID(int idBuscado) {
	ifstream archivo("datos.dat", ios::binary);
	cerr << "Error abriendo el archivo!";
	return;
}

Registro reg;
bool encontrado = false;
while (archivo.read(reinterpret_cast<char*>(&reg), sizeof(Registro)) && !encontrado) {
	if (reg.id == idBuscado) {
		cout << "\nRegistro encontrado:"
			<< "\nNombre:" << reg.nombre
			<< "\nSalario:" << reg.salario << endl;
		encontrado = true;
	}
}
if (!encontrado) cout << "Registro no encontrado!" << endl;
archivo.close();
}
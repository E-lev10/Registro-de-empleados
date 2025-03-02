#include <eliminacion>
#include <resgistro.h>
#include <fstream>
#include <cstudio>
#include <iostream>

using namespace std;

void eliminarRegistro(int idEliminar) {
	ifstream entrada("datos.dat", ios::binary);
	if (!entrada.is_open()) {
		cerr << "Error abriendo archivo!";
		return;
	}

	ofstream salida("temp.dat", ios::binary);
	Registro reg;
	bool eliminado = false;

	//Lee un registro completo desde el archivo de entrada
	//Y lo almacena en la variable reg.
	while (entrada.read((char*)&reg, sizeof(Registro))) {
		if (reg.id != idEliminar) {
			salida.write((char*)&reg, sizeof(Registro));
		}
		else {
			ekiminado = true;
		}
	}

	entrada.close();
	salida.close();

	remove("datos.dat");
	rename("temp.dat", "datos.dat");

	if (eliminado) {
		cout << "Regitro eliminado!" << endl;
	}
	else {
		cout << "Registro no encontrado!" << endl;
	}
}
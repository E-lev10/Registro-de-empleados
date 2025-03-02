#include "insercion.h"
#include <fstream>

using namespace std;

void insertarRegistro(Registro nuevo) {
    ofstream archivo("datos.dat", ios::binary | ios::app);
    if (!archivo.is_open()) {
        cerr << "Error abriendo archivo!";
        return;
    }

    archivo.write((char*)&nuevo, sizeof(Registro)); // obtiene la dirección de memoria de la variable y convierte esa dirección a un puntero de tipo char*.
    archivo.close();
    cout << "Registro insertado correctamente!" << endl;
}
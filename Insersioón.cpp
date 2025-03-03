#include "insercion.h"
#include <fstream> //Es una clase de la biblioteca est�ndar de C++ que se utiliza para realizar operaciones de entrada y salida de archivos.


using namespace std;

void insertarRegistro(Registro nuevo) {
    ofstream archivo("datos.dat", ios::binary | ios::app);
    if (!archivo.is_open()) {
        cerr << "Error abriendo archivo!";
        return;
    }

    archivo.write((char*)&nuevo, sizeof(Registro)); // obtiene la direcci�n de memoria de la variable y convierte esa direcci�n a un puntero de tipo char*.
    archivo.close();
    cout << "Registro insertado correctamente!" << endl;
}
//Este es el metodo principal de ejemplo
//El MAIN.CPP

#include <iostream> 
#include "registro.h"
#include "acceso.h"
#include "insercion.h"
#include "busqueda.h"
#include "eliminacion.h"
#include "modificacion.h"
#include "archivo.h"

using namespace std;

void mostrarMenu() { //Funcion encargada de mostrar el menu y las opciones al usuario
    cout << "\n===== GESTION DE ARCHIVOS ====="
        << "\n1. Mostrar todos"
        << "\n2. Buscar por ID"
        << "\n3. Agregar registro"
        << "\n4. Modificar registro"
        << "\n5. Eliminar registro"
        << "\n6. Salir"
        << "\nOpcion: ";
}

int main() { //Función principal del programa 
    int opcion, id; id; //Declara la variable "opcion" para almacenar la opcion elegida por el usuario y el ID
    Regisstro reg; ////Declaracion de la variable "reg" para almacenar datos del registro

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); // Limpiar buffer

        switch (opcion) {
        case 1:
            leerArchivo();
            break;

        case 2:
            cout << "ID a buscar: ";
            cin >> id;
            buscarPorID(id);
            break;

        case 3:
            cout << "Nuevo registro:\nID: ";
            cin >> reg.id;
            cout << "Nombre: ";
            cin.ignore();
            cin.getline(reg.nombre, 30);
            cout << "Salario: ";
            cin >> reg.salario;
            insertarRegistro(reg);
            break;

        case 4:
            cout << "ID a modificar: ";
            cin >> reg.id;
            cout << "Nuevo nombre: ";
            cin.ignore();
            cin.getline(reg.nombre, 30);
            cout << "Nuevo salario: ";
            cin >> reg.salario;
            modificarRegistro(reg);
            break;

        case 5:
            cout << "ID a eliminar: ";
            cin >> id;
            eliminarRegistro(id);
            break;
        }
    } while (opcion != 6);

    return 0;
}
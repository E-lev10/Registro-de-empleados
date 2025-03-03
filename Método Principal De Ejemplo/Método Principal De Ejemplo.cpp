#include <iostream> // Biblioteca para entrada y salida de datos 
#include <fstream> // Biblioteca para manje de archivos
#include "registro.h" // Archivo de encabezado con la estructura Registro
#include "acceso.h" // Archivo de encabezado para funciones de acceso a archivos
#include "insersion.h" // Archivo de encabezado para insertar registros 
#include "busqueda.h" // Archivo de encabezado para buscar registros 
#include "eliminacion.h" // Archivo de encabezado para eliminar registros 
#include "modificacion.h" // Archivo de encabezado para modificar registros 

using namespace std; //  Evita la necesidad de usar std:: en cada función de la biblioteca estándar

void mostrarMenu() { //Función que muestra el menú de opciones al usuario.
    cout << "\n===== GESTION DE ARCHIVOS =====" << endl; // Imprime el título del menú en la consola
    cout << "1. Mostrar todos" << endl; // Muestra la opción 1 en el menú, que permite al usuario mostrar todos los registros
    cout << "2. Buscar por ID" << endl; // Muestra la opción 2 en el menú, que permite al usuario buscar un registro específico por su ID
    cout << "3. Agregar registro" << endl; // Muestra la opción 3 en el menú, que permite al usuario agregar un nuevo registro
    cout << "4. Modificar registro" << endl; // Muestra la opción 4 en el menú, que permite al usuario modificar un registro existente
    cout << "5. Eliminar registro" << endl; // Muestra la opción 5 en el menú, que permite al usuario eliminar un registro específico
    cout << "6. Salir" << endl; // Muestra la opción 6 en el menú, que permite al usuario salir del programa
    cout << "Opcion: "; // Imprime el texto "Opcion: " para solicitar al usuario que ingrese su elección
}

int main() { //Función principal donde se ejecuta el flujo del programa.
    int opcion, id; // Variables para la opción seleccionada y el ID del registro
    Registro reg;  // Variable para almacenar los datos de un registro

    do { // Bucle 'do-while' para mostrar el menú y manejar las opciones hasta que el usuario elija salir.
        mostrarMenu(); // Muestra el menú en cada iteración
        while (!(cin >> opcion)) {// Validación de entrada para asegurar que sea un número
            cout << "Entrada invalida. Intente de nuevo: "; // Muestra un mensaje de error si la entrada no es válida.
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');// Elimina caracteres no válidos del buffer
        }

        switch (opcion) { //Estructura de control para ejecutar diferentes acciones según la opción ingresada por el usuario.
        case 1: // Caso que llama a la función para mostrar todos los registros.
            leerArchivo();// Llama a la función que muestra todos los registros
            break; // Termina el bloque del caso actual y sale del switch, evitando que se ejecuten otros casos

        case 2: // Caso para buscar un registro por su ID.
            cout << "ID a buscar: "; // Muestra un mensaje solicitando al usuario que ingrese el ID del registro que desea buscar.
            while (!(cin >> id)) { // Llama a la función que muestra todos los registros
                break; // Rompe el bucle inmediatamente, lo que no permite repetir la entrada
                cout << "Entrada invalida. Intente de nuevo: "; // Este código nunca se ejecutará debido al 'break' anterior
                cin.clear(); // Limpia el estado de error de 'cin' para permitir nuevas lecturas
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Elimina caracteres no válidos del buffer de entrada hasta el final de la línea
            }
            buscarPorID(id);// Llama a la función para buscar el registro por ID

            break; // Termina el bloque del caso actual y sale del switch, evitando que se ejecuten otros casos.

        case 3: // Caso para agregar un nuevo registro.
            cout << "Nuevo registro:" << endl; // Muestra un mensaje indicando que se va a ingresar un nuevo registro
            cout << "ID: "; // Solicita al usuario que ingrese el ID del nuevo registro
            while (!(cin >> reg.id)) { // Validación de entrada para ID
                cout << "Entrada invalida. Intente de nuevo: "; // Muestra un mensaje de error si la entrada no es válida
                cin.clear(); // Limpia el estado de error de 'cin' para permitir nuevas lecturas
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Elimina caracteres no válidos del buffer de entrada hasta el final de la línea
            }
            cin.ignore(); // Limpia el buffer para evitar problemas con getline
            cout << "Nombre: "; // Solicita al usuario que ingrese el nombre del nuevo registro
            cin.getline(reg.nombre, 30);// Captura el nombre del registro
            cout << "Salario: "; // Solicita al usuario que ingrese el salario del nuevo registro
            while (!(cin >> reg.salario)) { // Validación de entrada para salario
                cout << "Entrada invalida. Intente de nuevo: "; // Muestra un mensaje de error si la entrada no es válida
                cin.clear(); // Limpia el estado de error de 'cin' para permitir nuevas lecturas
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Elimina caracteres no válidos del buffer de entrada hasta el final de la línea
            }
            insertarRegistro(reg);// Inserta el nuevo registro en el archivo
            break; // Termina el bloque del caso actual y sale del switch.

        case 4: //Caso para modificar un registro existente.
            cout << "ID a modificar: "; // Solicita al usuario que ingrese el ID del registro que desea modificar
            while (!(cin >> reg.id)) { // Validación de entrada para ID
                cout << "Entrada invalida. Intente de nuevo: "; // Muestra un mensaje de error si la entrada no es válida.
                cin.clear(); // Limpia el estado de error de 'cin' para permitir nuevas lecturas
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Elimina caracteres no válidos del buffer de entrada hasta el final de la línea
            }
            cin.ignore(); // Limpia el buffer antes de capturar el nombre
            cout << "Nuevo nombre: "; // Solicita al usuario que ingrese el nuevo nombre del registro
            cin.getline(reg.nombre, 30);// Captura el nuevo nombre
            cout << "Nuevo salario: "; // Solicita al usuario que ingrese el nuevo salario del registro
            while (!(cin >> reg.salario)) {// Validación de entrada para salario
                cout << "Entrada invalida. Intente de nuevo: "; // Muestra un mensaje de error si la entrada no es válida
                cin.clear(); // Limpia el estado de error de 'cin' para permitir nuevas lecturas
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Elimina caracteres no válidos del buffer de entrada hasta el final de la línea
            }
            modificarRegistro(reg);// Llama a la función para modificar el registro
            break; // Termina el bloque del caso actual y sale del switch.

        case 5: // Caso para eliminar un registro mediante su ID.
            cout << "ID a eliminar: "; // Solicita al usuario que ingrese el ID del registro que desea eliminar
            while (!(cin >> id)) { // Validación de entrada para ID
                cout << "Entrada invalida. Intente de nuevo: "; // Muestra un mensaje de error si la entrada no es válida
                cin.clear(); // Limpia el estado de error de 'cin' para permitir nuevas lecturas
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Elimina caracteres no válidos del buffer de entrada hasta el final de la línea
            }
            eliminarRegistro(id); // Llama a la función para eliminar el registro
            break; // Termina el bloque del caso actual y sale del switch.

        case 6: // Caso para salir del programa.
            cout << "Saliendo del programa..." << endl; // Mensaje de salida
            break;// Termina el bloque del caso actual y sale del switch

        default: // Caso que maneja opciones no válidas ingresadas por el usuario.
            cout << "Opcion no valida. Intente de nuevo." << endl; // // Mensaje de error en caso de opción incorrecta
        }
    } while (opcion != 6); // Repite el bucle hasta que el usuario elija salir

    return 0; // Fin del programa

}
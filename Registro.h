#ifndef REGISTRO_H //  Verifica si REGISTRO_H no ha sido definido previamente
#define REGISTRO_H // Define REGISTRO_H para evitar m�ltiples inclusiones

#include <iostream> // Biblioteca est�ndar de entrada y salida, aunque no es necesaria en un archivo de encabezado sin funciones

// Definici�n de la estructura Registro
struct Registro {
	int id; // Identificador �nico del registro
	char nombre[30]; // Arreglo de caracteres para almacenar el nombre (hasta 29 caracteres + car�cter nulo)
	float salario; // Almacena el salario en formato de punto flotante
};

#endif // Fin de la directiva de preprocesador para evitar m�ltiples inclusiones.

#pragma once // Alternativa a la directiva de inclusi�n��nica.
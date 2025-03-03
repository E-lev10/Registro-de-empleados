#ifndef REGISTRO_H //  Verifica si REGISTRO_H no ha sido definido previamente
#define REGISTRO_H // Define REGISTRO_H para evitar múltiples inclusiones

#include <iostream> // Biblioteca estándar de entrada y salida, aunque no es necesaria en un archivo de encabezado sin funciones

// Definición de la estructura Registro
struct Registro {
	int id; // Identificador único del registro
	char nombre[30]; // Arreglo de caracteres para almacenar el nombre (hasta 29 caracteres + carácter nulo)
	float salario; // Almacena el salario en formato de punto flotante
};

#endif // Fin de la directiva de preprocesador para evitar múltiples inclusiones.

#pragma once // Alternativa a la directiva de inclusión única.
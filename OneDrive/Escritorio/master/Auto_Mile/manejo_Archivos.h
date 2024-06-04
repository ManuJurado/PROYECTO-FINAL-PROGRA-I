#ifndef MANEJO_ARCHIVOS_H_INCLUDED
#define MANEJO_ARCHIVOS_H_INCLUDED

#include "data_Management.h"
#include "menu.h"

//Definicion de variables globales para modularizar el codigo, ahorrar repeticiones y no tener la necesidad de pasar los datos por parametros
#define ARCHIPERSONAS "personas.dat"
#define ARCHI_VEHICULOS "Vehiculos.dat"

/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///

Persona administrador();
void guardarUsuario(Persona per);
void leerArchPersonas();
void eliminarPerson(Persona **listaPersonas, char nombrearch[],int posicionArray,int cantidadPersonas); ///<-------------------- ACOMODAR FUNCION SIN PUNTERO DOBLE

/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///


/// FUNCIONES DE ARCHIVOS PARA GESTION VEHICULOS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION VEHICULOS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION VEHICULOS---------------------------------------------------------------------------------///

void leerArchiVehiculos();///funcion necesaria para leer el archivo y cargar el arreglo dinamico.
void agregarVehiculo();///Funcion para agregar la estructura de vehiculo cargada al archivo y al arreglo dinamico
void modificaVehiArch(Patente pat, int posArray);///funcion que recibe una patente y busca la posicion en la que se encuentra esa patente dentro del archivo. En base a eso se copia una posicion del arreglo dinamico en esa posicion del archivo.
int buscarPatenteArch(Patente pat);///funcion para buscar una patente dentro de un archivo de registros vehiculos



#endif // MANEJO_ARCHIVOS_H_INCLUDED

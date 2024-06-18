#ifndef MANEJO_ARCHIVOS_H_INCLUDED
#define MANEJO_ARCHIVOS_H_INCLUDED

#include "data_Management.h"
#include "menu.h"

//Definicion de variables globales para modularizar el codigo, ahorrar repeticiones y no tener la necesidad de pasar los datos por parametros
#define ARCHIPERSONAS "personas.dat"
#define ARCHI_VEHICULOS "Vehiculos.dat"
#define ARCHI_ALQUILERES "Alquileres.dat"

/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///

Persona administrador();
int buscarPersonaArch(int dni);//busca la persona dentro de larchivo, si existe devuelve la posicion inicial del registro dentro del archivo. Si no, devuelve -1
void guardarNuevoUsuarioArch(Persona per);
void modificaUsuArch(int dni, Persona aux);
void leerArchPersonas();
/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///


/// FUNCIONES DE ARCHIVOS PARA GESTION VEHICULOS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION VEHICULOS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION VEHICULOS---------------------------------------------------------------------------------///

//funcion necesaria para leer el archivo y cargar el arreglo dinamico.
void leerArchiVehiculos();
//Funcion para agregar la estructura de vehiculo cargada al archivo y al arreglo dinamico
void agregarVehiculo();
//funcion que recibe una patente y busca la posicion en la que se encuentra esa patente dentro del archivo. En base a eso se copia una posicion del arreglo dinamico en esa posicion del archivo.
void modificaVehiArch(Patente pat, int posArray);
//funcion para buscar una patente dentro de un archivo de registros vehiculos. Retorna la posicion dentro del archivo donde esta la patente encontrada o 0 si no lo encuentra.
int buscarPatenteArch(Patente pat);
//funcion que recibe una patente y busca la posicion en la que se encuentra esa patente dentro del archivo. Posteriormente da la posibilidad de "eliminar" el vehiculo
//en caso de estar activo, y de "restaurar" si el vehiculo ya se habia eliminado.
void cambiarEstadoActivoVehi(Patente pat);
//Funcion que muestra todos los datos de un vehiculo a traves de su patente
void mostrarPorPatente(Patente pat);
/// FUNCIONES DE ARCHIVOS PARA GESTION ALQUILERES---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION ALQUILERES---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION ALQUILERES---------------------------------------------------------------------------------///

void leerArchAlquileres();
//muestra los alquileres correspondientes a una persona en particular. Los almacena en un arreglo auxiliar y luego lo libera.
void mostrarAlquilerPorDni(int dni);
//muestra los alquileres correspondientes a una patente en particular. Los almacena en un arreglo auxiliar y luego lo libera.
void mostrarAlquilerPorPatente(Patente patAux);
/// Funciones de guardado y modificacion de archivo de alquiler.
/// El guardado utiliza realloc para incrementar el tamanio de la memoria dinamica asignada, y tambien se incluye el nuevo registro dentro de este arreglo
/// Se utilizaran en el dataManagement.

/// Función para registrar un alquiler. Esta funcion recibira la posicion seleccionada del arreglo dinamico de vehiculos activos del cual se elige alquilar por parte del usuario. Si el vehiculo esta disponible podra alquilarse, de caso contrario volveremos.
void registrarAlquiler(int posArrDinVehi,int x, int y);
void registrarAlquilerUsuario(int posArrDinVehi,int x, int y, int dni);
void guardarUnAlquiler(char nombreArch[], Alquiler **alquileres, int *cantidadRegistros, Alquiler nuevoAlquiler);

/// FUNCIONES DE ARCHIVOS PARA GESTION ALQUILERES---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION ALQUILERES---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION ALQUILERES---------------------------------------------------------------------------------///





#endif // MANEJO_ARCHIVOS_H_INCLUDED

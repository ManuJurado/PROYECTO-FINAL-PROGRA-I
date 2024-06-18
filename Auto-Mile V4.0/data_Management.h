#ifndef DATA_MANAGEMENT_H_INCLUDED
#define DATA_MANAGEMENT_H_INCLUDED
#include <time.h>
///ESTRUCTURA PATENTE
typedef struct
{
    char letras[4];
    char numeros[4];
} Patente;

///ESTRUCTURA VEHICULO
typedef struct
{
    Patente patente;
    char marca[20];
    char modelo[20];
    int anio;
    int kms;
    float precioDeAlquilerDiario;
    char tipoVehiculo[20];   // 1-Auto, 2-Camioneta, 3-Utilitario
    int disponibilidad;   // 1-disponible, 0-no disponible
    int activo;   //1-activo, 0-eliminado
} Vehiculo;

///ESTRUCTURA PERSONA
typedef struct
{
    int dni;
    int activo; // 1 si esta activo, 0 si no.
    char nombre[50];
    char contra[30];
    char telefono[20];
    char direccion[100];
    char rol[20];

} Persona;

///ESTRUCTURA FECHA
typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

///ESTRUCTURA ALQUILER
typedef struct
{
    Fecha fechaInicio;
    Fecha fechaFin;
    Patente patenteVehi;
    int dniCliente;
    float precioTotal;
} Alquiler;

extern Persona *listaPersonas;
extern int cantidadPersonas;

extern Vehiculo *arrDinVehiculos;
extern int cantVehiculos;

extern Alquiler *arrDinAlquileres;
extern int cantAlquileres;


///FUNCIONES PARA GESTION DINAMICA DE USUARIOS---------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE USUARIOS---------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE USUARIOS---------------------------------------------------------------------------------///

void mostrarPersona(Persona usuario);
Persona buscarUsuarioArray(int dni, int *pos);
int tipoUsuario(int dni);
int entraUsuario(int dni,char contrasenia[]);/// retorna 2 si usuario y ctsenia son correctos, 1 si solo usuario correcto, 0 si no existe.
void modificarUsuarioEnArray(Persona per);
void copiaPersonaEnAux(Persona *auxPersona, int pos);
void copiaPersonaModificado(Persona auxPersona, int pos);
int verificarAdminOCliente(int dni);
void leerRegistroPersonas();

///FUNCIONES PARA GESTION DINAMICA DE USUARIOS--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE USUARIOS--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE USUARIOS--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///


///FUNCIONES PARA GESTION DINAMICA DE VEHICULOS-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE VEHICULOS-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE VEHICULOS-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///

// Función para validar si todos los caracteres en una cadena son dígitos
int sonNumerosKm(char str[], int longKms);
// Función para validar si todos los caracteres en una cadena son letras
int sonLetras(char str[]);
// Función para validar si todos los caracteres en una cadena son dígitos
int sonNumeros(char str[]);
// Función para convertir una cadena a mayúsculas
void convertirAMayusculas(char *cadena);
void cargaPatenteSinComprobacion(Patente *pat);
//carga la patente en un de un vehiculo. Devuelve 1 si pudo crearlo, 0 si no.
int cargaPatente(Patente *pat);
//Ingreso de Marca
void cargaMarca(char *marca);
//Ingreso de Modelo
void cargaModelo(char *modelo);
//Ingreso de Anio
void cargaAnio(int *anio);
void cargaKms(int *kms);
//Ingreso de Precio de Alquiler por dia
void cargaPrecioDiario(float *precioDeAlquilerDiario);
//Ingreso de Tipo (1-Auto / 2-Camioneta / 3-Utilitario)
void cargaTipo(char *tipoVehiculo);
//Funcion para ingresar un vehiculo
Vehiculo ingresoVehiculo();
//Funciones para printear los datos
void mostrarVehiculo(Vehiculo vehi);
//lee y muestra todos los registros de vehiculos dentro de un arreglo dinamico cargado
void leerRegistroVehiculos();
//misma funcion que leer Registros de vehiculos, pero con variante para seleccionar devolviendo por referencia la posicion en el arreglo dinamico en la que se encuentra el seleccionado.
void leerRegistroVehiculosSeleccion(int *posicion);
//Busca la patente de un vehiculo dentro del arreglo dinamigo. Si la encuentra devuelve 1, si no devuelve 0
int buscarPatenteArr(Patente pat, int *pos);
//funcion para contar la cantidad de vehiculos disponibles en un arrDin.
int contarVehiculosDisponibles();
//funcion que muestra un arreglo dinamico auxiliar de coches disponibles para su alquiler
void mostrarVehiculosDisponibles();

///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///

//funciones para mostrar la fecha del alquiler en cuestion. Se utilizan funciones que permiten almacenar en strings la fecha actual en la maquina local, y se utilizara para almacenar en la stfecha.
int obtenerMesDesdeCadena(const char *mesStr);
Fecha obtenerFechaHoraDesdeCadena(const char *cadenaTiempo);
// Función para mostrar la fecha y hora actual
void mostrarFechaHoraActual(const char *cadenaTiempo);
void mostrarFechaHoraAlquiler(Fecha fechaAlquiler);
///---------------------------------------------------------------------------------------///

///FUNCIONES DE MOSTRAR
//muestra un alquiler
void mostrarAlquiler(Alquiler alqui);
//lee y muestra todos los registros de alquieres dentro de un arreglo dinamico cargado
void leerRegistroAlquileres();
/// Autos disponibles para renta


/// Registra un alquiler para un vehiculo, que cambia el valor "disponible" de 1 a 0.(se realiza antes una verificacion dentro de la estructura dinamica de vehiculos, para ver cuales estan actualmente disponibles).
/// El registro modificado de vehiculo, deberia modificarse dentro de su correspondiente registro en el archivo. Esto se hace con una funcion "modificarVehiculo" comparando la patente. Esto permite al mismo tiempo que se guarda el
/// arreglo(no se modifica el malloc, ya que el arreglo dinamico deberi ser el mismo), se guarda el archivo.

///Funciones con validaciones para la carga de cada dato en struct alquileres

// Función para leer y validar un número en un rango específico
int leerNumero(const char* prompt, int min, int max, int maxDig);
Fecha cargarFecha(const char* prompt);
//verifica si una fecha de inicio es siempre menos a la fecha final
int esFechaValida(Fecha inicio, Fecha fin);
// Función para verificar si el DNI existe en el archivo y si la persona no está dada de baja
int verificarDNI(int dni);
// Función para validar y cargar un DNI
int cargarDNI(const char* prompt);
void invertirDisponibilidad(int *disponibilidad);
// Función para calcular la diferencia en días entre dos fechas
int calcularDias(Fecha inicio, Fecha fin);
// Función para leer los datos de un nuevo alquiler desde el usuario
Alquiler ingresoAlquiler(Patente patente, float precioPorDia);
Alquiler ingresoAlquilerUsuario(Patente patente, float precioPorDia, int dni);

/// FUNCIONES DE REPORTES Y ESTADISTICAS

// Implementación de la función para sumar importes por mes y año
float sumarImportesAlquileresPorMesYAnio(int mes, int anio);
// Implementación de la función que pide datos al usuario y llama a la función de suma
void pedirDatosYSumarImportes();
// Función para obtener la cantidad de días en un mes y año específicos
int obtenerDiasDelMes(int mes, int anio);
// Función para calcular los días dentro del mes y año especificados
int calcularDiasDentroDelMes(Fecha inicio, Fecha fin, int mes, int anio);
// Función para obtener el precio diario de un vehículo dado su patente
float obtenerPrecioDiario(Patente patente);
void mostrarVehiculos5aniosOrdenado();
void ordenamientoPorSeleccionArray(Vehiculo *arrDinVehiculoAux,int cantElementos, int anioActual);
//Funcion para mostrar el alquiler con mayor ingreso
void buscarAlquilerMayor();
//funcion para verificar el solapamiento entre fechas de un alquiler que se debe ingresar y uno que ya existe. Como los alquileres no pueden eliminarse, siempre se encontraran todos en el arrDinamico.
int alquilerSeSolapa(Alquiler *arrDinAlquileres, int cantAlquileres, Patente patente, Fecha inicio, Fecha fin);
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///


#endif // DATA_MANAGEMENT_H_INCLUDED

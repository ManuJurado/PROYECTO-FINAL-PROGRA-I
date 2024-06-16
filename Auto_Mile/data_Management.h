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
    int baja;
    char nombre[50];
    char contra[30];
    int telefono;
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
int buscarUsuarioArray(int dni, int *pos);
int tipoUsuario(int dni);
int entraUsuario(int dni[],char contrasenia[]);/// retorna 2 si usuario y ctsenia son correctos, 1 si solo usuario correcto, 0 si no existe.
void modificarUsuario();
void copiaPersonaEnAux(Persona *auxPersona, int pos);
void copiaPersonaModificado(Persona auxPersona, int pos);
int verificarAdminOCliente(int dni);

///FUNCIONES PARA GESTION DINAMICA DE USUARIOS--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE USUARIOS--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE USUARIOS--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///


///FUNCIONES PARA GESTION DINAMICA DE VEHICULOS-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE VEHICULOS-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE VEHICULOS-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///


int sonNumerosKm(char str[], int longKms);/// Funci�n para validar si todos los caracteres en una cadena son d�gitos
int sonLetras(char str[]);/// Funci�n para validar si todos los caracteres en una cadena son letras
int sonNumeros(char str[]);/// Funci�n para validar si todos los caracteres en una cadena son d�gitos
void cargaPatente(Patente *pat);///carga la patente en un de un vehiculo
void cargaMarca(char *marca);///Ingreso de Marca
void cargaModelo(char *modelo);///Ingreso de Modelo
void cargaAnio(int *anio);///Ingreso de Anio
void cargaKms(int *kms);///Ingreso de KMS
void cargaPrecioDiario(float *precioDeAlquilerDiario);///Ingreso de Precio de Alquiler por dia
void cargaTipo(char *tipoVehiculo);///Ingreso de Tipo (1-Auto / 2-Camioneta / 3-Utilitario);
void invertirDisponibilidad(int *disponibilidad); ///invierte la disponibilidad del vehiculo en el arreglo dinamico // <---------------terminar funcion ////
Vehiculo ingresoVehiculo();///Funcion para ingresar un vehiculo
void mostrarVehiculo(Vehiculo vehi);///Funciones para printear los datos
void leerRegistroVehiculos();///lee y muestra todos los registros de vehiculos dentro de un arreglo dinamico cargado
void leerRegistroVehiculosSeleccion(int *posicion);
int buscarPatenteArr(Patente pat, int *pos);///Busca la patente de un vehiculo dentro del arreglo dinamigo. Si la encuentra devuelve 1, si no devuelve 0
void copiaVehiEnAux(Vehiculo *auxVehiculo, int pos);///Funcion para copiar los datos del vehiculo encontrado, en un auxiliar donde se van a modificar los datos
void copiaVehiModificado(Vehiculo auxVehiculo, int pos);///copia un vehiculo que recibe por parametro en una posicion del arreglo dinamico, que tambien recibe por parametro.
void buscarVehiculoPorPatente(Patente patente);



///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///

///Funciones con validaciones para la carga de cada dato en struct alquileres

// Funci�n para leer y validar un n�mero en un rango espec�fico
int leerNumero(const char* prompt, int min, int max, int maxDig);
Fecha cargarFecha(const char* prompt);
// Funci�n para verificar si el DNI existe en el archivo y si la persona no est� dada de baja
int verificarDNI(int dni);
// Funci�n para validar y cargar un DNI
int cargarDNI(const char* prompt);
/// Funci�n para leer los datos de un nuevo alquiler desde el usuario
Alquiler ingresoAlquiler(Patente patente, float precioPorDia);

void mostrarAlquiler(Alquiler alqui);

//lee y muestra todos los registros de alquieres dentro de un arreglo dinamico cargado
void leerRegistroAlquileres();

// Implementaci�n de la funci�n para sumar importes por mes y a�o
float sumarImportesAlquileresPorMesYAnio(int mes, int anio);

// Implementaci�n de la funci�n que pide datos al usuario y llama a la funci�n de suma
void pedirDatosYSumarImportes();

// Funci�n para obtener la cantidad de d�as en un mes y a�o espec�ficos
int obtenerDiasDelMes(int mes, int anio);

// Funci�n para calcular los d�as dentro del mes y a�o especificados
int calcularDiasDentroDelMes(Fecha inicio, Fecha fin, int mes, int anio);

// Funci�n para obtener el precio diario de un veh�culo dado su patente
float obtenerPrecioDiario(Patente patente);

int encontrarAlquilerConMayorIngreso();
void mostrarAlquilerConMayorIngreso();


///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///



#endif // DATA_MANAGEMENT_H_INCLUDED

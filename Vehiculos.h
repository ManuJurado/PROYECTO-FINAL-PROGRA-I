#ifndef VEHICULOS_H_INCLUDED
#define VEHICULOS_H_INCLUDED


///ESTRUCTURA PATENTE
typedef struct
{
    char letras[3];
    char numeros[3];
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

#define FF fflush(stdin)
#define ESC 27
#define CLEAN system("cls")
#define COMPROBAR if(archiV==NULL){printf("El archivo no puede ser abierto.");}

//Definicion de variables globales para modularizar el codigo, ahorrar repeticiones y no tener la necesidad de pasar los datos por parametros
#define ARCHI_VEHICULOS "Vehiculos.dat"
extern Vehiculo *arrDinVehiculos;
extern int cantVehiculos;


///PROTOTIPADOS
void leerArchiVehiculos();
int sonLetras(char str[]);
int sonNumeros(char str[]);
void cargaPatente(Patente *pat);
void cargaMarca(char *marca);
void cargaModelo(char *modelo);
void cargaAnio(int *anio);
int sonNumerosKm(char str[], int longKms);
void cargaKms(int *kms);
void cargaPrecioDiario(float *precioDeAlquilerDiario);
void cargaTipo(char *tipoVehiculo);
Vehiculo ingresoVehiculo();
void agregarVehiculo();
void mostrarVehiculo(Vehiculo vehi);
void leerRegistroVehiculos();



#endif // VEHICULOS_H_INCLUDED

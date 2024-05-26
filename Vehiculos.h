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
    char tipoVehiculo[20];   // 1-Auto,2-Camioneta, 3-Utilitario
    int disponibilidad;   // 1-disponible, 0-no disponible
    int activo;   //1-activo, 0-eliminado
} Vehiculo;

///PROTOTIPADOS

void cargaMarca(char *marca);
void cargaModelo(char *modelo);
void cargaAnio(int *anio);
void cargaKms(int *kms);
void cargaPrecioDiario(float *precioDeAlquilerDiario);
void cargaTipo(char *tipoVehiculo);



#endif // VEHICULOS_H_INCLUDED

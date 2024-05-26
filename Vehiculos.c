#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "Vehiculos.h"

#define FF fflush(stdin)
#define ESC 27
#define CLEAN system("cls")
#define COMPROBAR if(archiV==NULL){printf("El archivo no puede ser abierto.");}
#define ARCHI_VEHICULOS "Vehiculos.dat"

/**
1. Gestión de Vehículos:
 - Agregar / modificar un vehículo. (Cuando se agrega, está disponible para alquilar.)
1. Agregar / modificar un vehículo:
 - Pedir datos como marca, modelo, año, kms, precio de adquisición, tipo de vehículo y disponibilidad.
 - Si es una modificación, permitir cambiar cualquiera de estos datos excepto la patente.
*/

//Ingreso de Patente
void cargaPatente(Patente *pat)
{
    char auxLetras[3];
    char auxNumeros[3];

    printf("\nIngrese la PATENTE del vehiculo (formato BBB999):\n> ");
    FF;
    gets((*pat).letras);
    printf("> ");
    FF;
    gets((*pat).numeros);
}

//Ingreso de Marca
void cargaMarca(char *marca)
{
    printf("\nIngrese la MARCA del vehiculo:\n> ");
    FF;
    gets(marca);
}

//Ingreso de Modelo
void cargaModelo(char *modelo)
{
    printf("\nIngrese el MODELO del vehiculo:\n> ");
    FF;
    gets(modelo);
}

//Ingreso de Anio
void cargaAnio(int *anio)
{
    int min = 1950;
    int max = 2024;
    int auxAnio;

    do
    {
        printf("\nIngrese el ANIO de fabricacion del vehiculo (entre %d y %d):\n> ", min, max);
        scanf("%d", &auxAnio);

        if (auxAnio >= min && auxAnio <= max)
        {
            *anio = auxAnio;
        }
        else
        {
            //CLEAN;
            printf("\nEl anio ingresado no es correcto. Intente nuevamente.\n");
        }
    }
    while (auxAnio < min || auxAnio > max);     //Se solicita la carga en un bucle do-while para que el usuario intente la carga hasta que ingrese un dato valido
}

//Ingreso de Kilometraje
void cargaKms(int *kms)
{
    int min = 0;
    int max = 300000;
    int auxKms;

    do
    {
        printf("\nIngrese el KILOMETRAJE del vehiculo (entre %d y %d):\n> ", min, max);
        scanf("%d", &auxKms);

        if (auxKms >= min && auxKms <= max)
        {
            *kms = auxKms;
        }
        else
        {
            //CLEAN;
            printf("\nEl kilometraje ingresado no es correcto. Intente nuevamente.\n");
        }
    }
    while (auxKms < min || auxKms > max);
}

//Ingreso de Precio de Alquiler por dia
void cargaPrecioDiario(float *precioDeAlquilerDiario)
{
    float min = 0;
    float max = 2000000;
    float auxPrecio;

    do
    {
        printf("\nIngrese el PRECIO DE ALQUILER DIARIO del vehiculo (entre $%.2f y $%.2f ARS):\n> ", min, max);
        scanf("%f", &auxPrecio);

        if (auxPrecio >= min && auxPrecio <= max)
        {
            *precioDeAlquilerDiario = auxPrecio;
        }
        else
        {
            //CLEAN;
            printf("\nEl precio ingresado no es correcto. Intente nuevamente.\n");
        }
    }
    while (auxPrecio < min || auxPrecio > max);
}

//Ingreso de Tipo (1-Auto / 2-Camioneta / 3-Utilitario)
void cargaTipo(char *tipoVehiculo)
{
    int tipo;
    char op1[] = "Auto";
    char op2[] = "Camioneta";
    char op3[] = "Utilitario";

    do
    {
        printf("\nIngrese el TIPO de vehiculo (1-Auto / 2-Camioneta / 3-Utilitario):\n> ");
        scanf("%i", &tipo);

        if (tipo >= 1 && tipo <= 3)
        {
            if(tipo == 1)           //dependiendo del nro ingresado asignarle el string correspondiente
            {
                strcpy(tipoVehiculo, op1);
            }
            else if(tipo == 2)
            {
                strcpy(tipoVehiculo, op2);
            }
            else
            {
                strcpy(tipoVehiculo, op3);
            }
        }
        else
        {
            //CLEAN;
            printf("\nEl tipo ingresado no es correcto. Intente nuevamente.\n");
        }
    }
    while (tipo < 1 || tipo > 3);
}

//Funcion para ingresar un vehiculo
Vehiculo ingresoVehiculo()
{
    Vehiculo vehi;
    Patente pat;

    cargaPatente(&pat);
    cargaMarca(&(vehi.marca));
    cargaModelo(&(vehi.modelo));
    cargaAnio(&(vehi.anio));
    cargaKms(&(vehi.kms));
    cargaPrecioDiario(&(vehi.precioDeAlquilerDiario));
    cargaTipo(&(vehi.tipoVehiculo));
    vehi.disponibilidad = 1;
    vehi.activo = 1;

    printf("\nPatente: %s", pat.letras, pat.numeros);
    printf("\nMarca: %s", vehi.marca);
    printf("\nModelo: %s", vehi.modelo);
    printf("\nAnio: %i", vehi.anio);
    printf("\nKilometraje: %ikms", vehi.kms);
    printf("\nPrecio de alquiler por dia: $%.2f", vehi.precioDeAlquilerDiario);
    printf("\nTipo de Vehiculo: %s", vehi.tipoVehiculo);
    if(vehi.disponibilidad == 1)
    {
        printf("\nVehiculo Disponible.");
    }
    else
    {
        printf("\nVehiculo NO Disponible.");
    }
    if(vehi.activo == 1)
    {
        printf("\nVehiculo Activo.");
    }
    else
    {
        printf("\nEl Vehiculo ha sido ELIMINADO del archivo.");
    }

    printf("\n\n");

}

//Funcion para agregar la estructura de vehiculo cargada al archivo y al arreglo dinamico
int agregarVehiculo(Vehiculo **cocheNuevo)
{
    FILE *archiV;
    archiV = fopen(ARCHI_VEHICULOS, "ab");

    char op;
    int cantVehiculos;
    Vehiculo vehiculo;
    Patente patente;

    COMPROBAR;
    if(archiV != NULL)
    {
        do
        {
            ingresoVehiculo();
            //AGREGAR INFORMACION EN ARREGLO DINAMICO Y REVISAR QUE DATOS DEBO AGREGAR EN LOS PARAMETROS DE LA FUNCION


            cantVehiculos++;

            printf("\nContinuar cargando alumnos? (ESC para finalizar)\n");
            FF;
            op = getch();
        }
        while(op != ESC);

        fclose(archiV);
    }

    return cantVehiculos;
}



/**
 - Ver listado de vehículos (marca, modelo, patente, tipo).
 2. Ver listado de vehículos:
 - Mostrar una tabla con marca, modelo, patente y tipo de todos los vehículos.
*/




/**
 - Ver vehículos disponibles (marca, modelo, patente, año, tipo).
 3. Ver vehículos disponibles:
 - Filtrar y mostrar los vehículos que tienen disponibilidad igual a 1.
*/




/**
 - Ver info de un vehículo (toda la info).
 4. Ver info de un vehículo:
 - Mostrar todos los datos de un vehículo dado su patente.
*/




/**
 4. Reportes y Estadísticas:
 - Ver los vehículos disponibles con menos de 5 años, por orden de antigüedad.
13. Ver vehículos disponibles con menos de 5 años:
 - Filtrar y mostrar los vehículos con disponibilidad igual a 1 y año mayor o igual al año actual menos 5,
ordenados por antigüedad.
*/




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

//Funcion inicial donde vamos a leer en el archivo la cantidad de vehiculos activos,
//que posteriormente cargaremos en el arreglo dinamico para trabajar en las consultas.
int leerArchiVehiculos(Vehiculo **vehiculos)
{
    FILE *archiV = fopen(ARCHI_VEHICULOS, "rb");
    int cantVehiculos, cont = 0;
    Vehiculo aux;

    COMPROBAR;

    if (archiV!= NULL)
    {
        while(fread((&aux), sizeof(Vehiculo), 1, archiV))
        {
            if(aux.activo == 1)
            {
                cantVehiculos++;
                mostrarVehiculo(aux);//LUEGO BORRAR ESTA LINEA, ESTA A MODO DE PRUEBA PARA VERIFICAR LOS DATOS AL EJECUTAR
            }
        }

        fseek(archiV, 0, SEEK_SET);

        *vehiculos = (Vehiculo*)malloc(cantVehiculos * sizeof(Vehiculo));

        while(fread(&aux, sizeof(Vehiculo), 1, archiV) && cont<(cantVehiculos+1))
        {
            if(aux.activo == 1)
            {
                (*vehiculos)[cont] = aux;
                cont++;
            }
        }
        fclose(archiV);
    }

    return cantVehiculos;
}

/**
1. Gestión de Vehículos:
 - Agregar / modificar un vehículo. (Cuando se agrega, está disponible para alquilar.)
1. Agregar / modificar un vehículo:
 - Pedir datos como marca, modelo, año, kms, precio de adquisición, tipo de vehículo y disponibilidad.
 - Si es una modificación, permitir cambiar cualquiera de estos datos excepto la patente.
*/

// Función para validar si todos los caracteres en una cadena son letras
int sonLetras(char str[])
{
    for (int i = 0; i < 3; i++)
    {
        if (!isalpha(str[i]))
        {
            return 0; // Falso
        }
    }
    return 1; // Verdadero
}

// Función para validar si todos los caracteres en una cadena son dígitos
int sonNumeros(char str[])
{
    for (int i = 0; i < 3; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0; // Falso
        }
    }
    return 1; // Verdadero
}

//Ingreso de Patente
void cargaPatente(Patente *pat)
{
    char auxLetras[4];
    char auxNumeros[4];

    do
    {
        printf("\nIngrese la PATENTE del vehiculo (formato BBB999):\n> ");
        FF;
        gets(&auxLetras);
        printf("> ");
        FF;
        gets(&auxNumeros);

        if (!sonLetras(auxLetras) || !sonNumeros(auxNumeros))
        {
            printf("Error en el formato ingresado. Las letras deben ser alfabeticas y los numeros deben ser digitos.\n");
        }
        else
        {
            // Copiar los valores a la estructura Patente
            strcpy(pat->letras, auxLetras);
            strcpy(pat->numeros, auxNumeros);
        }

    }
    while (!sonLetras(auxLetras) || !sonNumeros(auxNumeros));
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
    char auxAnioString[5]; // Suficientemente grande para un año + terminador nulo
    int auxAnioInt;

    do
    {
        printf("\nIngrese el ANIO de fabricacion del vehiculo (entre %d y %d):\n> ", min, max);
        scanf("%s", auxAnioString);

        if (sonNumeros(auxAnioString))
        {
            auxAnioInt = atoi(auxAnioString); // Convertir la cadena a entero
            if (auxAnioInt >= min && auxAnioInt <= max)
            {
                *anio = auxAnioInt;
                break;
            }
            else
            {
                printf("\nEl anio ingresado no esta dentro del rango permitido. Intente nuevamente.\n");
            }
        }
        else
        {
            printf("\nEntrada invalida. Por favor, ingrese un numero entero.\n");
        }
    }
    while (1);    // Bucle infinito hasta que se ingrese un dato válido
}
/* NO FUNCIONA PORQUE NO VALIDA QUE SEA UN DATO DE DIGITOS ENTEROS
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
*/
void cargaKms(int *kms)
{
    int min = 0;
    int max = 300000;
    char auxKmsString[7]; // Suficientemente grande para un kilometraje + terminador nulo
    int auxKmsInt;

    do
    {
        printf("\nIngrese el KILOMETRAJE del vehiculo (entre %d y %d):\n> ", min, max);
        scanf("%s", auxKmsString);

        if (sonNumeros(auxKmsString))
        {
            auxKmsInt = atoi(auxKmsString); // Convertir la cadena a entero
            if (auxKmsInt >= min && auxKmsInt <= max)
            {
                *kms = auxKmsInt;
                break;
            }
            else
            {
                printf("\nEl kilometraje ingresado no es correcto. Intente nuevamente.\n");
            }
        }
        else
        {
            printf("\nEntrada invalida. Por favor, ingrese un numero entero.\n");
        }
    }
    while (1);    // Bucle infinito hasta que se ingrese un dato válido
}
/*
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
*/
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

    cargaPatente(&(vehi.patente));
    cargaMarca(&(vehi.marca));
    cargaModelo(&(vehi.modelo));
    cargaAnio(&(vehi.anio));
    cargaKms(&(vehi.kms));
    cargaPrecioDiario(&(vehi.precioDeAlquilerDiario));
    cargaTipo(&(vehi.tipoVehiculo));
    vehi.disponibilidad = 1;
    vehi.activo = 1;
    /*
    printf("\nPatente: %s%s", vehi.patente.letras, vehi.patente.numeros);
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
        printf("\nEl Vehiculo ha sido ELIMINADO.");
    }
    printf("\n\n");
    */
    return vehi;
}

//Funcion para agregar la estructura de vehiculo cargada al archivo y al arreglo dinamico
agregarVehiculo(Vehiculo **vehiculos, int *cantVehiculos, Vehiculo nuevoVehiculo)
{
    FILE *archiV;
    archiV = fopen(ARCHI_VEHICULOS, "r+b");

    char op;
    Vehiculo vehiculo;
    Patente patente;

    //Redimensionar el arreglo dinámico para agregar el nuevo vehiculo
    *vehiculos = (Vehiculo *)realloc(*vehiculos, (*cantVehiculos + 1) * sizeof(Vehiculo));
    if (*vehiculos == NULL)
    {
        printf("Error al redimensionar el arreglo...");
        fclose(archiV);
        return;
    }

    COMPROBAR;
    if(archiV != NULL)
    {
        do
        {
            //Agregar el nuevo vehiculo al final del arreglo dinamico
            nuevoVehiculo = ingresoVehiculo();

            (*vehiculos)[*cantVehiculos] = nuevoVehiculo;

            (*cantVehiculos)++;

            //Mover el puntero del archivo al final y escribir el nuevo vehiculo
            fseek(archiV, 0, SEEK_END);
            fwrite(&nuevoVehiculo, sizeof(Vehiculo), 1, archiV);

            printf("\nIngrese ESC si no desea cargar otro vehiculo.\n");
            FF;
            op = getch();
        }
        while(op != ESC);

        fclose(archiV);
    }

    return cantVehiculos;
}

//Funciones para printear los datos
void mostrarVehiculo(Vehiculo vehi)
{
    printf("\nPatente: %s", vehi.patente.letras, vehi.patente.numeros);
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
        printf("\nEl Vehiculo ha sido ELIMINADO.");
    }
    printf("\n\n");
}

void leerRegistroVehiculos(Vehiculo *vehiculos)
{
    FILE *archiV;
    archiV = fopen (ARCHI_VEHICULOS, "rb");

    COMPROBAR;
    if (archiV != NULL)
    {
        printf("\nVehiculos disponibles: \n");
        while (fread(&vehiculos, sizeof(Vehiculo), 1, archiV) > 0)
        {
            //mostrarRegistro(&vehiculos);
        }
        fclose(archiV);
    }
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




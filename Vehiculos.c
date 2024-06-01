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

//Definicion de variables globales para modularizar el codigo, ahorrar repeticiones y no tener la necesidad de pasar los datos por parametros
#define ARCHI_VEHICULOS "Vehiculos.dat"
Vehiculo *arrDinVehiculos = NULL;
int cantVehiculos = 0;

//Funcion inicial donde vamos a leer en el archivo la cantidad de vehiculos activos,
//que posteriormente cargaremos en el arreglo dinamico para trabajar en las consultas.
void leerArchiVehiculos()
{
    FILE *archiV = fopen(ARCHI_VEHICULOS, "rb");
    int cont = 0;
    Vehiculo aux;

    cantVehiculos = 0;

    COMPROBAR;

    if (archiV!= NULL)
    {
        while(fread((&aux), sizeof(Vehiculo), 1, archiV))
        {
            if(aux.activo == 1)
            {
                cantVehiculos++;
                //mostrarVehiculo(aux);//LUEGO BORRAR ESTA LINEA, ESTA A MODO DE PRUEBA PARA VERIFICAR LOS DATOS AL EJECUTAR
            }
        }

        fseek(archiV, 0, SEEK_SET);

        arrDinVehiculos = (Vehiculo*)malloc(cantVehiculos * sizeof(Vehiculo));

        while(fread(&aux, sizeof(Vehiculo), 1, archiV) && cont<(cantVehiculos+1))
        {
            if(aux.activo == 1)
            {
                (arrDinVehiculos)[cont] = aux;
                cont++;
            }
        }
        fclose(archiV);
    }
}

/**
1. Gesti�n de Veh�culos:
 - Agregar / modificar un veh�culo. (Cuando se agrega, est� disponible para alquilar.)
1. Agregar / modificar un veh�culo:
 - Pedir datos como marca, modelo, a�o, kms, precio de adquisici�n, tipo de veh�culo y disponibilidad.
 - Si es una modificaci�n, permitir cambiar cualquiera de estos datos excepto la patente.
*/

// Funci�n para validar si todos los caracteres en una cadena son letras
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

// Funci�n para validar si todos los caracteres en una cadena son d�gitos
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
//void cargaPatente(Patente *pat)
//{
//    char auxLetras[3];
//    char auxNumeros[3];
//
//    do
//    {
//        printf("\nIngrese la PATENTE del vehiculo (formato BBB999):\n> ");
//        FF;
//        gets(auxLetras);
//        printf("> ");
//        FF;
//        gets(auxNumeros);
//
//        if (!sonLetras(auxLetras) || !sonNumeros(auxNumeros))
//        {
//            printf("Error en el formato ingresado. Las letras deben ser alfabeticas y los numeros deben ser digitos.\n");
//        }
//        else
//        {
//            // Copiar los valores a la estructura Patente
////            strcpy((*pat).letras, auxLetras);
////            strcpy((*pat).numeros, auxNumeros);
//            // Copiar los valores a la estructura Patente
//            strncpy(pat->letras, auxLetras, sizeof(auxLetras));
//            strncpy(pat->numeros, auxNumeros, sizeof(auxNumeros));
//            // Asegurar que las cadenas tengan un car�cter nulo al final
////            pat->letras[sizeof(auxLetras) - 1] = '\0';
////            pat->numeros[sizeof(auxNumeros) - 1] = '\0';
//        }
//
//    }
//    while (!sonLetras(auxLetras) || !sonNumeros(auxNumeros));
//}

void cargaPatente(Patente *pat)
{
    char auxLetras[4]; // Tama�o 4 para incluir el car�cter nulo
    char auxNumeros[4]; // Tama�o 4 para incluir el car�cter nulo

    do
    {
        printf("\nIngrese las letras de la patente (3 letras): ");
        fflush(stdin);
        fgets(auxLetras, sizeof(auxLetras), stdin);
        // Eliminar el car�cter de nueva l�nea si est� presente
        if (auxLetras[strlen(auxLetras) - 1] == '\n')
        {
            auxLetras[strlen(auxLetras) - 1] = '\0';
        }
        if (strlen(auxLetras) != 3 || !sonLetras(auxLetras))
        {
            printf("Error: Ingrese exactamente 3 letras alfab�ticas.\n");
            continue;
        }

        printf("Ingrese los n�meros de la patente (3 n�meros): ");
        fflush(stdin);
        fgets(auxNumeros, sizeof(auxNumeros), stdin);
        // Eliminar el car�cter de nueva l�nea si est� presente
        if (auxNumeros[strlen(auxNumeros) - 1] == '\n')
        {
            auxNumeros[strlen(auxNumeros) - 1] = '\0';
        }
        if (strlen(auxNumeros) != 3 || !sonNumeros(auxNumeros))
        {
            printf("Error: Ingrese exactamente 3 n�meros.\n");
            continue;
        }

        // Copiar los valores a la estructura Patente
        strncpy(pat->letras, auxLetras, sizeof(pat->letras) - 1); // Copiar solo los primeros 3 caracteres
        strncpy(pat->numeros, auxNumeros, sizeof(pat->numeros) - 1); // Copiar solo los primeros 3 caracteres
        pat->letras[sizeof(pat->letras) - 1] = '\0'; // Asegurar que la cadena est� terminada con '\0'
        pat->numeros[sizeof(pat->numeros) - 1] = '\0'; // Asegurar que la cadena est� terminada con '\0'

        break; // Salir del bucle si la patente es v�lida
    }
    while (1);
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
    char auxAnioString[5]; // Suficientemente grande para un a�o + terminador nulo
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
    while (1);    // Bucle infinito hasta que se ingrese un dato v�lido
}

// Funci�n para validar si todos los caracteres en una cadena son d�gitos
int sonNumerosKm(char str[], int longKms)
{
    for (int i = 0; i < longKms; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0; // Falso
        }
    }
    return 1; // Verdadero
}

void cargaKms(int *kms)
{
    int min = 0;
    int max = 300000;
    char auxKmsString[7]; // Suficientemente grande para un kilometraje + terminador nulo
    int auxKmsInt, longKms;

    do
    {
        printf("\nIngrese el KILOMETRAJE del vehiculo (entre %d y %d):\n> ", min, max);
        scanf("%s", auxKmsString);

        longKms = strlen(auxKmsString);

        if (sonNumerosKm(auxKmsString, longKms))
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
    while (1);    // Bucle infinito hasta que se ingrese un dato v�lido
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

invertirDisponibilidad(int *disponibilidad)
{
    if(disponibilidad == 1)
    {
        (*disponibilidad) = 0;
    }
    else
    {
        (*disponibilidad) = 1;
    }
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

    return vehi;
}

//Funcion para agregar la estructura de vehiculo cargada al archivo y al arreglo dinamico
void agregarVehiculo()
{
    FILE *archiV;
    archiV = fopen(ARCHI_VEHICULOS, "r+b");

    char op;
    Vehiculo nuevoVehiculo;
    Patente patente;

    //Redimensionar el arreglo din�mico para agregar el nuevo vehiculo
    arrDinVehiculos = (Vehiculo *)realloc(arrDinVehiculos, (cantVehiculos + 1) * sizeof(Vehiculo));
    if (arrDinVehiculos == NULL)
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

            (arrDinVehiculos)[cantVehiculos] = nuevoVehiculo;

            cantVehiculos++;

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
}

//Funciones para printear los datos
void mostrarVehiculo(Vehiculo vehi)
{
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

    //BORRAR DESPUES
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

void leerRegistroVehiculos()
{
    printf("\nVehiculos disponibles: \n");
    for(int i = 0; i<cantVehiculos; i++)
    {
        printf("---------------");
        mostrarVehiculo(arrDinVehiculos[i]);
        printf("---------------");
    }
}

//FUNCIONES PARA MODIFICAR UN VEHICULO
int buscarPatente(Patente pat, int *pos)
{
    for(int i = 0; i < cantVehiculos; i++)
    {
        if(strcmpi(arrDinVehiculos[i].patente.letras, pat.letras)  == 0 && strcmpi(arrDinVehiculos[i].patente.numeros, pat.numeros)  == 0)
        {
            printf("\nVehiculo encontrado.\n");

            mostrarVehiculo(arrDinVehiculos[i]);
            (*pos) = i;

            return 1;
        }
    }
    printf("\nVehiculo no encontrado.\n");

    return 0;
}

void modificarVehiculo()
{

    Patente patBusqueda;

    int pos = -1;

    printf("\nIngrese una patente del vehiculo a modificar:");
    cargaPatente(&patBusqueda);

    if(buscarPatente(patBusqueda, &pos) == 1)
    {
        int opMenu = 0;
        char opSalida, confirmacion;
        Vehiculo auxVehiculo;    //Se trabaja sobre un auxiliar para que al finalizar el menu, se puedan confirmar los cambios

        copiaVehiEnAux(&auxVehiculo, pos);

        do
        {
            mostrarVehiculo(auxVehiculo);
            printf("\n");
            printf("\n1-  Modificar la MARCA del vehiculo.");
            printf("\n2-  Modificar el MODELO del vehiculo.");
            printf("\n3-  Modificar el ANIO del vehiculo.");
            printf("\n4-  Modificar el KILOMETRAJE del vehiculo.");
            printf("\n5-  Modificar el PRECIO DE ALQUILER DIARIO del vehiculo.");
            printf("\n6-  Modificar el TIPO de vehiculo.");
            printf("\n7-  Modificar la DISPONIBILIDAD del vehiculo.");
            printf("\n> ");
            FF;
            scanf("%i", &opMenu);


            switch(opMenu)
            {
            case (1):
                    cargaMarca(&(auxVehiculo.marca));
                break;

            case (2):
                    cargaModelo(&(auxVehiculo.modelo));
                break;

            case (3):
                    cargaAnio(&(auxVehiculo.anio));
                break;

            case (4):
                    cargaKms(&(auxVehiculo.kms));
                break;

            case (5):
                    cargaPrecioDiario(&(auxVehiculo.precioDeAlquilerDiario));
                break;

            case (6):
                    cargaTipo(&(auxVehiculo.tipoVehiculo));
                break;

            case (7):
                    invertirDisponibilidad(&(auxVehiculo.disponibilidad));
                break;
            }

            printf("\nIngrese ESC para finalizar la modificacion...\n");
            opSalida = getch();
            CLEAN;
        }
        while (opSalida != ESC);

        printf("\nDesea guardar los cambios realizados? (Presione 's' para confirmar.)");
        FF;
        scanf("%c", &confirmacion);

        //CONFIRMACION PARA CAMBIAR DATOS DEL ARREGLO DINAMICO
        confirmacion = tolower(confirmacion); //Convierto el char a minuscula para asegurarme que entra el IF

        if(confirmacion == 's')
        {
            copiaVehiModificado(auxVehiculo, pos); //Reemplazar datos del auxVehiculo con el del arreglo dinamico en la posicion que se encuentra
        }

        //MODIFICAR EL VEHICULO EN EL ARCHIVO
    }
}

//Funcion para copiar los datos del vehiculo encontrado, en un auxiliar donde se van a modificar los datos
void copiaVehiEnAux(Vehiculo *auxVehiculo, int pos)
{
    strcpy((*auxVehiculo).marca, arrDinVehiculos[pos].marca);
    strcpy((*auxVehiculo).modelo, arrDinVehiculos[pos].modelo);
    (*auxVehiculo).anio = arrDinVehiculos[pos].anio;
    (*auxVehiculo).kms = arrDinVehiculos[pos].kms;
    (*auxVehiculo).precioDeAlquilerDiario = arrDinVehiculos[pos].precioDeAlquilerDiario;
    strcpy((*auxVehiculo).tipoVehiculo, arrDinVehiculos[pos].tipoVehiculo);
    (*auxVehiculo).disponibilidad = arrDinVehiculos[pos].disponibilidad;
}

void copiaVehiModificado(Vehiculo auxVehiculo, int pos)
{
    strcpy(arrDinVehiculos[pos].marca, auxVehiculo.marca);
    strcpy(arrDinVehiculos[pos].modelo, auxVehiculo.modelo);
    arrDinVehiculos[pos].anio = auxVehiculo.anio;
    arrDinVehiculos[pos].kms = auxVehiculo.kms;
    arrDinVehiculos[pos].precioDeAlquilerDiario = auxVehiculo.precioDeAlquilerDiario;
    strcpy(arrDinVehiculos[pos].tipoVehiculo, auxVehiculo.tipoVehiculo);
    arrDinVehiculos[pos].disponibilidad = auxVehiculo.disponibilidad;
}



/**
 - Ver listado de veh�culos (marca, modelo, patente, tipo).
 2. Ver listado de veh�culos:
 - Mostrar una tabla con marca, modelo, patente y tipo de todos los veh�culos.
*/




/**
 - Ver veh�culos disponibles (marca, modelo, patente, a�o, tipo).
 3. Ver veh�culos disponibles:
 - Filtrar y mostrar los veh�culos que tienen disponibilidad igual a 1.
*/




/**
 - Ver info de un veh�culo (toda la info).
 4. Ver info de un veh�culo:
 - Mostrar todos los datos de un veh�culo dado su patente.
*/




/**
 4. Reportes y Estad�sticas:
 - Ver los veh�culos disponibles con menos de 5 a�os, por orden de antig�edad.
13. Ver veh�culos disponibles con menos de 5 a�os:
 - Filtrar y mostrar los veh�culos con disponibilidad igual a 1 y a�o mayor o igual al a�o actual menos 5,
ordenados por antig�edad.
*/




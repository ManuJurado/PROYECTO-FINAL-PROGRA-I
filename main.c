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

void menuVehiculos();

int main()
{

    Vehiculo arrDin_VEHICULOS[100];

    menuVehiculos();

    return 0;
}

void menuVehiculos(char arrDin_VEHICULOS[])
{
    int cantVehiculos, ABM = 0;
    Vehiculo *vehiculos;
    char op;
    Vehiculo nuevoVehiculo;

    cantVehiculos = leerArchiVehiculos(&vehiculos);
    printf("\nCantidad de vehiculos: %i\n\n", cantVehiculos);

    //PRUEBA PARA VER SI EL ARREGLO ESTA BIEN CARGADO
    for(int i=0; i<cantVehiculos; i++)
    {
        printf("\n %i \n", i);
        //mostrarVehiculo(arrDin_VEHICULOS[i]); REVISAR FUNCION
    }

    do
    {
        printf("Ingrese el ABM del archivo:\n");
        printf("\n1-  Agregar un nuevo vehiculo.");
        printf("\n2-  Mostrar los vehiculos disponibles.");
        printf("\n3-  Modificar un vehiculo.");
        printf("\n> ");
        FF;
        scanf("%i", &ABM);


        switch(ABM)
        {
            case (1):
                agregarVehiculo(&vehiculos, &cantVehiculos, nuevoVehiculo);
            break;

            case (2):
                leerRegistroVehiculos(&vehiculos);
            break;

            case (3):

            break;

            case (4):

            break;

            case (5):

            break;
        }

        printf("\nIngrese ESC para finalizar...\n");
        op = getch();
        CLEAN;
    }while (op != ESC);

}


//VERIFICACION PARA INGRESAR EL PRECIO DEL VEHICULO CON 2 DECIMALES
    /*
    char precioChar[100];
    float precioFloat;

    printf("Ingrese un numero con 2 decimales: ");
    scanf("%s", precioChar);

    // Verificar que la entrada tenga el formato correcto
    int len = strlen(precioChar);
    char *dot = strchr(precioChar, '.');

    // Verificar que haya exactamente un punto decimal y dos dígitos después del punto
    if (dot != NULL && (dot - precioChar <= len - 3) && strlen(dot + 1) == 2) {
        // Convertir la cadena a un número float
        precioFloat = atof(precioChar);
        printf("Numero ingresado correctamente: %.2f\n", precioFloat);
    } else {
        printf("ERROR: Ingrese un numero con exactamente 2 decimales.\n");
    */

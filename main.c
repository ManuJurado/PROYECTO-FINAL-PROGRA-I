#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "Vehiculos.h"


void menuVehiculos();

int main()
{
    menuVehiculos();

    return 0;
}

void menuVehiculos()
{
    int ABM = 0;
    char op;

    leerArchiVehiculos();
    printf("\nCantidad de vehiculos: %i\n\n", cantVehiculos);

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
                agregarVehiculo();
            break;

            case (2):
                leerRegistroVehiculos();
            break;

            case (3):
                modificarVehiculo();
            break;

            case (4):
                //eliminarVehiculo();
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

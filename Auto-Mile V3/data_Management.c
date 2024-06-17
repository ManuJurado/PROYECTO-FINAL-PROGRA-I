#include "data_Management.h"
#include "manejo_Archivos.h"
#include "menu.h"

Vehiculo *arrDinVehiculos = NULL;
int cantVehiculos = 0;

Persona *listaPersonas = NULL;
int cantidadPersonas = 0;

Alquiler *arrDinAlquileres = NULL;
int cantAlquileres = 0;

///FUNCIONES PARA GESTION DINAMICA DE USUARIOS---------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE USUARIOS---------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE USUARIOS---------------------------------------------------------------------------------///

void mostrarPersona(Persona usuario)
{
    printf("Nombre:%s\n",usuario.nombre);
    printf("DNI: %s\n",usuario.dni);
}

Persona buscarUsuarioArray(int dni, int *pos)
{
    for(int i = 0; i < cantidadPersonas; i++)
    {
        if(listaPersonas[i].dni==dni)
        {
            (*pos)=i;
            return listaPersonas[i];
        }
    }
}

int tipoUsuario(int dni)
{
    for(int i = 0; i < cantidadPersonas; i++)
    {
        if(listaPersonas[i].dni==dni)
        {
            return (strcmpi(listaPersonas[i].rol,"Cliente")) ? 1 : 0;
        }
    }
    return -1;
}

int entraUsuario(int dni[],char contrasenia[])/// retorna 2 si usuario y ctsenia son correctos, 1 si solo usuario correcto, 0 si no existe.
{
    int i=0;
    while(i<cantidadPersonas)
    {
        if(listaPersonas[i].dni==dni)
        {
            if(strcmp(listaPersonas[i].contra,contrasenia)==0)
            {
                return 2; ///Usuario y contraseña correctos
            }
            else
            {
                return 1; ///Solo usuario correcto
            }
        }
        i++;
    }
    return 0;   ///Usuario no existe
}

void modificarUsuario(Persona per)
{
    int pos;
    buscarUsuarioArray(per.dni,&pos);
    listaPersonas[pos] = per;
}

void copiaPersonaEnAux(Persona *auxPersona, int pos)
{
    (*auxPersona).dni = listaPersonas[pos].dni;
    strcpy((*auxPersona).nombre, listaPersonas[pos].nombre);
    (*auxPersona).telefono = listaPersonas[pos].telefono;
    strcpy((*auxPersona).direccion,listaPersonas[pos].direccion);
    strcpy((*auxPersona).contra,listaPersonas[pos].contra);
}

void copiaPersonaModificado(Persona auxPersona, int pos)
{
    listaPersonas[pos].dni = auxPersona.dni;
    strcpy(listaPersonas[pos].nombre, auxPersona.nombre);
    listaPersonas[pos].telefono = auxPersona.telefono;
    strcpy(listaPersonas[pos].direccion, auxPersona.direccion);
    strcpy(listaPersonas[pos].contra, auxPersona.contra);
}

int verificarAdminOCliente(int dni)
{
    for(int i = 0; i<cantidadPersonas ; i++)
    {
        if(listaPersonas[i].dni == dni)
        {
            if(strcmpi(listaPersonas[i].rol,"Admin")==0)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
    return 0;
}

///FUNCIONES PARA GESTION DINAMICA DE USUARIOS--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE USUARIOS--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE USUARIOS--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///


///FUNCIONES PARA GESTION DINAMICA DE VEHICULOS-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE VEHICULOS-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE VEHICULOS-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///


// Función para validar si todos los caracteres en una cadena son dígitos
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

// Función para convertir una cadena a mayúsculas
void convertirAMayusculas(char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        cadena[i] = toupper(cadena[i]);
    }
}

//carga la patente en un de un vehiculo
void cargaPatente(Patente *pat)
{
    char auxLetras[4]; // Tamaño 4 para incluir el carácter nulo
    char auxNumeros[4]; // Tamaño 4 para incluir el carácter nulo

        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
        printf("Ingrese las letras de la patente (3 letras): ");
    do
    {
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-4);
        leerLimite(auxLetras, 3);

        if (strlen(auxLetras) != 3 || !sonLetras(auxLetras)) {
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
            printf("Error: Ingrese exactamente 3 letras alfabéticas.");
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-4);
            printf("             ");
            continue;
        }
        else{
            break;
        }
    }while (1);

        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-3);
        printf("Ingrese los números de la patente (3 números): ");
    do
    {
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-2);
        leerLimiteNumeros(auxNumeros, 3);

        if (strlen(auxNumeros) != 3 || !sonNumeros(auxNumeros)) {
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-3);
            printf("Error: Ingrese exactamente 3 números.        ");
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-2);
            printf("                       ");
            continue;
        }
        convertirAMayusculas(auxLetras);

        // Copiar los valores a la estructura Patente
        strncpy(pat->letras, auxLetras, sizeof(pat->letras) - 1); // Copiar solo los primeros 3 caracteres
        strncpy(pat->numeros, auxNumeros, sizeof(pat->numeros) - 1); // Copiar solo los primeros 3 caracteres
        pat->letras[sizeof(pat->letras) - 1] = '\0'; // Asegurar que la cadena esté terminada con '\0'
        pat->numeros[sizeof(pat->numeros) - 1] = '\0'; // Asegurar que la cadena esté terminada con '\0'

        break; // Salir del bucle si la patente es válida
    }while (1);

}

//Ingreso de Marca
void cargaMarca(char *marca)
{
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-1);
    printf("Ingrese la MARCA del vehiculo (max 15 caracteres): ");
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2));
    leerLimiteNumerosYLetras(marca, 15); // Limitar la entrada a 20 caracteres
    convertirAMayusculas(marca);
}

//Ingreso de Modelo
void cargaModelo(char *modelo)
{
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+1);
    printf("Ingrese el MODELO del vehiculo(max 15 caracteres): ");
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+2);
    leerLimiteNumerosYLetras(modelo, 15); // Limitar la entrada a 20 caracteres
    convertirAMayusculas(modelo);
}

//Ingreso de Anio
void cargaAnio(int *anio)
{
    int min = 1950;
    int max = 2024;
    char auxAnioString[5]; // Tamaño suficiente para un año de hasta 4 dígitos + terminador nulo
    int auxAnioInt;
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+3);
        printf("Ingrese el ANIO de fabricacion del vehiculo (entre %d y %d): ", min, max);

    do {
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+4);
        leerLimite(auxAnioString, 4); // Límite de 4 dígitos

        if (sonNumeros(auxAnioString)) {
            auxAnioInt = atoi(auxAnioString); // Convertir la cadena a entero

            if (auxAnioInt >= min && auxAnioInt <= max) {
                *anio = auxAnioInt;
                break;
            } else {
                gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+3);
                printf("El anio ingresado no esta dentro del rango permitido. Intente nuevamente.");
                gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+4);
                printf("         ");
            }
        } else {
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+3);
            printf("Entrada invalida. Por favor, ingrese un numero entero de hasta 4 digitos.");
        }
    } while (1); // Bucle infinito hasta que se ingrese un dato válido
}

void cargaKms(int *kms)
{
    int min = 0;
    int max = 300000;
    char auxKmsString[7]; // Tamaño suficiente para un kilometraje de hasta 6 dígitos + terminador nulo
    int auxKmsInt;

    do {
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+5);
        printf("Ingrese el KILOMETRAJE del vehiculo (entre %d y %d): ", min, max);
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+6);
        leerLimite(auxKmsString, 6); // Límite de 6 dígitos para el kilometraje

        if (sonNumeros(auxKmsString)) {
            auxKmsInt = atoi(auxKmsString); // Convertir la cadena a entero

            if (auxKmsInt >= min && auxKmsInt <= max) {
                *kms = auxKmsInt;
                break;
            } else {
                gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+5);
                printf("El kilometraje ingresado no está dentro del rango permitido. Intente nuevamente.");
                gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+6);
                printf("                           ");
            }
        } else {
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+5);
            printf("Entrada inválida. Por favor, ingrese un número entero de hasta 6 dígitos.");
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+6);
            printf("                                ");
        }
    } while (1); // Bucle infinito hasta que se ingrese un dato válido
}

//Ingreso de Precio de Alquiler por dia
void cargaPrecioDiario(float *precioDeAlquilerDiario)
{
    float min = 0;
    float max = 2000000;
    float auxPrecio;
    char auxPrecioString[20];

    do
    {
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+7);
        printf("Ingrese el PRECIO DE ALQUILER DIARIO (hasta $%.2f ARS): ", max);
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+8);
        leerLimiteNumeros(auxPrecioString,7);
        sscanf(auxPrecioString, "%f", &auxPrecio);

        if (auxPrecio >= min && auxPrecio <= max)
        {
            *precioDeAlquilerDiario = auxPrecio;
            break;
        }
        else
        {
            //CLEAN;
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+7);
            printf("El precio ingresado no es correcto. Intente nuevamente.    ");
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+8);
            printf("                        ");
        }
    }
    while (1);
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
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+14);
        printf("Ingrese el TIPO de vehiculo (1-Auto / 2-Camioneta / 3-Utilitario): ");
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
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+13);
            printf("El tipo ingresado no es correcto. Intente nuevamente.");
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+14);
        }
    }
    while (tipo < 1 || tipo > 3);
}

//invierte la disponibilidad del vehiculo en el arreglo dinamico
void invertirDisponibilidad(int *disponibilidad) /// <---------------terminar funcion ///
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

//Funciones para printear los datos
void mostrarVehiculo(Vehiculo vehi)
{
    MUTEXLOCK;
    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)-2));
    printf("Patente: %s - %s", vehi.patente.letras, vehi.patente.numeros);
    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)));
    printf("Marca: %s", vehi.marca);
    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)+2));
    printf("Modelo: %s", vehi.modelo);
    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)+4));
    printf("Anio: %i", vehi.anio);
    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)+6));
    printf("Kilometraje: %ikms", vehi.kms);
    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)+8));
    printf("Precio por dia: $%.2f", vehi.precioDeAlquilerDiario);
    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)+10));
    printf("Tipo de Vehiculo: %s", vehi.tipoVehiculo);
    if(vehi.disponibilidad == 1)
    {
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+10),((medidasConsola.alto/2)-(ALTO/2)+12));
        printf("[Vehiculo Disponible]");
    }
    else
    {
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)+12));
        printf("[Vehiculo NO Disponible]");
    }
    if(strcmpi(vehi.tipoVehiculo,"Camioneta")==0)
    {
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+28,((medidasConsola.alto/2)-(ALTO/2)-2));
        printf("                           .------.");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+28,((medidasConsola.alto/2)-(ALTO/2)-1));
        printf("                          :|||\"\"\"`.`.");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+28,((medidasConsola.alto/2)-(ALTO/2)));
        printf("                          :|||     7.`.");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+28,((medidasConsola.alto/2)-(ALTO/2)+1));
        printf("       .===+===+===+===+===||`----L7'-`7`---.._");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+28,((medidasConsola.alto/2)-(ALTO/2)+2));
        printf("       []                  || ==       |       \"\"\"-.");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+28,((medidasConsola.alto/2)-(ALTO/2)+3));
        printf("       []...._____.........||........../ _____ ____|");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+28,((medidasConsola.alto/2)-(ALTO/2)+4));
        printf("      c\\____/,---.\\_       ||_________/ /,---.\\_  _/");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+28,((medidasConsola.alto/2)-(ALTO/2)+5));
        printf("        /_,-/ ,-. \\ `._____|__________||/ ,-. \\ \\_[");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+28,((medidasConsola.alto/2)-(ALTO/2)+6));
        printf("           /\\ `-' /                    /\\ `-' /");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+28,((medidasConsola.alto/2)-(ALTO/2)+7));
        printf("                 `---'                       `---' ");
    }
    else if(strcmpi(vehi.tipoVehiculo,"Auto")==0)
    {
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+24,((medidasConsola.alto/2)-(ALTO/2)));
        printf("                        _..-------++._");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+24,((medidasConsola.alto/2)-(ALTO/2)+1));
        printf("                    _.-'/ |      _||  \"--._");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+24,((medidasConsola.alto/2)-(ALTO/2))+2);
        printf("              __.--'`._/_\\j_____/_||___\\    `----.");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+24,((medidasConsola.alto/2)-(ALTO/2)+3));
        printf("         _.--'_____    |          \\     _____    /");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+24,((medidasConsola.alto/2)-(ALTO/2)+4));
        printf("       _j    /,---.\\   |        =o |   /,---.\\   |_");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+24,((medidasConsola.alto/2)-(ALTO/2)+5));
        printf("      [__]==// .-. \\\\==`===========/==// .-. \\\\=[__]");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+24,((medidasConsola.alto/2)-(ALTO/2)+6));
        printf("        `-._|\\ `-' /|___\\_________/___|\\ `-' /|_.'     ");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+24,((medidasConsola.alto/2)-(ALTO/2)+7));
        printf("                   `---'                     `---'\n");
    }
    else if(strcmpi(vehi.tipoVehiculo,"Utilitario")==0)
    {
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+35,((medidasConsola.alto/2)-(ALTO/2))-1);
        printf("    ---------------------------.");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+35,((medidasConsola.alto/2)-(ALTO/2)));
        printf("   `/\"\"\"\"/\"\"\"\"/|\"\"|'|\"\"||\"\"|   ' \\");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+35,((medidasConsola.alto/2)-(ALTO/2))+1);
        printf("   /    /    / |__| |__||__|      |");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+35,((medidasConsola.alto/2)-(ALTO/2))+2);
        printf("  /----------=====================|");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+35,((medidasConsola.alto/2)-(ALTO/2)+3));
        printf("  | \\  /V\\  /    _.               |");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+35,((medidasConsola.alto/2)-(ALTO/2)+4));
        printf("  |()\\ \\W/ /()   _            _   |");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+35,((medidasConsola.alto/2)-(ALTO/2)+5));
        printf("  |   \\   /     / \\          / \\  |-( )");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+35,((medidasConsola.alto/2)-(ALTO/2)+6));
        printf("  =C========C==_| ) |--------| ) _/==] ");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1)+35,((medidasConsola.alto/2)-(ALTO/2)+7));
        printf("   \\_\\_/__..  \\_\\_/_ \\_\\_/ \\_\\_/__.__.");

    }
    MUTEXUNLOCK;
//
//    //BORRAR DESPUES
//    if(vehi.activo == 1)
//    {
//        printf("\nVehiculo Activo.");
//    }
//    else
//    {
//        printf("\nEl Vehiculo ha sido ELIMINADO.");
//    }
//    printf("\n\n");
}

//lee y muestra todos los registros de vehiculos dentro de un arreglo dinamico cargado
void leerRegistroVehiculos()
{
    char opcion;
    int i=0;
    mostrarVehiculo(arrDinVehiculos[i]);
    MUTEXLOCK;
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
    printf("Vehiculo %d de %d", i+1, cantVehiculos);
    MUTEXUNLOCK;
    do
    {
        fflush(stdin);
        opcion = getch();
        if(opcion !=0)
        {
            if (opcion == -32)
            {
                opcion = getch();
                switch (opcion)
                {
                case (75):      //moverse izquierda
                    i--;
                    if(i<0)
                    {
                        i=cantVehiculos-1;
                    }
                    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                    mostrarVehiculo(arrDinVehiculos[i]);
                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
                    printf("Vehiculo %d de %d", i+1, cantVehiculos);
                    MUTEXUNLOCK;
                    last_key=75;
                    Sleep(750);
                    break;
                case (77):      //moverse derecha
                    i++;
                    if(i>cantVehiculos-1)
                    {
                        i=0;
                    }
                    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                    mostrarVehiculo(arrDinVehiculos[i]);
                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
                    printf("Vehiculo %d de %d", i+1, cantVehiculos);
                    MUTEXUNLOCK;
                    last_key=77;
                    Sleep(750);
                    break;
                }
            }
            else if (opcion == ESC) //sale del if si se presiona ESC
            {
                break;
            }
        }
    }while(opcion != ESC); // ESC

}

///misma funcion que leer Registros de vehiculos, pero con variante para seleccionar devolviendo por referencia la posicion en el arreglo dinamico en la que se encuentra el seleccionado.
void leerRegistroVehiculosSeleccion(int *posicion)
{
    char opcion;
    int i=0;
    mostrarVehiculo(arrDinVehiculos[i]);
    MUTEXLOCK;
    gotoxy((medidasConsola.ancho/2 - 8),(medidasConsola.alto/2-ALTO/2)-8);
    printf("Vehiculo %d de %d", i+1, cantVehiculos);
    MUTEXUNLOCK;
    do
    {

        fflush(stdin);
        opcion = getch();

        if(opcion !=0)
        {
            if (opcion == -32)
            {
                opcion = getch();
                switch (opcion)
                {
                case (75):      //moverse izquierda
                    i--;
                    if(i<0)
                    {
                        i=cantVehiculos-1;
                    }
                    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                    mostrarVehiculo(arrDinVehiculos[i]);

                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2 - 8),(medidasConsola.alto/2-ALTO/2)-8);
                    printf("Vehiculo %d de %d", i+1, cantVehiculos);
                    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+8),((medidasConsola.alto/2)-(ALTO/2)+15));
                    printf("[PRESIONE ENTER PARA SELECCIONAR]");
                    MUTEXUNLOCK;
                    last_key=75;
                    Sleep(750);
                    break;
                case (77):      //moverse derecha
                    i++;
                    if(i>cantVehiculos-1)
                    {
                        i=0;
                    }
                    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                    mostrarVehiculo(arrDinVehiculos[i]);
                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2 - 8),(medidasConsola.alto/2-ALTO/2)-8);
                    printf("Vehiculo %d de %d", i+1, cantVehiculos);
                    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+8),((medidasConsola.alto/2)-(ALTO/2)+15));
                    printf("[PRESIONE ENTER PARA SELECCIONAR]");
                    MUTEXUNLOCK;
                    last_key=77;
                    Sleep(750);
                    break;
                }
            }
            else if (opcion == ESC || opcion == 13) //sale del if si se presiona ESC o ENTER
            {
                break;
            }
        }
    }while(opcion != ESC && opcion != 13); // ESC o ENTER

    if(opcion == 13){
            *posicion=i;
    }
}

//Busca la patente de un vehiculo dentro del arreglo dinamigo. Si la encuentra devuelve 1, si no devuelve 0
int buscarPatenteArr(Patente pat, int *pos)
{
    for(int i = 0; i < cantVehiculos; i++)
    {
        if(strcmpi(arrDinVehiculos[i].patente.letras, pat.letras)  == 0 && strcmpi(arrDinVehiculos[i].patente.numeros, pat.numeros)  == 0)
        {
            (*pos) = i;

            return 1;
        }
    }
    printf("Vehiculo no encontrado.");

    return 0;
}

void buscarVehiculoPorPatente(Patente patente)
{
    int posicion = -1;
    int encontrado = buscarPatenteArr(patente, &posicion);

    if (encontrado)
    {
        printf("\nVehículo encontrado en la posición %d.\n", posicion);
        // Aquí podrías realizar otras acciones con el vehículo encontrado si es necesario
    }
    else
    {
        printf("\nVehículo no encontrado.\n");
    }
}

//Funcion para copiar los datos del vehiculo encontrado, en un auxiliar donde se van a modificar los datos
void copiaVehiEnAux(Vehiculo *auxVehiculo, int pos)
{
    strcpy((*auxVehiculo).marca, arrDinVehiculos[pos].marca);
    strcpy((*auxVehiculo).modelo, arrDinVehiculos[pos].modelo);
    strcpy(auxVehiculo->patente.letras, arrDinVehiculos[pos].patente.letras);
    strcpy(auxVehiculo->patente.numeros, arrDinVehiculos[pos].patente.numeros);
    (*auxVehiculo).anio = arrDinVehiculos[pos].anio;
    (*auxVehiculo).kms = arrDinVehiculos[pos].kms;
    (*auxVehiculo).precioDeAlquilerDiario = arrDinVehiculos[pos].precioDeAlquilerDiario;
    strcpy((*auxVehiculo).tipoVehiculo, arrDinVehiculos[pos].tipoVehiculo);
    (*auxVehiculo).disponibilidad = arrDinVehiculos[pos].disponibilidad;
}

//copia un vehiculo que recibe por parametro en una posicion del arreglo dinamico, que tambien recibe por parametro.
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


///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///


///funciones para mostrar la fecha del alquiler en cuestion. Se utilizan funciones que permiten almacenar en strings la fecha actual en la maquina local, y se utilizara para almacenar en la stfecha.
int obtenerMesDesdeCadena(const char *mesStr) {
    if (strcmp(mesStr, "Jan") == 0) return 1;
    if (strcmp(mesStr, "Feb") == 0) return 2;
    if (strcmp(mesStr, "Mar") == 0) return 3;
    if (strcmp(mesStr, "Apr") == 0) return 4;
    if (strcmp(mesStr, "May") == 0) return 5;
    if (strcmp(mesStr, "Jun") == 0) return 6;
    if (strcmp(mesStr, "Jul") == 0) return 7;
    if (strcmp(mesStr, "Aug") == 0) return 8;
    if (strcmp(mesStr, "Sep") == 0) return 9;
    if (strcmp(mesStr, "Oct") == 0) return 10;
    if (strcmp(mesStr, "Nov") == 0) return 11;
    if (strcmp(mesStr, "Dec") == 0) return 12;
    return -1; // Error
}

Fecha obtenerFechaHoraDesdeCadena(const char *cadenaTiempo)
{
    char mesStr[4]; // Para almacenar el mes como cadena

    Fecha fechaACambiar;
    // Usamos sscanf para analizar la cadena de tiempo y extraer los componentes de la fecha y la hora
    sscanf(cadenaTiempo, "%*s %3s %d %*d:%*d:%*d %d", mesStr, fechaACambiar.dia, fechaACambiar.anio);

    // Convertir el mes de cadena a número
    fechaACambiar.mes = obtenerMesDesdeCadena(mesStr);

    return fechaACambiar;
}

/// Función para mostrar la fecha y hora actual
void mostrarFechaHoraActual(const char *cadenaTiempo)
{
    // Obtener la cadena de tiempo actual
    time_t tiempo_actual = time(NULL);
    cadenaTiempo = ctime(&tiempo_actual);

    // Convertir la cadena de tiempo en una estructura FechaHora
    Fecha fecha_hora_actual = obtenerFechaHoraDesdeCadena(cadenaTiempo);

    // Imprimir los componentes de la fecha y la hora
    printf("Fecha y hora actual: %d/%d/%d %02d:%02d:%02d\n",
        fecha_hora_actual.dia,
        fecha_hora_actual.mes,
        fecha_hora_actual.anio
    );
}

void mostrarFechaHoraAlquiler(Fecha fechaAlquiler)
{
     printf("Fecha y hora del alquiler: %d/%d/%d\n",
        fechaAlquiler.dia,
        fechaAlquiler.mes,
        fechaAlquiler.anio
    );
}

///---------------------------------------------------------------------------------------///

///FUNCIONES DE MOSTRAR
//muestra un alquiler
void mostrarAlquiler(Alquiler alqui)
{
    MUTEXLOCK;
    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)-2));
    printf("Patente de vehiculo alquilado: %s - %s", alqui.patenteVehi.letras, alqui.patenteVehi.numeros);
    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)));
    printf("DNI cliente: %d", alqui.dniCliente);
    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)+2));
    printf("Fecha inicio de alquiler: %d / %d / %d", alqui.fechaInicio.dia,alqui.fechaInicio.mes,alqui.fechaInicio.anio);
    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)+4));
    printf("Fecha fin de alquiler: %d / %d / %d", alqui.fechaFin.dia,alqui.fechaFin.mes,alqui.fechaFin.anio);
    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)+6));
    printf("Precio total de alquiler: %.2f $", alqui.precioTotal);
    MUTEXUNLOCK;
}

//lee y muestra todos los registros de alquieres dentro de un arreglo dinamico cargado
void leerRegistroAlquileres()
{
    char opcion;
    int i=0;
    mostrarAlquiler(arrDinAlquileres[i]);
    MUTEXLOCK;
    gotoxy((medidasConsola.ancho/2 - 8),(medidasConsola.alto/2-ALTO/2)-8);
    printf("Alquiler %d de %d", i+1, cantAlquileres);
    MUTEXUNLOCK;
    do
    {

        fflush(stdin);
        opcion = getch();

        if(opcion !=0)
        {
            if (opcion == -32)
            {
                opcion = getch();
                switch (opcion)
                {
                case (75):      //moverse izquierda
                    i--;
                    if(i<0)
                    {
                        i=cantAlquileres-1;
                    }
                    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                    mostrarAlquiler(arrDinAlquileres[i]);
                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2 - 8),(medidasConsola.alto/2-ALTO/2)-8);
                    printf("Alquiler %d de %d", i+1, cantAlquileres);
                    MUTEXUNLOCK;
                    last_key=75;
                    Sleep(750);
                    break;
                case (77):      //moverse derecha
                    i++;
                    if(i>cantAlquileres-1)
                    {
                        i=0;
                    }
                    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                    mostrarAlquiler(arrDinAlquileres[i]);
                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2 - 8),(medidasConsola.alto/2-ALTO/2)-8);
                    printf("Alquiler %d de %d", i+1, cantAlquileres);
                    MUTEXUNLOCK;
                    last_key=77;
                    Sleep(750);
                    break;
                }
            }
            else if (opcion == ESC) //sale del if si se presiona ESC
            {
                break;
            }
        }
    }while(opcion != ESC); // ESC

}

/// Autos disponibles para renta


/// Registra un alquiler para un vehiculo, que cambia el valor "disponible" de 1 a 0.(se realiza antes una verificacion dentro de la estructura dinamica de vehiculos, para ver cuales estan actualmente disponibles).
/// El registro modificado de vehiculo, deberia modificarse dentro de su correspondiente registro en el archivo. Esto se hace con una funcion "modificarVehiculo" comparando la patente. Esto permite al mismo tiempo que se guarda el
/// arreglo(no se modifica el malloc, ya que el arreglo dinamico deberi ser el mismo), se guarda el archivo.

///Funciones con validaciones para la carga de cada dato en struct alquileres

// Función para leer y validar un número en un rango específico
int leerNumero(const char* prompt, int min, int max, int maxDig)
{
    char input[3]; // Máximo 2 dígitos + terminador nulo
    int num, valido = 0;

    while (!valido) {
        printf("%s (%d-%d): ", prompt, min, max);
        leerLimiteNumeros(input, maxDig);

        if (isdigit(input[0])) {
            num = atoi(input);
            if (num >= min && num <= max) {
                valido = 1;
            } else {
                printf("Número fuera de rango. Intente de nuevo.");
            }
        } else {
            printf("Entrada no válida. Intente de nuevo.");
        }
    }

    return num;
}

Fecha cargarFecha(const char* prompt)
{
    Fecha fecha;
    printf("%s\n", prompt);

    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-1);
    fecha.dia = leerNumero("Ingrese el día\n", 1, 31,2);
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-2);
    fecha.mes = leerNumero("Ingrese el mes\n", 1, 12,2);
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-3);
    fecha.anio = leerNumero("Ingrese el año\n", 1900, 9999,4);

    return fecha;
}

// Función para verificar si el DNI existe en el archivo y si la persona no está dada de baja
int verificarDNI(int dni)
{
    FILE *archivo = fopen(ARCHIPERSONAS, "rb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 0;
    }

    Persona persona;
    while (fread(&persona, sizeof(Persona), 1, archivo)) {
        if (persona.dni == dni && persona.baja == 1) {
            fclose(archivo);
            return 1; // DNI encontrado y la persona no está dada de baja
        }
    }

    fclose(archivo);
    return 0; // DNI no encontrado o la persona está dada de baja
}

// Función para validar y cargar un DNI
int cargarDNI(const char* prompt)
{
    char input[9 + 1]; // +1 para el terminador nulo
    int dni, valido = 0;

    while (!valido) {
        printf("%s: ", prompt);
        leerLimiteNumeros(input, 9);

        if (strlen(input) > 9) {
            printf("DNI no válido. Intente de nuevo.");
        } else {
            dni = atoi(input);
            if (dni == 0) {
                printf("DNI no válido. Intente de nuevo.");
            } else if (!verificarDNI(dni)) {
                printf("DNI no encontrado o la persona está dada de baja. Intente de nuevo.");
            } else {
                valido = 1;
            }
        }
    }

    return dni;
}

// Función para calcular la diferencia en días entre dos fechas
int calcularDias(Fecha inicio, Fecha fin)
{
    int diasInicio = inicio.anio * 365 + inicio.mes * 30 + inicio.dia;
    int diasFin = fin.anio * 365 + fin.mes * 30 + fin.dia;
    return diasFin - diasInicio;
}

/// Función para leer los datos de un nuevo alquiler desde el usuario
Alquiler ingresoAlquiler(Patente patente, float precioPorDia)
{
    Alquiler nuevoAlquiler;
    nuevoAlquiler.patenteVehi = patente;
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+1);
    printf("%s %s", nuevoAlquiler.patenteVehi.letras,nuevoAlquiler.patenteVehi.numeros);

    nuevoAlquiler.fechaInicio = cargarFecha("Ingrese la fecha de inicio");
    nuevoAlquiler.fechaFin = cargarFecha("Ingrese la fecha de fin");

    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
    nuevoAlquiler.dniCliente = cargarDNI("ingrese DNI del cliente");

    int diasDeAlquiler = calcularDias(nuevoAlquiler.fechaInicio,nuevoAlquiler.fechaFin);
    nuevoAlquiler.precioTotal = (float)diasDeAlquiler * precioPorDia;

    return nuevoAlquiler;
}

/// Funcion de Administrador y Cliente. Para esta funcion necesitamos varias comprobaciones: desde comprobaciones de fecha(no puede reservar un coche en una fecha anterior a la actual siendo cliente),
/// que el vehiculo a rentar este disponible, hacer una verificacion de toda la lista de vehiculos que, con la patente, podemos verificar el estado de alquiler en el que se encuentra y si ya llego a la fecha de finalizacion
/// de alquiler, cambiando el estado de toda la lista de vehiculos disponibles dependiendo de esto(para esto se trabaja con funcion de lectura y guardado de archivos tambien en esta funcion).
/// Se pide que se determine la fecha de renta del vehiculo. Todo vehiculo rentado pasara a estar "no disponible" con lo cual no figurara en la lista
/// de mostrar disponibles para alquiler, a menos que(continuar con funciones)...

/// FUNCIONES DE REPORTES Y ESTADISTICAS

// Implementación de la función para sumar importes por mes y año
float sumarImportesAlquileresPorMesYAnio(int mes, int anio) {
    float sumaTotal = 0.0;

    for (int i = 0; i < cantAlquileres; i++) {
        int diasDentroDelMes = calcularDiasDentroDelMes(arrDinAlquileres[i].fechaInicio, arrDinAlquileres[i].fechaFin, mes, anio);
        if (diasDentroDelMes > 0) {
            float precioDiario = obtenerPrecioDiario(arrDinAlquileres[i].patenteVehi);
            sumaTotal += diasDentroDelMes * precioDiario;
        }
    }

    return sumaTotal;
}

// Implementación de la función que pide datos al usuario y llama a la función de suma
void pedirDatosYSumarImportes() {
    int mes, anio;

    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-3);
    printf("Ingrese el mes (1-12): ");
    scanf("%d", &mes);

    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-1);
    printf("Ingrese el año: ");
    scanf("%d", &anio);

    float total = sumarImportesAlquileresPorMesYAnio(mes, anio);

    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+3);
    printf("El importe total de los alquileres en todo el mes %d de %d es: %.2f", mes, anio, total);
    Sleep(3000);
}

// Función para obtener la cantidad de días en un mes y año específicos
int obtenerDiasDelMes(int mes, int anio) {
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            // Verificar si es un año bisiesto
            if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
                return 29;
            } else {
                return 28;
            }
        default:
            return 0;
    }
}

// Función para calcular los días dentro del mes y año especificados
int calcularDiasDentroDelMes(Fecha inicio, Fecha fin, int mes, int anio) {
    int diasDelMes = obtenerDiasDelMes(mes, anio);
    int inicioDia = (inicio.mes == mes && inicio.anio == anio) ? inicio.dia : 1;
    int finDia = (fin.mes == mes && fin.anio == anio) ? fin.dia : diasDelMes;

    // Verificar que el rango de días es válido
    if (inicioDia > finDia) {
        return 0;
    }

    return finDia - inicioDia + 1;
}

// Función para obtener el precio diario de un vehículo dado su patente
float obtenerPrecioDiario(Patente patente) {
    for (int i = 0; i < cantVehiculos; i++) {
        if (strncmp(arrDinVehiculos[i].patente.letras, patente.letras, 3) == 0 &&
            strncmp(arrDinVehiculos[i].patente.numeros, patente.numeros, 3) == 0) {
            return arrDinVehiculos[i].precioDeAlquilerDiario;
        }
    }
    return 0.0; // Si no se encuentra la patente, retornar 0
}


///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///

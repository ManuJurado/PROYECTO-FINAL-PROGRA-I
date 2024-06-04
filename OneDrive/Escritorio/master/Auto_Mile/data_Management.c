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

int buscarUsuarioArray(int dni, int *pos)
{
    for(int i = 0; i < cantidadPersonas; i++)
    {
        if(listaPersonas[i].dni==dni)
        {
            (*pos)=i;
            return 1;
        }
    }
return 0;
}

int tipoUsuario(int dni)
{
    for(int i = 0; i < cantidadPersonas; i++)
    {
        if(listaPersonas[i].dni==dni)
        {
            return (strcmp(listaPersonas[i].rol,"Cliente")) ? 1 : 0;
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

void modificarUsuario()
{
    Persona usuarioModificacion;
    int busquedadni;

    int pos;

    printf("Ingrese el dni del usuario q desea modificar ");

    scanf("%d",&busquedadni);

    if (buscarUsuarioArray(busquedadni,&pos))
    {
        int opc=0;
        char salida,save;
        Persona auxPersona;

        copiaPersonaEnAux(&auxPersona,pos);
        do
        {
            printf("\n");
            printf("\n1-  Modificar la DNI del usuario");
            printf("\n2-  Modificar el NOMBRE del usuario");
            printf("\n3-  Modificar el TELEFONO del usuario");
            printf("\n4-  Modificar la DIRECCION del usuario");
            printf("\n5-  Modificar la CONTRASEÑA del usuario");
            printf("\n> ");

            scanf("%i", &opc);

            switch(opc)
            {
            case (1):
                printf("Ingrese el dni: ");
                /// funcion cargar DNI
                break;

            case (2):
                printf("Ingrese el nombre: ");
                /// funcion cargar nombre
                break;

            case (3):
                printf("Ingrese el telefono: ");
                /// funcion cargar telefono
                break;

            case (4):
                printf("Ingrese la direccion: ");
                /// funcion cargar direccion
                break;

            case (5):
                printf("Ingrese la contraseña: ");
                /// funcion cargar contrasenia
                break;
            }

            printf("\nIngrese ESC para finalizar la modificacion...\n");
            salida = getch();
        }while(salida != ESC);

        printf("Guardar cambios s/n");

        scanf("%c",&save);

        if (save=='s'||save=='S')
        {
            copiaPersonaModificado(auxPersona,pos);
        }
    }
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

//carga la patente en un de un vehiculo
void cargaPatente(Patente *pat)
{
    char auxLetras[4]; // Tamaño 4 para incluir el carácter nulo
    char auxNumeros[4]; // Tamaño 4 para incluir el carácter nulo

    do {
        printf("\nIngrese las letras de la patente (3 letras): ");
        fflush(stdin);
        fgets(auxLetras, sizeof(auxLetras), stdin);
        // Eliminar el carácter de nueva línea si está presente
        if (auxLetras[strlen(auxLetras) - 1] == '\n') {
            auxLetras[strlen(auxLetras) - 1] = '\0';
        }
        if (strlen(auxLetras) != 3 || !sonLetras(auxLetras)) {
            printf("Error: Ingrese exactamente 3 letras alfabéticas.\n");
            continue;
        }

        printf("Ingrese los números de la patente (3 números): ");
        fflush(stdin);
        fgets(auxNumeros, sizeof(auxNumeros), stdin);
        // Eliminar el carácter de nueva línea si está presente
        if (auxNumeros[strlen(auxNumeros) - 1] == '\n') {
            auxNumeros[strlen(auxNumeros) - 1] = '\0';
        }
        if (strlen(auxNumeros) != 3 || !sonNumeros(auxNumeros)) {
            printf("Error: Ingrese exactamente 3 números.\n");
            continue;
        }

        // Copiar los valores a la estructura Patente
        strncpy(pat->letras, auxLetras, sizeof(pat->letras) - 1); // Copiar solo los primeros 3 caracteres
        strncpy(pat->numeros, auxNumeros, sizeof(pat->numeros) - 1); // Copiar solo los primeros 3 caracteres
        pat->letras[sizeof(pat->letras) - 1] = '\0'; // Asegurar que la cadena esté terminada con '\0'
        pat->numeros[sizeof(pat->numeros) - 1] = '\0'; // Asegurar que la cadena esté terminada con '\0'

        break; // Salir del bucle si la patente es válida
    } while (1);
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
    while (1);    // Bucle infinito hasta que se ingrese un dato válido
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
    printf("\nPatente: %s - %s", vehi.patente.letras, vehi.patente.numeros);
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

//lee y muestra todos los registros de vehiculos dentro de un arreglo dinamico cargado
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

//Busca la patente de un vehiculo dentro del arreglo dinamigo. Si la encuentra devuelve 1, si no devuelve 0
int buscarPatenteArr(Patente pat, int *pos)
{
    for(int i = 0; i < cantVehiculos; i++)
    {
        if(strcmpi(arrDinVehiculos[i].patente.letras, pat.letras)  == 0 && strcmpi(arrDinVehiculos[i].patente.numeros, pat.numeros)  == 0)
        {
            printf("\n\n\n\nVehiculo encontrado.\n\n\n\n");

            mostrarVehiculo(arrDinVehiculos[i]);
            (*pos) = i;

            return 1;
        }
    }
    printf("\nVehiculo no encontrado.\n");

    return 0;
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


///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///

#include "data_Management.h"
#include "manejo_Archivos.h"
#include "gotoxy.h"
#include "presentacion.h"

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
    MUTEXLOCK;
    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+6),((medidasConsola.alto/2)-(ALTO/2)+1));
    printf("1 - Nombre:     %s", usuario.nombre);
    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+6),((medidasConsola.alto/2)-(ALTO/2)+3));
    printf("2 - Telefono:   %s", usuario.telefono);
    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+6),((medidasConsola.alto/2)-(ALTO/2)+5));
    printf("3 - Direcci%cn:  %s", 162, usuario.direccion);
    MUTEXUNLOCK;
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

int entraUsuario(int dni,char contrasenia[])/// retorna 2 si usuario y ctsenia son correctos, 1 si solo usuario correcto, 0 si no existe.
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

void modificarUsuarioEnArray(Persona per)
{
    int pos;
    buscarUsuarioArray(per.dni,&pos);
    listaPersonas[pos] = per;
}

void copiaPersonaEnAux(Persona *auxPersona, int pos)
{
    (*auxPersona).dni = listaPersonas[pos].dni;
    strcpy((*auxPersona).nombre, listaPersonas[pos].nombre);
    strcpy((*auxPersona).telefono,listaPersonas[pos].telefono);
    strcpy((*auxPersona).direccion,listaPersonas[pos].direccion);
    strcpy((*auxPersona).contra,listaPersonas[pos].contra);
}

void copiaPersonaModificado(Persona auxPersona, int pos)
{
    listaPersonas[pos].dni = auxPersona.dni;
    strcpy(listaPersonas[pos].nombre, auxPersona.nombre);
    strcpy(listaPersonas[pos].telefono, auxPersona.telefono);
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

void leerRegistroPersonas()
{
    char opcion;
    int i=0;
    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);

    MUTEXLOCK;
    gotoxy(medidasConsola.ancho/2-ANCHO/2+6,medidasConsola.alto/2-ALTO/2-5);
    printf("CLiente %d de %d", i+1, cantidadPersonas);
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+10);
    printf("ENTER para modificar / ESC para salir");
    MUTEXUNLOCK;

    mostrarPersona(listaPersonas[i]);

    do
    {
        FF;
        opcion = getch();
        if(opcion !=0)
        {
            if (opcion == -32)
            {
                opcion = getch();
                if (opcion == 75)   //moverse izquierda
                {
                    i--;
                    if(i<0)
                    {
                        i = cantidadPersonas-1;
                    }
                    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                    mostrarPersona(listaPersonas[i]);

                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2-ANCHO/2)+6,(medidasConsola.alto/2-ALTO/2)-5);
                    printf("CLiente %d de %d", i+1, cantidadPersonas);
                    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+10);
                    printf("ENTER para modificar / ESC para salir");
                    MUTEXUNLOCK;

                    last_key=75;
                }
                if (opcion == 77)      //moverse derecha
                {
                    i++;
                    if(i>cantidadPersonas-1)
                    {
                        i=0;
                    }

                    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                    mostrarPersona(listaPersonas[i]);

                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2-ANCHO/2)+6,(medidasConsola.alto/2-ALTO/2)-5);
                    printf("CLiente %d de %d", i+1, cantidadPersonas);
                    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+10);
                    printf("ENTER para modificar / ESC para salir");
                    MUTEXUNLOCK;

                    last_key=77;
                }
            }
        }
    }while(opcion != ESC && opcion != ENTER); // ESC
            if (opcion == ENTER)
            {
                menuModificarUsuario(medidasConsola.ancho,medidasConsola.alto-15,listaPersonas[i]);
            }

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
void convertirAMayusculas(char *cadena)
{
    for (int i = 0; cadena[i] != '\0'; i++) {
        cadena[i] = toupper(cadena[i]);
    }
}

void cargaPatenteSinComprobacion(Patente *pat)
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
            printf("Error: Ingrese exactamente 3 letras alfab%cticas.",130);
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-4);
            printf("             ");

            continue;
        }
        else{
            break;
        }
    }while (1);



        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-3);
        printf("Ingrese los n%cmeros de la patente (3 n%cmeros): ",163,163);
    do
    {

        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-2);
        leerLimiteNumeros(auxNumeros, 3);

        if (strlen(auxNumeros) != 3 || !sonNumeros(auxNumeros)) {

            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-3);
            printf("Error: Ingrese exactamente 3 n%cmeros.              ",163);
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

        break;//salir si la patente es valida
    }while (1);
}

//carga la patente en un de un vehiculo. Devuelve 1 si pudo crearlo, 0 si no.
int cargaPatente(Patente *pat)
{
    char opcion;
    char auxLetras[4]; // Tamaño 4 para incluir el carácter nulo
    char auxNumeros[4]; // Tamaño 4 para incluir el carácter nulo


    do{

        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
        printf("Ingrese las letras de la patente (3 letras): ");
    do
    {
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-4);
        leerLimite(auxLetras, 3);


        if (strlen(auxLetras) != 3 || !sonLetras(auxLetras)) {

            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
            printf("Error: Ingrese exactamente 3 letras alfab%cticas.",130);
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-4);
            printf("             ");

            continue;
        }
        else{
            break;
        }
    }while (1);



        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-3);
        printf("Ingrese los n%cmeros de la patente (3 números): ",163);
    do
    {

        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-2);
        leerLimiteNumeros(auxNumeros, 3);

        if (strlen(auxNumeros) != 3 || !sonNumeros(auxNumeros)) {

            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-3);
            printf("Error: Ingrese exactamente 3 n%cmeros.        ",163);
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

        break;//salir si la patente es valida
    }while (1);

    if(buscarPatenteArch(*pat) != -1){

            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2));
            printf("La patente ingresada ya existe en la base de datos...");
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+1);
            printf("(verificar estado de activo con administradores)");
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+3);
            printf("Desea ingresar otra patente?(s/n)");
            leerSn(&opcion);
            if(opcion == 'n'){
                return 0;
            }
        }
        else{

        return 1; // Salir del bucle si la patente es válida
        }
        MUTEXUNLOCK;
        cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
        MUTEXLOCK;

    }while (1);

}

//Ingreso de Marca
void cargaMarca(char *marca)
{
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-1);
    printf("Ingrese la MARCA del veh%cculo (max 15 caracteres): ",161);
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2));
    leerLimiteNumerosYLetras(marca, 15); // Limitar la entrada a 20 caracteres
    convertirAMayusculas(marca);
}

//Ingreso de Modelo
void cargaModelo(char *modelo)
{
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+1);
    printf("Ingrese el MODELO del veh%cculo(max 15 caracteres): ",161);
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
        printf("Ingrese el a%co de fabricaci%cn del veh%cculo (entre %d y %d): ",164,162,161, min, max);

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
                printf("El a%co ingresado no est%c dentro del rango permitido. Intente nuevamente.",164,160);
                gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+4);
                printf("         ");
            }
        } else {
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+3);
            printf("Entrada inv%clida. Por favor, ingrese un n%cmero entero de hasta 4 d%cgitos.",160,163,161);
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+4);
            printf("         ");
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
        printf("Ingrese el KILOMETRAJE del veh%cculo (entre %d y %d): ",161, min, max);
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+6);
        leerLimite(auxKmsString, 6); // Límite de 6 dígitos para el kilometraje

        if (sonNumeros(auxKmsString)) {
            auxKmsInt = atoi(auxKmsString); // Convertir la cadena a entero

            if (auxKmsInt >= min && auxKmsInt <= max) {
                *kms = auxKmsInt;
                break;
            } else {
                gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+5);
                printf("El kilometraje ingresado no est%c dentro del rango permitido. Intente nuevamente.",225);
                gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+6);
                printf("                           ");
            }
        } else {
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1, (medidasConsola.alto/2-ALTO/2)+5);
            printf("Entrada inv%clida. Por favor, ingrese un n%cmero entero de hasta 6 d%cgitos.",160,163,161);
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

//Funcion para ingresar un vehiculo
Vehiculo ingresoVehiculo()
{
    Vehiculo vehi;

    if(cargaPatente(&(vehi.patente))){
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
    printf("A%co: %i",164, vehi.anio);
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
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+10),((medidasConsola.alto/2)-(ALTO/2)+12));
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
        printf("             `---'                       `---' ");
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
        printf("              `---'                     `---'\n");
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

//misma funcion que leer Registros de vehiculos, pero con variante para seleccionar devolviendo por referencia la posicion en el arreglo dinamico en la que se encuentra el seleccionado.
void leerRegistroVehiculosSeleccion(int *posicion)
{
    char opcion;
    int i=0;
    mostrarVehiculo(arrDinVehiculos[i]);
    MUTEXLOCK;
    gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+8),((medidasConsola.alto/2)-(ALTO/2)+15));
    printf("[PRESIONE ENTER PARA SELECCIONAR]");
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
    else{
        *posicion=-1;
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
    return 0;
}

int contarVehiculosDisponibles()
{
    int contador = 0;
    for(int i = 0; i<cantVehiculos; i++)
    {
        if(arrDinVehiculos[i].disponibilidad==1)
        {
            contador++;
        }
    }
    return contador;
}

//funcion que muestra un arreglo dinamico auxiliar de coches disponibles para su alquiler
void mostrarVehiculosDisponibles()
{
    // Verificar si hay vehículos disponibles
    int cantVehiDisponibles = 0;
    for (int pos = 0; pos < cantVehiculos; pos++) {
        if (arrDinVehiculos[pos].disponibilidad == 1) {
            cantVehiDisponibles++;
        }
    }

    if (cantVehiDisponibles == 0) {
        printf("No hay vehículos disponibles para mostrar.\n");
        return;
    }

    // Asignar memoria para los vehículos disponibles
    Vehiculo *arrDinVehiDisp = malloc(cantVehiDisponibles * sizeof(Vehiculo));
    if (arrDinVehiDisp == NULL) {
        perror("Error al asignar memoria para vehículos disponibles");
        return;
    }

    // Copiar vehículos disponibles al nuevo arreglo
    int j = 0;
    for (int pos = 0; pos < cantVehiculos; pos++) {
        if (arrDinVehiculos[pos].disponibilidad == 1) {
            arrDinVehiDisp[j++] = arrDinVehiculos[pos];
        }
    }

    // Mostrar el primer vehículo y la cantidad total
    int i = 0;

    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
    mostrarVehiculo(arrDinVehiDisp[i]);
    MUTEXLOCK;
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
    printf("Vehiculo %d de %d", i+1, cantVehiDisponibles);
    MUTEXUNLOCK;

    char opcion;
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
                        i=cantVehiDisponibles-1;
                    }
                    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                    mostrarVehiculo(arrDinVehiDisp[i]);
                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
                    printf("Vehiculo %d de %d", i+1, cantVehiDisponibles);
                    MUTEXUNLOCK;
                    last_key=75;
                    break;
                case (77):      //moverse derecha
                    i++;
                    if(i>cantVehiDisponibles-1)
                    {
                        i=0;
                    }
                    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                    mostrarVehiculo(arrDinVehiDisp[i]);
                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
                    printf("Vehiculo %d de %d", i+1, cantVehiDisponibles);
                    MUTEXUNLOCK;
                    last_key=77;
                    break;
                }
            }
            else if (opcion == ESC) //sale del if si se presiona ESC
            {
                break;
            }
        }
    }while(opcion != ESC); // ESC
    free(arrDinVehiDisp);

    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
    MUTEXLOCK;
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
    printf("liberando memoria principal");
    tipeo("...",200);
    MUTEXUNLOCK;
}


///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///

///funciones para mostrar la fecha del alquiler en cuestion. Se utilizan funciones que permiten almacenar en strings la fecha actual en la maquina local, y se utilizara para almacenar en la stfecha.
int obtenerMesDesdeCadena(const char *mesStr)
{
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
    char input[maxDig + 1]; // Máximo dígitos + terminador nulo
    int num, valido = 0;
        printf("%s (%d-%d): ", prompt, min, max);

    while (!valido) {
        gotoxy(posicionActual.x,posicionActual.y+1);
        leerLimiteNumeros(input, maxDig);

        if (isdigit(input[0])) {
            num = atoi(input);
            if (num >= min && num <= max) {
                valido = 1;
            } else {
                gotoxy(posicionActual.x,posicionActual.y);
                printf("N%cmero fuera de rango. Intente de nuevo(entre %d y %d).               ",163, min, max);
                gotoxy(posicionActual.x,posicionActual.y+1);
                printf("                 ");
                gotoxy(posicionActual.x,posicionActual.y+1);
            }
        } else {
            gotoxy(posicionActual.x,posicionActual.y);
            printf("Entrada no v%clida. Intente de nuevo.                   ",160);
            gotoxy(posicionActual.x,posicionActual.y+1);
            printf("                   ");
            gotoxy(posicionActual.x,posicionActual.y+1);
        }
    }

    return num;
}

Fecha cargarFecha(const char* prompt)
{
    Fecha fecha;


    gotoxy((medidasConsola.ancho/2-ANCHO/2)+6,(medidasConsola.alto/2-ALTO/2)-1);
    printf("%s", prompt);
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+1);
    posicionActual.x = ((medidasConsola.ancho/2-ANCHO/2)+1);
    posicionActual.y = ((medidasConsola.alto/2-ALTO/2)+1);
    fecha.dia = leerNumero("Ingrese el dia", 1, 31,2);
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+3);
    posicionActual.x = ((medidasConsola.ancho/2-ANCHO/2)+1);
    posicionActual.y = ((medidasConsola.alto/2-ALTO/2)+3);
    fecha.mes = leerNumero("Ingrese el mes", 1, 12,2);
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+5);
    posicionActual.x = ((medidasConsola.ancho/2-ANCHO/2)+1);
    posicionActual.y = ((medidasConsola.alto/2-ALTO/2)+5);
    fecha.anio = leerNumero("Ingrese el anio", 2024, 2100,4);

    return fecha;
}

//verifica si una fecha de inicio es siempre menos a la fecha final
int esFechaValida(Fecha inicio, Fecha fin)
{
    if (inicio.anio > fin.anio){
        return 0;
    }
    if (inicio.anio == fin.anio && inicio.mes > fin.mes){
        return 0;
    }
    if (inicio.anio == fin.anio && inicio.mes == fin.mes && inicio.dia > fin.dia){
        return 0;
    }
    return 1;
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
        if (persona.dni == dni && persona.activo == 1) {
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

        gotoxy((medidasConsola.ancho/2-ANCHO/2)+6,(medidasConsola.alto/2-ALTO/2)-1);
        printf("%s: ", prompt);
    while (!valido) {
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+6,(medidasConsola.alto/2-ALTO/2));
        printf("                        ");
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+6,(medidasConsola.alto/2-ALTO/2));
        leerLimiteNumeros(input, 9);

        if (strlen(input) > 9) {
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+6,(medidasConsola.alto/2-ALTO/2)-1);
            printf("DNI no v%clido. Intente de nuevo.",160);
        } else {
            dni = atoi(input);
            if (dni == 0) {
                gotoxy((medidasConsola.ancho/2-ANCHO/2)+6,(medidasConsola.alto/2-ALTO/2)-1);
                printf("DNI no v%clido. Intente de nuevo.",160);
            } else if (!verificarDNI(dni)) {
                gotoxy((medidasConsola.ancho/2-ANCHO/2)+6,(medidasConsola.alto/2-ALTO/2)-1);
                printf("DNI no encontrado o la persona est%c dada de baja. Intente de nuevo.",160);
            } else {
                valido = 1;
            }
        }
    }

    return dni;
}

void invertirDisponibilidad(int *disponibilidad)
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
    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+1);
    MUTEXLOCK;
    printf("%s %s", nuevoAlquiler.patenteVehi.letras,nuevoAlquiler.patenteVehi.numeros);
    MUTEXUNLOCK;

    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
    MUTEXLOCK;
    nuevoAlquiler.fechaInicio = cargarFecha("Ingrese la fecha de inicio");
    MUTEXUNLOCK;
    do
    {
        cuadroMenuInstantaneo(medidasConsola.ancho, medidasConsola.alto - 15);
        MUTEXLOCK;
        nuevoAlquiler.fechaFin = cargarFecha("Ingrese la fecha de fin");
        MUTEXUNLOCK;
        gotoxy((medidasConsola.ancho / 2 - ANCHO / 2) + 1, (medidasConsola.alto / 2 - ALTO / 2)-1);
        printf("fecha inicio de alquiler: %d / %d / %d ", nuevoAlquiler.fechaInicio.dia,nuevoAlquiler.fechaInicio.mes,nuevoAlquiler.fechaInicio.anio);

        if (!esFechaValida(nuevoAlquiler.fechaInicio, nuevoAlquiler.fechaFin))
        {
            cuadroMenuInstantaneo(medidasConsola.ancho, medidasConsola.alto - 15);
            MUTEXLOCK;
            gotoxy((medidasConsola.ancho / 2 - ANCHO / 2) + 1, (medidasConsola.alto / 2 - ALTO / 2)-1);
            printf("fecha inicio de alquiler: %d / %d / %d ", nuevoAlquiler.fechaInicio.dia,nuevoAlquiler.fechaInicio.mes,nuevoAlquiler.fechaInicio.anio);
            gotoxy((medidasConsola.ancho / 2 - ANCHO / 2) + 1, (medidasConsola.alto / 2 - ALTO / 2) - 5);
            printf("Error: La fecha de inicio no puede ser mayor a la fecha de fin.");
            gotoxy((medidasConsola.ancho / 2 - ANCHO / 2) + 1, (medidasConsola.alto / 2 - ALTO / 2) - 4);
            printf("Presione cualquier tecla para volver al menu anterior");
            getch();
            MUTEXUNLOCK;
        }
        else
        {
            break;
        }
    } while (1);

    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
    MUTEXLOCK;
    nuevoAlquiler.dniCliente = cargarDNI("ingrese DNI del cliente");
    MUTEXUNLOCK;

    int diasDeAlquiler = calcularDias(nuevoAlquiler.fechaInicio,nuevoAlquiler.fechaFin);
    nuevoAlquiler.precioTotal = (float)diasDeAlquiler * precioPorDia;

    return nuevoAlquiler;
}

Alquiler ingresoAlquilerUsuario(Patente patente, float precioPorDia, int dni)
{
    Alquiler nuevoAlquiler;
    nuevoAlquiler.patenteVehi = patente;
    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+1);
    MUTEXLOCK;
    printf("%s %s", nuevoAlquiler.patenteVehi.letras,nuevoAlquiler.patenteVehi.numeros);
    MUTEXUNLOCK;

    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
    MUTEXLOCK;
    nuevoAlquiler.fechaInicio = cargarFecha("Ingrese la fecha de inicio");
    MUTEXUNLOCK;
    do
    {
        cuadroMenuInstantaneo(medidasConsola.ancho, medidasConsola.alto - 15);
        MUTEXLOCK;
        nuevoAlquiler.fechaFin = cargarFecha("Ingrese la fecha de fin");
        MUTEXUNLOCK;
        gotoxy((medidasConsola.ancho / 2 - ANCHO / 2) + 1, (medidasConsola.alto / 2 - ALTO / 2)-1);
        printf("fecha inicio de alquiler: %d / %d / %d ", nuevoAlquiler.fechaInicio.dia,nuevoAlquiler.fechaInicio.mes,nuevoAlquiler.fechaInicio.anio);

        if (!esFechaValida(nuevoAlquiler.fechaInicio, nuevoAlquiler.fechaFin))
        {
            cuadroMenuInstantaneo(medidasConsola.ancho, medidasConsola.alto - 15);
            MUTEXLOCK;
            gotoxy((medidasConsola.ancho / 2 - ANCHO / 2) + 1, (medidasConsola.alto / 2 - ALTO / 2)-1);
            printf("fecha inicio de alquiler: %d / %d / %d ", nuevoAlquiler.fechaInicio.dia,nuevoAlquiler.fechaInicio.mes,nuevoAlquiler.fechaInicio.anio);
            gotoxy((medidasConsola.ancho / 2 - ANCHO / 2) + 1, (medidasConsola.alto / 2 - ALTO / 2) - 5);
            printf("Error: La fecha de inicio no puede ser mayor a la fecha de fin.");
            gotoxy((medidasConsola.ancho / 2 - ANCHO / 2) + 1, (medidasConsola.alto / 2 - ALTO / 2) - 4);
            printf("Presione cualquier tecla para volver al menu anterior");
            getch();
            MUTEXUNLOCK;
        }
        else
        {
            break;
        }
    } while (1);

    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
    MUTEXLOCK;
    nuevoAlquiler.dniCliente = dni;
    MUTEXUNLOCK;

    int diasDeAlquiler = calcularDias(nuevoAlquiler.fechaInicio,nuevoAlquiler.fechaFin);
    nuevoAlquiler.precioTotal = (float)diasDeAlquiler * precioPorDia;

    return nuevoAlquiler;
}

/// FUNCIONES DE REPORTES Y ESTADISTICAS

// Implementación de la función para sumar importes por mes y año
float sumarImportesAlquileresPorMesYAnio(int mes, int anio)
{
    float sumaTotal = 0.0;

    for (int i = 0; i < cantAlquileres; i++) {
        // Verificar si el alquiler cae dentro del mes y año especificados
        if (arrDinAlquileres[i].fechaInicio.anio <= anio && arrDinAlquileres[i].fechaFin.anio >= anio) {
            int diasDentroDelMes = calcularDiasDentroDelMes(arrDinAlquileres[i].fechaInicio, arrDinAlquileres[i].fechaFin, mes, anio);
            if (diasDentroDelMes > 0) {
                float precioDiario = obtenerPrecioDiario(arrDinAlquileres[i].patenteVehi);
                sumaTotal += diasDentroDelMes * precioDiario;
            }
        }
    }

    return sumaTotal;
}

// Implementación de la función que pide datos al usuario y llama a la función de suma
void pedirDatosYSumarImportes()
{
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
    getch();
}

// Función para obtener la cantidad de días en un mes y año específicos
int obtenerDiasDelMes(int mes, int anio)
{
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
int calcularDiasDentroDelMes(Fecha inicio, Fecha fin, int mes, int anio)
{
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
float obtenerPrecioDiario(Patente patente)
{
    for (int i = 0; i < cantVehiculos; i++) {
        if (strncmp(arrDinVehiculos[i].patente.letras, patente.letras, 3) == 0 &&
            strncmp(arrDinVehiculos[i].patente.numeros, patente.numeros, 3) == 0) {
            return arrDinVehiculos[i].precioDeAlquilerDiario;
        }
    }
    return 0.0; // Si no se encuentra la patente, retornar 0
}

void mostrarVehiculos5aniosOrdenado()
{
    Vehiculo *arrDinVehiAux = (Vehiculo*)malloc(5 * sizeof(Vehiculo));
    int cantVehi5anios = 0;
    int anioActual;
    char opcion;
    int i=0;
    int pos = 0;



    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
    MUTEXLOCK;
    gotoxy((medidasConsola.ancho/2)-(ANCHO/2)+1,(medidasConsola.alto/2)-(ALTO/2)-7);
    printf("Ingrese el a%co actual: ",164);
    gotoxy((medidasConsola.ancho/2)-(ANCHO/2)+1,(medidasConsola.alto/2)-(ALTO/2)-5);
    fflush(stdin);
    scanf("%d", &anioActual);
    MUTEXUNLOCK;

    while(pos < cantVehiculos)
    {
        if(arrDinVehiculos[pos].anio >= (anioActual - 5))
           {
               arrDinVehiAux[cantVehi5anios]=arrDinVehiculos[pos];

               cantVehi5anios++;
           }
           pos++;
    }
    ordenamientoPorSeleccionArray(arrDinVehiAux,cantVehi5anios, anioActual);

    mostrarVehiculo(arrDinVehiAux[i]);
    MUTEXLOCK;
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
    printf("Vehiculo %d de %d", i+1, cantVehi5anios);
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
                        i=cantVehi5anios-1;
                    }
                    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                    mostrarVehiculo(arrDinVehiAux[i]);
                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
                    printf("Vehiculo %d de %d", i+1, cantVehi5anios);
                    MUTEXUNLOCK;
                    last_key=75;
                    break;
                case (77):      //moverse derecha
                    i++;
                    if(i>cantVehi5anios-1)
                    {
                        i=0;
                    }
                    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                    mostrarVehiculo(arrDinVehiAux[i]);
                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
                    printf("Vehiculo %d de %d", i+1, cantVehi5anios);
                    MUTEXUNLOCK;
                    last_key=77;
                    break;
                }
            }
            else if (opcion == ESC) //sale del if si se presiona ESC
            {
                free(arrDinVehiAux);
                cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                MUTEXLOCK;
                gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
                printf("liberando memoria principal");
                tipeo("...",200);
                MUTEXUNLOCK;
                break;
            }
        }
    }while(opcion != ESC); // ESC
}

void ordenamientoPorSeleccionArray(Vehiculo *arrDinVehiculoAux,int cantElementos, int anioActual)
{
    int i, j, min_idx;

    // Algoritmo de ordenamiento por selección
    for (i = 0; i < cantElementos - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < cantElementos; j++) {
            // Calcular la diferencia de años entre el año actual y el siguiente vehículo
            int diff_i = abs(arrDinVehiculoAux[i + 1].anio - anioActual);
            int diff_j = abs(arrDinVehiculoAux[j].anio - anioActual);

            // Encontrar el índice del elemento con la menor diferencia de años
            if (diff_j < diff_i) {
                min_idx = j;
            }
        }

        // Intercambiar los elementos si el mínimo encontrado no es el actual
        if (min_idx != i) {
            // Swap
            Vehiculo temp = arrDinVehiculoAux[min_idx];
            arrDinVehiculoAux[min_idx] = arrDinVehiculoAux[i];
            arrDinVehiculoAux[i] = temp;
        }
    }
}

//Funcion para mostrar el alquiler con mayor ingreso
void buscarAlquilerMayor()
{
    Alquiler alqMayor = arrDinAlquileres[0]; // Tomamos el primer alquiler como el mayor inicialmente

    for (int i = 1; i < cantAlquileres; i++) {
        if (arrDinAlquileres[i].precioTotal > alqMayor.precioTotal) {
            alqMayor = arrDinAlquileres[i];
        }
    }

    mostrarAlquiler(alqMayor);
    getch();
}

//funcion para verificar el solapamiento entre fechas de un alquiler que se debe ingresar y uno que ya existe. Como los alquileres no pueden eliminarse, siempre se encontraran todos en el arrDinamico.
int alquilerSeSolapa(Alquiler *arrDinAlquileres, int cantAlquileres, Patente patente, Fecha inicio, Fecha fin)
{
    for (int i = 0; i < cantAlquileres; i++) {
        // Verificar si el alquiler es del mismo vehículo
        if (strcmp(arrDinAlquileres[i].patenteVehi.letras, patente.letras) == 0 &&
            strcmp(arrDinAlquileres[i].patenteVehi.numeros, patente.numeros) == 0) {

            // Verificar solapamiento de fechas
            if ((inicio.anio < arrDinAlquileres[i].fechaFin.anio || (inicio.anio == arrDinAlquileres[i].fechaFin.anio && inicio.mes < arrDinAlquileres[i].fechaFin.mes) || (inicio.anio == arrDinAlquileres[i].fechaFin.anio && inicio.mes == arrDinAlquileres[i].fechaFin.mes && inicio.dia <= arrDinAlquileres[i].fechaFin.dia)) &&
                (fin.anio > arrDinAlquileres[i].fechaInicio.anio || (fin.anio == arrDinAlquileres[i].fechaInicio.anio && fin.mes > arrDinAlquileres[i].fechaInicio.mes) || (fin.anio == arrDinAlquileres[i].fechaInicio.anio && fin.mes == arrDinAlquileres[i].fechaInicio.mes && fin.dia >= arrDinAlquileres[i].fechaInicio.dia))) {
                return 1; // Se solapa con otro alquiler existente
            }
        }
    }

    return 0; // No se solapa con ningún alquiler existente
}

///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
///FUNCIONES PARA GESTION DINAMICA DE ALQUILERES-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///

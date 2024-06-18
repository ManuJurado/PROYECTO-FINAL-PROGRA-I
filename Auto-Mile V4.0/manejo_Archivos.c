#include "menu.h"
#include "data_Management.h"
#include "manejo_Archivos.h"

/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///

Persona administrador()
{
    Persona admin;
    admin.dni=1234;
    admin.activo=1;
    strcpy(admin.contra,"admin");
    strcpy(admin.nombre,"admin");
    strcpy(admin.telefono,"");
    strcpy(admin.direccion,"");
    strcpy(admin.rol,"User del Sistema");
    return admin;
}

int buscarPersonaArch(int dni)//busca la persona dentro de larchivo, si existe devuelve la posicion inicial del registro dentro del archivo. Si no, devuelve -1
{
    Persona aux;
    int pos=0;
    FILE *archi = fopen(ARCHIPERSONAS,"rb");
    if(archi == NULL)
    {
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+5));
        printf("el archivo no pudo ser abierto");
    }
    while(fread(&aux,sizeof(Persona),1,archi))
    {
        if(aux.dni == dni)
        {
            fseek(archi,-sizeof(Vehiculo), SEEK_CUR);
            fclose(archi);
            return pos;
        }
        pos++;
    }
    fclose(archi);
    return -1;
}

void guardarNuevoUsuarioArch(Persona per)
{
    cantidadPersonas++;

    if(cantidadPersonas % 5 == 0)
    {
        listaPersonas = (Persona*)realloc(listaPersonas,(cantidadPersonas+5)*sizeof(Persona));
    }

    per.activo = 1;
    strcpy(per.rol, "Cliente");

    copiaPersonaModificado(per,cantidadPersonas);

    if(buscarPersonaArch(per.dni)==-1)
    {
        FILE *arch = fopen(ARCHIPERSONAS, "ab");

        fwrite(&per,sizeof(Persona),1,arch);

        fclose(arch);
    }
    else
    {
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+5),((medidasConsola.alto/2)-(ALTO/2)+1));
        printf("el usuario ya existe en la base de datos...");
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+5),((medidasConsola.alto/2)-(ALTO/2)+3));
        printf("contactarse con administradores para verificar estado activo");
        tipeo("...",300);
    }
}

void modificaUsuArch(int dni, Persona aux)
{
    int pos = buscarPersonaArch(dni);

    FILE *archiv = fopen(ARCHIPERSONAS, "r+b");

    fseek(archiv,pos*sizeof(Persona),SEEK_SET);

    fwrite(&aux,sizeof(Persona),1,archiv);

    fclose(archiv);

    gotoxy(((medidasConsola.ancho/2) - (ANCHO/2))+1,((medidasConsola.alto/2) - (ALTO/2))+13);
    printf("ARCHIVO ABIERTO Y LISTA DE REGISTROS GUARDADA");
    tipeo("...",800);
}

void leerArchPersonas()
{
    FILE *arch = fopen(ARCHIPERSONAS,"rb");
    Persona aux;
    cantidadPersonas = 0;
    listaPersonas = (Persona*)malloc(5 * sizeof(Persona));
    int contador=0;

    if (arch == NULL)
    {
        // El archivo no existe, se abrirá en modo de escritura para crearlo
        arch = fopen(ARCHIPERSONAS, "wb");
        // Escribir los datos del administrador
        aux = administrador();
        fwrite(&aux, sizeof(Persona), 1, arch);
        fclose(arch);
        return;
    }
    else
    {

        while(fread(&aux,sizeof(Persona),1,arch))
        {
            if(aux.activo==1)
            {
                cantidadPersonas++;
            }
            if(cantidadPersonas % 5 == 0)
            {
                listaPersonas = (Persona*)realloc(listaPersonas,(cantidadPersonas + 5) * sizeof(Persona));
            }
        }
        fseek(arch,0,SEEK_SET);

        while(fread(&aux,sizeof(Persona), 1, arch) && contador<(cantidadPersonas+1))
        {
            if(aux.activo==1)
            {
                (listaPersonas)[contador]=aux;
                contador++;
            }
        }
        fclose(arch);
    }
}

/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION PERSONAS---------------------------------------------------------------------------------///


/// FUNCIONES DE ARCHIVOS PARA GESTION VEHICULOS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION VEHICULOS---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION VEHICULOS---------------------------------------------------------------------------------///

//funcion necesaria para leer el archivo y cargar el arreglo dinamico.
void leerArchiVehiculos()
{
    FILE *archiV = fopen(ARCHI_VEHICULOS, "rb");
    int cont = 0;
    char opcion;
    Vehiculo aux;
    cantVehiculos=0;
    arrDinVehiculos = (Vehiculo*)malloc(5 * sizeof(Vehiculo));

    if (archiV!= NULL)
    {
        while(fread((&aux), sizeof(Vehiculo), 1, archiV))
        {
            if(aux.activo == 1)
            {
                cantVehiculos++;
            }
            if(cantVehiculos % 5 == 0)
            {
                arrDinVehiculos = (Vehiculo*)realloc(arrDinVehiculos,(cantVehiculos + 5) * sizeof(Vehiculo)); // se agregan 5 posiciones de registro cuando se llega a 5 registros para no tener que hacer realloc cada vez que creamos 1 Registro
            }
        }

        fseek(archiV, 0, SEEK_SET);

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
    else
    {
        MUTEXLOCK;
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,medidasConsola.alto/2);
        printf("El archivo no pudo ser abierto, desea crearlo y agregar datos?");
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2)+1);
        printf("[s] para confirmar o cualquier tecla para cancelar.");
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2)+2);
        fflush(stdin);
        opcion = getch();
        MUTEXUNLOCK;
        if(opcion == 's')
        {
            cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
            agregarVehiculo();
        }
    }
}

//Funcion para agregar la estructura de vehiculo cargada al archivo y al arreglo dinamico
void agregarVehiculo()
{
    FILE *archiV;
    archiV = fopen(ARCHI_VEHICULOS, "ab");

    char op;
    Vehiculo nuevoVehiculo;

    //Redimensionar el arreglo dinámico para agregar el nuevo vehiculo

    if (arrDinVehiculos == NULL)
    {
        MUTEXLOCK;
        gotoxy(medidasConsola.ancho/2,medidasConsola.alto/2);
        printf("Error al redimensionar el arreglo...");
        Sleep(1000);
        fclose(archiV);
        MUTEXUNLOCK;
        return;
    }

    if (archiV==NULL)
    {
        MUTEXLOCK;
        gotoxy(medidasConsola.ancho/2,medidasConsola.alto/2);
        printf("el archivo no pudo ser abierto");
        Sleep(1000);
        MUTEXUNLOCK;
    }
    if(archiV != NULL)
    {
        do
        {
            MUTEXLOCK;
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+1);
            nuevoVehiculo = ingresoVehiculo();
            MUTEXUNLOCK;

            cantVehiculos++;

            //Agregar el nuevo vehiculo al final del arreglo dinamico
            if(cantVehiculos % 5 == 0)
            {
                arrDinVehiculos = (Vehiculo *)realloc(arrDinVehiculos, (cantVehiculos + 5) * sizeof(Vehiculo));
            }
            (arrDinVehiculos)[cantVehiculos-1] = nuevoVehiculo;


            //Mover el puntero del archivo al final y escribir el nuevo vehiculo
            fseek(archiV, 0, SEEK_END);
            fwrite(&nuevoVehiculo, sizeof(Vehiculo), 1, archiV);
            MUTEXLOCK;
            gotoxy(medidasConsola.ancho/2-4,medidasConsola.alto/2+4);
            printf("Ingrese ESC si no desea cargar otro vehiculo.");
            gotoxy(medidasConsola.ancho/2-4,medidasConsola.alto/2+5);
            FF;
            op = getch();
            MUTEXUNLOCK;
            cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
        }
        while(op != ESC);

        fclose(archiV);
    }
}

//funcion que recibe una patente y busca la posicion en la que se encuentra esa patente dentro del archivo. En base a eso se copia una posicion del arreglo dinamico en esa posicion del archivo.
void modificaVehiArch(Patente pat, int posArray)
{
    int pos = buscarPatenteArch(pat);

    FILE *archiv = fopen(ARCHI_VEHICULOS, "r+b");

    fseek(archiv,pos*sizeof(Vehiculo),SEEK_SET);

    fwrite(&arrDinVehiculos[posArray],sizeof(Vehiculo),1,archiv);

    fclose(archiv);

    gotoxy(((medidasConsola.ancho/2) - (ANCHO/2))+1,((medidasConsola.alto/2) - (ALTO/2))+13);
    printf("ARCHIVO ABIERTO Y LISTA DE REGISTROS GUARDADA");
    tipeo("...",800);

}

//funcion para buscar una patente dentro de un archivo de registros vehiculos. Retorna la posicion dentro del archivo donde esta la patente encontrada o 0 si no lo encuentra.
int buscarPatenteArch(Patente pat)
{
    Vehiculo aux;
    int pos=0;
    FILE *archi = fopen(ARCHI_VEHICULOS,"rb");
    if(archi == NULL)
    {
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+5));
        printf("el archivo no pudo ser abierto");
    }
    while(fread(&aux,sizeof(Vehiculo),1,archi))
    {
        if(strcmpi(aux.patente.letras, pat.letras) == 0 && strcmpi(aux.patente.numeros, pat.numeros) == 0)
        {
            fseek(archi,-sizeof(Vehiculo), SEEK_CUR);
            fclose(archi);
            return pos;
        }
        pos++;
    }
    fclose(archi);
    return -1;
}

//funcion que recibe una patente y busca la posicion en la que se encuentra esa patente dentro del archivo. Posteriormente da la posibilidad de "eliminar" el vehiculo
//en caso de estar activo, y de "restaurar" si el vehiculo ya se habia eliminado.
void cambiarEstadoActivoVehi(Patente pat)
{
    Vehiculo vehi;
    char confirma;
    int pos = buscarPatenteArch(pat);

    if(pos >= 0)
    {
        FILE *archiv = fopen(ARCHI_VEHICULOS, "r+b");

        fseek(archiv,pos*sizeof(Vehiculo),SEEK_SET);

        fread(&vehi,sizeof(Vehiculo),1,archiv);

        fseek(archiv,-sizeof(Vehiculo),SEEK_CUR); //vuelvo a pararme antes del vehiculo encontrado

        if(vehi.activo == 1)
        {
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)+1));
            printf("El vehiculo se encuentra activo en la base de datos.");
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)+2));
            printf("Presione 's' para eliminarlo.");
            limpiarBufferEntrada();
            confirma = getch();
            if(confirma == 's')
            {
                vehi.activo = 0;

                fwrite(&vehi,sizeof(Vehiculo),1,archiv);
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                MUTEXLOCK;
                gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)+1));
                printf("Vehiculo ELIMINADO con exito!");
                tipeo("...",300);
                Sleep(2000);
            }
            else
            {
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                MUTEXLOCK;
                gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)+5));
                printf("Datos no modificados. Volviendo al menu anterior");
                Sleep(1000);
                tipeo("...",300);
                return;
            }
        }
        else
        {
            MUTEXUNLOCK;
            cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
            MUTEXLOCK;
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)+1));
            printf("El vehiculo se encuentra inactivo en la base de datos. Presione 's' para restaurarlo.");
            confirma = getch();
            if(confirma == 's')
            {
                vehi.activo = 1;

                fwrite(&vehi,sizeof(Vehiculo),1,archiv);
                gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)+1));
                printf("Vehiculo RESTAURADO con exito!");
                tipeo("...",300);
                Sleep(2000);
            }
            else
            {
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                MUTEXLOCK;
                gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)+5));
                printf("Datos no modificados. Volviendo al menu anterior");
                Sleep(1000);
                tipeo("...",300);
            }
        }

        fclose(archiv);

        free(arrDinVehiculos); //liberar la memoria del arreglo dinamico
        cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
        MUTEXLOCK;
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
        tipeo("Actualizando datos en memoria principal",10);
        tipeo("...",300);
        MUTEXUNLOCK;

        leerArchiVehiculos();   //actualizar datos en el arreglo dinamico
    }
    else
    {
        MUTEXUNLOCK;
        cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
        MUTEXLOCK;
        gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+1),((medidasConsola.alto/2)-(ALTO/2)+5));
        printf("Vehiculo no encontrado. Volviendo al menu anterior");
        Sleep(1000);
        tipeo("...",300);
    }

    //gotoxy(((medidasConsola.ancho/2) - (ANCHO/2))+1,((medidasConsola.alto/2) - (ALTO/2))+13);
    //printf("ARCHIVO ABIERTO Y LISTA DE REGISTROS GUARDADA");
    //tipeo("...",800);
}

//Funcion que muestra todos los datos de un vehiculo a traves de su patente
void mostrarPorPatente(Patente pat)
{
    Vehiculo vehi;
    int pos = buscarPatenteArch(pat);

    if(pos >= 0)
    {
        FILE *archiv = fopen(ARCHI_VEHICULOS, "r+b");

        fseek(archiv,pos*sizeof(Vehiculo),SEEK_SET);

        fread(&vehi,sizeof(Vehiculo),1,archiv);

        cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
        mostrarVehiculo(vehi);
        if(vehi.activo == 1)
        {
            MUTEXLOCK;
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+15,(medidasConsola.alto/2-ALTO/2)+15);
            printf("Vehiculo Activo.");
            MUTEXUNLOCK;
        }
        else
        {
            MUTEXLOCK;
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+15,(medidasConsola.alto/2-ALTO/2)+15);
            printf("Vehiculo Eliminado.");
            MUTEXUNLOCK;
        }
        fclose(archiv);
    }
    else
    {
        MUTEXLOCK;
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+5);
        printf("Vehiculo no encontrado.");
        MUTEXUNLOCK;
    }
    getch();
}

/// FUNCIONES DE ARCHIVOS PARA GESTION ALQUILERES---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION ALQUILERES---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION ALQUILERES---------------------------------------------------------------------------------///

void leerArchAlquileres()
{
    FILE *arch = fopen(ARCHI_ALQUILERES,"rb");
    FILE *arch2;

    cantAlquileres=0;
    int cont=0;
    Alquiler auxAlq;
    Vehiculo auxVehi;
    int posicionVehi=-1;
    arrDinAlquileres = (Alquiler*)malloc(5 * sizeof(Alquiler));

    if(arch==NULL)
    {
        return;
    }
    else
    {
        while(fread((&auxAlq), sizeof(Alquiler), 1, arch))//proceso para recorrer el archivo de alquileres, comparar la patente para verificar si no esta eliminada en el arch de vehiculos, y en base a eso dimensionar el arreglo dinamico.
        {
            posicionVehi = buscarPatenteArch(auxAlq.patenteVehi);
            if(posicionVehi != -1)
            {
                arch2 = fopen(ARCHI_VEHICULOS,"rb");
                fseek(arch2,posicionVehi * sizeof(Vehiculo),SEEK_SET);
                fread((&auxVehi),sizeof(Vehiculo),1,arch2);
                if(auxVehi.activo==1)
                {
                    cantAlquileres++;
                }
                fclose(arch2);
                if(cantAlquileres % 5 == 0)
                {
                    arrDinAlquileres = (Alquiler*)realloc(arrDinAlquileres,(cantAlquileres+ 5) * sizeof(Alquiler)); // se agregan 5 posiciones de registro cuando se llega a 5 registros para no tener que hacer realloc cada vez que creamos 1 Registro
                }
            }
        }
    }

    fseek(arch,0,SEEK_SET);// despues de leer todo el archivo, y dimensionar el arreglo, vuelvo al inicio del archivo para leer nuevamente y cargar el arreglo dinamico.

    while(fread((&auxAlq), sizeof(Alquiler), 1, arch))
    {
        posicionVehi = buscarPatenteArch(auxAlq.patenteVehi);
        if(posicionVehi != -1)
        {
            arch2 = fopen(ARCHI_VEHICULOS,"rb");
            fseek(arch2,posicionVehi * sizeof(Vehiculo),SEEK_SET);
            fread((&auxVehi),sizeof(Vehiculo),1,arch2);
            if(auxVehi.activo==1)
            {
                (arrDinAlquileres[cont] = auxAlq);
                cont++;
            }
            fclose(arch2);
        }
    }
    fclose(arch);
}

//muestra los alquileres correspondientes a una persona en particular. Los almacena en un arreglo auxiliar y luego lo libera.
void mostrarAlquilerPorDni(int dni)
{
    int cantAlqAux = 0;
    for (int pos = 0; pos < cantAlquileres; pos++)
    {
        if (dni == arrDinAlquileres[pos].dniCliente)
        {
            cantAlqAux++;
        }
    }

    if (cantAlqAux == 0)
    {
        cuadroMenuInstantaneo(medidasConsola.ancho, medidasConsola.alto - 15);
        MUTEXLOCK;
        gotoxy((medidasConsola.ancho / 2 - ANCHO / 2) + 1, (medidasConsola.alto / 2 - ALTO / 2) - 5);
        printf("No se encontraron alquileres para este usuario");
        Sleep(1000);
        MUTEXUNLOCK;
        return;
    }

    Alquiler *arrDinAlquileresAux = malloc(cantAlqAux * sizeof(Alquiler));
    if (arrDinAlquileresAux == NULL)
    {
        perror("Error al asignar memoria para alquileres");
        return;
    }

    int j = 0;
    for (int pos = 0; pos < cantAlquileres; pos++)
    {
        if (dni == arrDinAlquileres[pos].dniCliente)
        {
            arrDinAlquileresAux[j++] = arrDinAlquileres[pos];
        }
    }

    int i = 0;
    cuadroMenuInstantaneo(medidasConsola.ancho, medidasConsola.alto - 15);
    mostrarAlquiler(arrDinAlquileresAux[i]);
    MUTEXLOCK;
    gotoxy((medidasConsola.ancho / 2 - ANCHO / 2) + 1, (medidasConsola.alto / 2 - ALTO / 2) - 5);
    printf("Alquiler %d de %d", i + 1, cantAlqAux);
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
                        i=cantAlqAux-1;
                    }
                    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                    mostrarAlquiler(arrDinAlquileresAux[i]);
                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
                    printf("Alquiler %d de %d", i+1, cantAlqAux);
                    MUTEXUNLOCK;
                    last_key=75;
                    break;
                case (77):      //moverse derecha
                    i++;
                    if(i>cantAlqAux-1)
                    {
                        i=0;
                    }
                    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                    mostrarAlquiler(arrDinAlquileresAux[i]);
                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
                    printf("Alquiler %d de %d", i+1, cantAlqAux);
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
    }
    while(opcion != ESC);  // ESC

    free(arrDinAlquileresAux);
    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
    MUTEXLOCK;
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
    printf("liberando memoria principal");
    tipeo("...",200);
    MUTEXUNLOCK;

}

//muestra los alquileres correspondientes a una patente en particular. Los almacena en un arreglo auxiliar y luego lo libera.
void mostrarAlquilerPorPatente(Patente patAux)
{
    Alquiler *arrDinAlquileresAux = (Alquiler*)malloc(5 * sizeof(Alquiler));
    int cantAlqAux = 0;
    char opcion;
    int i=0;
    int pos = 0;

    while(pos < cantAlquileres)
    {
        if((strcmpi(patAux.letras,arrDinAlquileres[pos].patenteVehi.letras)==0) && (strcmpi(patAux.numeros,arrDinAlquileres[pos].patenteVehi.numeros)==0))
        {
            arrDinAlquileresAux[cantAlqAux] = arrDinAlquileres[pos];
            cantAlqAux++;
        }
        pos++;
    }
    if(cantAlqAux==0)
    {
        cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
        MUTEXLOCK;
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
        printf("No se encontraron alquileres para esta patente");
        Sleep(1000);
        free(arrDinAlquileresAux);
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-3);
        printf("liberando memoria principal");
        tipeo("...",300);
        MUTEXUNLOCK;
        return;
    }

    mostrarAlquiler(arrDinAlquileresAux[i]);
    MUTEXLOCK;
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
    printf("Alquiler %d de %d", i+1, cantAlqAux);
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
                        i=cantAlqAux-1;
                    }
                    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                    mostrarAlquiler(arrDinAlquileresAux[i]);
                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
                    printf("Alquiler %d de %d", i+1, cantAlqAux);
                    MUTEXUNLOCK;
                    last_key=75;
                    Sleep(750);
                    break;
                case (77):      //moverse derecha
                    i++;
                    if(i>cantAlqAux-1)
                    {
                        i=0;
                    }
                    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
                    mostrarAlquiler(arrDinAlquileresAux[i]);
                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
                    printf("Alquiler %d de %d", i+1, cantAlqAux);
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
    }
    while(opcion != ESC);  // ESC
}

/// Funciones de guardado y modificacion de archivo de alquiler.
/// El guardado utiliza realloc para incrementar el tamanio de la memoria dinamica asignada, y tambien se incluye el nuevo registro dentro de este arreglo
/// Se utilizaran en el dataManagement.

/// Función para registrar un alquiler. Esta funcion recibira la posicion seleccionada del arreglo dinamico de vehiculos activos del cual se elige alquilar por parte del usuario. Si el vehiculo esta disponible podra alquilarse, de caso contrario volveremos.
void registrarAlquiler(int posArrDinVehi,int x, int y)
{
    cuadroMenuInstantaneo(x,y);

    if (posArrDinVehi < 0 || posArrDinVehi >= cantVehiculos)
    {
        MUTEXLOCK;
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+6,(medidasConsola.alto/2-ALTO/2)-6);
        printf("indice de veh%cculo no valido.",161);
        MUTEXUNLOCK;
        return;
    }

    //Abro el arch de alquileres en ab debido a que no existira un alquiler "repetido", con lo cual no habra comprobacion en los mismos registros. Siempre se agregara al final.
    FILE *archi = fopen(ARCHI_ALQUILERES,"ab");
    if (!archi)
    {
        perror("Error al abrir el archivo de alquileres");
        return;
    }
    FILE *archi2;

    Alquiler nuevoAlquiler;

    int posArchVehi;

    //vamos a la pos del arreglo de vehi para modificar la disponibilidad tanto en el arreglo dinamico y luego en el archivo.
    if(arrDinVehiculos[posArrDinVehi].disponibilidad == 0)
    {
        MUTEXLOCK;
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+6,(medidasConsola.alto/2-ALTO/2)-6);
        printf("El veh%cculo seleccionado no est%c disponible para alquilar.",161,160);
        MUTEXUNLOCK;
        Sleep(3000);
        return;
    }
    else// cambio la disponibilidad del vehiculo a alquilar.
    {

        posArchVehi = buscarPatenteArch(arrDinVehiculos[posArrDinVehi].patente);

        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+1);
        nuevoAlquiler = ingresoAlquiler(arrDinVehiculos[posArrDinVehi].patente,arrDinVehiculos[posArrDinVehi].precioDeAlquilerDiario);

        arrDinVehiculos[posArrDinVehi].disponibilidad = 0;

        archi2 = fopen(ARCHI_VEHICULOS,"r+b");

        fseek(archi2,posArchVehi * sizeof(Vehiculo),SEEK_SET);

        fwrite(&arrDinVehiculos[posArchVehi],sizeof(Vehiculo),1,archi2);

        cantAlquileres++;

        //Agregar el nuevo alquiler al final del arreglo dinamico
        if(cantAlquileres % 5 == 0)
        {
            arrDinAlquileres = (Alquiler*)realloc(arrDinAlquileres, (cantAlquileres+ 5) * sizeof(Alquiler));
            if (!arrDinAlquileres)
            {
                perror("Error al realocar memoria para alquileres");
                cantAlquileres--;
                fclose(archi);
                fclose(archi2);
                return;
            }
        }
        arrDinAlquileres[cantAlquileres-1] = nuevoAlquiler;
        cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
        mostrarAlquiler(nuevoAlquiler);
        getch();
    }
    fwrite(&nuevoAlquiler,sizeof(Alquiler),1,archi);
    fclose(archi);
    fclose(archi2);
}



void registrarAlquilerUsuario(int posArrDinVehi,int x, int y, int dni)
{
    cuadroMenuInstantaneo(x,y);
    if (posArrDinVehi < 0 || posArrDinVehi >= cantVehiculos)
    {
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+6,(medidasConsola.alto/2-ALTO/2)-6);
        printf("indice de veh%cculo no valido.",161);
        return;
    }

    //Abro el arch de alquileres en ab debido a que no existira un alquiler "repetido", con lo cual no habra comprobacion en los mismos registros. Siempre se agregara al final.
    FILE *archi = fopen(ARCHI_ALQUILERES,"ab");
    if (!archi)
    {
        perror("Error al abrir el archivo de alquileres");
        return;
    }
    FILE *archi2;

    Alquiler nuevoAlquiler;

    int posArchVehi;

    //vamos a la pos del arreglo de vehi para modificar la disponibilidad tanto en el arreglo dinamico y luego en el archivo.
    if(arrDinVehiculos[posArrDinVehi].disponibilidad == 0)
    {
        MUTEXLOCK;
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+6,(medidasConsola.alto/2-ALTO/2)-6);
        printf("El veh%cculo seleccionado no est%c disponible para alquilar.",161,160);
        MUTEXUNLOCK;
        Sleep(3000);
        return;
    }
    else// cambio la disponibilidad del vehiculo a alquilar.
    {

        posArchVehi = buscarPatenteArch(arrDinVehiculos[posArrDinVehi].patente);

        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+1);
        nuevoAlquiler = ingresoAlquilerUsuario(arrDinVehiculos[posArrDinVehi].patente,arrDinVehiculos[posArrDinVehi].precioDeAlquilerDiario,dni);

        arrDinVehiculos[posArrDinVehi].disponibilidad = 0;

        archi2 = fopen(ARCHI_VEHICULOS,"r+b");

        fseek(archi2,posArchVehi * sizeof(Vehiculo),SEEK_SET);

        fwrite(&arrDinVehiculos[posArchVehi],sizeof(Vehiculo),1,archi2);

        cantAlquileres++;

        //Agregar el nuevo alquiler al final del arreglo dinamico
        if(cantAlquileres % 5 == 0)
        {
            mostrarAlquiler(arrDinAlquileres[cantAlquileres-1]);
            Sleep(10000);
            arrDinAlquileres = (Alquiler*)realloc(arrDinAlquileres, (cantAlquileres+ 5) * sizeof(Alquiler));
            if (!arrDinAlquileres)
            {
                perror("Error al realocar memoria para alquileres");
                cantAlquileres--;
                fclose(archi);
                fclose(archi2);
                return;
            }

        }
        arrDinAlquileres[cantAlquileres-1] = nuevoAlquiler;
    }
    fwrite(&nuevoAlquiler,sizeof(Alquiler),1,archi);
    fclose(archi);
    fclose(archi2);
}

void guardarUnAlquiler(char nombreArch[], Alquiler **alquileres, int *cantidadRegistros, Alquiler nuevoAlquiler)
{
    FILE *arch = fopen(nombreArch, "r+b");

    // Redimensionar el arreglo dinámico para agregar el nuevo alquiler
    *alquileres = (Alquiler *)realloc(*alquileres, (*cantidadRegistros + 1) * sizeof(Alquiler));
    if (*alquileres == NULL)
    {
        printf("Error al redimensionar el arreglo...");
        fclose(arch);
        return;
    }

    // Agregar el nuevo alquiler al final del arreglo
    (*alquileres)[*cantidadRegistros] = nuevoAlquiler;
    (*cantidadRegistros)++;

    // Mover el puntero del archivo al final y escribir el nuevo alquiler
    fseek(arch, 0, SEEK_END);
    fwrite(&nuevoAlquiler, sizeof(Alquiler), 1, arch);

    fclose(arch);
}

/// FUNCIONES DE ARCHIVOS PARA GESTION ALQUILERES---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION ALQUILERES---------------------------------------------------------------------------------///
/// FUNCIONES DE ARCHIVOS PARA GESTION ALQUILERES---------------------------------------------------------------------------------///

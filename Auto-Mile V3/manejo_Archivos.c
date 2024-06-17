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
    admin.baja=1;
    strcpy(admin.contra,"admin");
    strcpy(admin.nombre,"admin");
    admin.telefono = 0;
    strcpy(admin.direccion,"");
    strcpy(admin.rol,"User del Sistema");
    return admin;
}

void guardarUsuario(Persona per)
{
    cantidadPersonas++;

    if(cantidadPersonas % 5 == 0)
    {
        listaPersonas = (Persona*)realloc(listaPersonas,(cantidadPersonas+5)*sizeof(Persona));
    }

    per.baja = 1;
    strcpy(per.rol, "Cliente");

    copiaPersonaModificado(per,cantidadPersonas);

    FILE *arch = fopen(ARCHIPERSONAS, "ab");

    fwrite(&per,sizeof(Persona),1,arch);

    fclose(arch);
}

void leerArchPersonas()
{
    FILE *arch = fopen(ARCHIPERSONAS,"rb");
    Persona aux;
    listaPersonas = (Persona*)malloc(5 * sizeof(Persona));
    int contador=0;

    if (arch == NULL)
    {
        // El archivo no existe, se abrirá en modo de escritura para crearlo
        arch = fopen(ARCHIPERSONAS, "wb");
        if (arch == NULL)
        {
            printf("Error al abrir el archivo %s.\n", ARCHIPERSONAS);
            return;
        }
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
            if(aux.baja==1)
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
            if(aux.baja==1)
            {
                (listaPersonas)[contador]=aux;
                contador++;
            }
        }
        fclose(arch);
    }
}

void eliminarPerson(Persona **listaPersonas, char nombrearch[],int posicionArray,int cantidadPersonas) ///<-------------------- ACOMODAR FUNCION SIN PUNTERO DOBLE
{
    int dni;
    printf("Ingrese el dni del usuario q desea eliminar del sistema: ");
    scanf("%d",&dni);
    int eliminacion=0;

    for(int i=0; i<cantidadPersonas; i++)
    {
        if((*listaPersonas)[i].dni==dni)
        {
            (*listaPersonas)[i].baja=0;///marca el usuario como dado de baja
            eliminacion=1;             ///se asegura q recorrio la funcion
        }
        if(eliminacion==0)
        {
            printf("usuario no encontrado");
        }
    }

    FILE *archi = fopen(nombrearch,"r+b");   ///Escribir en listaPersonas las personas validas (osea las q no estan marcadas con 0)
    if(archi!=NULL)
    {
        for(int i=0; i<cantidadPersonas; i++)
        {
            fwrite(&((*listaPersonas)[i]),sizeof(Persona),1,archi);
        }
    }
    fclose(archi);
    printf("Cambios realizados con exito");
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
        printf("el archivo no pudo ser abierto, desea crearlo y agregar datos? (s/n)");
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2)+1);
        scanf("%d", opcion);
        if(opcion == 's')
        {
            agregarVehiculo();
        }
        MUTEXUNLOCK;
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
        printf("Error al redimensionar el arreglo...");
        fclose(archiV);
        return;
    }

    if (archiV==NULL)
    {
        printf("el archivo no pudo ser abierto");
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
    printf("ARCHIVO ABIERTO Y LISTA DE REGISTROS GUARDADA");tipeo("...",800);

}

//funcion para buscar una patente dentro de un archivo de registros vehiculos. Retorna la posicion dentro del archivo donde esta la patente encontrada o 0 si no lo encuentra.
int buscarPatenteArch(Patente pat)
{
    Vehiculo aux;
    int pos=0;
    FILE *archi = fopen(ARCHI_VEHICULOS,"rb");
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
    return pos;
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
        printf("no se pudo abrir el archivo...");
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

/// Funciones de guardado y modificacion de archivo de alquiler.
/// El guardado utiliza realloc para incrementar el tamanio de la memoria dinamica asignada, y tambien se incluye el nuevo registro dentro de este arreglo
/// Se utilizaran en el dataManagement.

/// Función para registrar un alquiler. Esta funcion recibira la posicion seleccionada del arreglo dinamico de vehiculos activos del cual se elige alquilar por parte del usuario. Si el vehiculo esta disponible podra alquilarse, de caso contrario volveremos.
void registrarAlquiler(int posArrDinVehi,int x, int y)
{
    cuadroMenuInstantaneo(x,y);
    if (posArrDinVehi < 0 || posArrDinVehi >= cantVehiculos)
    {
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+6,(medidasConsola.alto/2-ALTO/2)-6);
        printf("Índice de vehículo no válido.");
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
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+6,(medidasConsola.alto/2-ALTO/2)-6);
        printf("El vehiculo seleccionado no esta disponible para alquilar.");
        Sleep(3000);
        return;
    }
    else// cambio la disponibilidad del vehiculo a alquilar.
    {

        posArchVehi = buscarPatenteArch(arrDinVehiculos[posArrDinVehi].patente);



        MUTEXLOCK;
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+1);
        nuevoAlquiler = ingresoAlquiler(arrDinVehiculos[posArrDinVehi].patente,arrDinVehiculos[posArrDinVehi].precioDeAlquilerDiario);
        MUTEXUNLOCK;

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

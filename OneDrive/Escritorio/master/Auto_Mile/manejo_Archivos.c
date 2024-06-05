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

    if(cantidadPersonas % 5 == 0){
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

    if (arch == NULL) {
        // El archivo no existe, se abrirá en modo de escritura para crearlo
        arch = fopen(ARCHIPERSONAS, "wb");
        if (arch == NULL) {
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

    int numAux=0;
    if (archiV!= NULL)
    {
        while(fread((&aux), sizeof(Vehiculo), 1, archiV))
        {
            if(aux.activo == 1)
            {
                cantVehiculos++;
                //mostrarVehiculo(aux);//LUEGO BORRAR ESTA LINEA, ESTA A MODO DE PRUEBA PARA VERIFICAR LOS DATOS AL EJECUTAR
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
    else{
        MUTEXLOCK;
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,medidasConsola.alto/2);
        printf("el archivo no pudo ser abierto, desea crearlo y agregar datos?");
        scanf("%d", opcion);
        if(opcion == 's'){
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
    Patente patente;

    //Redimensionar el arreglo dinámico para agregar el nuevo vehiculo

    if (arrDinVehiculos == NULL)
    {
        printf("Error al redimensionar el arreglo...");
        fclose(archiV);
        return;
    }

    if (archiV==NULL){
        printf("el archivo no pudo ser abierto");
    }
    if(archiV != NULL)
    {
        do
        {
            //Agregar el nuevo vehiculo al final del arreglo dinamico
            MUTEXLOCK;
            gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)+1);
            nuevoVehiculo = ingresoVehiculo();
            MUTEXUNLOCK;

            cantVehiculos++;

            if(cantVehiculos % 5 == 0){
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

    printf("\n\n\nARCHIVO ABIERTO Y LISTA DE REGISTROS\n\n\n");

    leerArchiVehiculos();

    leerRegistroVehiculos();

}

//funcion para buscar una patente dentro de un archivo de registros vehiculos
int buscarPatenteArch(Patente pat)
{
    Vehiculo aux;
    int pos=0;
    FILE *archi = fopen(ARCHI_VEHICULOS,"rb");
    while(fread(&aux,sizeof(Vehiculo),1,archi))
    {printf("leyendo pos %d del registro", pos);
        Sleep(1000);
        if(strcmpi(aux.patente.letras, pat.letras) == 0 && strcmpi(aux.patente.numeros, pat.numeros) == 0)
        {
            fseek(archi,-sizeof(Vehiculo), SEEK_CUR);
            fclose(archi);
            return pos;
        }
        pos++;
    }
    fclose(archi);
    return printf("no se encontro la posicion con esa patente");
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"


/*
typedef struct {
int dni;
char nombre[50];
char telefono[20];
char direccion[100];
char rol[20]; // Cliente o Usuario del Sistema
} Persona;

Gestión de Personas:
- Agregar / modificar una persona.
- Ver listado de personas (nombre, apellido y dni).
- Ver info de una persona (toda la info).

*/
typedef struct
{
    int dni;
    int baja;
    char nombre[50];
    char contra[30];
    char telefono[20];
    char direccion[100];
    char rol[20];
} Persona;

int funcionprincipal()
{

    char continuar='s';
    Persona *usuario=NULL;
    int cantidad_usurarios=0;

    do
    {
        guardarUsuario(&usuario,&cantidad_usurarios);
        printf("\nDesea registrar otro usuario s/n\n");
        fflush(stdin);
        scanf("%c",&continuar);
    }
    while(continuar=='s');

    buscarUsuario(usuario,cantidad_usurarios);

    int validacion=ingresaUsuario(usuario,cantidad_usurarios);

    if(validacion==2)
    {
        printf("Usuario correcto");
    }
    else if(validacion==1)
    {
        printf("si existe pero la contraseña es incorrecta");
    }
    else
    {
        printf(" No existe el usuario");
    }




    return 0;
}


void guardarUsuario(Persona **usuario, int *cantidad_usuarios)
{

    (*cantidad_usuarios)++;
    *usuario=(Persona*)realloc(*usuario,(*cantidad_usuarios)*sizeof(Persona));

    int dni;
    printf("Ingrese el DNI del usuario: ");
    scanf("%d",&dni);

    if(usuarioRepetido(*usuario,*cantidad_usuarios-1,dni))
    {
        printf("ERROR DNI ya existente");
        (*cantidad_usuarios)--;
        return;
    }

    (*usuario)[*cantidad_usuarios-1].dni=dni;

    printf("Ingrese el nombre: ");
    scanf("%s", (*usuario)[*cantidad_usuarios-1].nombre);
    printf("Ingrese el contraseña respetando mayusculas y minusculas: ");
    scanf("%s", (*usuario)[*cantidad_usuarios-1].contra);
    printf("Ingrese el telefono: ");
    scanf("%s", (*usuario)[*cantidad_usuarios-1].telefono);
    printf("Ingrese la direccion: ");
    scanf("%s", (*usuario)[*cantidad_usuarios-1].direccion);

    /*if(*cantidad_usuarios>1)
    {
        int dnirep=usuaritoRepetido(*usuario, *cantidad_usuarios-1,(*usuario)[*cantidad_usuarios-1].dni);
        if(dnirep!=-1)
        {
            char cambio;
            printf("Este dni lo posee otro usurio, desea remplazarlo? s/n\n");
            fflush(stdin);
            scanf("%c",&cambio);
            if(cambio=='s')
            {
                printf("Ingrese el nombre: ");
                scanf("%s", (*usuario)[dnirep].nombre);
                printf("Ingrese el telefono: ");
                scanf("%s", (*usuario)[dnirep].telefono);
                printf("Ingrese la direccion: ");
                scanf("%s", (*usuario)[dnirep].direccion);

                return;

                /*(*usuario)[dnirep].dni=(*usuario)[*cantidad_usuarios-1].dni;
                printf("Ingrese el nombre: ");
                scanf("%s", (*usuario)[dnirep].nombre);
                strcpy((*usuario)[dnirep].nombre,(*usuario)[*cantidad_usuarios-1].nombre);
                printf("Ingrese el telefono: ");
                scanf("%s", (*usuario)[dnirep].telefono);
                strcpy((*usuario)[dnirep].telefono,(*usuario)[*cantidad_usuarios-1].telefono);
                printf("Ingrese la direccion: ");
                scanf("%s", (*usuario)[dnirep].direccion);
                strcpy((*usuario)[dnirep].direccion,(*usuario)[*cantidad_usuarios-1].direccion);

                (*usuario)[dnirep]=(*usuario)[*cantidad_usuarios-1];
                (*cantidad_usuarios)--;

            }
        }
    }
    */

}

int usuarioRepetido(Persona *usuario,int cantidad_usuarios,int dni) /// la idea es q si encuentra coincidencias habilite el cambio o no (pasando -1)
{
    for (int i=0; i<cantidad_usuarios; i++)
        if(usuario[i].dni==dni)
        {
            return 1;
        }
    return 0;
}

void mostrarPersona(Persona usuario)
{
    printf("Nombre:%s\n",usuario.nombre);
    printf("DNI: %s\n",usuario.dni);
}

void buscarUsuario(Persona *usuario, int cantidad_usuarios)
{
    int buscar_dni;
    printf("Ingrese un dni del usuario: ");
    scanf("%d",&buscar_dni);

    if(cantidad_usuarios>=1)
    {
        for(int i=0; i<cantidad_usuarios; i++)
        {
            if(usuario[i].dni==buscar_dni)
            {
                mostrarPersona(usuario[i]);
                return;
            }
        }
    }
    else
    {
        printf("Usuarion no encontrado");
    }
}

int ingresaUsuario(Persona *usuario, int cantidad_usuarios)
{
    int comprobarDNI;
    char comprobarContra[30];

    printf("Ingrese su DNI:");
    scanf("%d",&comprobarDNI);
    printf("Ingrese contra: ");
    scanf("%s",comprobarContra[30]);
    int correcto=0,existe=0;

    for(int i=0; i<cantidad_usuarios; i++)
    {
        if(usuario[i].dni==comprobarDNI)
        {
            existe=1;
            if(strcmp(usuario[i].contra,comprobarContra)==0)
            {
                correcto=1;
            }
        }
    }

    if(existe)
    {
        if(correcto)
        {
            return 2; ///Usuario y contraseña correctos
        }
        else
        {
            return 1; ///Solo la contraseña incorrecta
        }
    }
    else
    {
        return 0;   ///Usuario no existe
    }
}

int leerArchVehiculos(char nombrearch[], Persona **listaPersonas)
{

    FILE *arch = fopen(nombrearch,"rb");
    int cantidadRegistros=0;
    Persona aux;
    int contador=0;

    if(arch==NULL)
    {
        printf("no se pudo abrir el archivo...");
        return;
    }
    while(fread(&aux,sizeof(Persona),1,arch))
    {
        if(aux.baja==1)
        {
            cantidadRegistros++;
        }
    }
    fseek(arch,0,SEEK_SET);

    *listaPersonas = (Persona*)malloc(cantidadRegistros * sizeof(Persona));

    while(fread(&aux,sizeof(Persona), 1, arch) && contador<cantidadRegistros+1)
    {
        if(aux.baja==1)
        {
            (*listaPersonas)[contador]=aux;
            contador++;
        }
    }
    fclose(arch);
    return cantidadRegistros;
}
void eliminarPerson(Persona **listaPersonas, char nombrearch[],int posicionArray)
{

}
///isdigit()










#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"

#define ARCHIPERSONAS "personas.bin"

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

Persona *listaPersonas;
int *cantidadPersonas;

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

    return 0;
}

void guardarUsuario(Persona **usuario, int *cantidad_usuarios)
{
    (*cantidad_usuarios)++;
    *usuario=(Persona*)realloc(*usuario,(*cantidad_usuarios)*sizeof(Persona));

    int dni;
    printf("Ingrese el DNI del usuario: ");
    scanf("%d",&dni);

    if(existeUsuario(*usuario,*cantidad_usuarios-1,dni))
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
    scanf((*usuario)[*cantidad_usuarios-1].baja==1);    /// siempre marcados como 1 , solo aparece como 0 si el usuario lo designa mas tarde
}

int existeUsuario(Persona *usuario,int cantidad_usuarios,int dni) /// la idea es q si encuentra coincidencias habilite el cambio o no (pasando -1)
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

int registrarUsuario(int dni[],char contrasenia[])
{
    int i=0;
    while(i<(*cantidadPersonas))
    {
        if(listaPersonas[i].dni==dni)
        {
            if(strcmp(listaPersonas[i].contra,contrasenia)==0)
            {
                return 2; ///Usuario y contraseña correctos
            }
            else
            {
                return 1; ///Solo la contraseña incorrecta
            }
        }
        i++;
    }

        return 0;   ///Usuario no existe
}

void leerArchPersonas()
{
    FILE *arch = fopen(ARCHIPERSONAS,"rb");
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
            (*cantidadPersonas)++;
        }
    }
    fseek(arch,0,SEEK_SET);

    listaPersonas = (Persona*)malloc(*cantidadPersonas * sizeof(Persona));

    while(fread(&aux,sizeof(Persona), 1, arch) && contador<*cantidadPersonas+1)
    {
        if(aux.baja==1)
        {
            (listaPersonas)[contador]=aux;
            contador++;
        }
    }
    fclose(arch);
}

void eliminarPerson(Persona **listaPersonas, char nombrearch[],int posicionArray,int cantidad_usuarios)
{
int dni;
printf("Ingrese el dni del usuario q desea eliminar del sistema: ");
scanf("%d",&dni);
int eliminacion=0;

for(int i=0;i<cantidad_usuarios;i++)
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

FILE *archi = fopen(nombrearch,"wb");   ///Escribir en listaPersonas las personas validas (osea las q no estan marcadas con 0)
if(archi!=NULL)
{
    for(int i=0;i<cantidad_usuarios;i++)
    {
        fwrite(&((*listaPersonas)[i]),sizeof(Persona),1,archi);
    }
}
fclose(archi);
printf("Cambios realizados con exito");
}

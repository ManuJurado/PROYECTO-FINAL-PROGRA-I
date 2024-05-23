#include <stdio.h>
#include <stdlib.h>
#include "dataManagement.h"

/// La funcion lee un archivo de alquileres y devuelve un entero, que representa la cantidad de alquileres leidos
/// El entero se utiliza para asignar en memoria dinamica la cantidad de registros a trabajar y poder almacenar los mismos ahi.
/// Al no tener variables de baja, alta, disponible o no disponible se tendran en cuenta todos los registros dentro del archivo.

int leerArchAlquileres(char nombrearch[], Alquiler **alquileres){
    FILE *arch = fopen(nombrearch,"rb");
    int cantidadRegistros=0;

    if(arch==NULL){
        printf("no se pudo abrir el archivo...");
        return;
    }
    fseek(arch,0,SEEK_END);
    cantidadRegistros = ftell(arch)/sizeof(Alquiler);
    fseek(arch,0,SEEK_SET);

    *alquileres = (Alquiler*)malloc(cantidadRegistros * sizeof(Alquiler));

    for(int i = 0; i<cantidadRegistros; i++){
        fread(alquileres[i],sizeof(Alquiler),1,arch);
    }
    fclose(arch);
    return cantidadRegistros;
}

/// Funciones de guardado y modificacion de archivo de alquiler.
/// El guardado utiliza realloc para incrementar el tamanio de la memoria dinamica asignada, y tambien se incluye el nuevo registro dentro de este arreglo
/// Se utilizaran en el dataManagement.

void guardarUnAlquiler(char nombreArch[], Alquiler **alquileres, int *cantidadRegistros, Alquiler nuevoAlquiler){
    FILE *arch = fopen(nombreArch, "r+b");

    // Redimensionar el arreglo dinámico para agregar el nuevo alquiler
    *alquileres = (Alquiler *)realloc(*alquileres, (*cantidadRegistros + 1) * sizeof(Alquiler));
    if (*alquileres == NULL) {
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





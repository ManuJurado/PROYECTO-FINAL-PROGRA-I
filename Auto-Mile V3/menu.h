#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#include <pthread.h>
#include <time.h>
#include <ctype.h>

#define ARCHIVO_MP3 "carengine.wav"
#define ARCHIVO_2_MP3 "route66.wav"

#include "data_Management.h"
#include "manejo_Archivos.h"
#include "gotoxy.h"

#define MAX 100
#define FF fflush(stdin)
#define ESC 27
#define CLEAN system("cls")
#define ANCHO 80
#define ALTO 25
#define IZQ 75
#define DER 77
#define MAX_CARACTERES 30

#define A 219
#define B 178
#define C 177
#define D 176

// Definiciones de constantes para caracteres especiales

#define MUTEXLOCK pthread_mutex_lock(&key_mutex)
#define MUTEXUNLOCK pthread_mutex_unlock(&key_mutex)




// Variables globales para almacenar la tecla y un flag de acci�n
extern volatile char global_key;
extern volatile char last_key;
pthread_mutex_t key_mutex; // Mutex para proteger la variable global

typedef struct
{
    int ancho;
    int alto;
} Medidas;

Medidas medidasConsola; // Declaraci�n de la variable global para la consola
Medidas medidasCuadro;  // Declaraci�n de la variable global para el recuadro



///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///

int mainMenu(int anchoConsola, int altoConsola);
int inicio(int x, int y);
void menuInicio(int x, int y);
void cursorClean(int ver);/// cambia la visualizacion del cursor. Se pasa como parametro 1 para mostrar o 0 para esconder.
void cuadroMenuInstantaneo(int x, int y);/// dibuja la interfaz del cuadro de forma instantanea(sin sleeps);
void cuadroMenu(int x, int y);/// dibuja la interfaz del cuadro de forma pausada(con sleeps);
void tituloMenu(int x, int y);/// dibuja el titulo en el centro de la consola
void selectCrearUsuario(int x,int y);/// pinta la opcion de crear usuario en el menu principal
void selectIniciarSesion(int x, int y);/// pinta la opcion de crear iniciar sesion en el menu principal
void detallesMenu(int x, int y);/// printea los cuadros de seleccion crear usuario e iniciar sesion cuando empieza el menu principal
void leerLimite(char *digitos, int max);
void leerLimiteNumeros(char *digitos, int max);
void cuadroEscritura(int x, int y, int l);/// dibuja un cuadro donde nos ubicaremos para escribir. Se le pasa por parametro una constante MAX_CARACTERES para delimitar el alcance del cuadro.
void textoCuadro(int x, int y, int l, char data[]);/// Se ubica en una posicion x,y , escribe lo que se pasa por parametro y dibuja un cuadro abajo para pedir los datos en esa posicion. Gotoxy queda situado en la posicion del cuadro.
void escribeCuadro(int x, int y, void (*funcion)(), char texto[], int cant);
void menuCrearUsuario(int x, int y, int *dni, char contra[]);
void guardarDatosUsuario(int x, int y, int dniusu, char contrasenia[]);
int ingresaUsuario(int x, int y, int *dni); /// ver


/// Funciones de Administrador ///

void menuOpcionesDeAdmin(int x,int y, Persona per);
void menuGestionVehiAdmin(int x, int y);
void modificarVehiculo(int x, int y);
void menuGestionPersAdmin(int x, int y, Persona per);
void menuGestionAlqAdmin(int x, int y);


/// Funciones de Cliente ///

//void mostrarPersona(int x, int y, Persona usuario);
void menuOpcionesDeUsuario(int x,int y, int dni);
void menuGestionUsuario(int x, int y, int dni);
void menuAlquilerUsuario(int x, int y);
void menuGestionAlqUsuario(int x, int y);


///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///


#endif // MENU_H_INCLUDED

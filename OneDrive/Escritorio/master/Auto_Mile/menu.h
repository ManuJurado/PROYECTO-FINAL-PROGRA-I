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

// Definiciones de constantes para caracteres especiales
#define H 1
#define V 2
#define Q 3
#define Z 4
#define C 5
#define E 6
#define I 7
#define L 8
#define K 9
#define N 10
#define B 11
#define U 12
#define J 13
#define A 14
#define F 15
#define D 0

#define A 219
#define B 178
#define C 177
#define D 176

#define MUTEXLOCK pthread_mutex_lock(&key_mutex)
#define MUTEXUNLOCK pthread_mutex_unlock(&key_mutex)

// Variables globales para almacenar la tecla y un flag de acci�n
extern volatile char global_key;
extern volatile char last_key;
pthread_mutex_t key_mutex; // Mutex para proteger la variable global

typedef struct {
    int ancho;
    int alto;
} Medidas;

struct PosicionActual
{
    int x;
    int y;
};

extern Medidas medidasConsola; // Declaraci�n de la variable global para la consola
extern Medidas medidasCuadro;  // Declaraci�n de la variable global para el recuadro

///FUNCIONES DE PRESENTACION E HILOS--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE PRESENTACION E HILOS--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE PRESENTACION E HILOS--------------------------------------------------------------------------------------------------------------------///

struct PosicionActual posicionActual;

///FUNCIONES DE PRESENTACION E HILOS--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE PRESENTACION E HILOS--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE PRESENTACION E HILOS--------------------------------------------------------------------------------------------------------------------///

void *key_listener(void *arg); // funcion hilo auxiliar que permanentemente analiza lo ingresado por teclado en caso de que existe kbhit
void *giro_coche(void *arg);// Hilo para procesar la tecla capturada
void izq1(int x, int y);
void izq2(int x, int y);
void izq3(int x, int y);
void izq4(int x, int y);
void izq5(int x, int y);
void der1(int x, int y);
void der2(int x, int y);
void der3(int x, int y);
void der4(int x, int y);
void der5(int x, int y);
void centro(int x, int y);
void *funcionHiloCoche(void *arg);

///FUNCIONES DE HILOS--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE HILOS--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE HILOS--------------------------------------------------------------------------------------------------------------------///


///FUNCIONES DE PRESENTACION --------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE PRESENTACION --------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE PRESENTACION --------------------------------------------------------------------------------------------------------------------///


void* funcionHilo(void* arg);/// Funci�n que se ejecutar� en el hilo
/// funciones para implementar el uso de gotoxy, que determinan el tamanio de la consola y en base a eso se determinara gotoxy
void presentacion(int x, int y);
void tipeo2(const char * p,int ms);
void tipeo(const char * p,int ms);
void getConsoleSize(int* ancho, int* altura);
void maximizeAndFixConsoleWindow();
void ocultarCursor();
void printearAuto(int x, int y);///printea un coche en simbolos
void borrarAuto(int x, int y);///borra el auto printeado
void autoCorriendo(struct PosicionActual *posicionActual,int altoConsola,int anchoConsola); ///
void printCharacter(int valor, int x, int y);
int presentacion2(int matriz[30][70], struct PosicionActual *posicionActualX, struct PosicionActual *posicionActualY);
int presentacion3(int matriz[30][70], struct PosicionActual *posicionActualX, struct PosicionActual *posicionActualY);
void borrarPresentacion(int matriz[30][70], int x, int y);
void intro();

///FUNCIONES DE PRESENTACION E HILOS--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE PRESENTACION E HILOS--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE PRESENTACION E HILOS--------------------------------------------------------------------------------------------------------------------///


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
void cuadroEscritura(int x,int y);/// dibuja un cuadro donde nos ubicaremos para escribir. Se le pasa por parametro una constante MAX_CARACTERES para delimitar el alcance del cuadro.
void textoCuadro(int x, int y, char data[]);/// Se ubica en una posicion x,y , escribe lo que se pasa por parametro y dibuja un cuadro abajo para pedir los datos en esa posicion. Gotoxy queda situado en la posicion del cuadro.
void escribeCuadro(int x, int y, void (*funcion)(), char texto[], int cant);
void menuCrearUsuario(int x, int y, int *dni, char contra[]);
void guardarDatosUsuario(int x, int y, char dniusu[], char contrasenia[]);
int ingresaUsuario(int x, int y);

///menu para modificar un vehiculo por dato
void modificarVehiculo();
///----------------------------------///

void menuOpcionesDeAdmin(int x,int y, int dni);
void menuOpcionesDeUsuario(int x,int y, int dni);
void menuGestionVehiAdmin(int x, int y);
void menuGestionPersAdmin(int x, int y);
void menuGestionAlqAdmin(int x, int y);
void menuGestionCliente(int x, int y);




///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///





#endif // MENU_H_INCLUDED

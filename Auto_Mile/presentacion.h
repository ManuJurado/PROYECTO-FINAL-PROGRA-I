#ifndef PRESENTACION_H_INCLUDED
#define PRESENTACION_H_INCLUDED

#include "menu.h"

///FUNCIONES DE PRESENTACION E HILOS--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE PRESENTACION E HILOS--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE PRESENTACION E HILOS--------------------------------------------------------------------------------------------------------------------///


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


void* funcionHilo(void* arg);/// Función que se ejecutará en el hilo
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


#endif // PRESENTACION_H_INCLUDED

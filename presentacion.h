#ifndef PRESENTACION_H_INCLUDED
#define PRESENTACION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "gotoxy.h"


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
#define D 16



void ocultarCursor();

void mostrarAutito(int matriz[6][37],int x,int y);

void printearAuto(int x, int y);

void borrarAuto(int x, int y);

void autoCorriendo(int x, int y,int aceleracion, int anchoConsola, int altoConsola);

int presentacion2(int matriz[30][70], int startX, int startY, int *posFinalX,int *posFinalY);

int presentacion3(int matriz[30][70], int x, int y);

void borrarPresentacion(int matriz[30][70], int x, int y);

void tipeo2(const char * p,int ms);

void tipeo(const char * p,int ms);

void presentacion();

void intro();



#endif // PRESENTACION_H_INCLUDED

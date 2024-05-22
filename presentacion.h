#ifndef PRESENTACION_H_INCLUDED
#define PRESENTACION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "gotoxy.h"


#define H 8 ///PARED HORIZONTAL
#define V 2 ///PARED VERTICAL
#define E 9 ///ESQUINA SUPERIOR DERECHA
#define Q 7 ///ESQUINA SUPERIOR IZQUIERDA
#define C 3 ///ESQUINA INFERIOR DERECHA
#define Z 1 ///ESQUINA INFERIOR IZQUIERDA
#define K 11
#define N 12
#define B 13
#define U 14
#define J 15
#define W 0
#define M 0
#define I 5
#define L 0
#define A 0
#define O 0
#define G 0
#define F 0
#define S 0
#define D 0

void ocultarCursor();

void mostrarAutito(int matriz[6][37],int x,int y);

void printearAuto(int x, int y);

void borrarAuto(int x, int y);

void autoCorriendo(int x, int y,int aceleracion);

int presentacion2(int matriz[30][70], int x, int y);

int presentacion3(int matriz[30][70], int x, int y);

int borrarPresentacion(int matriz[30][70], int x, int y);

void tipeo2(const char * p,int ms);

void tipeo(const char * p,int ms);

void presentacion();

void intro();

#endif // PRESENTACION_H_INCLUDED

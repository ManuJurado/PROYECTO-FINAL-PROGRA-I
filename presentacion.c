
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "gotoxy.h"
#include "pthread.h"
#include "semaphore.h"



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

#include "presentacion.h"

/// funciones para implementar el uso de gotoxy, que determinan el tamanio de la consola y en base a eso se determinara gotoxy

void presentacion(int x, int y){
    gotoxy((x/2)-30,y/2);
    tipeo2("BIENVENIDO/A A AUTOMILE, SU COCHERA DE CONFIANZA\n\n",10);
    gotoxy((x/2)-30,(y/2)+5);
    Sleep(500);
    system("pause");
}

void tipeo2(const char * p,int ms){
    if (NULL == p)
        return;

    while(*p)
    {
        printf("%c\xDB", *p++);
        Sleep(ms);
        printf("\b \b");
        Sleep(ms);
    }
}

void tipeo(const char * p,int ms){
    if (NULL == p)
        return;

    while(*p)
    {
        if(kbhit())
        {
            ms=0;
        }
        printf("%c\xDB", *p++);
        Sleep(ms);
        printf("\b \b");
        Sleep(ms);
    }
}

void getConsoleSize(int* ancho, int* altura){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columnas, filas;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columnas = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    filas = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    *ancho = columnas;
    *altura = filas;
}

void maximizeConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE);
}

int matriz [30][70] ={
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,Q,H,H,H,H,E,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,V,0,0,0,0,V,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,V,0,0,0,0,V,0,0,0,0,0,0,V,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,V,0,0,0,0,V,0,0,0,0,Q,H,U,H,E,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,N,H,H,H,H,B,0,V,0,0,V,0,V,0,N,H,H,E,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,V,0,0,0,0,V,0,V,0,0,V,0,V,0,V,0,0,V,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,V,0,0,0,0,V,0,V,0,0,V,0,V,0,V,0,0,V,0,H,H,H,H,H,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,V,0,0,0,0,V,0,V,0,0,V,0,V,0,V,0,0,V,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,V,0,0,0,0,V,0,Z,H,H,C,0,V,0,Z,H,H,C,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,V,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,V,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,V,0,0,0,0,0,0,0,0,0,0,0,V,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,N,H,H,K,H,H,E,0,H,K,H,0,V,0,Q,H,H,H,E,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,V,0,0,V,0,0,V,0,0,V,0,0,V,0,V,0,0,0,V,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,V,0,0,V,0,0,V,0,0,V,0,0,V,0,V,0,0,0,V,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,V,0,0,V,0,0,V,0,0,V,0,0,V,0,N,H,H,H,C,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,V,0,0,V,0,0,V,0,0,V,0,0,V,0,V,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,V,0,0,V,0,0,V,0,0,V,0,0,V,0,V,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,V,0,0,V,0,0,V,0,H,J,H,0,Z,0,Z,H,H,H,H,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

void ocultarCursor(){
    // Secuencia de escape ANSI para ocultar el cursor
    printf("\e[?25l");
    fflush(stdout); // Asegura que la salida se limpie de inmediato
}

void printearAuto(int x, int y){
    gotoxy(x,y);
    puts("              ____----------- _____");
    gotoxy(x,y+1);
    puts(" \\~~~~~~~~~~/~_--~~~------~~~~~~~   \\");
    gotoxy(x,y+2);
    puts("  `---`\\  _-~      |                   \\");
    gotoxy(x,y+3);
    puts("    _-~  <_         |                     \\  ");
    gotoxy(x,y+4);
    puts("  / ___     ~~--[\"\"] |      ________-------'_");
    gotoxy(x,y+5);
    puts(" > /~` \\    |-.   `\\~~.~~~~~                _ ~ - _");
    gotoxy(x,y+6);
    puts("  ~|  ||\\%  |       |    ~  ._                ~ _   ~ ._");
    gotoxy(x,y+7);
    puts("    `_//|_%  \\      |          ~  .              ~-_   /\\");
    gotoxy(x,y+8);
    puts("           `--__     |    _-____  /\\               ~-_ \\/.");
    gotoxy(x,y+9);
    puts("                ~--_ /  ,/ -~-_ \\ \\/          _______---~/");
    gotoxy(x,y+10);
    puts("                    ~~-/._<   \\ \\`~~~~~~~~~~~~~     ##--~/");
    gotoxy(x,y+11);
    puts("                          \\    ) |`------##---~~~~-~  ) )");
    gotoxy(x,y+12);
    puts("                           ~-_/_/                  ~~ ~~");
}

void borrarAuto(int x, int y){
    int i;
    for (i = 0; i < 13; i++) {
        printf("                                                                            ");
        gotoxy(x, y + i);
    }
}

void autoCorriendo(int x, int y,int aceleracion, int anchoConsola, int altoConsola){
    int velocidad = 2000;
    printf("\033[0;31m");
    x=60;
    y=0;
    gotoxy(x,y);
    while(altoConsola>y+13 && x + 60 < anchoConsola)
    {
        printearAuto(x, y);
        Sleep(velocidad/aceleracion);
        borrarAuto(x-3, y-1);
        printearAuto(x, y);
        aceleracion+=2;
        x+=2;
        y+=1;
    }
    Sleep(300);
}

void printCharacter(int valor, int x, int y) {
    gotoxy(x, y);
    printf("\033[0;36m");
    switch (valor) {
        case H: printf("%c", 205); break;
        case V: printf("%c", 186); break;
        case Q: printf("%c", 201); break;
        case Z: printf("%c", 200); break;
        case C: printf("%c", 188); break;
        case E: printf("%c", 187); break;
        case I: printf("%c", 190); break;
        case L: printf("%c", 64); break;
        case K: printf("%c", 203); break;
        case N: printf("%c", 204); break;
        case B: printf("%c", 185); break;
        case U: printf("%c", 206); break;
        case J: printf("%c", 202); break;
        case A: printf("%c", 255); break;
        case F: printf("%c", 220); break;
        case D: printf(" "); break;
        default: break;
    }
}

int presentacion2(int matriz[30][70], int startX, int startY, int *posFinalX, int *posFinalY) {
    for (int j = 15; j < 45; j++) {
        int x = startX + (j - 15);
        int y = startY;

        for (int i = 0; i < 12; i++) {
            printCharacter(matriz[i][j], x - 30, y + i - 20);
        }
        Sleep(1);
    }

    *posFinalX = startX + 29;
    *posFinalY = startY + 11;
    return 1;
}

int presentacion3(int matriz[30][70], int startX, int startY) {
    for (int j = 15; j < 45; j++) {
        int x = startX + (j - 40);
        int y = startY - 30;

        printCharacter(matriz[12][j], x + 30, y-30);
        Sleep(1);

        for (int i = 13; i < 24; i++) {
            printCharacter(matriz[i][j], x + 25, startY + i-20);
        }
    }
    return 1;
}

void borrarPresentacion(int matriz[30][70], int x, int y) {
    // Limpia cada posición de la matriz
    for (int i = 0; i < 50; i++) {
            Sleep(1);
        for (int j = 0; j < 70; j++) {
            // Calcula las coordenadas en la consola sumando las coordenadas iniciales
            int posX = x + j;
            int posY = y + i;
            gotoxy(posX, posY);

            // Imprime un espacio en blanco para limpiar la posición
            printf(" ");
        }
    }
}

void intro() {
    int anchoConsola =0;
    int altoConsola =0;
    maximizeConsoleWindow();
    getConsoleSize(&anchoConsola, &altoConsola);

    //igualo las variables posicionales con el ancho y lo alto de la consola
    int x = anchoConsola;
    int y = altoConsola;

    //utilizo las funciones para poder ocultar el cursor dentro de la consola y que no moleste visualmente
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    presentacion(x, y);
    system("cls");
    gotoxy((x / 2) - 30, y / 2);
    tipeo("Accediendo al menu principal", 10);
    Sleep(1000);
    tipeo("...", 300);
    Sleep(500);
    system("cls");

    int flag = 0;
    while (flag != 1) {
        int aux1 = x;
        int aux2 = y;

        // Actualizar x e y según la salida de presentacion2
        presentacion2(matriz, x / 2, y / 2, &x, &y);
        presentacion3(matriz, aux1 / 2, aux2 / 2);

        fflush(stdin);

        // Resetear posiciones para autoCorriendo
        x = 0;
        y = altoConsola * 0.3;
        Sleep(1000);
        autoCorriendo(x, y, 80,anchoConsola,altoConsola);

        Sleep(3000);

        y = 0;
        borrarPresentacion(matriz, x, y);

        x = 0;
        y = 0;
        gotoxy(x, y);
        Sleep(5500);



        flag = 1;
    }
}

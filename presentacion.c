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

/// hilo
// Mutex para sincronizar el acceso a la salida estándar
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// Variable de condición para señalizar al hilo principal cuando el hilo secundario haya completado su tarea
pthread_cond_t condicion = PTHREAD_COND_INITIALIZER;
// Bandera para indicar si el hilo secundario ha completado su tarea
int tarea_completada = 0;

// Estructura para almacenar la posición actual

void personitaBailando(int x, int y)
{
    gotoxy(x,y);
    puts("(._.)");
    gotoxy(x,y+1);
    puts("<)  )/");
    gotoxy(x,y+2);
    puts("/  \\ ");
    Sleep(500);
    gotoxy(x,y);
    puts("(._.)");
    gotoxy(x,y+1);
    puts("\\(  (>");
    gotoxy(x,y+2);
    puts(" /  \\ ");
    Sleep(500);
}

// Función que se ejecutará en el hilo
void* funcionHilo(void* arg)
{
    // Obtener la posición actual del argumento
    struct PosicionActual* posicionActual = (struct PosicionActual*)arg;

    // Moverse a una posición específica y realizar la impresión
    while (1)
    {
        // Adquirir el mutex antes de imprimir
        pthread_mutex_lock(&mutex);

        // Moverse a la posición deseada y realizar la impresión  // Moverse a la posición deseada
        personitaBailando(0,0);
        fflush(stdout);

        // Volver a la posición inicial
        gotoxy(posicionActual->x, posicionActual->y);
        // Señalizar al hilo principal que la tarea ha sido completada
        tarea_completada = 1;


        pthread_cond_signal(&condicion);
        // Liberar el mutex después de imprimir
        pthread_mutex_unlock(&mutex);

        // Esperar un tiempo antes de imprimir nuevamente
        usleep(100000);  // Esperar 0.1 segundos
    }
    return NULL;
}

/// funciones para implementar el uso de gotoxy, que determinan el tamanio de la consola y en base a eso se determinara gotoxy

void presentacion(int x, int y)
{
    gotoxy((x/2)-30,y/2);
    tipeo2("BIENVENIDO/A A AUTOMILE, SU COCHERA DE CONFIANZA\n\n",10);
    gotoxy((x/2)-30,(y/2)+5);
    Sleep(500);
    system("pause");
}

void tipeo2(const char * p,int ms)
{
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

void tipeo(const char * p,int ms)
{
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

void getConsoleSize(int* ancho, int* altura)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columnas, filas;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columnas = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    filas = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    *ancho = columnas;
    *altura = filas;
}

BOOL g_bIsMaximized = FALSE;

void maximizeAndFixConsoleWindow()
{
    HWND consoleWindow = GetConsoleWindow();

    // Obtener el estilo actual de la ventana
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);

    // Remover el estilo de la barra de título y del borde
    style &= ~(WS_CAPTION | WS_BORDER);

    // Aplicar el nuevo estilo a la ventana
    SetWindowLong(consoleWindow, GWL_STYLE, style);

    // Redibujar la ventana con el nuevo estilo
    SetWindowPos(consoleWindow, NULL, 0, 0, 0, 0,
                 SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);

    // Maximizar la ventana de la consola
    ShowWindow(consoleWindow, SW_SHOWMAXIMIZED);
}

int matriz [30][70] =
{
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

void ocultarCursor()
{
    // Secuencia de escape ANSI para ocultar el cursor
    printf("\e[?25l");
    fflush(stdout); // Asegura que la salida se limpie de inmediato
}

void printearAuto(int x, int y)
{
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

void borrarAuto(int x, int y)
{
    int i;
    for (i = 0; i < 13; i++)
    {
        printf("                                                                            ");
        gotoxy(x, y + i);
    }
}

void autoCorriendo(struct PosicionActual *posicionActual,int altoConsola,int anchoConsola)
{
    int velocidad = 2000;
    int aceleracion = 80;
    printf("\033[0;31m");
    posicionActual->x=60;
    posicionActual->y=0;
    printearAuto(posicionActual->x, posicionActual->y);
    Sleep(3000);
    while(altoConsola>posicionActual->y+13 && posicionActual->x + 60 < anchoConsola)
    {
        printearAuto(posicionActual->x, posicionActual->y);
        Sleep(velocidad/aceleracion);
        borrarAuto(posicionActual->x-3, posicionActual->y-1);
        printearAuto(posicionActual->x, posicionActual->y);
        aceleracion+=2;
        posicionActual->x += 2;
        posicionActual->y += 1;

    }
    Sleep(300);
}

void printCharacter(int valor, int x, int y)
{
    gotoxy(x, y);
    printf("\033[0;36m");
    switch (valor)
    {
    case H:
        printf("%c", 205);
        break;
    case V:
        printf("%c", 186);
        break;
    case Q:
        printf("%c", 201);
        break;
    case Z:
        printf("%c", 200);
        break;
    case C:
        printf("%c", 188);
        break;
    case E:
        printf("%c", 187);
        break;
    case I:
        printf("%c", 190);
        break;
    case L:
        printf("%c", 64);
        break;
    case K:
        printf("%c", 203);
        break;
    case N:
        printf("%c", 204);
        break;
    case B:
        printf("%c", 185);
        break;
    case U:
        printf("%c", 206);
        break;
    case J:
        printf("%c", 202);
        break;
    case A:
        printf("%c", 255);
        break;
    case F:
        printf("%c", 220);
        break;
    case D:
        printf(" ");
        break;
    default:
        break;
    }
}

int presentacion2(int matriz[30][70], struct PosicionActual *posicionActualX, struct PosicionActual *posicionActualY)
{
    int startX = posicionActualX->x - 5; // Determinar el valor inicial de x
    int startY = posicionActualY->y; // Determinar el valor inicial de y

    for (int j = 15; j < 45; j++)
    {
        int x = startX + (j - 15);
        int y = startY;

        for (int i = 0; i < 12; i++)
        {
            printCharacter(matriz[i][j], posicionActualX->x - 30, posicionActualY->y + i - 20);
        }
        posicionActualX->x = x;
        posicionActualY->y = y;

        Sleep(10);
    }

    return 1;
}

int presentacion3(int matriz[30][70], struct PosicionActual *posicionActualX, struct PosicionActual *posicionActualY) {
    // Calcular startX y startY una vez al principio de la función
    int startX = posicionActualX->x - 15; // Determinar el valor inicial de x
    int startY = posicionActualY->y + 10; // Determinar el valor inicial de y

    for (int j = 15; j < 45; j++) {
        // Calcular las nuevas posiciones de x e y para esta iteración
        int x = posicionActualX->x + (j - 40);
        int y = posicionActualY->y - 30;

        // Actualizar las posiciones actuales de x e y
        posicionActualX->x = x;
        posicionActualY->y = y;

        // Llamar a la función para imprimir el carácter matriz[12][j]
        printCharacter(matriz[12][j], x + 30, y - 30);
        Sleep(10);

        // Imprimir los caracteres de la matriz para las filas 13 a 23
        for (int i = 13; i < 24; i++) {
            // Calcular las nuevas posiciones de x e y para esta iteración
            int currentX = startX + (j - 40);
            int currentY = startY + i - 20;

            // Llamar a la función para imprimir el carácter matriz[i][j] en la posición calculada
            printCharacter(matriz[i][j], currentX + 25, currentY);
        }
    }

    return 1;
}

void borrarPresentacion(int matriz[30][70], int x, int y)
{
    // Limpia cada posición de la matriz
    for (int i = 0; i < 50; i++)
    {
        Sleep(1);
        for (int j = 0; j < 70; j++)
        {
            // Calcula las coordenadas en la consola sumando las coordenadas iniciales
            int posX = x + j;
            int posY = y + i;
            gotoxy(posX, posY);

            // Imprime un espacio en blanco para limpiar la posición
            printf(" ");
        }
    }
}

void intro()
{
    const char* archivoMP3 = "carengine.wav";
    int anchoConsola =0;
    int altoConsola =0;
    maximizeAndFixConsoleWindow();
    getConsoleSize(&anchoConsola, &altoConsola);

    //igualo las variables posicionales con el ancho y lo alto de la consola
    posicionActual.x = anchoConsola;
    posicionActual.y = altoConsola;

    pthread_t hilo;

    //utilizo las funciones para poder ocultar el cursor dentro de la consola y que no moleste visualmente
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    presentacion(posicionActual.x, posicionActual.y);
    system("cls");
    gotoxy((posicionActual.x / 2) - 30, posicionActual.y / 2);
    tipeo("Accediendo al menu principal", 10);
    Sleep(1000);
    tipeo("...", 300);
    Sleep(500);
    system("cls");

    posicionActual.x = anchoConsola/2;
    posicionActual.y = altoConsola/2;

    int flag = 0;
    while (flag != 1)
    {
        // Actualizar x e y según la salida de presentacion2
        presentacion2(matriz, &posicionActual, &posicionActual);
        presentacion3(matriz, &posicionActual, &posicionActual);
        pthread_create(&hilo, NULL, funcionHilo, (void*)&posicionActual);

        Sleep(1000);
        fflush(stdin);

        // Resetear posiciones para autoCorriendo
        posicionActual.x = 0;
        posicionActual.y = altoConsola * 0.3;

        PlaySoundA(archivoMP3,NULL,SND_ASYNC);
        Sleep(1000);
        autoCorriendo(&posicionActual, altoConsola, anchoConsola);

        Sleep(2000);

        system("cls");

        flag = 1;
    }
}

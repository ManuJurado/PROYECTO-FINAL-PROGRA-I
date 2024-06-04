#include "menu.h"

volatile char global_key = 0;
volatile char last_key;

/// hilo
// Mutex para sincronizar el acceso a la salida estándar
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// Variable de condición para señalizar al hilo principal cuando el hilo secundario haya completado su tarea
pthread_cond_t condicion = PTHREAD_COND_INITIALIZER;
// Bandera para indicar si el hilo secundario ha completado su tarea
int tarea_completada = 0;

///FUNCIONES DE HILOS--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE HILOS--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE HILOS--------------------------------------------------------------------------------------------------------------------///

void *key_listener(void *arg) // funcion hilo auxiliar que permanentemente analiza lo ingresado por teclado en caso de que existe kbhit
{

    while (1)
    {
        if (_kbhit())
        {
            last_key = getch();
        }
        Sleep(3);
    }

    return NULL;
}

void *giro_coche(void *arg)// Hilo para procesar la tecla capturada
{

    Medidas *localMedidasConsola = (Medidas *)arg;  // Cast del argumento al tipo correcto
    int x = ((localMedidasConsola->ancho)/2 - 80/2)-10;
    int y = localMedidasConsola->alto * 0.75 - 5;

    while (1)
    {
        // Bloquear el mutex antes de acceder a la variable global
        if (last_key !=0)
        {
            if (last_key == 75)   // Tecla izquierda
            {
                global_key = 1;
                centro(x,y);
                Sleep(70);
                izq1(x,y);
                Sleep(70);
                izq2(x,y);
                Sleep(70);
                izq3(x,y);
                Sleep(70);
                izq4(x,y);
                Sleep(70);
                izq5(x,y);
                Sleep(70);
                izq4(x,y);
                Sleep(70);
                izq3(x,y);
                Sleep(70);
                izq2(x,y);
                Sleep(70);
                izq1(x,y);
            }
            else if (last_key == 77)     // Tecla derecha
            {
                global_key = 1;
                centro(x,y);
                Sleep(70);
                der1(x,y);
                Sleep(70);
                der2(x,y);
                Sleep(70);
                der3(x,y);
                Sleep(70);
                der4(x,y);
                Sleep(70);
                der5(x,y);
                Sleep(70);
                der4(x,y);
                Sleep(70);
                der3(x,y);
                Sleep(70);
                der2(x,y);
                Sleep(70);
                der1(x,y);
            }
            // Reiniciar la variable global y el flag después de usarla
            last_key = 0;
            global_key = 0;

        }
        Sleep(10); // Esperar un momento antes de revisar de nuevo
    }
    // Limpiar el búfer de entrada después de que el bucle principal haya terminado

    return NULL;
}

void izq1(int x, int y)
{
    MUTEXLOCK;
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,C,D,D,D,D,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,D,D,D,D,D,D,D,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,A,B,B,B,B,B,C,C,C,D,D,D,D,D,D,D,D,C,D,D,D,D,D,D,D,C,C,C,B,B,B,B,B,B,B,A,A,A,A,A,B,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,C,C,D,D,C,C,C,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,C,C,C,C,C,B,B,B,A,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,A,A,A,A,A,A,A);
    gotoxy(x,y+7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,C,C,C,C,C,C,C,B,A,A,A,A,A,B,B,B,B,C,C,C,C,C,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,A,A,B,A,A,B,B,B,B,B,B,B,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,A,A,A);
    gotoxy(x,y+8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,C,C,B,A,A,A,B,B,B,B,C,C,C,C,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,A,B,B,B,B,B,A,A,A,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,B,A,A,B,B,B,C,C,C,B,B,B,B,B,B,B,B,A,A,A,A,A,B,B,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,C,C,C,C,B,B,B,B,B,B,A,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,C,B,C,D,C,B,B,B,B,B,B,B,A,A,A,A,A,A,A,B,B,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,B,B,B,B,B,A,A,A,A,A,A,A,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,D,D,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,A,A,A,A,A,A,B,B,B,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,D,D,D,C,C,C,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,A,A,A,A,A,B,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,C,D,C,C,C,C,C,C,C,C,D,C,C,C,D,D,D,D,D,C,C,C,C,C,C,C,C,B,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,D,C,C,A,A,A,C,C,D,D,C,C,B,C,C,C,C,D,D,D,D,C,C,C,D,C,C,C,C,C,C,C,D,C,C,C,C,D,D,D,D,D,D,D,D,C,B,B,B,B,B,B,A,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,C,C,C,C,B,A,C,C,D,B,B,B,B,B,B,B,B,B,B,B,C,C,D,C,D,C,C,C,C,C,C,C,C,C,C,C,C,C,D,C,D,D,C,C,B,B,B,D,D,D,C,B,B,A,A,A,A,A,A,A,C,C,C,C,C,C,D,D,D,D,D,D,D,D,C,C,C,D,D,D,D,D);
    gotoxy(x,y+16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,B,B,A,A,B,C,B,B,A,A,A,A,B,B,B,B,B,B,B,B,B,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,B,B,B,B,B,A,B,C,D,C,B,A,A,A,A,A,A,B,C,C,C,C,D,C,C,B,C,B,C,C,C,C,C,C,C,D,D,D,D,D,D,D);
    gotoxy(x,y+17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,C,A,A,A,A,A,A,A,C,C,B,A,A,B,A,A,A,B,B,B,B,B,B,B,A,B,B,B,B,C,B,D,B,B,B,B,B,B,B,B,B,B,C,C,B,B,C,C,B,B,A,A,A,A,A,B,C,B,B,C,C,C,A,A,A,A,A,A,A,A,C,C,C,D,C,B,A,B,B,B,B,B,C,C,C,C,C,C);
    gotoxy(x,y+18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,C,A,A,A,A,A,A,A,A,C,C,C,B,B,B,B,B,B,B,B,B,B,A,A,A,A,A,A,B,B,C,C,B,B,D,D,D,D,D,D,B,B,C,C,B,B,B,B,B,A,A,B,B,A,A,A,A,B,B,B,C,C,C,A,A,A,A,A,A,A,A,A,B,B,B,A,A,A,A,A,A,B,B,B,B,B,B,B,B,B);
    gotoxy(x,y+19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,C,A,A,A,A,A,A,A,A,D,C,B,B,B,B,B,C,C,C,C,C,C,B,A,A,A,A,A,B,C,C,B,C,C,D,D,D,C,B,C,C,B,B,B,B,B,B,A,A,B,A,A,A,A,A,B,B,B,B,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,A,A,A,B,C,C);
    MUTEXUNLOCK;
}

void izq2(int x, int y)
{
    MUTEXLOCK;
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,D,D,D,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,D,D,D,D,D,D,D,D,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,B,B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,B,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,A,A,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,A,A,A,A,A,A,A,A);
    gotoxy(x,y+6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,A,B,B,B,B,B,C,C,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,A,A,A,A,A,A,A);
    gotoxy(x,y+7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,C,D,D,D,C,C,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,B,B);
    gotoxy(x,y+8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,C,C,D,C,C,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C);
    gotoxy(x,y+9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,C,C,C,C,B,B,B,B,B,B,B,B,B,A,A,A,A,B,B,B,B,B,B,B,B,C,B,B,B,B,B,B,B,B,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,B,B,B,B,C,C,C,B,B,B,B,B,B,B,A,A,A,A,A,A,B,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,B,B,B,C,C,C,B,B,B,B,B,B,B,A,B,B,A,A,A,A,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,D,D,D,D,D,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,A,A,A,A,A,B,C,C,C,B,B,B,B,B,B,B,A,A,A,B,B,A,A,A,A,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,B,B,C,C,C,B,B,B,B,B,A,A,A,A,A,B,B,B,A,A,A,A,B,B,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,D,D,D,D,D,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,B,B,C,C,B,B,B,B,B,B,A,A,A,A,A,A,A,B,B,A,A,A,A,B,C,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,C,C,C,C,C,C,C,D,D,B,B,B,B,D,D,D,D,D,C,C,C,C,C,C,C,B,B,C,C,C,C,D,D,C,C,A,B,B,B,B,B,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",C,C,C,B,B,B,B,B,B,B,A,A,A,A,A,A,A,B,B,A,A,A,B,C,D,D,C,B,B,B,C,C,C,C,C,D,D,D,C,C,C,D,C,C,C,C,C,C,C,D,B,A,A,B,D,D,C,C,D,D,D,D,D,C,B,B,B,B,B,A,A,A,B,C,C,B,B,A,A,A,B,B,B,B,B,C,B,B,B,C,C,C,C,D,D,D,D,D,D,D);
    gotoxy(x,y+16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,C,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,B,B,B,C,B,B,B,B,B,B,B,C,B,B,D,C,D,C,C,C,C,C,C,C,C,C,C,B,B,C,C,C,C,B,C,C,C,C,C,C,D,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,C,B,B,A,C,C,C,C,C,D,D);
    gotoxy(x,y+17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,C,C,B,A,A,A,A,A,A,A,B,C,D,B,B,B,A,A,A,B,B,B,B,B,B,B,B,B,B,C,C,D,D,D,D,D,D,D,D,D,D,D,C,C,B,A,A,C,C,D,B,C,C,C,C,B,C,B,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,C,B,B,A,A,C,C,C,C);
    gotoxy(x,y+18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,C,D,C,C,C,A,A,A,A,A,B,C,C,B,B,A,A,A,A,A,A,B,B,B,B,A,A,B,B,B,B,C,C,B,B,C,C,C,B,B,B,B,B,C,A,A,B,B,B,B,B,B,B,A,B,B,B,B,B,B,D,C,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,C,B,B,A,A,A,C,C,C,C,C);
    gotoxy(x,y+19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,C,C,C,C,B,A,A,A,A,A,A,C,C,C,B,C,B,B,B,B,B,C,B,A,A,A,A,A,A,B,B,C,C,C,C,D,D,D,D,D,C,C,C,B,B,C,A,A,A,B,B,A,A,A,A,B,B,B,B,B,B,C,C,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,A,A,A,B,C,C,C,C,C,C);
    MUTEXUNLOCK;
}

void izq3(int x, int y)
{
    MUTEXLOCK;
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,D,D,D,D,D,D,D,D,C,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,B,B,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,B,B,A,A,A,A);
    gotoxy(x,y+6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,A,B,B,B,A,A,A,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,B,A,A,A);
    gotoxy(x,y+7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,B,B,B,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C);
    gotoxy(x,y+8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,C,C,C,C,C,C,C,C,B,B,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,B,C,C,D,D,C,B,B,B,B,B,B,B,B,B,B,B,B,B,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,C,D,D,C,B,B,B,B,B,B,B,B,A,A,B,B,B,B,B,B,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,C,D,C,B,B,B,B,B,B,B,A,A,A,A,A,A,B,B,B,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,C,C,C,B,B,B,B,B,B,B,B,A,A,A,A,A,B,B,B,C,C,D,D,D,D,D,D,D,D,D,D,D,C,C,C,D,D,D,D,C,C,C,C,C,D,D,D,D,D,D,D,C,C,B,B,B,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,B,B,B,C,C,C,B,B,B,B,B,B,A,B,B,A,A,A,A,B,B,C,C,C,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,D,C,C,C,C,C,C,D,D,C,B,A,A,A,B,B,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,A,A,A,A,A,A,B,B,C,C,B,B,B,B,B,A,A,A,A,A,B,B,A,A,A,A,B,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,A,A,A,A,A,A,A,B,B,B,B,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,B,B,A,A,B,B,B,C,C,C,B,B,B,B,B,A,A,A,A,A,A,B,B,A,A,A,A,A,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,B,B,B,B,B,B,C,C,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,B,B,A,A,A,A,A,A,A,A,B,B,B,B,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,B,B,C,C,B,B,B,B,B,A,A,A,A,A,A,A,A,B,B,A,A,A,A,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,C,B,A,B,B,B,B,C,C,D,C,C,C,D,D,D,D,D,D,C,C,B,B,B,B,B,B,B,A,A,A,A,A,A,A,B,B,B,B,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,B,B,C,C,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,B,B,A,A,B,C,C,C,B,B,B,B,B,C,C,B,C,C,D,D,D,C,B,B,C,B,A,A,A,B,B,B,B,B,B,B,D,D,D,D,D,D,D,D,D,D,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,C,C,C,D,D,D,D,D,D,D);
    gotoxy(x,y+18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,C,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,C,C,C,B,A,A,B,B,B,B,B,B,B,B,C,B,B,C,C,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,B,B,B,B,C,C,C,C,C,C,D,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,B,A,B,B,B,C,C,C,C,C,D,D,D,D,D,D,D);
    gotoxy(x,y+19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,C,C,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,C,C,C,B,B,B,A,A,B,B,B,B,B,B,B,B,B,B,B,C,C,C,C,C,C,C,C,C,C,C,D,C,C,B,B,B,A,B,B,B,B,B,B,C,C,C,B,C,D,C,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,D,D,D,D,D);
    MUTEXUNLOCK;
}

void izq4(int x, int y)
{
    MUTEXLOCK;
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,A,A,A,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,B,B,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,B,B,A,A,A,A,A,A);
    gotoxy(x,y+7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,B,B,B);
    gotoxy(x,y+8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,C,C,D,D,C,C,B,B,B,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,C,C,C,C,C,B,B,B,B,B,B,B,B,B,B,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,B,C,D,C,C,B,B,B,B,B,A,A,A,A,A,A,A,A,B,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,B,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,B,A,B,B,B,B,C,C,C,B,B,B,B,B,B,A,B,A,A,A,A,A,A,B,B,C,C,C,C,D,D,D,D,C,C,C,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,B,B,B,B,B,B,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,C,D,C,B,B,B,B,B,B,B,B,B,B,A,A,A,A,B,B,C,C,C,D,D,C,D,D,C,C,C,C,C,D,D,C,C,C,C,C,C,D,D,C,C,C,D,C,C,C,C,C,B,B,B,B,A,A,A,A,A,B,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,A,A,A,A,A,A,A,A,B,B,B,C,C,B,B,B,B,B,B,B,A,A,A,A,A,B,B,A,A,A,A,B,B,C,C,C,D,D,D,D,D,D,C,B,B,B,B,B,C,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,A,A,A,A,A,A,A,B,B,B,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,B,B,B,A,A,A,B,B,C,C,C,B,B,B,B,B,A,A,A,A,A,B,B,B,A,A,A,A,A,B,B,C,D,D,D,D,D,D,D,D,D,D,D,C,B,B,B,B,C,C,C,C,C,C,C,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,B,A,A,A,A,A,A,A,A,B,B,B,B,C,C,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,B,B,C,C,B,B,B,B,B,A,A,A,A,A,A,A,A,B,B,A,A,A,A,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,B,B,B,C,B,B,B,B,B,B,B,B,C,D,C,C,C,C,D,D,D,D,D,D,D,C,C,B,B,B,B,B,B,A,A,A,A,A,A,A,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,B,C,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,A,B,B,A,A,B,C,C,C,C,B,B,B,B,B,C,C,C,C,C,C,C,C,B,B,B,B,A,A,A,B,B,B,B,B,B,A,B,D,D,D,D,D,D,D,D,D,C,C,B,B,B,B,A,A,A,A,A,A,A,A,A,A,B,B,C,C,C,C,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,B,B,B,C,C,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,C,C,C,B,B,A,B,B,B,B,B,B,B,B,B,B,C,C,C,C,C,C,C,B,B,B,B,B,B,B,C,C,C,C,C,B,C,C,C,C,C,C,C,C,D,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,D,D,D,D,D,D,D,D,D);
    MUTEXUNLOCK;
}

void izq5(int x, int y)
{
    MUTEXLOCK;
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,A,A,A,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,A,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,B,B,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,A,A,B,B,B,B,B,A,A,A,A,A,A,A,A,A,B,C,C,C,C,C,C,C,C,C,D,D,D,D,C,C,C,C,C,C,D,D,D,D,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,B,B,B,B,A,A,A,A);
    gotoxy(x,y+5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C);
    gotoxy(x,y+6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,D,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,D,D,D,D,D);
    gotoxy(x,y+7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,B,B,B,B,C,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,B,B,B,B,B,B,C,C,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,B,B,B,B,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,B,B,B,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,C,C,C,C,B,A,A,A,A,A,A,A,A,B,B,B,B,B,C,C,D,D,D,D,D,D,D,C,C,C,C,C,B,B,B,B,B,C,C,C,D,D,D,D,D,D,D,D,D,C,C,C,C,B,B,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,A,A,A,B,C,C,C,C,C,C,C,C,C,B,B,A,A,A,A,B,C,C,C,C,C,C,D,D,D,B,A,B,B,B,A,B,A,A,A,A,A,A,A,B,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,B,B,B,A,A,A,A,A,B,B,B,C,C,C,C,B,B,B,A,A,A,B,C,C,C,C,B,B,B,B,B,B,C,C,C,C,A,B,B,B,A,A,A,A,A,A,A,A,B,B,A,B,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,B,B,A,A,A,A,A,A,A,A,B,B,B,C,C,B,B,B,A,A,A,C,B,B,A,A,A,A,A,A,B,A,A,A,A,B,B,B,B,A,B,B,A,A,A,A,A,B,B,A,A,B,B,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,B,B,B,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,A,A,A,B,C,C,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,B,A,A,A,A,B,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,B,A,A,A,A,A,A,A,A,B,B,B,A,A,A,B,A,A,C,A,A,A,A,A,B,B,B,B,B,A,B,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,B,B,A,A,A,A,A,A,A,B,A,A,A,A,A,A,A,A,A,A,A,A,A,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,C,C,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    MUTEXUNLOCK;
}

void der1(int x, int y)
{
    MUTEXLOCK;
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,A,B,C,C,D,D,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,C,D,D,D,D,D,D,D,D,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,A,A,A,A,A,A,A,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,A,B,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,A,A,A,A,A,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,B,B,B,B,B,B,B,B,B,B,A,B,B,B,B,A,B,B,B,B,B,B,B,A,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,B,A,A,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,A,A,B,B,B,B,B,B,B,B,B,B,B,C,C,C,C,C,C,C,B,B,B,B,B,B,B,B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,B,C,C,C,D,D,C,C,C,C,C,C,C,C,C,C,C,B,B,B,B,B,C,C,C,C,C,C,C,C,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,C,C,C,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,C,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,D,D,D);
    gotoxy(x,y+9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,A,A,A,A,A,B,B,B,B,A,B,B,B,B,B,B,B,C,C,C,B,B,B,A,A,A,A,B,C,C,C,D,D,D,D,D,D,C,C,C);
    gotoxy(x,y+10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,B,B,B,B,B,B,B,A,A,B,A,A,B,B,B,A,A,B,B,B,B,C,C,C,B,A,A,A,B,C,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C);
    gotoxy(x,y+11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,C,C,B,B,B,B,B,A,A,A,A,A,A,A,A,B,B,B,B,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,B,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,B,A,A,A,A,A,A,A,A,A,B,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,A,B,B,C,C,C,B,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,B,A,A,A,A,A,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,C,C,C,C,D,D,D,D,D,D,D,D,D,C,C,B,A,A,A,C,D,C,C,C,C,C,C,D,D,D,C,C,D,C,C,C,C,C,C,C,C,C,D,C,C,C,C,C,D,D,D,D,D,C,B,C,C,C,C,B,B,B,B,A,A,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,C,C,A,C,C,C,A,C,C,C,C,C,C,B,B,B,A,A,A,B,C,C,D,B,A,B,B,B,B,B,A,C,D,C,D,C,C,C,D,C,C,C,C,C,C,D,C,C,C,C,D,D,D,D,C,D,D,C,D,D,C,B,B,B,B,B,B,A,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,C,C,C,C,B,B,B,B,B,B,A,A,B,B,B,B,A,A,A,A,A,A,A,C,C,C,A,A,A,B,A,A,A,A,A,B,B,B,D,C,D,C,C,C,C,C,C,C,C,C,C,C,C,D,C,D,C,C,C,C,C,C,C,C,D,D,C,B,A,A,A,A,C,C,C,C,C,C,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",C,C,C,C,A,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,B,B,B,C,C,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,C,C,C,C,C,C,C,C,C,B,B,D,C,B,A,A,A,A,A,B,C,C,B,A,A,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",C,B,B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,D,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,D,B,B,B,B,B,B,B,B,B,B,C,C,B,B,C,B,B,B,B,B,B,B,B,B,B,B,B,C,C,C,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,C,B,B,B,B,B,A,A,B,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,B,B,B,B,B,B,B,A,A,A,A,A,A,A,B,C,C,B,C,D,D,D,D,D,B,C,C,B,C,C,B,B,B,B,B,B,B,B,B,B,B,C,B,B,C,C,C,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D);
    MUTEXUNLOCK;
}

void der2(int x, int y)
{
    MUTEXLOCK;
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,C,B,B,A,A,A,A,A,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,A,A,A,A,B,C,D,D,D,D,D,D,D,D,D,D,D,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,B,A,B,B,B,B,A,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,A,A,A,A,A,A,B,B,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,A,A,B,B,B,B,B,B,B,B,A,A,A,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,B,B,B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",C,C,C,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,B,B,B,B,B,C,C,C,C,C,C,C,C,C,C,C,C,B,B,B,B,A,A,A,A,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",C,C,C,D,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,C,C,C,C,C,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,C,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,B,B,B,B,B,B,B,B,B,A,A,A,A,A,B,B,B,B,B,B,B,B,B,B,B,B,C,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,D,D,D,D,C,C,C,C,C,B,B,B,B,B,A,A,A,B,A,A,A,A,A,B,B,B,B,B,B,B,B,C,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,B,B,B,B,A,A,A,A,A,A,A,A,B,B,B,B,B,B,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,B,B,B,C,C,C,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,B,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,A,A,A,A,A,B,B,B,B,A,A,A,B,B,B,B,B,C,C,D,D,D,D,D,C,C,C,C,C,C,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,C,B,B,A,A,A,A,A,A,A,A,A,A,B,A,A,A,A);
    gotoxy(x,y+16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,D,D,C,C,C,D,D,C,B,B,C,B,B,B,B,B,C,C,C,C,C,C,C,C,D,D,D,D,D,C,C,B,C,C,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,C,B,B,A,A,A,A,C,C,C,C,C,C);
    gotoxy(x,y+17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,C,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,C,C,C,C,B,B,B,A,B,B,B,B,C,C,C,C,B,B,C,B,B,A,B,C,C,C,C,D,C,C,C,C,D,D,D,D,D,D,D,C,C,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,C,B,B,B,B,C,C,D,D,D,C,C,C);
    gotoxy(x,y+18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,C,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,B,B,A,B,B,A,A,B,A,A,A,B,B,B,C,C,C,C,C,B,B,B,C,C,C,C,C,C,C,C,D,C,C,C,C,C,C,D,D,D,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,C,C,C,C,D,D,D,D,C,C,D,D,D,D,D);
    gotoxy(x,y+19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,B,C,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,C,C,C,C,C,C,C,C,C,C,C,C,C,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D);
    MUTEXUNLOCK;
}

void der3(int x, int y)
{
    MUTEXLOCK;
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,D,D,D,D,D,D,D,C,C,D,D,C,C,C,C,C,C,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,C,C,B,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,C,C,C,C,C,C,D,D,D,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,C,D,D,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,B,B,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,B,B,B,C,C,C,C,C,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,B,B,B,B,B,B,B,B,B,C,C,C,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,B,B,B,B,B,B,B,B,B,B,B,C,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,D,D,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,B,B,B,A,A,A,A,A,B,B,B,B,B,B,B,D,D,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,B,B,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,B,B,A,A,A,A,A,A,A,A,B,B,B,B,B,B,C,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,B,A,A,A,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,D,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,B,B,A,A,A,B,C,D,D,C,B,B,B,B,B,B,B,B,B,B,B,B,B,C,B,C,C,D,D,D,D,C,C,C,C,C,C,C,C,C,B,B,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,B,A,A,A,A,B,B,C,D,C,C,C,C,B,B,C,C,B,A,B,A,B,B,A,B,C,B,A,A,B,D,D,D,D,D,D,D,D,C,C,B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,C,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,A,A,A,A,A,B,B,A,A,B,B,C,C,C,C,B,B,B,A,A,A,A,A,B,B,A,A,B,C,C,C,C,C,C,C,D,D,D,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,B,A,A,A,C,C,D,D,D,D,D,D,D,D,D,D,C,C,C,B,B,B,B,C,C,C,C,C,D,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B);
    gotoxy(x,y+19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,A,A,A,A,A,A,B,B,B,B,B,A,A,A,B,B,B,C,B,B,B,B,B,B,B,B,B,B,C,C,B,B,B,B,A,A,B,B,B,B,C,C,C,B,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,A,A,A,A,B,B,B,A,B,B,A,A,A,A);
    MUTEXUNLOCK;
}

void der4(int x, int y)
{
    MUTEXLOCK;
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,C,C,B,A,A,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,D,D,D,D,C,C,C,C,D,D,D,D,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,D,C,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,C,C,D,D,D,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,D,D,D,D,D,B,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,B,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,B,C,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,B,B,B,B,C,C,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,B,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,A,B,B,B,B,B,B,B,B,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,B,A,A,B,C,C,C,C,D,D,D,D,C,C,C,C,D,D,D,D,C,C,C,B,A,A,A,A,B,B,B,B,B,C,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,B,A,A,A,A,A,B,C,C,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,A,A,A,A,A,A,A,A,B,B,B,B,B,C,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,B,B,A,A,A,A,B,B,B,B,C,B,B,A,B,C,D,D,D,D,D,C,C,C,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,B,A,A,B,A,A,A,A,B,B,A,B,B,A,A,B,C,C,C,C,C,D,D,D,D,C,C,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,D,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,A,A,A,B,C,C,B,B,B,B,B,B,B,B,C,C,C,C,B,B,B,B,C,C,C,D,D,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,A,A,A);
    gotoxy(x,y+19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,B,A,A,A,A,B,C,C,D,D,D,D,D,D,D,D,D,C,C,B,B,A,B,B,A,B,B,A,B,B,B,C,C,C,C,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,C,B,B,A,A,A,A,B,B,B,B,A,B,B,B,A,A,A,A,A,A);
    MUTEXUNLOCK;
}

void der5(int x, int y)
{
    MUTEXLOCK;
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,C,C,C,C,C,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,B,B,B,B,A,A,B,A,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,A,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,B,A,A,B,B,A,A,A,A,A,A,A,B,B,C,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,B,B,B,B,B,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,B,B,B,B,C,C,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,A,A,B,B,B,B,B,C,C,C,C,C,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,D,D,D,D,C,C,C,C,C,C,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,B,B,B,B,C,C,C,C,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,B,C,C,C,C,B,B,B,B,B,A,A,A,A,A,B,B,B,B,B,A,A,B,A,A,A,B,B,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",C,C,B,B,B,B,B,B,B,B,B,B,B,B,A,A,A,A,A,A,B,B,B,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,D,D,D,C,C,C,D,D,D,C,D,D,D,D,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,A,A,A,A,B,B,B,B,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,D,D,D,D,C,C,C,C,C,C,C,D,D,D,D,D,C,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,D,C,D,D,D,C,C,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",C,D,D,C,D,D,D,D,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,B,B,C,C,C,C,C,C,C,C,C,C,C,C,B,B,B,A,A,A,A,A,A,A,A,A,A,B,B,B,A,A,A,A,B,B,B);
    gotoxy(x,y+17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,B,B,A,B,B,B,C,C,D,C,C,C,C,C,C,C,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,B,A,A,A,A,A,A,A,A,A,A,A,B,B);
    gotoxy(x,y+18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,B,B,B,A,A,A,C,C,D,D,C,C,C,C,C,C,C,C,C,C,A,A,A,B,B,B,A,A,A,A,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,B,A,A,A,A,A,A,A,A,B,B,B,B,C,C,C,C,C,C,C,C,A,A,A,A,A,B,B,B,A,A,A,A,A,B,A,B,A,A,A,A,A,A,A,A,A,A,A,A,A);
    MUTEXUNLOCK;
}

void centro(int x, int y)
{
    MUTEXLOCK;
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,B,B,B,A,A,A,A,A,B,C,D,D,D,D,C,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A);
    gotoxy(x,y+5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,B,B,B,B,B,B,C,C,C,C,C,D,D,D,D,D,D,C,C,B,B,A,A,A,A,A,A,A,A,A,A,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,C,D,D,D,C,C,A,A,A,A);
    gotoxy(x,y+6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,B,B,B,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,C,D,C,C,B,A,A,A,A,A,B,B,B,B,B,B,B,C,C,C,C,C,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,B,B,B,B,B,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,B,D,D,D,D,D,D,C,C,C,C,C,C,B,A,A,A,A);
    gotoxy(x,y+7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",B,B,B,B,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,A,A,A,B,B,B,B,B,C,C,C,C,C,C,C,C,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,C,C,C,C,C,B,B,B,B,A,A,A,A,A,A,A,B,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,B,B);
    gotoxy(x,y+8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",A,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,B,B,B,B,B,C,C,C,C,C,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,C,C,C,B,B,B,A,A,A,B,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C);
    gotoxy(x,y+9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,B,B,B,B,B,B,B,B,B,B,B,B,B,A,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,A,A,B,B,B,B,B,A,A,B,B,B,B,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,B,B,B,B,B,A,A,A,A,A,B,B,B,B,B,C,C,C,C,C,C,B,B,B,B,B,B,B,B,B,B,A,A,A,A,B,B,B,B,A,A,B,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,A,A,A,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,B,B,B,B,B,B,A,A,A,B,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,B,B,B,C,C,C,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,D,C,C,C,B,B,B,B,B,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,C,B,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,B,A,D,D,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,D,D,D,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,B,B,A,A,A,B,A,A,A,C,D,C,C,C,D,D,D,D,D,D,C,C,D,D,C,C,C,C,C,C,C,D,C,C,C,C,D,D,D,D,D,D,C,C,B,B,B,B,C,C,C,C,C,B,A,A,C,C,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,A,A,A,A,B,C,C,C,B,B,B,B,B,C,B,B,C,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D,C,B,B,B,B,B,B,A,A,A,A,A,B,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,C,B,A,A,A,A,A,A,C,C,C,B,A,A,B,A,A,B,B,B,B,B,B,B,B,C,C,D,D,D,D,D,D,D,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,D,C,B,A,A,A,A,A,A,A,A,B,C,C,C,C,C,C,C,C,D,D,D,D,D,D,D,D,D);
    gotoxy(x,y+18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,D,D,C,C,C,C,D,D,D,D,D,C,C,C,B,A,A,A,A,A,A,A,C,C,B,B,B,B,A,A,A,B,B,B,B,B,B,B,B,B,B,C,C,C,C,C,C,C,D,D,D,D,C,C,C,C,B,B,C,C,B,C,C,C,C,C,B,B,C,C,B,A,A,A,A,A,A,A,A,A,B,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C);
    gotoxy(x,y+19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",D,C,C,C,C,C,C,C,B,B,C,C,C,C,B,B,A,A,A,A,A,A,A,A,B,C,C,B,A,A,B,B,B,A,A,A,A,A,A,A,A,B,B,B,B,C,B,B,C,C,C,C,C,C,B,B,C,C,B,B,B,B,B,B,B,B,B,B,B,B,A,B,B,B,C,C,B,A,A,A,A,A,A,A,A,A,A,B,C,C,C,C,C,C,C,B,B,B,B,B);
    MUTEXUNLOCK;
}

void *funcionHiloCoche(void *arg)
{
    Medidas *localMedidasConsola = (Medidas *)arg;  // Cast del argumento al tipo correcto
    int x = ((localMedidasConsola->ancho)/2 - 80/2)-10;
    int y = localMedidasConsola->alto * 0.75 -5;
    char key;

    // Inicializar el mutex
    pthread_mutex_init(&key_mutex, NULL);

    // Leer teclas presionadas hasta que se presiona una flecha izquierda o derecha
    while (1)
    {
        while (last_key != 77 && last_key != 75 && !global_key)
        {
            for (int i = 0; i < 4; i++)
            {
                centro(x, y);
                Sleep(50);
                if (last_key == 77 || last_key == 75) break;
            }

            for (int i = 0; i < 4; i++)
            {
                der1(x, y);
                Sleep(50);
                if (last_key == 77 || last_key == 75) break;
            }

            for (int i = 0; i < 4; i++)
            {
                centro(x, y);
                Sleep(50);
                if (last_key == 77 || last_key == 75) break;
            }

            for (int i = 0; i < 4; i++)
            {
                izq1(x, y);
                Sleep(50);
                if (last_key == 77 || last_key == 75) break;
            }

        }
    }
}


///FUNCIONES DE HILOS--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE HILOS--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE HILOS--------------------------------------------------------------------------------------------------------------------///


///FUNCIONES DE PRESENTACION --------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE PRESENTACION --------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE PRESENTACION --------------------------------------------------------------------------------------------------------------------///

Medidas medidasConsola = {0, 0};

BOOL g_bIsMaximized = FALSE;

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

void printearAuto(int x, int y)///printea un coche en simbolos
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

void borrarAuto(int x, int y)///borra el auto printeado
{
    int i;
    for (i = 0; i < 13; i++)
    {
        printf("                                                                            ");
        gotoxy(x, y + i);
    }
}

void autoCorriendo(struct PosicionActual *posicionActual,int altoConsola,int anchoConsola) ///
{
    int velocidad = 3000;
    int aceleracion = 100;
    printf("\033[0;31m");
    posicionActual->x=anchoConsola/4;
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
    printf("\033[0m"); // Vuelve al color predeterminado
    Sleep(30);
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

int presentacion3(int matriz[30][70], struct PosicionActual *posicionActualX, struct PosicionActual *posicionActualY)
{
    // Calcular startX y startY una vez al principio de la función
    int startX = posicionActualX->x - 15; // Determinar el valor inicial de x
    int startY = posicionActualY->y + 10; // Determinar el valor inicial de y

    for (int j = 15; j < 45; j++)
    {
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
        for (int i = 13; i < 24; i++)
        {
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

    pthread_t hiloManejando;
    pthread_t hiloAux;
    pthread_t keyCapture;

    pthread_create(&keyCapture,NULL,key_listener,NULL);
    pthread_join(&keyCapture,NULL);

    maximizeAndFixConsoleWindow();
    getConsoleSize(&medidasConsola.ancho, &medidasConsola.alto);

    //igualo las variables posicionales con el ancho y lo alto de la consola
    posicionActual.x = medidasConsola.ancho;
    posicionActual.y = medidasConsola.alto;

    pthread_t hilo;

    //utilizo las funciones para poder ocultar el cursor dentro de la consola y que no moleste visualmente
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    presentacion(medidasConsola.ancho, medidasConsola.alto);
    system("cls");
    gotoxy((medidasConsola.ancho / 2) - 30, medidasConsola.alto / 2);
    tipeo("Accediendo al menu principal", 10);
    Sleep(1000);
    tipeo("...", 300);
    Sleep(500);
    system("cls");

    posicionActual.x = medidasConsola.ancho/2;
    posicionActual.y = medidasConsola.alto/2;

    int flag = 0;
    while (flag != 1)
    {
        // Actualizar x e y según la salida de presentacion2
        presentacion2(matriz, &posicionActual, &posicionActual);
        presentacion3(matriz, &posicionActual, &posicionActual);

        Sleep(1000);
        fflush(stdin);

        // Resetear posiciones para autoCorriendo
        posicionActual.x = 0;
        posicionActual.y = medidasConsola.alto * 0.3;

        PlaySoundA(ARCHIVO_MP3,NULL,SND_ASYNC);
        Sleep(1000);
        autoCorriendo(&posicionActual, medidasConsola.alto, medidasConsola.ancho);

        Sleep(2000);

        system("cls");

        flag = 1;
    }

    PlaySoundA(ARCHIVO_2_MP3,NULL,SND_ASYNC | SND_LOOP);
    Sleep(1300);

    pthread_create(&hiloAux,NULL,giro_coche,&medidasConsola);
    pthread_create(&hiloManejando,NULL,funcionHiloCoche,&medidasConsola);
}




///FUNCIONES DE PRESENTACION E HILOS--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE PRESENTACION E HILOS--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE PRESENTACION E HILOS--------------------------------------------------------------------------------------------------------------------///



///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///

int mainMenu(int anchoConsola, int altoConsola)
{
    char contra[MAX_CARACTERES], opcion, op;
    int flag, dni;
    do
    {
        leerArchPersonas();
        menuInicio(anchoConsola,altoConsola);
        flag = inicio(anchoConsola, altoConsola);

        if (flag == 1)
        {
            do
            {
                menuCrearUsuario(anchoConsola, altoConsola, &dni, contra);

                MUTEXLOCK;
                gotoxy(anchoConsola/2-33,altoConsola/2-10);
                printf("ESCAPE para volver hacia atr%cs / C para continuar...",160);

                opcion = getch();
                MUTEXUNLOCK;
                flag = (opcion == 27) ? 0 : 1;
            }
            while (flag == 1);
        }
        else if (flag == 2)
        {
            flag = ingresaUsuario(anchoConsola,altoConsola);

            if (flag == 1)
            {
                cuadroMenuInstantaneo(anchoConsola,altoConsola);
                MUTEXLOCK;
                gotoxy(anchoConsola/2-33,altoConsola/2-9);
                printf("Has superado la cantidad m%cxima de intentos.",160);
                gotoxy(anchoConsola/2-33,altoConsola/2-7);
                printf("Presione cualquier tecla para salir al men%c principal...",163);
                MUTEXUNLOCK;

                opcion = getch();
            }
            else  //flag = 2  ->  Ingresa sesión.
            {
                if (tipoUsuario(dni)){
                    menuOpcionesDeAdmin(anchoConsola,altoConsola,dni);
                }
                else{
                    menuOpcionesDeUsuario(anchoConsola,altoConsola,dni);
                }

                MUTEXLOCK;
                gotoxy(anchoConsola/2-33,altoConsola/2-8);
                printf("Presione cualquier tecla para salir al men%c principal...",163);
                MUTEXUNLOCK;

                opcion = getch();
                flag = (opcion == 27) ? 0 : 1;
            }
        }
    }
    while (flag>=0);

    do
    {
        MUTEXLOCK;
        gotoxy((medidasConsola.ancho/2-10),(medidasConsola.alto * 0,75));
        printf("\nIngrese ESC para finalizar...\n");
        op = getch();
        MUTEXUNLOCK;
    }
    while (op != ESC);

    return 1;
}

int inicio(int x, int y)
{
    int flag = 0;
    char opcion;

    do
    {
        opcion = getch();

        if(opcion !=0)
        {
            if (opcion == -32)
            {
                opcion = getch();
                switch (opcion)
                {
                case (75):      //Crear Usuario. izquierda
                    MUTEXLOCK;
                    selectCrearUsuario(x,y);
                    MUTEXUNLOCK;
                    flag = 1;
                    last_key=75;
                    Sleep(800);
                    break;

                case (77):      //Inicio de sesión. derecha
                    MUTEXLOCK;
                    selectIniciarSesion(x,y);
                    MUTEXUNLOCK;
                    flag = 2;
                    last_key=77;
                    Sleep(800);
                    break;
                }
            }
            else if (opcion == 13 && flag)     // Seleccionar opcion
            {
                return flag;
            }
            else if (opcion == 27)     // Seleccionar opcion
            {
                return -1;
            }
        }
        Sleep(10);
    }
    while (1);
}

void menuInicio(int x, int y)
{
    CLEAN;
    cursorClean(0);
    Sleep(100);
    cuadroMenuInstantaneo(x,y);
    MUTEXLOCK;
    tituloMenu(x,y);
    detallesMenu(x,y);
    MUTEXUNLOCK;
}

void cursorClean(int ver)/// cambia la visualizacion del cursor. Se pasa como parametro 1 para mostrar o 0 para esconder.
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    if (ver == 0)
    {
        cursorInfo.bVisible = FALSE;
    }
    else
    {
        cursorInfo.bVisible = TRUE;
    }
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void cuadroMenuInstantaneo(int x, int y)/// dibuja la interfaz del cuadro de forma instantanea(sin sleeps)
{
    int centrox = x/2 - ANCHO/2;
    int centroy = y/2 - ALTO/2;

    MUTEXLOCK;
    gotoxy(centrox,centroy-1);
    printf("\033[0;37m");
    printf("%c",201);    // ╔
    for (int renglon=0; renglon<ANCHO; renglon++)
    {
        printf("%c",205);   // ═
    }
    printf("%c\n",187);     // ╗


    for (int altura=0; altura<ALTO; altura++)
    {
        gotoxy(centrox,centroy + altura);
        printf("%c",186);// ║
        for (int espacio=0; espacio<ANCHO; espacio++)
        {
            printf(" ");
        }
        printf("%c\n",186); // ║
    }

    gotoxy(centrox,centroy+ALTO);
    printf("%c",200);    // ╚
    for (int renglon=0; renglon<ANCHO; renglon++)
    {
        printf("%c",205);   // ═
    }
    printf("%c\n",188);     // ╝
    MUTEXUNLOCK;
}

void cuadroMenu(int x, int y)/// dibuja la interfaz del cuadro de forma pausada(con sleeps)
{
    int centrox = x/2 - ANCHO/2;
    int centroy = y/2 - ALTO/2;

    gotoxy(centrox,centroy-1);
    printf("\033[0;37m");
    printf("%c",201);    // ╔
    for (int renglon=0; renglon<ANCHO; renglon++)
    {
        printf("%c",205);   // ═
        Sleep(20);
    }
    printf("%c\n",187);     // ╗


    for (int altura=0; altura<ALTO; altura++)
    {
        gotoxy(centrox,centroy + altura);
        printf("%c",186);// ║
        for (int espacio=0; espacio<ANCHO; espacio++)
        {
            printf(" ");
        }
        printf("%c\n",186); // ║
        Sleep(20);
    }

    gotoxy(centrox,centroy+ALTO);
    printf("%c",200);    // ╚
    for (int renglon=0; renglon<ANCHO; renglon++)
    {
        printf("%c",205);   // ═
        Sleep(20);
    }
    printf("%c\n",188);     // ╝
    fflush(stdin);
}

void tituloMenu(int x, int y)/// dibuja el titulo en el centro de la consola
{
    int centrox = x/2-16;
    int centroy = y/2;

    //Auto-mile
    gotoxy(centrox,centroy-8);
    printf("%c%c%c%c%c",218,196,196,196,191);
    gotoxy(centrox,centroy-7);
    printf("%c   %c\n",179,179);
    gotoxy(centrox,centroy-6);
    printf("%c   %c   %c%c%c                %c",179,179,218,197,191,179);
    gotoxy(centrox,centroy-5);
    printf("%c   %c%c  %c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c %c%c%c%c", 179, 179, 179, 179, 179, 195,196,196,191,195,196,196,194,196,196,191, 194, 179, 218,196,196,191);
    gotoxy(centrox,centroy-4);
    printf("%c%c%c%c%c%c  %c%c%c  %c     %c  %c  %c%c%c %c  %c",195,   196,196,   196,180,179,179,179,179,179,179,179,179,179,179, 179, 179);
    gotoxy(centrox,centroy-3);
    printf("%c   %c%c  %c%c%c  %c %c%c%c %c  %c  %c%c%c %c%c%c%c", 179, 179, 179, 179, 179, 179, 179, 196, 196, 196,179,179,179,179,179, 195,196,196,217);
    gotoxy(centrox,centroy-2);
    printf("%c   %c%c  %c%c%c  %c     %c  %c  %c%c%c %c", 179, 179, 179, 179, 179, 179, 179,179,179,179,179,179, 179, 179, 179);
    gotoxy(centrox,centroy-1);
    printf("%c   %c%c%c%c%c%c%c%c%c%c     %c  %c  %c%c%c%c%c%c%c", 179, 179, 192, 196, 196, 217, 179, 192, 196,196, 217,179,179,179,193,192,196, 192,196,196);
}

void selectCrearUsuario(int x,int y)/// pinta la opcion de crear usuario en el menu principal
{
    int centrox = x/2 - 21;
    int centroy = y/2 + 7;

    gotoxy(centrox,centroy);
    printf("\e[7mCrear usuario");
    gotoxy(centrox,centroy+1);
    printf("     (%c)     \e[0m",174);

    gotoxy(centrox+30,centroy);
    printf("Iniciar sesi%cn", 162);
    gotoxy(centrox+30,centroy+1);
    printf("     (%c)      ", 175);
}

void selectIniciarSesion(int x, int y)/// pinta la opcion de crear iniciar sesion en el menu principal
{
    int centrox = x/2 - 21;
    int centroy = y/2 + 7;

    gotoxy(centrox,centroy);
    printf("Crear usuario");
    gotoxy(centrox,centroy+1);
    printf("     (%c)     ",174);

    gotoxy(centrox+30,centroy);
    printf("\e[7mIniciar sesi%cn", 162);
    gotoxy(centrox+30,centroy+1);
    printf("     (%c)      \e[0m", 175);
}

void detallesMenu(int x, int y)/// printea los cuadros de seleccion crear usuario e iniciar sesion cuando empieza el menu principal
{
    int centrox = x/2 - 21;
    int centroy = y/2 + 7;

    gotoxy(centrox,centroy);
    printf("Crear usuario");
    gotoxy(centrox,centroy+1);
    printf("     (%c)     ",174);

    gotoxy(centrox+30,centroy);
    printf("Iniciar sesi%cn", 162);
    gotoxy(centrox+30,centroy+1);
    printf("     (%c)      ", 175);
}

void leerLimite(char *digitos, int max)///
{
    int contador = 0;

    while (1)
    {
        char tecla = getch();

        if (tecla == '\r')
        {
            digitos[contador] = '\0';
            break;
        }

        else if (tecla == '\b' && contador > 0)
        {
            printf("\b \b");
            contador--;
        }

        else if (contador < max && tecla != '\b')
        {
            putchar(tecla);
            digitos[contador] = tecla;
            contador++;
        }
    }
}

void leerLimiteNumeros(char *digitos, int max)
{
    int contador = 0;

    while (1)
    {
        char tecla = getch();

        if (tecla == '\r')
        {
            digitos[contador] = '\0';
            break;
        }

        else if (tecla == '\b' && contador > 0)
        {
            printf("\b \b");
            contador--;
        }

        else if (tecla >= '0' && tecla <= '9' && contador < max)
        {
            putchar(tecla);
            digitos[contador] = tecla;
            contador++;
        }
    }
}

void cuadroEscritura(int x,int y)/// dibuja un cuadro donde nos ubicaremos para escribir. Se le pasa por parametro una constante MAX_CARACTERES para delimitar el alcance del cuadro.
{
    int i;

    gotoxy(x,y);
    printf("%c",218);
    for (i = 0; i<MAX_CARACTERES; i++)
    {
        printf("%c",196);
    }

    printf("%c",191);
    gotoxy(x,y+1);
    printf("%c",179);
    for (i=0; i<MAX_CARACTERES; i++)
    {
        printf(" ");
    }
    printf("%c",179);

    gotoxy(x,y+2);
    printf("%c",192);
    for (i = 0; i<MAX_CARACTERES; i++)
    {
        printf("%c",196);
    }
    printf("%c",217);
}

void textoCuadro(int x, int y, char data[])/// Se ubica en una posicion x,y , escribe lo que se pasa por parametro y dibuja un cuadro abajo para pedir los datos en esa posicion. Gotoxy queda situado en la posicion del cuadro.
{
    MUTEXLOCK;
    cuadroEscritura(x,y);
    gotoxy(x-26,y+1);
    printf("%s", data);
    MUTEXUNLOCK;
}

void escribeCuadro(int x, int y, void (*funcion)(), char texto[], int cant)
{
    MUTEXLOCK;
    do
    {
        cursorClean(1);
        gotoxy(x,y);
        FF;
        funcion(texto,cant);
        cursorClean(0);
        if (!strcmp(texto,""))
        {
            gotoxy(x-3,y+2);
            printf("Debe ingresar los datos solicitados.");
        }
    }
    while (!strcmp(texto,""));
    gotoxy(x-3,y+2);
    printf("                                    ");
    MUTEXUNLOCK;
}

void menuCrearUsuario(int x, int y, int *dni, char contra[])/// ver
{
    int centrox = x/2 - 26;
    int centroy = y/2;
    char auxContra[MAX_CARACTERES], dniUsu[10];
    int pos=0;

    cuadroMenuInstantaneo(x,y);

    do
    {
        printf("\e[?25h");
        MUTEXLOCK;
        gotoxy(centrox,centroy-7);
        printf("M%cximo %i caracteres.", 160, MAX_CARACTERES);
        MUTEXUNLOCK;

        textoCuadro(centrox+22,centroy-5,"DNI de usuario:");
        textoCuadro(centrox+22,centroy-1,"Contrasena:");
        textoCuadro(centrox+22,centroy+3,"Repetir Contrasena:");

        escribeCuadro(centrox+23,centroy-4,leerLimiteNumeros,dniUsu,8);
        (*dni) = strtol(dniUsu,NULL,10);
        escribeCuadro(centrox+23,centroy,leerLimite,contra,MAX_CARACTERES);
        escribeCuadro(centrox+23,centroy+4,leerLimite,auxContra,MAX_CARACTERES);

        if (strcmp(contra,auxContra)!=0)
        {
            MUTEXLOCK;
            gotoxy(centrox-4,centroy+8);
            printf("Las contrase%cas son diferentes. Por favor reintente...", 164);
            MUTEXUNLOCK;
        }
    }
    while(strcmp(contra,auxContra)!=0);

    if (buscarUsuarioArray((*dni),&pos))
    {
        MUTEXLOCK;
        gotoxy(x-4,y+8);
        printf("El usuario ya existe.                                 ");
        gotoxy(x-4,y+9);
        printf("Ingrese sesi%cn para continuar o Reintente con otro DNI.", 162);
        MUTEXUNLOCK;
    }
    else
    {
        guardarDatosUsuario(x,y,(*dni),contra);   /// En arreglo dinámico.
    }
}

void guardarDatosUsuario(int x, int y, char dniusu[], char contrasenia[])/// ver
{
    int centrox = x/2;
    int centroy = y/2;
    Persona per;
    char tel[14];

    cuadroMenuInstantaneo(x,y);

    textoCuadro(centrox-4,centroy-5,"Nombre:");
    textoCuadro(centrox-4,centroy-1,"Telefono:");
    textoCuadro(centrox-4,centroy+3,"Direccion:");

    escribeCuadro(centrox-3,centroy-4,leerLimite,per.nombre,MAX_CARACTERES);
    escribeCuadro(centrox-3,centroy,leerLimiteNumeros,tel,13);
    per.telefono = strtol(tel, NULL, 10);
    escribeCuadro(centrox-3,centroy+4,leerLimite,per.direccion,MAX_CARACTERES);
    per.dni = strtol(dniusu,NULL,10);
    strcpy(per.contra,contrasenia);

    guardarUsuario(per);

    cuadroMenuInstantaneo(x,y);
    MUTEXLOCK;
    gotoxy(centrox-26,centroy-2);
    printf("Usuario guardado satisfactoriamente.");
    gotoxy(centrox-26,centroy+2);
    printf("Ingreses sesi%cn para continuar...", 162);
    MUTEXUNLOCK;
}

int ingresaUsuario(int x, int y) /// ver
{
    int centrox = x/2 - 25;
    int centroy = y/2 + 2;
    char contra[MAX_CARACTERES];
    int intentos = 0, ingreso, dni;

    cuadroMenuInstantaneo(x,y);

    do
    {
        textoCuadro(centrox+22,centroy-5,"DNI de usuario:");
        textoCuadro(centrox+22,centroy-1,"Contrasena:");

        escribeCuadro(centrox+23,centroy-4,leerLimiteNumeros,contra,8);
        dni = strtol(contra, NULL, 10);
        escribeCuadro(centrox+23,centroy,leerLimite,contra,20);

        ingreso = entraUsuario(dni,contra);
        switch (ingreso)
        {
        case (0):
            MUTEXLOCK;
            gotoxy(centrox-8,centroy+6);
            printf("El usuario no existe. Intente nuevamente.");
            MUTEXUNLOCK;
            break;

        case (1):
            intentos++;
            MUTEXLOCK;
            gotoxy(centrox-8,centroy+6);
            printf("Contrase%ca incorrecta. Intente nuevamente.", 164);
            MUTEXUNLOCK;
            break;

        default:
            MUTEXLOCK;
            gotoxy(centrox-8,centroy+6);
            printf("Ingresando a su perfil...", 164);
            Sleep(2000);
            MUTEXUNLOCK;
            break;
        }
    }
    while(intentos < 3 && ingreso != 2);

    return ingreso;
}



///menu para modificar un vehiculo por dato
void modificarVehiculo()
{

    Patente patBusqueda;

    int pos = -1;

    printf("\nIngrese una patente del vehiculo a modificar:");
    cargaPatente(&patBusqueda);

    if(buscarPatenteArr(patBusqueda, &pos) == 1)
    {
        int opMenu = 0;
        char opSalida, confirmacion;
        Vehiculo auxVehiculo;    //Se trabaja sobre un auxiliar para que al finalizar el menu, se puedan confirmar los cambios

        copiaVehiEnAux(&auxVehiculo, pos);

        do
        {
            mostrarVehiculo(auxVehiculo);
            printf("\n");
            printf("\n1-  Modificar la MARCA del vehiculo.");
            printf("\n2-  Modificar el MODELO del vehiculo.");
            printf("\n3-  Modificar el ANIO del vehiculo.");
            printf("\n4-  Modificar el KILOMETRAJE del vehiculo.");
            printf("\n5-  Modificar el PRECIO DE ALQUILER DIARIO del vehiculo.");
            printf("\n6-  Modificar el TIPO de vehiculo.");
            printf("\n7-  Modificar la DISPONIBILIDAD del vehiculo.");
            printf("\n> ");
            FF;
            scanf("%i", &opMenu);


            switch(opMenu)
            {
            case (1):
                cargaMarca(&(auxVehiculo.marca));
                break;

            case (2):
                cargaModelo(&(auxVehiculo.modelo));
                break;

            case (3):
                cargaAnio(&(auxVehiculo.anio));
                break;

            case (4):
                cargaKms(&(auxVehiculo.kms));
                break;

            case (5):
                cargaPrecioDiario(&(auxVehiculo.precioDeAlquilerDiario));
                break;

            case (6):
                cargaTipo(&(auxVehiculo.tipoVehiculo));
                break;

            case (7):
                invertirDisponibilidad(&(auxVehiculo.disponibilidad));
                break;
            }

            printf("\nIngrese ESC para finalizar la modificacion...\n");
            opSalida = getch();
            CLEAN;
        }
        while (opSalida != ESC);

        printf("\nDesea guardar los cambios realizados? (Presione 's' para confirmar.)");
        FF;
        scanf("%c", &confirmacion);

        //CONFIRMACION PARA CAMBIAR DATOS DEL ARREGLO DINAMICO
        confirmacion = tolower(confirmacion); //Convierto el char a minuscula para asegurarme que entra el IF

        if(confirmacion == 's')
        {
            copiaVehiModificado(auxVehiculo, pos); //Reemplazar datos del auxVehiculo con el del arreglo dinamico en la posicion que se encuentra
        }

        //MODIFICAR EL VEHICULO EN EL ARCHIVO

            modificaVehiArch(patBusqueda, pos);

    }
}



void menuOpcionesDeAdmin(int x,int y, int dni)
{
    //menuGestionVehiAdmin
    //menuGestionPersAdmin
    //menuGestionAlqAdmin
}

void menuOpcionesDeUsuario(int x,int y, int dni)
{
    //Ver Vehículos.
    //Alquilar un Vehículo.
    //Modificar Usuario Propio.
    //Darse de baja.
}

void menuGestionVehiAdmin(int x, int y)
{
    //Ver Vehículos.
    //Agregar Vehículo.
    //Modificar Vehículos.
    //Dar de baja un Vehículo.
}

void menuGestionPersAdmin(int x, int y)
{
    //Modificar Usuario Propio.
    //Ver Usuarios.
    //Modificar Usuarios.
    //Dar de baja un Usuario.
}

void menuGestionAlqAdmin(int x, int y)
{
    //Ver Dominions veh.
    //Alquilar
    //Modificar alquiler.
    //ver estadisticas alquiler
}

void menuGestionCliente(int x, int y)
{
    //funciones de visualizacion
}








///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///











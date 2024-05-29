#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "menu.h"
#include "FuncionesHilosPMenu.h"

#define MAX 100
#define COMPROBAR if(archi==NULL){printf("El archivo no puede ser abierto.");}
#define ARCHIVO "datos_binarios.DAT"
#define FF fflush(stdin)
#define ESC 27
#define CLEAN system("cls")

typedef struct
{
    char letras[3];
    char numeros[3];
} Patente;

typedef struct
{
    Patente patente;
    char marca[20];
    char modelo[20];
    int anio;
    int kms;
    float precioDeAlquilerDiario;
    char tipoVehiculo[20]; // 1-Auto, 2-Camioneta, 3-Utilitario
    int disponibilidad; // 1-disponible, 0-no disponible
} Vehiculo;

typedef struct
{
    int dni;
    char nombre[50];
    char telefono[20];
    char direccion[100];
    char rol[20]; // Cliente o User del Sistema
} Persona;

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct
{
    Fecha fechaInicio;
    Fecha fechaFin;
    Patente vehiculo;
    int dniCliente;
    float precioTotal;
} Alquiler;


int main()
{
    const char* archivo2MP3 = "route66.wav";
    int ABM, dato, a, b;
    char op;
    int ancho;
    int alto;
    char opt;

    pthread_t hiloManejando;
    pthread_t hiloAux;
    pthread_t limpiarTeclado;
    pthread_t keyCapture;

    pthread_create(&keyCapture,NULL,key_listener,NULL);
    pthread_join(&keyCapture,NULL);

    intro(&ancho,&alto);
    Medidas medidas;

    medidas.alto = alto;
    medidas.ancho = ancho;

    Sleep(1000);

//    pthread_create(&limpiarTeclado,NULL,clean_kbhit,NULL);
    pthread_create(&hiloAux,NULL,key_thread,&medidas);
    pthread_create(&hiloManejando,NULL,funcionHiloCoche,&medidas);

    PlaySoundA(archivo2MP3,NULL,SND_ASYNC | SND_LOOP);

    mainMenu(ancho ,alto-5);

    do
    {
        printf("\nIngrese ESC para finalizar...\n");
        op = getch();
    }while (op != ESC);


}

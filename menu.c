#include "menu.h"
#include "gotoxy.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#include <pthread.h>

#define ANCHO 80
#define ALTO 25
#define CLEAN system("cls")
#define PAUSE system("pause")
#define FF fflush(stdin)
#define IZQ 75
#define DER 77
#define MAX_CARACTERES 30

int mainMenu(int anchoConsola, int altoConsola)
{
    char dni[MAX_CARACTERES], contra[MAX_CARACTERES], opcion;
    int flag, intentos = 0, ingreso;

    do
    {
        int flag = inicio(anchoConsola, altoConsola);
        if (flag == 1)
        {
            do
            {
                crearUsuario(anchoConsola, altoConsola, dni, contra);

                //if (existeUsuario(dni))
                {
                    gotoxy(anchoConsola/2-30,altoConsola/2+8);
                    printf("El usuario ya existe.                                 ");
                    gotoxy(anchoConsola/2-30,altoConsola/2+9);
                    printf("Ingrese sesi%cn para continuar o Reintente con otro DNI.", 162);

                    gotoxy(anchoConsola/2-34,altoConsola/2-10);
                    printf("ESCAPE para volver hacia atr%cs / C para continuar...",160);
                    opcion = getch();
                    if (opcion == 27)
                    {
                        flag = 0;
                    }
                    else
                    {
                        flag = 1;
                    }
                }
                //else
                {
                    //guardarDatosUsuario(dni);   /// En arreglo dinámico.
                    printf("Usuario guardado satisfactoriamente.");
                    printf("Ingreses sesi%cn para continuar...", 162);

                    gotoxy(anchoConsola/2-34,altoConsola/2-10);
                    printf("ESCAPE para volver hacia atr%cs / C para continuar...",160);
                }
            }while (flag == 1);
        }
        else if (flag == 2)
        {
            //ingreso = ingresaUsuario(dni, contra);
            if (!ingreso)
            {
                printf("El usuario no existe. Intente nuevamente.");
            }
            else if (ingreso == 1)
            {
                intentos++;
                printf("Contrase%ca incorrecta. Intente nuevamente.", 164);
            }
            else if (ingreso == 2)
            {
                //CONTINUAR.
            }
        }
    }while (flag && intentos<3);

return 1;
}

int inicio(int x, int y)
{
    int flag = 0;
    char opcion;
    menuInicio(x,y);
    do
    {
        opcion = getch();

        if (opcion == -32)
        {
            opcion = getch();
            switch (opcion)
            {
            case (75):      //Crear Usuario.
                selectCrearUsuario(x,y);
                flag = 1;
                break;

            case (77):      //Inicio de sesión.
                selectIniciarSesion(x,y);
                flag = 2;
                break;
            }
        }
        else if (opcion == 0)
        {
            opcion = getch();
        }

        else if (opcion == 13 && flag)     // Seleccionar opcion
        {
            return flag;
        }
    }while (opcion!=13 || !flag);
}

void menuInicio(int x, int y)
{
    CLEAN;
    cursosClean(0);
    cuadroMenu(x,y);
    tituloMenu(x,y);
    detallesMenu(x,y);
}

void cursosClean(int ver)
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

void cuadroMenu(int x, int y)
{
    int centrox = x/2 - ANCHO/2;
    int centroy = y/2 - ALTO/2;

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
}

void tituloMenu(int x, int y)
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
    printf("%c   %c%c  %c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c %c%c%c%c", 179, 179, 179, 179, 179, 195,196,196,191         ,195,196,196,194,196,196,191, 194, 179, 218,196,196,191);
    gotoxy(centrox,centroy-4);
    printf("%c%c%c%c%c%c  %c%c%c  %c     %c  %c  %c%c%c %c  %c",195,   196,196,   196,180,179,179,179,179,179             ,179,179,179,179,179, 179, 179);
    gotoxy(centrox,centroy-3);
    printf("%c   %c%c  %c%c%c  %c %c%c%c %c  %c  %c%c%c %c%c%c%c", 179, 179, 179, 179, 179, 179, 179, 196, 196, 196         ,179,179,179,179,179, 195,196,196,217);
    gotoxy(centrox,centroy-2);
    printf("%c   %c%c  %c%c%c  %c     %c  %c  %c%c%c %c", 179, 179, 179, 179, 179, 179, 179         ,179,179,179,179,179, 179, 179, 179);
    gotoxy(centrox,centroy-1);
    printf("%c   %c%c%c%c%c%c%c%c%c%c     %c  %c  %c%c%c%c%c%c%c", 179, 179, 192, 196, 196, 217, 179, 192, 196,196, 217         ,179,179,179,193,192,196, 192,196,196);
}

void selectCrearUsuario(x,y)
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

void selectIniciarSesion(x,y)
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

void detallesMenu(int x, int y)
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

void leerLimite(char *digitos, int max)
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

        else if (contador < max)
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

void crearUsuario(int x, int y, char dni[], char contra[])
{
    int centrox = x/2 - 26;
    int centroy = y/2;
    char auxContra[20];
    cuadroMenu(x,y);

    do
    {
        printf("\e[?25h");
        gotoxy(centrox,centroy-7);
        printf("M%cximo %i caracteres.", 160, MAX_CARACTERES);

        cuadroEscritura(centrox+22,centroy-5);
        gotoxy(centrox,centroy-4);
        printf("DNI de usuario:");

        cuadroEscritura(centrox+22,centroy-1);
        gotoxy(centrox,centroy);
        printf("Contrase%ca:",164);

        cuadroEscritura(centrox+22,centroy+3);
        gotoxy(centrox,centroy+4);
        printf("Repetir Contrase%ca:",164);

        cursosClean(1);

        gotoxy(centrox+23,centroy-4);
        FF;
        leerLimiteNumeros(dni,8);

        gotoxy(centrox+23,centroy);
        FF;
        leerLimite(contra,20);

        gotoxy(centrox+23,centroy+4);
        FF;
        leerLimite(auxContra,20);

        if (strcmp(contra,auxContra)!=0)
        {
            gotoxy(centrox-4,centroy+8);
            printf("Las contrase%cas son diferentes. Por favor reintente...", 164);
        }
    }while(strcmp(contra,auxContra)!=0);
}

void cuadroEscritura(int x,int y)
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

void ingresaUsuario(int x, int y, char dni[], char contra[])
{
    int centrox = x/2 - 21;
    int centroy = y/2 +7;

    //if (existeUsuario(dni))
    {

    }
}

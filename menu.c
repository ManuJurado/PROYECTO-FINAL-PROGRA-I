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
#include "FuncionesHilosPMenu.h"
#include "GestionPersonas.h"

#define ANCHO 80
#define ALTO 25
#define CLEAN system("cls")
#define PAUSE system("pause")
#define FF fflush(stdin)
#define IZQ 75
#define DER 77
#define MAX_CARACTERES 30

int need_selectCrearUsuario = 0;

int mainMenu(int anchoConsola, int altoConsola)
{
    char dni[MAX_CARACTERES], contra[MAX_CARACTERES], opcion;
    int flag, intentos;

    do
    {
        menuInicio(anchoConsola,altoConsola);
        flag = inicio(anchoConsola, altoConsola);

        if (flag == 1)
        {
            do
            {
                crearUsuario(anchoConsola, altoConsola, dni, contra);

                if (/*existeUsuario(dni)*/0)
                {
                    MUTEXLOCK;
                    gotoxy(anchoConsola/2-30,altoConsola/2+8);
                    printf("El usuario ya existe.                                 ");
                    gotoxy(anchoConsola/2-30,altoConsola/2+9);
                    printf("Ingrese sesi%cn para continuar o Reintente con otro DNI.", 162);
                    gotoxy(anchoConsola/2-33,altoConsola/2-10);
                    printf("ESCAPE para volver hacia atr%cs / C para continuar...",160);
                    MUTEXUNLOCK;

                    opcion = getch();
                    flag = (opcion == 27) ? 0 : 1;
                }
                else
                {
                    MUTEXLOCK;
                    guardarDatosUsuario(anchoConsola,altoConsola,dni,contra);   /// En arreglo dinámico.
                    gotoxy(anchoConsola/2-33,altoConsola/2-10);
                    printf("ESCAPE para volver hacia atr%cs / C para crear otro usuario...",160);
                    MUTEXUNLOCK;

                    opcion = getch();
                    flag = (opcion == 27) ? 0 : 1;
                }
            }
            while (flag == 1);
        }
        else if (flag == 2)
        {
            intentos = 0;
            do
            {
                flag = ingresaUsuario(anchoConsola,altoConsola,&intentos);
            }
            while (flag != 2 && intentos<3);

            if (flag == 1)
            {
                MUTEXLOCK;
                cuadroMenuInstantaneo(anchoConsola,altoConsola);
                gotoxy(anchoConsola/2-33,altoConsola/2-9);
                printf("Haz superado la cantidad m%cxima de intentos.",160);
                gotoxy(anchoConsola/2-33,altoConsola/2-7);
                printf("Presione cualquier tecla para salir al men%c principal...",163);
                MUTEXUNLOCK;

                opcion = getch();
            }
            else  //flag = 2  ->  Ingresa sesión.
            {
                if (/*tipoUsuario(dni)*/1)
                    menuOpcionesDeAdmin();
                else
                    menuOpcionesDeUsuario();

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
                    Sleep(1100);
                    break;

                case (77):      //Inicio de sesión. derecha
                    MUTEXLOCK;
                    selectIniciarSesion(x,y);
                    MUTEXUNLOCK;
                    flag = 2;
                    last_key=77;
                    Sleep(1100);
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
    cursosClean(0);
    Sleep(100);
    MUTEXLOCK;
    cuadroMenuInstantaneo(x,y);
    tituloMenu(x,y);
    detallesMenu(x,y);
    MUTEXUNLOCK;
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

void cuadroMenuInstantaneo(int x, int y)
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

void selectCrearUsuario(int x,int y)
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

void selectIniciarSesion(int x, int y)
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

void textoCuadro(int x, int y, char data[])
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
        cursosClean(1);
        gotoxy(x,y);
        FF;
        funcion(texto,cant);
        cursosClean(0);
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

void crearUsuario(int x, int y, char dni[], char contra[])
{
    int centrox = x/2 - 26;
    int centroy = y/2;
    char auxContra[MAX_CARACTERES];

    MUTEXLOCK;
    cuadroMenuInstantaneo(x,y);
    MUTEXUNLOCK;

    do
    {
        printf("\e[?25h");
        MUTEXLOCK;
        gotoxy(centrox,centroy-7);
        MUTEXUNLOCK;
        printf("M%cximo %i caracteres.", 160, MAX_CARACTERES);

        textoCuadro(centrox+22,centroy-5,"DNI de usuario:");
        textoCuadro(centrox+22,centroy-1,"Contrasena:");
        textoCuadro(centrox+22,centroy+3,"Repetir Contrasena:");

        escribeCuadro(centrox+23,centroy-4,leerLimiteNumeros,dni,8);
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
}

void guardarDatosUsuario(int x, int y, char dniusu[], char contrasenia[])
{
    int centrox = x/2;
    int centroy = y/2;
    Persona per;

    cuadroMenuInstantaneo(x,y);

    MUTEXUNLOCK;
    textoCuadro(centrox-4,centroy-5,"Nombre:");
    textoCuadro(centrox-4,centroy-1,"Telefono:");
    textoCuadro(centrox-4,centroy+3,"Direccion:");

    escribeCuadro(centrox-3,centroy-4,leerLimite,per.nombre,MAX_CARACTERES);
    escribeCuadro(centrox-3,centroy,leerLimiteNumeros,per.telefono,13);
    escribeCuadro(centrox-3,centroy+4,leerLimite,per.direccion,MAX_CARACTERES);
    per.dni = strtol(dniusu,NULL,10);
    strcpy(per.contra,contrasenia);

    //guardarUsuario(per);

    MUTEXLOCK;
    cuadroMenuInstantaneo(x,y);
    gotoxy(centrox-26,centroy-2);
    printf("Usuario guardado satisfactoriamente.");
    gotoxy(centrox-26,centroy+2);
    printf("Ingreses sesi%cn para continuar...", 162);
    MUTEXUNLOCK;
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

int ingresaUsuario(int x, int y, int *intentos)
{
    int centrox = x/2 - 25;
    int centroy = y/2 + 2;
    char dni[MAX_CARACTERES], contra[MAX_CARACTERES];
    int ingreso = 2; //borrar luego de tener la funcion "registraUsuario"

    MUTEXLOCK;
    cuadroMenuInstantaneo(x,y);
    MUTEXUNLOCK;

    do
    {
        textoCuadro(centrox+22,centroy-5,"DNI de usuario:");
        textoCuadro(centrox+22,centroy-1,"Contrasena:");

        escribeCuadro(centrox+23,centroy-4,leerLimiteNumeros,dni,8);
        escribeCuadro(centrox+23,centroy,leerLimite,contra,20);

        //int ingreso = registraUsuario(dni,contra);
        switch (ingreso)
        {
        case (0):
            MUTEXLOCK;
            gotoxy(centrox-8,centroy+6);
            printf("El usuario no existe. Intente nuevamente.");
            MUTEXUNLOCK;
            break;

        case (1):
            (*intentos)++;
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
    while(*intentos < 3 && ingreso != 2);

    return ingreso;
}

void menuOpcionesDeAdmin(int x,int y, char dni[])
{
    //Ver Vehículos.
    //Agregar Vehículo.
    //Modificar Vehículos.
    //Dar de baja un Vehículo.

    //Modificar Usuario Propio.
    //Ver Usuarios.
    //Modificar Usuarios.
    //Dar de baja un Usuario.
}

void menuOpcionesDeUsuario(int x,int y, char dni[])
{
    //Ver Vehículos.
    //Alquilar un Vehículo.

    //Modificar Usuario Propio.
    //Darse de baja.
}

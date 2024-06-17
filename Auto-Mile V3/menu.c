#include "menu.h"

volatile char global_key = 0;
volatile char last_key;


///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///

/// Funciones auxiliares para los menues///

void limpiarBufferEntrada()
{
    while (kbhit())
        getch(); // Limpiar buffer de entrada de teclado
}

void leerLimite(char *digitos, int max)///
{
    int contador = 0;

    while (1)
    {
        fflush(stdin);
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

void leerLimiteNumerosYLetras(char *digitos, int max)
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
        else if ((isalnum(tecla) || tecla == ' ') && contador < max - 1)     // Permitir alfanuméricos y espacio, y verificar límite
        {
            putchar(tecla);
            digitos[contador] = tecla;
            contador++;
        }
    }
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

void cuadroEscritura(int x, int y, int largo)/// dibuja un cuadro donde nos ubicaremos para escribir. Se le pasa por parametro una constante MAX_CARACTERES para delimitar el alcance del cuadro.
{
    int i;

    gotoxy(x,y);
    printf("%c",218);
    for (i = 0; i<largo; i++)
    {
        printf("%c",196);
    }

    printf("%c",191);
    gotoxy(x,y+1);
    printf("%c",179);
    for (i=0; i<largo; i++)
    {
        printf(" ");
    }
    printf("%c",179);

    gotoxy(x,y+2);
    printf("%c",192);
    for (i = 0; i<largo; i++)
    {
        printf("%c",196);
    }
    printf("%c",217);
}

void textoCuadro(int x, int y, int l, char data[])/// Se ubica en una posicion x,y , escribe lo que se pasa por parametro y dibuja un cuadro abajo para pedir los datos en esa posicion. Gotoxy queda situado en la posicion del cuadro.
{
    MUTEXLOCK;
    cuadroEscritura(x,y,l);
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

///-----------------------------------------------------------------------------------------------------------------------------fin funciones auxiliares para menues///









/// Funciones de menu principales ----------------------------------------------------------------------------------------------------------------------------------///

int mainMenu(int anchoConsola, int altoConsola)
{
    char contra[MAX_CARACTERES], opcion, op;
    int flag, dni;
    do
    {
        menuInicio(anchoConsola,altoConsola);
        flag = inicio(anchoConsola, altoConsola);
        leerArchPersonas();

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
                flag = (opcion == 67 || opcion == 99) ? 1 : 0;
            }
            while (flag == 1);
        }
        else if (flag == 2)
        {
            flag = ingresaUsuario(anchoConsola,altoConsola,&dni);

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
                if (tipoUsuario(dni))
                {
                    cuadroMenuInstantaneo(anchoConsola,altoConsola);
                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2),(medidasConsola.alto/2));
                    printf("Ingresando al menu Administrador...");
                    Sleep(1000);
                    MUTEXUNLOCK;
                    cuadroMenuInstantaneo(anchoConsola,altoConsola);
                    menuOpcionesDeAdmin(anchoConsola,altoConsola,buscarUsuarioArray(dni,&flag));
                }
                else
                {
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

        textoCuadro(centrox+22,centroy-5,MAX_CARACTERES,"DNI de usuario:");
        textoCuadro(centrox+22,centroy-1,MAX_CARACTERES,"Contrasena:");
        textoCuadro(centrox+22,centroy+3,MAX_CARACTERES,"Repetir Contrasena:");

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

    if (buscarUsuarioArray((*dni),&pos).dni)
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

void guardarDatosUsuario(int x, int y, int dniusu, char contrasenia[])/// ver
{
    int centrox = x/2;
    int centroy = y/2;
    Persona per;
    char tel[14];

    cuadroMenuInstantaneo(x,y);

    textoCuadro(centrox-4,centroy-6,35,"Nombre:");
    textoCuadro(centrox-4,centroy-2,35,"Telefono:");

    MUTEXLOCK;
    cuadroEscritura(centrox-34,centroy+4,68);
    gotoxy(centrox-30,centroy+3);
    printf("Direcci%cn:", 162);
    MUTEXUNLOCK;

    escribeCuadro(centrox-3,centroy-5,leerLimite,per.nombre,35);
    escribeCuadro(centrox-3,centroy-1,leerLimiteNumeros,tel,13);
    escribeCuadro(centrox-33,centroy+5,leerLimite,per.direccion,68);

    per.telefono = strtol(tel, NULL, 10);
    per.dni = dniusu;
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

int ingresaUsuario(int x, int y, int *dni) /// ver
{
    int centrox = x/2 - 25;
    int centroy = y/2 + 2;
    char contra[MAX_CARACTERES];
    int intentos = 0, ingreso;

    cuadroMenuInstantaneo(x,y);

    do
    {
        textoCuadro(centrox+22,centroy-5,MAX_CARACTERES,"DNI de usuario:");
        textoCuadro(centrox+22,centroy-1,MAX_CARACTERES,"Contrasena:");

        escribeCuadro(centrox+23,centroy-4,leerLimiteNumeros,contra,8);
        (*dni) = strtol(contra, NULL, 10);
        escribeCuadro(centrox+23,centroy,leerLimite,contra,20);

        ingreso = entraUsuario((*dni),contra);
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
            MUTEXUNLOCK;
            break;
        }
    }
    while(intentos < 3 && ingreso != 2);

    if(intentos == 3)
    {
        gotoxy(centrox-8,centroy+6);
        printf("maxima cantidad de intentos alcanzada. Volviendo al menu principal...");
        return mainMenu(x,y);
    }
    else
    {
        return ingreso;
    }
}

///--------------------------------------------------------------------------------------------------------------------------- fin funciones principales para menues///





int QR [31][31] =
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,A,A,A,A,A,A,A,0,A,0,0,0,0,A,0,A,A,0,0,0,A,0,A,A,A,A,A,A,A,0},
    {0,A,0,0,0,0,0,A,0,A,0,0,A,A,0,A,0,A,A,0,A,A,0,A,0,0,0,0,0,A,0},
    {0,A,0,A,A,A,0,A,0,A,A,0,0,A,0,A,0,0,0,0,A,A,0,A,0,A,A,A,0,A,0},
    {0,A,0,A,A,A,0,A,0,A,A,A,0,A,0,A,0,0,0,A,0,0,0,A,0,A,A,A,0,A,0},
    {0,A,0,A,A,A,0,A,0,0,A,A,0,A,A,A,0,0,0,0,0,0,0,A,0,A,A,A,0,A,0},
    {0,A,0,0,0,0,0,A,0,A,A,A,0,0,0,0,0,A,A,0,0,A,0,A,0,0,0,0,0,A,0},
    {0,A,A,A,A,A,A,A,0,A,0,A,0,A,0,A,0,A,0,A,0,A,0,A,A,A,A,A,A,A,0},
    {0,0,0,0,0,0,0,0,0,0,0,A,A,0,0,A,A,0,0,0,A,0,0,0,0,0,0,0,0,0,0},
    {0,A,A,0,0,A,A,A,0,0,0,A,0,A,0,0,0,0,0,0,A,0,0,0,A,0,A,A,A,A,0},
    {0,A,0,A,A,A,A,0,0,A,0,0,0,0,A,0,0,A,0,0,A,0,A,A,A,A,0,A,0,0,0},
    {0,0,A,A,A,0,0,A,A,0,A,A,0,0,A,0,A,A,0,0,0,0,A,A,0,A,A,A,0,A,0},
    {0,A,0,0,A,A,A,0,0,A,A,0,0,A,A,A,0,0,0,0,A,A,A,0,0,0,A,0,0,0,0},
    {0,0,0,A,0,A,0,A,0,0,0,0,A,0,A,A,0,A,A,0,A,A,A,A,A,0,A,A,A,0,0},
    {0,0,A,0,A,A,0,0,A,0,A,A,0,A,A,0,0,A,0,0,0,A,0,A,A,A,0,A,0,0,0},
    {0,0,0,A,A,0,A,A,A,A,A,A,A,A,0,A,0,0,0,A,0,0,0,A,0,A,A,A,A,0,0},
    {0,0,0,A,0,0,A,0,0,0,A,A,A,0,0,A,0,A,A,A,A,A,0,0,0,0,0,0,A,0,0},
    {0,0,0,0,0,0,0,A,A,0,0,A,0,A,0,0,0,0,A,0,A,0,0,A,A,0,A,A,A,0,0},
    {0,A,0,A,A,A,A,0,A,A,0,0,0,0,A,0,A,A,0,0,A,0,A,0,A,A,0,A,A,A,0},
    {0,0,0,0,0,A,0,A,0,A,0,0,0,0,A,A,A,0,0,A,0,A,0,A,0,A,A,A,A,0,0},
    {0,0,0,A,0,A,0,0,0,0,A,0,0,A,0,0,0,0,A,0,A,A,A,0,0,0,0,0,A,0,0},
    {0,A,A,0,A,A,0,A,A,0,A,A,A,A,0,0,0,A,0,A,A,A,A,A,A,A,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,A,0,0,0,A,A,0,A,A,0,0,A,A,0,0,0,A,A,A,0,0,0},
    {0,A,A,A,A,A,A,A,0,0,0,A,A,0,0,A,0,0,0,A,0,A,0,A,0,A,A,A,0,A,0},
    {0,A,0,0,0,0,0,A,0,A,A,A,A,0,A,A,0,A,A,A,A,A,0,0,0,A,0,A,A,0,0},
    {0,A,0,A,A,A,0,A,0,A,A,A,0,0,A,A,0,0,0,0,A,A,A,A,A,A,A,0,0,A,0},
    {0,A,0,A,A,A,0,A,0,0,A,0,0,A,A,A,0,0,0,A,0,0,A,A,A,0,A,A,A,0,0},
    {0,A,0,A,A,A,0,A,0,0,A,0,A,A,A,A,0,A,0,A,A,0,0,0,0,A,0,A,A,A,0},
    {0,A,0,0,0,0,0,A,0,A,0,0,A,A,0,0,0,0,A,0,A,0,0,A,A,A,A,A,0,0,0},
    {0,A,A,A,A,A,A,A,0,A,0,0,0,0,0,A,0,A,A,A,0,A,A,A,0,A,0,0,A,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};






/// Funciones de Administrador -------------------------------------------------------------------------------------------------------------------------------------///

void menuOpcionesDeAdmin(int x,int y, Persona per)
{
    char op;

    int inicioCuadroX = (x/2) - (ANCHO/2) + 6;
    int inicioCuadroY = (y/2);

    do
    {
        cuadroMenuInstantaneo(x,y);
        MUTEXLOCK;
        gotoxy(inicioCuadroX,inicioCuadroY-4);
        printf("Ingrese el menu al cual quiere ingresar:");
        gotoxy(inicioCuadroX,inicioCuadroY-2);
        printf("1-  Gestion de personas.");
        gotoxy(inicioCuadroX,inicioCuadroY);
        printf("2-  Gestion de vehiculos.");
        gotoxy(inicioCuadroX,inicioCuadroY+2);
        printf("3-  Gestion de alquileres.");
        MUTEXUNLOCK;
        limpiarBufferEntrada();
        op = getch();

        switch(op)
        {
            case '1':
                menuGestionPersAdmin(x,y, per);
            break;

            case '2':
                menuGestionVehiAdmin(x,y);
            break;

            case '3':
                menuGestionAlqAdmin(x,y);
            break;
        }
    }
    while (op != ESC);
}

void menuModificarUsuario(int x, int y, Persona per)
{
    char op, aceptar[8];

    int inicioCuadroX = (x/2) - (ANCHO/2) + 6;
    int inicioCuadroY = (y/2);

    do
    {
        cuadroMenuInstantaneo(x,y);
        //mostrarPersona();
        MUTEXLOCK;
        gotoxy(inicioCuadroX,inicioCuadroY-8);
        printf("Ingrese ESC para volver para atrás");
        gotoxy(inicioCuadroX,inicioCuadroY-1);
        printf("Ingrese la opci%cn a modificar:", 162);
        gotoxy(inicioCuadroX,inicioCuadroY+1);
        printf("1-  Modificar el nombre.");
        gotoxy(inicioCuadroX,inicioCuadroY+2);
        printf("2-  Modificar la direccion.");
        gotoxy(inicioCuadroX,inicioCuadroY+3);
        printf("3-  Modificar el telefono.");
        gotoxy(inicioCuadroX,inicioCuadroY+4);
        printf("4-  Darse de baja.");
        MUTEXUNLOCK;



        limpiarBufferEntrada();
        op = getch();
        cuadroMenuInstantaneo(x,y);

        switch(op)
        {
        case '1':
            textoCuadro(inicioCuadroX+25,inicioCuadroY-1,35,"Nuevo Nombre:");
            escribeCuadro(inicioCuadroX+26,inicioCuadroY,leerLimite,per.nombre,35);
            break;

        case '2':
            MUTEXLOCK;
            cuadroEscritura(inicioCuadroX,inicioCuadroY-1,68);
            gotoxy(inicioCuadroX,inicioCuadroY-2);
            printf("Direcci%cn:", 162);
            MUTEXUNLOCK;
            escribeCuadro(inicioCuadroX+1,inicioCuadroY,leerLimite,per.direccion,68);
            break;

        case '3':
            textoCuadro(inicioCuadroX+25,inicioCuadroY-1,35,"Nuevo Telefono:");
            escribeCuadro(inicioCuadroX+26,inicioCuadroY,leerLimiteNumeros,per.telefono,13);
            break;

        case '4':
            gotoxy(inicioCuadroX,inicioCuadroY-4);
            printf("Est%c seguro que desea darse de baja?", 160);
            gotoxy(inicioCuadroX,inicioCuadroY-2);
            printf("Escriba \"ACEPTAR\" para continuar con la baja.");
            cuadroEscritura(inicioCuadroX,inicioCuadroY+1,7);
            escribeCuadro(inicioCuadroX+1,inicioCuadroY+2,leerLimite,aceptar,7);
            if (aceptar == "aceptar" || aceptar == "ACEPTAR" || aceptar == "Aceptar" )
            per.baja = 0;
            break;
        }

    }
    while (op != ESC);

    modificarUsuario(per);
}

void menuGestionPersAdmin(int x, int y, Persona per)
{
    char op;
    int pos;

    int inicioCuadroX = (x/2) - (ANCHO/2) + 6;
    int inicioCuadroY = (y/2);

    do
    {
        cuadroMenuInstantaneo(x,y);
        MUTEXLOCK;
        gotoxy(inicioCuadroX,inicioCuadroY-4);
        printf("Ingrese el menu al cual quiere ingresar:");
        gotoxy(inicioCuadroX,inicioCuadroY-2);
        printf("1-  Modificar Usuario Propio.");
        gotoxy(inicioCuadroX,inicioCuadroY);
        printf("2-  Ver lista de usuarios.");
        MUTEXUNLOCK;
        limpiarBufferEntrada();
        op = getch();

        if (op == '1')
        {
            menuModificarUsuario(x,y,buscarUsuarioArray(per.dni,&pos));
        }
        else if (op == '2')
        {
            //listarUsuarios(x,y);
        }
    }
    while (op != ESC);
}

void modificarVehiculo(int x, int y)
{
    Patente patBusqueda;

    int pos = -1;

    cuadroMenuInstantaneo(x,y);
    MUTEXLOCK;
    gotoxy((x/2-ANCHO/2)+1,(y/2-ALTO/2)-5);
    printf("Ingrese una patente del vehiculo a modificar:");
    MUTEXUNLOCK;
    cargaPatente(&patBusqueda);

    if(buscarPatenteArr(patBusqueda, &pos) == 1)
    {
        char opMenu;
        char confirmacion;
        Vehiculo auxVehiculo;    //Se trabaja sobre un auxiliar para que al finalizar el menu, se puedan confirmar los cambios
        int inicioCuadroX = (x/2) - (ANCHO/2) + 6;
        int inicioCuadroY = (y/2);

        copiaVehiEnAux(&auxVehiculo, pos);
        cuadroMenuInstantaneo(x,y);
        mostrarVehiculo(auxVehiculo);
        Sleep(2000);

        do
        {
            cuadroMenuInstantaneo(x,y);
            MUTEXLOCK;
            gotoxy(inicioCuadroX,inicioCuadroY-2);
            printf("1-  Modificar la MARCA del vehiculo.");
            gotoxy(inicioCuadroX,inicioCuadroY);
            printf("2-  Modificar el MODELO del vehiculo.");
            gotoxy(inicioCuadroX,inicioCuadroY+2);
            printf("3-  Modificar el ANIO del vehiculo.");
            gotoxy(inicioCuadroX,inicioCuadroY+4);
            printf("4-  Modificar el KILOMETRAJE del vehiculo.");
            gotoxy(inicioCuadroX+1,inicioCuadroY+6);
            printf("5-  Modificar el PRECIO DE ALQUILER DIARIO del vehiculo.");
            gotoxy(inicioCuadroX,inicioCuadroY+8);
            printf("6-  Modificar el TIPO de vehiculo.");
            gotoxy(inicioCuadroX,inicioCuadroY+10);
            printf("7-  Modificar la DISPONIBILIDAD del vehiculo.");
            gotoxy(inicioCuadroX,inicioCuadroY+12);
            MUTEXUNLOCK;

            limpiarBufferEntrada();
            opMenu = getch();


            switch(opMenu)
            {
            case '1':
                cuadroMenuInstantaneo(x,y);
                cargaMarca(auxVehiculo.marca);
                break;

            case '2':
                cuadroMenuInstantaneo(x,y);
                cargaModelo(auxVehiculo.modelo);
                break;

            case '3':
                cuadroMenuInstantaneo(x,y);
                cargaAnio(&(auxVehiculo.anio));
                break;

            case '4':
                cuadroMenuInstantaneo(x,y);
                cargaKms(&(auxVehiculo.kms));
                break;

            case '5':
                cuadroMenuInstantaneo(x,y);
                cargaPrecioDiario(&(auxVehiculo.precioDeAlquilerDiario));
                break;

            case '6':
                cuadroMenuInstantaneo(x,y);
                cargaTipo(&(auxVehiculo.tipoVehiculo));
                break;

            case '7':
                cuadroMenuInstantaneo(x,y);
                invertirDisponibilidad(&(auxVehiculo.disponibilidad));
                break;
            }
        }while (opMenu != ESC);

        if(opMenu == ESC){
        gotoxy(inicioCuadroX+1,inicioCuadroY+12);
        printf("Desea guardar los cambios realizados? (Presione 's' para confirmar.)");
        limpiarBufferEntrada();
        confirmacion = getch();
        }

        //CONFIRMACION PARA CAMBIAR DATOS DEL ARREGLO DINAMICO
        confirmacion = tolower(confirmacion); //Convierto el char a minuscula para asegurarme que entra el IF

        if(confirmacion == 's')
        {
            copiaVehiModificado(auxVehiculo, pos); //Reemplazar datos del auxVehiculo con el del arreglo dinamico en la posicion que se encuentra
            //MODIFICAR EL VEHICULO EN EL ARCHIVO
            modificaVehiArch(patBusqueda, pos);
        }
    }
}

void menuGestionVehiAdmin(int x, int y)
{
    int ABM = 0;
    char op;
    leerArchiVehiculos();
    int inicioCuadroX = (medidasConsola.ancho/2) - (ANCHO/2) + 6;
    int inicioCuadroY = (medidasConsola.alto/2);

    do
    {
        cuadroMenuInstantaneo(x,y);
        MUTEXLOCK;
        gotoxy(inicioCuadroX,inicioCuadroY-10);
        printf("Ingrese el ABM del archivo:");
        gotoxy(inicioCuadroX,inicioCuadroY-8);
        printf("1-  Agregar un nuevo vehiculo.");
        gotoxy(inicioCuadroX,inicioCuadroY-6);
        printf("2-  Mostrar los vehiculos disponibles.");
        gotoxy(inicioCuadroX,inicioCuadroY-4);
        printf("3-  Modificar un vehiculo.");
        MUTEXUNLOCK;

        limpiarBufferEntrada();
        op = getch();

        switch(op)
        {
        case '1':
            cuadroMenuInstantaneo(x,y);
            agregarVehiculo();
            break;
        case '2':
            cuadroMenuInstantaneo(x,y);
            leerRegistroVehiculos();
            break;
        case '3':
            cuadroMenuInstantaneo(x,y);
            modificarVehiculo(x, y);
            break;
        case '4':
            //eliminarVehiculo();
            break;
        case '5':

            break;
        default:
            break;
        }
    }
    while (op != ESC);
    limpiarBufferEntrada();

    free(arrDinVehiculos);
    //Ver Vehículos.
    //Agregar Vehículo.
    //Modificar Vehículos.
    //Dar de baja un Vehículo.
}

void menuGestionAlqAdmin(int x, int y)
{
    char op;
    leerArchiVehiculos();
    leerArchAlquileres();
    int inicioCuadroX = (medidasConsola.ancho/2) - (ANCHO/2) + 6;
    int inicioCuadroY = (medidasConsola.alto/2);
    int posicionArrayDinVehi;

    do
    {
        posicionArrayDinVehi=-1;
        cuadroMenuInstantaneo(x,y);
        MUTEXLOCK;
        gotoxy(inicioCuadroX,inicioCuadroY-12);
        printf("1-  Agregar un nuevo alquiler.");
        gotoxy(inicioCuadroX,inicioCuadroY-10);
        printf("2-  Mostrar todos los alquileres.");
        gotoxy(inicioCuadroX,inicioCuadroY-8);
        printf("3-  Calcular ingresos de alquileres.");
        gotoxy(inicioCuadroX,inicioCuadroY-6);
        printf("4-  Ver alquiler mas alto.");
        gotoxy(inicioCuadroX,inicioCuadroY-4);
        printf("5-  Ver vehiculos con menos de 5 anios.");
        gotoxy(inicioCuadroX,inicioCuadroY-2);
        printf("6-  Ver listado de alquileres por cliente.");
        MUTEXUNLOCK;
        fflush(stdin);
        op = getch();

        switch(op)
        {
        case '1':
            cuadroMenuInstantaneo(x,y);
            leerRegistroVehiculosSeleccion(&posicionArrayDinVehi);
            if(posicionArrayDinVehi!= -1)
            {
                cuadroMenuInstantaneo(x,y);
                registrarAlquiler(posicionArrayDinVehi,x,y);
            }
            break;
        case '2':
            cuadroMenuInstantaneo(x,y);
            leerRegistroAlquileres();
            break;
        case '3':
            cuadroMenuInstantaneo(x,y);
            pedirDatosYSumarImportes();
            break;
        case '4':
            cuadroMenuInstantaneo(x,y);
            break;
        case '5':
            cuadroMenuInstantaneo(x,y);
            break;
        default:
            break;
        }
    }
    while (op != ESC);

    free(arrDinAlquileres);
    free(arrDinVehiculos);

}

///---------------------------------------------------------------------------------------------------------------------------------- fin funciones de administrador///







/// Funciones de Cliente -------------------------------------------------------------------------------------------------------------------------------------------///

void menuOpcionesDeUsuario(int x,int y, int dni)
{
    char op;

    int inicioCuadroX = (medidasConsola.ancho/2) - (ANCHO/2) +6;
    int inicioCuadroY = (medidasConsola.alto/2);

    MUTEXLOCK;
    gotoxy(inicioCuadroX+1,inicioCuadroY+1);
    MUTEXUNLOCK;

    do
    {
        cuadroMenuInstantaneo(x,y);
        MUTEXLOCK;
        gotoxy(inicioCuadroX,inicioCuadroY+2);
        printf("Ingrese el menu al cual quiere ingresar:");
        gotoxy(inicioCuadroX,inicioCuadroY+4);
        printf("1-  Modificar usuario.");
        gotoxy(inicioCuadroX,inicioCuadroY+6);
        printf("2-  Alquilar vehiculo.");
        gotoxy(inicioCuadroX,inicioCuadroY+8);
        printf("3-  Gestion de alquileres propios.");
        gotoxy(inicioCuadroX,inicioCuadroY+10);
        MUTEXUNLOCK;
        FF;
        op = getch();

        switch(op)
        {
            case '1':
                menuGestionUsuario(inicioCuadroX,inicioCuadroY,dni);
            break;

            case '2':
                menuAlquilerUsuario(inicioCuadroX,inicioCuadroY);
            break;

            case '3':
                menuGestionAlqUsuario(inicioCuadroX,inicioCuadroY);
            break;
        }
    }while (op != ESC);
}

/*void mostrarPersona(int x, int y, Persona usuario)
{
    MUTEXLOCK;
    gotoxy(x,y-5);
    printf("1 - Nombre:     %s", usuario.nombre);
    gotoxy(x,y-3);
    printf("2 - Telefono:   %s", usuario.telefono);
    gotoxy(x,y-1);
    printf("3 - Direcci%n:", 162);
    gotoxy(x,y);
    printf("%s", 162, usuario.direccion);
    MUTEXUNLOCK;
}*/

void menuGestionUsuario(int x, int y, int dni)
{
    int pos;
    //funciones de modificacion de uisuario propio.
    cuadroMenuInstantaneo(x,y);

    MUTEXLOCK;
    gotoxy(x,y);
    printf("Seleccione lo que desea modificar:");
    //mostrarPersona(buscarUsuarioArray(dni,&pos));
    MUTEXUNLOCK;
}

void menuAlquilerUsuario(int x, int y)
{
    //funciones de alquiler.
}

void menuGestionAlqUsuario(int x, int y)
{
    //funciones de visualizacion de alquileres propios.
}


///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///







#include "menu.h"
#include "data_Management.h"

volatile char global_key = 0;
volatile char last_key;

///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///

///inicio funciones auxiliares para menues-----------------------------------------------------------------------------------------------------------------------------///

// Función para leer una entrada 's' o 'n' del usuario y devolver por referencia
void leerSn(char *resultado)
{
    char opcion;
    do
    {
        opcion = getch(); // Lee una tecla sin mostrarla en la consola
        opcion = tolower(opcion); // Convierte la entrada a minúscula para aceptar tanto 's' como 'S' y 'n' como 'N'
    } while (opcion != 's' && opcion != 'n');

    *resultado = opcion; // Asigna la opción validada al resultado por referencia
}

void limpiarBufferEntrada()
{
    while (kbhit())
        getch(); // Limpiar buffer de entrada de teclado
}

int leerLimite(char *digitos, int max)/// limitar dígitos de escritura
{
    int contador = 0;

    while (1)
    {
        fflush(stdin);
        char tecla = getch();

        if (tecla == ESC)
        {
            return 0;
        }

        if (tecla == '\r')
        {
            digitos[contador] = '\0';
            return 1;
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

int leerLimiteNumeros(char *digitos, int max)/// limitar dígitos de escritura y permitir escribir solo números
{
    int contador = 0;

    while (1)
    {
        char tecla = getch();

        if (tecla == ESC)
        {
            return 0;
        }

        if (tecla == '\r')
        {
            digitos[contador] = '\0';
            return 1;
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

int leerLimiteNumerosYLetras(char *digitos, int max)
{
    int contador = 0;

    while (1)
    {
        char tecla = getch();

        if (tecla == ESC)
        {
            return 0;
        }

        if (tecla == '\r')
        {
            digitos[contador] = '\0';
            return 1;
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

    MUTEXLOCK;
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
    MUTEXUNLOCK;
}

///-----------------------------------------------------------------------------------------------------------------------------fin funciones auxiliares para menues///



///INICIO FUNCIONES GRAFICAS/FRONTEND PARA MENUES-----------------------------------------------------------------------------------------------------------------------------///

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

int escribeCuadro(int x, int y, int (*funcion)(), char texto[], int cant) /// modularización
{
    int breaking;
    MUTEXLOCK;
    do
    {
        cursorClean(1);
        gotoxy(x,y);
        FF;
        breaking = funcion(texto,cant);
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

return breaking;
}

///-----------------------------------------------------------------------------------------------------------------------------FIN FUNCIONES GRAFICAS/FRONTEND PARA MENUES///



/// Funciones de menu principales ----------------------------------------------------------------------------------------------------------------------------------///

int mainMenu(int anchoConsola, int altoConsola) /// menú principal
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
            flag = menuCrearUsuario(anchoConsola, altoConsola, &dni, contra);
            if (flag == 1)
            {
                MUTEXLOCK;
                gotoxy(anchoConsola/2-33,altoConsola/2-10);
                printf("ESCAPE para volver hacia atr%cs...",160);

                opcion = getch();
                MUTEXUNLOCK;
                flag = (opcion == 67 || opcion == 99) ? 2 : 0;
            }
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
            if (flag == 2)  // Ingresa sesión.
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
                    cuadroMenuInstantaneo(anchoConsola,altoConsola);
                    MUTEXLOCK;
                    gotoxy((medidasConsola.ancho/2),(medidasConsola.alto/2));
                    printf("Ingresando al menu de cliente...");
                    MUTEXUNLOCK;
                    Sleep(1000);
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
        cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
        MUTEXLOCK;
        gotoxy(medidasConsola.ancho/2-20,medidasConsola.alto/2-15);
        printf("Ingrese ESC para finalizar...\n");
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
                    break;

                case (77):      //Inicio de sesión. derecha
                    MUTEXLOCK;
                    selectIniciarSesion(x,y);
                    MUTEXUNLOCK;
                    flag = 2;
                    last_key=77;
                    break;
                }
            }
            else if (opcion == ENTER && flag)     // Seleccionar opcion
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
    cuadroMenu(x,y);
    MUTEXLOCK;
    tituloMenu(x,y);
    detallesMenu(x,y);
    MUTEXUNLOCK;
}

int menuCrearUsuario(int x, int y, int *dni, char contra[])/// ver
{
    int centrox = x/2 - 26;
    int centroy = y/2;
    char auxContra[MAX_CARACTERES], dniUsu[10];
    int pos = 0;

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

        if (escribeCuadro(centrox+23,centroy-4,leerLimiteNumeros,dniUsu,8)) /// devuelve 1 si sale correctamente
        {
            (*dni) = strtol(dniUsu,NULL,10);
            if (escribeCuadro(centrox+23,centroy,leerLimite,contra,MAX_CARACTERES))
            {
                if (!escribeCuadro(centrox+23,centroy+4,leerLimite,auxContra,MAX_CARACTERES))
                    return ESC;
            }
            else
                return ESC;
        }
        else
            return ESC;

        if (strcmp(contra,auxContra)!=0)
        {
            MUTEXLOCK;
            gotoxy(centrox-4,centroy+8);
            printf("Las contrase%cas son diferentes. Por favor reintente...", 164);
            MUTEXUNLOCK;
        }
    }
    while(strcmp(contra,auxContra)!=0);

    if (buscarPersonaArch((*dni)) != -1)
    {
        cuadroMenuInstantaneo(x,y);
        MUTEXLOCK;
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-2);
        printf("El usuario ya existe.                                 ");
        gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2));
        printf("Ingrese sesi%cn para continuar o Reintente con otro DNI.", 162);
        getch();
        MUTEXUNLOCK;
        cuadroMenuInstantaneo(x,y);
    }
    else
    {
        guardarDatosUsuario(x,y,(*dni),contra);   /// En arreglo dinámico. Llamo a la funcion de guardado en funcion guardarDatosUsuario en el archivo para el usuario una vez terminadas las comprobaciones anteriores...
    }

return 1;
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
    escribeCuadro(centrox-3,centroy-1,leerLimiteNumeros,per.telefono,14);
    escribeCuadro(centrox-33,centroy+5,leerLimite,per.direccion,68);

    per.dni = dniusu;
    strcpy(per.contra,contrasenia);

    guardarNuevoUsuarioArch(per);
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

        if (escribeCuadro(centrox+23,centroy-4,leerLimiteNumeros,contra,8))
        {
            (*dni) = strtol(contra, NULL, 10);
            if (!escribeCuadro(centrox+23,centroy,leerLimite,contra,20))
                return 0;
        }
        else
            return 0;

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
        }
    }
    while(intentos < 3 && ingreso != 2);

    if(intentos == 3)
    {
        gotoxy(centrox-8,centroy+6);
        printf("maxima cantidad de intentos alcanzada. Volviendo al menu principal...");
        return 0;
    }
    else
    {
        return ingreso;
    }
}

///--------------------------------------------------------------------------------------------------------------------------- fin funciones principales para menues///


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


///menu gestion personas Administrador-----------------------------------------------------------------------------------------------------------------
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
        printf("Seleccione el menu al cual quiere ingresar:");
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
            cuadroMenuInstantaneo(x,y);
            if(cantidadPersonas != 0){
            leerRegistroPersonas();
            }
            else
            {
            MUTEXLOCK;
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+5));
            printf("no hay registros de personas vigentes");
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+7));
            printf("Presione cualquier tecla para volver al menu anterior");tipeo("...",500);
            getch();
            MUTEXUNLOCK;
            break;
            }
            break;
        }
    }
    while (op != ESC);
}

///-----------------------------------------------------------------------------------------------------------------fin menu gestion personas Administrador



void modificarVehiculo(int x, int y)
{
    Patente patBusqueda;

    int pos = -1;

    cuadroMenuInstantaneo(x,y);
    MUTEXLOCK;
    gotoxy(((medidasConsola.ancho/2) - (ANCHO/2))+1,((medidasConsola.alto/2) - (ALTO/2))-8);
    printf("Ingrese una patente del vehiculo a modificar:");
    cargaPatenteSinComprobacion(&patBusqueda);
    MUTEXUNLOCK;

    if(buscarPatenteArr(patBusqueda, &pos) == 1)
    {
        char opMenu;
        char confirmacion;
        Vehiculo auxVehiculo;    //Se trabaja sobre un auxiliar para que al finalizar el menu, se puedan confirmar los cambios
        Vehiculo vehiInicial;    //Se trabaja sobre un auxiliar que es la primera version del vehiculo para que al finalizar el menu, se puedan confirmar los cambios
        int inicioCuadroX = (x/2) - (ANCHO/2) + 6;
        int inicioCuadroY = (y/2) - (ALTO/2)+6;

        auxVehiculo = arrDinVehiculos[pos];
        vehiInicial = arrDinVehiculos[pos];

        cuadroMenuInstantaneo(x,y);
        mostrarVehiculo(auxVehiculo);
        getch();

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
            gotoxy(inicioCuadroX,inicioCuadroY+6);
            printf("5-  Modificar el PRECIO DE ALQUILER DIARIO del vehiculo.");
            gotoxy(inicioCuadroX,inicioCuadroY+8);
            printf("6-  Modificar el TIPO de vehiculo.");
            gotoxy(inicioCuadroX,inicioCuadroY+10);
            printf("7-  Modificar la DISPONIBILIDAD del vehiculo.");
            gotoxy(inicioCuadroX,inicioCuadroY+14);
            printf("8-  Ver vehiculo con nuevos datos.");
            gotoxy(inicioCuadroX,inicioCuadroY+16);
            printf("9-  Ver vehiculo antes de modificaciones.");
            MUTEXUNLOCK;

            limpiarBufferEntrada();
            opMenu = getch();

            switch(opMenu)
            {
            case '1':
                cuadroMenuInstantaneo(x,y);
                MUTEXLOCK;
                cargaMarca(auxVehiculo.marca);
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(x,y);
                MUTEXLOCK;
                gotoxy(inicioCuadroX,inicioCuadroY-2);
                printf("Marca anterior: %s",vehiInicial.marca);
                gotoxy(inicioCuadroX,inicioCuadroY);
                printf("Nueva marca: %s",auxVehiculo.marca);
                gotoxy(inicioCuadroX,inicioCuadroY+6);
                printf("Presione cualquier tecla para continuar...");
                getch();
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(x,y);
                break;

            case '2':
                cuadroMenuInstantaneo(x,y);
                MUTEXLOCK;
                cargaModelo(auxVehiculo.modelo);
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(x,y);
                MUTEXLOCK;
                gotoxy(inicioCuadroX,inicioCuadroY-2);
                printf("Modelo anterior: %s",vehiInicial.modelo);
                gotoxy(inicioCuadroX,inicioCuadroY);
                printf("Nuevo modelo: %s",auxVehiculo.modelo);
                gotoxy(inicioCuadroX,inicioCuadroY+6);
                printf("Presione cualquier tecla para continuar...");
                getch();
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(x,y);
                break;

            case '3':
                cuadroMenuInstantaneo(x,y);
                MUTEXLOCK;
                cargaAnio(&(auxVehiculo.anio));
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(x,y);
                MUTEXLOCK;
                gotoxy(inicioCuadroX,inicioCuadroY-2);
                printf("A%co anterior: %d",241,vehiInicial.anio);
                gotoxy(inicioCuadroX,inicioCuadroY);
                printf("Nuevo A%co: %d",241,auxVehiculo.anio);
                gotoxy(inicioCuadroX,inicioCuadroY+6);
                printf("Presione cualquier tecla para continuar...");
                getch();
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(x,y);
                break;

            case '4':
                cuadroMenuInstantaneo(x,y);
                MUTEXLOCK;
                cargaKms(&(auxVehiculo.kms));
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(x,y);
                MUTEXLOCK;
                gotoxy(inicioCuadroX,inicioCuadroY-2);
                printf("Anterior KM: %d",vehiInicial.kms);
                gotoxy(inicioCuadroX,inicioCuadroY);
                printf("Nuevo KM: %d",auxVehiculo.kms);
                gotoxy(inicioCuadroX,inicioCuadroY+6);
                printf("Presione cualquier tecla para continuar...");
                getch();
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(x,y);
                break;

            case '5':
                cuadroMenuInstantaneo(x,y);
                MUTEXLOCK;
                cargaPrecioDiario(&(auxVehiculo.precioDeAlquilerDiario));
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(x,y);
                MUTEXLOCK;
                gotoxy(inicioCuadroX,inicioCuadroY-2);
                printf("Precio diario anterior: %.2f",vehiInicial.precioDeAlquilerDiario);
                gotoxy(inicioCuadroX,inicioCuadroY);
                printf("Precio diario nuevo: %.2f",auxVehiculo.precioDeAlquilerDiario);
                gotoxy(inicioCuadroX,inicioCuadroY+6);
                printf("Presione cualquier tecla para continuar...");
                getch();
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(x,y);
                break;

            case '6':
                cuadroMenuInstantaneo(x,y);
                MUTEXLOCK;
                cargaTipo(&(auxVehiculo.tipoVehiculo));
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(x,y);
                MUTEXLOCK;
                gotoxy(inicioCuadroX,inicioCuadroY-2);
                printf("Tipo de vehiculo anterior: %s",vehiInicial.tipoVehiculo);
                gotoxy(inicioCuadroX,inicioCuadroY);
                printf("Tipo de vehiculo nuevo: %s",auxVehiculo.tipoVehiculo);
                gotoxy(inicioCuadroX,inicioCuadroY+6);
                printf("Presione cualquier tecla para continuar...");
                getch();
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(x,y);
                break;

            case '7':
                cuadroMenuInstantaneo(x,y);
                invertirDisponibilidad(&(auxVehiculo.disponibilidad));
                MUTEXLOCK;
                gotoxy(inicioCuadroX,inicioCuadroY-2);
                if(vehiInicial.disponibilidad==1){
                    printf("Disponibilidad anterior [DISPONIBLE]");
                    gotoxy(inicioCuadroX,inicioCuadroY);
                    printf("Disponibilidad nueva [NO DISPONIBLE]");
                }
                else{
                    printf("Disponibilidad anterior [NO DISPONIBLE]");
                    gotoxy(inicioCuadroX,inicioCuadroY);
                    printf("Disponibilidad nueva [DISPONIBLE]");
                }
                gotoxy(inicioCuadroX,inicioCuadroY+6);
                printf("Presione cualquier tecla para continuar...");
                getch();
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(x,y);
                break;
            case '8':
                cuadroMenuInstantaneo(x,y);
                mostrarVehiculo(auxVehiculo);
                gotoxy(inicioCuadroX,inicioCuadroY+17);
                printf("Presione cualquier tecla para continuar...");
                getch();
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(x,y);
                break;

            case '9':
                cuadroMenuInstantaneo(x,y);
                mostrarVehiculo(vehiInicial);
                gotoxy(inicioCuadroX,inicioCuadroY+17);
                printf("Presione cualquier tecla para continuar...");
                getch();
                MUTEXUNLOCK;
                cuadroMenuInstantaneo(x,y);
                break;
            }

        }while (opMenu != ESC);

        if(opMenu == ESC){
        cuadroMenuInstantaneo(x,y);
        MUTEXLOCK;
        gotoxy(inicioCuadroX+1,inicioCuadroY+10);
        printf("Desea guardar los cambios realizados?");
        gotoxy(inicioCuadroX+1,inicioCuadroY+11);
        printf("(Presione 's' para confirmar o cualquier otra tecla para salir)");
        limpiarBufferEntrada();
        confirmacion = getch();
        }

        //CONFIRMACION PARA CAMBIAR DATOS DEL ARREGLO DINAMICO
        confirmacion = tolower(confirmacion); //Convierto el char a minuscula para asegurarme que entra el IF

        if(confirmacion == 's')
        {
            arrDinVehiculos[pos] = auxVehiculo; //Reemplazar datos del auxVehiculo con el del arreglo dinamico en la posicion que se encuentra
            //MODIFICAR EL VEHICULO EN EL ARCHIVO
            modificaVehiArch(patBusqueda, pos);
        }
        MUTEXUNLOCK;
    }
    else{
    cuadroMenuInstantaneo(x,y);
    MUTEXLOCK;
    gotoxy(((medidasConsola.ancho/2) - (ANCHO/2))+1,((medidasConsola.alto/2) - (ALTO/2))-8);
    printf("Vehiculo no encontrado");
    getch();
    gotoxy(((medidasConsola.ancho/2) - (ANCHO/2))+1,((medidasConsola.alto/2) - (ALTO/2))-6);
    printf("Volviendo al menu anterior");tipeo("...",500);
    MUTEXUNLOCK;
    }
}

void menuGestionVehiAdmin(int x, int y)
{
    int ABM = 0;
    char op;
    leerArchiVehiculos();
    Patente pat;
    int inicioCuadroX = (medidasConsola.ancho/2) - (ANCHO/2) + 6;
    int inicioCuadroY = (medidasConsola.alto/2)-8;

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
        printf("3-  Mostrar todos los vehiculos.");
        gotoxy(inicioCuadroX,inicioCuadroY-2);
        printf("4-  Buscar un vehiculo por patente.");
        gotoxy(inicioCuadroX,inicioCuadroY);
        printf("5-  Modificar un vehiculo.");
        gotoxy(inicioCuadroX,inicioCuadroY+2);
        printf("6-  Cambiar estado de activo de un vehiculo.");
        gotoxy(inicioCuadroX,inicioCuadroY);
        MUTEXUNLOCK;

        limpiarBufferEntrada();
        op = getch();
        cuadroMenuInstantaneo(x,y);

        switch(op)
        {
        case '1':
            agregarVehiculo();
            break;
        case '2':
            cuadroMenuInstantaneo(x,y);
            if(cantVehiculos != 0 && contarVehiculosDisponibles() != 0){
            mostrarVehiculosDisponibles();
            }
            else
            {
            MUTEXLOCK;
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+5));
            printf("no hay registros de vehiculos vigentes o disponibles");
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+7));
            printf("Presione cualquier tecla para volver al menu anterior");
            getch();
            MUTEXUNLOCK;
            break;
            }
            break;

        case '3':
            if(cantVehiculos != 0){
            leerRegistroVehiculos();
            }
            else
            {
            MUTEXLOCK;
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+5));
            printf("no hay registros de vehiculos vigentes");
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+7));
            printf("Presione cualquier tecla para volver al menu anterior");
            getch();
            MUTEXUNLOCK;
            break;
            }
            break;

        case '4':
            if(cantVehiculos != 0){
            MUTEXLOCK;
            cargaPatenteSinComprobacion(&pat);
            MUTEXUNLOCK;
            mostrarPorPatente(pat);
            }
            else
            {
            MUTEXLOCK;
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+5));
            printf("no hay registros de vehiculos vigentes");
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+7));
            printf("Presione cualquier tecla para volver al menu anterior");
            getch();
            MUTEXUNLOCK;
            break;
            }
            break;

        case '5':
            if(cantVehiculos != 0){
            modificarVehiculo(x, y);
            }
            else
            {
            MUTEXLOCK;
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+5));
            printf("no hay registros de vehiculos vigentes");
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+7));
            printf("Presione cualquier tecla para volver al menu anterior");
            getch();
            MUTEXUNLOCK;
            break;
            }
            break;
        case '6':
            MUTEXLOCK;
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+5),((medidasConsola.alto/2)-(ALTO/2)-7));
            printf("Escribe una patente para buscar y eliminar o restaurar");
            cargaPatenteSinComprobacion(&pat);
            cambiarEstadoActivoVehi(pat);
            MUTEXUNLOCK;
            break;
        }
    }
    while (op != ESC);
    limpiarBufferEntrada();

    free(arrDinVehiculos);
    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
    MUTEXLOCK;
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
    printf("liberando memoria principal");
    tipeo("...",300);
    MUTEXUNLOCK;
    //Dar de baja un Vehículo.
}

void menuGestionAlqAdmin(int x, int y)
{
    char op;
    int dni;
    Patente pat;
    leerArchiVehiculos();
    leerArchAlquileres();
    int inicioCuadroX = (medidasConsola.ancho/2) - (ANCHO/2) + 6;
    int inicioCuadroY = (medidasConsola.alto/2-6);
    int posicionArrayDinVehi;

    do
    {
        posicionArrayDinVehi=-1;
        cuadroMenuInstantaneo(x,y);
        MUTEXLOCK;
        gotoxy(inicioCuadroX,inicioCuadroY-12);
        printf("1-  Agregar un nuevo alquiler.");
        gotoxy(inicioCuadroX,inicioCuadroY-10);
        printf("2-  Mostrar historial de todos los alquileres.");
        gotoxy(inicioCuadroX,inicioCuadroY-8);
        printf("3-  Calcular ingresos de alquileres.");
        gotoxy(inicioCuadroX,inicioCuadroY-6);
        printf("4-  Ver alquiler mas alto.");
        gotoxy(inicioCuadroX,inicioCuadroY-4);
        printf("5-  Ver vehiculos con menos de 5 a%cos.",164);
        gotoxy(inicioCuadroX,inicioCuadroY-2);
        printf("6-  Ver listado de alquileres por cliente.");
        gotoxy(inicioCuadroX,inicioCuadroY);
        printf("7-  Ver listado de alquileres por patente.");
        gotoxy(inicioCuadroX,inicioCuadroY);
        MUTEXUNLOCK;
        fflush(stdin);
        op = getch();
        cuadroMenuInstantaneo(x,y);

        switch(op)
        {
        case '1':
            if(cantVehiculos!=0){
            leerRegistroVehiculosSeleccion(&posicionArrayDinVehi);
            }
            else
            {
            MUTEXLOCK;
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+5));
            printf("no hay registros de vehiculos vigentes");
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+7));
            printf("Presione cualquier tecla para volver al menu anterior");
            getch();
            MUTEXUNLOCK;
            break;
            }
            if(posicionArrayDinVehi!= -1)
            {
                cuadroMenuInstantaneo(x,y);
                registrarAlquiler(posicionArrayDinVehi,x,y);
            }
            break;
        case '2':
            if(cantAlquileres!=0){
            leerRegistroAlquileres();
            }
            else
            {
            MUTEXLOCK;
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+5));
            printf("no hay registros de vehiculos vigentes");
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+7));
            printf("Presione cualquier tecla para volver al menu anterior");
            getch();
            MUTEXUNLOCK;
            break;
            }
            break;
        case '3':
            if(cantAlquileres != 0){
            MUTEXLOCK;
            pedirDatosYSumarImportes();
            MUTEXUNLOCK;
            }
            else
            {
            MUTEXLOCK;
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+5));
            printf("No hay registros de veh%cculos vigentes",161);
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+7));
            printf("Presione cualquier tecla para volver al men%c anterior",163);tipeo("...",500);
            getch();
            MUTEXUNLOCK;
            break;
            }
            break;
        case '4':
            if(cantAlquileres!=0){
            buscarAlquilerMayor();
            }
            else
            {
            MUTEXLOCK;
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+5));
            printf("no hay registros de veh%cculos vigentes",161);
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+7));
            printf("Presione cualquier tecla para volver al men%c anterior",163);tipeo("...",500);
            MUTEXUNLOCK;
            getch();
            break;
            }
            break;
        case '5':
            mostrarVehiculos5aniosOrdenado();
            break;
        case '6':
            MUTEXLOCK;
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+2),((medidasConsola.alto/2)-(ALTO/2)+1));
            printf("Ingrese el DNI del cual se buscar%cn los alquileres",160);
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+2),((medidasConsola.alto/2)-(ALTO/2)+3));
            scanf("%d",&dni);
            MUTEXUNLOCK;
            cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
            if(buscarPersonaArch(dni)!=-1){
            mostrarAlquilerPorDni(dni);
            }
            else{
            MUTEXLOCK;
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+2),((medidasConsola.alto/2)-(ALTO/2)+1));
            printf("No se encontr%c el usuario en la base de datos",162);tipeo("...",300);
            MUTEXUNLOCK;
            }
            break;
        case '7':
            MUTEXLOCK;
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+2),((medidasConsola.alto/2)-(ALTO/2)+1));
            printf("Ingrese la patente de la cual se buscar%cn los alquileres",160);
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+2),((medidasConsola.alto/2)-(ALTO/2)+3));
            cargaPatenteSinComprobacion(&pat);
            MUTEXUNLOCK;
            cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
            if(buscarPatenteArch(pat)!=-1){
            mostrarAlquilerPorPatente(pat);
            }
            else{
            MUTEXLOCK;
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+2),((medidasConsola.alto/2)-(ALTO/2)+1));
            printf("No se encontr%c el vehiculo en la base de datos",162);tipeo("...",300);
            MUTEXUNLOCK;
            }
            break;
        }
    }
    while (op != ESC);

    free(arrDinAlquileres);
    free(arrDinVehiculos);
    cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
    MUTEXLOCK;
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
    printf("liberando memoria principal");
    tipeo("...",300);
    MUTEXUNLOCK;
}

///---------------------------------------------------------------------------------------------------------------------------------- fin funciones de administrador///


/// Funciones de Cliente -------------------------------------------------------------------------------------------------------------------------------------------///

void menuOpcionesDeUsuario(int x,int y, int dni)
{
    leerArchAlquileres();
    leerArchiVehiculos();
    char op;
    int pos;
    int posicionArrayDinVehi;

    int inicioCuadroX = (medidasConsola.ancho/2) - (ANCHO/2) +6;
    int inicioCuadroY = (medidasConsola.alto/2)- (ALTO/2);

    MUTEXLOCK;
    gotoxy(inicioCuadroX+1,inicioCuadroY+1);
    MUTEXUNLOCK;

    do
    {
        cuadroMenuInstantaneo(x,y);
        MUTEXLOCK;
        gotoxy(inicioCuadroX,inicioCuadroY);
        printf("Ingrese el men%c al cual quiere ingresar:",163);
        gotoxy(inicioCuadroX,inicioCuadroY+2);
        printf("1-  Modificar usuario.");
        gotoxy(inicioCuadroX,inicioCuadroY+4);
        printf("2-  Alquilar vehiculo.");
        gotoxy(inicioCuadroX,inicioCuadroY+6);
        printf("3-  Visualizar mis alquileres.");
        gotoxy(inicioCuadroX,inicioCuadroY+8);
        MUTEXUNLOCK;
        FF;
        op = getch();
        switch(op)
        {
            case '1':
                menuModificarUsuario(x,y,buscarUsuarioArray(dni,&pos));
            break;

            case '2':
            cuadroMenuInstantaneo(x,y);
            if(cantVehiculos!=0)
            {
            leerRegistroVehiculosSeleccion(&posicionArrayDinVehi);
            }
            else
            {
            MUTEXLOCK;
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+5));
            printf("no hay registros de vehiculos vigentes");
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+12),((medidasConsola.alto/2)-(ALTO/2)+7));
            printf("Presione cualquier tecla para volver al menu anterior");tipeo("...",500);
            getch();
            MUTEXUNLOCK;
            break;
            }
            if(posicionArrayDinVehi!= -1)
            {
                cuadroMenuInstantaneo(x,y);
                registrarAlquilerUsuario(posicionArrayDinVehi,x,y,dni);
            }
            break;

            case '3':
            cuadroMenuInstantaneo(medidasConsola.ancho,medidasConsola.alto-15);
            if(buscarPersonaArch(dni)!=-1){
            mostrarAlquilerPorDni(dni);
            }
            else{
            MUTEXLOCK;
            gotoxy(((medidasConsola.ancho/2)-(ANCHO/2)+2),((medidasConsola.alto/2)-(ALTO/2)+1));
            printf("No se encontr%c el usuario en la base de datos",162);tipeo("...",300);
            MUTEXUNLOCK;
            }
            break;
        }
    }while (op != ESC);
}

void menuModificarUsuario(int x, int y, Persona per)
{
    char op, aceptar[8],confirmacion;

    int inicioCuadroX = (x/2) - (ANCHO/2) + 6;
    int inicioCuadroY = (y/2);

    do
    {
        cuadroMenuInstantaneo(x,y);
        MUTEXLOCK;
        gotoxy(inicioCuadroX,inicioCuadroY-10);
        printf("Datos de usuario");
        gotoxy(inicioCuadroX,inicioCuadroY-8);
        printf("Presiona una tecla para continuar");
        MUTEXUNLOCK;
        mostrarPersona(per);
        getch();
        cuadroMenuInstantaneo(x,y);
        MUTEXLOCK;
        gotoxy(inicioCuadroX,inicioCuadroY-10);
        printf("Ingrese ESC para volver para atr%cs",160);
        gotoxy(inicioCuadroX,inicioCuadroY-6);
        printf("Ingrese la opci%cn a modificar:", 162);
        gotoxy(inicioCuadroX,inicioCuadroY-4);
        printf("1-  Modificar el nombre.");
        gotoxy(inicioCuadroX,inicioCuadroY-2);
        printf("2-  Modificar la direcci%cn.",162);
        gotoxy(inicioCuadroX,inicioCuadroY);
        printf("3-  Modificar el tel%cfono.",130);
        gotoxy(inicioCuadroX,inicioCuadroY+2);
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
            MUTEXLOCK;
            gotoxy(inicioCuadroX,inicioCuadroY-4);
            printf("Est%c seguro que desea darse de baja?", 160);
            gotoxy(inicioCuadroX,inicioCuadroY-2);
            printf("Escriba \"ACEPTAR\" para continuar con la baja.");
            cuadroEscritura(inicioCuadroX,inicioCuadroY+1,7);
            MUTEXUNLOCK;
            escribeCuadro(inicioCuadroX+1,inicioCuadroY+2,leerLimite,aceptar,7);
            if (aceptar == "aceptar" || aceptar == "ACEPTAR" || aceptar == "Aceptar" )
            per.activo = 0;
            break;
        }
    }
    while (op != ESC);

    if(op == ESC){
        MUTEXLOCK;
        gotoxy(inicioCuadroX+1,inicioCuadroY+10);
        printf("Desea guardar los cambios realizados? (Presione 's' para confirmar.)");
        gotoxy(inicioCuadroX+1,inicioCuadroY+11);
        printf("(Presione 's' para confirmar o cualquier otra tecla para salir)");
        limpiarBufferEntrada();
        confirmacion = getch();
        }

        //CONFIRMACION PARA CAMBIAR DATOS DEL ARREGLO DINAMICO
        confirmacion = tolower(confirmacion); //Convierto el char a minuscula para asegurarme que entra el IF

        if(confirmacion == 's')
        {
            modificarUsuarioEnArray(per);
            modificaUsuArch(per.dni, per);
        }
    MUTEXUNLOCK;
    cuadroMenuInstantaneo(x,y);
}




///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///







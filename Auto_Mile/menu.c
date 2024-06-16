#include "menu.h"

volatile char global_key = 0;
volatile char last_key;


///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///

/// Funciones auxiliares para los menues///

void limpiarBufferEntrada() {
    while (kbhit()) {
        getch(); // Limpiar buffer de entrada de teclado
    }
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
    gotoxy(centrox+2,centroy);
    printf("ESC para volver");
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

///-----------------------------------------------------------------------------------------------------------------------------fin funciones auxiliares para menues///

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
                    Sleep(2000);
                    MUTEXUNLOCK;
                    cuadroMenuInstantaneo(anchoConsola,altoConsola);
                    menuOpcionesDeAdmin(anchoConsola,altoConsola);
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

int ingresaUsuario(int x, int y, int *dni) /// ver
{
    int centrox = x/2 - 25;
    int centroy = y/2 + 2;
    char contra[MAX_CARACTERES];
    int intentos = 0, ingreso;

    cuadroMenuInstantaneo(x,y);

    do
    {
        textoCuadro(centrox+22,centroy-5,"DNI de usuario:");
        textoCuadro(centrox+22,centroy-1,"Contrasena:");

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

///menu para modificar un vehiculo por dato
void modificarVehiculo(int x, int y)
{
    Patente patBusqueda;

    int pos = -1;

    cuadroMenuInstantaneo(x,y);
    MUTEXLOCK;
    gotoxy((medidasConsola.ancho/2-ANCHO/2)+1,(medidasConsola.alto/2-ALTO/2)-5);
    printf("Ingrese una patente del vehiculo a modificar:");
    MUTEXUNLOCK;
    cargaPatente(&patBusqueda);

    if(buscarPatenteArr(patBusqueda, &pos) == 1)
    {
        char opMenu;
        char opSalida, confirmacion;
        Vehiculo auxVehiculo;    //Se trabaja sobre un auxiliar para que al finalizar el menu, se puedan confirmar los cambios
        int inicioCuadroX = (medidasConsola.ancho/2) - (ANCHO/2);
        int inicioCuadroY = (medidasConsola.alto/2) - (ALTO/2);

        copiaVehiEnAux(&auxVehiculo, pos);
            cuadroMenuInstantaneo(x,y);
            mostrarVehiculo(auxVehiculo);
            Sleep(2000);
        do
        {
            cuadroMenuInstantaneo(x,y);
            MUTEXLOCK;
            gotoxy(inicioCuadroX+1,inicioCuadroY-2);
            printf("1-  Modificar la MARCA del vehiculo.");
            gotoxy(inicioCuadroX+1,inicioCuadroY);
            printf("2-  Modificar el MODELO del vehiculo.");
            gotoxy(inicioCuadroX+1,inicioCuadroY+2);
            printf("3-  Modificar el ANIO del vehiculo.");
            gotoxy(inicioCuadroX+1,inicioCuadroY+4);
            printf("4-  Modificar el KILOMETRAJE del vehiculo.");
            gotoxy(inicioCuadroX+1,inicioCuadroY+6);
            printf("5-  Modificar el PRECIO DE ALQUILER DIARIO del vehiculo.");
            gotoxy(inicioCuadroX+1,inicioCuadroY+8);
            printf("6-  Modificar el TIPO de vehiculo.");
            gotoxy(inicioCuadroX+1,inicioCuadroY+10);
            printf("7-  Modificar la DISPONIBILIDAD del vehiculo.");
            gotoxy(inicioCuadroX+1,inicioCuadroY+12);
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

void menuOpcionesDeAdmin(int x,int y)
{
    char op;

    int inicioCuadroX = (medidasConsola.ancho/2) - (ANCHO/2);
    int inicioCuadroY = (medidasConsola.alto/2) - (ALTO/2);

    MUTEXLOCK;
    gotoxy(inicioCuadroX+1,inicioCuadroY+1);
    MUTEXUNLOCK;

    do
    {
        cuadroMenuInstantaneo(x,y);
        MUTEXLOCK;
        gotoxy(inicioCuadroX+1,inicioCuadroY-4);
        printf("Ingrese el menu al cual quiere ingresar:");
        gotoxy(inicioCuadroX+1,inicioCuadroY-2);
        printf("1-  Gestion de personas.");
        gotoxy(inicioCuadroX+1,inicioCuadroY);
        printf("2-  Gestion de vehiculos.");
        gotoxy(inicioCuadroX+1,inicioCuadroY+2);
        printf("3-  Gestion de alquileres.");
        gotoxy(inicioCuadroX+1,inicioCuadroY+4);
        MUTEXUNLOCK;
        limpiarBufferEntrada();
        op = getch();

        switch(op)
        {
        case '1':
//                menuGestionPersAdmin(x,y);

            break;
        case '2':
            menuGestionVehiAdmin(x,y);
            break;
        case '3':
            menuGestionAlqAdmin(x,y);
            break;
        default:

            break;
        }
    }
    while (op != ESC);

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
    int ABM = 0;
    char op;
    leerArchiVehiculos();
    int inicioCuadroX = (medidasConsola.ancho/2) - (ANCHO/2);
    int inicioCuadroY = (medidasConsola.alto/2) - (ALTO/2);

    do
    {
        cuadroMenuInstantaneo(x,y);
        MUTEXLOCK;
        gotoxy(inicioCuadroX+1,inicioCuadroY-4);
        printf("Ingrese el ABM del archivo:");
        gotoxy(inicioCuadroX+1,inicioCuadroY-2);
        printf("1-  Agregar un nuevo vehiculo.");
        gotoxy(inicioCuadroX+1,inicioCuadroY);
        printf("2-  Mostrar los vehiculos disponibles.");
        gotoxy(inicioCuadroX+1,inicioCuadroY+2);
        printf("3-  Modificar un vehiculo.");
        gotoxy(inicioCuadroX+1,inicioCuadroY+4);
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

void menuGestionPersAdmin(int x, int y)
{
    //Modificar Usuario Propio.
    //Ver Usuarios.
    //Modificar Usuarios.
    //Dar de baja un Usuario.
}

void menuGestionAlqAdmin(int x, int y)
{
    int ABM = 0;
    char op;
    leerArchiVehiculos();
    leerArchAlquileres();
    int inicioCuadroX = (medidasConsola.ancho/2) - (ANCHO/2);
    int inicioCuadroY = (medidasConsola.alto/2) - (ALTO/2);
    int posicionArrayDinVehi;

    do
    {
        posicionArrayDinVehi=-1;
        cuadroMenuInstantaneo(x,y);
        MUTEXLOCK;
        gotoxy(inicioCuadroX+1,inicioCuadroY-1);
        printf("1-  Agregar un nuevo alquiler.");
        gotoxy(inicioCuadroX+1,inicioCuadroY+1);
        printf("2-  Mostrar todos los alquileres.");
        gotoxy(inicioCuadroX+1,inicioCuadroY+3);
        printf("3-  Calcular ingresos de alquileres.");
        gotoxy(inicioCuadroX+1,inicioCuadroY+5);
        printf("4-  Ver alquiler mas alto.");
        gotoxy(inicioCuadroX+1,inicioCuadroY+7);
        printf("5-  Ver vehiculos con menos de 5 anios.");
        gotoxy(inicioCuadroX+1,inicioCuadroY+9);
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

void menuGestionCliente(int x, int y)
{
    //funciones de visualizacion
}


///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///
///FUNCIONES DE MENU E INTERFAZ--------------------------------------------------------------------------------------------------------------------///







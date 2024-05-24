#include "menu.h"
#include "gotoxy.h"

#define ANCHO 80
#define CLEAN system("cls")
#define FALLO printf("\n");printf("   Intente nuevamente con las indicaciones dadas...")
#define CONTINUAR printf("\n   ");system("pause")
#define ERROR CLEAN;FALLO;printf("\n");CONTINUAR;
#define IZQ 75
#define DER 77


int mainMenu()
{
    if (menuInicio()==75)   //Crear Usuario
    {
        CLEAN;
        //creaUsuario();      /// <<< VINCULAR A Matias
    }
    else                    //Inicio de sesión
    {
        CLEAN;
        //ingresaUsuario();   /// <<< VINCULAR A Matias
    }

return 1;
}

int menuInicio()
{
    char opcion = 0;
    int flag = 1;
    do
    {
        CLEAN;
        cuadroMenu();
        tituloMenu();
        detallesMenu();
        opcion = getch();
        if (opcion == -32)
        {
            opcion = getch();
        }
        if (opcion == 75 || opcion == 77)
        {
            flag = 0;
        }
        else
        {
            ERROR;
        }
    }while(flag);
return opcion;
}

void cuadroMenu()
{
    printf("\n");
    printf("   %c",201);    // ╔
    for (int renglon=0; renglon<ANCHO; renglon++)
    {
        printf("%c",205);   // ═
    }
    printf("%c\n",187);     // ╗

    for (int altura=0; altura<20; altura++)
    {
        printf("   %c",186);// ║
        for (int espacio=0; espacio<ANCHO; espacio++)
        {
            printf(" ");
        }
        printf("%c\n",186); // ║
    }

    printf("   %c",200);    // ╚
    for (int renglon=0; renglon<ANCHO; renglon++)
    {
        printf("%c",205);   // ═
    }
    printf("%c\n",188);     // ╝
}

void tituloMenu()
{
    //Auto-mile
    gotoxy(27,3);
    printf("%c%c%c%c%c",218,196,196,196,191);
    gotoxy(27,4);
    printf("%c   %c\n",179,179);
    gotoxy(27,5);
    printf("%c   %c   %c%c%c                %c",179,179,218,197,191,179);
    gotoxy(27,6);
    printf("%c   %c%c  %c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c %c%c%c%c", 179, 179, 179, 179, 179, 195,196,196,191         ,195,196,196,194,196,196,191, 194, 179, 218,196,196,191);
    gotoxy(27,7);
    printf("%c%c%c%c%c%c  %c%c%c  %c     %c  %c  %c%c%c %c  %c",195,   196,196,   196,180,179,179,179,179,179             ,179,179,179,179,179, 179, 179);
    gotoxy(27,8);
    printf("%c   %c%c  %c%c%c  %c %c%c%c %c  %c  %c%c%c %c%c%c%c", 179, 179, 179, 179, 179, 179, 179, 196, 196, 196         ,179,179,179,179,179, 195,196,196,217);
    gotoxy(27,9);
    printf("%c   %c%c  %c%c%c  %c     %c  %c  %c%c%c %c", 179, 179, 179, 179, 179, 179, 179         ,179,179,179,179,179, 179, 179, 179);
    gotoxy(27,10);
    printf("%c   %c%c%c%c%c%c%c%c%c%c     %c  %c  %c%c%c%c%c%c%c", 179, 179, 192, 196, 196, 217, 179, 192, 196,196, 217         ,179,179,179,193,192,196, 192,196,196);

}

void detallesMenu()
{
    gotoxy(22,15);
    printf("Crear usuario                 Iniciar sesi%cn", 162);
    gotoxy(27,16);
    printf("(%c)                            (%c)",174, 175);
    gotoxy(43,18);
}




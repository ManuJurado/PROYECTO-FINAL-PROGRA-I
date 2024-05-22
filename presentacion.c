
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "gotoxy.h"


#define H 8 ///PARED HORIZONTAL
#define V 2 ///PARED VERTICAL
#define E 9 ///ESQUINA SUPERIOR DERECHA
#define Q 7 ///ESQUINA SUPERIOR IZQUIERDA
#define C 3 ///ESQUINA INFERIOR DERECHA
#define Z 1 ///ESQUINA INFERIOR IZQUIERDA
#define K 11
#define N 12
#define B 13
#define U 14
#define J 15
#define W 0
#define M 0
#define I 5
#define L 0
#define A 0
#define O 0
#define G 0
#define F 0
#define S 0
#define D 0

#include "presentacion.h"


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

void mostrarAutito(int matriz[6][37],int x,int y){
    int i=0;
    int j=0;
    for(j=0; j<37; j++)
    {
        printf("%c", matriz[i][j]);
        if(matriz[i][j] == 0)
        {
            printf(" ");
        }
        gotoxy(x,y);
        x=j;
        y=i;
        for(i=0; i<6; i++)
        {
            printf("%c", matriz[i][j]);
            if(matriz[i][j] == 0)
            {
                printf(" ");
            }
            gotoxy(x,y);
            x=j;
            y=i;
        }
    }
}

void printearAuto(int x, int y){
    puts("   -           __                    ");
    gotoxy(x,y);
    puts(" --          ~( \\   \\           ");
    gotoxy(x,y+1);
    puts("---   _________]_[__/_>________ ");
    gotoxy(x,y+2);
    puts("     /  ____ \\ <>     |  ____  \\ ");
    gotoxy(x,y+3);
    puts("    =\\_/ __ \\_\\_______|_/ __ \\__D");
    gotoxy(x,y+4);
    puts("________(__)_____________(__)____ ");
    gotoxy(x,y+5);
}

void borrarAuto(int x, int y){
    int i;
    for (i = 0; i < 6; i++) {
        printf("                                     ");
        gotoxy(x, y+i);
    }
}

void autoCorriendo(int x, int y,int aceleracion){
    int velocidad = 2000;
    printf("\033[0;31m");
    gotoxy(x,y);
    for(int i=0; i<80; i++)
    {
        borrarAuto(x+i-1,y);
        printearAuto(x+i, y);
        Sleep(velocidad/aceleracion);
        aceleracion+=2;
        gotoxy(x,y);
    }
}

int presentacion2(int matriz[30][70], int x, int y){
    int flag = 0;
    int i=0;
    int j=0;
    for(j=15; j<45; j++)
    {
        printf("\033[0;36m");
        x=j;
        y=i;
        if(matriz[i][j] == H)
        {
            gotoxy(x,y);
            printf("%c", 205);
        }
        if(matriz[i][j] == V)
        {
            gotoxy(x,y);
            printf("%c", 186);
        }
        if(matriz[i][j] == Q)
        {
            gotoxy(x,y);
            printf("%c", 201);
        }
        if(matriz[i][j] == Z)
        {
            gotoxy(x,y);
            printf("%c", 200);
        }
        if(matriz[i][j] == C)
        {
            gotoxy(x,y);
            printf("%c", 188);
        }
        if(matriz[i][j] == E)
        {
            gotoxy(x,y);
            printf("%c", 187);
        }
        if(matriz[i][j] == I)
        {
            gotoxy(x,y);
            printf("%c", 190);
        }
        if(matriz[i][j] == E)
        {
            gotoxy(x,y);
            printf("%c", 187);
        }
        if(matriz[i][j] == L)
        {
            gotoxy(x,y);
            printf("%c", 64);
        }
        if(matriz[i][j] == K)
        {
            gotoxy(x,y);
            printf("%c", 203);
        }
        if(matriz[i][j] == N)
        {
            gotoxy(x,y);
            printf("%c", 204);
        }
        if(matriz[i][j] == B)
        {
            gotoxy(x,y);
            printf("%c", 185);
        }
        if(matriz[i][j] == U)
        {
            gotoxy(x,y);
            printf("%c", 206);
        }
        if(matriz[i][j] == J)
        {
            gotoxy(x,y);
            printf("%c", 202);
        }
        if(matriz[i][j] == A)
        {
            gotoxy(x,y);
            printf("%c",255);
        }
        if(matriz[i][j] == F)
        {
            gotoxy(x,y);
            printf("%c",220);
        }
        if(matriz[i][j] == D)
        {
            gotoxy(x,y);
            printf(" ");
        }
        x=j;
        y=i;
        Sleep(1);
        for(i=0; i<12; i++)
        {
            printf("\033[0;36m");
            if(matriz[i][j] == H)
            {
                gotoxy(x,y);
                printf("%c", 205);
            }
            if(matriz[i][j] == V)
            {
                gotoxy(x,y);
                printf("%c", 186);
            }
            if(matriz[i][j] == Q)
            {
                gotoxy(x,y);
                printf("%c", 201);
            }
            if(matriz[i][j] == Z)
            {
                gotoxy(x,y);
                printf("%c", 200);
            }
            if(matriz[i][j] == C)
            {
                gotoxy(x,y);
                printf("%c", 188);
            }
            if(matriz[i][j] == E)
            {
                gotoxy(x,y);
                printf("%c", 187);
            }
            if(matriz[i][j] == I)
            {
                gotoxy(x,y);
                printf("%c", 190);
            }
            if(matriz[i][j] == E)
            {
                gotoxy(x,y);
                printf("%c", 187);
            }
            if(matriz[i][j] == L)
            {
                gotoxy(x,y);
                printf("%c", 64);
            }
            if(matriz[i][j] == K)
            {
                gotoxy(x,y);
                printf("%c", 203);
            }
            if(matriz[i][j] == N)
            {
                gotoxy(x,y);
                printf("%c", 204);
            }
            if(matriz[i][j] == B)
            {
                gotoxy(x,y);
                printf("%c", 185);
            }
            if(matriz[i][j] == U)
            {
                gotoxy(x,y);
                printf("%c", 206);
            }
            if(matriz[i][j] == J)
            {
                gotoxy(x,y);
                printf("%c", 202);
            }
            if(matriz[i][j] == A)
            {
                gotoxy(x,y);
                printf("%c",255);
            }
            if(matriz[i][j] == F)
            {
                gotoxy(x,y);
                printf("%c",220);
            }
            if(matriz[i][j] == D)
            {
                gotoxy(x,y);
                printf(" ");
            }
            x=j;
            y=i;
        }
    }
    flag = 1;
    return flag;
}

int presentacion3(int matriz[30][70], int x, int y){
    int flag = 0;
    int i=12;
    int j=0;
    x=j;
    y=i;
    for(j=15; j<45; j++)
    {
        printf("\033[0;31m");
        if(matriz[i][j] == H)
        {
            gotoxy(x,y);
            printf("%c", 205);
        }
        if(matriz[i][j] == V)
        {
            gotoxy(x,y);
            printf("%c", 186);
        }
        if(matriz[i][j] == Q)
        {
            gotoxy(x,y);
            printf("%c", 201);
        }
        if(matriz[i][j] == Z)
        {
            gotoxy(x,y);
            printf("%c", 200);
        }
        if(matriz[i][j] == C)
        {
            gotoxy(x,y);
            printf("%c", 188);
        }
        if(matriz[i][j] == E)
        {
            gotoxy(x,y);
            printf("%c", 187);
        }
        if(matriz[i][j] == I)
        {
            gotoxy(x,y);
            printf("%c", 190);
        }
        if(matriz[i][j] == E)
        {
            gotoxy(x,y);
            printf("%c", 187);
        }
        if(matriz[i][j] == L)
        {
            gotoxy(x,y);
            printf("%c", 64);
        }
        if(matriz[i][j] == K)
        {
            gotoxy(x,y);
            printf("%c", 203);
        }
        if(matriz[i][j] == N)
        {
            gotoxy(x,y);
            printf("%c", 204);
        }
        if(matriz[i][j] == B)
        {
            gotoxy(x,y);
            printf("%c", 185);
        }
        if(matriz[i][j] == U)
        {
            gotoxy(x,y);
            printf("%c", 206);
        }
        if(matriz[i][j] == J)
        {
            gotoxy(x,y);
            printf("%c", 202);
        }
        if(matriz[i][j] == A)
        {
            gotoxy(x,y);
            printf("%c",255);
        }
        if(matriz[i][j] == F)
        {
            gotoxy(x,y);
            printf("%c",220);
        }
        if(matriz[i][j] == D)
        {
            gotoxy(x,y);
            printf(" ");
        }
        x=j;
        y=i;

        Sleep(1);
        for(i=12; i<24; i++)
        {
            printf("\033[0;31m");
            if(matriz[i][j] == H)
            {
                gotoxy(x,y);
                printf("%c", 205);
            }
            if(matriz[i][j] == V)
            {
                gotoxy(x,y);
                printf("%c", 186);
            }
            if(matriz[i][j] == Q)
            {
                gotoxy(x,y);
                printf("%c", 201);
            }
            if(matriz[i][j] == Z)
            {
                gotoxy(x,y);
                printf("%c", 200);
            }
            if(matriz[i][j] == C)
            {
                gotoxy(x,y);
                printf("%c", 188);
            }
            if(matriz[i][j] == E)
            {
                gotoxy(x,y);
                printf("%c", 187);
            }
            if(matriz[i][j] == I)
            {
                gotoxy(x,y);
                printf("%c", 190);
            }
            if(matriz[i][j] == E)
            {
                gotoxy(x,y);
                printf("%c", 187);
            }
            if(matriz[i][j] == L)
            {
                gotoxy(x,y);
                printf("%c", 64);
            }
            if(matriz[i][j] == K)
            {
                gotoxy(x,y);
                printf("%c", 203);
            }
            if(matriz[i][j] == N)
            {
                gotoxy(x,y);
                printf("%c", 204);
            }
            if(matriz[i][j] == B)
            {
                gotoxy(x,y);
                printf("%c", 185);
            }
            if(matriz[i][j] == U)
            {
                gotoxy(x,y);
                printf("%c", 206);
            }
            if(matriz[i][j] == J)
            {
                gotoxy(x,y);
                printf("%c", 202);
            }
            if(matriz[i][j] == A)
            {
                gotoxy(x,y);
                printf("%c",255);
            }
            if(matriz[i][j] == F)
            {
                gotoxy(x,y);
                printf("%c",220);
            }
            if(matriz[i][j] == D)
            {
                gotoxy(x,y);
                printf(" ");
            }
            x=j;
            y=i;
        }
    }
    flag = 1;
    return flag;
}

int borrarPresentacion(int matriz[30][70], int x, int y){
    int flag = 0;
    int i=0;
    int j=0;
    x=j;
    y=i;

    for(j=0; j<70; j++)
    {
        if(matriz[i][j] == H)
        {
            gotoxy(x,y);
            printf(" ");
        }
        if(matriz[i][j] == V)
        {
            gotoxy(x,y);
            printf(" ");
        }
        if(matriz[i][j] == Q)
        {
            gotoxy(x,y);
            printf (" ");
        }
        if(matriz[i][j] == Z)
        {
            gotoxy(x,y);
            printf(" ");
        }
        if(matriz[i][j] == C)
        {
            gotoxy(x,y);
            printf(" ");
        }
        if(matriz[i][j] == E)
        {
            gotoxy(x,y);
            printf(" ");
        }
        if(matriz[i][j] == I)
        {
            gotoxy(x,y);
            printf(" ");
        }
        if(matriz[i][j] == E)
        {
            gotoxy(x,y);
            printf(" ");
        }
        if(matriz[i][j] == L)
        {
            gotoxy(x,y);
            printf(" ");
        }
        if(matriz[i][j] == K)
        {
            gotoxy(x,y);
            printf(" ");
        }
        if(matriz[i][j] == N)
        {
            gotoxy(x,y);
            printf(" ");
        }
        if(matriz[i][j] == B)
        {
            gotoxy(x,y);
            printf(" ");
        }
        if(matriz[i][j] == U)
        {
            gotoxy(x,y);
            printf(" ");
        }
        if(matriz[i][j] == J)
        {
            gotoxy(x,y);
            printf(" ");
        }
        if(matriz[i][j] == A)
        {
            gotoxy(x,y);
            printf(" ");
        }
        if(matriz[i][j] == F)
        {
            gotoxy(x,y);
            printf(" ");
        }
        if(matriz[i][j] == D)
        {
            gotoxy(x,y);
            printf(" ");
        }
        x=j;
        y=i;
        Sleep(1);
        for(i=0; i<30; i++)
        {
            if(matriz[i][j] == H)
            {
                gotoxy(x,y);
                printf(" ");
            }
            if(matriz[i][j] == V)
            {
                gotoxy(x,y);
                printf(" ");
            }
            if(matriz[i][j] == Q)
            {
                gotoxy(x,y);
                printf (" ");
            }
            if(matriz[i][j] == Z)
            {
                gotoxy(x,y);
                printf(" ");
            }
            if(matriz[i][j] == C)
            {
                gotoxy(x,y);
                printf(" ");
            }
            if(matriz[i][j] == E)
            {
                gotoxy(x,y);
                printf(" ");
            }
            if(matriz[i][j] == I)
            {
                gotoxy(x,y);
                printf(" ");
            }
            if(matriz[i][j] == E)
            {
                gotoxy(x,y);
                printf(" ");
            }
            if(matriz[i][j] == L)
            {
                gotoxy(x,y);
                printf(" ");
            }
            if(matriz[i][j] == K)
            {
                gotoxy(x,y);
                printf(" ");
            }
            if(matriz[i][j] == N)
            {
                gotoxy(x,y);
                printf(" ");
            }
            if(matriz[i][j] == B)
            {
                gotoxy(x,y);
                printf(" ");
            }
            if(matriz[i][j] == U)
            {
                gotoxy(x,y);
                printf(" ");
            }
            if(matriz[i][j] == J)
            {
                gotoxy(x,y);
                printf(" ");
            }
            if(matriz[i][j] == A)
            {
                gotoxy(x,y);
                printf(" ");
            }
            if(matriz[i][j] == F)
            {
                gotoxy(x,y);
                printf(" ");
            }
            if(matriz[i][j] == D)
            {
                gotoxy(x,y);
                printf(" ");
            }
            x=j;
            y=i;
        }
    }
    flag = 1;
    return flag;
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

void presentacion(){
    gotoxy(1,6);
    tipeo2("BIENVENIDO/A A AUTOMILE, SU COCHERA DE CONFIANZA\n\n",10);
    gotoxy(1,12);
    Sleep(500);
    system("pause");
}

void intro(){
    int x=0;
    int y=30;
    int color = 37;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    SMALL_RECT rect = {30, 20, 109, 54};
    SetConsoleWindowInfo(hConsole, TRUE, &rect);
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Oculta el cursor
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    int flag = 0;
    system("cls");
    gotoxy(6,10);
    Sleep(100);
    presentacion();
    system("cls");
    tipeo("Accediendo al menu principal",10);
    Sleep(1000);
    tipeo("...",300);
    Sleep(500);
    system("cls");

    while(flag!=1)
    {
        presentacion2(matriz, x, y);
        presentacion3(matriz, x, y);
        fflush(stdin);
        x=0;
        y=23;
        autoCorriendo(x,y,80);
        Sleep(3000);
        y=0;
        borrarPresentacion(matriz, x, y);
        x=0;
        y=0;
        gotoxy(x,y);
        Sleep(5500);
        printf("%d %d",x,y);
        flag = 1;
    }

}

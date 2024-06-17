#include <stdio.h>
#include <stdlib.h>

#include "presentacion.h"
#include "menu.h"

int main()
{
    maximizeAndFixConsoleWindow();
    getConsoleSize(&medidasConsola.ancho, &medidasConsola.alto);

    //intro(); /// comentar en caso de no querer hilos ni presentacion y solo necesitar el programa funcional.

    mainMenu(medidasConsola.ancho ,medidasConsola.alto-15);
}

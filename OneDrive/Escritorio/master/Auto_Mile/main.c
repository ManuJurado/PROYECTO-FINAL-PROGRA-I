#include <stdio.h>
#include <stdlib.h>

#include "data_Management.h"
#include "manejo_Archivos.h"
#include "menu.h"

int main()
{
    intro();

    mainMenu(medidasConsola.ancho ,medidasConsola.alto-15);
}

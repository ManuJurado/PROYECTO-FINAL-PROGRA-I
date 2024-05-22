#include "menu.h"

void mostrarMenu()
{
    for (int renglon=0; renglon<20; renglon++)
    {
        printf("-");
    }

    for (int altura=0; altura<20; altura++)
    {
        printf("-");
        for (int espacio=0; espacio<40; espacio++)
        {
            printf(" ");
        }
        printf("-");
    }
    for (int renglon=0; renglon<20; renglon++)
    {
        printf("-");
    }
}

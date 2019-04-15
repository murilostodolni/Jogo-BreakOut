#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "funcoes_externas.h"

extern int x_barra, y_barra;

void movimento_barra (int passos, int mx)
{
    x_barra+=passos;
    gotoxy(x_barra+mx,y_barra);
    printf("   ");
}

void printa_barra ()
{
    unsigned char barra = 254;

    textcolor(15);
    gotoxy(x_barra,y_barra);
    printf("%c%c%c%c%c%c%c%c", barra, barra, barra, barra, barra, barra, barra, barra);
}

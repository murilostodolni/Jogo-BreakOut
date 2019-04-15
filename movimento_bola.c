#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "funcoes_externas.h"

extern int x_bola, y_bola;
extern int x_direcao, y_direcao;

void bola_dos_lados (int x, int xd)
{
    x_direcao = x;
    x_bola = xd;
}

void bola_em_cima (int y, int yd)
{
    y_direcao = y;
    y_bola = yd;
}

void bola_na_barra (int xd)
{
    y_direcao = -1;
    x_direcao = xd;
    y_bola = 33;
}

void apaga_rastro_bola ()
{
    extern int x_rastro, y_rastro;

    //PARA APAGAR O RASTRO DA BOLA
    x_rastro = x_bola;
    y_rastro = y_bola;

    gotoxy(x_rastro,y_rastro); //apagando o rastro
    printf(" ");
}

void printa_bola()
{
    unsigned char bola = 79;

    //MOVIMENTO DA BOLINHA
    x_bola+=x_direcao;
    y_bola+=y_direcao;

    textcolor(14);
    gotoxy(x_bola,y_bola); //printando a bola
    printf("%c", bola);
}

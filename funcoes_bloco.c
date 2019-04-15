#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "funcoes_externas.h"
#include "matriz.h"

extern unsigned char matriz [38][50];
extern int x_bola, y_bola;
extern int x_direcao, y_direcao;
extern int x_barra, y_barra;

void em_cima_ou_baixo_e_do_lado_com_bloco (int x, int y, int xd, int yd)
{
    //vai apagar os dois blocos e voltar na mesma direção que veio
    matriz[y_bola+y][x_bola] = 0; //-> sempre vai ter isso para mudar o valor da matriz (função matrix.c)
    matriz[y_bola][x_bola+x] = 0;
    gotoxy(x_bola,y_bola+y);
    printf("%c", 0);
    gotoxy(x_bola+x,y_bola);
    printf("%c", 0);
    x_direcao = xd; //mudando a direção da bolinha
    y_direcao = yd; //mudando a direção da bolinha
}

void em_cima_ou_baixo_e_dos_dois_lados_com_blocos (int y, int yd)
{
    //vai apagar os dois blocos e voltar na mesma direção que veio
    matriz[y_bola+y][x_bola] = 0; //-> sempre vai ter isso para mudar o valor da matriz (função matrix.c)
    matriz[y_bola][x_bola+1] = 0;
    matriz[y_bola][x_bola-1] = 0;
    gotoxy(x_bola,y_bola+y);
    printf("%c", 0);
    gotoxy(x_bola+1,y_bola);
    printf("%c", 0);
    gotoxy(x_bola-1,y_bola);
    printf("%c", 0);
    y_direcao = yd; //mudando a direção da bolinha
}

void em_baixo_e_dos_dois_lados_com_blocos (int x1, int x2, int y, int yd)
{
    //vai apagar os dois blocos e voltar na mesma direção que veio
    matriz[y_bola+y][x_bola] = 0; //-> sempre vai ter isso para mudar o valor da matriz (função matrix.c)
    matriz[y_bola][x_bola+x1] = 0;
    matriz[y_bola][x_bola+x2] = 0;
    gotoxy(x_bola,y_bola+y);
    printf("%c", 0);
    gotoxy(x_bola+x1,y_bola);
    printf("%c", 0);
    gotoxy(x_bola+x2,y_bola);
    printf("%c", 0);
    y_direcao = yd; //mudando a direção da bolinha
}

void com_bloco(int y, int yd)
{
    //bloco_em_cima (x_bola, y_bola);
    matriz[y_bola+y][x_bola] = 0;
    gotoxy(x_bola,y_bola+y);
    printf("%c", 0);
    y_direcao = yd; //mudando a direção da bolinha
}

void quina_do_bloco (int x, int y, int xd, int yd)
{
    matriz[y_bola+y][x_bola+x] = 0;
    gotoxy(x_bola+x,y_bola+y);
    printf("%c", 0);
    x_direcao = xd;
    y_direcao = yd; //mudando a direção da bolinha
}

void bate_lado_bloco(int x, int xd)
{
    matriz[y_bola][x_bola+x] = 0;
    gotoxy(x_bola+x,y_bola);
    printf("%c", 0);
    x_direcao = xd;
}

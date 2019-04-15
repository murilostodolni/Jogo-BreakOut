#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#define ENTER 13
#define ESC 27
#define VELOCIDADE_FACIL 70
#define VELOCIDADE_MEDIA 50
#define VELOCIDADE_DIFICIL 30
#include "desenhos.h"
#include "menu.h"

int velocidade_jogo = 0;

void escolha_nivel()
{
    unsigned char seta;
    int comando_seta = 0;

    do
    {
        nome_breakout ();

        printf("\n\n\n\n\n\n\t\t\t\t\t\t ESCOLHA SEU NIVEL:");

        if (comando_seta == 0)
            printf("\n\n\n\n\n\t\t\t FACIL \t\t\t\t Medio \t\t\t\t Dificil \n\t\t\t*******");
        else if (comando_seta == 1)
            printf("\n\n\n\n\n\t\t\t Facil \t\t\t\t MEDIO \t\t\t\t Dificil \n\t\t\t\t\t\t\t*******");
        else if (comando_seta == 2)
            printf("\n\n\n\n\n\t\t\t Facil \t\t\t\t Medio \t\t\t\t DIFICIL \n\t\t\t\t\t\t\t\t\t\t\t*********");

        seta=getch();

        switch (seta)
        {
        case 75:
            comando_seta--;
            break;

        case 77:
            comando_seta++;
            break;

        case ENTER:
            if (comando_seta == 0)
            {
                velocidade_jogo = VELOCIDADE_FACIL;
            }
            else if (comando_seta == 1)
            {
                velocidade_jogo = VELOCIDADE_MEDIA;
            }
            else if (comando_seta == 2)
            {
                velocidade_jogo = VELOCIDADE_DIFICIL;
            }
        }

        system("cls");

        if (comando_seta>2)
            comando_seta=0;
        if (comando_seta<0)
            comando_seta=2;
        if (seta == ESC)
            menu();
    }
    while(seta!=ENTER);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include "jogo.h"
#include "pontuacao.h"
#include "velocidade_jogo.h"
#include "desenhos.h"
#include "matriz.h"
#include "jogo.h"
#include "intrucoes.h"
#include "funcoes_ranking.h"
#define ENTER 13

void menu ()
{
    unsigned char seta;
    int comando_seta = 0;

    do
    {
        nome_breakout ();

        if (comando_seta == 0)
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t JOGAR \t\t\t Instrucoes \t\t\t Ranking \t\t\t Sair \n\t\t*******");
        else if (comando_seta == 1)
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t Jogar \t\t\t INSTRUCOES \t\t\t Ranking \t\t\t Sair \n\t\t\t\t\t************");
        else if (comando_seta == 2)
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t Jogar \t\t\t Instrucoes \t\t\t RANKING \t\t\t Sair \n\t\t\t\t\t\t\t\t\t*********");
        else if (comando_seta == 3)
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t Jogar \t\t\t Instrucoes \t\t\t Ranking \t\t\t SAIR \n\t\t\t\t\t\t\t\t\t\t\t\t\t******");

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
            if (comando_seta==0)
            {
                system("cls");
                escolha_nivel();//FUNÇÃO MATRIX MUDA O VALOR DA VELOCIDADE!!!!
                matrix();
                jogo();
                continue;
            }

            else if (comando_seta==1)
            {
                system("cls");
                instrucoes ();
            }
            else if (comando_seta==2)
            {
                system("cls");
                exibir_ranking();
            }
            else if (comando_seta==3)
            {
                sair_do_jogo();
                exit(0);
            }
        }

        system("cls");

        if (comando_seta>3)
            comando_seta=0;
        if (comando_seta<0)
            comando_seta=3;
    }
    while(seta!=ENTER);
}

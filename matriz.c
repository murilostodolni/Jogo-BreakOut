#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "funcoes_externas.h"

unsigned char matriz [38][50];
extern int vidas;

// Função para a caixa onde o jogo vai rodar.
void matrix()
{
    int i, j; //i = LINHAS e j = COLUNAS

    textcolor(15);
    for (i=1; i<=38; i++)
    {
        for (j=1; j<=50; j++)
        {
            if (j==1 || j==50 || i==1 || i==36 || i==38 || (i==37 && j==20) || (i==37 && j==31))
            {
                matriz[i][j] = 219; //BORDA DO JOGO
            }
            //PRINTAR BLOCOS
            else if (i==5 || i ==6 || i==7)
            {
                if (j==1 || j==2 || j==3 || j==4 || j==47 || j==48 || j==49 || j==50)
                {
                    matriz[i][j] = 0;
                }
                else
                    matriz[i][j] = 177; //BLOCOS
            }
            else
            {
                matriz [i][j] = 0;
            }
        }
    }

    for (i=1; i<=38; i++)
    {
        for (j=1; j<=50; j++)
        {
            printf("%c", matriz [i][j]);
        }
        printf("\n");
    }

    gotoxy(2,37);
    printf(" *STATUS DO JOGO* ");
    gotoxy (22,37);
    printf("VIDAS: %d", vidas);
    gotoxy (33,37);
    printf("SCORE: 0");
}

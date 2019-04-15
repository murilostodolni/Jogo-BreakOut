#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define ENTER 13

void instrucoes()
{
    textcolor(14);

    printf("\n\n\n\t\t\t\t\t\tSeja Bem Vindo ao Breakout!\n\n\n\n\n");

    printf("Para jogar eh bem facil e intuitivo, vamos comecar!\n\n");

    printf("O objetivo do jogo eh quebrar todos os blocos espalhados pelo cenario no menor tempo e perdendo o menor numero de vidas\n");
    printf("possivel. Para isso vamos utilizar a bola e a barra presente na parte inferior da tela para rebate-la.\n\n");

    printf("Para movimentar a barra para os lados utilize as setas para Esquerda (<--) e para Direita (-->).\n");
    printf("Para pausar/retomar o jogo utilize a barra de espaco.\n");
    printf("Com o jogo pausado, pressione ESC para retornar ao Menu.\n\n");

    textcolor(12);

    printf("CUIDADO!\n");
    printf("Tente nao deixar a bola cair fora da barra, isso fara com que voce perca uma vida!\n\n\n");

    textcolor(14);
    printf("\t\t\t\t\t\t\tBoa Sorte!");

    retorna_menu();
}

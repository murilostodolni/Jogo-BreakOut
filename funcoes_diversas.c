#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define ESPACO 32
#define ESC 27
#include "funcoes_externas.h"
#include "desenhos.h"
#include "funcoes_ranking.h"
#include "menu.h"

extern int x_bola, y_bola;
extern int x_direcao, y_direcao;
extern int vidas;
extern pontos;

void perdeu_uma_vida ()
{
    unsigned char perdeu;

    vidas--;
    textcolor(4);
    gotoxy (22,37);
    printf("VIDAS: %d", vidas);
    gotoxy(x_bola, y_bola);
    printf("%c", 0);
    y_bola=29;
    y_direcao=-1;
    x_direcao=1;

    do
    {
        textcolor(15);
        gotoxy(81, 21);
        printf("                ");
        gotoxy(60, 20);
        printf("VOCE PERDEU UMA VIDA!");
        gotoxy(82, 20);
        printf("                                  ");
        gotoxy(60, 21);
        printf("CLIQUE ENTER PARA CONTINUAR");
        perdeu=getch();
    }
    while(perdeu!=13);

    gotoxy(60, 20);
    printf("                       ");
    gotoxy(60, 21);
    printf("                            ");

    gotoxy (22,37);
    printf("VIDAS: %d", vidas);
}

void retorna_menu()
{
    char tecla;
    do
    {
        gotoxy(1,25);
        textcolor(15);
        printf("PRESSIONE:\nENTER -> VOLTAR AO MENU");
        tecla=getch();
    }
    while(tecla != 13);

    system("cls");
    menu();
}

void finaliza_jogo(char opcao)
{
    extern int pontos;
    system("cls");

    if (opcao == 'p')
    {
        system("cls");
        nome_gameover();
        textcolor(2);
        printf("\n\n\t\t\t\t\t\tSUA PONTUACAO FOI: %d", pontos);
        ranking ();
        pontos = 0;
        retorna_menu();
    }
    else if (opcao == 'g')
    {
        system("cls");
        nome_voceganhou();
        ranking();
        pontos = 0;
        retorna_menu();
    }
}

void pausar_jogo()
{
    extern int vidas, pontos;
    extern unsigned char muv;

    textcolor(15);
    gotoxy(65,19);
    printf("PRESSIONE:");
    gotoxy(65,20);
    printf("BARRA DE ESPACO -> PAUSAR/CONTINUAR JOGO");
    gotoxy(65,21);
    printf("ESC -> VOLTAR AO MENU (perde as informacoes)");
    muv = getch();
    if (muv == ESPACO)
    {

        gotoxy(65,19);
        printf("            ");
        gotoxy(65,21);
        printf("                                                   ");
        gotoxy(65,20);
        printf("                                                   ");
    }
    else if (muv == ESC)
    {
        system("cls");
        pontos = 0;
        menu();
    }
}

int tamanho_string (char *nome)
{
    int i, contador;

    for(i=contador=0; nome[i]; i++)
        if (isalpha(nome[i]))
            contador++;
    return contador;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define POSITIVO 1
#define NEGATIVO -1
#define SETA_DIREITA 77
#define SETA_ESQUERDA 75
#define ESPACO 32
#include "pontuacao.h"
#include "funcoes_externas.h"
#include "funcoes_diversas.h"
#include "funcoes_bloco.h"
#include "movimento_barra.h"
#include "movimento_bola.h"
#include "velocidade_jogo.h"

extern unsigned char matriz [38][50];
extern int velocidade_jogo; //velocidade do jogo
unsigned char muv;
int vidas = 3;
int x_barra = 23, y_barra = 34; //Posição da Barra
int x_bola, y_bola; //Posição da Bola
int x_direcao, y_direcao; //Para dar direção a  bola
int x_rastro, y_rastro; //para apagar rastro da bola

void jogo ()
{
    unsigned char bloco = 177; //desenhos da TABELA ASCII
    srand(time(NULL)); //Gera uma "semente" para a função rand gerar números realmente aleatórios
    x_bola = 1 + rand() % 45;
    y_bola = 29;
    vidas = 3; // COLOCANDO OS VALORES AQUI PARA QUANDO VOLTAR A FUNÇÃO INICIAR DO ZERO!!!!
    x_direcao = 1;
    y_direcao = -1;

    while (1)
    {
        muv=0; //PARA TECLA MUV FICAR NULA NOVAMENTE QUANDO ENTRAR NO LOOP.
        printa_barra();

        if (kbhit())
        {
            muv = getch();
            if (muv == ESPACO)
                pausar_jogo();
            fflush(stdin);
        }

        if (muv == SETA_DIREITA && x_barra<41)// Movimento da BARRA PARA A DIREITA
            movimento_barra (3, -3);
        else if (muv == SETA_ESQUERDA && x_barra>3)// Movimento da BARRA PARA A ESQUERDA
            movimento_barra (-3, 8);

        if (x_bola>48) // BOLA NA PAREDE DO LADO DIREITO
            bola_dos_lados (-1, 49);
        else if (x_bola<3) // BOLA NA PAREDE DO LADO ESQUERDO
            bola_dos_lados(1, 2);
        else if (y_bola<3) // BOLA NA PAREDE DE CIMA
            bola_em_cima (1,2);
        else if (y_bola>32 && (x_bola >= x_barra && x_bola<=x_barra+3))// bola DO LADO ESQUERDO DA BARRA (esquerda pra cima)
            bola_na_barra (-1);
        else if (y_bola>32 && (x_bola >= x_barra+4 && x_bola <= x_barra+7))// bola DO LADO DIREITO DA BARRA (direita pra cima)
            bola_na_barra (1);
        else if (y_bola>33) //BOLA FORA DA BARRA
        {
            if (vidas>1)
                perdeu_uma_vida ();//diminuindo o numero de vidas
            else
                finaliza_jogo('p');
        }
        //BOLA BATENDO NOS BLOCOS
        if (x_direcao == POSITIVO && y_direcao == NEGATIVO) //DIREÇÃO: direita pra cima
        {
            if (matriz[y_bola-1][x_bola] == bloco) //se acima da bola for um bloco faz o else
            {
                if (matriz[y_bola][x_bola+1] == bloco && matriz[y_bola][x_bola-1] == bloco)
                {
                    em_cima_ou_baixo_e_dos_dois_lados_com_blocos (-1, 1);
                    pontos_bloco(3); //dois bloco destruidos
                }
                else if (matriz[y_bola][x_bola+1] == bloco) //se a posição de cima e a do lado for bloco
                {
                    em_cima_ou_baixo_e_do_lado_com_bloco (1, -1, -1, 1);
                    pontos_bloco(2); //dois bloco destruidos
                }
                else
                {
                    com_bloco(-1, 1);
                    pontos_bloco(1); //um bloco destruido
                }
            }
            //se a posição acima da bola não for um bloco, mas a posição do lado de onde não tem for um bloco
            else if (matriz[y_bola-1][x_bola] == 0 && matriz[y_bola-1][x_bola+1] == bloco)
            {
                // se a de cima dele for um bloco também vai mudar o x_direção e não o y_direção
                if (matriz[y_bola][x_bola+1] == bloco)
                {
                    bate_lado_bloco(1, -1); //bate do lado esquerdo
                    pontos_bloco(1);
                }
                else //vai apagar e voltar na mesma posição
                {
                    quina_do_bloco (1, -1, -1, 1);
                    pontos_bloco(1);
                }
            }
        }
        else if (x_direcao == NEGATIVO && y_direcao == NEGATIVO) //DIREÇÃO: esquerda pra cima (MESMO ESQUEMA DO DE CIMA)
        {
            if (matriz[y_bola-1][x_bola] == bloco)
            {
                if (matriz[y_bola][x_bola+1] == bloco && matriz[y_bola][x_bola-1] == bloco)
                {
                    em_cima_ou_baixo_e_dos_dois_lados_com_blocos (-1, 1);
                    pontos_bloco(3); //dois bloco destruidos
                }
                else if (matriz[y_bola][x_bola-1] == bloco)
                {
                    em_cima_ou_baixo_e_do_lado_com_bloco (-1, -1, 1, 1);
                    pontos_bloco(2);
                }
                else
                {
                    com_bloco(-1, 1);
                    pontos_bloco(1);
                }
            }
            else if (matriz[y_bola-1][x_bola] == 0 && matriz[y_bola-1][x_bola-1] == bloco)
            {
                if(matriz[y_bola][x_bola-1] == bloco)
                {
                    bate_lado_bloco(-1, 1); //bate do lado direito
                    pontos_bloco(1);
                }
                else
                {
                    quina_do_bloco (-1, -1, 1, 1);
                    pontos_bloco(1);
                }
            }
        }
        else if(x_direcao == NEGATIVO && y_direcao == POSITIVO) //DIREÇÃO: esquerda pra baixo
        {
            if (matriz[y_bola+1][x_bola] == bloco)
            {
                if (matriz[y_bola][x_bola-1] == bloco && matriz[y_bola][x_bola+1] == bloco)
                {
                    em_cima_ou_baixo_e_dos_dois_lados_com_blocos (1, -1);
                    pontos_bloco(3);
                }
                else if (matriz[y_bola][x_bola-1] == bloco)
                {
                    em_cima_ou_baixo_e_do_lado_com_bloco (-1, 1, 1, -1);
                    pontos_bloco(2);
                }
                else
                {
                    com_bloco(1, -1);
                    pontos_bloco(1);
                }
            }
            else if (matriz[y_bola+1][x_bola] == 0 && matriz[y_bola+1][x_bola-1] == bloco)
            {
                if (matriz[y_bola][x_bola-1] == bloco)
                {
                    bate_lado_bloco(-1, 1); //bate do lado direito
                    pontos_bloco(1);
                }
                else
                {
                    quina_do_bloco (-1, 1, 1, -1);
                    pontos_bloco(1);
                }
            }
        }
        else if (x_direcao == POSITIVO && y_direcao == POSITIVO) //DIREÇÃO: direita pra baixo
        {
            if (matriz[y_bola+1][x_bola] == bloco)
            {
                if (matriz[y_bola][x_bola+1] == bloco && matriz[y_bola][x_bola-1] == bloco)
                {
                    em_cima_ou_baixo_e_dos_dois_lados_com_blocos (1, -1);
                    pontos_bloco(3);
                }
                else if (matriz[y_bola][x_bola+1] == bloco)
                {
                    em_cima_ou_baixo_e_do_lado_com_bloco (1, 1, -1, -1);
                    pontos_bloco(2);
                }
                else
                {
                    com_bloco(1, -1);
                    pontos_bloco(1);
                }
            }
            else if (matriz[y_bola+1][x_bola] == 0 && matriz[y_bola+1][x_bola+1] == bloco)
            {
                if (matriz[y_bola][x_bola+1] == bloco)
                {
                    bate_lado_bloco(1, -1); //bate do lado esquerdo
                    pontos_bloco(1);
                }
                else
                {
                    quina_do_bloco (1, 1, -1, -1);
                    pontos_bloco(1);
                }
            }
        }
        apaga_rastro_bola();
        printa_bola();
        Sleep(velocidade_jogo);
    }
}

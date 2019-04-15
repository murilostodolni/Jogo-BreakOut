#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "funcoes_diversas.h"
#include "funcoes_externas.h"

int pontos = 0;

void pontos_bloco(int num_blocos_destruidos)
{
    static int total_blocos;
    pontos += (10*num_blocos_destruidos);
    gotoxy (33,37);
    printf("SCORE: %d", pontos);

    total_blocos+=num_blocos_destruidos;

    if (total_blocos == 126)
        finaliza_jogo('g');
}

#include <stdio.h>
#include <stdlib.h>
#include "desenhos.h"
#include "funcoes_externas.h"
#include "menu.h"

int main()
{
    hidecursor();
    system("mode con:cols=120 lines=39"); //assinatura da fun��o para limitar o tamanho do console
    inicia_nome_breakout();
    menu();
    return 0;
}

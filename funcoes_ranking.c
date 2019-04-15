#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <locale.h>
#include "funcoes_diversas.h"
#include "funcoes_externas.h"
#include "desenhos.h"
#include "funcoes_ranking.h"

extern int pontos;

void ranking ()
{
    FILE *rank;
    char nome [200];
    int tamanho, i;

    rank = fopen("ranking.txt", "a+");

    do
    {
        fflush(stdin);
        textcolor(15);
        gotoxy (50,15);
        printf("Digite seu nome: ");
        textcolor(14);
        gets(nome);
        tamanho = tamanho_string(nome);

        if (tamanho < 3 || tamanho > 7)
        {
            gotoxy(67,15);
            for (i=0; i<=tamanho; i++)
                printf(" ");
        }
    }
    while (tamanho < 3 || tamanho > 7);

    fprintf(rank,"%s\t\t%d\n", nome, pontos);

    fclose(rank);
}

void exibir_ranking()
{
    FILE *rank;
    char nome [10];
    int p;

    rank = fopen("ranking.txt", "r");

    nome_ranking ();

    printf("\n\n\n\n\n\t\t\t\t\tNOME:\t\tPONTOS:\n");
    if (rank == NULL)
    {
        textcolor(4);
        printf("\t\t\t\tJOGUE A PRIMEIRA VEZ PARA ABRIR O RANKING!");
        textcolor(15);
    }

    while (fscanf(rank, "%s\t\t%d\n", nome, &p) != EOF)
        printf("\t\t\t\t\t%s\t\t%d\n", nome, p);

    fclose(rank);

    retorna_menu();
}

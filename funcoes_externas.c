#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

//Assinatura da função GOTOXY
void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x-1,y-1
    });
}

//assinatura da função hidecursor
void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

//assinatura da função textcolor
int textcolor(int cor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
    return 0;
    /* CORES
    BLACK	0
    BLUE	1
    GREEN	2
    CYAN	3
    RED	4
    MAGENTA	5
    BROWN	6
    LIGHTGRAY	7
    DARKGRAY	8
    LIGHTBLUE	9
    LIGHTGREEN	10
    LIGHTCYAN	11
    LIGHTRED	12
    LIGHTMAGENTA	13
    YELLOW	14
    WHITE	15

    */
}

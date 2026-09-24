/*
    Autore: Edoardo Trifone
    Classe: 3 CI
    Data: 11/03/26
    Obbiettivo: Far muovere un ape in una matrice tramite input utente
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define MAXL 100
#define W 120
#define H 35

#define X_MIN 2
#define X_MAX (W - 7)
#define Y_MIN 2
#define Y_MAX (H - 6)

void spost(char *mv, int *x, int *y, char *dir);

void stampa(int x, int y, char dir)
{
    char *apedx[] = {
        " ,-. ",
        " \\ / ",
        "{|||)>",
        " / \\ ",
        " `-^ "};
    int righe_dx = 5;

    char *apesx[] = {
        "  ,-. ",
        "  \\ / ",
        "<(|||}",
        "  / \\ ",
        "  ^-` "};
    int righe_sx = 5;

    char *apeup[] = {
        "  ^  ",
        " ,-. ",
        "-| |-",
        " {|} ",
        " / \\ ",
        " `-` "};
    int righe_up = 6;

    char *apedw[] = {
        " ,-. ",
        "-| |-",
        " {|} ",
        " \\ / ",
        " `-` ",
        "  v  "};
    int righe_dw = 6;

    char **ape;
    int righe_ape;
    switch (dir)
    {
    case 'd':
        ape = apedx;
        righe_ape = righe_dx;
        break;
    case 's':
        ape = apesx;
        righe_ape = righe_sx;
        break;
    case 'a':
        ape = apeup;
        righe_ape = righe_up;
        break;
    case 'b':
        ape = apedw;
        righe_ape = righe_dw;
        break;
    default:
        ape =  apedx;
        righe_ape = righe_dx;
        break;
    }

    system("cls");
    printf("\033[2J\033[H");
    for (int r = 1; r <= H; r++) // stampo riga per riga
    {
        for (int c = 1; c <= W; c++)
        {
            if (c == x && r >= y && r < y + righe_ape) // quando sono in posizione ape stampa ape
            {
                printf("\033[1;33m%s\033[0m", ape[r - y]);
                c += strlen(ape[r - y]) - 1;
            }
            else if (r == 1 || r == H || c == 1 || c == W)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("Pos: x=%d y=%d\n", x - 2, y - 2);
    printf("Muoviti (A/S/D/B) poi invio: ");
    fflush(stdin);
}

void spost(char *mv, int *x, int *y, char *dir)
{
    for (int i = 0; i < strlen(mv); i++)
    {
        switch (mv[i])
        {
        case 'A':
            if (*y > Y_MIN)
            {
                (*y)--;
            }
            *dir = 'a';
            break;
        case 'a':
            if (*y > Y_MIN)
            {
                (*y)--;
            }
            *dir = 'a';
            break;
        case 'B':
            if (*y < Y_MAX)
            {
                (*y)++;
            }
            *dir = 'b';
            break;
        case 'b':
            if (*y < Y_MAX)
            {
                (*y)++;
            }
            *dir = 'b';
            break;
        case 'D':
            if (*x < X_MAX)
            {
                (*x)++;
            }
            *dir = 'd';
            break;
        case 'd':
            if (*x < X_MAX)
            {
                (*x)++;
            }
            *dir = 'd';
            break;
        case 'S':
            if (*x > X_MIN)
            {
                (*x)--;
            }
            *dir = 's';
            break;
        case 's':
            if (*x > X_MIN)
            {
                (*x)--;
            }
            *dir = 's';
            break;
        }
    }
}

int main()
{
    int x, y;
    char dir;
    char spos[MAXL];
    char storico[MAXL];
    storico[0] = '\0';

    while (1)
    {
        x = 2;
        y = 2;
        dir = 'd';
        spost(storico, &x, &y, &dir);
        stampa(x, y, dir);
        fgets(spos, MAXL, stdin);
        strcat(storico, spos);
    }
    return 0;
}
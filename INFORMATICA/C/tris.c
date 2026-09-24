#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 3
char board[SIZE][SIZE] = {"000", "000", "000"};

void stampa()
{
    printf("\n");
    for (int i = 0; i <= 2; i++)
    {
        for (int c = 0; c <= 2; c++)
        {
            if (board[i][c] == '0')
            {
                printf("-");
            }
            else
            {
                printf("%c", board[i][c]);
            }
        }
        printf("\n");
    }
}

void resetboard()
{
    for (int i = 0; i <= 2; i++)
    {
        for (int c = 0; c <= 2; c++)
        {
            board[c][i] = '0';
        }
    }
}

bool check_able(int x, int y)
{
    if (board[y][x] == '0')
    {
        return true;
    }
    return false;
}

bool checktris()
{
    char a, b, c;
    a = board[0][0];
    b = board[0][1];
    c = board[0][2];
    if (a == b && a == c && a != '0' && b != '0' && c != '0')
        return 1;
    a = board[0][0];
    b = board[1][0];
    c = board[2][0];
    if (a == b && a == c && a != '0' && b != '0' && c != '0')
        return 1;
    a = board[1][0];
    b = board[1][1];
    c = board[1][2];
    if (a == b && a == c && a != '0' && b != '0' && c != '0')
        return 1;
    a = board[0][1];
    b = board[1][1];
    c = board[2][1];
    if (a == b && a == c && a != '0' && b != '0' && c != '0')
        return 1;
    a = board[2][1];
    b = board[2][2];
    c = board[2][3];
    if (a == b && a == c && a != '0' && b != '0' && c != '0')
        return 1;
    a = board[0][2];
    b = board[1][2];
    c = board[2][2];
    if (a == b && a == c && a != '0' && b != '0' && c != '0')
        return 1;
    a = board[0][0];
    b = board[1][1];
    c = board[2][2];
    if (a == b && a == c && a != '0' && b != '0' && c != '0')
        return 1;
    a = board[0][2];
    b = board[1][1];
    c = board[2][0];
    if (a == b && a == c && a != '0' && b != '0' && c != '0')
        return 1;
    else
        return 0;
}

void insertplayer1()
{
    int x, y;
    bool cond = false;
    do
    {
        printf("\ndove vuoi mettere la X? (max n=3)\n");
        printf("\nx: ");
        scanf("%d", &x);
        printf("\ny: ");
        scanf("%d", &y);
        if (check_able(x, y) == false)
            printf("\nriprova");
        else
        {
            cond = true;
            board[y][x] = 'X';
        }
    } while (cond == false);
    stampa();
}

void insertplayer2()
{
    int x, y;
    bool cond = false;
    do
    {
        printf("\ndove vuoi mettere la O? (max n=3)\n");
        printf("\nx: ");
        scanf("%d", &x);
        printf("\ny: ");
        scanf("%d", &y);
        if (check_able(x, y) == false)
            printf("\nriprova");
        else
        {
            cond = true;
            board[y][x] = 'O';
        }
    } while (cond == false);
    stampa();
}

void insertbotstupid()
{
    int x, y;
    bool cond = false;
    do
    {
        x = rand() % 3;
        y = rand() % 3;
        if (check_able(x, y) == true)
        {
            cond = true;
            board[y][x] = 'O';
        }
    } while (cond == false);
    stampa();
}

int insertobotsmart(int x, int y, int move)
{
    int winner = checktris(); 
    if(winner == 1)
        return 1;
}

int main()
{
    int input, x, y;
    bool inciclo = false;
    bool trisX = false;
    bool trisO = false;
    int numcicli = 0;

    srand(time(NULL));
    resetboard();

    while (inciclo = 1)
    {
        printf("\nquesto è tris, vuoi giocare con player (1) o bot (2)?");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            do
            {
                insertplayer1();
                numcicli++;
                if (checktris() == true)
                {
                    trisX = true;
                    break;
                }

                insertplayer2();
                numcicli++;
                if (checktris() == true)
                {
                    trisO = true;
                    break;
                }

                if (numcicli == 9)
                {
                    resetboard();
                }

            } while (checktris() == false);

            if (trisO == true)
                printf("ha vinto O!");
            if (trisX == true)
                printf("ha vinto X!");
            stampa();

            break;

        case 2:
            do
            {
                insertplayer1();
                numcicli++;
                if (checktris() == true)
                {
                    trisX = true;
                    break;
                }

                insertbotstupid();
                numcicli++;
                if (checktris() == true)
                {
                    trisO = true;
                    break;
                }

            } while (checktris() == false);
            if (trisO == true)
                printf("ha vinto O!");
            if (trisX == true)
                printf("ha vinto X!");
            stampa();

            break;

        case 3:
            do
            {
                insertplayer1();
                numcicli++;
                if (checktris() == true)
                {
                    trisX = true;
                    break;
                }

                insertbotsmart();
                numcicli++;
                if (checktris() == true)
                {
                    trisO = true;
                    break;
                }

            } while (checktris() == false);
            if (trisO == true)
                printf("ha vinto O!");
            if (trisX == true)
                printf("ha vinto X!");
            stampa();
        }
    }
    printf("\nfine");
}

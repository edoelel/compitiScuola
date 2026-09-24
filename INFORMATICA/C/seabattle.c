/*
    Autore: Edoardo Trifone
    Classe: 3 CI
    Data: 11/03/26
    Obbiettivo: Battaglia navale in c
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define MAXR 10
#define ORIZ 0
#define VERT 1
#define LIMITE 9

void titolo()
{
    printf("__________    ___________________________.____     ___________ _________ ___ ___ ._____________ \n");
    printf("\\______   \\  /  _  \\__    ___/\\__    ___/|    |    \\_   _____//   _____//   |   \\|   \\______   \\\n");
    printf(" |    |  _/ /  /_\\  \\|    |     |    |   |    |     |    __)_ \\_____  \\/    ~    \\   ||     ___/\n");
    printf(" |    |   \\/    |    \\    |     |    |   |    |___  |        \\/        \\    Y    /   ||    |    \n");
    printf(" |______  /\\____|__  /____|     |____|   |_______ \\/_______  /_______  /\\___|_  /|___||____|    \n");
    printf("        \\/         \\/                            \\/        \\/        \\/       \\/                \n");
}

void initmatrice(int matrice[MAXR][MAXR])
{
    int i;
    int j;
    for (i = 0; i < MAXR; i++)
    {
        for (j = 0; j < MAXR; j++)
        {
            matrice[i][j] = 0;
        }
    }
}

void stampaMatr(int matrice[MAXR][MAXR])
{
    printf("     ");
    for (int i = 0; i < MAXR; i++)
    {
        printf("%c  ", 'A'+i);
    }
    printf("\n\n");   
    for (int i = 0; i < MAXR; i++)
    {
        printf("%2d  ", i);
        for (int j = 0; j < MAXR; j++)
        {
            printf("%2d ", matrice[i][j]);
        }
        printf("\n");
    }
}

void genera_nave2(int matrice[MAXR][MAXR])
{
    int orientamento, x, y;
    orientamento = rand() % 2;
    do
    {
        x = 0;
        y = 0;
        x = rand() % MAXR;
        y = rand() % MAXR;
        matrice[y][x] = 2;
        if (orientamento == ORIZ)
        {
            x++;
            if (x > LIMITE || matrice[y][x] != 0)
            {
                x--;
                matrice[y][x] = 0;
                x++;
                continue;
            }
        }
        else if (orientamento == VERT)
        {
            y++;
            if (y > LIMITE || matrice[y][x] != 0)
            {
                y--;
                matrice[y][x] = 0;
                y++;
                continue;
            }
        }
        matrice[y][x] = 2;
    } while (x > LIMITE || y > LIMITE);
}

void genera_navtqc(int matrice[MAXR][MAXR])
{
    int orientamento, x, y, i, j, k = 0, flag = 0;
    for (int n = 3; n <= 5; n++)
    {
        do
        {
            if (k != 0)
            {
                for (i = 0; i < MAXR; i++)
                {
                    for (j = 0; j < MAXR; j++)
                    {
                        if (matrice[i][j] == n)
                        {
                            matrice[i][j] = 0;
                        }
                    }
                }
            }
            x = 0;
            y = 0;
            orientamento = rand() % 2;
            x = rand() % MAXR;
            y = rand() % MAXR;
            matrice[y][x] = n;
            if (orientamento == ORIZ && x + n - 1 <= LIMITE)
            {
                for (i = 0; i < n - 1; i++)
                {
                    x++;
                    matrice[y][x] = n;
                }
                flag = 1;
            }
            else if (orientamento == VERT && y + n - 1 <= LIMITE)
            {
                for (i = 0; i < n - 1; i++)
                {
                    y++;
                    matrice[y][x] = n;
                }
                flag = 1;
            }
            k++;
        } while (flag == 0);
    }
}

void genera_navi(int matr[MAXR][MAXR])
{
    int flag = 0, ct = 0, cth = 0, cf = 0, cfi = 0, i, j;
    do
    {
        ct = 0, cth = 0, cf = 0, cfi = 0;
        initmatrice(matr);
        for (i = 0; i < 2; i++)
        {
            genera_nave2(matr);
        }
        genera_navtqc(matr);
        for (i = 0; i < MAXR; i++)
        {
            for (j = 0; j < MAXR; j++)
            {
                switch (matr[i][j])
                {
                case 2:
                    ct++;
                    break;
                case 3:
                    cth++;
                    break;
                case 4:
                    cf++;
                    break;
                case 5:
                    cfi++;
                    break;
                default:
                    break;
                }
            }
        }
        if (ct == 2 && cth == 3 && cf == 4 && cfi == 5)
        {
            flag = 1;
        }
    } while (flag == 0);
}

void colpo1(int matr[MAXR][MAXR], int x, int y, int *ct1, int *cth1, int *cf1, int *cfi1, int *tiro) // COntrollo e setto i colpi del giocatore 1
{
    switch (matr[y][x])
    {
    case 2:
        matr[y][x] = 1;
        *(tiro) = 1;
        *(ct1)++;
        printf("Hai colpito una nave!\n");
        break;
    case 3:
        matr[y][x] = 1;
        *(tiro) = 1;
        *(cth1)++;
        if (*cth1 == 3)
        {
            printf("Hai affondato la Nave da quattro\n");
        }
        else
        {
            printf("Hai colpito una nave!\n");
        }
        break;
    case 4:
        matr[y][x] = 1;
        *(tiro) = 1;
        *(cf1)++;
        if (*cf1 == 4)
        {
            printf("Hai affondato la Nave da quattro\n");
        }
        else
        {
            printf("Hai colpito una nave!\n");
        }
        break;
    case 5:
        matr[y][x] = 1;
        *(tiro) = 1;
        *(cfi1)++;
        if (*cfi1 == 5)
        {
            printf("Hai affondato la Nave da quattro\n");
        }
        else
        {
            printf("Hai colpito una nave!\n");
        }
        break;
    default:
        *(tiro) = 0;
        matr[y][x] = -1;
        break;
    }
}

void colpo2(int matr[MAXR][MAXR], int x, int y, int *ct2, int *cth2, int *cf2, int *cfi2, int *tiro) // COntrollo e setto i colpi del giocatore 2
{
    switch (matr[y][x])
    {
    case 2:
        matr[y][x] = 1;
        *(tiro) = 1;
        *(ct2)++;
        printf("Hai colpito una nave!\n");
        break;
    case 3:
        matr[y][x] = 1;
        *(tiro) = 1;
        *(cth2)++;
        if (*cth2 == 3)
        {
            printf("Hai affondato la Nave da tre\n");
        }
        else
        {
            printf("Hai colpito una nave!\n");
        }
        break;
    case 4:
        matr[y][x] = 1;
        *(tiro) = 1;
        *(cf2)++;
        if (*cf2 == 4)
        {
            printf("Hai affondato la Nave da quattro\n");
        }
        else
        {
            printf("Hai colpito una nave!\n");
        }
        break;
    case 5:
        matr[y][x] = 1;
        *(tiro) = 1;
        *(cfi2)++;
        if (*cfi2 == 5)
        {
            printf("Hai affondato la Nave da cinque\n");
        }
        else
        {
            printf("Hai colpito una nave!\n");
        }
        break;
    default:
        *(tiro) = 0;
        matr[y][x] = -1;
        break;
    }
}

void controllo(int matr[MAXR][MAXR], int *win)
{
    for (int i = 0; i < MAXR; i++)
    {
        for (int j = 0; j < MAXR; j++)
        {
            if (matr[i][j] == 1 || matr[i][j] == 0 || matr[i][j] == -1)
            {
                *(win) = 1;
            }
            else
            {
                *(win) = 0;
            }
        }
        printf("\n");
    }
}

int main()
{
    int i = 0, win = 0, mod = 0, x = 0, y = 0, ct1 = 0, cth1 = 0, cf1 = 0, cfi1 = 0, tiro = 0, ct2 = 0, cth2 = 0, cf2 = 0, cfi2 = 0;
    srand(time(NULL));
    int matrice1[MAXR][MAXR];
    int matrice2[MAXR][MAXR];
    titolo();
    printf("\n\n");
    printf("Quale modalita' di gioco vuoi scegliere:\n1.. vs BOT\n2.. vs 1 vs 1\n");
    do
    {
        scanf("%d", &mod);
    } while (mod != 1 && mod != 2);
    genera_navi(matrice1);
    genera_navi(matrice2);
    if (mod == 1)
    {
        do
        {

        } while (win == 0);
    }
    else if (mod == 2)
    {
        do
        {
            do
            {
                stampaMatr(matrice2);
                printf("Turno giocatore 1\n");
                printf("Cosa vuoi colpire(Numeri da 0 a 9, prima x e poi y con uno spazio): ");
                do
                {
                    scanf("%d %d", &x, &y);
                } while (x > LIMITE || y > LIMITE);

                colpo1(matrice2, x, y, &ct1, &cth1, &cf1, &cfi1, &tiro);
                controllo(matrice2, &win);
            } while (tiro == 1);
            do
            {
                stampaMatr(matrice1);
                printf("Turno giocatore 2\n");
                printf("Cosa vuoi colpire(Numeri da 0 a 9, prima x e poi y con uno spazio): ");
                do
                {
                    scanf("%d %d", &x, &y);
                }while (x > LIMITE || y > LIMITE);
                colpo2(matrice1, x, y, &ct2, &cth2, &cf2, &cfi2, &tiro);
                controllo(matrice1, &win);
            } while (tiro == 1);
        } while (win == 0);
    }
}
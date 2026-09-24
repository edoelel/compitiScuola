#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#define usleep(usec) Sleep((usec) / 1000)
#else
#include <unistd.h>
#endif

#define MAXR 10
#define MAXCLM 15

float mediam(int matrice[MAXR][MAXCLM], int len){
    float somma = 0;
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 10; j++){
            somma += matrice[j][i];
        }
    }
    float media;
    media = somma / len;
    return media;
}

int sommam(int matrice[MAXR][MAXCLM]){
    int somma = 0;
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 10; j++){
            somma += matrice[j][i];
        }
    }
    return somma;
}

int main(){
    srand(time(NULL));
    int matrix[MAXR][MAXCLM];
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 10; j++){
            matrix[j][i] = rand()% 101;
        }
    }
    /*for(int i = 0; i < 15; i++){
        for(int j = 0; j < 10; j++){
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }*/
   int len = sizeof(matrix) / 4;
    printf("La somma di tutti gli elementi della tua matrice e': %d\n", sommam(matrix));
    printf("La media di tutti gli elementi della tua matrice e': %g", mediam(matrix, len));
    return 0;
}
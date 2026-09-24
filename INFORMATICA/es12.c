#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#define usleep(usec) Sleep((usec) / 1000)
#else
#include <unistd.h>
#endif
void stVoti(char nomi[5][70], int voti[5]){
    for(int i=0; i<4; i++){
        if(voti[i]>5){
        printf("%s: ", nomi[i]);
        printf("%d\n", voti[i]);
        }
    }
}

int main(){
    char scol[5][70] = {"Trifone", "Luchetta", "Golisano", "Lavista"};
    int voti[5] = {6,7,9,1};
    stVoti(scol, voti);
}
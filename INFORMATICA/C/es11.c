#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#define usleep(usec) Sleep((usec) / 1000)
#else
#include <unistd.h>
#endif

void stCol(char nomi[30][70]){
    for(int i = 0; i < 8; i++){
        for(int k = 0; k < 4; k++){
            if(nomi[k][i]!='/0'){
                printf("%c ", nomi[k][i]);
            }
        }
        printf("\n");
    }
}
int main(){
    char scol[30][70] = {"Edoardo", "Gabriele", "Fabio", "Leo"};
    stCol(scol);
}
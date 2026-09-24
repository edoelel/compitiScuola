#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>



int main() {
    time_t rawtime = time(NULL);
    struct tm *info = localtime(&rawtime); 
    int mese = (*info).tm_mon+1;
    int giorno = (*info).tm_mday;
    int anno = (*info).tm_year + 1900;
    printf("l'anno e' il %d", anno);
    return 0;
}
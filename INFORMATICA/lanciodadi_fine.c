/*
Autore: Edoardo Trifone
Data: 14/01/25
Obbiettivo: Capire cosa c'è dietro la funzione rand() attraverso il lancio di dadi che tramite un istogramma mostra graficamente
i dati raccolti dal lancio dei dadi
*/



#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int dado(int numdadi) {  
    int i;
    for(i=0; i<numdadi; i++){
    return rand() % 6 + 1;
    }
}

int maxarr(int arr[], int lunghezza)
{
    int i;
    int max=0;
    max=arr[0];
    for(i=0; i!=lunghezza;i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
            }
        }
    return max;
}

void stampa_istogramma(int array[], int lunghezza, int max){
    int i, r;
    for(r=max; r > 0; r--){
        printf("%2d", r);
        for(i = 0; i < lunghezza; i++){
            if(array[i] == r){
                printf(" _ ");
            }else if(array[i] > r ){
                printf("| |");
            }else {
                printf("   ");
            }
            
        }
        printf("\n");
    }
    printf("   1  2  3  4  5  6 ");
}


int main(){
    srand(time(NULL));
    int risdadi[6] = {0};
    int volte, numdadi, max, len, k;
    printf("Quanti dadi volte lanciare alla volta (max 2): ");
    scanf("%d", & numdadi);
    while(numdadi>2){
        system("cls");
        printf("Quanti dadi volte lanciare alla volta (max 2): ");
        scanf("%d", & numdadi);
    }
    printf("Quante volte vuoi lanciare i dadi: ");
    scanf("%d", & volte);
    int dadi[volte];
    for(k = 0; k < volte; k++){
        dadi[k] = dado(numdadi);
        switch (dadi[k])
        {
        case 1:
            risdadi[0]++;
            break;
        case 2:
            risdadi[1]++;
            break;
        case 3:
            risdadi[2]++;
            break;
        case 4:
            risdadi[3]++;
            break;
        case 5:
            risdadi[4]++;
            break;
        case 6:
            risdadi[5]++;
            break;
        
        default:
            break;
        }
    }
    len = sizeof(risdadi) / sizeof(risdadi[0]);
    max = maxarr(risdadi, len);
    stampa_istogramma(risdadi, len, max);
}
/*
    Prova 1 10 coppie dadi: 
    max 1 = 4 volte
    Prova 2 10 coppie dadi: 
    max 2 = 3 volte
    Prova 1 50 coppie dadi: 
    max 1 = 15 volte
    Prova 2 50 coppie dadi: 
    max 2 = 11 volte
    Prova 3 50 coppie dadi: 
    max 3 = 11 volte
    Prova 4 50 coppie dadi: 
    max 2 = 11 volte
    Prova 1 100 coppie dadi: 
    max 5 = 20 volte
    Prova 2 100 coppie dadi: 
    max 3 = 25 volte
    La funzione rand time da sempre risultati divres per cui potrebbe davvero riuscire a salvare i risultati tramite compilatore 
    La realtà è che importando la libreria time e impostando il seme su time null il compilatore prende i data da ora e data 
    così da cambiare ogni volta risultati
*/
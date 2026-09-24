#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#ifdef _WIN32 //funzione che mi serve per forzare windows.h e unistd perchè il mio compilatore ha deciso di non farli funzionare
#include <windows.h>
#define usleep(usec) Sleep((usec) / 1000)
#else
#include <unistd.h>
#endif
void pallotto(){
        printf("                 _______\n");
    printf("               /         \\\n");
    printf("              /    ___    \\\n");
    printf("             |    /   \\    |\n");
    printf("             |   |   8   |   |\n");
    printf("              \\    \\___/    /\n");
    printf("               \\___________/\n");
}

int main(){
    srand(time(NULL));
    int random;
    while(1){
        system("cls");
        pallotto();
        printf("Fammi una domanda e la palla magica ti rispondera': ");
        getchar();
        getchar();
        while (getchar() != '\n'); 
        random = rand() % 20;
          switch(random) {
        case 1:
            printf("Per quanto posso vedere, si'\n");
            break;
        case 2:
            printf("E' certo\n");
            break;
        case 3:
            printf("E' decisamente cosi'\n");
            break;
        case 4:
            printf("Molto probabilmente\n");
            break;
        case 5:
            printf("Le prospettive sono buone\n");
            break;
        case 6:
            printf("I segni indicano di si'\n");
            break;
        case 7:
            printf("Senza alcun dubbio\n");
            break;
        case 8:
            printf("Si'\n");
            break;
        case 9:
            printf("Si', senza dubbio\n");
            break;
        case 10:
            printf("Ci puoi contare\n");
            break;
        case 11:
            printf("E' difficile rispondere, prova di nuovo\n");
            break;
        case 12:
            printf("Rifai la domanda piu' tardi\n");
            break;
        case 13:
            printf("Meglio non risponderti adesso\n");
            break;
        case 14:
            printf("Non posso predirlo ora\n");
            break;
        case 15:
            printf("Concentrati e rifai la domanda\n");
            break;
        case 16:
            printf("Non ci contare\n");
            break;
        case 17:
            printf("La mia risposta è no\n");
            break;
        case 18:
            printf("Le mie fonti dicono di no\n");
            break;
        case 19:
            printf("Le prospettive non sono buone\n");
            break;
        case 20:
            printf("Molto incerto\n");
            break;
        default:
            printf("Errore\n");
    }
    usleep(5000000);
    }
    return 0;
}
/*Classe: 3CI
  Autore: Edoardo Trifone
  Data: 28/03/2023
  Obbiettivo: Simulazione di un distributore automatico con erogazione di resto
  
*/
#include <stdio.h>
#include <unistd.h>

void menu(){
    printf("                                  Scegli una tra le opzioni digitando il numero corrispondente\n");
    printf("                                                 |1) Caffe                  |\n");
    printf("                                                 |--------------------------|\n");
    printf("                                                 |2) Bibita                 |\n");
    printf("                                                 |--------------------------|\n");
    printf("                                                 |3) Merendina              |\n");
    printf("                                                 |--------------------------|\n");
    printf("                                                 |4) Termina                |\n");
    printf("                                                 |--------------------------|\n");
}

void resto(float credito)
{
    float moneta[] = {100, 50, 20, 10, 5, 2, 1, 0.50, 0.20, 0.10, 0.05};
    int i = 0;

    while (credito > 0) // Finché il credito è maggiore di 0 quindi diverso da 0
    {
        if (credito >= moneta[i]) // Controlla se il credito é maggiore cosi riesco a capire se posso erogare la moneta
        {
            credito -= moneta[i]; // Sottrai il valore della moneta dal credito scelta tramite l'indice i
            printf("Erogazione moneta da %.2f\n", moneta[i]); 
        }
        else
        {
            i++;
        }
    }
}


int main()
{
    float p1=(0.5);//selezione dal disributore
    float p2=2;//selezione dal disributore
    float p3=3;//selezione dal disributore
    int ut=0;//input utente
    float cr;//credito dell'utente
    printf("Inserisci i soldi per comprare qualcosa\n");
    scanf("%f", & cr);
    while(ut!=4) //finche l'utente non sceglie di terminare
    {
        menu();
        scanf("%d", &ut);
        
        switch(ut){
            case 1:
                cr= cr-p1;
                printf("Erogazione Caffe");
                fflush(stdout); //forza la stampa immediata di usleep
                usleep(300000);
                printf(".");
                fflush(stdout);
                usleep(300000);
                printf(".");
                fflush(stdout);
                usleep(300000);
                printf(".");
                fflush(stdout);
                usleep(600000);
                printf("\nCaffe erogato\nIl tuo credito e' stato aggiornato %.2f \n", cr); //uso .2f cosi non mi stampa tutte le cifre decimali
                break;
            case 2:
                cr= cr-p2;
                printf("Erogazione bibita");
                fflush(stdout);
                usleep(300000);
                printf(".");
                fflush(stdout);
                usleep(300000);
                printf(".");
                fflush(stdout);
                usleep(300000);
                printf(".");
                fflush(stdout);
                usleep(600000);
                printf("\nBibita erogata\nIl tuo credito e' stato aggiornato %.2f \n", cr); 
                break;
            case 3:
                cr= cr-p3;
                printf("Erogazione Merendina");
                fflush(stdout);
                usleep(300000);
                printf(".");
                fflush(stdout);
                usleep(300000);
                printf(".");
                fflush(stdout);
                usleep(300000);
                printf(".");
                fflush(stdout);
                usleep(600000);
                printf("\nMerendina erogata\nIl tuo credito e' stato aggiornato %.2f \n", cr); 
                break;
            case 4:
                printf("Erogo il resto");
                fflush(stdout);
                usleep(300000);
                printf(".");
                fflush(stdout);
                usleep(300000);
                printf(".");
                fflush(stdout);
                usleep(300000);
                printf(".\n");
                fflush(stdout);
                usleep(600000);
                resto(cr); 
                break;
            default:
                printf("Non hai inserito una tra le opzioni \n");

        }
    }
    
}
/*
obiettivo: creare il gioco dell'oca per due giocatori in c
Autori: Sara Contu, Edoardo Trifone
CONSEGNA: Ad ogni turno, verrÃ  chiesto all'utente di lanciare il dado, che generera'  un numero (casuale) tra 1 e 6.
L'utente dovra'  avanzare sul tabellone, (composto da 20 caselle), per il numero di volte indicate sul dado.
In alcune caselle pero', potrebbe trovare dei vantaggi o degli svantaggi, i quali lo costringeranno ad avanzare o tornare indietro
di qualche casella.
Se l'utente, arrivato verso la fine del tabellone, tira il dado e ottiene un numero con il quale sfora il numero di arrivo (20)
sara' costretto a tornare indietro, facendo la posizione in cui si trova il giocatore - il numero delle caselle.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32 //funzione che mi serve per forzare windows.h e unistd perchè il mio compilatore ha deciso di non farli funzionare
#include <windows.h>
#define usleep(usec) Sleep((usec) / 1000)
#else
#include <unistd.h>
#endif

void clear_screen() {   //funzione per pulire lo schermo(copiata da internet)
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J\033[H");
    fflush(stdout);
#endif
}

void puntini(){ //funzione per fare i puntini di caricamento 
    for(int i=0;i<3;i++) //Il ciclo stampa 1 puntino per ogni giro.
    {
        printf(". ");
        fflush(stdout); // .(mezzo sec)-->..(mezzo sec)-->...
        usleep(500000); //Crea l'effetto animato mettendo in pausa il programma per 0.5 sec.
    }
    printf("\n");
}

void titolo(){// titolo in ascii art
    printf("  _______  __    ______     ______   ______       _______   _______  __       __       __   ______     ______      ___      \n");
    printf(" /  _____||  |  /  __  \\   /      | /  __  \\     |       \\ |   ____||  |     |  |     (_ ) /  __  \\   /      |    /   \\     \n");
    printf("|  |  __  |  | |  |  |  | |  ,----'|  |  |  |    |  .--.  ||  |__   |  |     |  |      |/ |  |  |  | |  ,----'   /  ^  \\    \n");
    printf("|  | |_ | |  | |  |  |  | |  |     |  |  |  |    |  |  |  ||   __|  |  |     |  |         |  |  |  | |  |       /  /_\\  \\   \n");
    printf("|  |__| | |  | |  `--'  | |  `----.|  `--'  |    |  '--'  ||  |____ |  `----.|  `----.    |  `--'  | |  `----. /  _____  \\  \n");
    printf(" \\______| |__|  \\______/   \\______| \\______/     |_______/ |_______||_______||_______|     \\______/   \\______|/__/     \\__\\ \n");

}
void vit1(){    // fine1 in ascii art
    printf("  _______  __      __    __       ___         ____    ____  __  .__   __. .___________.  ______    __  \n");
    printf(" /  _____|/_ |    |  |  |  |     /   \\        \\   \\  /   / |  | |  \\ |  | |           | /  __  \\  |  | \n");
    printf("|  |  __   | |    |  |__|  |    /  ^  \\        \\   \\/   /  |  | |   \\|  | `---|  |----`|  |  |  | |  | \n");
    printf("|  | |_ |  | |    |   __   |   /  /_\\  \\        \\      /   |  | |  . `  |     |  |     |  |  |  | |  | \n");
    printf("|  |__| |  | |    |  |  |  |  /  _____  \\        \\    /    |  | |  |\\   |     |  |     |  `--'  | |__| \n");
    printf(" \\______|  |_|    |__|  |__| /__/     \\__\\        \\__/     |__| |__| \\__|     |__|      \\______/  (__) \n");

}

void vit2(){    // fine2 in ascii art
    printf("  _______  ___       __    __       ___         ____    ____  __  .__   __. .___________.  ______    __  \n");
    printf(" /  _____||__ \\     |  |  |  |     /   \\        \\   \\  /   / |  | |  \\ |  | |           | /  __  \\  |  | \n");
    printf("|  |  __     ) |    |  |__|  |    /  ^  \\        \\   \\/   /  |  | |   \\|  | `---|  |----`|  |  |  | |  | \n");
    printf("|  | |_ |   / /     |   __   |   /  /_\\  \\        \\      /   |  | |  . `  |     |  |     |  |  |  | |  | \n");
    printf("|  |__| |  / /_     |  |  |  |  /  _____  \\        \\    /    |  | |  |\\   |     |  |     |  `--'  | |__| \n");
    printf(" \\______| |____|    |__|  |__| /__/     \\__\\        \\__/     |__| |__| \\__|     |__|      \\______/  (__) \n");
}
int dado() {    //funzione per il lancio del dado
    srand(time(NULL)); //comp genera num != ogni volta che si avvia il programma 
    return rand() % 6 + 1; //genera num tra 1 e 6.
}



void inizializza_pv(int tab[]){  //funzione che dichiara la posizione di 2 vant/svant.
    int v1, v2, p1, p2;
    srand(time(NULL));
    do
    {
        //TROVO LA POSIZIONE DEL VANTAGGIO/SVANTAGGIO NELL'ARRAY (genera 4 posiz casuali).
        v1 = rand() % 20;
        v2 = rand() % 20;
        p1 = rand() % 20;
        p2 = rand() % 20;
    }
    
    while(v1 == v2 || p1 == p2|| v1 == p1 || v1 == p2 || v2 == p1 || v2 == p2 
           || v1 == 0 || v2 == 0 || p1 == 0 || p2 == 0 || v1 == 19 
           || v2 == 19 || p1 == 19 || p2 == 19 );       
    //per evitare che le caselle speciali coincidano tra loro o siano nella posizione iniziale (0) o quella di arrivo (19).
   
    tab[v1] = 1;        //salto
    tab[v2] = 2;        //ali
    tab[p1] = -1;       //prigione
    tab[p2] = -2;       //labirinto
}


void stampa_tabella(int tab[], int g1_pos, int g2_pos) {// funzione per stampare il tabellone
    // per le ascii art ho inserito un prompt su chat gpt siccome non siamo abbastanza creativi (poi le abbiamo modificate un po' a mano)
    char *papera_g1[6] = {
        "\033[31m      ___________ \033[0m",
    "\033[31m     |%2d   __    |\033[0m",
    "\033[31m     |  __( o)>  |\033[0m",
    "\033[31m     |  \\ <_. )  |\033[0m",
    "\033[31m     |   `---'   |\033[0m",
    "\033[31m     |___________|\033[0m"
    };// uso i char per creare le caselle grafiche cosi' da poter stampare riga per riga il tabellone

    char *casella_papera_g2[6] = {
    "\033[36m      ___________ \033[0m",
    "\033[36m     |%2d   __    |\033[0m",
    "\033[36m     |  __( o)>  |\033[0m",
    "\033[36m     |  \\ <_. )  |\033[0m",
    "\033[36m     |   `---'   |\033[0m",
    "\033[36m     |___________|\033[0m"
    };

    char *casella_vuota[6] = {
        "      ___________ ",
        "     |%2d         |",
        "     |           |",
        "     |           |",
        "     |           |",
        "     |___________|"
    };

    char *casella_salto[6] = {
        "      ___________ ",
        "     |%2d  _      |",
        "     |     / |\\  |",
        "     |   *---'   |",
        "     |   SALTO   |",
        "     |___________|"
    };

    char *casella_ali[6] = {
        "      ___________ ",
        "     |%2d_    _   |",
        "     | ( \\  / )  |",
        "     |  \\_)(_ /  |",
        "     |    ALI    |",
        "     |___________|"
    };

    char *casella_prigione[6] = {
        "      ___________ ",
        "     |%2d _  _  _ |",
        "     | | || || | |",
        "     | |_||_||_| |",
        "     |   CAGE    |",
        "     |___________|"
    };

    char *casella_labirinto[6] = {
        "      ___________ ",
        "     |%2d  |_|__  |",
        "     |   _|  |   |",
        "     |  |_|__|   |",
        "     | LABIRINTO |",
        "     |___________|"
    };
    
    char *casella_papera_g1g2[6] = {
    "\033[35m      _______________________ \033[0m",
    "\033[35m     |%2d   __         __     |\033[0m",
    "\033[35m     | ___( o)>   ___( o)>   |\033[0m",
    "\033[35m     |  \\ <_. )    \\ <_. )   |\033[0m",
    "\033[35m     |   `---'      `---'    |\033[0m",
    "\033[35m     |_______________________|\033[0m"
    };


    for (int base = 0; base < 20; base += 4) {// ciclo per stampare 4 caselle alla volta

    for (int r = 0; r < 6; r++) {// ciclo per stampare riga per riga

        for (int i = base; i < base + 4; i++) {// ciclo per stampare le 4 caselle

            if (i == g1_pos && i == g2_pos)
                printf(casella_papera_g1g2[r], i+1);//stampo la prima riga(r) di ogni casella poi passo alla riga successiva
            else if (i == g1_pos)
                printf(papera_g1[r], i+1);
            else if (i == g2_pos)
                printf(casella_papera_g2[r], i+1);
            else {
                switch (tab[i]) {
                    case 1:  
                    printf(casella_salto[r], i+1); 
                    break;
                    case 2:  
                    printf(casella_ali[r], i+1);
                    break;
                    case -1: 
                    printf(casella_prigione[r], i+1); 
                    break;
                    case -2: 
                    printf(casella_labirinto[r], i+1); 
                    break;
                    default: 
                    printf(casella_vuota[r], i+1); 
                    break;
                }
            }
        }

        printf("\n"); 
    }

    printf("\n"); 
}
}




int main(){
    
    int tabellone[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //crea il tabellone di 20 caselle  
    int giocatore1_pos = 0; //posizione iniziale dei giocatori (la pos Ã¨ l'indice dell'array NON casella visuale che parte da 1 )
    int giocatore2_pos = 0;
    int turno=0; 
    int tiro1; //memorizza il valore del dado
    int tiro2;
    inizializza_pv(tabellone); //prepara le caselle speciali
    do
    {   
        if (turno==0){
        clear_screen();
        titolo(); //stampa il titolo del gioco
        stampa_tabella(tabellone, giocatore1_pos, giocatore2_pos); //mostra il tabellone iniziale 
        }
        printf("\nTurno del giocatore 1. Premi invio per tirare il dado.");
        getchar();
        puntini();
        clear_screen();
        tiro1 = dado();
        giocatore1_pos += tiro1;
        if(giocatore1_pos == 19) //gestisco la vittoria
        {   
            clear_screen();
            titolo();
            stampa_tabella(tabellone, giocatore1_pos, giocatore2_pos);
            vit1();
            goto fine;  // uso il goto per uscire dal ciclo do while in caso di vittoria e non eseguire il turno del secondo giocatore
        }
        else if (giocatore1_pos > 19)   //gestisco il superamento della casella 20
        {
            giocatore1_pos = 19 - (giocatore1_pos - 19);
            clear_screen();
            titolo();
            stampa_tabella(tabellone, giocatore1_pos, giocatore2_pos);
            printf("Hai tirato un %d\n", tiro1);
            printf("Posizione giocatore 1: %d\n", giocatore1_pos + 1);
        }
        else
        {
            switch(tabellone[giocatore1_pos]){  //gestisco le caselle speciali. RIMBALZO
                case 1:
                    giocatore1_pos += 2;
                    if(giocatore1_pos > 19)
                    {
                        giocatore1_pos = 19 - (giocatore1_pos - 19);
                    }
                    clear_screen();
                    titolo();
                    stampa_tabella(tabellone, giocatore1_pos, giocatore2_pos);
                    printf("Hai tirato un %d\n", tiro1);
                    printf("Hai trovato una casella salto! Avanzi di 2 caselle.\n");
                    printf("Posizione giocatore 1: %d\n", giocatore1_pos + 1);
                    break;
                case 2: //VANT: ALI
                    giocatore1_pos += 3;
                    if(giocatore1_pos > 19)
                    {
                        giocatore1_pos = 19 - (giocatore1_pos - 19);
                    }
                    clear_screen();
                    titolo();
                    stampa_tabella(tabellone, giocatore1_pos, giocatore2_pos);
                    printf("Hai tirato un %d\n", tiro1);
                    printf("Hai trovato una casella ali! Avanzi di 3 caselle.\n");
                    printf("Posizione giocatore 1: %d\n", giocatore1_pos + 1);
                    break;
                case -1: //SVANT: PRIGIONE 
                    giocatore1_pos -= 2;
                    if(giocatore1_pos < 0) // evito di andare sotto lo 0
                    {
                    giocatore1_pos = 0;
                    }
                    clear_screen();
                    titolo();
                    stampa_tabella(tabellone, giocatore1_pos, giocatore2_pos);
                    printf("Hai tirato un %d\n", tiro1);
                    printf("Hai trovato una casella prigione! Torni indietro di 2 caselle.\n");
                    printf("Posizione giocatore 1: %d\n", giocatore1_pos + 1);
                    break;
                case -2: //SVANT
                    giocatore1_pos -= 3;
                    if(giocatore1_pos < 0) // evito di andare sotto lo 0
                    { 
                        giocatore1_pos = 0;
                    }           
                    clear_screen();
                    titolo();
                    stampa_tabella(tabellone, giocatore1_pos, giocatore2_pos);
                    printf("Hai tirato un %d\n", tiro1);
                    printf("Hai trovato una casella labirinto! Torni indietro di 3 caselle.\n");
                    printf("Posizione giocatore 1: %d\n", giocatore1_pos + 1);
                    break;
                default:
                    clear_screen();
                    titolo();
                    stampa_tabella(tabellone, giocatore1_pos, giocatore2_pos);
                    printf("Hai tirato un %d\n", tiro1);
                    printf("Posizione giocatore 1: %d\n", giocatore1_pos + 1);
                    break;
                }
            }
            
            //STESSA COSA CON GIOCATORE2
            printf("\nTurno del giocatore 2. Premi invio per tirare il dado.");
            getchar();
            puntini();
            clear_screen();
            tiro2 = dado();
            giocatore2_pos += tiro2;
            if(giocatore2_pos == 19)
            {
                clear_screen();
                titolo();
                stampa_tabella(tabellone, giocatore1_pos, giocatore2_pos);
                vit2();
                goto fine;
            }
            else
            if(giocatore2_pos > 19)
            {
                giocatore2_pos = 19 - (giocatore2_pos - 19);
                clear_screen();
                titolo();
                stampa_tabella(tabellone, giocatore1_pos, giocatore2_pos);
                printf("Hai tirato un %d\n", tiro2);
                printf("Posizione giocatore 2: %d\n\n", giocatore2_pos + 1);
            }
            else
            {
                switch(tabellone[giocatore2_pos])
                {
                    case 1:
                        giocatore2_pos += 2;
                        if(giocatore2_pos > 19)
                        {
                            giocatore2_pos = 19 - (giocatore2_pos - 19);
                        }
                        clear_screen();
                        titolo();
                        stampa_tabella(tabellone, giocatore1_pos, giocatore2_pos);
                        printf("Hai tirato un %d\n", tiro2);
                        printf("Hai trovato una casella ali! Avanzi di 3 caselle.\n");
                        printf("Posizione giocatore 2: %d\n", giocatore2_pos + 1);
                        break;
                    case 2:
                        giocatore2_pos += 3;
                        if(giocatore2_pos > 19)
                        {
                            giocatore2_pos = 19 - (giocatore2_pos - 19);
                        }
                        clear_screen();
                        titolo();
                        stampa_tabella(tabellone, giocatore1_pos, giocatore2_pos);
                        printf("Hai tirato un %d\n", tiro2);
                        printf("Hai trovato una casella ali! Avanzi di 3 caselle.\n");
                        printf("Posizione giocatore 2: %d\n", giocatore2_pos + 1);
                        ;
                        break;
                    case -1:
                        giocatore2_pos -= 2;
                        if(giocatore2_pos < 0)
                        {
                        giocatore2_pos = 0;
                        }
                        clear_screen();
                        titolo();
                        stampa_tabella(tabellone, giocatore1_pos, giocatore2_pos);
                        printf("Hai tirato un %d\n", tiro2);
                        printf("Hai trovato una casella prigione! Torni indietro di 2 caselle.\n");
                        printf("Posizione giocatore 2: %d\n", giocatore2_pos + 1);
                        break;
                    case -2:
                        giocatore2_pos -= 3;
                        if(giocatore2_pos < 0)
                        {
                            giocatore2_pos = 0;
                        }   
                        clear_screen();
                        titolo();        
                        stampa_tabella(tabellone, giocatore1_pos, giocatore2_pos);
                        printf("Hai tirato un %d\n", tiro2);
                        printf("Hai trovato una casella labirinto! Torni indietro di 3 caselle.\n");
                        printf("Posizione giocatore 2: %d\n", giocatore2_pos + 1);
                        break;
                    default:
                        clear_screen();
                        titolo();
                        stampa_tabella(tabellone, giocatore1_pos, giocatore2_pos);
                        printf("Hai tirato un %d\n", tiro2);
                        printf("Posizione giocatore 2: %d\n", giocatore2_pos + 1);  //la scrivo anche qui cosi' da essere ancora piu' chiaro(non necessario)
                        break;
                    }
                printf("Premi invio per passare al turno successivo");
                getchar();
            }
        turno++;
    }
    while (giocatore1_pos < 19 && giocatore2_pos < 19);    //il turno dura finche' uno dei due giocatori non arriva alla casella 20
    fine:   
    return 0;    
}
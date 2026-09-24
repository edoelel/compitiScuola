#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
    char phrase[1000];
    char upPhrase[1000];
    int i;
    printf("Inserisci una frase e la trasformo in maiuscolo");
    fgets(phrase, sizeof(phrase), stdin);
    /* phrase[strlen(phrase) - 1] = '\0';
    Se il programma non prende il char e prende solo lo \n allora(causa buffer):
    char prova = getchar();
    oppure
    fflush(stdin);
    fgets();
    */
	for (i = 0; i < strlen(phrase); i++){
            if(phrase[i] >= 'a' && phrase[i] <= 'z'){
            phrase[i] = phrase[i] - 32;
            }
            
    }
    printf("La tua frase in maiuscolo e': %s", phrase);
    return 0;
}
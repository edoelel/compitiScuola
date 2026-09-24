/*Dato un array di char che contiene una stringa, scrivi una funzione che:
    Conta quante vocali sono presenti e restituisce quel valore
    Conta quante parole separate da spazio sono presenti e restituisce quel valore
    Conta quante lettere doppie sono presenti nelle varie parole (Es in “belli miei come ve la passate?” contiene 2 lettere doppie)
    non contare le lettere con più caratteri ripetuti (tipo:”www”)
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define usleep(usec) Sleep((usec) / 1000)
#else
#include <unistd.h>
#endif

int contaVocali(char str[]){
    int i=0, v=0;
    for(i=0; i<strlen(str); i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' 
        || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            v++;
        }
    }
    return v;
}

int contaSpazi(char str[]){
    int i=0, s=0;
    for(i=0; i<strlen(str); i++){
        if(str[i]==' '){
            s++;
        }
    }
    return s;
}


int contaDoppie(char str[]){
    int i = 0, d = 0;
    for(i=1; i<strlen(str); i++){
        if(str[i-2] == str[i]){
            
        }else if(str[i+1] == str[i]){
            
        }else if (str[i-1] == str[i])
        {
            d++;
        }
        
    }
    return d;
}


int main(){
    char palle[1000];
    printf("inserisci una stringa");
    fgets(palle, 1000, stdin);
    palle[strlen(palle) - 1] = '\0';
    printf("Le vocali presenti in questa frase sono: %d\n", contaVocali(palle));
    printf("Gli spazi presenti in questa frase sono: %d\n", contaSpazi(palle));
    printf("Le doppie presenti in questa frase sono: %d", contaDoppie(palle));
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(){
    char word[1000];
    char palc[1000];
    int i = 0;
    printf("Scrivi una parola/frase e la inverto: ");
    scanf("%s", word);
    while(i < strlen(word)){
        palc[i] = word[strlen(word) - i - 1];
        i++;
    }
    printf("\nLa tua parola invertita e': %s", palc);
}
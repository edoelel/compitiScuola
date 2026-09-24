#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(){
    char phrase[1000];
    int i, n;
    printf("Inserisci una frase/parola: ");
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strcspn(phrase, "\n")] = '\0';
    printf("Inserisci il numero di volte che vuoi ripetere la frase/parola: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("%s", phrase);
    }
}
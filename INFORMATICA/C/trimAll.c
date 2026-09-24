#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
    char phrase[1000];
    char trPhrase[1000];
    int i, k;
    k = 0;
    printf("Inserisci una frase e ti tolgo gli spazi: ");
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strlen(phrase) - 1] = '\0';
    fflush(stdin);
    for (i = 0; i < strlen(phrase); i++){
        if(phrase[i] == ' '){
            continue;
        }else{
            printf("%c", phrase[i]);
        }
    }
    return 0;
}
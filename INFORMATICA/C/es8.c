#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
    char str[100];
    int vo = 0;
    int i;
    printf("Inserisci stringa: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';
    printf("La tua stringa e' lunga: %d caratteri\n", strlen(str));
    for(i = 0; i < strlen(str); i++){
        switch (str[i])
        {
        case 'a':
            vo++;
            break;
        case 'A':
            vo++;
            break;
        case 'e':
            vo++;
            break;
        case 'E':
            vo++;
            break;
        case 'i':
            vo++;
            break;
        case 'I':
            vo++;
            break;
        case 'o':
            vo++;
            break;
        case 'O':
            vo++;
            break;
        case 'u':
            vo++;
            break;
        case 'U':
            vo++;
            break;
        
        default:
            break;
        }
    }
    printf("Le vocali presenti nella frase sono: %d", vo);
}
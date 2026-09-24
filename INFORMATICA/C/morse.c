#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
    char phrase[1000];
    int i;
    printf("Inserisci una frase e la traduco in codice morse: ");
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strlen(phrase) - 1] = '\0';
    fflush(stdin);
    for(i = 0; i < strlen(phrase); i++){
        switch (phrase[i]) {
            case 'a':
                printf(".- ");
                break;
            case 'b':
                printf("-... ");
                break;
            case 'c':
                printf("-.-. ");
                break;
            case 'd':
                printf("-.. ");
                break;
            case 'e':
                printf(". ");
                break;
            case 'f':
                printf("..-. ");
                break;
            case 'g':
                printf("--. ");
                break;
            case 'h':
                printf(".... ");
                break;
            case 'i':
                printf(".. ");
                break;
            case 'j':
                printf(".--- ");
                break;
            case 'k':
                printf("-.- ");
                break;
            case 'l':
                printf(".-.. ");
                break;
            case 'm':
                printf("-- ");
                break;
            case 'n':
                printf("-. ");
                break;
            case 'o':
                printf("--- ");
                break;
            case 'p':
                printf(".--. ");
                break;
            case 'q':
                printf("--.- ");
                break;
            case 'r':
                printf(".-. ");
                break;
            case 's':
                printf("... ");
                break;
            case 't':
                printf("- ");
                break;
            case 'u':
                printf("..- ");
                break;
            case 'v':
                printf("...- ");
                break;
            case 'w':
                printf(".-- ");
                break;
            case 'x':
                printf("-..- ");
                break;
            case 'y':
                printf("-.-- ");
                break;
            case 'z':
                printf("--.. ");
                break;

            // Numeri
            case '0':
                printf("----- ");
                break;
            case '1':
                printf(".---- ");
                break;
            case '2':
                printf("..--- ");
                break;
            case '3':
                printf("...-- ");
                break;
            case '4':
                printf("....- ");
                break;
            case '5':
                printf("..... ");
                break;
            case '6':
                printf("-.... ");
                break;
            case '7':
                printf("--... ");
                break;
            case '8':
                printf("---.. ");
                break;
            case '9':
                printf("----. ");
                break;

            // Punteggiatura di base
            case '.':
                printf(".-.-.- ");
                break;
            case ',':
                printf("--..-- ");
                break;
            case '?':
                printf("..--.. ");
                break;
            case '!':
                printf("-.-.-- ");
                break;
            case ' ':
                printf(" ");
                break;  // Separatore tra parole

            // Carattere apostrofo singolo
            case '\'':
                printf(".----. ");
                break;
            default:
                break;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 30


int main()
{
    FILE *rubrica = fopen("rubrica.csv", "a");

    if (rubrica == NULL)
    {
        printf("Errore");
        return 0;
    }

    int i = 1;
    char nome[MAXL];
    char cognome[MAXL];
    char numero[MAXL];

    while (i == 1)
    {
        printf("Qual e' il nome del contatto: ");
        scanf("%s", nome);
        printf("Qual e' il cognome del contatto: ");
        scanf("%s", cognome);
        printf("Qual e' il numero del contatto: ");
        scanf("%s", numero); // fgets per spazi da gestire

        fprintf(rubrica, "%s,%s,%s\n", nome, cognome, numero);

        printf("Vuoi continuare(1 = si; 0 = no): ");
        scanf("%d", &i);
    }
    fclose(rubrica);
    return 0;
}
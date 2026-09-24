#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATTI 100


typedef struct
{
    char nome[50];
    char cognome[50];
    char telefono[20];
} Contatto;

Contatto contatti[MAX_CONTATTI];
int numero_contatti = 0;

void aggiungi_contatto()
{
    if (numero_contatti >= MAX_CONTATTI)
    {
        printf("Rubrica piena!\n");
        return;
    }
    Contatto *c = &contatti[numero_contatti];
    printf("Nome: ");
    scanf("%s", c->nome);
    printf("Cognome: ");
    scanf("%s", c->cognome);
    printf("Telefono: ");
    scanf("%s", c->telefono);
    numero_contatti++;
}

int cerca(char *nome, int i)
{
    while(i != -1){
    if (i >= numero_contatti){
        return -1;
    }
    if (strcasecmp(contatti[i].nome, nome) == 0){
        return i;
    }
    return cerca(nome, i + 1);
    }
}


void salva()
{
    FILE *f = fopen("rubrica.csv", "a");
    Contatto *c = &contatti[numero_contatti - 1];
    fprintf(f, "%s,%s,%s\n", c->nome, c->cognome, c->telefono);
    fclose(f);
}

void carica()
{
    FILE *f = fopen("rubrica.csv", "r");
    if (f == NULL)
        return;
    while (numero_contatti < MAX_CONTATTI)
    {
        Contatto *c = &contatti[numero_contatti];
        if (fscanf(f, "%[^,],%[^,],%[^\n]\n", c->nome, c->cognome, c->telefono) != 3)
            break;
        numero_contatti++;
    }
    fclose(f);
}

int main()
{
    carica();

    int scelta;
    do
    {
        printf("\n1. Aggiungi  2. Cerca  0. Esci\n> ");
        scanf("%d", &scelta);

        if (scelta == 1)
        {
            aggiungi_contatto();
            salva();
        }
        else if (scelta == 2)
        {
            char nome[50];
            printf("Nome: ");
            scanf("%s", nome);
            int i = cerca(nome, 0);
            if (i == -1)
                printf("Non trovato.\n");
            else
                printf("%s %s - %s\n", contatti[i].nome, contatti[i].cognome, contatti[i].telefono);
        }
    } while (scelta != 0);

    return 0;
}
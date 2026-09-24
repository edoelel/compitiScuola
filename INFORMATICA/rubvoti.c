#include <stdio.h>
#include <stdlib.h>

#define LEN 40
#define NVOTI 100


int minarr(int voto[], int len)
{
    int i;
    int min = voto[0];
    for(i=0; i<len; i++)
        {
            if(voto[i]<min)
            {
                min=voto[i];
            }
        }
    return min;
}

int maxarr(int voto[], int len)
{
    int i;
    int min=voto[0];
    for(i=0; i<len; i++)
        {
            if(voto[i]>min)
            {
                min=voto[i];
            }
        }
    return min;
}

float mediarr(int voto[], int len)
{
    int somma = 0;
    int i;
    float media;
    for (i = 0; i < len; i++)
    {
        somma += voto[i];
    }
    media = (float)somma / len;
    return media;
}

int main(){
    FILE *file = fopen("infos.csv", "r");
    FILE *suff = fopen("sufficienti.csv", "a");
    if (file == NULL)
    {
        perror("Errore nell'apertura del file");
        return 1;
    }
    char nome[40], cognome[40];
    int voto[100] = {0};
    char line[100];
    int i = 0, len, suffic = 0;
    float media =0, max=0, min=0;
    while (fgets(line, sizeof(line), file))
    {
        if (fscanf(file, "%49[^,],%49[^,],%d", nome, cognome, &voto[i]) ==  3)
        {
            printf("Lo studente: %s %s e' ha il voto di %d\n", nome, cognome, voto[i]);
            if(voto[i] >= 18){
                fprintf(suff, "%s, %s, %d\n", nome, cognome, voto[i]);
                suffic++;
            }
            
        }
        else
        {
            fprintf(stderr, "Errore nel parsing della riga: %s", line);
        }
        i++;
    }
    media = mediarr(voto, i);
    min = minarr(voto, i);
    max = maxarr(voto, i);
    printf("Statische: \nLa media e': %.2f\nIl minimo e': %.2f\nIl massimo e': %.2f\nI sufficienti sono: %d", media, min, max, suffic);

    fclose(file);
    fclose(suff);
}
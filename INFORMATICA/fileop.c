#include <stdio.h>
#include <stlib.h>

int main()
{
    time_t rawtime = time(NULL);
    struct tm *info = localtime(&rawtime); 
    int month = (*info).tm_mon+1;
    int day = (*info).tm_mday;
    int year = (*info).tm_year + 1900;
    FILE *file = fopen("infos.csv", "a");
    if (file == NULL)
    {
        perror("Errore nell'apertura del file");
        return 1;
    }
    char line[200];
    fgets(line, sizeof(line), stdin);
    char nome[], cognome[];
    int anno, mese, giorno, eta;
    while (fgets(line, sizeof(line), file))
    {
        if (sscanf(line, "%s,%s, %d, %d, %d", &nome, &cognome, &giorno, &mese, &anno) ==  5)
        {
            if(month == mese && day == giorno){
                eta = a
            }
            printf("Nome: %s, Cognome %s, Data di nascita: %d/%d/%d\n", nome, cognome, giorno, mese, anno);
            fprintf(eta, "\n");
        }
        else
        {
            fprintf(stderr, "Errore nel parsing della riga: %s", line);
        }
    }
}
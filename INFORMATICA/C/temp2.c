#include <stdio.h>

int main()
{
	FILE *filet = fopen("filet.csv", "r");
	FILE *caldo = fopen("caldo.csv", "w");

	char giorno[50];
	char line[100];
	int temperatura = 0;
	int somma = 0;
	int max;
	int min;
	float media;
	int cont = 0;
	int giornicaldi = 0;
	filet = fopen("filet.csv", "r");

	if (filet == NULL)
	{
		printf("errore file\n");
	}

	fgets(line, sizeof(line), filet);

	while (fgets(line, sizeof(line), filet))
	{

		if (fscanf(filet, "%49[^,], %d", giorno, &temperatura) == 2)
		{

			printf("giorno %s: temperatura: %d\n", giorno, temperatura);

			min = temperatura;
			max = temperatura;
			somma += temperatura;
			cont++;

			if (temperatura >= 25)
			{
				fprintf(caldo, "%s, %d", giorno, temperatura);
				giornicaldi++;
			}

			if (temperatura > max)
			{
				max = temperatura;
			}

			if (temperatura < min)
			{
				min = temperatura;
			}

			if (temperatura >= 25)
			{
				fprintf(caldo, "%49[^,], %d", giorno, temperatura);
				giornicaldi++;
			}
		}
	}

	media = somma / cont;

	printf("\nTemperatura media: %.2f\n", media);
	printf("Temperatura massima: %d\n", max);
	printf("Temperatura minima: %d\n", min);

	printf("Numero giorni caldi: %d\n", giornicaldi);

	fclose(filet);
	fclose(caldo);

	return 0;
}

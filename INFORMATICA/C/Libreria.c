#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <time.h>
int fattoriale(int numFattoriale)
{
	int pfatt = 1;
	for(; numFattoriale > 0; numFattoriale--){
		pfatt = numFattoriale * pfatt;
	}
	return pfatt;
}

int ValoreAss(int numValAssoluto)
{
	if(numValAssoluto >= 0)
		return numValAssoluto;
	else
		return -numValAssoluto;
}

int Maggiore(int NUM1, int NUM2)
{
	if(NUM1 > NUM2)
		return NUM1;
	else
		return NUM2;
}

int Minore(int num1, int num2)
{
	if(num1 > num2)
		return num2;
	else
		return num1;
}

int Media(int med1,int med2)
{
	int media = (med1 + med2) / 2;
	return media;
}

int AreaRett(int l1,int l2)
{
	int areaRett = (l1 * l2);
	return areaRett;
}

int AreaTria(int a,int b, int c)
{
	int s = (a + b + c) / 2.0;
	int areaTria = sqrt(s * (s - a) * (s - b) * (s - c));
	return areaTria;
}

int AreaTrap(int bt1,int bt2,int ht)
{
	int areaTrap = (bt1 + bt2) * ht / 2.0;
	return areaTrap;
}

int cir(int raggio)
{
	int circonferenza = 2 * 3.14 * raggio;
	return circonferenza;
}

int distanza(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int primo(int n) {
    int i;
    if (n <= 1) return 0;

    for (i = 2; i < n; i++) {
        if (n % i == 0)
            return 0; 
    }

    return 1;
}

int randomRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int randomint01() {
    return (int)rand() / RAND_MAX;
}

int dado(int nFacce) {
    return randomRange(1, nFacce);
}

int sommaDadi(int numDadi, int nFacce) {
    int i;
    int somma = 0;
    for (i = 0; i < numDadi; i++) {
        somma = somma+dado(nFacce);
    }
    return somma;
}

int moneta() {
    return rand() %2;
}


int main()
{
    int risultato;
    int risultato_int;
    srand(time(NULL));

	printf("------------------------------------------------------------------------\n");
	printf("TESTING FATTORIALE\n");
	risultato_int = fattoriale(4);
	if(risultato_int == 24){
		printf("test 1 superato: 4! = %d\n", risultato_int);
	} else{
		printf("test 1 fallito\n");
	}	
	risultato_int = fattoriale(7);
	if(risultato_int == 5040){
		printf("test 2 superato: 7! = %d\n", risultato_int);
	} else{
		printf("test 2 fallito\n");
	}
	
	printf("------------------------------------------------------------------------\n");
	printf("TESTING VALORE ASSOLUTO\n");
	risultato = ValoreAss(5);
	if(risultato == 5){
		printf("test 1 superato: Il valore assoluto di 5 e' = %.2f\n", risultato);
	} else{
		printf("test 1 fallito\n");
	}	
	risultato = ValoreAss(-8);
	if(risultato == 8){
		printf("test 2 superato: Il valore assoluto di -8 e' = %.2f\n", risultato);
	} else{
		printf("test 2 fallito\n");
	}

	printf("------------------------------------------------------------------------\n");
	printf("TESTING NUMERO MAGGIORE\n");
	risultato = Maggiore(7, 4);
	if(risultato == 7){
		printf("test 1 superato: Il numero maggiore tra 7 e 4 e' = %.2f\n", risultato);
	} else{
		printf("test 1 fallito\n");
	}
	risultato = Maggiore(37, 100);
	if(risultato == 100){
		printf("test 2 superato: Il numero maggiore tra 37 e 100 e' = %.2f\n", risultato);
	} else{
		printf("test 2 fallito\n");
	}

	printf("------------------------------------------------------------------------\n");
	printf("TESTING NUMERO MINORE\n");
	risultato = Minore(9, 3);
	if(risultato == 3){
		printf("test 1 superato: Il numero minore tra 9 e 3 e' = %.2f\n", risultato);
	} else{
		printf("test 1 fallito\n");
	}
	risultato = Minore(27, 102);
	if(risultato == 27){
		printf("test 2 superato: Il numero minore tra 27 e 102 e' = %.2f\n", risultato);
	} else{
		printf("test 2 fallito\n");
	}

	printf("------------------------------------------------------------------------\n");
	printf("TESTING DELLA MEDIA FRA DUE NUMERI\n");
	risultato = Media(8, 2);
	if(risultato == 5){
		printf("test 1 superato: La media tra 8 e 2 e' = %.2f\n", risultato);
	} else{
		printf("test 1 fallito\n");
	}
	risultato = Media(30, 100);
	if(risultato == 65){
		printf("test 2 superato: La media tra 30 e 100 e' = %.2f\n", risultato);
	} else{
		printf("test 2 fallito\n");
	}

	printf("------------------------------------------------------------------------\n");
	printf("TESTING DELL'AREA DI UN RETTANGOLO\n");
	risultato = AreaRett(3, 2);
	if(risultato == 6){
		printf("test 1 superato: L'area di un rettangolo di lati 3 e 2 e' = %.2f\n", risultato);
	} else{
		printf("test 1 fallito\n");
	}
	risultato = AreaRett(10, 12);
	if(risultato == 120){
		printf("test 2 superato: L'area di un rettangolo di lati 10 e 12 e' = %.2f\n", risultato);
	} else{
		printf("test 2 fallito\n");
	}

	printf("------------------------------------------------------------------------\n");
	printf("TESTING DELL'AREA DI UN TRIANGOLO\n");
	risultato = AreaTria(3,4,5);
	if((int)risultato == 6){
		printf("test 1 superato: L'area di un triangolo di lati 3, 4 e 5 e' = %.2f\n", risultato);
	} else{
		printf("test 1 fallito\n");
	}
	risultato = AreaTria(5,5,6);
	if((int)risultato == 12){
		printf("test 2 superato: L'area di un triangolo di lati 5, 5 e 6 e' = %.2f\n", risultato);
	} else{
		printf("test 2 fallito\n");
	}

	printf("------------------------------------------------------------------------\n");
	printf("TESTING DELL'AREA DI UN TRAPEZIO\n");
	risultato = AreaTrap(2,3,5);
	if((int)risultato == 12){
		printf("test 1 superato: L'area di un trapezio di basi 2, 3 e altezza 5 e' = %.2f\n", risultato);
	} else{
		printf("test 1 fallito\n");
	}
	risultato = AreaTrap(4,2,6);
	if((int)risultato == 18){
		printf("test 2 superato: L'area di un trapezio di basi 4, 2 e altezza 6 e' = %.2f\n", risultato);
	} else{
		printf("test 2 fallito\n");
	}

	printf("------------------------------------------------------------------------\n");
	printf("TESTING DELLA CIRCONFERENZA DATO IL RAGGIO\n");
	risultato = cir(3);
	if((int)risultato == 18){
		printf("test 1 superato: la circonferenza di un cerchio di raggio 3 e' = %.2f\n", risultato);
	} else{
		printf("test 1 fallito\n");
	}
	risultato = cir(6);
	if((int)risultato == 37){
		printf("test 2 superato: la circonferenza di un cerchio di raggio 6 e' = %.2f\n", risultato);
	} else{
		printf("test 2 fallito\n");
	}

    printf("------------------------------------------------------------------------\n");
    printf("TESTING DISTANZA TRA DUE PUNTI\n");
    risultato = distanza(0, 0, 3, 4);
    if((int)risultato == 5)
        printf("test 1 superato: distanza (0,0)-(3,4) = %.2f\n", risultato);
    else
        printf("test 1 fallito\n");

    printf("------------------------------------------------------------------------\n");
    printf("TESTING NUMERO PRIMO\n");
    risultato_int = primo(7);
    if(risultato_int == 1)
        printf("test 1 superato: 7 e' primo\n");
    else
        printf("test 1 fallito\n");
    risultato_int = primo(8);
    if(risultato_int == 0)
        printf("test 2 superato: 8 non e' primo\n");
    else
        printf("test 2 fallito\n");

    printf("------------------------------------------------------------------------\n");
    printf("TESTING NUMERO CASUALE TRA MIN E MAX\n");
    risultato_int = randomRange(1, 6);
    if(risultato_int >= 1 && risultato_int <= 6)
        printf("test superato: numero casuale tra 1 e 6 = %d\n", risultato_int);
    else
        printf("test fallito\n");

    printf("------------------------------------------------------------------------\n");
    printf("TESTING NUMERO CASUALE DECIMALE DA 0 A 1\n");
    risultato = randomint01();
    if(risultato >= 0 && risultato <= 1)
        printf("test superato: numero casuale decimale = %.3f\n", risultato);
    else
        printf("test fallito\n");

    printf("------------------------------------------------------------------------\n");
    printf("TESTING LANCIO DI UN DADO A N FACCE\n");
    risultato_int = dado(6);
    if(risultato_int >= 1 && risultato_int <= 6)
        printf("test superato: risultato dado a 6 facce = %d\n", risultato_int);
    else
        printf("test fallito\n");

    printf("------------------------------------------------------------------------\n");
    printf("TESTING SOMMA DI PIU DADI\n");
    risultato_int = sommaDadi(3, 6);
    if(risultato_int >= 3 && risultato_int <= 18)
        printf("test superato: somma di 3 dadi a 6 facce = %d\n", risultato_int);
    else
        printf("test fallito\n");

    printf("------------------------------------------------------------------------\n");
    printf("TESTING LANCIO DI MONETA\n");
    risultato_int = moneta();
    if(risultato_int == 0 || risultato_int == 1)
        printf("test superato: moneta = %d (0=testa, 1=croce)\n", risultato_int);
    else
        printf("test fallito\n");


	return 0;
}

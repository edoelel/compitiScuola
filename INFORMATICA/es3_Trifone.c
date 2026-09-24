#include <stdio.h>

int main()
{
	int n=1;
	int d=0;
	int p=0;
    
	do
	 {
	  printf("\nscrivi un numero ( 0 per uscire): ");
	  scanf ("%d", &n);
	  if(n<0)
	  	d++;
	  if(n>0)
	  	p++; 
	 }	
	while (n!=0);
	
	printf("hai scritto %d numeri negativi e %d numeri positivi",d,p);
	return 0;
}

#include <stdio.h>
/*Nome: Edoardo Trifone
 Data:3/12/25
 Descrizione: Funzioni che ritornano il valore minimo e massimo di un array
 off topic: uso queste due funzioni per chiedere a delle persone come e' andata la giornata e poi dico chi e' stato piu' sfortunato e chi piu' fortunato
 */
int minarr(int arr[], int len)
{
    int i;
    int min=0;
    min=arr[0];
    for(i=0; i!=len; i++)
        {
            if(arr[i]<min)
            {
                min=arr[i];
            }
        }
    return min;
}

int maxarr(int arr[], int len)
{
    int i;
    int max=0;
    max=arr[0];
    for(i=0; i!=len;i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
            }
        }
    return max;
}




int main()
{
    int p, np=0;
    int sfort=1;
    int fort=1;
    printf("A quante persone vogliamo chiedere come e' andata la giornata? ");
    scanf("%d", &p);
    int arr[p];
    for(int i=0; i<p; i++){
        np++;
        printf("come valuteresti la tua giornata da 1 a 10 persona  %d? ", np);
        scanf("%d", &arr[i]);
    }
    int min = arr[0];
    int max = arr[0];
    for(int i = 1; i < p; i++) {
        if(arr[i] < min) {
            min = arr[i];
            sfort = i + 1;
        }
        if(arr[i] > max) {
            max = arr[i];
            fort = i + 1;
        }
    }
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("La persona piu' sfortunata e' la : %d\nIl voto di questa persona alla sua giornata e' stato di: %d\n", sfort, minarr(arr, len));
    printf("La persona piu' fortunata e' la numero %d\nIl voto di questa persona alla sua giornata e' stato di: %d\n", fort, maxarr(arr, len));
    return 0;
}
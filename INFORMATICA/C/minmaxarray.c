#include <stdio.h>


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
    printf("Tra quanti numeri vuoi sapere qaul e' il piu' grande e il più piccolo");
    scanf("%d", &p);
    int arr[p];
    for(int i=0; i<p; i++){
        np++;
        printf("Inserisci %d° numero ", np);
        scanf("%d", &arr[i]);
    }
    int min = arr[0];
    int max = arr[0];
    for(int i = 1; i < p; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("Il numero piu' piccolo e': \n", minarr(arr, len));
    printf("Il numero piu' grande e': \n", maxarr(arr, len));
    return 0;
}
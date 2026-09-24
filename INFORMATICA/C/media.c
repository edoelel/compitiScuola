#include <stdio.h>
float mediarr(int arr[], int len)
{
    int somma = 0;
    int i;
    float media;
    for (i = 0; i < len; i++)
    {
        somma = somma+arr[i];
    }
    media = (float)somma / len;
    return media;
}

int main()
{
    int arr[6]={10, 8, 5, 4, 6, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    float m;
    printf("La media e: %f\n", mediarr(arr, len));
    return 0;
}

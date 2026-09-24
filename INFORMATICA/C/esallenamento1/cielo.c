#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#define usleep(usec) Sleep((usec) / 1000)
#else
#include <unistd.h>
#endif

int main() {
    int stars;
    char s[5001]; 
    srand(time(NULL)); 
    while (1) {
        for (stars = 0; stars < 5000; stars++) {
            int m = rand() % 2;
            if (m == 0) {
                s[stars] = ' ';
            } else {
                s[stars] = '*';
            }
        }   
        s[5000] = '\0';
        printf("%s\n", s);
        usleep(500000);
        system("cls");   
    }
    return 0;
}

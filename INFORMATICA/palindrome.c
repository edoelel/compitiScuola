#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(){
    char word[1000];
    char palc[1000];
    int i = 0;
    bool a = true;
    printf("Scrivi una frase e controllo se e' palindroma o no\n");
    scanf("%s", word);

    i=0;
    while(i < strlen(word)){
        if(word[i] != palc[i]){
            a = false;
            if(word[i] == ' ' || palc[i] == ' '){
                a = true;
            }
        }
        i++;
    }
    if(a){
        printf("e' palindroma!!");
    }else{
        printf("non e' palindroma");
    }
}
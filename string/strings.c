#include <stdio.h>
#include <stdlib.h>

void escreve(char string[]){
    int i = 0;
    while(string[i] != '\0'){
        putchar(string[i++]);
    }
}

int main(){
    char nome1[10] = "Valeria";
    char nome2[10] = {'V','a','l','e','r','i','a'};
    char nome3[] = "Ícaro\0aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    escreve(nome1);
    printf("\n");
    escreve(nome2);
    printf("\n");
    escreve(nome3);

    return 0;
}
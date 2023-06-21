#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
int ehmaiusculo(char variavel[]){
    int tudo_maiusculo = 1;
    int len = strlen(variavel);
    for (int i = 0; i < len; i++){
        if (!isupper(variavel[i])) {
            tudo_maiusculo = 1;
            break;
        }
    }

    return tudo_maiusculo ? 1 : 0;
}


int main(){
    char nome[10] = "Valéria";
    char nome2[10] = {'V','a','l','e','r','i','a'};
    char nome3[5] = "J";

    printf("%s\n", nome);
    printf("%s\n", nome2);
    printf("%s\n", nome3);

    printf("%d", ehmaiusculo(nome3));

    return 0;
}*/

char nome[] = {'i','c','a','r','o'};

#define TAM_MAX 10
int dados[TAM_MAX], i, posicao;
char x = 'r';

int main(){

    printf("Primeiro vetor:\n\n");

    for (i = 0; i < TAM_MAX; i++){
        printf("%c\n", nome[i]);
    }

    printf("\nSegundo vetor:\n\n");

    for (i = 0; i < TAM_MAX; i++){
        dados[i] = i + 10;
        printf("%d\n", dados[i]);
    }

    printf("\nVamos procurar o caractere 'r' no Vetor 'icaro' \n\n");

    for (i = 1; i < TAM_MAX; i++){
        if (nome[i] == x){
            posicao = i;
            break;
        };
    }

    printf("Posição: %d\n\n", posicao);

    printf("Agora vamos escrever em um vetor: \n");

    float vetor[4];

    for(i = 0; i < 4; i++){
        scanf("%f", &vetor[i]);
    }
    for (i = 0; i < 4; i ++){
        printf("Elemento: %.1f - Posição: %d\n", vetor[i], i);
    }

    return 0;
}
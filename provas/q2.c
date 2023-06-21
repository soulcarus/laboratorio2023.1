#include <stdio.h>
#include <stdlib.h>
// e não ter como descrever toda impureza em um só verso...

int main(){

    int quantidade;
    int maior = 0;
    int i = 0;
    int count = 1;

    printf("BEM VINDO A CORRIDA DAS LESMAS!!\n");
    printf("Quantidade de lesmas do grupo -> ");
    scanf("%d", &quantidade);
    printf("\nInsira as velocidades abaixo (uma linha)\n");
    int lesmas[quantidade];

    while(scanf("%d", &lesmas[i]) && count < quantidade){
        i++;
        count++;
    }
    printf("\nTodos os numeros apenas para ilustrar: \n\n");
    
    for (i = 0; i < quantidade; i ++){
        printf("lesma: %d - Velocidade: %d \n",i + 1, lesmas[i]);
    }

    for (int j = 0; j < quantidade; j++){
        if (lesmas[j] > maior){
            maior = lesmas[j];
        }
    }

    if (maior < 10){
        printf("\nNível 1\n");
    }else if( maior >= 10 && maior < 20){
        printf("\nNível 2\n");
    }else if(maior >= 20){
        printf("\nNível 3\n");
    }

/*
    for (i = 1; i < quantidade + 1; i++){
        printf("Insira a velocidade da lesma %d -> ", i);
        scanf("%d", lesmas[i - 1]);
    }

    for (i = 0; i < quantidade; i++){
        printf("Velocidade: %d", lesmas[i]);
    }
*/

    return 0;
}
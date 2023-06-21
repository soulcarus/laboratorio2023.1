#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 12

int vetnum[TAM_MAX], vetpar[TAM_MAX / 2], vetimpar[TAM_MAX / 2];
int contador_par, contador_impar = 0;

void lerInteiros(){

    printf("Insira 12 numeros inteiros: \n\n");
    for (int i = 0; i < TAM_MAX; i ++){
        printf("Numero: ");
        scanf("\n%d", &vetnum[i]);
    }

    for (int i = 0; i < TAM_MAX; i ++){
        if (vetnum[i] % 2 == 0){
            vetpar[contador_impar] = vetnum[i];
            contador_par += 1;
        }else{
            vetimpar[contador_impar] = vetnum[i];
            contador_impar += 1;
        }
    }

    printf("Vetor par: \n\n");
    for (int i = 0; i < TAM_MAX/2; i ++){
        printf("%d\n", vetpar[i]);
    }

    printf("\nVetor impar: \n\n");
    for (int i = 0; i < TAM_MAX/2; i ++){
        printf("%d\n", vetimpar[i]);
    }
    
}

int main(){
    lerInteiros();


    return 0;
}
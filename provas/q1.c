#include <stdio.h>
#include <stdlib.h>

// querida e amada professora, lhe dedico, a cada questão um verso
// o mundo pode ser perverso...
int main(){

    int indice;

    printf("Qual sua felicidade hoje?: ");
    scanf("%d", &indice);
    if (indice == 0){
        printf("Poxa, que tristeza... pois vou encerrar!\n\n:D");
        return 1;
    }
    printf("Feliz Nat");
    for (int i = 0; i < indice; i ++){
        printf("a");
    }
    printf("l!\n");

    return 0;
}
#include <stdio.h>

#define MAXSIZE 10000000

char visto[MAXSIZE];

int main(){
    int i; // navegando nos loops
    unsigned n; // notação cientifica

    scanf("%u", &n); // scanear o valor inicial 

    unsigned long long total = 0; // declarar um somatorio para o numero de carneiros
    unsigned estrelas[n]; // declarar um array do tamanho da qtd de estrelas para amarzenálas

    for (i = 0; i < n; i ++){ // iremos pedir os inputs da qtd de carneiros de cada estrela 
        scanf("%u", &estrelas[i]); // armazenar na posicao atual do vetor de estrelas
        total += estrelas[i]; // pegar a quantidade de carneiros na posicao e somar no contador
    }

    i = 0; // zerar o nosso navegador do loop
    unsigned long long atacadas = 0; // declarar um unsigned 2x maior para armazenar as atacadas

    while(i >= 0 && i < n){ // simular a jornada pelas estrelas
    // SUA FUNCAO É ATACAR TODAS AS ESTRELAS E PARAR NA ULTIMA
    // VERIFICAR SE A ESTRELA É PAR, SE FOR, VOLTA UMA ESTRELA
    // SE FOR IMPAR, PULA UMA ESTRELA
        
        // verificar se o visto eh nulo e aumentar a quantidade de atacadas

        if(!visto[i]){ // se estrela n foi atacada
            atacadas++; // incrementa o contador de estrelas atacadas
        }

        visto[i] = 1; // marcar como atacada sempre (funcionalidade principal do while)

        //verificar se a estrela eh impar
        if (estrelas[i] & 1){
            --total; // decrementar o TOTAL de carneiros
            --estrelas[i++]; // decrementar o numero de carneiros na estrela atual e mover para a prox
        }else{
            if (estrelas[i]){
                --total; // decrementar o TOTAL de carneiros
                --estrelas[i]; // decrementar o numero de carneiros na estrela 
            }
            --i; // mover para a posicao da estrela anterior
        }
    }

    printf("%llu %llu\n", atacadas, total);

    return 0;
}
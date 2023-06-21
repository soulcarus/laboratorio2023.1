#include <stdio.h>
#include <stdlib.h>

#define MAX_QTD 10

// mas meu tempo aqui está acabando

typedef struct{
    int codigo;
    float valor;
    char tipo;
} Boleto;


int main(){

    Boleto boletos[MAX_QTD];
    float saldo[MAX_QTD] = {0};
    int numero_projeto;
    char c;
    
    printf("Insira o numero do projeto (-1 para sair): ");
    scanf("%d", &numero_projeto);
    if (numero_projeto > 9){
        printf("Projeto Inexistente! ENCERRANDO!");
        exit(1);
    }

    while(numero_projeto != -1){
        printf("\nInsira o valor: ");
        scanf("%f", &boletos[numero_projeto].valor);
        scanf("%c", &c);

        printf("\nInsira o tipo (R para Receita e D para Despesa): ");
        scanf("%c", &boletos[numero_projeto].tipo);

        if (boletos[numero_projeto].tipo == 'R'){
            saldo[numero_projeto] += boletos[numero_projeto].valor;
        } else if (boletos[numero_projeto].tipo == 'D'){
            saldo[numero_projeto] -= boletos[numero_projeto].valor;
        }

        printf("\nInsira o numero do projeto (-1 para sair): ");
        scanf("%d", &numero_projeto);

        }

        printf("\n");
        for (int i = 0; i < MAX_QTD; i++){
            printf("Projeto %d - Saldo Final: %.2f\n", i, saldo[i]);
        }

    return 0;
    }
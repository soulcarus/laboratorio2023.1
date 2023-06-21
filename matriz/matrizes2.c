#include <stdio.h>

int main(){

    char matriz[2][3] = {{'a','b','c'},{'d','e','f'}};;

    int linhas, colunas;

    for(linhas = 0 ; linhas < 2 ; linhas++){
        printf("Elementos da linha %d: ",linhas);
        for(colunas = 0 ; colunas < 3 ; colunas++){
            printf("%c,",matriz[linhas][colunas]);
        } printf("\n");
        }
}

/*

add:

char nomes[5][30];
int i;

for(i = 0 ; i < 5 ; i++){
    printf("Insira o nome %d: ",i+1);
    scanf("%s",nomes[i]);
}

vetor de strings:

char menu[][7] = {"abrir","editar","salvar","sair"};
int i;

for(i = 0 ; i < 4 ; i++)
    printf("%s\n",menu[i]);

*/

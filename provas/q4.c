#include <stdio.h>
#include <stdlib.h>

// No final das contas deu de boa, ainda faltam 30 minutos
// entao o tempo nao ta acabando nao
// mas meu cerebro fritou, n sei mais poetizar ok? fica pra proxima, lhe devo
// boa correção

int main(){

    int n;
    int coelhos = 0, ratos = 0, sapos = 0;
    int qtd;
    char tipo;

    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d %c", &qtd, &tipo);
        if (tipo == 'C'){
            coelhos += qtd;
        }else if (tipo == 'R'){
            ratos += qtd;
        }else if (tipo == 'S'){
            sapos += qtd;
        }
    }

    int total = coelhos + ratos + sapos;
    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", coelhos);
    printf("Total de ratos: %d\n", ratos);
    printf("Total de sapos: %d\n", sapos);
    printf("Percentual de coelhos: %.2f %%\n", (float) coelhos/total * 100);
    printf("Percentual de ratos: %.2f %%\n", (float) ratos/total  * 100);
    printf("Percentual de sapos: %.2f %%\n", (float) sapos/total  * 100);


    return 0;
}
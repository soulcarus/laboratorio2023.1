#include <stdio.h>

int main()
{
    int i, j;
    int x[3][4];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            x[i][j] = 1;
            if (x[i][j] == x[j][i])
            {
                x[i][j] = 0;
            }
            printf("%d,", x[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main()
{
    int i, j;
    int x[3][4];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
printf("Digite o valor da posicao [%d, %d%s", i, j, "]: ");
scanf("%d", &x[i][j]);
        }
    }
    // mostrar
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
printf("%d", x[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main()
{
    int i, j;
    int soma;
    int x[3][3];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
printf("Digite o valor da posicao [%d, %d%s", i,
       j, "]: ");
scanf("%d", &x[i][j]);
        }
    }
    // mostrar
    for (i = 0; i < 3; i++)
    {
        soma = 0;
        for (j = 0; j < 3; j++)
        {
soma += x[i][j];
        }
        printf("\n");
        printf("Soma linha %d, %d ", i, soma);
    }
    return 0;
}

int main()
{
    int i, j, valor, achou;
    int soma;
    int x[3][3];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
        printf("Digite um valor da posicao [%d, %d%s", i, j, "]:");
        scanf("%d", &x[i][j]);
        }
    }
    printf("Digite o valor a ser buscado:");
    scanf("%d", &valor);
    achou = 0;
    // mostrar
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
if (x[i][j] == valor)
{
    achou = 1;
}
        }
    }
    if (achou)
    {
        printf("O valor esta na matriz");
    }
    else
    {
        printf("O valor não esta na matriz");
    }
    return 0;
}

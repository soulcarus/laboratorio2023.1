#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct evento
{
    char nome[100];
    char data[11];
    int capacidade;
    float valor;
} evento;

FILE *file;

void adicionar_evento(char *nome, char *data, int capacidade, float valor)
{
    evento novo;

    strcpy(novo.nome, nome);
    strcpy(novo.data, data);
    novo.capacidade = capacidade;
    novo.valor = valor;

    file = fopen("eventos.txt", "a");
    if (file == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    fprintf(file, "%s %s %d %.2f\n", novo.nome, novo.data, novo.capacidade, novo.valor);

    fclose(file);
}

void listar_eventos()
{
    file = fopen("eventos.txt", "r");
    if (file == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    evento aux;
    int contador = 1;

    while (fscanf(file, "%s %s %d %f\n", aux.nome, aux.data, &aux.capacidade, &aux.valor) != EOF)
    {
        printf("\nEvento Número %d\n\n", contador);
        printf("Nome: %s\n", aux.nome);
        printf("Data: %s\n", aux.data);
        printf("Capacidade: %d\n", aux.capacidade);
        printf("Valor: %.2f\n\n", aux.valor);
        contador += 1;
    }

    fclose(file);
}

void atualizar_evento(int num_evento, char *nome, char *data, int capacidade, float valor)
{
    evento eventos[MAX_SIZE];
    int num_eventos = 0;

    file = fopen("eventos.txt", "r");
    if (file == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    while (fscanf(file, "%s %s %d %f\n", eventos[num_eventos].nome, eventos[num_eventos].data, &eventos[num_eventos].capacidade, &eventos[num_eventos].valor) != EOF)
        num_eventos += 1;

    fclose(file);

    if (num_evento < 1 || num_evento > num_eventos)
        printf("Número de evento inválido!\n");
    else
    {
        evento *atualizar = &eventos[num_evento - 1];

        if (strcmp(nome, "") != 0)
            strcpy(atualizar->nome, nome);

        if (strcmp(data, "") != 0)
            strcpy(atualizar->data, data);

        if (capacidade != -1)
            atualizar->capacidade = capacidade;

        if (valor != -1)
            atualizar->valor = valor;

        file = fopen("eventos.txt", "w");
        if (file == NULL)
        {
            printf("Erro na abertura do arquivo\n");
            exit(1);
        }

        for (int i = 0; i < num_eventos; i++)
            fprintf(file, "%s %s %d %.2f\n", eventos[i].nome, eventos[i].data, eventos[i].capacidade, eventos[i].valor);

        fclose(file);
    }
}

void remover_evento(int num_evento)
{
    evento eventos[MAX_SIZE];
    int num_eventos = 0;

    file = fopen("eventos.txt", "r");
    if (file == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    while (fscanf(file, "%s %s %d %f\n", eventos[num_eventos].nome, eventos[num_eventos].data, &eventos[num_eventos].capacidade, &eventos[num_eventos].valor) != EOF)
        num_eventos += 1;

    fclose(file);
    
    if (num_evento < 1 || num_evento > num_eventos)
        printf("Número de evento inválido!\n");
    else
    {
        for (int i = num_evento - 1; i < num_eventos - 1; i++)
            eventos[i] = eventos[i + 1];

        num_eventos -= 1;

        file = fopen("eventos.txt", "w");
        if (file == NULL)
        {
            printf("Erro na abertura do arquivo\n");
            exit(1);
        }

        for (int i = 0; i < num_eventos; i++)
            fprintf(file, "%s %s %d %.2f\n", eventos[i].nome, eventos[i].data, eventos[i].capacidade, eventos[i].valor);

        fclose(file);
    }
}

int main(int argc, char *argv[])
{
    char *action = argv[1];

    if (strcmp(action, "adicionar") == 0)
    {
        char *nome = argv[2];
        char *data = argv[3];
        char *capacidade_str = argv[4];
        char *valor_str = argv[5];

        int capacidade = atoi(capacidade_str);
        float valor = atof(valor_str);

        adicionar_evento(nome, data, capacidade, valor);
        printf("DEU BOM!");
    }
    else if (strcmp(action, "listar") == 0)
    {
        listar_eventos();
    }
    else if (strcmp(action, "editar") == 0)
    {
        int num_evento = atoi(argv[6]);
        char *nome = argv[2];
        char *data = argv[3];
        int capacidade = atoi(argv[4]);
        float valor = atof(argv[5]);

        atualizar_evento(num_evento, nome, data, capacidade, valor);
    }
    else if (strcmp(action, "remover") == 0)
    {
        int num_evento = atoi(argv[2]);

        remover_evento(num_evento);
    }
    else
    {
        printf("Ação inválida\n");
    }

    return 0;
}

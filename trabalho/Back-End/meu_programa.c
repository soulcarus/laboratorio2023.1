#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

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
        printf("Content-type: text/html\n\n");
        printf("<html><head><title>Erro</title></head><body>");
        printf("<h1>Erro na abertura do arquivo</h1>");
        printf("</body></html>");
        exit(1);
    }

    fprintf(file, "%s %s %d %.2f\n", novo.nome, novo.data, novo.capacidade, novo.valor);

    fclose(file);

    printf("Content-type: text/html\n\n");
    printf("<html><head><title>Sucesso</title></head><body>");
    printf("<h1>Evento adicionado com sucesso!</h1>");
    printf("</body></html>");
}

void listar_eventos()
{
    file = fopen("eventos.txt", "r");
    if (file == NULL)
    {
        printf("Content-type: text/html\n\n");
        printf("<html><head><title>Erro</title></head><body>");
        printf("<h1>Erro na abertura do arquivo</h1>");
        printf("</body></html>");
        exit(1);
    }

    evento aux;
    int contador = 1;

    printf("Content-type: text/html\n\n");
    printf("<html><head><title>Eventos</title></head><body>");
    printf("<h1>Eventos</h1>");

    while (fscanf(file, "%s %s %d %f\n", aux.nome, aux.data, &aux.capacidade, &aux.valor) != EOF)
    {
        printf("<h2>Evento Número %d</h2>", contador);
        printf("<p>Nome: %s</p>", aux.nome);
        printf("<p>Data: %s</p>", aux.data);
        printf("<p>Capacidade: %d</p>", aux.capacidade);
        printf("<p>Valor: %.2f</p>", aux.valor);
        contador += 1;
    }

    printf("</body></html>");

    fclose(file);
}

void atualizar_evento(int num_evento, char *nome, char *data, int capacidade, float valor)
{
    evento eventos[MAX_SIZE];
    int num_eventos = 0;

    file = fopen("eventos.txt", "r");
    if (file == NULL)
    {
        printf("Content-type: text/html\n\n");
        printf("<html><head><title>Erro</title></head><body>");
        printf("<h1>Erro na abertura do arquivo</h1>");
        printf("</body></html>");
        exit(1);
    }

    while (fscanf(file, "%s %s %d %f\n", eventos[num_eventos].nome, eventos[num_eventos].data, &eventos[num_eventos].capacidade, &eventos[num_eventos].valor) != EOF)
        num_eventos += 1;

    fclose(file);

    if (num_evento < 1 || num_evento > num_eventos)
    {
        printf("Content-type: text/html\n\n");
        printf("<html><head><title>Erro</title></head><body>");
        printf("<h1>Número de evento inválido!</h1>");
        printf("</body></html>");
    }
    else
    {
        evento *atualizar = &eventos[num_evento - 1];

        if (nome != NULL && strcmp(nome, "") != 0)
            strcpy(atualizar->nome, nome);

        if (data != NULL && strcmp(data, "") != 0)
            strcpy(atualizar->data, data);

        if (capacidade != -1)
            atualizar->capacidade = capacidade;

        if (valor != -1)
            atualizar->valor = valor;

        file = fopen("eventos.txt", "w");
        if (file == NULL)
        {
            printf("Content-type: text/html\n\n");
            printf("<html><head><title>Erro</title></head><body>");
            printf("<h1>Erro na abertura do arquivo</h1>");
            printf("</body></html>");
            exit(1);
        }

        for (int i = 0; i < num_eventos; i++)
            fprintf(file, "%s %s %d %.2f\n", eventos[i].nome, eventos[i].data, eventos[i].capacidade, eventos[i].valor);

        fclose(file);

        printf("Content-type: text/html\n\n");
        printf("<html><head><title>Sucesso</title></head><body>");
        printf("<h1>Evento atualizado com sucesso!</h1>");
        printf("</body></html>");
    }
}

void remover_evento(int num_evento)
{
    evento eventos[MAX_SIZE];
    int num_eventos = 0;

    file = fopen("eventos.txt", "r");
    if (file == NULL)
    {
        printf("Content-type: text/html\n\n");
        printf("<html><head><title>Erro</title></head><body>");
        printf("<h1>Erro na abertura do arquivo</h1>");
        printf("</body></html>");
        exit(1);
    }

    while (fscanf(file, "%s %s %d %f\n", eventos[num_eventos].nome, eventos[num_eventos].data, &eventos[num_eventos].capacidade, &eventos[num_eventos].valor) != EOF)
        num_eventos += 1;

    fclose(file);

    if (num_evento < 1 || num_evento > num_eventos)
    {
        printf("Content-type: text/html\n\n");
        printf("<html><head><title>Erro</title></head><body>");
        printf("<h1>Número de evento inválido!</h1>");
        printf("</body></html>");
    }
    else
    {
        for (int i = num_evento - 1; i < num_eventos - 1; i++)
            eventos[i] = eventos[i + 1];

        num_eventos -= 1;

        file = fopen("eventos.txt", "w");
        if (file == NULL)
        {
            printf("Content-type: text/html\n\n");
            printf("<html><head><title>Erro</title></head><body>");
            printf("<h1>Erro na abertura do arquivo</h1>");
            printf("</body></html>");
            exit(1);
        }

        for (int i = 0; i < num_eventos; i++)
            fprintf(file, "%s %s %d %.2f\n", eventos[i].nome, eventos[i].data, eventos[i].capacidade, eventos[i].valor);

        fclose(file);

        printf("Content-type: text/html\n\n");
        printf("<html><head><title>Sucesso</title></head><body>");
        printf("<h1>Evento removido com sucesso!</h1>");
        printf("</body></html>");
    }
}

int main()
{
    char *query_string = getenv("QUERY_STRING");
    char action[20];
    char nome[100];
    char data[11];
    int capacidade;
    float valor;
    int num_evento;

    if (query_string != NULL)
    {
        sscanf(query_string, "action=%[^&]&nome=%[^&]&data=%[^&]&capacidade=%d&valor=%f&num_evento=%d", action, nome, data, &capacidade, &valor, &num_evento);

        if (strcmp(action, "adicionar") == 0)
            adicionar_evento(nome, data, capacidade, valor);
        else if (strcmp(action, "listar") == 0)
            listar_eventos();
        else if (strcmp(action, "editar") == 0)
            atualizar_evento(num_evento, nome, data, capacidade, valor);
        else if (strcmp(action, "remover") == 0)
            remover_evento(num_evento);
    }

    return 0;
}

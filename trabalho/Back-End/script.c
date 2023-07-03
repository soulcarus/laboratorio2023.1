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

void adicionar_evento()
{
    evento novo;

    printf("Insira o nome do evento: ");
    scanf("%s", novo.nome);

    printf("Insira a data do evento (DD/MM/AAAA): ");
    scanf("%s", novo.data);

    printf("Insira a capacidade do evento: ");
    scanf("%d", &novo.capacidade);

    printf("Insira o valor do evento: ");
    scanf("%f", &novo.valor);

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

void atualizar_evento()
{
    int num_evento;
    printf("Insira o número do evento que deseja atualizar: ");
    scanf("%d", &num_evento);

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

        printf("Insira o novo nome do evento (deixe em branco para não alterar): ");
        char novo_nome[100];
        scanf("\n%[^\n]", novo_nome);
        if (strcmp(novo_nome, "") != 0)
            strcpy(atualizar->nome, novo_nome);

        printf("Insira a nova data do evento (deixe em branco para não alterar): ");
        char nova_data[11];
        scanf("\n%[^\n]", nova_data);
        if (strcmp(nova_data, "") != 0)
            strcpy(atualizar->data, nova_data);

        printf("Insira a nova capacidade do evento (digite -1 para não alterar): ");
        int nova_capacidade;
        scanf("%d", &nova_capacidade);
        if (nova_capacidade != -1)
            atualizar->capacidade = nova_capacidade;

        printf("Insira o novo valor do evento (digite -1 para não alterar): ");
        float novo_valor;
        scanf("%f", &novo_valor);
        if (novo_valor != -1)
            atualizar->valor = novo_valor;

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

void remover_evento()
{
    int num_evento;
    
    printf("Insira o número do evento que deseja remover: ");
    scanf("%d", &num_evento);

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

int main()
{
    int escolha;

    while (1)
    {
        printf("\n\nGERENCIAMENTO DE EVENTOS\n");
        printf("\n[1] Adicionar Evento\n");
        printf("[2] Listar Eventos\n");
        printf("[3] Editar Evento\n");
        printf("[4] Remover Evento\n");
        printf("[0] Sair\n");

        printf("\nInsira o número da opção: ");
        scanf("%d", &escolha);

        if (escolha == 1)
            adicionar_evento();
        else if (escolha == 2)
            listar_eventos();
        else if (escolha == 3)
            atualizar_evento();
        else if (escolha == 4)
            remover_evento();
        else if (escolha == 0)
            exit(0);
        else
        {
            printf("ESCOLHA INVÁLIDA\n");
            break;
        }
    }

    return 0;
}

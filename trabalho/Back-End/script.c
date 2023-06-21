#include <stdio.h>
#include <stdlib.h>
#include <cjson/cJSON.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct evento
{
    char nome[100];
    char data[11];
    int capacidade;
    float valor;
    struct evento *prox;
    struct evento *ant;
} evento;

evento *inicio = NULL;
int tam;
evento *fim = NULL;

FILE *file;

void inicializar(const char *nome, const char *data, int capacidade, float valor)
{

    evento *novo = malloc(sizeof(evento));
    strcpy(novo->nome, nome);
    strcpy(novo->data, data);
    novo->capacidade = capacidade;
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if (inicio == NULL && tam == 0)
    {
        inicio = novo;
        fim = novo;
    }
    else
    {
        fim->prox = novo;
        fim = novo;
    }

    tam += 1;
}

void listar_eventos()
{
    evento *aux = inicio;
    int contador = 1;

    for (int i = 0; i < tam; i++)
    {
        printf("\nEvento Número %d\n\n", contador);
        printf("Nome: %s\n", aux->nome);
        printf("Data: %s\n", aux->data);
        printf("Capacidade: %d\n", aux->capacidade);
        printf("Valor: %.2f\n\n", aux->valor);
        contador += 1;
        aux = aux->prox;
    }
}

void sobrescrever_arquivo()
{
    file = fopen("registros.json", "w");
    if (file == NULL)
    {
        printf("Erro na abertura do arquivo");
        system("pause");
        exit(1);
    }

    fprintf(file, "[\n");  // Início do array JSON

    evento *aux = inicio;

    for (int i = 0; i < tam; i++)
    {
        fprintf(file, "  {\n");  // Início do objeto JSON
        fprintf(file, "    \"Nome\": \"%s\",\n", aux->nome);
        fprintf(file, "    \"Data\": \"%s\",\n", aux->data);
        fprintf(file, "    \"Capacidade\": %d,\n", aux->capacidade);
        fprintf(file, "    \"Valor\": %.2f\n", aux->valor);
        fprintf(file, "  }");

        if (i < tam - 1)
            fprintf(file, ",");

        fprintf(file, "\n");

        aux = aux->prox;
    }

    fprintf(file, "]");  // Fim do array JSON

    fclose(file);
}


void ler_arquivo()
{
    file = fopen("registros.json", "r");
    if (file == NULL)
    {
        printf("Erro na abertura do arquivo");
        system("pause");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char *jsonString = malloc(fileSize + 1);
    fread(jsonString, 1, fileSize, file);
    jsonString[fileSize] = '\0';

    cJSON *root = cJSON_Parse(jsonString);
    int arraySize = cJSON_GetArraySize(root);

    for (int i = 0; i < arraySize; i++)
    {
        cJSON *item = cJSON_GetArrayItem(root, i);

        cJSON *nome = cJSON_GetObjectItem(item, "Nome");
        printf("Nome: %s\n", nome->valuestring);

        cJSON *data = cJSON_GetObjectItem(item, "Data");
        printf("Data: %s\n", data->valuestring);

        cJSON *capacidade = cJSON_GetObjectItem(item, "Capacidade");
        printf("Capacidade: %d\n", capacidade->valueint);

        cJSON *valor = cJSON_GetObjectItem(item, "Valor");
        printf("Valor: %.2f\n", valor->valuedouble);
    }

    fclose(file);
    free(jsonString);
}

int main()
{   
    int escolha;

    while(1){
        printf("\n\nGERENCIAMENTO DE EVENTOS\n");
        printf("\n[1] Cadastrar Eventos\n");
        printf("[2] Listar Eventos\n");
        printf("[3] Atualizar Evento\n");
        printf("[4] Remover Evento\n");
        printf("[0] Sair\n");

        printf("\nInsira o numero da opção: ");
        scanf("%d", &escolha);

        if (escolha == 1){
            inicializar("L7nnon", "27/12/2023", 72, 129.90);
            inicializar("Matue", "12/12/2023", 302, 249.90);
            inicializar("Icaro", "08/08/2023", 50, 79.90);
            inicializar("Carlinhos", "21/06/2023", 5, 29.90);
        }else if (escolha == 2){ // maneira antiga
            listar_eventos();
        }else if (escolha == 3){
            sobrescrever_arquivo();
        }else if (escolha == 4){
            ler_arquivo();
        }else if (escolha == 0){
            exit(1);
        }else{
            printf("ESCOLHA INVÁLIDA");
            break;
        }

    }
    

    listar_eventos();
    sobrescrever_arquivo();

    return 0;
}
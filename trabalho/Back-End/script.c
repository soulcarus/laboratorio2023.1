#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

typedef struct evento
{
    char *nome;
    char *data;
    int capacidade;
    float valor;
    struct evento *prox;
    struct evento *ant;
} evento;

evento *inicio = NULL;
int tam;
evento *fim = NULL;

FILE *file;

void inicializar(char *nome, char *data, int capacidade, float valor)
{

    evento *novo = malloc(sizeof(evento));
    novo->nome = nome;
    novo->data = data;
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
    file = fopen("registros.txt", "w");
    if (file == NULL)
    {
        printf("Erro na abertura do arquivo");
        system("pause");
        exit(1);
    }

    evento *aux = inicio;
    printf("teste");
    int contador = 1;

    for (int i = 0; i < tam; i++)
    {
        fputs("", aux->nome);
        printf("Data: %s\n", aux->data);
        printf("Capacidade: %d\n", aux->capacidade);
        printf("Valor: %.2f\n\n", aux->valor);
        contador += 1;
        aux = aux->prox;
    }
    fclose(file);
}

FILE *ler_arquivo()
{

    file = fopen("registros.txt", "r");
    if (file == NULL)
    {
        printf("Erro na abertura do arquivo");
        system("pause");
        exit(1);
    }
    fclose(file);

    return file;
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
            NULL;
        }else if (escolha == 4){
            NULL;
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
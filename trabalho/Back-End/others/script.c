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

void adicionar_evento()
{
    evento novo;

    printf("Content-type: text/html\n\n");
    printf("<html><body>");

    printf("<h1>Adicionar Evento</h1>");

    printf("<form action=\"/cgi-bin/meu_programa.cgi\" method=\"get\">");
    printf("<label for=\"nome\">Nome:</label>");
    printf("<input type=\"text\" id=\"nome\" name=\"nome\" required>");

    printf("<label for=\"data\">Data:</label>");
    printf("<input type=\"text\" id=\"data\" name=\"data\" required>");

    printf("<label for=\"capacidade\">Capacidade:</label>");
    printf("<input type=\"number\" id=\"capacidade\" name=\"capacidade\" required>");

    printf("<label for=\"valor\">Valor:</label>");
    printf("<input type=\"number\" step=\"0.01\" id=\"valor\" name=\"valor\" required>");

    printf("<input type=\"hidden\" name=\"action\" value=\"adicionar\">");

    printf("<input type=\"submit\" value=\"Adicionar Evento\">");
    printf("</form>");

    printf("</body></html>");
}

void listar_eventos()
{
    // Código para listar eventos
}

void atualizar_evento()
{
    // Código para atualizar evento
}

void remover_evento()
{
    // Código para remover evento
}

int main()
{
    char query[MAX_SIZE];

    if (getenv("REQUEST_METHOD") != NULL && strcmp(getenv("REQUEST_METHOD"), "GET") == 0)
    {
        if (getenv("QUERY_STRING") != NULL)
        {
            strncpy(query, getenv("QUERY_STRING"), MAX_SIZE);
            query[MAX_SIZE - 1] = '\0';
        }
    }

    if (strlen(query) > 0)
    {
        char *action = strtok(query, "&");
        if (action != NULL)
        {
            action = strtok(action, "=");
            if (action != NULL)
            {
                if (strcmp(action, "action") == 0)
                {
                    char *value = strtok(NULL, "=");
                    if (value != NULL)
                    {
                        if (strcmp(value, "adicionar") == 0)
                        {
                            adicionar_evento();
                        }
                        else if (strcmp(value, "listar") == 0)
                        {
                            listar_eventos();
                        }
                        else if (strcmp(value, "editar") == 0)
                        {
                            atualizar_evento();
                        }
                        else if (strcmp(value, "remover") == 0)
                        {
                            remover_evento();
                        }
                    }
                }
            }
        }
    }
    else
    {
        printf("Content-type: text/html\n\n");
        printf("<html><body>");

        printf("<h1>Agendamento de Eventos</h1>");

        printf("<h2>Adicionar Evento</h2>");
        printf("<form action=\"/cgi-bin/meu_programa.cgi\" method=\"get\">");
        printf("<label for=\"nome\">Nome:</label>");
        printf("<input type=\"text\" id=\"nome\" name=\"nome\" required>");

        printf("<label for=\"data\">Data:</label>");
        printf("<input type=\"text\" id=\"data\" name=\"data\" required>");

        printf("<label for=\"capacidade\">Capacidade:</label>");
        printf("<input type=\"number\" id=\"capacidade\" name=\"capacidade\" required>");

        printf("<label for=\"valor\">Valor:</label>");
        printf("<input type=\"number\" step=\"0.01\" id=\"valor\" name=\"valor\" required>");

        printf("<input type=\"hidden\" name=\"action\" value=\"adicionar\">");

        printf("<input type=\"submit\" value=\"Adicionar Evento\">");
        printf("</form>");

        printf("<h2>Listar Eventos</h2>");
        printf("<form action=\"/cgi-bin/meu_programa.cgi\" method=\"get\">");
        printf("<input type=\"hidden\" name=\"action\" value=\"listar\">");
        printf("<input type=\"submit\" value=\"Listar Eventos\">");
        printf("</form>");

        printf("<h2>Editar Evento</h2>");
        printf("<form action=\"/cgi-bin/meu_programa.cgi\" method=\"get\">");
        printf("<input type=\"hidden\" name=\"action\" value=\"editar\">");
        printf("<label for=\"num_evento\">Número do Evento:</label>");
        printf("<input type=\"number\" id=\"num_evento\" name=\"num_evento\" required>");
        printf("<input type=\"submit\" value=\"Editar Evento\">");
        printf("</form>");

        printf("<h2>Remover Evento</h2>");
        printf("<form action=\"/cgi-bin/meu_programa.cgi\" method=\"get\">");
        printf("<input type=\"hidden\" name=\"action\" value=\"remover\">");
        printf("<label for=\"num_evento\">Número do Evento:</label>");
        printf("<input type=\"number\" id=\"num_evento\" name=\"num_evento\" required>");
        printf("<input type=\"submit\" value=\"Remover Evento\">");
        printf("</form>");

        printf("</body></html>");
    }

    return 0;
}

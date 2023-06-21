#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int serverSocket, newSocket, bytesRead;
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t clientAddressLength;
    char buffer[BUFFER_SIZE];

    // Criação do socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Falha ao criar o socket");
        exit(EXIT_FAILURE);
    }

    // Configuração do endereço do servidor
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    // Vincula o socket a um endereço/porta
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Falha ao vincular o socket");
        exit(EXIT_FAILURE);
    }

    // Coloca o socket em modo de escuta
    if (listen(serverSocket, 5) == -1) {
        perror("Falha ao colocar o socket em modo de escuta");
        exit(EXIT_FAILURE);
    }

    printf("Servidor aguardando conexões na porta %d...\n", PORT);

    // Aceita conexões entrantes
    clientAddressLength = sizeof(clientAddress);
    if ((newSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLength)) == -1) {
        perror("Falha ao aceitar a conexão");
        exit(EXIT_FAILURE);
    }

    // Lê a solicitação do cliente
    memset(buffer, 0, BUFFER_SIZE);
    bytesRead = recv(newSocket, buffer, BUFFER_SIZE - 1, 0);
    if (bytesRead == -1) {
        perror("Falha ao ler a solicitação do cliente");
        exit(EXIT_FAILURE);
    }

    printf("Requisição recebida:\n%s\n", buffer);

    // Envia a resposta ao cliente
    char* response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 12\r\n\r\nHello World!";
    if (send(newSocket, response, strlen(response), 0) == -1) {
        perror("Falha ao enviar a resposta ao cliente");
        exit(EXIT_FAILURE);
    }

    printf("Resposta enviada: \n%s\n", response);

    // Fecha os sockets e encerra o servidor
    pclose(newSocket);
    pclose(serverSocket);

    return 0;
}
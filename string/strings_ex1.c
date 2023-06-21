#include <stdio.h>
#define SIZE 30

int main(){
    char nome[SIZE];
    printf("Digite seu nome: ");
    scanf("%s",nome);
    printf("Bom dia, %s.\n",nome);
    return 0;
}

/*

Biblioteca <string.h>
memchr
memcmp
memcpy
memmove
memset
strcat
strchr
strcoll
strcmp
strcpy
strcspn
strerror
strlen
strncat
strncmp
strncpy
strpbrk
strrchr
strspn
strstr
strtok
strxfrm

*/

/*

Comparação entre Strings
int strcmp( const char str1[], const char str2[] );

Cópia de uma string para outra
char* strcpy( char str1[] , const char str2[] );

Concatena uma string no final da outra
char* strcat( char str1[] , const char str2[] );

Versões com número de caracteres delimitado
int strncmp( const char str1[], const char str2[], size_t n );
char* strncpy( char str1[], const char str2[], size_t n );
char* strncat( char str1[], const char str2[], size_t n );

Busca por um caractere
char* strchr( const char str[], int c );
char* strrchr( const char str[], int c );

Busca por um caractere
char* strpbrk( const char str1[], const char str2[] )

Busca por uma substring
char* strstr( const char str1[], const char str2[] );

Divide uma string
char* strtok( char str1[], const char str2[] );
char str1[80] = "Nome - Matricula - Nota";
char str2[] = " - ";
char *t;
t = strtok(str1,str2);
while(t != NULL){
printf("%s\n",t);
t = strtok(NULL,str2);
}


*/
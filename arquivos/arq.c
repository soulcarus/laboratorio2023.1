
#include <stdio.h>
#include <stdlib.h>

// FILE *fopen(char *nome_aquivo, char *modo);

/*

r - abre um arquivo no modo leitura
• w - abre ou cria um arquivo de texto no modo de escrita
• a - abre um arquivo no modo de inclusão (append)
• r+ - abre um arquivo nos modos de leitura e escrita
• a+ - abre um arquivo nos modos de leitura e escrita
• w+ - abre um arquivo nos modos de leitura e escrita

*/

int main() {
FILE *file;
file = fopen(“texte.txt”, “w”);
if (file == NULL){
printf(“Erro na abertura do arquivo”);
system(“pause”);
exit(1);
}
fclose(file);
return 0;
}

/*
Existem funções na linguagem C que permitem ler/escrever uma sequência de caracteres,
isto é, uma string.
• fputs()
• fgets()
int fputs(char *str, FILE *fp);
int fgets(char *str, int tamanho, FILE *fp);

fopen() - criar um arquivo ou abrir um arquivo existente
fclose() - fechar um arquivo
getc() - ler um caractere de um arquivo
putc() - escrever um caractere de um arquivo
fscanf() - ler um conjunto de dados de um arquivo
fprintf() - escrever um conjunto de dados em um arquivo
getw() - ler um número inteiro de um arquivo
putw() - escrever um número inteiro em um arquivo
fseek() - definir a posição em um ponto desejado
ftell() - dar a posição atual no arquivo
rewind() - definir a posição como o ponto inicial

*/

void escreveArquivo(){
FILE *arq;
arq = fopen("exemplo.txt","w");
int i;
if(arq == NULL){
printf("Erro ao abrir o arquivo\n");
system("pause");
exit(1);
}
for (i=0; i<=10;i++)
fprintf(arq,"%d ",i);
fclose(arq);
}

void lerArquivo(){
FILE *arq;
char *result;
char str[30];
arq = fopen("exemplo.txt","r");
if(arq == NULL){
printf("Erro ao abrir o arquivo\n");
system("pause");
exit(1);
}
result = fgets(str,30,arq);
if(result==NULL)
printf("Erro na leitura do arquivo\n");
else
printf("%s", str);
fclose(arq);
}

void modificaArquivo(){
int i;
FILE *arq;
arq = fopen("exemplo.txt", "a");
if (arq == NULL){
printf("Erro ao abrir o arquivo\n");
system("pause");
exit(1);
}
for (i = 11; i <= 20; i++)
fprintf(arq, "%d ", i);
fclose(arq);
}

int main()
{
float nota, media=0.0;
FILE *arq1 = fopen("notas.txt", "w");
if (arq1 == NULL){
printf("Erro ao abrir o arquivo\n");
system("pause");
exit(1);
}else{
printf("Nota de Matamatica:\n");
scanf("%f", &nota);
fprintf(arq1, "Matemática: %.2f\n",nota);
media+=nota;
printf("Nota de Fisica:\n");
scanf("%f", &nota);
fprintf(arq1, "Fisica: %.2f\n",nota);
media+=nota;
printf("Nota de Quimica:\n");
scanf("%f", &nota);
fprintf(arq1, "Quimica: %.2f\n",nota);
media+=nota;
media/=3;
fprintf(arq1, "Media: %.2f\n",media);
printf("Notas salvas com sucesso, verifique o arquivo\n");
}
fclose(arq1);
return 0;
}


void copiaConteudo(FILE *arquivo1, FILE *arquivo2){
char leitor [1000];
while(fgets(leitor, 1000, arquivo1)!= NULL){
fputs(leitor, arquivo2);
}
}
int main()
{
FILE *arq1 = fopen("arquivo1.txt", "r");
if (arq1 == NULL)
{
printf("Erro ao abrir o arquivo\n");
system("pause");
exit(1);
}
FILE *arq2 = fopen("arquivo2.txt", "w");
copiaConteudo(arq1, arq2);
fclose(arq1);
fclose(arq2);
return 0;
}
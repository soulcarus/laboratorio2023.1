#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    char nome[50];
    float nota;
}Aluno;

int main(){
    
    Aluno variavel_aluno;

    printf("Digite o nome do aluno:\n");
    fgets(variavel_aluno.nome, 50, stdin);

    printf("Digite a matricula:\n");
    scanf("%d", &variavel_aluno.matricula);

    printf("Digite a nota:\n");
    scanf("%f", &variavel_aluno.nota);

    printf("---------Dados do aluno--------");
    printf("Matricula.........%d", variavel_aluno.matricula);
    printf("Nome..............%s", variavel_aluno.nome);
    printf("Nota..........%f", variavel_aluno.nota);

    return 0;

}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Aluno
{
    char nome[30];
    float notas[2];
    int id;
    float media;
    char situacao[10];
};
void linha()
{
    printf("------------------------------------------------------------------");
}

void lerDadosAluno(struct Aluno aluno[], int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        printf("\nNome do aluno: ");
        fflush(stdin);
        scanf(" %s", &aluno[i].nome);
        printf("Primeira nota do aluno %s: ", aluno[i].nome);
        scanf("%f", &aluno[i].notas[0]);
        printf("Segunda nota do aluno %s: ", aluno[i].nome);
        scanf("%f", &aluno[i].notas[1]);
        aluno[i].id = i + 1;
        linha();
    }
}

void calcularMedia(struct Aluno aluno[], int quantidade)
{
    float media;
    const int len = 2;
    for (int i = 0; i < quantidade; i++)
    {
        media = (aluno[i].notas[0] + aluno[i].notas[1]) / len;
        aluno[i].media = media;
    }
}

void definirSituacaoDoAluno(struct Aluno aluno[], int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        if (aluno[i].media >= 7)
        {
            strcpy(aluno[i].situacao, "aprovado");
        }
        else
        {
            strcpy(aluno[i].situacao, "reprovado");
        }
    }
}
void mostrarResultado(struct Aluno aluno[], int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        linha();
        printf("\nnome do Aluno : %s.\n", aluno[i].nome);
        printf("matricula: %d.\n", aluno[i].id);
        printf("media : %.2f.\n", aluno[i].media);
        printf("situacao: %s.\n", aluno[i].situacao);
        linha();
    }
}

int definirQuantidadeAlunos()
{
    int quantidade;
    printf("Quantos alunos na turma: ");
    scanf("%d", &quantidade);
    return quantidade;
}

void app()
{
    system("cls");
    int quantidade = definirQuantidadeAlunos();
    struct Aluno aluno[quantidade];
    lerDadosAluno(aluno, quantidade);
    calcularMedia(aluno, quantidade);
    definirSituacaoDoAluno(aluno, quantidade);
    mostrarResultado(aluno, quantidade);
}

int main()
{
    app();
    return 0;
}
/*
    1. Faça um programa para corrigir uma prova com 10 questões de múltipla escolha
    (a, b, c, d ou e), em uma turma com 3 alunos.
     Cada questão vale 1 ponto. Leia o gabarito, e para cada aluno leia sua matricula
     (número inteiro) e suas respostas. Calcule e escreva:
      Para cada aluno, escreva sua matrícula, suas respostas, e sua nota.
     O percentual de aprovação, assumindo média 7.0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>

char questoes[3][10];
int matricula[3];
float notas[3];
char gabarito[10];

void setGabarito(char *gabarito)
{
    char v[] = {"abcde"};
    for (int i = 0; i < 10; i++)
    {
        gabarito[i] = v[rand() % 6];
    }
}

void setNotas(float *notas)
{
    for (int i = 0; i < 3; i++)
    {
        notas[i] = 0.0;
    }
}

int main(void)
{
    setlocale(LC_ALL, "");
    srand(time(NULL));
    setGabarito(&gabarito[0]);
    setNotas(&notas[0]);
    int i = 0;
    int j = 0;

    for (i = 0; i < 3; i++)
    {
        printf("\nALUNO %d:\n", i + 1);
        printf("\nDigite sua matrícula:");
        scanf("%d", &matricula[i]);

        printf("\nDigite as suas questões:");
        for (j = 0; j < 10; j++)
        {
            printf("\nQuestão %d:", j + 1);
            setbuf(stdin, NULL);
            scanf(" %c", &questoes[i][j]);

            if (
                tolower(questoes[i][j]) != 'a' &&
                tolower(questoes[i][j]) != 'b' &&
                tolower(questoes[i][j]) != 'c' &&
                tolower(questoes[i][j]) != 'd' &&
                tolower(questoes[i][j]) != 'e')
            {
                puts("Opção inválida!");
                j--;
                continue;
            }

            if (questoes[i][j] == gabarito[j])
            {
                notas[i] += 1.0;
            }
        }
    }

    printf("\nGabarito:\n");
    for (j = 0; j < 10; j++)
    {
        printf("[%c]", gabarito[j]);
    }
    puts(" ");

    for (i = 0; i < 3; i++)
    {
        printf("\nALUNO %d:\n", i + 1);
        printf("\nNota:%.2f\n", notas[i]);
        if (notas[i] >= 7.0)
        {
            puts("Você está aprovado.");
        }
        else
        {
            puts("Você está reprovado.");
        }

        printf("\nMatrícula:%d", matricula[i]);
    }
    return 0;
}
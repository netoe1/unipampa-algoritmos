/*
    5) Escrever um algoritmo que leia 5 conjuntos de 2 valores, o primeiro representando o número de um aluno, e o segundo representando a sua altura em centímetros. Encontre o aluno mais alto e o mais baixo.
     Mostre o número do aluno mais alto e do mais baixo, junto com suas alturas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "");
    float alturaMaior = 0.0;
    float alturaMenor = 0.0;
    int nAlunoMaior = 0;
    int nAlunoMenor = 0;
    int numero = 0;
    float altura = 0;
    int x = 0;

    printf("\nDigite um número para um aluno:");
    scanf("%d", &numero);
    setbuf(stdin, NULL);

    printf("\nDigite a altura do aluno:");
    scanf("%f", &altura);
    setbuf(stdin, NULL);

    alturaMaior = altura;
    nAlunoMaior = numero;

    for (x == 1; x <= 4; x++)
    {
        printf("\nDigite um número para um aluno:");
        scanf("%d", &numero);
        setbuf(stdin, NULL);
        printf("\nDigite a altura do aluno:");
        scanf("%f", &altura);
        setbuf(stdin, NULL);

        if (altura >= alturaMaior)
        {
            alturaMaior = altura;
            nAlunoMaior = numero;
        }
        else
        {
            alturaMenor = altura;
            nAlunoMenor = numero;
        }
    }

    printf("\nnAlunoMaior:%d\nalturaAlunoMaior:%.2f\n", nAlunoMaior, alturaMaior);
    printf("\nnAlunoMenor:%d\nalturaAlunoMenor:%.2f\n", nAlunoMenor, alturaMenor);
    return 0;
}
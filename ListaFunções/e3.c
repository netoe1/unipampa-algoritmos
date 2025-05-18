/*
    3 - Escreva uma função que receba 3 notas de um aluno e uma letra. Se a letra for A a função retorna a média aritmética das notas do aluno,
    se for P, a sua média ponderada (pesos: 5, 3 e 2) e se for H, a sua média harmônica.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
void getNotas(float n[3])
{
    int i = 0;
    puts("\nDigite as 3 notas dos alunos:");
    scanf("%f %f %f", &n[0], &n[1], &n[2]);
}

char getLetra()
{
    char l = '0';

    puts("\nDiga qual operação vai fazer:\nA-> Média Aritmética\nP-> Média Ponderada\nH-> Média Harmônica\n-->:");
    setbuf(stdin, NULL);
    scanf("%c", &l);
    l = tolower(l);

    if (l != 'a' || l != 'p' || l != 'h')
    {
        return 'a';
    }

    return l;
}

int main(void)
{
    setlocale(LC_ALL, "");
    float notas[3];
    char op = ' ';
    float res = 0.0;
    getNotas(notas);
    op = getLetra();

    switch (op)
    {
    case 'a':
        res = (notas[0] + notas[1] + notas[2]) / 3;
        break;
    case 'p':
        res = (5 * notas[0] + 3 * notas[1] + 2 * notas[2]) / 3;
        break;
    case 'h':
        res = 3 / (1 / notas[0] + 1 / notas[1] + 1 / notas[2]);
        break;
    default:
        puts("Opção incorreta.");
        break;
    }

    printf("\nResultado[%c]->:%.2f\n", op, res);
    return 0;
}
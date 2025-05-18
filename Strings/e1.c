/*
    Faça um programa que receba o nome completo e salário de um funcionário, calcule e mostre o
nome e novo salário, sabendo-se que este sofreu um aumento de 25%.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char nome[30] = {"0"};
float salario = 0.0;
int main(void)
{
    setlocale(LC_ALL, "");
    puts("Digite o seu nome completo:");
    setbuf(stdin, NULL);
    fgets(nome, strlen(nome), stdin);

    puts("Digite o seu salário, você terá 25% de aumento!");
    scanf("%f", &salario);

    salario = salario * 1.25;

    printf("\nFuncionário:%s", nome);
    printf("\nO seu salário é:R$ %.2f", salario);
    return EXIT_SUCCESS;
}
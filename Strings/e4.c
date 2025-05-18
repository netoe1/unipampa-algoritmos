/*Escreva um programa que leia um nome completo do teclado e o escreva na tela no formato
Sobrenome, Nome. Exemplo: Nome → Fulano / Sobrenome → Silva Gates / Saída no vídeo →
Silva Gates, Fulano*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(void)
{
    setlocale(LC_ALL, "");
    char nome[10];
    char sobrenome[10];

    puts("Digite o seu nome:");
    fflush(stdin);

    fgets(nome, 9, stdin);
    nome[strspn(nome, "\n")] = '\0';
    
    puts("Digite o seu sobrenome:");
    fflush(stdin);
    nome[strspn(nome, "\n")] = '\0';
    fgets(sobrenome, 9, stdin);

    printf("\n%s,%s.", sobrenome, nome);

    return 0;
}
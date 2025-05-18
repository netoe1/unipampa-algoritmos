/*
  Faça um programa que leia um nome (string1) e um sobrenome (string2)
   e mostre na tela:
A. Nome completo, guardado em uma string diferente das lidas (string3)
B. Quantidade de caracteres do nome, sobrenome e nome completo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void)
{
  setlocale(LC_ALL, "");
  char nome[30];
  char sobrenome[30];
  char nomeCompleto[60];

  puts("\nDigite o seu nome:");
  fflush(stdin);
  fgets(nome, 29, stdin);
  nome[strcspn(nome, "\n")] = '\0';

  puts("\nDigite o seu sobrenome:");
  fflush(stdin);
  fgets(sobrenome, 29, stdin);
  sobrenome[strcspn(sobrenome, "\n")] = '\0';

  strcat(nomeCompleto, nome);
  strcat(nomeCompleto, " ");
  strcat(nomeCompleto, sobrenome);
  printf("\nNome Completo:%s\n", nomeCompleto);
  printf("\nQuantidade de caracteres em nome:%d\n", (int)strlen(nome));
  printf("\nQuantidade de caracteres em sobrenome:%d\n", (int)strlen(sobrenome));
  printf("\nQuantidade de caracteres em nomeCompleto:%d\n", (int)strlen(nomeCompleto));

  return 0;
}

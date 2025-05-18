/*
2) Elaborar um algoritmo que leia N vezes a idade, peso e sexo de indivíduos. Calcular a média de idade e de peso dos indivíduos do sexo feminino, a média de idade e de peso dos indivíduos do sexo masculino.

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float peso = 0.0;
int idade = 0;
char sexo = ' ';

int idadeHomem = 0;
int nHomem = 0;
float pesoHomem = 0.0;

int idadeMulher = 0;
float pesoMulher = 0.0;
int nMulher = 0;

int main(void)
{
  while (sexo != '0')
  {

    printf("\nDigite o seu sexo: H - Homem, M- Mulher,0 - Sair:");
    setbuf(stdin, NULL);
    scanf("%c", &sexo);

    if (sexo == '0')
    {
      break;
    }

    printf("\nDigite a sua idade:");
    scanf("%d", &idade);

    printf("\nDigite o seu peso:");
    scanf("%f", &peso);

    if (tolower(sexo) == 'h')
    {
      nHomem++;
      idadeHomem += idade;
      pesoHomem += peso;
    }
    else if (tolower(sexo) == 'm')
    {
      nMulher++;
      idadeMulher += idade;
      pesoMulher += peso;
    }
    else
    {
      printf("\nSexo inválido\n");
      idade = 0;
      peso = 0.0;
      sexo = ' ';
    }
  }

  printf("\nMedia HOMENS:\n");
  printf("\nPeso:%.2f\n", (pesoHomem / nHomem));
  printf("\nIdade:%.2f\n",(float) (idadeHomem / nHomem));

  printf("\nMedia Mulheres:\n");
  printf("\nPeso:%.2f\n", (pesoMulher / nMulher));
  printf("\nIdade:%.2f\n",(float) (idadeMulher / nMulher));

  return 0;
}

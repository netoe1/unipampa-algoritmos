/*

Um quadrado mágico de ordem N (sendo N um número ímpar) é um
arranjo de números de 1 a n 2 em uma matriz quadrada de tal modo que a soma de cada linha, coluna e diagonal é a mesma.

A figura mostra um quadrado mágico de ordem 5. A regra para gerá-lo é
relativamente fácil de observar: comece com o 1 no meio da primeira
linha, então siga para cima e para esquerda diagonalmente, (quando sair
do quadrado suponha que os lados superior e inferior estão unidos e que
os lados da direita e esquerda também) em cada quadrado que passar,
coloque o valor do quadrado anterior mais 1 (um), quando atingir um
quadrado já ocupado, desça um quadrado e continue seguindo a diagonal
até ter preenchido todos os quadrados. Escrever um algoritmo que gere o
quadrado mágico para o um número de ordem 15.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main(void)
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

    return 0;
}
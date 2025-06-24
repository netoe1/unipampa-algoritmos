/*
4: Jogo da Média
Crie uma struct chamada Jogador com os campos: nome, pontuações[3] (array de 3 int)
Permita ao usuário cadastrar 5 jogadores e calcule a média de pontuação de cada um,
mostrando:
• Nome
• Média
• O jogador com melhor média
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef struct
{
    char nome[30];
    int pontuacoes[3];
    float media;
} Jogador;

Jogador jogador[5];

void cadastrarJogadores()
{
    for (int i = 0; i < 5; i++)
    {
        printf("\nJogador %d\n", i + 1);
        printf("\nDigite o nome do jogador:");
        setbuf(stdin, NULL);
        fgets(jogador[i].nome, sizeof(jogador[i].nome) - 1, stdin);
        jogador[i].nome[strcspn(jogador[i].nome, "\n")] = '\0';

        puts("Digite as 3 pontuações");
        scanf("%d %d %d", &jogador[i].pontuacoes[0], &jogador[i].pontuacoes[1], &jogador[i].pontuacoes[2]);

        jogador[i].media = (jogador[i].pontuacoes[0] + jogador[i].pontuacoes[1] + jogador[i].pontuacoes[2]) / 3;
    }
}

void mostrarJogadores()
{
    for (int i = 0; i < 5; i++)
    {
        printf("\nNome:%s\nPontuações = [%d %d %d]\nMédia:%.2f", jogador[i].nome, jogador[i].pontuacoes[0], jogador[i].pontuacoes[1], jogador[i].pontuacoes[2], jogador[i].media);
    }
}

void verMelhorMedia()
{

    float melhorMedia = jogador[0].media;
    for (int i = 0; i < 5; i++)
    {
        if (melhorMedia < jogador[i].media)
        {
            melhorMedia = jogador[i].media;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (jogador[i].media == melhorMedia)
        {
            puts("=====Melhor média=====");
            printf("\nNome:%s\nPontuações = [%d %d %d]\nMédia:%.2f", jogador[i].nome, jogador[i].pontuacoes[0], jogador[i].pontuacoes[1], jogador[i].pontuacoes[2], jogador[i].media);
        }
    }
}

int main(void)
{
    setlocale(LC_ALL, "");
    cadastrarJogadores();
    mostrarJogadores();
    verMelhorMedia();
    return 0;
}
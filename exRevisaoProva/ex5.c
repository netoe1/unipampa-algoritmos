/*
5: Clima de 7 Dias
Crie uma struct Clima com: diaSemana[10], temperaturaMax, temperaturaMin.
Permita o cadastro de dados para 7 dias. Depois:
• Mostre o dia mais quente
• Mostre o dia mais frio
• Calcule a média da temperatura máxima e mínima da semana
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    int diaSemana[10];
    float temperaturaMax;
    float temperaturaMin;
} Clima;

void sgets(char *s, size_t size)
{
    setbuf(stdin, NULL);
    fgets(s, size, stdin);
    s[strcspn(s, "\n")] = '\0';
}

Clima semana;
void cadastrarClima()
{
    for (int i = 0; i < 7; i++)
    {
        printf("\nDia %d\n", i + 1);
        puts("\nDigite a");
    }
}
int main(void)
{
    setlocale(LC_ALL, "");
    return 0;
}
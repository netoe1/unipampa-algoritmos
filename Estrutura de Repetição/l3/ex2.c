/*
    Ler nome, sexo e idade. Se sexo for feminino e idade menor que 25. Imprimir o
nome da pessoa e a palavra ACEITA. Caso contrário, imprimir NAO ACEITA.
*/
#include <stdio.h>

int idade = 0;
char sexo = ' ';
char nomePessoa[64];
int main(void)
{
    printf("\nDigite o seu nome:");
    setbuf(stdin, NULL);
    fgets(nomePessoa, 63, stdin);

    printf("\nInforme o seu sexo:H - Homem, M - Mulher:");
    setbuf(stdin, NULL);
    scanf("%c", &sexo);

    printf("\nInforme a sua idade:");
    scanf("%d", &idade);

    if(sexo == 'M' && idade < 25){
        printf("\nACEITA\n");
    }
    else{
        printf("\nNAO ACEITA\n");
    }
    return 0;
}
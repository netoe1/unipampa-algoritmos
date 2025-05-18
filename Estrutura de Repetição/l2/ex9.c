/*9- Escrever um programa que receba vários números inteiros no teclado e no final imprimir a
média dos números múltiplos de 3. Para sair digitar 0 (zero).*/
#include <stdio.h>

int main(void)
{
    int n = 1;
    int sumn = 0;
    int i = 0;

    while (n != 0)
    {
        printf("\nDigite algum nro, digite 0 para sair:");
        scanf("%d", &n);
        if (n % 3 == 0 && n != 0)
        {
            sumn += n;
            i++;
        }
    }

    printf("\nA media dos numeros foram:%d\n", (sumn / i));
    return 0;
}
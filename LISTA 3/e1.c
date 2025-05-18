/*
  1) Escrever um algoritmo que leia um valor V maior que 10. Escrever todos os números pares entre 1 e o valor V.
*/

#include <stdio.h>
#include <stdlib.h>


int main(void){
  int n = 0;
    
  printf("\nDigite um valor maior que 10:");
  scanf("%d",&n);
  
  if(n < 10){
    printf("\n O valor que vc digitou esta fora do limite ;-;");
    return EXIT_FAILURE;
  }
  
  int i = 0;
  for(i = 1;i <= n;i++){
    if(i % 2 == 0){
        printf("\nValor:[%d]",i);
    }
  }
}

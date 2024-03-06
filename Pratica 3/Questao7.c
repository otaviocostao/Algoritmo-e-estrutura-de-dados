#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void checar_numero(int num1, int num2){

    //Checar se é igual:
    if(num1==num2){
        printf("\nO número %d é igual ao número %d\n", num1, num2);
    }else{
        printf("\nO número %d é difetente do número %d\n", num1, num2);
    }

    //Checar se o numero 1 é par ou impar
    if(num1 % 2 ==0){
        printf("\nO número %d é par\n", num1);
    }else{
        printf("\nO número %d é ímpar\n", num1);
    }

    //Checar se o numero 2 é par ou impar

    if(num2 % 2 ==0){
        printf("\nO número %d é par\n", num2);
    }else{
        printf("\nO número %d é ímpar\n", num2);
    }
}

int main (){
    setlocale(LC_ALL, "Portuguese");

    int num1, num2;

    do{
        printf("\n-- Checando dois numeros --\n\n");
        printf("Caso deseje sair digite um valor negativo no primeiro número\n");
        printf("Digite o numero 1: ");
        scanf("%d", &num1);

        if(num1<0){
            printf("\nSaindo\n");
            break;
        }

        printf("\nDigite o numero 2: ");
        scanf("%d", &num2);

        checar_numero(num1, num2);

    }while(num1>0);
}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void checar_numero(int num1, int num2){

    //Checar se � igual:
    if(num1==num2){
        printf("\nO n�mero %d � igual ao n�mero %d\n", num1, num2);
    }else{
        printf("\nO n�mero %d � difetente do n�mero %d\n", num1, num2);
    }

    //Checar se o numero 1 � par ou impar
    if(num1 % 2 ==0){
        printf("\nO n�mero %d � par\n", num1);
    }else{
        printf("\nO n�mero %d � �mpar\n", num1);
    }

    //Checar se o numero 2 � par ou impar

    if(num2 % 2 ==0){
        printf("\nO n�mero %d � par\n", num2);
    }else{
        printf("\nO n�mero %d � �mpar\n", num2);
    }
}

int main (){
    setlocale(LC_ALL, "Portuguese");

    int num1, num2;

    do{
        printf("\n-- Checando dois numeros --\n\n");
        printf("Caso deseje sair digite um valor negativo no primeiro n�mero\n");
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
//Escrever uma função que recebe o valor de tres parametros do tipo char, e mostre estes valores em ordem crescente, por exemplo, se ch1, ch2, ch3 tem armazenado respectivamente "b", "a", "c" serão apresentado "a", "b", "c".

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void orderChar(char ch1, char ch2, char ch3){
    char temp;

    if(ch1>ch2){
        temp = ch1;
        ch1 = ch2;
        ch2 = temp;
    }

    if(ch2 > ch3){
        temp = ch2;
        ch2 = ch3;
        ch3 = temp;
    

        if(ch1>ch2){
            temp = ch1;
            ch1 = ch2;
            ch2 = temp;
        }
    }

    printf("Ordem crescente dos caracteres: %c, %c, %c\n", ch1, ch2, ch3);

}

int main (){

    setlocale(LC_ALL, "Portuguese");

    char ch1, ch2, ch3;

    printf("Digite a primeira letra: ");
    scanf("%c", &ch1);
    getchar();

    printf("\nDigite a segunda letra: ");
    scanf("%c", &ch2);
    getchar();

    printf("\nDigite a terceira letra: ");
    scanf("%c", &ch3);
    getchar();

    orderChar(ch1, ch2, ch3);

    system("pause");
    return 0;
}
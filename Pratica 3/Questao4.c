//Escrever uma função que recebe o valor de tres parametros do tipo char, e mostre estes valores em ordem crescente, por exemplo, se ch1, ch2, ch3 tem armazenado respectivamente "b", "a", "c" serão apresentado "a", "b", "c".

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Função para ordenar os caracteres:

void orderChar(char ch1[2], char ch2[2], char ch3[2]){
    char temp[2];

    if(strcmp(ch1,ch2)>0){ 
        strcpy(temp, ch1);
        strcpy(ch1, ch2);
        strcpy(ch2, temp);
    }

    if(strcmp(ch2,ch3)> 0){
        strcpy(temp, ch2);
        strcpy(ch2, ch3);
        strcpy(ch3, temp);
    

        if(strcmp(ch1,ch2)>0){
            strcpy(temp, ch1);
            strcpy(ch1, ch2);
            strcpy(ch2, temp);
        }
    }

    
    printf("Ordem crescente dos caracteres: %s, %s, %s\n", ch1, ch2, ch3);

}

int main (){

    setlocale(LC_ALL, "Portuguese");

    char ch1[2], ch2[2], ch3[2];

    printf("Digite a primeira letra: ");
    gets(ch1);

    printf("\nDigite a segunda letra: ");
    gets(ch2);

    printf("\nDigite a terceira letra: ");
    gets(ch3);

    orderChar(ch1, ch2, ch3); // Chamando a função

    system("pause");
    return 0;
}
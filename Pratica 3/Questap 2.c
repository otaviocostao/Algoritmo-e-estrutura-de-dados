#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int bissexto(int ano){
    if(ano % 400 == 0){
        return 1;
    }else if(ano % 4 == 0 && ano % 100 !=0 ){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int ano, condicao;

    printf("\n-- Verificar se o ano é bissexto --\n");

    printf("\nDigite o ano: ");
    scanf("%d", &ano);

    condicao = bissexto(ano);

    if(condicao == 1){
        printf("\nO ano %d é bissexto.\n",ano);
    }else{
        printf("\nO ano %d não é bissexto\n", ano);
    }

    system("pause");
    return 0;
}
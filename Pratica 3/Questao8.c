#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int numero_primo(int num){
    int i;

    if(num<=1){
        return 0; // FALSO
    }
    
    for(i=2; i*i <= num; i++){
        if(num % i == 0){
            return 0; // FALSO
        }
    }

    return 1; // VERDADEIRO
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num, primo;
    while(1){
        printf("\n-- Checar se o número é primo --\n\n");

        printf("\nCaso deseje sair digite 0");
        printf("\nDigite um número: ");
        scanf("%d", &num);

        if(num==0){
            printf("\nSaindo.\n");
            break;
        }

        primo = numero_primo(num);
        if(primo == 1){
            printf("\nO número %d é primo\n", num);
            system("pause");
        }else{
            printf("\nO número %d não é primo\n", num);
            system("pause");
        }

    }

    system("pause");
    return 0;

}
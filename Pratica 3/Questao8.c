#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void numero_primo(int num){
    int i, primo =1;

    if(num<=1){
        printf("\nO número %d não é primo\n", num);
        return;
    }
    
    for(i=2; i*i <= num; i++){
        if(num % i == 0){
            primo = 0;
            break;
        }
    }

    if(primo == 1){
        printf("\nO número %d é primo\n", num);
    }else{
        printf("\nO número %d não é primo\n", num);
    }
    system("pause");
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num;
    while(1){
        printf("\n-- Checar se o número é primo --\n\n");

        printf("\nCaso deseje sair digite 0");
        printf("\nDigite um número: ");
        scanf("%d", &num);

        if(num==0){
            printf("\nSaindo.\n");
            break;
        }

        numero_primo(num);

    }

    system("pause");
    return 0;

}
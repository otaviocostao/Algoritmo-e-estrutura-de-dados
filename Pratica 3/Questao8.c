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
        printf("\n-- Checar se o n�mero � primo --\n\n");

        printf("\nCaso deseje sair digite 0");
        printf("\nDigite um n�mero: ");
        scanf("%d", &num);

        if(num==0){
            printf("\nSaindo.\n");
            break;
        }

        primo = numero_primo(num);
        if(primo == 1){
            printf("\nO n�mero %d � primo\n", num);
            system("pause");
        }else{
            printf("\nO n�mero %d n�o � primo\n", num);
            system("pause");
        }

    }

    system("pause");
    return 0;

}
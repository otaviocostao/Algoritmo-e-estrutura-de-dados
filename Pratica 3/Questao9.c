#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int soma_numero(int n){
    int i, resultado=0;
    
    for(i=1; i<=n; i++){
        resultado += i;
    }

    return resultado;
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num, soma;

    printf("\n-- Somando os N primeiros n�meros --\n\n");

    printf("Digite um valor para N: ");
    scanf("%d", &num);

    soma = soma_numero(num);

    printf("\nA soma dos N primeiros n�meros antes de %d �: %d\n", num, soma);

    system("pause");
    return 0;
}
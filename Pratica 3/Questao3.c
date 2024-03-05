#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float reajuste_valor(float preco, float reajuste){
    float preco_final;

    preco_final = preco + (preco * (reajuste/100));
    return preco_final;

}

int main (){
    setlocale(LC_ALL, "Portuguese");

    float preco, preco_final, reajuste;

    printf("-- Reajuste dos preços --\n\n");

    printf("Digite o preço do produto: ");
    scanf("%f", &preco);
    
    printf("\nDigite o reajuste em %% que deseja dar ao produto: ");
    scanf("%f", &reajuste);

    preco_final = reajuste_valor(preco, reajuste);

    printf("\nO produto passou a ser R$%.2f, com o aumento de %.2f%%\n", preco_final, reajuste);

    system("pause");
    return 0;
    }

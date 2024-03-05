#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float potencia(float base, float expoente){
    float resultado = 1;
    int i;

    if (expoente == 0){
        return 1;  
    }

    if(expoente >= 1){
        for(i=1; i<=expoente; i++){
            resultado *= base;
        }
    }

    else{
        for(i=1; i<= -expoente; i++){
            resultado *= 1 / base;
        }
    }

    return resultado;
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    float val1, val2, resultado;

    printf("-- Calcular uma potencia --\n\n");

    printf("Digite o primeiro valor (Valor da base): ");
    scanf("%f", &val1);

    printf("\nDigite o segundo valor (Valor do expoente): ");
    scanf("%f", &val2);

    resultado = potencia(val1, val2);

    printf("O resultado de %.2f elevado à %.2f é %.2f\n", val1, val2, resultado);

    system("pause");
    return 0;

}
//QUESTAO 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Letra a)

void mensagem(){
    printf("***********************\n");
    printf("** FELIZ ANIVERSARIO **\n");
    printf("***********************\n");

}

//Letra b)

float converter_temp(float fahrenheit){
    float celsius;
    celsius = (fahrenheit - 32) * 5 /9;
    return celsius;
}

//Letra c)

float calc_area (float base, float altura){
    float area;
    area = base * altura;
    return area;
}

// Letra d))

int fatorial(int num){
    int fatorial = 1;
    int i;

    if (num == 0 || num == 1) {
        return 1;
    } else {
        for (i = 2; i <= num; i++) {
            fatorial *= i;
        }
        return fatorial;
    }
}

int main (){
    
    setlocale(LC_ALL, "Portuguese");

    float temperatura, f; 
    float base, altura, area;
    int num, fat;
    int opcao;
    
    do{
        printf("Selecione a função que deseja acessar:\n[0]a)\n[1]b)\n[2]c)\n[3]d)\n[4]SAIR\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("\n");
            mensagem();
            break;
    
        case 1:
            printf("\n-- Converter temperatura --\n");
            printf("\nDigite a temperatura em Fahrenheit: ");
            scanf("%f", &f);

            temperatura = converter_temp(f);
            printf("A temperatura em Celsius é: %.2f\n", temperatura);
            break;

        case 2:
            printf("\n-- Cálculo da área do retângulo --\n");

            printf("\nDigite o valor da base: ");
            scanf("%f", &base);

            printf("\nDigite o valor da altura: ");
            scanf("%f", &altura);

            area = calc_area(base, altura);
            printf("\nA área do retângulo é: %.2f\n", area);
            break;

        case 3:
            printf("\n-- Fatorial de um numero --\n");
            printf("\nDigite um numero: ");
            scanf("%d", &num);

            fat = fatorial(num);
            printf("\nA fatorial de %d é: %d\n", num, fat); 
            break;

        case 4:
            printf("\nSaindo.\n");
            break;
    
        default:
            printf("Valor não encontrado.\n");
            break;
        }
        }while(opcao != 4);

    system("pause");
    return 0;
}
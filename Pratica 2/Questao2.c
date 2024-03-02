//*2.Escrever um programa que cadastre o nome, a altura, o peso, o cpf e sexo de algumas pessoas. Com os dados cadastrados,
//em seguida localizar uma pessoas através do seu CPF e imprimir o seu IMC.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 3

struct molde{

    char nome[100];
    float altura;
    float peso;
    char cpf[15];
    char sexo[15];

}pessoa[TAM];

int main(){

    setlocale(LC_ALL, "Portuguese");

    int i, condicao, encontrado=0;
    char busca[11];

    printf("Cadastro de pessoas:\n\n");

    for(i=0;i<TAM;i++){
        printf("Digite o nome: ");
        gets(pessoa[i].nome);

        printf("\nDigite a altura: ");
        scanf("%f", &pessoa[i].altura);

        printf("\nDigite o peso: ");
        scanf("%f", &pessoa[i].peso);

        printf("\nDigite o CPF: ");
        getchar();
        gets(pessoa[i].cpf);

        printf("\nDigite o sexo: ");
        gets(pessoa[i].sexo);
    }

    printf("\n\nDigite o CPF que deseja buscar: ");
    gets(busca);

    for(i=0;i<TAM;i++){
        condicao = strcmp(busca,pessoa[i].cpf);
        if(condicao==0){
            printf("\n");
            puts(pessoa[i].nome);
            printf("%.2f", pessoa[i].altura);
            printf("\n%.2f", pessoa[i].peso);
            printf("\n");
            puts(pessoa[i].cpf);
            puts(pessoa[i].sexo);

            encontrado = 1;
            break;
        }
    }

    if(encontrado!=1){
        printf("\nO CPF buscado não foi encontrado\n");
    }

    system("pause");
    return 0;
}

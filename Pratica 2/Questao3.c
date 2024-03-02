// Escrever um programa que cadastre vários produtos. Em seguida, imprima uma lista com o código e nome da cada produto. Por último, consulte o preço de um produto através de seu código. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 10

struct produtos{
    char nome[100];
    char codigo[50];
    float preco;
}produto[TAM];

int main(){
    setlocale(LC_ALL, "Portuguese");
    int i, encontrado=0, condicao=1;
    char head_nome[100], head_codigo[100], busca[50];

    printf("Cadastro de produtos:\n");

    for(i=0;i<TAM;i++){
        printf("\nDigite o nome do produto: ");
        gets(produto[i].nome);

        printf("Digite o código do produto: ");
        gets(produto[i].codigo);

        printf("Digite o valor do produto: ");
        scanf("%f", &produto[i].preco);
        getchar();
    }

    printf("Lista de produtos:\n");
    for(i=0; i<TAM; i++){
        strcpy(head_nome, "Nome do produto: ");
        strcat(head_nome, produto[i].nome);
        puts(head_nome);

        strcpy(head_codigo, "Codigo do produto: ");
        strcat(head_codigo, produto[i].codigo);
    }

    printf("Digite o codigo para buscar: ");
    gets(busca);

    for(i=0;i<TAM;i++){
        condicao = strcmp(busca, produto[i].codigo);
        if(condicao==0){
            strcpy(head_nome, "Nome do produto: ");
            strcat(head_nome, produto[i].nome);
            puts(head_nome);
            
            strcpy(head_codigo, "Codigo do produto: ");
            strcat(head_codigo, produto[i].codigo);

            printf("Preço do produto: %.2f\n");

            encontrado = 1;
            break;
        }
    }

    if(encontrado != 1){
        printf("O produto não foi encontrado!\n")
    }

    system("pause");
    return 0;
}

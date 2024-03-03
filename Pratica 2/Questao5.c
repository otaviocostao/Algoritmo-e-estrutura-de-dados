//Faça um programa que leia um vetor com os dados de 5 carros: marca (máximo 15  letras), ano e preço. Leia um valor p e mostre as informações de todos os carros com preço menor que p. Repita este processo até que seja lido um valor p = 0.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 2

struct info{
    char marca[15];
    int ano;
    float preco;
}carro[TAM];

int main (){

    setlocale(LC_ALL, "Portuguese");

    int i;
    float p;
    char head_marca[40];
    
    //Recebendo as informações:
    for(i=0; i<TAM; i++){
        
        printf("\nInformações do %d carro: \n\n", i+1);

        printf("Digite a marca do carro:\n");
        gets(carro[i].marca);

        printf("Digite o ano do carro:\n");
        scanf("%d", &carro[i].ano);

        printf("Digite o preço do carro:\n");
        scanf("%f", &carro[i].preco);
        getchar();
    }

    //Digitar o valor para buscar
    do{

        printf("\nDigite um valor para buscar:\n");
        printf("Caso deseje sair digite [0].\n");
        scanf("%f", &p);
    
        for (i=0; i<TAM; i++){
            if(carro[i].preco <= p){
                printf("\nLista de veículos:\n\n");
                
                strcpy(head_marca,"Marca: ");
                strcat(head_marca, carro[i].marca);
                puts(head_marca);

                printf("Ano: %d", carro[i].ano);

                printf("\nPreco: R$%.2f\n\n", carro[i].preco);
                system("pause");
            }
        }
    }while(p!=0);

    system("pause");
    return 0;
}
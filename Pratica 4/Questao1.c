// Utilizando uma pilha, escreva um programa que disponha de uma rotina que receba um n√∫mero inteiro positivo no formato decimal e converta este n√∫mero para o formato bin√°rio.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 50

int pilha[max];
int topo;

void menu();
void converter();
void desempilhar();
void inicializa();


int main(){
    int continuar;
    inicializa();
    setlocale(LC_ALL, "Portuguese");

    do{
        menu();
        printf("\nDeseja continuar no menu?[1]Sim [2]N„o\n");
        scanf("%d", &continuar);
    }while(continuar==1);

    system("pause");
    return 0;    
}

void menu(){
    int opcao;

    system("cls");

    printf("--- MENU ---\n\n");
    printf("[1] - Converter um numero para binario\n");
    printf("[2] - Exibir o numero convertido\n");
    printf("[3] - Sair\n");
    scanf("%d", &opcao);


    switch (opcao)
    {
    case 1:
        inicializa();
        converter();
        break;
    
    case 2:
    printf("\nNumero convertido:\n");
        desempilhar();
        break;

    case 3:
        printf("\nSaindo...\n");
        break;

    default:
        printf("\nOpÁ„o invalida!\n");
        break;
    }

}

void converter(){
    int resto, numero;
    printf("Digite o n√∫mero para ser convertido: ");
    scanf("%d", &numero);

    while(numero>0){
        resto = numero % 2;
        numero = numero/2;
        topo++;
        pilha[topo] = resto;
    }

}

void desempilhar(){
    int i;
    for(i=topo; i>=0; i--){
        printf("%d", pilha[i]);
    }
    printf("\n");
}

int ver_vazia(){
    if(topo == -1){
        return 1;
    }else{
        return 0;
    }
}

int ver_cheia(){
    if(topo == max-1){
        return 1;
    }else{
        return 0;
    }
}

void inicializa(){
    topo =-1;
}
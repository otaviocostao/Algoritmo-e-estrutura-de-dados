// Utilizando uma pilha, escreva um programa que disponha de uma rotina que receba um número inteiro positivo no formato decimal e converta este número para o formato binário.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 10

int pilha[max];
int topo;

void menu();
void converter(int);
void desempilhar();
void inicializa();


int main(){
    inicializa();
    setlocale(LC_ALL, "Portuguese");

    menu();

    system("pause");
    return 0;    
}

void menu(){
    int numero;

    system("cls");

    printf("Digite o número para ser convertido: ");
    scanf("%d", &numero);

    converter(numero);
    desempilhar();

}

void converter(int elemento){
    int resto;
    while(elemento>0){
        resto = elemento % 2;
        elemento = elemento/2;
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
#include <stdio.h>
#include <stdlib.h>

void soma10(int);

void soma10p(int *);

int main(void){
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    printf("\nNumero lido originalmente: %d", numero);

    soma10(numero); //chamada de funcao

    printf("\nNo retorno por valor: %d", numero);

    soma10p(&numero); //Chhamada de funcao com ponteiro

    printf("\nNo retorno por referencia: %d", numero);

}

void soma10(int x){
    x = x + 10;
    printf("\nX apos a soma na funcao por valor: %d", x);
}

void soma10p(int *x){
    *x = *x + 10;
    printf("\nX apos a soma na funcao por valor: %d", *x);
}
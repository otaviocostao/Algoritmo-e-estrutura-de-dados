#include <stdio.h>
#include <stdlib.h>
#define TAM 20

int main(){
    int *vetor, i, x, achou;
    vetor = (int*) malloc(TAM*sizeof(int));

    for(i=0; i<TAM; i++){
        printf("\nDigite o %d valor do vetor:\n", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("\nDigite o valor para buscar: ");
    scanf("%d", &x);

    for(i=0; i<TAM; i++){
        if(vetor[i]==x){
            printf("\nO valor %d foi encontrado na posicao %d", x, i);
            achou = 1;
        }
    }

    if(!achou){
        printf("\nO valor digitado nao esta no vetor\n");
    }

    return 0;
}
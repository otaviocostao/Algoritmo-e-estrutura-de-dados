// Dada uma fila sequencial, escreva um programa que inverta a ordem dos elementos da fila, utilizando para isso uma pilha. Exibir a pilha e a fila. 

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 10

int fila[max];
int pilha[max];
int inicio, fim, topo;

void menu();

//CABEÇALHO DA FILA
int fila_ver_cheia();
int fila_ver_vazia();
void fila_inserir();
void fila_remover();
void listar_fila();
void incializar_fila();

//CABEÇALHO PILHA
void inverter();
void listar_pilha();
void inicializar_pilha();
int pilha_ver_vazia();

int main(){
    incializar_fila();
    inicializar_pilha();

    setlocale(LC_ALL, "Portuguese");
    int resp=1;

    while(resp==1){
        menu();

        printf("\nDeseja continuar no menu?\n[1]Sim [2]Não\n");
        scanf("%d", &resp);
    }
    system("pause");
    return 0;
}

void menu(){
    int opcao;
    system("cls");

    printf("[1] - Inserir um elemento na fila\n");
    printf("[2] - Remover um elemento na fila\n");
    printf("[3] - Listar a fila\n");
    printf("[4] - Inverter fila na pilha\n");
    printf("[5] - Exibir elementos da pilha\n");
    printf("[6] - Verificar se a fila está cheia\n");
    printf("[7] - Verificar se a fila está vazia\n");
    printf("[8] - Sair\n");

    printf("\nDigite o numero da função que deseja: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        fila_inserir();
        break;
    
    case 2:
        fila_remover();
        break;
    
    case 3:
        listar_fila();
        break;

    case 4:
        inverter();
        break;
    
    case 5:
        listar_pilha();
        break;

    case 6:
        if(fila_ver_cheia()==1){
            printf("\nA fila está cheia.\n");
        }else{
            printf("\nA fila não está cheia.\n");
        }
        break;
    
    case 7:
        if(fila_ver_vazia()==1){
            printf("\nA fila está vazia.\n");
        }else{
            printf("\nA fila não está vazia.\n");
        }
        break;

    case 8:
        printf("\nSaindo.\n");
        break;
    
    default:
        printf("\nOpção invalida.\n");
        break;
    }
}

int fila_ver_cheia(){
    if(fim == max){
        return 1;
    }else{
        return 0;
    }
}

int fila_ver_vazia(){
    if(inicio == fim){
        return 1;
    }else{
        return 0;
    }
}

void fila_inserir(){
    int elemento;

    if(fila_ver_cheia()==1){
        printf("\nA fila está cheia, não é possivel inserir.\n");
    }else{
        printf("\nDigite o elemento que deseja armazenar: ");
        scanf("%d", &elemento);
        fila[fim] = elemento;
        fim++;
    }


};

void fila_remover(){
    if(fila_ver_vazia()==1){
        printf("\nA fila está vazia, não é possivel remover algum elemento.\n");
    }else{
        printf("\nO valor removido foi %d.", fila[inicio]);
        inicio++;
    }
}

void listar_fila(){
    int i;

    if(fila_ver_vazia()==1){
        printf("A fila está vazia, não é possivel listar.\n");
    }else{
        for(i=inicio; i<fim; i++){
            printf("%d\n", fila[i]);
        }
    }

}

void incializar_fila(){
    inicio =0;
    fim = 0;
}

void inverter(){
    int i;
    inicializar_pilha();

    for(i=inicio; i<fim; i++){
        topo++;
        pilha[topo] = fila[i];
    }
}

void listar_pilha(){
    int i;
    if(pilha_ver_vazia()==1){
        printf("\nA pilha está vazia, não é possivel listar\n");
    }else{
        for(i=topo; i>=0; i--){
            printf("%d\n", pilha[i]);
        }
    }
}

void inicializar_pilha(){
    topo =-1;
}

int pilha_ver_vazia(){
    if(topo == -1){
        return 1;
    }else{
        return 0;
    }
}

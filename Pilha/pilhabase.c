#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 6

int pilha[max];
int topo;

void menu();
void inserir(int);
void remover();
void ver_topo();
void listagem();
int ver_vazia();
int ver_cheia();
void buscar();
void inicializa();


int main(){
    inicializa();
    setlocale(LC_ALL, "Portuguese");

    int resp = 1;

    while(resp == 1){
        menu();
        printf("\nDeseja continuar no menu?\n[1]Sim [2]Não\n");
        scanf("%d", &resp);
    }

    system("pause");
    return 0;    
}

void menu(){
    int opcao, elemento;
    system("cls");

    printf("-------MENU-------\n");
    printf("[1] - INSERIR\n");
    printf("[2] - REMOVER\n");
    printf("[3] - VER TOPO\n");
    printf("[4] - LISTAGEM\n");
    printf("[5] - VERIFICAR SE ESTÁ VAZIA\n");
    printf("[6] - VERIFICAR SE ESTÁ CHEIA\n");
    printf("[7] - BUSCAR\n");
    printf("[8] - SAIR\n\n");

    printf("Digite a opção que deseja: ");
    scanf("%d", &opcao);

    switch (opcao)
    {

    //INSERIR ELEMENTO
    case 1:
        if(ver_cheia()==1){
            printf("\nA pilha está cheia, não é possivel inserir.\n");
        }else{
            printf("Digite o elemento que deseja inserir: ");
            scanf("%d", &elemento);
            inserir(elemento);
        }
        break;

    //REMOVER ELEMENTO
    case 2:
        if(ver_vazia()==1){
            printf("\nA pilha está vazia, não é possivel remover.\n");

        }else{
            remover();
        }
        break;

    //VER O ELEMENTO DO TOPO DA PILHA
    case 3:
        if(ver_vazia()==1){
            printf("\nA pilha está vazia, não é possivel ver o topo.\n");
        }else{
        ver_topo();
        break;
        }

    //LISTAR OS ELEMENTOS DA PILHA
    case 4:
        if(ver_vazia()==1){
            printf("\nA pilha está vazia, não é possivel listar os elementos.\n");
        }else{
            listagem();
        }
        break;

    //VERIFICAR SE A PILHA ESTA VAZIA
    case 5:
        if(ver_vazia()==1){
            printf("\nA pilha está vazia\n");
        }else{
            printf("\nA pilha não está vazia\n");
        }
        break;

    //VERIFICAR SE A PILHA ESTA CHEIA
    case 6:
        if(ver_cheia()==1){
            printf("\nA pilha está cheia.\n");
        }else{
            printf("\nA pilha não está cheia.\n");
        }
        break;

    //BUSCAR ELEMENTO NA PILHA
    case 7:
        if(ver_vazia()==1){
            printf("\nA pilha está vazia, não é possivel buscar elementos.\n");
        }else{
            buscar();
        }
        break;

    //SAIR
    case 8:
        printf("\nSaindo!\n");
        break;
    
    default:
        printf("\nOpção invalida!\n");
        break;
    }
}

void inserir(int elemento){
    topo++;
    pilha[topo] = elemento;
}

void remover(){
    printf("O elemento removido foi: %d", pilha[topo]);
    topo--;
}

void ver_topo(){
    printf("O elemento do topo é: %d", pilha[topo]);
}

void listagem(){
    int i;
    for(i=topo; i>=0; i--){
        printf("%d \n", pilha[i]);
    }
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

void buscar(){
    int i, elemento, achei=0;
    
    printf("Digite o elemento que deseja buscar: ");
    scanf("%d", &elemento);

    for(i=topo; i>=0; i--){
        if(pilha[i]==elemento){
            printf("\nO elemento %d foi encontrado na pilha\n", pilha[i]);
            achei = 1;
        }
    }

    if(!achei){
        printf("\nO elemento buscado não foi encontrado.\n");
    }
}

void inicializa(){
    topo =-1;
}
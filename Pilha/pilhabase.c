#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 6

int pilha[max];
int topo=-1;

void menu();
void inserir(int);
void remover();
void ver_topo();
void listagem();
int ver_vazia();
int ver_cheia();
void buscar();


int main(){
    setlocale(LC_ALL, "Portguese");
    int opcao;

    menu();
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    case 6:
        /* code */
        break;
    case 7:
        /* code */
        break;
    case 8:
        /* code */
        break;
    
    default:
        break;
    }
}

void menu(){
    
    system("cls");

    printf("-------MENU-------\n");
    printf("[1] - INSERIR\n");
    printf("[2] - REMOVER\n");
    printf("[3] - VER TOPO\n");
    printf("[4] - LISTAGEM\n");
    printf("[5] - VER VAZIA\n");
    printf("[6] - VER CHEIA\n");
    printf("[7] - BUSCAR\n");
    printf("[8] - SAIR\n\n");

    printf("Digite a opção que deseja: ");
}

void inserir(int elemento){
    if(topo!=max){
        printf("Digite o elemento que deseja inserir: ");
        scanf("%d", &elemento);
        topo++;
        pilha[topo] = elemento;
    }
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
    if(topo == max){
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
        if(pilha[topo]==elemento){
            printf("\nO elemento %d foi encontrado na pilha\n", pilha[i]);
            achei = 1;
        }
    }

    if(!achei){
        printf("\nO elemento buscado não foi encontrado.\n");
    }
}
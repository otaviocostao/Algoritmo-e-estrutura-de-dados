#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 3

int fila[max];
int inicio, fim;

void menu();
int ver_cheia();
int ver_vazia();
void inserir();
void remover ();
void ver_inicio();
void ver_fim();
void listagem();
void buscar();
void inicializar();

int main(){
    inicializar();
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

    printf("[1] - Inserir um elemento\n");
    printf("[2] - Remover um elemento\n");
    printf("[3] - Listar a fila\n");
    printf("[4] - Buscar elemento\n");
    printf("[5] - Verificar se está cheia\n");
    printf("[6] - Verificar se está vazia\n");
    printf("[7] - Ver o início\n");
    printf("[8] - Ver o final\n");
    printf("[9] - Sair\n");

    printf("\nDigite o numero da função que deseja: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        inserir();
        break;
    
    case 2:
        remover();
        break;
    
    case 3:
        listagem();
        break;
    
    case 4:
        buscar();
        break;
    
    case 5:
        if(ver_cheia()==1){
            printf("\nA fila está cheia.\n");
        }else{
            printf("\nA fila não está cheia.\n");
        }
        break;
    
    case 6:
        if(ver_vazia()==1){
            printf("\nA fila está vazia.\n");
        }else{
            printf("\nA fila não está vazia.\n");
        }
        break;
    
    case 7:
        ver_inicio();
        break;
    
    case 8:
        ver_fim();
        break;

    case 9:
        printf("\nSaindo.\n");
        break;
    
    default:
        printf("\nOpção invalida.\n");
        break;
    }

}

int ver_cheia(){
    if(fim == max){
        return 1;
    }else{
        return 0;
    }
}

int ver_vazia(){
    if(inicio == fim){
        return 1;
    }else{
        return 0;
    }
}

void inserir(){
    int elemento;

    if(ver_cheia()==1){
        printf("\nA fila já está cheia, não é possivel inserir.\n");
    }else{
        printf("\nDigite o elemento que deseja armazenar: ");
        scanf("%d", &elemento);
    }

    fila[fim] = elemento;
    fim++;
};

void remover(){
    if(ver_vazia()==1){
        printf("\nA fila está vazia, não é possível remover algum elemento.\n");
    }else{
        printf("\nO valor removido foi %d.", fila[inicio]);
        inicio++;
    }
}

void ver_inicio(){
    if(ver_vazia()==1){
        printf("\nA fila está vazia, não é possivel ver o inicio.\n");
    }else{
        printf("\nO valor do inicio é: %d.\n", fila[inicio]);
    }
}

void ver_fim(){
    if(ver_vazia()==1){
        printf("\nA lista está vazia, não é possivél ver o final.\n");
    }else{
        printf("\nO valor do final é: %d.\n", fila[fim-1]);
    }
}

void listagem(){
    int i;
    if(ver_vazia()==1){
        printf("A fila está vazia, não é possivel listar.\n");
    }else{
        for(i=inicio; i<fim; i++){
            printf("%d\n", fila[i]);
        }
    }

}

void buscar(){
    int i, achei=0, elemento;

    if(ver_vazia()==1){
        printf("\nA fila está vazia, não é possivel buscar.\n");
    }else{
        printf("\nDigite o elemento que deseja buscar: ");
        scanf("%d", &elemento);

        for(i=inicio; i<fim; i++){
            if(fila[i] == elemento){
                printf("\nO elemento %d foi encontrado na fila na posição %d", elemento, i);
                achei = 1;
            }
        }

        if(!achei){
            printf("\nO elemento %d não foi encontrado na fila.\n", elemento);
        }
    }
}

void inicializar(){
    inicio =0;
    fim = 0;
}

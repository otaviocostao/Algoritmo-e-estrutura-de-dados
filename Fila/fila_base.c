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
    setlocale(LC_ALL, "portuguese");
    int resp=1;

    while(resp==1){
        menu();

        printf("\nDeseja continuar no menu?\n[1]Sim [2]N?o\n");
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
    printf("[5] - Verificar se est? cheia\n");
    printf("[6] - Verificar se est? vazia\n");
    printf("[7] - Ver o in?cio\n");
    printf("[8] - Ver o final\n");
    printf("[9] - Sair\n");

    printf("\nDigite o numero da fun??o que deseja: ");
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
            printf("\nA fila est? cheia.\n");
        }else{
            printf("\nA fila n?o est? cheia.\n");
        }
        break;
    
    case 6:
        if(ver_vazia()==1){
            printf("\nA fila est? vazia.\n");
        }else{
            printf("\nA fila n?o est? vazia.\n");
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
        printf("\nOp??o invalida.\n");
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
        printf("\nA fila j? est? cheia, n?o ? possivel inserir.\n");
    }else{
        printf("\nDigite o elemento que deseja armazenar: ");
        scanf("%d", &elemento);

        fila[fim] = elemento;
        fim++;
    }
};

void remover(){
    if(ver_vazia()==1){
        printf("\nA fila est? vazia, n?o ? poss?vel remover algum elemento.\n");
    }else{
        printf("\nO valor removido foi %d.", fila[inicio]);
        inicio++;
    }
}

void ver_inicio(){
    if(ver_vazia()==1){
        printf("\nA fila est? vazia, n?o ? possivel ver o inicio.\n");
    }else{
        printf("\nO valor do inicio ?: %d.\n", fila[inicio]);
    }
}

void ver_fim(){
    if(ver_vazia()==1){
        printf("\nA lista est? vazia, n?o ? possiv?l ver o final.\n");
    }else{
        printf("\nO valor do final ?: %d.\n", fila[fim-1]);
    }
}

void listagem(){
    int i;
    if(ver_vazia()==1){
        printf("A fila est? vazia, n?o ? possivel listar.\n");
    }else{
        for(i=inicio; i<fim; i++){
            printf("%d\n", fila[i]);
        }
    }

}

void buscar(){
    int i, achei=0, elemento;

    if(ver_vazia()==1){
        printf("\nA fila est? vazia, n?o ? possivel buscar.\n");
    }else{
        printf("\nDigite o elemento que deseja buscar: ");
        scanf("%d", &elemento);

        for(i=inicio; i<fim; i++){
            if(fila[i] == elemento){
                printf("\nO elemento %d foi encontrado na fila na posi??o %d", elemento, i);
                achei = 1;
            }
        }

        if(!achei){
            printf("\nO elemento %d n?o foi encontrado na fila.\n", elemento);
        }
    }
}

void inicializar(){
    inicio =0;
    fim = 0;
}

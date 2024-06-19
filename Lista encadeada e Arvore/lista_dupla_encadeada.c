#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No {
    int dado;
    struct No *ant;
    struct No *prox;
} No;

No *inicio = NULL;
No *fim = NULL;


void menu();
int ver_vazia();
void inserirInicio(int);
void inserirFim(int);
void removerInicio();
void removerFim();
void verInicio();
void verFim();
void listagem();
void buscar(int);

int main(){
    setlocale(LC_ALL, "portuguese");
    int resp=1;

    while(resp==1){
        menu();

        printf("\nDeseja continuar no menu?\n[1]Sim [2]Nao\n");
        scanf("%d", &resp);
    }
    system("pause");
    return 0;
}

void menu(){
    int opcao, num, x;
    system("cls");

    printf("[1] - Inserir um elemento no inicio\n");
    printf("[2] - Inserir um elemento no fim\n");
    printf("[3] - Remover um elemento no inicio\n");
    printf("[4] - Remover um elemento no fim\n");
    printf("[5] - Listar a lista\n");
    printf("[6] - Buscar elemento\n");
    printf("[7] - Verificar se esta vazia\n");
    printf("[8] - Ver o inicio\n");
    printf("[9] - Ver o final\n");
    printf("[10] - Sair\n");

    printf("\nDigite o numero da funcao que deseja: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("\nDigite o elemento que deseja inserir: ");
        scanf("%d", &num);

        inserirInicio(num);
        break;
    
    case 2:
        printf("\nDigite o elemento que deseja inserir: ");
        scanf("%d", &num);

        inserirFim(num);
        break;
    
    case 3:
        if(ver_vazia()==1){
        printf("\nA lista esta vazia, nao e possivel remover algum elemento.\n");
    }else{
        removerInicio();
    }
        break;
    
    case 4:
        if(ver_vazia()==1){
        printf("\nA lista esta vazia, nao e possivel remover algum elemento.\n");
    }else{
        removerFim();
    }
        break;
    
    case 5:
        if(ver_vazia()==1){
            printf("\nA lista esta vazia, nao e possivel listar os elementos.\n");
        }else{
            listagem();
        }
        break;
    
    case 6:
        if(ver_vazia()==1){
            printf("\nA lista esta vazia, nao e possivel buscar.\n");
        }else{
            printf("\nDigite o elemento que deseja buscar: ");
            scanf("%d", &x);
            buscar(x);
        }
        break;
    
    case 7:
        if(ver_vazia()==1){
            printf("\nA lista esta vazia.\n");
        }else{
            printf("\nA lista nao esta vazia.\n");
        }
        break;
    
    case 8:
        if(ver_vazia()==1){
            printf("\nA lista esta vazia, nao e possivel ver o inicio.\n");
        }else{
            verInicio();
        }
        break;
    
    case 9:
        if(ver_vazia()==1){
            printf("\nA lista esta vazia, nao e possivel ver o fim.\n");
        }else{
            verFim();
        }
        break;

    case 10:
        printf("\nSaindo.\n");
        break;
    
    default:
        printf("\nOpcao invalida.\n");
        break;
    }

}

int ver_vazia(){
    if(inicio==NULL){
        return 1;
    }else{
        return 0;
    }
}

void inserirInicio(int num){
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = num;
    novoNo->ant = NULL;
    novoNo->prox = inicio;

    if(inicio==NULL){
        inicio = novoNo;
        fim = novoNo;
    }else{
        inicio->ant = novoNo;
        inicio = novoNo;
    }

}

void inserirFim(int num){
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = num;
    novoNo->ant = fim;
    novoNo->prox = NULL;

    if(inicio==NULL){
        inicio = novoNo;
        fim = novoNo;
    }else{
        fim->prox = novoNo;
        fim = novoNo;
    }

}

void removerInicio(){
    No *temp = inicio;

    if(inicio==fim){
        inicio=NULL;
        fim=NULL;
    }else{
        inicio= inicio->prox;
        inicio->ant= NULL;
    }
    free(temp);
}

void removerFim(){
    No *temp = fim;

    if(inicio==fim){
        inicio=NULL;
        fim=NULL;
    }else{
        fim= fim->ant;
        fim->prox= NULL;
    }
    free(temp);
}

void verInicio(){
    printf("\nO elemento do inicio e: %d\n", inicio->dado);
}

void verFim(){
    printf("\nO elemento do fim e: %d\n", fim->dado);
}

void listagem(){
    No *temp = inicio;

    while (temp != NULL)
    {
        printf("%d ", temp->dado);
        temp=temp->prox;
    }
    printf("\n");
}

void buscar(int x){
    No *temp = inicio;
    int pos = 0, achei=0;

    while (temp != NULL)
    {
        pos++;
        if(temp->dado == x){
            printf("\nO elemento %d foi encontrado na posicao %d", temp->dado, pos);
            achei=1;
        }
        temp = temp->prox;
    }

    if(!achei){
        printf("\nO elemento %d nao foi encontrado\n", x);
    }
    
}
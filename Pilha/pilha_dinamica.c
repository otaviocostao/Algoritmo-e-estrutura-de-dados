#include <stdio.h>
#include <stdlib.h>

struct Node{
    int dado;
    struct Node *prox;
};

struct Node *topo = NULL;

void menu();
void inserir(int);
void remover();
void ver_topo();
void listagem();
int ver_vazia();
void buscar(int);


int main(){
    int resp = 1;

    while(resp == 1){
        menu();
        printf("\nDeseja continuar no menu?\n[1]Sim [2]Nao\n");
        scanf("%d", &resp);
    }

    system("pause");
    return 0;    
}

void menu(){
    int opcao, elemento, elemento_buscar;;
    system("cls");

    printf("-------MENU-------\n");
    printf("[1] - INSERIR\n");
    printf("[2] - REMOVER\n");
    printf("[3] - VER TOPO\n");
    printf("[4] - LISTAGEM\n");
    printf("[5] - VERIFICAR SE ESTA VAZIA\n");
    printf("[6] - BUSCAR\n");
    printf("[7] - SAIR\n\n");

    printf("Digite a opcao que deseja: ");
    scanf("%d", &opcao);

    switch (opcao)
    {

    //INSERIR ELEMENTO
    case 1:
        printf("Digite o elemento que deseja inserir: ");
        scanf("%d", &elemento);
        inserir(elemento);
        break;

    //REMOVER ELEMENTO
    case 2:
        if(ver_vazia()==1){
            printf("\nA pilha esta vazia, nao e possivel remover.\n");

        }else{
            remover();
        }
        break;

    //VER O ELEMENTO DO TOPO DA PILHA
    case 3:
        if(ver_vazia()==1){
            printf("\nA pilha esta vazia, nao e possivel ver o topo.\n");
        }else{
            ver_topo();
        break;
        }

    //LISTAR OS ELEMENTOS DA PILHA
    case 4:
        if(ver_vazia()==1){
            printf("\nA pilha esta vazia, nao e possivel listar os elementos.\n");
        }else{
            listagem();
        }
        break;

    //VERIFICAR SE A PILHA ESTA VAZIA
    case 5:
        if(ver_vazia()==1){
            printf("\nA pilha esta vazia\n");
        }else{
            printf("\nA pilha nao esta vazia\n");
        }
        break;


    //BUSCAR ELEMENTO NA PILHA
    case 6:
        if(ver_vazia()==1){
            printf("\nA pilha esta vazia, nao e possivel buscar elementos.\n");
        }else{
            printf("\nDigite o elemento que deseja buscar: ");
            scanf("%d", &elemento_buscar);
            buscar(elemento_buscar);
        }
        break;

    case 7:
        printf("\nSaindo!\n");
        break;
    
    default:
        printf("\nOpcao invalida!\n");
        break;
    }
}

void inserir(int elemento){
    struct Node *novoNo = (struct Node*)malloc(sizeof(struct Node));
    if(novoNo){
        printf("\nErro ao alocar memoria\n");
    };
    
    novoNo->dado = elemento;
    novoNo->prox = topo;
    topo = novoNo;
    printf("\nElemento %d adicionado na pilha.\n", elemento);
}

void remover(){
    struct Node *temp = topo;
    topo = topo->prox;
    printf("\nElemento removido da pilha: %d.\n", temp->dado);
    free(temp);
}

void ver_topo(){
    printf("O elemento do topo: %d", topo->dado);
}

void listagem(){
    struct Node *temp = topo;
    printf("\nElementos da pilha:\n");
    while(temp != NULL){
        printf("%d\n", temp->dado);
        temp = temp->prox;
    }
}

int ver_vazia(){
    return(topo==NULL);
}

void buscar(int elemento){
    int posicao=1, achei=0;
    struct Node *temp = topo;

    while(temp != NULL){
        if(temp ->dado == elemento){
            printf("\nO elemento %d foi encontrado na posicao %d", elemento, posicao);
            achei=1;
        }
        temp = temp->prox;
        posicao++;
    }

    if(!achei){
        printf("\nO elemento %d nao foi encontrado na pilha\n", elemento);
    }
}
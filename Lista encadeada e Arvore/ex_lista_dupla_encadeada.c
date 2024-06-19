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
int contador = 0;

void menu();
int ver_vazia();
void inserirInicio(int);
void inserirFim(int);
void listagem();
void trocar(int, int);

int main(){
    setlocale(LC_ALL, "portuguese");

    menu();

    system("pause");
    return 0;
}

void menu(){
    int i, opcao, num, m, n;
    system("cls");
    
    for(i=0; i<5; i++){
        printf("[1] - Inserir um elemento no inicio\n");
        printf("[2] - Inserir um elemento no fim\n");

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

        default:
            printf("\nOpcao invalida.\n");
            break;
        }
    }
    printf("\nA lista foi preenchida, seus valores sao:\n\n");
    listagem();

    printf("Trocar o valor de m e n");
    printf("\nDigite o valor de m: ");
    scanf("%d", &m);

    printf("\nDigite o valor de n: ");
    scanf("%d", &n);

    trocar(m, n);

    listagem();
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

void listagem(){
    No *temp = inicio;

    while (temp != NULL)
    {
        printf("%d ", temp->dado);
        temp=temp->prox;
    }
    printf("\n");
}

void trocar(int m, int n){
    No *temp = inicio;
    No *temp2 = inicio;
    int pos=0, pos_m=0, pos_n=0;

    while (temp != NULL)
    {
        pos++;
        if(temp->dado == m){
            pos_m=pos;
        }
        else

        if(temp->dado == n){
            pos_n=pos;
        }
        temp = temp->prox;
    }

    pos=0;
    while (temp2 != NULL){
        pos++;

        if(pos == pos_m){
            temp2->dado = n;
        }

        if(pos== pos_n){
            temp2->dado = m;
        }
        temp2 = temp2->prox;
    }
    
}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct No {
    int dado;
    struct No* prox;
};

struct fila {
    struct No* ini;
    struct No* fim;
};

struct fila f;

void menu();
int ver_vazia(struct fila *f);
void inserir(struct fila *f, int);
void remover (struct fila *f);
void ver_inicio(struct fila *f);
void ver_fim(struct fila *f);
void listagem(struct fila *f);
void buscar(struct fila *f, int);
void inicializar(struct fila *f);
void media_elementos(struct fila *f);

int main(){
    inicializar(&f);
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

    printf("[1] - Inserir um elemento\n");
    printf("[2] - Remover um elemento\n");
    printf("[3] - Listar a fila\n");
    printf("[4] - Buscar elemento\n");
    printf("[5] - Verificar se esta vazia\n");
    printf("[6] - Ver o inicio\n");
    printf("[7] - Ver o final\n");
    printf("[8] - Ver media dos elementos\n");
    printf("[9] - Sair\n");

    printf("\nDigite o numero da funcao que deseja: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("\nDigite o elemento que deseja inserir: ");
        scanf("%d", &num);

        inserir(&f, num);
        break;
    
    case 2:
        if(ver_vazia(&f)==1){
        printf("\nA fila esta vazia, nao e possivel remover algum elemento.\n");
    }else{
        remover(&f);
    }
        break;
    
    case 3:
        listagem(&f);
        break;
    
    case 4:
        if(ver_vazia(&f)==1){
            printf("\nA fila esta vazia, nao e possivel ver o inicio.\n");
        }else{
            printf("\nDigite o elemento que deseja buscar: ");
            scanf("%d", &x);
            buscar(&f, x);
        }
        break;
    
    case 5:
        if(ver_vazia(&f)==1){
            printf("\nA fila esta vazia.\n");
        }else{
            printf("\nA fila nao esta vazia.\n");
        }
        break;
    
    case 6:
        if(ver_vazia(&f)==1){
            printf("\nA fila esta vazia, nao e possivel ver o inicio.\n");
        }else{
            ver_inicio(&f);
        }
        break;
    
    case 7:
        if(ver_vazia(&f)==1){
            printf("\nA fila esta vazia, nao e possivel ver o fim.\n");
        }else{
            ver_fim(&f);
        }
        break;

    case 8:
        if(ver_vazia(&f)==1){
            printf("\nA fila esta vazia, nao e possivel ver a media");
        }else{
            media_elementos(&f);
        }
        break;

    case 9:
        printf("\nSaindo.\n");
        break;
    
    default:
        printf("\nOpcao invalida.\n");
        break;
    }
}

void inicializar(struct fila *f){
    f->ini = NULL;
    f->fim = NULL;
}

int ver_vazia(struct fila *f){
    return (f->ini == NULL);
}

void inserir(struct fila *f, int num){
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));

    if(novoNo==NULL){
        printf("\nMemoria insuficiente\n");
        return;
    }
    novoNo->dado = num;
    novoNo->prox = NULL;

    if(f->fim == NULL){
        f->ini = novoNo;
        f->fim = novoNo;
    }else{
        f->fim->prox = novoNo; // Corrigir aqui para usar f->fim->prox
        f->fim = novoNo;
    }
    printf("\nO elemento %d foi inserido na fila\n", f->fim->dado);
}

void remover(struct fila *f){
    struct No* temp = f->ini;
    int dado = temp->dado;
    f->ini = f->ini->prox;
    if (f->ini == NULL) {
        f->fim = NULL;
    }
    free(temp);
    printf("O valor retirado é: %d\n", dado);
}

void ver_inicio(struct fila *f){
    printf("\nO elemento do inicio e %d.\n", f->ini->dado);
}

void ver_fim(struct fila *f){
    printf("\nO elemento do fim e %d.\n", f->fim->dado);
}

void listagem(struct fila *f){
    struct No* temp = f->ini;
    printf("Elementos na fila:\n");
    while (temp != NULL) {
        printf("%d ", temp->dado);
        temp = temp->prox;
    }
    printf("\n");
}

void buscar(struct fila *f, int x){
    struct No* temp = f->ini;
    int posicao = 0;
    int achei = 0;
    while (temp != NULL) {
        posicao++;
        if (temp->dado == x) {
            printf("O elemento %d foi encontrado na fila na posicao %d \n", temp->dado, posicao);
            achei = 1;
        }
        temp = temp->prox;
    }
    if (!achei) {
        printf("O elemento buscado não foi encontrado \n");
    }
}

void media_elementos(struct fila *f){
    struct No* temp = f->ini;
    int soma_elementos=0, contador_elementos=0;
    float media;

    while(temp!=NULL){
        soma_elementos = soma_elementos + temp->dado;
        temp = temp->prox;
        contador_elementos++;
    }
    printf("soma=%d", soma_elementos);
    printf("soma=%d", contador_elementos);

    media = (float)soma_elementos/contador_elementos;
    printf("\n\nA media dos elementos inseridos e: %.2f\n", media);
}

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int dado;
    struct Node *prox;
};

struct Node *topo = NULL;

struct Node2{
    int dado2;
    struct Node2 *prox2;
};

struct Node2 *topo2 = NULL;

void menu();

void inserir(int);
void inserir2(int);

void remover();
void remover2();

void listagem();
void listagem2();

int ver_vazia();
int ver_vazia2();

void ver_maior();
void ver_maior2();

void ver_menor();
void ver_menor2();

void ver_media();
void ver_media2();

void qtd_par();

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
    int opcao, elemento, elemento2;
    system("cls");

    printf("-------MENU-------\n");
    printf("[1] - INSERIR NA PILHA 1\n");
    printf("[2] - INSERIR NA PILHA 2\n");
    printf("[3] - REMOVER NA PILHA 1\n");
    printf("[4] - REMOVER NA PILHA 2\n");
    printf("[5] - LISTAGEM PILHA 1\n");
    printf("[6] - LISTAGEM PILHA 2\n");
    printf("[7] - VER MAIOR ELEMENTO DA PILHA 1\n");
    printf("[8] - VER MAIOR ELEMENTO DA PILHA 2\n");
    printf("[9] - VER MENOR ELEMENTO DA PILHA 1\n");
    printf("[10] - VER MENOR ELEMENTO DA PILHA 2\n");
    printf("[11] - VER MEDIA DOS ELEMENTOS DA PILHA 1\n");
    printf("[12] - VER MEDIA DOS ELEMENTOS DA PILHA 1\n");
    printf("[13] - VER QUANTIDADE DE PARES\n");
    printf("[14] - SAIR\n\n");

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

    case 2:
        printf("Digite o elemento que deseja inserir: ");
        scanf("%d", &elemento2);
        inserir2(elemento2);
        break;

    //REMOVER ELEMENTO
    case 3:
        if(ver_vazia()==1){
            printf("\nA pilha 1 esta vazia, nao e possivel remover.\n");

        }else{
            remover();
        }
        break;

    case 4:
        if(ver_vazia2()==1){
            printf("\nA pilha 2 esta vazia, nao e possivel remover.\n");

        }else{
            remover2();
        }
        break;

    //LISTAR OS ELEMENTOS DA PILHA
    case 5:
        if(ver_vazia()==1){
            printf("\nA pilha esta vazia, nao e possivel listar os elementos da pilha 1.\n");
        }else{
            listagem();
        }
        break;

    case 6:
        if(ver_vazia2()==1){
            printf("\nA pilha esta vazia, nao e possivel listar os elementos da pilha 2.\n");
        }else{
            listagem2();
        }
        break;

    case 7:
        if(ver_vazia()==1){
            printf("\nA pilha esta vazia, nao e possivel ver o maior elemento da pilha 1.\n");
        }else{
            ver_maior();
        }
        break;

    case 8:
        if(ver_vazia2()==1){
            printf("\nA pilha esta vazia, nao e possivel ver o maior elemento da pilha 2.\n");
        }else{
            ver_maior2();
        }
        break;

    case 9:
        if(ver_vazia()==1){
            printf("\nA pilha esta vazia, nao e possivel ver o menor elemento da pilha 1.\n");
        }else{
            ver_menor();
        }
        break;

    case 10:
        if(ver_vazia2()==1){
            printf("\nA pilha esta vazia, nao e possivel ver o menor elemento da pilha 2.\n");
        }else{
            ver_menor2();
        }
        break;

    case 11:
        if(ver_vazia()==1){
            printf("\nA pilha esta vazia, nao e possivel ver a media dos elementos da pilha 1.\n");
        }else{
            ver_media();
        }
        break;        

    case 12:
        if(ver_vazia2()==1){
            printf("\nA pilha esta vazia, nao e possivel ver a media dos elementos da pilha 2.\n");
        }else{
            ver_media2();
        }
        break;

    case 13:
        if(ver_vazia()==1 && ver_vazia2()==1){
            printf("\nAs pilhas estao vazias, nao e possivel ver a media dos elementos das pilhas.\n");
        }else{
            qtd_par();
        }
        break;

    case 14:
        printf("\nSaindo!\n");
        break;
    
    default:
        printf("\nOpcao invalida!\n");
        break;
    }
}

void inserir(int elemento){
    struct Node *novoNo = (struct Node*)malloc(sizeof(struct Node));
    if(!novoNo){
        printf("\nErro ao alocar memoria\n");
        return;
    };
    
    novoNo->dado = elemento;
    novoNo->prox = topo;
    topo = novoNo;
    printf("\nElemento %d adicionado na pilha.\n", elemento);
}

void inserir2(int elemento2){
    struct Node2 *novoNo2 = (struct Node2*)malloc(sizeof(struct Node2));
    if(!novoNo2){
        printf("\nErro ao alocar memoria\n");
        return;
    };
    
    novoNo2->dado2 = elemento2;
    novoNo2->prox2 = topo2;
    topo2 = novoNo2;
    printf("\nElemento %d adicionado na pilha.\n", elemento2);
}

void remover(){
    struct Node *temp = topo;
    topo = topo->prox;
    printf("\nElemento removido da pilha: %d.\n", temp->dado);
    free(temp);
}

void remover2(){
    struct Node2 *temp2 = topo2;
    topo2 = topo2->prox2;
    printf("\nElemento removido da pilha: %d.\n", temp2->dado2);
    free(temp2);
}

void listagem(){
    struct Node *temp = topo;
    printf("\nElementos da pilha:\n");
    while(temp != NULL){
        printf("%d\n", temp->dado);
        temp = temp->prox;
    }
}

void listagem2(){
    struct Node2 *temp2 = topo2;
    printf("\nElementos da pilha:\n");
    while(temp2 != NULL){
        printf("%d\n", temp2->dado2);
        temp2 = temp2->prox2;
    }
}

int ver_vazia(){
    return(topo==NULL);
}

int ver_vazia2(){
    return(topo2==NULL);
}

void ver_maior(){
    int maior=-1000;
    struct Node *temp = topo;

    while(temp != NULL){
        if(temp->dado > maior){
            maior = temp->dado;
        }
        temp = temp->prox;
    }

    printf("\nO maior valor da pilha 1: %d\n", maior);
}

void ver_maior2(){
    int maior2=-1000;
    struct Node2 *temp2 = topo2;

    while(temp2 != NULL){
        if(temp2->dado2 > maior2){
            maior2 = temp2->dado2;
        }
        temp2 = temp2->prox2;
    }

    printf("\nO maior valor da pilha 2: %d\n", maior2);
}

void ver_menor(){
    int menor = 1000000;
    struct Node *temp = topo;

    while(temp != NULL){
        if(temp->dado < menor){
            menor = temp->dado;
        }
        temp = temp -> prox;
    }

    printf("\nO menor valor da pilha 1: %d\n", menor);
}

void ver_menor2(){
    int menor2 = 1000000;
    struct Node2 *temp2 = topo2;

    while(temp2 != NULL){
        if(temp2->dado2 < menor2){
            menor2 = temp2->dado2;
        }
        temp2 = temp2 -> prox2;
    }

    printf("\nO menor valor da pilha 2: %d\n", menor2);
}

void ver_media(){
    int soma_dados=0, contador=0, resultado;
    struct Node *temp = topo;

    while(temp != NULL){
        soma_dados += temp->dado;
        contador++;
        temp = temp->prox;
    }
    
    resultado = soma_dados / contador;
    printf("\nA media dos elementos da pilha 1: %d", resultado);
}

void ver_media2(){
    int soma_dados2=0, contador2=0, resultado2;
    struct Node2 *temp2 = topo2;

    while(temp2 != NULL){
        soma_dados2 += temp2->dado2;
        contador2++;
        temp2 = temp2->prox2;
    }
    
    resultado2 = soma_dados2 / contador2;
    printf("\nA media dos elementos da pilha 2: %d", resultado2);
}

void qtd_par(){
    int opcao, qtd_par=0, qtd_par2=0;
    struct Node *temp = topo;
    struct Node2 *temp2 = topo2;
    
    printf("\nSelecione a pilha que deseja:\n[1]Pilha 1 [2]Pilha 2\n");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
        while(temp != NULL){
            if(temp->dado%2==0){
                qtd_par +=1;
            }
            temp = temp->prox;
        }
        printf("\nA pilha 1 possui %d elementos pares.\n", qtd_par);
        break;

        case 2:
            while(temp2 != NULL){
                if(temp2->dado2%2==0){
                    qtd_par2+=1;
                }
                temp2 = temp2->prox2;
            }
            printf("\nA pilha 2 possui %d elementos pares.\n", qtd_par2);
            break;

        default:
            printf("opcao invalida\n");
            break;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 5

int inicio, fim, contador;

void menu();
int ver_cheia();
int ver_vazia();
void inserir();
void realizar_tarefa();
void remover ();
void ver_inicio();
void ver_fim();
void listagem();
void inicializar();

struct molde_tarefa{
    char tarefa[50];
    char data_execucao[10];
}fila_circular[max];

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

    printf("[1] - Inserir nova tarefa\n");
    printf("[2] - Remover uma tarefa\n");
    printf("[3] - Listar as tarefas\n");
    printf("[4] - Realizar tarefa\n");
    printf("[5] - Verificar se esta cheia\n");
    printf("[6] - Verificar se esta vazia\n");
    printf("[7] - Ver a proxima pesquisa\n");
    printf("[8] - Sair\n");

    printf("\nDigite o numero da funcao que deseja: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        if(ver_cheia()==1){
            printf("\nA fila circular ja esta cheia, nao e possivel inserir.\n");
        }else{
            inserir();
        }
        break;

    case 2:
        if(ver_vazia()==1){
            printf("\nA fila circular esta vazia, nao e possivel remover algum elemento.\n");
        }else{
            remover();
        }
        break;

    case 3:
        listagem();
        break;

    case 4:
        realizar_tarefa();
        break;

    case 5:
        if(ver_cheia()==1){
            printf("\nA fila circular esta cheia.\n");
        }else{
            printf("\nA fila circular nao esta cheia.\n");
        }
        break;

    case 6:
        if(ver_vazia()==1){
            printf("\nA fila circular esta vazia.\n");
        }else{
            printf("\nA fila circular nao esta vazia.\n");
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
        printf("\nOpcao invalida.\n");
        break;
    }

}

int ver_cheia(){
    if(contador == max){
        return 1;
    }else{
        return 0;
    }
}

int ver_vazia(){
    if(contador == 0){
        return 1;
    }else{
        return 0;
    }
}

void inserir(){
    char tarefa_cad[50], data[10];
    if(contador < max && fim == max){
        fim = 0;
        getchar();
        printf("\nDigite a tarefa que deseja cadastrar: ");
        gets(tarefa_cad);

        printf("\nDigite a data de entrega: ");
        gets(data);

        strcpy(fila_circular[fim].tarefa, tarefa_cad);
        contador++;
        fim++;
    }else{
        getchar();
        printf("\nDigite a tarefa que deseja cadastrar: ");
        gets(tarefa_cad);

        printf("\nDigite a data de entrega: ");
        gets(data);

        strcpy(fila_circular[fim].tarefa, tarefa_cad);
        contador++;
        fim++;
    }
    
}

void remover(){
    if(ver_vazia()==1){
        printf("\nA fila circular esta vazia, nao e possivel remover algum elemento.\n");
    }else{
        printf("\nO valor removido foi %d.", fila_circular[inicio]);
        inicio++;
    }
}


void ver_inicio(){
    if(ver_vazia()==1){
        printf("\nA fila_circular esta vazia, nao e possivel ver o inicio.\n");
    }else{
        printf("\nO valor do inicio e: %d.\n", fila_circular[inicio]);
    }
}

void ver_fim(){
    if(ver_vazia()==1){
        printf("\nA fila esta vazia, nao e possivel ver o final.\n");
    }else{
        printf("\nO valor do final e: %d.\n", fila_circular[fim-1]);
    }
}

void listagem(){
    int i;
    if(ver_vazia()==1){
        printf("A fila_circular esta vazia, nao e possivel listar.\n");
    }else{
        for(i=inicio; i<fim; i++){
            printf("%d\n", fila_circular[i]);
        }
    }

}

void inicializar(){
    inicio =0;
    fim = 0;
    contador = 0;
}

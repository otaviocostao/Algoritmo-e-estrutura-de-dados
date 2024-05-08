#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 3

int fila[max];
int inicio, fim, contador;

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
    printf("[5] - Verificar se esta cheia\n");
    printf("[6] - Verificar se esta vazia\n");
    printf("[7] - Ver o inicio\n");
    printf("[8] - Ver o final\n");
    printf("[9] - Sair\n");

    printf("\nDigite o numero da funcao que deseja: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        if(ver_cheia()==1){
            printf("\nA fila ja esta cheia, nao e possivel inserir.\n");
        }else{
            inserir();
        }
        break;
    
    case 2:
        if(ver_vazia()==1){
            printf("\nA fila esta vazia, nao e possivel remover algum elemento.\n");
        }else{
            remover();
        }
        break;
    
    case 3:

        if(ver_vazia()==1){
            printf("A fila esta vazia, nao e possivel listar.\n");
        }else{
            listagem();
        }
        
        break;
    
    case 4:
        if(ver_vazia()==1){
            printf("\nA fila esta vazia, nao e possivel buscar.\n");
        }else{
            buscar();
        }
        break;
    
    case 5:
        if(ver_cheia()==1){
            printf("\nA fila esta cheia.\n");
        }else{
            printf("\nA fila nao esta cheia.\n");
        }
        break;
    
    case 6:
        if(ver_vazia()==1){
            printf("\nA fila esta vazia.\n");
        }else{
            printf("\nA fila nao esta vazia.\n");
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
    int elemento;

    if(contador < max && fim == max){
        fim=0;
        printf("\nDigite o elemento que deseja inserir: ");
        scanf("%d", &elemento);
        fila[fim]=elemento;
        contador++;
        fim++;
    }else{
        printf("\nDigite o elemento que deseja inserir: ");
        scanf("%d", &elemento);
        fila[fim]=elemento;
        contador++;
        fim++;
    }
};

void remover(){
    if(fim<inicio && contador>0){
        inicio =0;
        printf("\nO valor retirado e: %d\n", fila[inicio]);
        inicio++;
        contador--;
    }else{
        printf("\nO valor retirado e: %d\n", fila[inicio]);
        inicio++;
        contador--;
    }
}

void ver_inicio(){
    if(ver_vazia()==1){
        printf("\nA fila esta vazia, nao e possivel ver o inicio.\n");
    }else{
        printf("\nO valor do inicio e: %d.\n", fila[inicio]);
    }
}

void ver_fim(){
    if(ver_vazia()==1){
        printf("\nA fila esta vazia, nao e possivel ver o final.\n");
    }else{
        printf("\nO valor do final e: %d.\n", fila[fim-1]);
    }
}

void listagem(){
    int i;
    printf("\n");
    if(inicio < fim){
        for(i=inicio; i<fim; i++){
            printf("%d\n", fila[i]);
        }
    }else{
        for(i=inicio; i<max; i++){
            printf("%d\n", fila[i]);
        }
        for(i=0; i<=fim; i++){
            printf("%d\n", fila[i]);
        }
    }
}

void buscar(){
    int i, achei=0, elemento;

    printf("\nDigite o elemento que deseja buscar: ");
    scanf("%d", &elemento);

    if(inicio<fim){
        for(i=inicio; i<fim; i++){
            if(fila[i]==elemento){
                printf("\nO elemento %d foi encontrado na posicao %d", elemento, i);
                achei=1;
            }
        }
    }else{
        for(i=inicio; i<max; i++){
            if(fila[i]==elemento){
                printf("\nO elemento %d foi encontrado na posicao %d", elemento, i);
                achei=1;
            }
        }
        for(i=0; i<fim; i++){
            if(fila[i]==elemento){
                printf("\nO elemento %d foi encontrado na posicao %d", elemento, i);
                achei=1;
            }
        }
    }

    if(!achei){
        printf("\nO elemento %d n?o foi encontrado na fila.\n", elemento);
    }
}

void inicializar(){
    inicio =0;
    fim = 0;
    contador= 0;
}

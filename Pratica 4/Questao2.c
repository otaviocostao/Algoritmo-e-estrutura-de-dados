//Ler numeros
//inserir na fila_imp e fila_par
//remover numeros das filas
//

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 5

//DECLARAÇÕES DA FILA
int fila_imp[max], fila_par[max];
int inicio_imp, fim_imp, inicio_par, fim_par;

//DECLARAÇÕES DA PILHA
int pilha[max*2], topo;

//MODULOS DO EXERCICIO
void entrada1();
int check_par(int);
int ver_pos_neg();

//MODULOS DA FILA
void ins_filaimp(int);
void ins_filapar(int);
void rem_filaimp();
void rem_filapar();
void listar_filas();
void inicializar_filaimp();
void incializar_filapar();


//MODULOS DA PILHA
void inicializar_pilha();
void ins_pilha(int);
void rem_pilha();
void list_pilha();
int pilha_vazia();

int main(){
    incializar_filapar();
    inicializar_filaimp();
    inicializar_pilha();

    system("cls");
    printf("\n--- Inicio ---\n\n");
    entrada1();
    listar_filas();

    system("pause");

    ver_pos_neg();
    printf("\n");
    list_pilha();

    system("pause");
    return 0;
}

void entrada1(){
    int i, temp;

    printf("Digite 10 valores inteiros, caso desejar sair digite 0.\n");

    for(i=0;i<max*2; i++){
        scanf("%d", &temp);
        if(temp == 0){
            printf("\nSaindo...\n");
            break;
        }
        if(check_par(temp)==1){
            ins_filapar(temp);
        }else{
            ins_filaimp(temp);
        }

        
    }
}

void ins_filaimp(int elemento){
    fila_imp[fim_imp] = elemento;
    fim_imp++;
}

void ins_filapar(int elemento){
    fila_par[fim_par] = elemento;
    fim_par++;
}

void listar_filas(){
    int i;

    printf("\nFila impar:\n\n");

    for(i=inicio_imp; i<fim_imp; i++){
        printf("%d, ", fila_imp[i]);
    }

    printf("\nFila par:\n\n");

    for(i=inicio_par; i<fim_par; i++){
        printf("%d, ", fila_par[i]);
    }
    printf("\n");
}

void rem_filaimp(){
    inicio_imp++;
}

void rem_filapar(){
    inicio_par++;
}


void inicializar_filaimp(){
    inicio_imp = 0;
    fim_imp = 0;
}

void incializar_filapar(){
    inicio_par = 0;
    fim_par = 0;
}

int check_par(int elemento){
    if(elemento % 2 == 0){
        return 1;
    }else{
        return 0;
    }
}

int ver_pos_neg(){

    while(inicio_imp < fim_par){

        if(fila_imp[inicio_imp] < 0){
            rem_pilha();
        }else{
            ins_pilha(fila_imp[inicio_imp]);
        }
        rem_filaimp();

        if(fila_par[inicio_par] < 0){
            rem_pilha();
        }else{
            ins_pilha(fila_par[inicio_par]);
        }
        rem_filapar();
    }

}

//MODULOS DA PILHA

void inicializar_pilha(){
    topo = -1;
}

void ins_pilha(int elemento){
    topo++;
    pilha[topo] = elemento;
}

void rem_pilha(){
    if(pilha_vazia()==1){
        printf("\nA pilha já está vazia, não é possivel remover um elemento.\n");
    }else{
        topo--;
    }
}

void list_pilha(){
    int i;
    printf("\nElementos da pilha:\n\n");
    for(i=topo; i>=0; i--){
        printf("%d, ", pilha[i]);
    }
    printf("\n");
}

int pilha_vazia(){
    if(topo==-1){
        return 1;
    }else{
        return 0;
    }
}
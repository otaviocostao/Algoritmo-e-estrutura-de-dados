#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct No 
{
    int matricula;
    float media;
    struct No* prox;
};
struct fila 
{
    struct No* ini;
    struct No* fim;
};

struct fila f;


void menu();
int ver_vazia(struct fila *f);
void inserir(struct fila *f, int, float);
void remover (struct fila *f);
void ver_inicio(struct fila *f);
void ver_fim(struct fila *f);
void listagem(struct fila *f);
void buscar(struct fila *f, int);
void inicializar(struct fila *f);
void maior_media(struct fila *f);

int main(){
    inicializar(&f);
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
    int opcao, matricula, busca_matricula;
    float media;
    system("cls");

    printf("[1] - Cadastrar aluno\n");
    printf("[2] - Remover aluno\n");
    printf("[3] - Listar a alunos\n");
    printf("[4] - Buscar aluno\n");
    printf("[5] - Verificar se esta vazia\n");
    printf("[6] - Ver o inicio\n");
    printf("[7] - Ver o final\n");
    printf("[8] - Ver maior media\n");
    printf("[9] - Sair\n");

    printf("\nDigite o numero da funcao que deseja: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("\nDigite a matricula que deseja inserir: ");
        scanf("%d", &matricula);

        printf("\nDigite a media do aluno: ");
        scanf("%f", &media);
        inserir(&f, matricula, media);
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
            printf("\nDigite a matricula que deseja buscar: ");
            scanf("%d", &busca_matricula);
            buscar(&f, busca_matricula);
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
            printf("\nA fila esta vazia, nao e possivel ver maior media.\n");
        }else{
            maior_media(&f);
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

void inserir(struct fila *f, int matricula, float media){
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));

    if(novoNo==NULL){
        printf("\nMemoria insuficiente\n");
        return;
    }
    novoNo->matricula = matricula;
    novoNo->media = media;
    novoNo->prox = NULL;

    if(f->fim == NULL){
        f->ini = novoNo;
        f->fim = novoNo;
    }else{
        f->ini->prox = novoNo;
        f->fim = novoNo;
    }
    printf("\nFoi inserido a matricula: %d e a media %.2f\n", f->fim->matricula, f->fim->media);
};

void remover(struct fila *f){
    struct No* temp = f->ini;
    int matricula = temp->matricula;
    f->ini = f->ini->prox;
    if (f->ini == NULL) {
        f->fim = NULL;
    }
    free(temp);
    printf("O aluno removido e de matricula: %d\n", matricula);
}


void ver_inicio(struct fila *f){
    printf("\nA matricula do inicio e %d.\n", f->ini->matricula);
}

void ver_fim(struct fila *f){
    printf("\nA matricula do fim e %d.\n", f->fim->matricula);
}

void listagem(struct fila *f){
    struct No* temp = f->ini;
    printf("Elementos na fila:\n");
    while (temp != NULL) {
        printf("Matricula: %d ", temp->matricula);
        printf("\nMedia: %.2f ", temp->media);
        printf("\n");
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
        if (temp->matricula == x) {
            printf("O aluno de matricula %d foi encontrado na fila na posicao %d e tem media: %.2f \n", temp->matricula, posicao, temp->media);
            achei = 1;
        }
        temp = temp->prox;
    }
    if (!achei) {
        printf("O aluno buscado não foi encontrado \n");
    }
}

void maior_media(struct fila *f){
    struct No* temp = f->ini;
    float maior_media=-10;
    while (temp != NULL) {
        if (temp->media > maior_media) {
            maior_media = temp->media;
        }
        temp = temp->prox;
    }
    
    printf("\nA maior media e: %.2f", maior_media);
}

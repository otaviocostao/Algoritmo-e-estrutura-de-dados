#include <stdio.h>
#include <stdlib.h>
#define TAM 6

void menu();
void inserir_bilhete();
void inserir_num_loteria();
void verificar_numeros();

int *num_loteria;
int *num_bilhete;

int main(){
    int resp=1;

    system("cls");
    while(resp==1){
        menu();
        printf("\nDeseja continuar no menu?\n[1]Sim [2]Nao\n");
        scanf("%d", &resp);
    }
}

void menu(){
    int opcao;
    printf("=== MENU ===\n\n");
    printf("[1] - Inserir numeros gerados pela loteria\n");
    printf("[2] - Inserir os numeros do seu bilhete\n");
    printf("[3] - Verificar acertos do bilhete\n");
    printf("[4] - Sair\n\n");
    printf("Selecione uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        inserir_num_loteria(&num_loteria);
        break;
    case 2:
        inserir_bilhete(&num_bilhete);
        break;
    case 3:
        verificar_numeros();
        break;
    
    case 4:
        printf("\nSaindo\n");
        break;
    
    default:
        break;
    }
}

void inserir_num_loteria(){
    int i;
    num_loteria = (int*) malloc(TAM*sizeof(int));

    printf("\nDigite os numeros gerados pela loteria:\n");
    for(i=0; i<TAM; i++){
        printf("\nDigite o %dº numero: ", i+1);
        scanf("%d", &num_loteria[i]);
    }

    for(i=0; i<TAM; i++){
        printf("%d, ", num_loteria[i]);
    }
}

void inserir_bilhete(){
    int i;
    num_bilhete = (int*) malloc(TAM*sizeof(int));

    printf("\nDigite os numeros do seu bilhete:\n");
    for(i=0; i<TAM; i++){
        printf("\nDigite o %dº numero: ", i+1);
        scanf("%d", &num_bilhete[i]);
    }

    for(i=0; i<TAM; i++){
        printf("%d, ", num_bilhete[i]);
    }
}

void verificar_numeros(){
    int *acertos;
	acertos = (int *)malloc(TAM * sizeof(int));
	int i, j, k = 0;
	for(i = 0; i< TAM; i++){
		for(j = 0; j < TAM; j++){
			if(num_loteria[i] == num_bilhete[j]){
				acertos[k] = num_bilhete[j];
				k++;
			}
		}
	}
	
	printf("Foram acertados %d números\n", k);
    printf("\nSeu bilhete:\n");
    for(int i = 0; i < k; i++){
		printf("%d ", num_bilhete[i]);
	}

    printf("\nNumeros da loteria:\n");
    for(int i = 0; i < k; i++){
		printf("%d ", num_loteria[i]);
	}

	printf("\nSeus acertos: \n");
	for(int i = 0; i < k; i++){
		printf("%d ", acertos[i]);
	}
}

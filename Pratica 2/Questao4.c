//Escreva um programa que simule contas banc�rias, com as seguintes especifica��es: ? Ao iniciar o programa vamos criar contas banc�rias para tr�s clientes.
//Cada conta ter� o nome e o CPF do cliente associado a ela. O no ato da cria��o da conta o cliente precisar� fazer um dep�sito inicial.

//Ap�s as contas serem criadas, o sistema dever� possibilitar realiza��es de saques ou dep�sitos nas contas. O sempre que uma opera��o de saque ou dep�sito seja realizada, o sistema dever� imprimir o nome do titular e o saldo final da conta.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 1

//Criando a estrutura:
struct conta{
    char nome[100];
    char cpf[12];
    char pin[5];
    float deposito_inicial;
}cliente[TAM];

//Funcao para realizar o deposito:
float deposito(float saldo, float depositado){
    return saldo += depositado;
}

//funcao para realizar o saque:
float saque(float saldo, float sacado){
    return saldo -= sacado;
}

int main(){
    setlocale(LC_ALL, "Portuguese;");

    int i, cpf_true, pin_true, operacao, continuar=1;
    char log_cpf[12], log_pin[5];
    float saldo_final, valor;
    char head_login[100], head_user[100];

    printf("Inicio - Cadastrar clientes:\n\n");

    //Criando a conta dos clientes:
    for(i=0; i<TAM; i++){
        printf("Digite o nome do cliente: ");
        gets(cliente[i].nome);

        printf("\nDigite o CPF do cliente: ");
        gets(cliente[i].cpf);

        do{
            printf("\nDigite um PIN de 4 digitos para o usu�rio: ");
            gets(cliente[i].pin);
        }while(strlen(cliente[i].pin)!=4);

        do{
            printf("\nDigite o valor do deposito inicial:\n");
            scanf("%f", &cliente[i].deposito_inicial);
        }while(cliente[i].deposito_inicial<=0);
        getchar();
    }
    
    //Logar a conta do cliente para realizar a opera��o:

    printf("\n---Login do usu�rio---\n");
    do{
        printf("\nDigite o CPF do cliente: ");
        gets(log_cpf);

        if(strlen(log_cpf)!=11){
            printf("\nO CPF digitado � invalido.\n");
        }
    }while(strlen(log_cpf)!=11);
    
    do{
        printf("\nDigite o PIN do cliente: ");
        gets(log_pin);

        if(strlen(log_pin)!=4){
            printf("\nO PIN digitado � invalido.\n");
        }
    }while(strlen(log_pin)!=4);

    for(i=0; i<TAM; i++){
        //Realizando a valida��o do usuario:
        cpf_true = strcmp(log_cpf, cliente[i].cpf);
        pin_true = strcmp(log_pin, cliente[i].pin);
        
//if((cpf_true==0) && (pin_true == 0))
            
        do{
            if (cpf_true == 0 && pin_true == 0){
            
                strcpy(head_login, "Seja bem-vindo ");
                strcat(head_login, cliente[i].nome);
                puts(head_login);
                printf("Seu saldo atual: %.2f\n\n", cliente[i].deposito_inicial);

                printf("Digite a operacao que deseja:\n[1]Deposito\n[2]Saque\n");
                scanf("%d", &operacao);}else{
                printf("\nUsu�rio n�o encontrado\n");
                break;
            }

            if(operacao == 1){
                printf("\nDigite o valor que deseja depositar: ");
                scanf("%f", &valor);

                saldo_final = deposito(cliente[i].deposito_inicial, valor);
                printf("\nDeposito no valor de %.2f realizado com sucesso!\n\n", valor);

                strcpy(head_user, "Titular da conta: ");
                strcat(head_user, cliente[i].nome);
                puts(head_user);

                printf("Saldo atual: %.2f\n\n", saldo_final);
            }

            if(operacao==2){
                printf("\nDigite o valor que deseja sacar: ");
                scanf("%f", &valor);
                
                if(valor<=cliente[i].deposito_inicial){
                    saldo_final = saque(cliente[i].deposito_inicial, valor);
                    printf("\nSaque no valor de %.2f realizado com sucesso!\n", valor);

                    strcpy(head_user, "Titular da conta: ");
                    strcat(head_user, cliente[i].nome);
                    puts(head_user);

                    printf("Saldo atual: %.2f\n\n", saldo_final);

                    }else{
                        printf("Saldo insuficiente para realizar a opera��o!\n");
                    }

            }

            printf("[1]Continuar\n[2]Sair\n");
            scanf("%d", &continuar);
            if(continuar!=1){
                printf("\nSaindo!\n");
            }

        }while(continuar==1);
    }

    system("pause");
    return 0;

}
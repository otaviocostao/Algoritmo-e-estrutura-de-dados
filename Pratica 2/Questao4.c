//Escreva um programa que simule contas bancárias, com as seguintes especificações: • Ao iniciar o programa vamos criar contas bancárias para três clientes.
//Cada conta terá o nome e o CPF do cliente associado a ela. O no ato da criação da conta o cliente precisará fazer um depósito inicial.

//Após as contas serem criadas, o sistema deverá possibilitar realizações de saques ou depósitos nas contas. O sempre que uma operação de saque ou depósito seja realizada, o sistema deverá imprimir o nome do titular e o saldo final da conta.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 1

//Criando a estrutura:
struct conta{
    char nome[100];
    char cpf[12];
    char pin[4];
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

    int i, cpf_true=1, pin_true=1, operacao;
    char log_cpf[11], log_pin[4];
    float saldo_final, valor;
    char head_login;

    printf("Inicio - Cadastrar clientes:\n\n");

    //Criando a conta dos clientes:
    for(i=0; i<TAM; i++){
        printf("Digite o nome do cliente: ");
        gets(cliente[i].nome);

        printf("\nDigite o CPF do cliente: ");
        gets(cliente[i].cpf);

        printf("\nDigite um PIN de 4 digitos para o usuário: ");
        gets(cliente[i].pin);

        printf("\nDigite o valor do deposito inicial:\n");
        scanf("%f", &cliente[i].deposito_inicial);
        getchar();
    }
    
    //Logar a conta do cliente para realizar a operação:

    printf("\nDigite o CPF do cliente: ");
    gets(log_cpf);

    printf("\nDigite o PIN do cliente: ");
    gets(log_pin);

    for(i=0; i<TAM; i++){
        //Realizando a validação do usuario:
        cpf_true = strcmp(log_cpf, cliente[i].cpf);
        pin_true = strcmp(log_pin, cliente[i].pin);

        if((cpf_true==0) && (pin_true == 0)){
            strcpy(head_login, "Seja bem-vindo ");
            strcat(head_login, cliente[i].nome);
            puts(head_login);

            printf("Digite a operacao que deseja:\n[1]Deposito\n[2]Saque");
            scanf("%f", &operacao);



//FALTA FINALIZAR ESSA PARTE!!!!!!!!!!!!!!!!!!!!!!!! e testar as funcoes!!!!



            while(operacao == 1){
                printf("Digite o valor que deseja depositar: ");
                scanf("%f", &valor);


            }
        }
    }

    system("pause");
    return 0;
}
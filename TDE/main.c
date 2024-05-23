#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <locale.h>
#define MAX 4

struct Paciente{
    int codigo_paciente;
    char nome_paciente[50];
    char endereco[30];
    char data_nasc[15];
    int prioridade;
    char cpf[12];
    char rg[14];
    char telefone[15];
    char email[20];
    int status; //1 se marcado, 0 se não marcado
} paciente_clinicoGeral[MAX], paciente_oftalmo[MAX], paciente_dermato[MAX];
    
struct Consulta{
    int codigo_consulta;
    int codigo_paciente;
    char especialidade[20];
    char dia_consulta[15];
    char pagamento[15];
    char nome_medico[50];
}consulta_clinicoGeral[MAX], consulta_oftalmo[MAX], consulta_dermato[MAX];

struct Especialidade{
    int codigo_especialidade;
    char nome_especialidade[20];
    int qtd_consultas;
}especialidade[3];

int vagas_segunda_cg = MAX;
int contador_consulta = 0;
int contador_paciente= 0;

void marcar_consulta();
int busca(char[]);
void mostrar_consulta(struct Paciente, struct Consulta);
void cadastro_paciente(int, char[]);
void menu();
void listar_consultas();

int main()
{
    setlocale(LC_ALL, "portuguese");
    int escolha=1;

    while (escolha==1)
    {
        menu();
        fflush(stdin);
        printf("\nDeseja continuar?\n[1]-Sim [2]-Não\nDigite a opção: ");
        scanf("%d", &escolha);
    }
    
}

void menu(){
    int opcao;
    system("cls");
    printf("==========================");
    printf("\nGERENCIADOR DE CONSULTAS");
    printf("\n==========================\n");
    printf("\n[1] - Marcar consulta");
    printf("\n[2] - Desmarcar consulta");
    printf("\n[3] - Listar consultas");
    printf("\n[4] - Listar fila de espera");
    printf("\n[5] - Buscar paciente");
    printf("\n[6] - Sair");
    printf("\nSelecione uma opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        marcar_consulta();
        break;
    
    case 2:

        break;

    case 3:

        break;

    case 4:

        break;

    case 5:

        break;

    case 6:
        printf("\nSaindo do sistema.\n");
        break;

    default:
        printf("\nVocê digitou uma opção invalida!\n");
        break;
    }
}

void marcar_consulta(){
    char cpf_temp[12];
    int escolha_temp;
    int dia_temp;
    
    printf("ESPECIALIDADES:\n");
    printf("1 - Clinico Geral\n");
    printf("2 - Oftalmologista\n");
    printf("3 - Dermatologista\n");
    printf("Escolha a especialidade que deseja marcar\n");
    scanf("%d", &escolha_temp);
    getchar();
    
    switch(escolha_temp){
        case 1: 
        	int pag_temp;
            system("pause");
            system("cls");
            printf("DIAS DE CONSULTA CLINICO GERAL:\n");
            printf("1 - SEGUNDA-FEIRA\n");
            printf("2 - TERÇA-FEIRA\n");
            scanf("%d", &dia_temp);
            getchar();
            
            if(dia_temp == 1 && vagas_segunda_cg > 0){
                printf("Temos %d vagas disponíveis para clinico geral na segunda-feira\n", vagas_segunda_cg);
                do{
                	printf("Qual será a forma de pagamento:\n");
	                printf("1 - Convênio\n");
	                printf("2 - Cartão\n");
	                printf("3 - Dinheiro\n");
	                scanf("%d", &pag_temp);
	                getchar();
				}while(pag_temp < 1 && pag_temp > 3);
				
                printf("Informe seu CPF: \n");
                fgets(cpf_temp, sizeof(cpf_temp), stdin);
              
                int index_paciente = busca(cpf_temp);
                if(index_paciente != 0){
                    vagas_segunda_cg--; 
                    contador_consulta++;
                    paciente_clinicoGeral[index_paciente].status = 1;
                    consulta_clinicoGeral[contador_consulta].codigo_consulta = contador_consulta; 
                    consulta_clinicoGeral[contador_consulta].codigo_paciente = paciente_clinicoGeral[busca(cpf_temp)].codigo_paciente;
                    strcpy(consulta_clinicoGeral[contador_consulta].especialidade, "Clinico Geral");
                    strcpy(consulta_clinicoGeral[contador_consulta].nome_medico, "Dr. Marcelo Novais");
                    strcpy(consulta_clinicoGeral[contador_consulta].dia_consulta, "Segunda-feira");
                    if(pag_temp == 1){
                    	strcpy(consulta_clinicoGeral[contador_consulta].pagamento, "Convênio");
					}
					else if(pag_temp == 2){
						strcpy(consulta_clinicoGeral[contador_consulta].pagamento, "Cartão");
					}
					else{
						strcpy(consulta_clinicoGeral[contador_consulta].pagamento, "Dinheiro");
					}
                    system("cls");
                    mostrar_consulta(paciente_clinicoGeral[index_paciente], consulta_clinicoGeral[contador_consulta]);
                }
                else{
                    printf("Você não tem cadastro\n");
                    cadastro_paciente(escolha_temp, cpf_temp);
                    vagas_segunda_cg--; 
                    contador_consulta++;
                    paciente_clinicoGeral[contador_paciente].status = 1;
                    consulta_clinicoGeral[contador_consulta].codigo_consulta = contador_consulta; 
                    consulta_clinicoGeral[contador_consulta].codigo_paciente = paciente_clinicoGeral[contador_paciente].codigo_paciente;
                    strcpy(consulta_clinicoGeral[contador_consulta].especialidade, "Clinico Geral");
                    strcpy(consulta_clinicoGeral[contador_consulta].nome_medico, "Dr. Marcelo Novais");
                    strcpy(consulta_clinicoGeral[contador_consulta].dia_consulta, "Segunda-feira");
                    if(pag_temp == 1){
                    	strcpy(consulta_clinicoGeral[contador_consulta].pagamento, "Convênio");
					}
					else if(pag_temp == 2){
						strcpy(consulta_clinicoGeral[contador_consulta].pagamento, "Cartão");
					}
					else{
						strcpy(consulta_clinicoGeral[contador_consulta].pagamento, "Dinheiro");
					}
                    system("cls");
                    mostrar_consulta(paciente_clinicoGeral[contador_paciente], consulta_clinicoGeral[contador_consulta]);
                }
            }
    }
}

int busca(char Cpf[]){
    int achei = 0;
    for(int i = 0; i < MAX; i++){
        if(strcmp(Cpf, paciente_clinicoGeral[i].cpf) == 0){
            achei = i;
            break;
        }
    }
    return achei;
}

void mostrar_consulta(struct Paciente p, struct Consulta c){
    printf("Dados da consulta: \n");
    
    printf("Paciente: %s\n", p.nome_paciente);
    printf("Data de nascimento: %s\n", p.data_nasc);
    if(p.prioridade == 2){
        printf("Prioridade: Não\n");
    }
    else{
        printf("Prioridade: Sim\n");
    }
    printf("Cpf: %s\n", p.cpf);
    printf("Especialidade: %s\n", c.especialidade);
    printf("Médico: %s\n", c.nome_medico);
    printf("\n");
    printf("Dia da consulta: %s\n", c.dia_consulta);
    printf("Pagamento: %s\n", c.pagamento);
}

void cadastro_paciente(int escolha_esp, char cpf_pac[]){
    if(escolha_esp == 1){
        contador_paciente++;
        paciente_clinicoGeral[contador_paciente].codigo_paciente = contador_paciente;
        do{
        	fflush(stdin);
            printf("Informe seu nome:\n");
            fgets(paciente_clinicoGeral[contador_paciente].nome_paciente, sizeof(paciente_clinicoGeral[contador_paciente].nome_paciente), stdin);
        }while(strlen(paciente_clinicoGeral[contador_paciente].nome_paciente) <= 1);
        
        printf("Informe seu endereço: \n");
        fgets(paciente_clinicoGeral[contador_paciente].endereco, sizeof(paciente_clinicoGeral[contador_paciente].endereco), stdin);
        
        do{
        	fflush(stdin);
            printf("Informe sua data de nascimento: \n");
            fgets(paciente_clinicoGeral[contador_paciente].data_nasc, sizeof(paciente_clinicoGeral[contador_paciente].data_nasc), stdin);
        }while(strlen(paciente_clinicoGeral[contador_paciente].data_nasc)< 10);
        
        do{
            printf("Você é prioridade?\n");
            printf("1 - Sim\n");
            printf("2 - Não\n");
            scanf("%d", &paciente_clinicoGeral[contador_paciente].prioridade);
            getchar();
        }while(paciente_clinicoGeral[contador_paciente].prioridade < 1 || paciente_clinicoGeral[contador_paciente].prioridade > 2);
        
        strcpy(paciente_clinicoGeral[contador_paciente].cpf, cpf_pac);
        /*printf("Informe seu cpf:\n");
        printf("Informe apenas numeros\n");
        printf("Se seu cpf começar por 0, digite a partir do segundo número\n");
        scanf("%d", &paciente_clinicoGeral[contador_paciente].cpf);*/
        
        printf("Informe seu rg: \n");
        fgets(paciente_clinicoGeral[contador_paciente].rg, sizeof(paciente_clinicoGeral[contador_paciente].rg), stdin);
        
        printf("Informe seu telefone:\n");
        fgets(paciente_clinicoGeral[contador_paciente].telefone, sizeof(paciente_clinicoGeral[contador_paciente].telefone), stdin);
        
        printf("Informe seu e-mail\n");
        fgets(paciente_clinicoGeral[contador_paciente].email, sizeof(paciente_clinicoGeral[contador_paciente].email), stdin);
    }
}
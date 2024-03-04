//Escrever um programa que cadastre o nome, a matrícula e duas notas de vários alunos. Em seguida imprima a matrícula, o nome e a média de cada um deles.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 3

struct molde{
    char nome[100];
    char matricula[50];
    float av1;
    float av2;
}aluno[TAM];

int main(){
    setlocale(LC_ALL, "Portuguese");

    int i;
    float media;
    char rot_nome[100], rot_matricula[100];

    printf("Sistema de cadastro de alunos:\n\n");

    //Recebendo as informações:

    for(i=0;i<TAM;i++){
        printf("Cadastro do %dº Aluno\n\n", i+1);

        printf("Digite o nome do aluno: ");
        gets(aluno[i].nome);

        printf("\nDigite a matricula do aluno: ");
        gets(aluno[i].matricula);

        printf("\nDigite a nota da primeira avaliação: ");
        scanf("%f", &aluno[i].av1);

        printf("\nDigite a nota da segunda avaliação: ");
        scanf("%f", &aluno[i].av2);
        getchar();
    }

    //Exibindo as informações:

    for(i=0; i<TAM; i++){
        strcpy(rot_nome, "Nome: ");
        strcpy(rot_matricula, "Matricula :");
        printf("Cadastro do aluno: \n\n");

        strcat(rot_nome, aluno[i].nome);
        puts(rot_nome);

        strcat(rot_matricula, aluno[i].matricula);
        puts(rot_matricula);

        media = (aluno[i].av1 + aluno[i].av2)/2;
        printf("Media do aluno: %.2f\n", media);

        system("pause");
    }

    system("pause");
    return 0;
}

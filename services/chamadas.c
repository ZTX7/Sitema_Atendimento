#include "chamadas.h"

void menu(){
    printf("\n\n~~~~~~~~~ MENU ~~~~~~~~~\n\n");
    printf("(1). Cadastrar Paciente.\n");
    printf("(2). Fila de Atendimento.\n");
    printf("(3). Historico de atendimento.\n");
    printf("(4). Sair.\n");
    printf("\nSelecione a opcao para continuar: ");
}

Paciente*cadastrar(Paciente *lista){
    printf("\n\n~~~~~~~~~ CADASTRANDO PACIENTE ~~~~~~~~~\n\n");
    char nome[51];
    int idade;
    char cpf[12];

    printf("Digite o nome: ");
    fgets(nome, 51, stdin);
    nome[strcspn(nome, "\n")] = 0;

    printf("Digite a idade: ");
    scanf("%d", &idade);
    while (getchar() != '\n')
        ;

    printf("Digite o CPF (11 digitos): ");
    fgets(cpf, 12, stdin);
    cpf[strcspn(cpf, "\n")] = 0;
    if (strlen(cpf) != 11){
        printf("\nERRO: O CPF deve ter 11 digitos. Cadastro cancelado.\n");
        return lista;
    }

    lista = inserirElementoComeco(lista, nome, idade, cpf);
    printf("\nPaciente cadastrado com sucesso!\n");
    return lista;
}

void visualizarPacientes(Paciente *inicio){
    if (listaVazia(inicio)){
        printf("\n\n----------------------------");
        printf("\n\nNao ha pacientes cadastrados.\n");
        printf("\n-----------------------------");
        return;
    }
    else{
        printf("\n\n~~~~~~~~~ FILA DE ATENDIMENTO ~~~~~~~~~\n\n");
        Paciente *temp = inicio;
        int i = 1;
        while (temp != NULL){
            printf("\n--- Paciente %d ---\n", i);
            printf("Nome: %s\n", temp->nome);
            printf("Idade: %d\n", temp->idade);
            printf("CPF: %s\n", temp->CPF);
            printf("Prioridade: %s\n", temp->prioridade ? "Sim" : "Nao");
            temp = temp->prox;
            i++;
        }
        printf("\n-----------------------------");
    }
}
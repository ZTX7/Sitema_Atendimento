#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//---------------------------------------------------------------
//                       LISTA ENCADEADA
//---------------------------------------------------------------

typedef struct paciente{
    char nome[51];
    int idade;
    char CPF[12];
    char prioridade[4];

    struct paciente *prox;
} Paciente;

Paciente* criarNo(char nome[], int idade, char cpf[]){
    Paciente* novoNo = (Paciente*)malloc(sizeof(Paciente));

    strcpy(novoNo->nome, nome);
    novoNo->idade = idade;
    strcpy(novoNo->CPF, cpf);
    if (idade >= 50) {
        strcpy(novoNo->prioridade, "Sim");
    } else {
        strcpy(novoNo->prioridade, "Nao");
    }
    
    novoNo->prox = NULL;
    return novoNo;
}

int listaVazia(Paciente *lista) {
    return lista == NULL;
}

Paciente* inserirElementoComeco(Paciente* lista, char nome[], int idade, char cpf[]){
    Paciente* novoNo = criarNo(nome, idade, cpf);
    novoNo->prox = lista;
    return novoNo;
}
//---------------------------------------------------------------
//                           FILA
//---------------------------------------------------------------


typedef struct {
    Paciente *inicio; 
    Paciente *fim;   
    int tamanho;
} Fila;


//---------------------------------------------------------------
//                       PARTE LÓGICA
//---------------------------------------------------------------

void menu(){
    printf("\n\n~~~~~~~~~ MENU ~~~~~~~~~\n\n");
    printf("(1). Cadastrar Paciente.\n");
    printf("(2). Pacientes Cadastrados.\n");
    printf("(3). Buscar por CPF.\n");
    printf("(4). Mostrar fila de atendimento.\n");
    printf("(5). Historico de atendimento.\n");
    printf("(6). Sair.\n");
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
    while (getchar() != '\n');

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

void visualizarPacientes(Paciente *lista){
    if (listaVazia(lista)){
        printf("\n\n----------------------------");
        printf("\n\nNao ha pacientes cadastrados.\n");
        printf("\n-----------------------------");
        return;
    }
    else{
        printf("\n\n~~~~~~~~~ PACIENTES CADASTRADOS ~~~~~~~~~\n\n");
        Paciente *temp = lista;
        int i = 1;
        while (temp != NULL){
            printf("\n--- Paciente %d ---\n", i);
            printf("Nome: %s\n", temp->nome);
            printf("Idade: %d\n", temp->idade);
            printf("CPF: %s\n", temp->CPF);
            printf("Prioridade: %s\n", temp->prioridade);
            temp = temp->prox;
            i++;
        }
        printf("\n-----------------------------");
    }
}

Paciente* buscarCpf(Paciente*lista){
    char buscacpf[12];

    printf("\n\n~~~~~~~~~ BUSCAR POR CPF ~~~~~~~~~\n\n");
    printf("Digite o CPF (11 digitos): ");
    fgets(buscacpf, 12, stdin);
    buscacpf[strcspn(buscacpf, "\n")] = 0;

    if (strlen(buscacpf) != 11){
        printf("\nERRO: O CPF deve ter 11 digitos. Busca cancelada.\n");
    }

    Paciente *temp = lista;
    while (temp != NULL) {
        if (strcmp(temp->CPF, buscacpf) == 0) {
            
            printf("\nPaciente %s:\n", temp->CPF);
            printf("Nome: %s\n", temp->nome);
            printf("Idade: %d\n", temp->idade);
            printf("Prioridade: %s\n", temp->prioridade);
            
            return temp;
        }
        temp = temp->prox;
    }
    
    printf("\nPaciente %s nao encontrado, CPF não existente.\n", buscacpf);
    printf("\n-----------------------------");
    return NULL;
}

//---------------------------------------------------------------
//                        CHAMADAS
//---------------------------------------------------------------

void iniciarSistema(){
    int option;
    Paciente *listaDePacientes = NULL;

    do{
        menu();
        scanf("%d", &option);
        while (getchar() != '\n');

        switch (option){
        case 1:
            listaDePacientes = cadastrar(listaDePacientes);
            // Adicionar o paciente para a fila de atendimento e de acordo com a prioridade
            break;
        case 2:
            visualizarPacientes(listaDePacientes);
            break;
        case 3:
            buscarCpf(listaDePacientes);
            break;
        case 4:
            printf("\n~~~~~~~~~ FILA DE ATENDIMENTO ~~~~~~~~~.\n");
            int yes;
            do{
                printf("\nDeseja chamar proximo atendimento? ");
                printf("\n(1). Sim\n");
                printf("(2). Nao\n");
                printf("\nSelecione a opcao para continuar: ");
                scanf("%d", &yes);
                while (getchar() != '\n');

                switch (yes){
                case 1:
                    printf("\nPaciente chamado\n");
                    break;
                case 2:
                    printf("\nSaindo da fila de atendimento...\n");
                    break;
                default:
                    printf("\nOpcao invalida.\n");
                    break;
                }
            }while(yes!=2);
            
            printf("\n-----------------------------");
            break; 
        case 5:
            printf("\nHistorico de atendimento.\n");
            break;    
        case 6:
            printf("\nSaindo do programa...\n");
            break;
        default:
            printf("\nOpcao invalida. Por favor, selecione uma opcao de 1 a 4.\n");
            break;
        }
    } while (option != 6);
}

int main(){   
    printf("\n\n----- Bem Vindo a SyClin -----");
    iniciarSistema();

    return 0;
}
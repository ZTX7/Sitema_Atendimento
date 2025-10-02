#include "chamadas.h"

void menu(){
    printf("\n\n_________________ MENU _________________\n");
    printf("(1). Cadastrar Paciente.\n");
    printf("(2). Pacientes Cadastrados.\n");
    printf("(3). Buscar por CPF.\n");
    printf("(4). Mostrar fila de atendimento.\n");
    printf("(5). Historico de atendimento.\n");
    printf("(6). Sair.\n");
    printf("\nSelecione a opcao para continuar: ");
}

Paciente*cadastrar(Paciente *lista, FilaDuplaPrioridade** gerenciadorFila){
    printf("\n\n~~~~~~~~~~ CADASTRANDO PACIENTE ~~~~~~~~~~\n\n");
    
    char nome[51];
    int idade;
    char cpf[12];

    if (*gerenciadorFila == NULL) {
        *gerenciadorFila = criarFilaDupla();
    }

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
    EnfileirarDuplo(*gerenciadorFila, nome, idade, cpf); 

    printf("\n> Paciente cadastrado com sucesso!\n");
    return lista;
}

void visualizarPacientes(Paciente *lista){
    printf("\n\n~~~~~~~~~ PACIENTES CADASTRADOS ~~~~~~~~~\n\n");
    if (listaVazia(lista)){
        printf("> Nao ha pacientes cadastrados\n");
        return;
    }
    else{
        Paciente *temp = lista;
        while (temp != NULL){
            printf("\n--- %s ---\n", temp->nome);
            printf("Idade: %d\n", temp->idade);
            printf("CPF: %s\n", temp->CPF);
            printf("Prioridade: %s\n", temp->prioridade);
            temp = temp->prox;
        }
    }
}

Paciente* buscarCpf(Paciente*lista){
    char buscacpf[12];

    printf("\n\n~~~~~~~~~~~~ BUSCAR POR CPF ~~~~~~~~~~~~\n\n");
    printf("Digite o CPF (11 digitos): ");
    fgets(buscacpf, 12, stdin);
    buscacpf[strcspn(buscacpf, "\n")] = 0;

    Paciente *temp = lista;
    while (temp != NULL) {
        if (strcmp(temp->CPF, buscacpf) == 0) {
            
            printf("\n--- Paciente %s:\n", temp->CPF);
            printf("Nome: %s\n", temp->nome);
            printf("Idade: %d\n", temp->idade);
            printf("Prioridade: %s\n", temp->prioridade);
            
            return temp;
        }
        temp = temp->prox;
    }
    printf("\n> CPF nao encontrado ou inexistente\n", buscacpf);
    return NULL;
}

void visualizarFilaSimples(Fila* f, const char* titulo) { 
    printf("\n\n--- %s (Tamanho: %d) ---\n", titulo, f->tamanho);
    
    Paciente *atual = f->inicio;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("[%d] Nome: %s, Idade: %d, CPF: %s\n", 
               posicao++, atual->nome, atual->idade, atual->CPF); 
        atual = atual->prox;
    }
}

void visualizarFilaDupla(FilaDuplaPrioridade* fd) {
    printf("\n~~~~~~~~~~ FILA DE ATENDIMENTO ~~~~~~~~~~\n");
    if (fd == NULL) {
        printf("\n> O sistema de filas nao foi inicializado.\n");
        return;
    }
    
    visualizarFilaSimples(fd->filaPrioridade, "FILA DE PRIORIDADE");
    visualizarFilaSimples(fd->filaNormal, "FILA NORMAL");
}
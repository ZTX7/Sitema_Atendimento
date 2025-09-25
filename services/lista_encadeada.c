#include "../include/lista_encadeada.h"

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

int listaVazia(Paciente *inicio) {
    return inicio == NULL;
}

Paciente* inserirElementoComeco(Paciente* inicio, char nome[], int idade, char cpf[]){
    Paciente* novoNo = criarNo(nome, idade, cpf);
    novoNo->prox = inicio;
    return novoNo;
}
#include "../include/lista_encadeada.h"

int listaVazia(Paciente* inicio){
    return inicio == NULL;
}

Paciente* criarNo(char nome[], int idade, char cpf[]){
    Paciente* novoNo = (Paciente*)malloc(sizeof(Paciente));

    strcpy(novoNo->nome, nome);
    novoNo->idade = idade;
    strcpy(novoNo->CPF, cpf);
    if (idade >= 50) {
        novoNo->prioridade = true;
    } else {
        novoNo->prioridade = false;
    }
    
    novoNo->prox = NULL;
    return novoNo;
}

Paciente* inserirElementoComeco(Paciente* inicio, char nome[], int idade, char cpf[]){
    Paciente* novoNo = criarNo(nome, idade, cpf);
    novoNo->prox = inicio;
    return novoNo;
}
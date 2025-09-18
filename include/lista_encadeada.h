#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct Paciente{
	char nome[50];
	int idade;
	int cpf;
	int prioridade;
    struct Paciente* prox;

}Paciente;

Paciente* CriarPaciente(char* nome, int idade, int cpf, int prioridade);

Paciente* ListaVazia(Paciente* inicio);

 #endif
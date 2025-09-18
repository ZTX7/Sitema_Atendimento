#include <stdio.h>
#include <stdlib.h>

typedef struct Paciente{
	char nome[50];
	int idade;
	int cpf;
	int prioridade;
    struct Paciente* prox;

}Paciente;

/* Usando esse o typedef, estou dando um apelido a estrutura, pois
toda vez que eu chamar o struct, não vou mais declara-lo como um
tipo de variavel sempre que for estruturar um novo conjunto de dados 
(ex: struct Paciente p1;), mas sim (ex: Paciente p1;)*/


Paciente* CriarPaciente(char* nome, int idade, int cpf, int prioridade){
    Paciente* novoPaciente = (Paciente*)malloc(sizeof(Paciente));

    int i = 0;
    while (nome[i] != '\0' && i < 49) {
        novoPaciente->nome[i] = nome[i];
        i++;
    };
     
    novoPaciente->nome[i] = '\0'; // Adiciona o terminador nulo no final

    novoPaciente->idade = idade;
    novoPaciente->cpf = cpf;
    novoPaciente->prioridade = prioridade;
    novoPaciente->prox = NULL;

    return novoPaciente;

}


Paciente* ListaVazia(Paciente* inicio){
    return inicio == NULL;
}


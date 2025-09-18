#include <stdio.h>
#include "../include/lista_encadeada.h"
#include "../include/menu.h"

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrar_pacientes(){
	
	int idade, cpf, prioridade, condition;
	char nome[50];

	printf("\n\n~~~~~~~~ Cadastrar Paciente ~~~~~~~~\n");

	limpar_buffer();
	
	printf("Digite o nome do paciente:\n");
	fgets(nome, sizeof(nome), stdin);	

    int i = 0;
    while (nome[i] != '\n' && nome[i] != '\0' && i < 49) {
        i++;
    }

    if (nome[i] == '\n') {
        nome[i] = '\0';
    }

	printf("Digite a idade do paciente:\n");
	scanf("%d", &idade);	
	printf("Digite o CPF do paciente:\n"); 
	scanf("%i", &cpf);	
	printf("Digite o nível de prioridade: (1. Normal - 2. Urgênte)\n");
	scanf("%d", &prioridade);

	Paciente* CriarPaciente(char* nome, int idade, int cpf, int prioridade);
	
	printf("(1)Cadastrar novo paciente.(2)Voltar ao Menu.\n");
	printf("Selecione a opção para continuar: ");
	scanf("%i", &condition);
	

	if (condition == 1){

	 cadastrar_pacientes();

	}else if(condition == 2){

		menu();

	}else{

		printf("\nTente Novamente, retornando ao Menu. ");
		menu(); /*colocar isso aqui por enquanto*/

	};

}


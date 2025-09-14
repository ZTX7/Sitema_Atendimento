#include <stdio.h>
#include "../include/cadastrar_pacientes.h"
#include "../include/struct.h"
#include "../include/menu.h"



void cadastrar_pacientes(){
	
	struct Paciente p;
	int condition;

	printf("\n\n~~~~~~~~ Cadastrar Paciente ~~~~~~~~\n");
	printf("Digite o nome do paciente:\n");
	scanf("%49s", &p.nome);	
	printf("Digite a idade do paciente:\n");
	scanf("%d", &p.idade);	
	printf("Digite o CPF do paciente:\n"); 
	scanf("%i", &p.cpf);	
	printf("Digite o nível de prioridade: (1. Normal - 2. Urgênte)\n");
	scanf("%d", &p.prioridade);	
	
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
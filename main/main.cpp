#include <stdio.h>


struct Paciente {
	char nome[50];
	int idade;
	int cpf;
	bool prioridade;
};



void cadastrar_pacientes(){
	
	struct Paciente paciente1;
	char condition;
	
	printf("Digite ai negão, o nome do caba:\n");
	scanf("%99s", &paciente1.nome);	
	printf("Digite ai negão, a idade do caba:\n");
	scanf("%d", &paciente1.idade);	
	printf("Digite ai negão, o cpf do caba:\n");
	scanf("%d", &paciente1.cpf);	
	printf("Diga ai negão, ta fudido o caba?:\n");
	scanf("%d", &paciente1.prioridade);	
	
	printf("Digite ai negão, cadastra mais algum nego?: \n1. Sim \n2.Não");
	scanf("%99s", &condition);
}


int main(){
	cadastrar_pacientes();
	return 0;
}
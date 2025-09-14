#include <stdio.h>
#include "../include/menu.h"
#include "../include/cadastrar_pacientes.h"


void menu(){

	int option;

	printf("\n\n~~~~~~~~~ Bem Vindo a SysClin ~~~~~~~~~\n\n");
	printf("1. Pacientes.\n");
	printf("2. Fila de Atendimento.\n");
	printf("3. Histórico de atendimento.\n");
	printf("4. Sair.\n");
	printf("\nSelecione a opção para continuar: ");
	scanf("%d", &option);


	switch (option) {

        case 1:

            printf("\n\n~~~~~~~~~~~~ Pacientes ~~~~~~~~~~~~\n\n");
            printf("1. Cadastrar paciente.\n");
            printf("2. Listar pacientes.\n");
            printf("3. Buscar Paciente.\n");
            printf("(4)-Voltar ao Menu.\n\n");

            printf("Selecione a opção para continuar: ");
            scanf("%i", &option);

            switch (option){
            case 1:

                cadastrar_pacientes();
                break;
            
            case 2:
            case 3:
            case 4:
                menu();
                break;

            default:
                break;
            }
        
        
        case 4:
            break;
            
        default: /* Corrigir o erro de dado, e resetar o menu.*/
            printf("Error: Não foi possível assimilar as opções. Tente Novamente: ");
            break;
        }

}
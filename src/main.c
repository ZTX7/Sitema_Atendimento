#include "../include/chamadas.h"

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
            break;
        case 2:
            visualizarPacientes(listaDePacientes);
            break;
        case 3:
            printf("\n\n~~~~~~~~~ HISTORICO DE ATENDIMENTO ~~~~~~~~~\n\n");
            break;
        case 4:
            printf("\nSaindo do programa...\n");
            break;
        default:
            printf("\nOpcao invalida. Por favor, selecione uma opcao de 1 a 4.\n");
            break;
        }
    } while (option != 4);
}

int main(){   
    printf("\n\n----- Bem Vindo a SyClin -----");
    iniciarSistema();

    return 0;
}
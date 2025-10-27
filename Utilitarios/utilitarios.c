#include <stdio.h>
#include <stdlib.h>
#include "utilitarios.h"

void limparTela(void) {
    // Peguei as ideias com o Gemini 2.5 pro
    #ifdef _WIN32
        // Se o sistema for Windows, executa o comando "cls"
        system("cls");
    #else
        // Para outros sistemas (Linux, macOS), executa o comando "clear"
        system("clear");
    #endif
}

int confirmarExclusao(const char *modulo) {
    char confirma;
    int c;

    while (1) {
        printf("\nDeseja realmente excluir este dado do sistema? (s/n): ");
        scanf(" %c", &confirma);

        while ((c = getchar()) != '\n' && c != EOF);

        if (confirma == 's' || confirma == 'S') {
            printf("\n==============================================================================\n");
            printf("                        %s Excluído com sucesso                      \n", modulo);
            printf("==============================================================================\n");
            return 1;
        } 
        else if (confirma == 'n' || confirma == 'N') {
            printf("\n==============================================================================\n");
            printf("||                            Exclusão cancelada                            ||\n");
            printf("==============================================================================\n");
            return 0;
        } 
        else {
            printf("\nOpção inválida! Digite apenas 's' ou 'n'.\n");
        }
    }
}


int confirmarAlteracao(){

    char confirma;
    int c;

    while(1){
        printf("\nDeseja Realmente alterar esse(s) dado(s)? s - sim ou n - não: ");
        scanf(" %c", &confirma);

        while ((c = getchar()) != '\n' && c != EOF);

        if(confirma == 's' || confirma == 'S'){
            printf("\n==============================================================================\n");
            printf("||                     Dado(s) Atualizado(s) com sucesso                    ||\n");
            printf("==============================================================================\n");
            return 1;
        }else if(confirma == 'n' || confirma == 'N'){
            printf("\n==============================================================================\n");
            printf("||                           Alteracao Cancelado                            ||\n");
            printf("==============================================================================\n");
            return 0;
        }else{
            printf("\nOpção inválida! Tente novamente.\n");
        } 
    }
}
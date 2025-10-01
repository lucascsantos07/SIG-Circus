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

void confirmarExclusao(const char *modulo){

    char confirma;

    printf("\nDeseja Realmente Excluir este dado do Sistema? s - sim ou n - não: ");
    scanf(" %c", &confirma);
    getchar();
    if(confirma == 's'){
        printf("\n==============================================================================\n");
        printf("                        %s Excluido Com Sucesso                      \n", modulo);
        printf("==============================================================================\n");
    }else if(confirma == 'n'){
        printf("\n==============================================================================\n");
        printf("||                            Exclusao Cancelado                            ||\n");
        printf("==============================================================================\n");
    }else{
        printf("\nOpção inválida! Tente novamente.\n");
    }

}

int confirmarAlteracao(){

    char confirma;

    printf("\nDeseja Realmente alterar esse(s) dado(s)? s - sim ou n - não: ");
    scanf(" %c", &confirma);
    getchar();

    if(confirma == 's'){
        printf("\n==============================================================================\n");
        printf("||                     Dado(s) Atualizado(s) com sucesso                    ||\n");
        printf("==============================================================================\n");
        return 1;
    }else if(confirma == 'n'){
        printf("\n==============================================================================\n");
        printf("||                           Alteracao Cancelado                            ||\n");
        printf("==============================================================================\n");
        return 0;
    }else{
        printf("\nOpção inválida! Tente novamente.\n");
    }

}
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

void confirmarAlteracao(){

    char confirma;

    printf("\nDeseja Realmente alterar esse(s) dado(s)? s - sim ou n - não: ");
    scanf(" %c", &confirma);
    getchar();

    if(confirma == 's'){
        printf("\n==============================================================================\n");
        printf("||                     Dado(s) Atualizado(s) com sucesso                    ||\n");
        printf("==============================================================================\n");
    }else if(confirma == 'n'){
        printf("\n==============================================================================\n");
        printf("||                           Alteracao Cancelado                            ||\n");
        printf("==============================================================================\n");
    }else{
        printf("\nOpção inválida! Tente novamente.\n");
    }

}

void telaPrincipal(void) {
    limparTela();
    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||             Universidade Federal do Rio Grande do Norte                  ||\n");
    printf("||                 Centro de Ensino Superior do Seridó                      ||\n");
    printf("||               Departamento de Computação e Tecnologia                    ||\n");
    printf("||                  Disciplina DCT1106 -- Programação                       ||\n");
    printf("||                         Projeto SIG-Circus                               ||\n");
    printf("||             Developed by @ViniciusL07 -- since Aug, 2025                 ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||               ~ ~ ~ Sistema de Gestão Para Um Circo ~ ~ ~                ||\n");
    printf("||                                                                          ||\n");
    printf("||                           -- Menu Principal --                           ||\n");
    printf("||                                                                          ||\n");
    printf("||             1. Clientes                                                  ||\n");
    printf("||             2. Funcionários                                              ||\n");
    printf("||             3. Agendamentos                                              ||\n");
    printf("||             4. Vendas de ingressos                                       ||\n");
    printf("||             5. Relatórios                                                ||\n");
    printf("||             6. Sobre o Projeto                                           ||\n");
    printf("||             7. Equipe de Desenvolvimento                                 ||\n");
    printf("||             0. Sair                                                      ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}

void telaFinalizacao(void) {
    limparTela();
    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||             Universidade Federal do Rio Grande do Norte                  ||\n");
    printf("||                 Centro de Ensino Superior do Seridó                      ||\n");
    printf("||               Departamento de Computação e Tecnologia                    ||\n");
    printf("||                  Disciplina DCT1106 -- Programação                       ||\n");
    printf("||                         Projeto SIG-Circus                               ||\n");
    printf("||             Developed by @ViniciusL07 -- since Aug, 2025                 ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||               ~ ~ ~ Sistema de Gestão Para Um Circo ~ ~ ~                ||\n");
    printf("||                                                                          ||\n");
    printf("||                  Obrigado por utilizar o SIG-Circus!                     ||\n");
    printf("||                                                                          ||\n");
    printf("||                          Até a próxima!                                  ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\n");
}
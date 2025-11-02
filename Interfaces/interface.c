#include <stdio.h>
#include <stdlib.h>
#include "./interface.h"
#include "../Utilitarios/utilitarios.h"

char telaPrincipal(void) {
    char opcao;
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
    printf("||             3. Agendamentos de Espetáculo                                ||\n");
    printf("||             4. Vendas de ingressos                                       ||\n");
    printf("||             5. Relatórios                                                ||\n");
    printf("||             6. Sobre o Projeto                                           ||\n");
    printf("||             7. Equipe de Desenvolvimento                                 ||\n");
    printf("||             0. Sair                                                      ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
    scanf("%c", &opcao);
    limparBuffer();
    return opcao;
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
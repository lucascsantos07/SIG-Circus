#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Agendamentos/agendamentos.h"
#include "../Utilitarios/utilitarios.h"
#include "relatorio.h"

#define True 1
#define False 0

void exibirModuloRelatorios(void){
    char opcaoRelatorio;

    do {
        menuRelatorios();
        scanf(" %c", &opcaoRelatorio);
        getchar();

        switch (opcaoRelatorio){
            case '1':
                relatorioAgendamentos();
                break;
            case '2':
                relatorioAgendamentosAtivos();
                break;
            case '3':
                relatorioAgendamentosInativos();
                break;
            case '0':
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }

        if (opcaoRelatorio != '0') {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }

    } while (opcaoRelatorio != '0');
}

void menuRelatorios(void){
    limparTela();
    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||             Universidade Federal do Rio Grande do Norte                  ||\n");
    printf("||                 Centro de Ensino Superior do Seridó                      ||\n");
    printf("||               Departamento de Computação e Tecnologia                    ||\n");
    printf("||                  Disciplina DCT1106 -- Programação                       ||\n");
    printf("||                         Projeto SIG-Circus                               ||\n");
    printf("||             Developed by @j.samuel007 -- since Nov, 2025                 ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||               ~ ~ ~ Sistema de Gestão Para Um Circo ~ ~ ~                ||\n");
    printf("||                                                                          ||\n");
    printf("||                              -- Relatórios --                            ||\n");
    printf("||                                                                          ||\n");
    printf("||             1. Relatório de Todos os Agendamentos                        ||\n");
    printf("||             2. Relatório de Agendamentos Ativos                          ||\n");
    printf("||             3. Relatório de Agendamentos Inativos                        ||\n");
    printf("||             0. Voltar Menu Principal                                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}

void relatorioAgendamentos(void){
    limparTela();

    FILE *arq;
    Agendamento ag;
    int contador = 0;

    printf("\n==============================================================================\n");
    printf("||                     ~ ~ ~ Relatório de Agendamentos ~ ~ ~                ||\n");
    printf("==============================================================================\n");

    arq = fopen("Agendamentos/agendamento.dat", "rb");
    if (arq == NULL){
        printf("\n  Nenhum agendamento encontrado!\n");
        return;
    }

    printf("\nID  | Data       | Hora  | Cidade               | Capacidade | Preço   | Ingressos Vendidos | CPF Responsável | Status\n");
    printf("---------------------------------------------------------------------------------------------------------------------------\n");

    while(fread(&ag, sizeof(Agendamento), 1, arq) == 1){
        printf("%-3d | %-10s | %-5s | %-20s | %-10d | %-7.2f | %-18d | %-15s | %s\n",
               ag.id, ag.data, ag.horario, ag.cidade,
               ag.capacidade, ag.precoIngresso,
               ag.quantIngressosVend, ag.cpfResponsavel,
               ag.status ? "Ativo" : "Cancelado");
        contador++;
    }

    if (contador == 0){
        printf("\n  Nenhum agendamento cadastrado.\n");
    }

    fclose(arq);
}

void relatorioAgendamentosAtivos(void){
    limparTela();

    FILE *arq;
    Agendamento ag;
    int contador = 0;

    printf("\n==============================================================================\n");
    printf("||                 ~ ~ ~ Relatório de Agendamentos Ativos ~ ~ ~             ||\n");
    printf("==============================================================================\n");

    arq = fopen("Agendamentos/agendamento.dat", "rb");
    if (arq == NULL){
        printf("\n  Nenhum agendamento encontrado!\n");
        return;
    }

    printf("\nID  | Data       | Hora  | Cidade               | Capacidade | Preço   | Ingressos Vendidos | CPF Responsável\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    while(fread(&ag, sizeof(Agendamento), 1, arq) == 1){
        if(ag.status){
            printf("%-3d | %-10s | %-5s | %-20s | %-10d | %-7.2f | %-18d | %-15s\n",
                   ag.id, ag.data, ag.horario, ag.cidade,
                   ag.capacidade, ag.precoIngresso,
                   ag.quantIngressosVend, ag.cpfResponsavel);
            contador++;
        }
    }

    if (contador == 0){
        printf("\n  Nenhum agendamento ativo encontrado.\n");
    }

    fclose(arq);
}

void relatorioAgendamentosInativos(void){
    limparTela();

    FILE *arq;
    Agendamento ag;
    int contador = 0;

    printf("\n==============================================================================\n");
    printf("||                 ~ ~ ~ Relatório de Agendamentos Inativos ~ ~ ~           ||\n");
    printf("==============================================================================\n");

    arq = fopen("Agendamentos/agendamento.dat", "rb");
    if (arq == NULL){
        printf("\n  Nenhum agendamento encontrado!\n");
        return;
    }

    printf("\nID  | Data       | Hora  | Cidade               | Capacidade | Preço   | Ingressos Vendidos | CPF Responsável\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    while(fread(&ag, sizeof(Agendamento), 1, arq) == 1){
        if(ag.status){
            printf("%-3d | %-10s | %-5s | %-20s | %-10d | %-7.2f | %-18d | %-15s\n",
                   ag.id, ag.data, ag.horario, ag.cidade,
                   ag.capacidade, ag.precoIngresso,
                   ag.quantIngressosVend, ag.cpfResponsavel);
            contador++;
        }
    }

    if (contador == 0){
        printf("\n  Nenhum agendamento inativo encontrado.\n");
    }

    fclose(arq);
}
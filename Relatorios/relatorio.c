#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Agendamentos/agendamentos.h"
#include "../Clientes/clientes.h"
#include "../Utilitarios/utilitarios.h"
#include "relatorio.h"
#include "../Funcionarios/funcionarios.h"
#include "../Ingressos/ingressos.h"

#define True 1
#define False 0

void exibirModuloRelatorios(void){
    int opcaoRelatorio;

    do {
        menuRelatorios();
        scanf(" %d", &opcaoRelatorio);
        getchar();

        switch (opcaoRelatorio){
            case 1:
                menuRelatoriosAgendamentos();
                exibirRelatoriosAgendamentos();
                break;
            case 2:
                menuRelatoriosClientes();
                exibirRelatoriosClientes();
                break;
            case 7:
                relatorioFuncionarios(2);
                break;
            case 8:
                relatorioFuncionarios(1);
                break;
            case 9:
                relatorioFuncionarios(0);
                break;
            case 10:
                relatorioIngressos(2);
                break;
            case 11:
                relatorioIngressos(1);
                break;
            case 12:
                relatorioIngressos(0);
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }

        if (opcaoRelatorio != 0) {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }

    } while (opcaoRelatorio != 0);
}

void exibirRelatoriosAgendamentos(void){
    int opcaoRelatorio;

    do {
        menuRelatoriosAgendamentos();
        scanf(" %d", &opcaoRelatorio);
        getchar();

        switch (opcaoRelatorio){
            case 1:
                relatorioAgendamentos(2);
                break;
            case 2:
                relatorioAgendamentos(1);
                break;
            case 3:
                relatorioClientes(0);
                break;
            case 0:
                printf("\nVoltando ao menu de relatórios...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }

        if (opcaoRelatorio != 0) {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }

    } while (opcaoRelatorio != 0);
}

void exibirRelatoriosClientes(void){
    int opcaoRelatorio;

    do {
        menuRelatoriosClientes();
        scanf(" %d", &opcaoRelatorio);
        getchar();

        switch (opcaoRelatorio){
            case 1:
                relatorioClientes(2);
                break;
            case 2:
                relatorioClientes(1);
                break;
            case 3:
                relatorioClientes(0);
                break;
            case 0:
                printf("\nVoltando ao menu de relatórios...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }

        if (opcaoRelatorio != 0) {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }

    } while (opcaoRelatorio != 0);
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
    printf("||             1. Todos os Relatório de Agendamentos                        ||\n");
    printf("||             2. Todos os Relatório de Clientes                            ||\n");
    printf("||             3. Todos os Relatório de Funcionários                        ||\n");
    printf("||             4. Todos os Relatório de Ingressos                           ||\n"); 
    printf("||             0. Voltar Menu Principal                                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}

void menuRelatoriosAgendamentos(void){
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
    printf("||                       -- Relatórios Agendamentos--                       ||\n");
    printf("||                                                                          ||\n");
    printf("||             1. Relatório de Todos os Agendamentos                        ||\n");
    printf("||             2. Relatório dos Agendamentos Ativos                         ||\n");
    printf("||             3. Relatório dos Agendamentos Inativos                       ||\n");
    printf("||             0. Voltar ao menu de Relatórios                              ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}

void menuRelatoriosClientes(void){
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
    printf("||                         -- Relatórios Clientes--                         ||\n");
    printf("||                                                                          ||\n");
    printf("||             1. Relatório de Todos os Clientes                            ||\n");
    printf("||             2. Relatório dos Clientes Ativos                             ||\n");
    printf("||             3. Relatório dos Clientes Inativos                           ||\n");
    printf("||             0. Voltar ao menu de Relatórios                              ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}

void relatorioAgendamentos(int status){
    limparTela();

    FILE *arqAgendamentos;
    Agendamento* ag;
    ag = (Agendamento*)malloc(sizeof(Agendamento));

    arqAgendamentos = fopen("Agendamentos/agendamento.dat", "rb");
    if (arqAgendamentos == NULL){
        printf("\n  Nenhum agendamento encontrado!\n");
        return;
    }

    printf("\n==============================================================================\n");
    printf("||                     ~ ~ ~ Relatório de Agendamentos ~ ~ ~                ||\n");
    printf("==============================================================================\n");

    printf("\nID  | Data       | Hora  | Cidade               | Capacidade | Preço   | Ingressos Vendidos | CPF Responsável | Status\n");
    printf("---------------------------------------------------------------------------------------------------------------------------\n");

    if (status == 2){
        while(fread(ag, sizeof(Agendamento), 1, arqAgendamentos)){
            printf("%-3d | %-10s | %-5s | %-20s | %-10d | %-7.2f | %-18d | %-15s | %s\n",
                ag->id, ag->data, ag->horario, ag->cidade,
                ag->capacidade, ag->precoIngresso,
                ag->quantIngressosVend, ag->cpfResponsavel,
                ag->status ? "Ativo" : "Cancelado");
        }
    }

    else if (status == 0 || status == 1){
        while (fread(ag, sizeof(Agendamento), 1, arqAgendamentos)) {
            if (ag->status == status) {
                printf("%-3d | %-10s | %-5s | %-20s | %-10d | %-7.2f | %-18d | %-15s | %s\n",
                    ag->id, ag->data, ag->horario, ag->cidade,
                    ag->capacidade, ag->precoIngresso,
                    ag->quantIngressosVend, ag->cpfResponsavel,
                    ag->status ? "Ativo" : "Cancelado");
            }
        }
    }
    fclose(arqAgendamentos);
    free(ag);
}

void relatorioClientes(int status){
    limparTela();

    FILE *arqCliente;
    Cliente* cli;
    cli = (Cliente*)malloc(sizeof(Cliente));

    arqCliente = fopen("Clientes/clientes.dat", "rb");
    if (arqCliente == NULL){
        printf("\n  Nenhum cliente encontrado!\n");
        return;
    }

    printf("\n==============================================================================\n");
    printf("||                       ~ ~ ~ Relatório de Clientes ~ ~ ~                  ||\n");
    printf("==============================================================================\n");
    printf("\nCPF           | Nome                           | Data de Nasc.   | Email          | Status\n");
    printf("--------------------------------------------------------------------------------------------\n");

    if (status == 2){
        while (fread(cli, sizeof(Cliente), 1, arqCliente) == 1) {
            printf("%-13s | %-30s | %-11s | %-25s | %s\n",
            cli->cpf, cli->nome, cli->dataNascimento, cli->email,
            cli->status ? "Ativo" : "Inativo");
        }
    }

    else if (status == 0 || status == 1){
        while (fread(cli, sizeof(Cliente), 1, arqCliente)) {
            if (cli->status == status) {
                printf("%-13s | %-30s | %-11s | %-25s | %s\n",
                cli->cpf, cli->nome, cli->dataNascimento, cli->email,
                cli->status ? "Ativo" : "Inativo");
            }
        }
    }
    fclose(arqCliente);
    free(cli);
}

void relatorioClientesAtivos(void){
    limparTela();

    FILE *arq;
    Cliente cli;
    int contador = 0;

    printf("\n==============================================================================\n");
    printf("||                   ~ ~ ~ Relatório de Clientes Ativos ~ ~ ~               ||\n");
    printf("==============================================================================\n");

    arq = fopen("Clientes/clientes.dat", "rb");
    if (arq == NULL){
        printf("\n  Nenhum cliente encontrado!\n");
        return;
    }

    printf("\nCPF           | Nome                           | Data de Nasc.   | Email\n");
    printf("-----------------------------------------------------------------------------\n");

    while(fread(&cli, sizeof(Cliente), 1, arq) == 1){
        if(cli.status){
            printf("%-13s | %-30s | %-11s | %-30s\n",
                cli.cpf, cli.nome, cli.dataNascimento, cli.email);
            contador++;
        }
    }

    if (contador == 0){
        printf("\n  Nenhum cliente ativo encontrado.\n");
    }

    fclose(arq);
}


void relatorioClientesInativos(void){
    limparTela();

    FILE *arq;
    Cliente cli;
    int contador = 0;

    printf("\n==============================================================================\n");
    printf("||                  ~ ~ ~ Relatório de Clientes Inativos ~ ~ ~              ||\n");
    printf("==============================================================================\n");

    arq = fopen("Clientes/clientes.dat", "rb");
    if (arq == NULL){
        printf("\n  Nenhum cliente encontrado!\n");
        return;
    }

    printf("\nCPF           | Nome                           | Data de Nasc.   | Email\n");
    printf("-----------------------------------------------------------------------------\n");

    while(fread(&cli, sizeof(Cliente), 1, arq) == 1){
        if(!cli.status){
            printf("%-13s | %-30s | %-11s | %-30s\n",
                cli.cpf, cli.nome, cli.dataNascimento, cli.email);
            contador++;
        }
    }

    if (contador == 0){
        printf("\n  Nenhum cliente inativo encontrado.\n");
    }

    fclose(arq);
}

void relatorioFuncionarios(int status) {
    Funcionarios* funcionario;
    FILE* arqFuncionarios;

    funcionario = (Funcionarios*)malloc(sizeof(Funcionarios));

    arqFuncionarios = fopen("Funcionarios/funcionarios.dat", "rb");

    printf("CPF | Nome | Email | Data de Nascimento | Sexo | Endereço | Telefone | Salário | Cargo | Status\n");
    printf("-----------------------------------------------------------------------------------------------");

    if (status == 2) {
        while (fread(funcionario, sizeof(Funcionarios), 1, arqFuncionarios)) {
        printf("\n%s | %s | %s | %s | %s | %s | %s | %s | %s | %s", funcionario->cpf, funcionario->nome, funcionario->email, funcionario->dataNascimento,  funcionario->sexo, funcionario->endereco, funcionario->telefone, funcionario->salario, funcionario->cargo, funcionario->status ? "Ativo" : "Inativo");
        }
    } else if (status == 0 || status == 1) {
        while (fread(funcionario, sizeof(Funcionarios), 1, arqFuncionarios)) {
            if (funcionario->status == status) {
            printf("\n%s | %s | %s | %s | %s | %s | %s | %s | %s | %s", funcionario->cpf, funcionario->nome, funcionario->email, funcionario->dataNascimento,  funcionario->sexo, funcionario->endereco, funcionario->telefone, funcionario->salario, funcionario->cargo, funcionario->status ? "Ativo" : "Inativo");
            }
        }
    }


    fclose(arqFuncionarios);
    free(funcionario);
}

relatorioIngressos(int status) {
    Ingressos* ingresso;
    FILE* arqIngresso;

    ingresso = (Ingressos*)malloc(sizeof(Ingressos));

    arqIngresso = fopen("Ingressos/ingressos.dat", "rb");

    printf("ID | CPF do cliente | Quantidade de Ingressos | ID do espetáculo | Status\n");
    printf("-----------------------------------------------------------------------------------------------");

    if (status == 2) {
        while (fread(ingresso, sizeof(Ingressos), 1, arqIngresso)) {
        printf("\n%d | %s | %d | %d | %s ", ingresso->id, ingresso->cpfCliente, ingresso->quantidadeIngressos, ingresso->idEspetaculo, ingresso->status ? "Ativo" : "Inativo");
        }
    } else if (status == 0 || status == 1) {
        while (fread(ingresso, sizeof(Ingressos), 1, arqIngresso)) {
            if (ingresso->status == status) {
                printf("\n%d | %s | %d | %d | %s ", ingresso->id, ingresso->cpfCliente, ingresso->quantidadeIngressos, ingresso->idEspetaculo, ingresso->status ? "Ativo" : "Inativo");            }
        }
    }

    fclose(arqIngresso);
    free(ingresso);
}


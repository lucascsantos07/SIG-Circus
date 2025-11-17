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
            case 3:
                menuRelatoriosFuncionarios();
                exibirRelatoriosFuncionarios();
                break;
            case 4:
                menuRelatoriosIngressos();
                exibirRelatoriosIngressos();
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
                relatorioAgendamentos(0);
                break;
            case 4:
                filtrarAgendamentosPorCidade();
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
            case 4:
                filtrarClientesPorNome();
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

void exibirRelatoriosFuncionarios(void){
    int opcaoRelatorio;

    do {
        menuRelatoriosFuncionarios();
        scanf(" %d", &opcaoRelatorio);
        getchar();

        switch (opcaoRelatorio){
            case 1:
                relatorioFuncionarios(2);
                break;
            case 2:
                relatorioFuncionarios(1);
                break;
            case 3:
                relatorioFuncionarios(0);
                break;
            case 4:
                filtrarFuncionariosPorNome();
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

void exibirRelatoriosIngressos(void){
    int opcaoRelatorio;

    do {
        menuRelatoriosIngressos();
        scanf(" %d", &opcaoRelatorio);
        getchar();

        switch (opcaoRelatorio){
            case 1:
                relatorioIngressos(2);
                break;
            case 2:
                relatorioIngressos(1);
                break;
            case 3:
                relatorioIngressos(0);
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
    printf("||             4. Filtro de Relatório de Agendamentos por Cidades           ||\n");
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
    printf("||             4. Filtro de Relatório dos Clientes Por Nomes                ||\n");
    printf("||             0. Voltar ao menu de Relatórios                              ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}

void menuRelatoriosFuncionarios(void){
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
    printf("||                       -- Relatórios Funcionários--                       ||\n");
    printf("||                                                                          ||\n");
    printf("||             1. Relatório de Todos os Funcionários                        ||\n");
    printf("||             2. Relatório dos Funcionários Ativos                         ||\n");
    printf("||             3. Relatório dos Funcionários Inativos                       ||\n");
    printf("||             0. Voltar ao menu de Relatórios                              ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}

void menuRelatoriosIngressos(void){
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
    printf("||                         -- Relatórios Ingresss--                         ||\n");
    printf("||                                                                          ||\n");
    printf("||             1. Relatório de Todos os Ingressos                           ||\n");
    printf("||             2. Relatório dos Ingresos Ativos                             ||\n");
    printf("||             3. Relatório dos Ingressos Inativos                          ||\n");
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
            printf("%d | %s | %s | %s | %d | %.2f | %d | %s | %s\n",
                ag->id, ag->data, ag->horario, ag->cidade,
                ag->capacidade, ag->precoIngresso,
                ag->quantIngressosVend, ag->cpfResponsavel,
                ag->status ? "Ativo" : "Cancelado");
        }
    }

    else if (status == 0 || status == 1){
        while (fread(ag, sizeof(Agendamento), 1, arqAgendamentos)) {
            if (ag->status == status) {
                printf("%d | %s | %s | %s | %d | %.2f | %d | %s | %s\n",
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
            printf("%s | %s | %s | %s | %s\n",
            cli->cpf, cli->nome, cli->dataNascimento, cli->email,
            cli->status ? "Ativo" : "Inativo");
        }
    }

    else if (status == 0 || status == 1){
        while (fread(cli, sizeof(Cliente), 1, arqCliente)) {
            if (cli->status == status) {
                printf("%s | %s | %s | %s | %s\n",
                cli->cpf, cli->nome, cli->dataNascimento, cli->email,
                cli->status ? "Ativo" : "Inativo");
            }
        }
    }
    fclose(arqCliente);
    free(cli);
}

void relatorioFuncionarios(int status) {
limparTela();

    Funcionarios* funcionario;
    FILE* arqFuncionarios;

    funcionario = (Funcionarios*)malloc(sizeof(Funcionarios));

    arqFuncionarios = fopen("Funcionarios/funcionarios.dat", "rb");

    printf("\n===============================================================================================\n");
    printf("||                             ~ ~ ~ Relatório de Funcionárioss ~ ~ ~                        ||\n");
    printf("===============================================================================================\n");
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
    limparTela();

    Ingressos* ingresso;
    FILE* arqIngresso;

    ingresso = (Ingressos*)malloc(sizeof(Ingressos));

    arqIngresso = fopen("Ingressos/ingressos.dat", "rb");

    printf("\n===========================================================================\n");
    printf("||                     ~ ~ ~ Relatório de Ingressos ~ ~ ~                ||\n");
    printf("===========================================================================\n");
    printf("ID | CPF do cliente | Quantidade de Ingressos | ID do espetáculo | Status\n");
    printf("-------------------------------------------------------------------------");

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

int buscarAgendamentosPorCidade(const char* cidadeBuscada) {
    limparTela();

    FILE* arqAgendamentos;

    arqAgendamentos = fopen("Agendamentos/agendamento.dat","rb");

    if (arqAgendamentos == NULL) {
        printf("\nErro ao abrir o arquivo de agendamentos!\n");
        return 0;
    }

    Agendamento* ag;
    ag = (Agendamento*)malloc(sizeof(Agendamento));
    int encontrados = 0;

    printf("\n========================================================================================================================\n");
    printf("||                               ~ ~ ~ Relatório de Agendamentos Filtrados Por Cidades ~ ~ ~                          ||\n");
    printf("========================================================================================================================\n");

    printf("\nID  |    Data    | Hora  |        Cidade        | Capacidade |  Preço  | Ingressos Vendidos | CPF Responsável | Status\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    while (fread(ag, sizeof(Agendamento), 1, arqAgendamentos)) {
        if (strcasecmp(ag->cidade, cidadeBuscada) == 0) {
            encontrados++;
            printf("%d | %s | %s | %s | %d | %.2f | %d | %s | %s\n",
                ag->id, ag->data, ag->horario, ag->cidade,
                ag->capacidade, ag->precoIngresso,
                ag->quantIngressosVend, ag->cpfResponsavel,
                ag->status ? "Ativo" : "Cancelado");
        }
    }

    return encontrados;
}

void filtrarAgendamentosPorCidade(void) {
    limparTela();

    FILE* arqAgendamentos = fopen("Agendamentos/agendamento.dat", "rb");
    if (arqAgendamentos == NULL) {
        printf("\nNenhum agendamento encontrado!\n");
        return;
    }

    printf("\n======================================================================\n");
    printf("||                     ~ ~ ~ Filtro de Cidades ~ ~ ~                ||\n");
    printf("======================================================================\n");

    char cidadeBuscada[50];
    printf("\nDigite a cidade para filtrar: ");
    fgets(cidadeBuscada, 50, stdin);
    cidadeBuscada[strcspn(cidadeBuscada, "\n")] = '\0';

    int encontrados = buscarAgendamentosPorCidade(cidadeBuscada);

    if (encontrados == 0) {
        printf("\nNenhum agendamento encontrado para a cidade \"%s\".\n", cidadeBuscada);
    }

    fclose(arqAgendamentos);
}

int buscarClientesPorNome(const char* nomeBuscado) {
    limparTela();

    FILE* arqCliente;
    arqCliente = fopen("Clientes/clientes.dat","rb");
    if (arqCliente == NULL){
        printf("\nErro ao abrir o arquivo!");
        return 0;
    }

    Cliente*cli;
    cli = (Cliente*)malloc(sizeof(Cliente));

    int encontrados = 0;

    printf("\n============================================================================================\n");
    printf("||                              ~ ~ ~ Relatório de Clientes ~ ~ ~                         ||\n");
    printf("============================================================================================\n");
    printf("\nCPF           | Nome                           | Data de Nasc.   | Email          | Status\n");
    printf("--------------------------------------------------------------------------------------------\n");

    while (fread(cli, sizeof(Cliente), 1, arqCliente)) {
        if (strcasestr(cli->nome, nomeBuscado) != NULL) {
            encontrados++;
            printf("%s | %s | %s | %s | %s\n",
                cli->cpf, cli->nome, cli->dataNascimento, cli->email,
                cli->status ? "Ativo" : "Inativo");
        }
    }

    return encontrados;
}

void filtrarClientesPorNome(void) {
    limparTela();

    FILE* arqCliente = fopen("Clientes/clientes.dat", "rb");
    if (arqCliente == NULL) {
        printf("\nNenhum cliente encontrado!\n");
        return;
    }

    printf("\n======================================================================\n");
    printf("||                      ~ ~ ~ Filtro de Nomes ~ ~ ~                 ||\n");
    printf("======================================================================\n");

    char nomeBuscado[50];
    printf("\nDigite parte do nome para buscar: ");
    fgets(nomeBuscado, 50, stdin);
    nomeBuscado[strcspn(nomeBuscado, "\n")] = '\0';

    int encontrados = buscarClientesPorNome(nomeBuscado);

    if (encontrados == 0) {
        printf("\nNenhum cliente encontrado contendo \"%s\" no nome.\n", nomeBuscado);
    }

    fclose(arqCliente);
}

int buscarFuncionariosPorNome(const char *nomeBuscado) {
    limparTela();

    FILE* arqFuncionarios;

    Funcionarios* func;
    func = (Funcionarios*)malloc(sizeof(Funcionarios));

    int encontrados = 0;
    
    printf("\n============================================================================================\n");
    printf("||                              ~ ~ ~ Relatório de Funcionários ~ ~ ~                     ||\n");
    printf("============================================================================================\n");
    printf("\nCPF           | Nome                           | Data de Nasc.   | Email          | Status\n");
    printf("--------------------------------------------------------------------------------------------\n");

    while (fread(func, sizeof(Funcionarios), 1, arqFuncionarios)) {
        if (strcasestr(func->nome, nomeBuscado) != NULL) {
            encontrados++;
            printf("%s | %s | %s | %s | %s | %s | %s | %s | %s | %s \n", func->nome, func->dataNascimento, func->email, func->cpf, func->sexo, func->endereco, func->telefone, func->salario, func->cargo, func->status ? "Ativo" : "Inativo");
        }
    }

    fclose(arqFuncionarios);
    free(func);

    return encontrados;

}

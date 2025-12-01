#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorio.h"
#include "../Agendamentos/agendamentos.h"
#include "../Clientes/clientes.h"
#include "../Utilitarios/utilitarios.h"
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
            case 4:
                filtrarIngressosPorEspetaculo();
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
    printf("||             4. Filtrar Funcionários por Nome                             ||\n");
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
    printf("||             4. Filtrar Ingressos por Espetáculo                          ||\n");
    printf("||             0. Voltar ao menu de Relatórios                              ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}

// Creáditos ao chatGPT por ajudar na implementação da função abaixo
// a partir de um código referencial de @flaviusgorgonio

void relatorioAgendamentos(int status){
    limparTela();

    FILE *arqAgendamentos;
    Funcionarios* funcionario;
    Agendamento tempAg;

    Ag* listaOrdenada = NULL;

    arqAgendamentos = fopen("Agendamentos/agendamento.dat", "rb");
    if (arqAgendamentos == NULL){
        printf("\n  Nenhum agendamento encontrado!\n");
        return;
    }

    while (fread(&tempAg, sizeof(Agendamento), 1, arqAgendamentos)) {

        if (status == 2 || tempAg.status == status) {
            inserirOrdenado(&listaOrdenada, &tempAg);
        }
    }

    fclose(arqAgendamentos);

    printf("\n==============================================================================\n");
    printf("||                     ~ ~ ~ Relatório de Agendamentos ~ ~ ~                ||\n");
    printf("==============================================================================\n");

    printf("\nID  |  Nome do Espetáculo  | Data       | Hora  | Cidade               | Capacidade | Preço   | Ingressos Vendidos | Nome do Responsável | Status\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");

    Ag* aux = listaOrdenada;

    if (status == 2) {
        while (aux != NULL) {
            funcionario = encontrarFuncionariosPorCpf(aux->ag.cpfResponsavel);

            printf("%d | %s | %s | %s | %s | %d | %.2f | %d | %s | %s\n",
                aux->ag.id, aux->ag.nomeEspetaculo, aux->ag.data, aux->ag.horario, aux->ag.cidade,
                aux->ag.capacidade, aux->ag.precoIngresso,
                aux->ag.quantIngressosVend, funcionario->nome,
                aux->ag.status ? "Ativo" : "Cancelado");

            aux = aux->prox;
        }
    } else if (status == 0 || status == 1) {
        while (aux != NULL) {
            if (aux->ag.status == status) {
                funcionario = encontrarFuncionariosPorCpf(aux->ag.cpfResponsavel);

                printf("%d | %s | %s | %s | %s | %d | %.2f | %d | %s | %s\n",
                    aux->ag.id, aux->ag.nomeEspetaculo, aux->ag.data, aux->ag.horario, aux->ag.cidade,
                    aux->ag.capacidade, aux->ag.precoIngresso,
                    aux->ag.quantIngressosVend, funcionario->nome,
                    aux->ag.status ? "Ativo" : "Cancelado");
            }
            aux = aux->prox;
        }

    }

    while (listaOrdenada != NULL) {
        Ag* tmp = listaOrdenada;
        listaOrdenada = listaOrdenada->prox;
        free(tmp);
    }
}


void relatorioClientes(int status){
    limparTela();

    Cliente* listaClientes = NULL;

    lerClientes("Clientes/clientes.dat", &listaClientes);

    printf("\n=============================================================================\n");
    printf("||                       ~ ~ ~ Relatório de Clientes ~ ~ ~                  ||\n");
    printf("=============================================================================\n");
    printf("\nCPF           | Nome                           | Data de Nasc.   | Email          | Status\n");
    printf("--------------------------------------------------------------------------------------------\n");

    Cliente* temp = listaClientes;

    if (status == 2) {
        while (temp != NULL) {
            printf("%s | %s | %s | %s | %s\n",
                temp->cpf, temp->nome, temp->dataNascimento, temp->email,
                temp->status ? "Ativo" : "Inativo");
            temp = temp->prox;
        }
    } else if( status == 0 || status == 1) {
        while (temp != NULL) {
            if (temp->status == status) {
                printf("%s | %s | %s | %s | %s\n",
                    temp->cpf, temp->nome, temp->dataNascimento, temp->email,
                    temp->status ? "Ativo" : "Inativo");
            }
            temp = temp->prox;
        }
    }

    while (listaClientes != NULL) {
        Cliente* aux = listaClientes;
        listaClientes = listaClientes->prox;
        free(aux);
    }

    return;
}

void relatorioFuncionarios(int status){
    limparTela();

    Funcionarios* listaFuncionarios = NULL;

    lerFuncionarios("Funcionarios/funcionarios.dat", &listaFuncionarios);

    printf("\n============================================================================================\n");
    printf("||                              ~ ~ ~ Relatório de Funcionários ~ ~ ~                     ||\n");
    printf("============================================================================================\n");
    printf("\nCPF | Nome | Data de Nasc. | Email | Sexo | Endereço | Telefone | Salário | Cargo |status\n");
    printf("--------------------------------------------------------------------------------------------\n");

    Funcionarios* temp = listaFuncionarios;

    if (status == 2) {
        while (temp != NULL) {
            printf("\n%s | %s | %s | %s | %s | %s | %s | %s | %s | %s",
            temp->cpf, temp->nome, temp->dataNascimento, temp->email, 
            temp->sexo, temp->endereco, temp->telefone, temp->salario, 
            temp->cargo, temp->status ? "Ativo" : "Inativo");
            temp = temp->prox;
        }
    } else if (status == 0 || status == 1) {
        while (temp != NULL) {
            if (temp->status == status) {
                printf("\n%s | %s | %s | %s | %s | %s | %s | %s | %s | %s",
                temp->cpf, temp->nome, temp->dataNascimento, temp->email, 
                temp->sexo, temp->endereco, temp->telefone, temp->salario, 
                temp->cargo, temp->status ? "Ativo" : "Inativo");
            }
            temp = temp->prox;
        }
    }

    while (listaFuncionarios != NULL) {
        Funcionarios* aux = listaFuncionarios;
        listaFuncionarios = listaFuncionarios->prox;
        free(aux);
    }

    return;
}

void relatorioIngressos(int status) {
    limparTela();

    Ingressos* ingresso;
    FILE* arqIngresso;
    Cliente* cliente;
    Agendamento* agendamento;

    ingresso = (Ingressos*)malloc(sizeof(Ingressos));

    arqIngresso = fopen("Ingressos/ingressos.dat", "rb");

    printf("\n===========================================================================\n");
    printf("||                     ~ ~ ~ Relatório de Ingressos ~ ~ ~                ||\n");
    printf("===========================================================================\n");
    printf("ID | Nome do cliente | Quantidade de Ingressos | Nome do espetáculo | Status\n");
    printf("----------------------------------------------------------------------------\n");

    cliente = encontrarClientePorCPF(ingresso->cpfCliente);
    agendamento = encontrarAgendamentoPorID(ingresso->idEspetaculo);

    if (status == 2) {
        while (fread(ingresso, sizeof(Ingressos), 1, arqIngresso)) {
        printf("\n%d | %s | %d | %s | %s ", ingresso->id, cliente->nome, ingresso->quantidadeIngressos, agendamento->nomeEspetaculo, ingresso->status ? "Ativo" : "Inativo");
        }
    } else if (status == 0 || status == 1) {
        while (fread(ingresso, sizeof(Ingressos), 1, arqIngresso)) {
            if (ingresso->status == status) {
                printf("\n%d | %s | %d | %s | %s ", ingresso->id, cliente->nome, ingresso->quantidadeIngressos, agendamento->nomeEspetaculo, ingresso->status ? "Ativo" : "Inativo");            }
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
    Funcionarios* funcionario;

    Agendamento* ag;
    ag = (Agendamento*)malloc(sizeof(Agendamento));
    int encontrados = 0;

    printf("\n========================================================================================================================\n");
    printf("||                               ~ ~ ~ Relatório de Agendamentos Filtrados Por Cidades ~ ~ ~                          ||\n");
    printf("========================================================================================================================\n");

    printf("\nID  |    Data    | Hora  |        Cidade        | Capacidade |  Preço  | Ingressos Vendidos | Nome do Responsável | Status\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    while (fread(ag, sizeof(Agendamento), 1, arqAgendamentos)) {
        if (strcasecmp(ag->cidade, cidadeBuscada) == 0) {
            encontrados++;
            funcionario = encontrarFuncionariosPorCpf(ag->cpfResponsavel);
            printf("%d | %s | %s | %s | %d | %.2f | %d | %s | %s\n",
                ag->id, ag->data, ag->horario, ag->cidade,
                ag->capacidade, ag->precoIngresso,
                ag->quantIngressosVend, funcionario->nome,
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
        if (strncasecmp(cli->nome, nomeBuscado, strlen(nomeBuscado)) == 0) {
            encontrados++;
            printf("%s | %s | %s | %s | %s\n",
                cli->cpf, cli->nome, cli->dataNascimento, cli->email,
                cli->status ? "Ativo" : "Inativo");
        }
    }

    free(cli);
    fclose(arqCliente);

    return encontrados;
}

void filtrarClientesPorNome(void) {
    limparTela();

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

    arqFuncionarios = fopen("Funcionarios/funcionarios.dat", "r+b");
    if (arqFuncionarios == NULL) {
        printf("\n\n\nERROR!\n\n\n");
        return 0 ;
    }

    while (fread(func, sizeof(Funcionarios), 1, arqFuncionarios)) {
        if (strncasecmp(func->nome, nomeBuscado,  strlen(nomeBuscado)) == 0) {
            encontrados++;
            printf("%s | %s | %s | %s | %s | %s | %s | %s | %s | %s \n", func->nome, func->dataNascimento, func->email, func->cpf, func->sexo, func->endereco, func->telefone, func->salario, func->cargo, func->status ? "Ativo" : "Inativo");
        }
    }

    fclose(arqFuncionarios);
    free(func);

    return encontrados;

}

void filtrarFuncionariosPorNome(void) {
    limparTela();

    int encontrados;

    printf("\n======================================================================\n");
    printf("||                      ~ ~ ~ Filtro de Nomes ~ ~ ~                 ||\n");
    printf("======================================================================\n");

    char nomeBuscado[50];
    printf("\nDigite parte do nome para buscar: ");
    fgets(nomeBuscado, 50, stdin);
    nomeBuscado[strcspn(nomeBuscado, "\n")] = '\0';

    encontrados = buscarFuncionariosPorNome(nomeBuscado);

    if (!encontrados) {
        printf("\nNenhum funcionário encontrado contendo \"%s\" no nome.\n", nomeBuscado);    
    }


}

int buscarIngressosPorEspetaculo(const int* espetaculoID) {
    limparTela();

    FILE* arqIngresso;
    Cliente* cliente;
    Agendamento* agendamento;

    Ingressos* ing;
    ing = (Ingressos*)malloc(sizeof(Ingressos));

    int encontrados;

    printf("\n============================================================================================\n");
    printf("||                              ~ ~ ~ Relatório de Ingressos ~ ~ ~                        ||\n");
    printf("============================================================================================\n");
    printf("\nID do  ingresso | Nome do Cliente | Quantidade  | Nome do espetáculo    | Status\n");
    printf("--------------------------------------------------------------------------------------------\n");

    arqIngresso = fopen("Ingressos/ingressos.dat", "r+b");
    if (arqIngresso == NULL) {
        printf("\n\n\nERROR\n\n\n");
        return 0;
    }

    while (fread(ing, sizeof(Ingressos), 1, arqIngresso)) {
        if (ing->idEspetaculo == *espetaculoID) {
            encontrados++;
            cliente = encontrarClientePorCPF(ing->cpfCliente);
            agendamento = encontrarAgendamentoPorID(ing->idEspetaculo);

            if (cliente == NULL) {
            printf("Cliente não encontrado.\n");
            } else {
            printf("%d | %s | %d | %s | %s \n", ing->id, cliente->nome, ing->quantidadeIngressos, agendamento->nomeEspetaculo, ing->status ? "Ativo":"Inativo");
            }

            
        }
    }

    free(cliente);
    free(agendamento);
    fclose(arqIngresso);
    free(ing);

    return encontrados;

}

void filtrarIngressosPorEspetaculo(void) {
    limparTela();

    int encontrados;
    int idBuscado;

    printf("\n======================================================================\n");
    printf("||                    ~ ~ ~ Filtro de Espetáculo ~ ~ ~              ||\n");
    printf("======================================================================\n");

    printf("Digite o ID do espetáculo: ");
    scanf("%d", &idBuscado);
    getchar();

    encontrados = buscarIngressosPorEspetaculo(&idBuscado);

    if (!encontrados) {
        printf("\nNenhum ingresso no espetáculo com ID: \"%d\"\n", idBuscado);
    }

}

Cliente* encontrarClientePorCPF(char cpfParametro[]) {
    FILE* arqCliente;
    Cliente* cli;
    cli = (Cliente*)malloc(sizeof(Cliente));
    arqCliente = fopen("Clientes/clientes.dat", "rb");
    if (arqCliente == NULL) {
        printf("\n\n\nERROR!\n\n\n");
    }

    while (fread(cli, sizeof(Cliente), 1, arqCliente)) {
        if (strcmp(cli->cpf, cpfParametro) == 0) {
            fclose(arqCliente);
            return cli;
        }
    }

    fclose(arqCliente);
    return NULL;
}

Agendamento* encontrarAgendamentoPorID(int idEspParametro) {
    FILE* arqAgendamento;
    Agendamento* ag;
    ag = (Agendamento*)malloc(sizeof(Agendamento));
    arqAgendamento = fopen("Agendamentos/agendamento.dat", "rb");
    if (arqAgendamento == NULL) {
        printf("\n\n\nERROR\n\n\n");
        return NULL;
    }

    while(fread(ag, sizeof(Agendamento), 1, arqAgendamento)) {
        if (ag->id == idEspParametro) {
            fclose(arqAgendamento);
            return ag;
        }
    }

    fclose(arqAgendamento);
    return NULL;
}

Funcionarios* encontrarFuncionariosPorCpf(char cpfParametro[]) {
    FILE* arqFuncionarios;
    Funcionarios* funcionario;
    funcionario = (Funcionarios*)malloc(sizeof(Funcionarios));
    arqFuncionarios = fopen("Funcionarios/funcionarios.dat", "rb");
    if (arqFuncionarios == NULL) {
        printf("\n\n\nERROR\n\n\n");
        return NULL;
    }

    while(fread(funcionario, sizeof(Funcionarios), 1, arqFuncionarios)) {
        if (strcmp(funcionario->cpf, cpfParametro) == 0) {
            fclose(arqFuncionarios);
            return funcionario;
        }
    }

    fclose(arqFuncionarios);
    return NULL;
}

// Créditos ao ChatGPT da OpenAI pela ajuda nesta função abaixo

int dataParaInt(const char* data) {
    int d, m, a;
    sscanf(data, "%d/%d/%d", &d, &m, &a);
    return a*10000 + m*100 + d;
}


void inserirOrdenado(Ag** lista, Agendamento* novoAg) {
    Ag* novo = (Ag*)malloc(sizeof(Ag));
    novo->ag = *novoAg;
    novo->prox = NULL;

    int dataNovo = dataParaInt(novoAg->data);

    Ag *atual = *lista, *anterior = NULL;

    while (atual != NULL && dataParaInt(atual->ag.data) < dataNovo) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        novo->prox = *lista;
        *lista = novo;
    } else {
        anterior->prox = novo;
        novo->prox = atual;
    }
}


void lerClientes(const char* nomeArquivo, Cliente** lista) {
    FILE *arqCliente;
    Cliente* novaCliente;
    
    arqCliente = fopen(nomeArquivo, "rb");
    if (arqCliente == NULL) {
        printf("Erro na abertura do arquivo de clientes!\n");
        exit(1);
    }

    while (1) {
        novaCliente = (Cliente*)malloc(sizeof(Cliente));
        if (novaCliente == NULL) {
            printf("Erro ao alocar memória para o cliente.\n");
            fclose(arqCliente);
            exit(1);
        }

        if (fread(novaCliente, sizeof(Cliente), 1, arqCliente) != 1) {
            free(novaCliente);
            break;
        }

        if (*lista == NULL || strcmp(novaCliente->nome, (*lista)->nome) < 0) {
            novaCliente->prox = *lista;
            *lista = novaCliente;
        } else {
            Cliente* anter = *lista, *atual = (*lista)->prox;
            while (atual != NULL && strcmp(novaCliente->nome, atual->nome) > 0) {
                anter = atual;
                atual = atual->prox;
            }
            anter->prox = novaCliente;
            novaCliente->prox = atual;
        }
    }

    fclose(arqCliente);
}

void lerFuncionarios(const char* nomeArquivo, Funcionarios** lista) {
    FILE *arqFuncionarios;
    Funcionarios* novoFuncionario;
    
    arqFuncionarios = fopen(nomeArquivo, "rb");
    if (arqFuncionarios == NULL) {
        printf("Erro na abertura do arquivo de funcionários!\n");
        exit(1);
    }

    while (1) {
        novoFuncionario = (Funcionarios*)malloc(sizeof(Funcionarios));
        if (novoFuncionario == NULL) {
            printf("Erro ao alocar memória para o funcionário.\n");
            fclose(arqFuncionarios);
            exit(1);
        }

        if (fread(novoFuncionario, sizeof(Funcionarios), 1, arqFuncionarios) != 1) {
            free(novoFuncionario);
            break;
        }

        // Inserção ordenada por nome
        if (*lista == NULL || strcmp(novoFuncionario->nome, (*lista)->nome) < 0) {
            novoFuncionario->prox = *lista;
            *lista = novoFuncionario;
        } else {
            Funcionarios* anter = *lista, *atual = (*lista)->prox;
            while (atual != NULL && strcmp(novoFuncionario->nome, atual->nome) > 0) {
                anter = atual;
                atual = atual->prox;
            }
            anter->prox = novoFuncionario;
            novoFuncionario->prox = atual;
        }
    }

    fclose(arqFuncionarios);
}

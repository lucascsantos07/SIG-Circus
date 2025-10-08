#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingressos.h"
#include "../Utilitarios/utilitarios.h"


void menuVendasIngressos(void) {
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
    printf("||                        -- Venda de Ingressos --                          ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||             1. Cadastrar Venda de Ingresso                               ||\n");
    printf("||             2. Consultar Venda de Ingresso                               ||\n");
    printf("||             3. Reembolsar Venda de Ingresso                              ||\n");
    printf("||             0. Voltar Menu Principal                                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}


void telaCadastroVendaIngresso(void) {
    limparTela();
    char linha[1000];
    int id;
    float valorTotal;

    Ingressos ing;

    FILE *arqIngressos;

    FILE *arqAgendamentos;

    id = 0;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Venda de Ingressos ~ ~ ~                      ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");
    
    printf("\n   CPF do Cliente        : ");
    fgets(ing.cpfCliente,20, stdin);
    ing.cpfCliente[strcspn(ing.cpfCliente, "\n")] = 0;
    printf("\n   Lista de Espetáculos:  \n ");
    printf("\n--------------------------------------------------------------------------------------------------------------------------------------------\n");


    arqAgendamentos = fopen("Agendamentos/agendamentos.csv", "rt");
    
    while (fgets(linha, sizeof(linha), arqAgendamentos)) {
        id++;
        sscanf(linha, "%[^;];%[^;];%[^;];%d;%f;%[^\n]", ing.data, ing.horario, ing.cidade, &ing.capacidadeMax, &ing.precoIngresso, ing.cpfResponsavel);
        printf("%d - Data: %s, Horário: %s, Cidade: %s, Quantidade de Ingressos Disponível: %d, Preço do Ingresso: %.2f, CPF do responsável: %s", id, ing.data, ing.horario, ing.cidade, ing.capacidadeMax, ing.precoIngresso, ing.cpfResponsavel);
        printf("\n--------------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    fclose(arqAgendamentos);

    id = 0;

    arqAgendamentos = fopen("Agendamentos/agendamentos.csv", "rt");

    printf("\n\n   Digite o id do espetáculo: ");
    scanf(" %d", &ing.idEspetaculo);
    getchar();
    while (fgets(linha, sizeof(linha), arqAgendamentos)) {
        id++;
        if (id == ing.idEspetaculo) {
            sscanf(linha, "%[^;];%[^;];%[^;];%d;%f;%[^\n]", ing.data, ing.horario, ing.cidade, &ing.capacidadeMax, &ing.precoIngresso, ing.cpfResponsavel);
            break;
        }
    }

    fclose(arqAgendamentos);
    printf("\n   Valor do ingresso: R$ %.2f", ing.precoIngresso);
    printf("\n\n   Digite a Quantidade de Ingressos: ");
    scanf(" %d", &ing.quantidadeIngressos);
    getchar();
    valorTotal = ing.quantidadeIngressos * ing.precoIngresso;
    printf("\n   Valor Total: R$ %.2f", valorTotal);

    printf("\n\n   Forma de Pagamento: \n");
    printf("\n      1 - PIX ");
    printf("\n      2 - Cartão de Crédito \n");
    printf("\n   Digite sua opcao: ");
    scanf(" %d", &ing.escolha);
    getchar();

    arqIngressos = fopen("Ingressos/ingressos.csv", "at");

    fprintf(arqIngressos, "%s;", ing.cpfCliente);
    fprintf(arqIngressos, "%d;", ing.idEspetaculo);
    fprintf(arqIngressos, "%d;", ing.quantidadeIngressos);
    fprintf(arqIngressos, "%.2f;", valorTotal);

    if(ing.escolha==1){
        fprintf(arqIngressos, "%s\n", "PIX");
    }else if(ing.escolha==2){
        fprintf(arqIngressos, "%s\n", "Cartão de Crédito");
    }

    fclose(arqIngressos);

    printf("\n==============================================================================\n");
    printf("||                           Venda concluída                                ||\n");
    printf("==============================================================================\n");

}


void consultarVendaIngresso(void) {
    limparTela();

    char linha[255];
    Ingressos ing;
    char resto[255];
    float valorTotal;

    FILE *arqIngressos;


    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Consultar Vendas ~ ~ ~                        ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||                   Developed by @ViniciusL07 -- since Aug, 2025           ||\n");
    printf("==============================================================================\n");

    printf("\nInforme o seu CPF: ");
    fgets(ing.cpfCliente, 20, stdin);
    ing.cpfCliente[strcspn(ing.cpfCliente, "\n")] = '\0';

    arqIngressos = fopen("Ingressos/ingressos.csv","rt");

    if (arqIngressos == NULL){
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }

    int encontrado = 0;

    printf("\nLista de ingressos encontrados do cliente %s:\n", ing.cpfCliente);

    while(fscanf(arqIngressos,"%[^\n]",linha) == 1){
        
        fgetc(arqIngressos);

        sscanf(linha, "%[^;];%[^\n]", ing.cpfCliente, resto);

        sscanf(resto, "%d;%[^\n]", &ing.idEspetaculo, resto);

        sscanf(resto, "%d;%[^\n]", &ing.quantidadeIngressos, resto);

        sscanf(resto, "%f;%[^\n]", &valorTotal, resto);

        sscanf(resto, "%[^\n]", &ing.formaPag);

        if(strcmp(ing.cpfCliente,ing.cpfCliente)==0){
            printf("\n==============================================================================\n");
            printf("\nCPF do Cliente: %s\n",ing.cpfCliente);
            printf("ID do Espetáculo: %d\n",ing.idEspetaculo);
            printf("Quantidade de Ingressos Comprados: %d\n",ing.quantidadeIngressos);
            printf("Valor Total: %.2f\n",valorTotal);
            printf("Forma de Pagamento: %d\n", ing.formaPag);
            printf("\n==============================================================================\n");
            encontrado++;
        }
    }

    if(encontrado==0){
        printf("\nNenhuma Venda para este Usuário\n");
    }

    fclose(arqIngressos);

}


void reembolsarVendaIngresso(void){
    limparTela();
    char cpf_busca[20];
    char justificativa[200];
    char confirma;
    int idVenda;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                   ~ ~ ~ Reembolso de Venda de Ingressos ~ ~ ~            ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");

    printf("\n   Informe seu CPF: ");
    fgets(cpf_busca, sizeof(cpf_busca), stdin);
    printf("\n   Lista seus Ingressos:\n");

    printf("\n   Informe o ID da Venda que deseja reembolsar: ");
    scanf("%d", &idVenda);
    getchar();

    printf("\n   Justificativa do reembolso: ");
    fgets(justificativa, sizeof(justificativa), stdin);

    printf("\n   Confirma o reembolso da venda %d? (S/N): ", idVenda);
    scanf(" %c", &confirma);
    getchar();

    if (confirma == 'S' || confirma == 's') {
        printf("\n   Reembolso realizado com sucesso!\n");
        printf("   Motivo: %s\n", justificativa);
    } else {
        printf("\n   Reembolso cancelado.\n");
    }
}



void exibirModuloVendasIngressos(void){
    char opcaoVendaIngresso;
    do{

        menuVendasIngressos();
        scanf(" %c", &opcaoVendaIngresso);
        getchar();
        if(opcaoVendaIngresso == '1'){
            telaCadastroVendaIngresso();
        }else if (opcaoVendaIngresso == '2'){
            consultarVendaIngresso();
        }else if(opcaoVendaIngresso == '3'){
            reembolsarVendaIngresso();
        }else if(opcaoVendaIngresso != '0'){
            printf("\nOpção inválida! Tente novamente.\n");
        }

        if (opcaoVendaIngresso != '0') {
            printf("\nPressione ENTER para continuar...");
            getchar();   
        }

    }while(opcaoVendaIngresso != '0');
}
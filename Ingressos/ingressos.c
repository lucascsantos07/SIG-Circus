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
    char cpfCliente[20];
    int quantidadeIngressos, escolha, idEspetaculo, id;
    float valorTotal;
    char linha[1000];

    char data[12], cpfResponsavel[20], cidade[50], horario[7], dataLida[12], cpfLido[20];
    int capacidadeMax;
    float precoIngresso;

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
    fgets(cpfCliente,20, stdin);
    cpfCliente[strcspn(cpfCliente, "\n")] = 0;
    printf("\n   Lista de Espetáculos:  \n ");
    printf("\n--------------------------------------------------------------------------------------------------------------------------------------------\n");


    arqAgendamentos = fopen("Agendamentos/agendamentos.csv", "rt");
    
    while (fgets(linha, sizeof(linha), arqAgendamentos)) {
        id++;
        sscanf(linha, "%[^;];%[^;];%[^;];%d;%f;%[^\n]", data, horario, cidade, &capacidadeMax, &precoIngresso, cpfResponsavel);
        printf("%d - Data: %s, Horário: %s, Cidade: %s, Quantidade de Ingressos Disponível: %d, Preço do Ingresso: %.2f, CPF do responsável: %s", id, data, horario, cidade, capacidadeMax, precoIngresso, cpfResponsavel);
        printf("\n--------------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    fclose(arqAgendamentos);

    id = 0;

    arqAgendamentos = fopen("Agendamentos/agendamentos.csv", "rt");

    printf("\n\n   Digite o id do espetáculo: ");
    scanf(" %d", &idEspetaculo);
    getchar();
    while (fgets(linha, sizeof(linha), arqAgendamentos)) {
        id++;
        if (id == idEspetaculo) {
            sscanf(linha, "%[^;];%[^;];%[^;];%d;%f;%[^\n]", data, horario, cidade, &capacidadeMax, &precoIngresso, cpfResponsavel);
            break;
        }
    }

    fclose(arqAgendamentos);
    printf("\n   Valor do ingresso: R$ %.2f", precoIngresso);
    printf("\n\n   Digite a Quantidade de Ingressos: ");
    scanf(" %d", &quantidadeIngressos);
    getchar();
    valorTotal = quantidadeIngressos * precoIngresso;
    printf("\n   Valor Total: R$ %.2f", valorTotal);

    printf("\n\n   Forma de Pagamento: \n");
    printf("\n      1 - PIX ");
    printf("\n      2 - Cartão de Crédito \n");
    printf("\n   Digite sua opcao: ");
    scanf(" %d", &escolha);
    getchar();

    arqIngressos = fopen("Ingressos/ingressos.csv", "at");

    fprintf(arqIngressos, "%s;", cpfCliente);
    fprintf(arqIngressos, "%d;", idEspetaculo);
    fprintf(arqIngressos, "%d;", quantidadeIngressos);
    fprintf(arqIngressos, "%.2f;", valorTotal);

    if(escolha==1){
        fprintf(arqIngressos, "%s\n", "PIX");
    }else if(escolha==2){
        fprintf(arqIngressos, "%s\n", "Cartão de Crédito");
    }

    fclose(arqIngressos);

    printf("\n==============================================================================\n");
    printf("||                           Venda concluída                                ||\n");
    printf("==============================================================================\n");

}


void consultarVendaIngresso(void) {
    limparTela();

    char cpfCliente[20], linha[256], resto[256];

    char cpfLido[20], formaPag[22];

    int quantidadeIngressos, idEspetaculo;
    float precoIngresso, valorTotal;

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
    fgets(cpfLido, 20, stdin);
    cpfLido[strcspn(cpfLido, "\n")] = '\0';

    arqIngressos = fopen("Ingressos/ingressos.csv","rt");

    if (arqIngressos == NULL){
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }

    int encontrado = 0;

    printf("\nLista de ingressos encontrados do cliente %s:\n", cpfLido);

    while(fscanf(arqIngressos,"%[^\n]",linha) == 1){
        
        fgetc(arqIngressos);

        sscanf(linha, "%[^;];%[^\n]", cpfCliente, resto);

        sscanf(resto, "%d;%[^\n]", &idEspetaculo, resto);

        sscanf(resto, "%d;%[^\n]", &quantidadeIngressos, resto);

        sscanf(resto, "%f;%[^\n]", &valorTotal, resto);

        sscanf(resto, "%[^\n]", formaPag);

        if(strcmp(cpfCliente,cpfLido)==0){
            printf("\n==============================================================================\n");
            printf("\nCPF do Cliente: %s\n",cpfCliente);
            printf("ID do Espetáculo: %d\n",idEspetaculo);
            printf("Quantidade de Ingressos Comprados: %d\n",quantidadeIngressos);
            printf("Valor Total: %.2f\n",valorTotal);
            printf("Forma de Pagamento: %s\n", formaPag);
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
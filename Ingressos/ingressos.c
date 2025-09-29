#include <stdio.h>
#include <stdlib.h>
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

    FILE *fp_ingressos;

    FILE *fp_agendamentosr;

    id = 0;

    fp_agendamentosr = fopen("Agendamentos/agendamentos.csv", "rt");

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Venda de Ingressos ~ ~ ~                      ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");
    
    printf("\n   CPF do Cliente        : ");
    fgets(cpfCliente, sizeof(cpfCliente), stdin);
    cpfCliente[strcspn(cpfCliente, "\n")] = 0;
    printf("\n   Lista de Espetáculos  : ");
    printf("\n-----------------------------------------------\n");

    while (fgets(linha, sizeof(linha), fp_agendamentosr)) {
        id++;
        sscanf(linha, "%[^;];%[^;];%[^;];%d;%f;%[^\n]", data, horario, cidade, &capacidadeMax, &precoIngresso, cpfResponsavel);
        printf("%d - Data: %s, Horário: %s, Cidade: %s, Capacidade Máxima de Pessoas: %d, Preço do Ingresso: %.2f, CPF do responsável: %s", id, data, horario, cidade, capacidadeMax, precoIngresso, cpfResponsavel);
        printf("\n-----------------------------------------------\n");
    }

    fclose(fp_agendamentosr);

    id = 0;

    fp_agendamentosr = fopen("Agendamentos/agendamentos.csv", "rt");

    printf("\n\n   Digite o id do espetáculo: ");
    scanf(" %d", &idEspetaculo);
    getchar();
    while (fgets(linha, sizeof(linha), fp_agendamentosr)) {
        id++;
        if (id == idEspetaculo) {
            sscanf(linha, "%[^;];%[^;];%[^;];%d;%f;%[^\n]", data, horario, cidade, &capacidadeMax, &precoIngresso, cpfResponsavel);
            break;
        }
    }

    fclose(fp_agendamentosr);
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

    fp_ingressos = fopen("Ingressos/ingressos.csv", "at");

    if (ftell(fp_ingressos) == 0) {
        fprintf(fp_ingressos, "%s;", cpfCliente);
    } else {
        fprintf(fp_ingressos, "\n%s;", cpfCliente);
    }

    fprintf(fp_ingressos, "%d;", idEspetaculo);
    fprintf(fp_ingressos, "%d;", quantidadeIngressos);
    fprintf(fp_ingressos, "%d;", escolha);

    fclose(fp_ingressos);

    printf("\n==============================================================================\n");
    printf("||                           Venda concluída                                ||\n");
    printf("==============================================================================\n");

}


void consultarVendaIngresso(void) {
    limparTela();
    int escolha, idEspetaculo, id;
    char dataInput[12], cpfCliente[20], linha[1000], linha2[1000];

    char data[12], cpfResponsavel[20], cidade[50], horario[7], dataLida[12], cpfLido[20];
    int quantidadeIngressos;
    float precoIngresso;

    FILE *fp_ingressos;


    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Consultar Vendas ~ ~ ~                        ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||                   Developed by @ViniciusL07 -- since Aug, 2025           ||\n");
    printf("==============================================================================\n");

    printf("\n   Selecione o ID do show: \n");
    scanf(" %d", &id);
    getchar();
    printf("\n   Vendas encontradas para o espetáculo selecionado: \n");
    fp_ingressos = fopen("Ingressos/ingressos.csv", "rt");
    if (fp_ingressos == NULL) {
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }
    while (fgets(linha, sizeof(linha), fp_ingressos)) {
        sscanf(linha, "%[^;];%d;%d;%d", cpfCliente, &idEspetaculo, &quantidadeIngressos, &escolha);
        if (id == idEspetaculo) {
            printf("\n==============================================================================\n");
            printf("\nCPF do Cliente: %s\n", cpfCliente);
            printf("ID do Espetáculo: %d\n", id);
            printf("Quantidade de Ingressos: %d\n", quantidadeIngressos);
            printf("Forma de Pagamento: %d\n", escolha);
            printf("\n==============================================================================\n");
        }
    }
    fclose(fp_ingressos);

    /* printf("\n   Deseja Pesquisar Por \n");
    printf("\n      1 - Data ");
    printf("\n      2 - Espetaculo ");
    printf("\n      3 - Cliente \n");
    printf("\n   Digite sua opcao: ");
    scanf(" %d", &escolha); 
    getchar();

    if(escolha == 1){
        printf("\n   Informe a Data (DD/MM/AAAA): ");
        fgets(dataInput, sizeof(data), stdin);
        dataInput[strcspn(dataInput, "\n")] = '\0';
        fp_agendamentos = fopen("Agendamentos/agendamentos.csv", "rt");
        fp_ingressos = fopen("Ingressos/ingressos.csv", "rt");
        if (fp_agendamentos == NULL){
            printf("Erro na criacao do arquivo\n!");
            exit(1);
        }
        while (fgets(linha, sizeof(linha), fp_agendamentos)) {
            sscanf(linha, "%[^;];%[^;];%[^;];%d;%f;%[^\n]", dataLida, horario, cidade, &quantidadeIngressos, &precoIngresso, cpfResponsavel);

            if (strcmp(dataInput, dataLida) == 0) {
                while (linha2, sizeof(linha2), fp_ingressos) {
                    sscanf(linha2, "%[^;];%d;%d;%d", cpfCliente, &idEspetaculo, &quantidadeIngressos, &escolha);
                    if (idEspetaculo == idEspetaculo) {
                        printf("\n==============================================================================\n");
                        printf("\nData: %s\n",data);
                        printf("Horário: %s\n",horario);
                        printf("Cidade: %s\n",cidade);
                        printf("Quantidade de Ingressos: %d\n",quantidadeIngressos);
                        printf("Preço do Ingresso: %.2f\n",precoIngresso);
                        printf("CPF do Responsável: %s\n",cpfResponsavel);
                        printf("\n==============================================================================\n");
                    }
                }
            } else {
                ids[idEspetaculo] = 0;
            }
            idEspetaculo++;
            
        }

    }else if(escolha == 2){
        printf("\n   Digite o id do espetáculo: ");
        scanf(" %d", &idEspetaculo);
        getchar();
        printf("\n   Vendas encontradas para o espetáculo selecionado: \n");
    }else if(escolha == 3){
        printf("\n   Informe a CPF do Cliente: ");
        fgets(cpfCliente, sizeof(cpfCliente), stdin);
        printf("\n   Compras encontradas do cliente %s\n", cpfCliente);
    }else{
        printf("\nOpção inválida! Tente novamente.\n");
    } */

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
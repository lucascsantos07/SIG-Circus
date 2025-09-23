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
    int quantidadeIngressos, escolha, idEspetaculo;
    float valorTotal, precoIngresso;

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
    printf("\n   Lista de Espetáculos  : ");
    printf("\n\n   Digite o id do espetáculo: ");
    scanf(" %f", &idEspetaculo);
    getchar();
    precoIngresso = 20.00;
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

    printf("\n==============================================================================\n");
    printf("||                           Venda concluída                                ||\n");
    printf("==============================================================================\n");

}


void consultarVendaIngresso(void) {
    limparTela();
    int escolha, idEspetaculo;
    char data[12], cpfCliente[20];

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Consultar Vendas ~ ~ ~                        ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||                   Developed by @ViniciusL07 -- since Aug, 2025           ||\n");
    printf("==============================================================================\n");

    printf("\n   Deseja Pesquisar Por \n");
    printf("\n      1 - Data ");
    printf("\n      2 - Espetaculo ");
    printf("\n      3 - Cliente \n");
    printf("\n   Digite sua opcao: ");
    scanf(" %d", &escolha);
    getchar();

    if(escolha == 1){
        printf("\n   Informe a Data (DD/MM/AAAA): ");
        fgets(data, sizeof(data), stdin);
        printf("\n   Vendas encontradas para a data %s\n", data);
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
    }

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
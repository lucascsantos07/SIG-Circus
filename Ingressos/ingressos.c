#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingressos.h"
#include "../Agendamentos/agendamentos.h"
#include "../Utilitarios/utilitarios.h"
#include "../Validacao/validacao.h"

#define True 1
#define False 0


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
    printf("||             4. Deletar Venda de Ingresso Permanentemente                 ||\n");
    printf("||             0. Voltar Menu Principal                                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}


void telaCadastroVendaIngresso(void) {
    limparTela();
    
    Ingressos* ingresso;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Venda de Ingressos ~ ~ ~                      ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");
    
    ingresso = ColetarDadosIngressos();

    ExibirIngresso(ingresso);

    ConfirmarCadastroIngresso(ingresso);

}


void consultarVendaIngresso(void) {
    limparTela();

    char cpfInput[20];
    int encontrado = 0;

    FILE* fp_ingresso;
    Ingressos* ingresso;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Consultar Vendas ~ ~ ~                        ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||                   Developed by @ViniciusL07 -- since Aug, 2025           ||\n");
    printf("==============================================================================\n");

    ingresso = (Ingressos*)malloc(sizeof(Ingressos));
    printf("\nInforme o CPF do Cliente: ");
    fgets(cpfInput, sizeof(cpfInput), stdin);
    cpfInput[strcspn(cpfInput, "\n")] = 0;

    fp_ingresso = fopen("Ingressos/ingressos.dat", "r+b");
    if (fp_ingresso == NULL) {
        printf("ERROR!");
        exit(1);
    }

    encontrado = 0;

    while (fread(ingresso, sizeof(Ingressos), 1, fp_ingresso)) {
        if (strcmp(ingresso->cpfCliente, cpfInput) == 0 && ingresso->status) {
            encontrado = 1;
            ExibirIngresso(ingresso);
        }
    }

    fclose(fp_ingresso);
    free(ingresso);
    if (!encontrado) {
        printf("Ingresso nao encontrado...");
    }
    return;
}


void reembolsarVendaIngresso(void){
    limparTela();
    Ingressos* ingresso;
    FILE* fp_ingresso;
    char confirma;
    int encontrado;
    int idVenda;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                   ~ ~ ~ Reembolso de Venda de Ingressos ~ ~ ~            ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");

    ingresso = (Ingressos*)malloc(sizeof(Ingressos));

    printf("\n   Informe o ID da Venda que deseja reembolsar: ");
    scanf("%d", &idVenda);
    getchar();

    fp_ingresso = fopen("Ingressos/ingressos.dat", "r+b");

    if (fp_ingresso == NULL) {
        printf("\n\nERROR!\n\n");
        exit(1);
    }

    encontrado = 0;

    while (fread(ingresso, sizeof(Ingressos), 1, fp_ingresso)) {
        if ((ingresso->id == idVenda) && ingresso->status) {
            encontrado = True;
            ExibirIngresso(ingresso);
            confirma = confirmarExclusao("Ingresso");
            if (confirma) {
                ingresso->status = 0;
                fseek(fp_ingresso,(-1)*sizeof(Ingressos), SEEK_CUR);
                fwrite(ingresso,sizeof(Ingressos),1,fp_ingresso);
            }
        }
    }

    fclose(fp_ingresso);
    free(ingresso);
    if(!encontrado){
        printf("\n  Cliente não encontrado\n");
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
        }else if(opcaoVendaIngresso == '4'){
            deletarIngressoPermanentemente();
        }else if(opcaoVendaIngresso != '0'){
            printf("\nOpção inválida! Tente novamente.\n");
        }

        if (opcaoVendaIngresso != '0') {
            printf("\nPressione ENTER para continuar...");
            getchar();   
        }

    }while(opcaoVendaIngresso != '0');
}

void ExibirTodosAgendamentos(void) {
    FILE* fp_agendamentos;
    Agendamento* agendamento;

    agendamento = (Agendamento*)malloc(sizeof(Agendamento));

    fp_agendamentos = fopen("Agendamentos/agendamento.dat", "rb");

    if (fp_agendamentos == NULL) {
        printf("\n\n\n\nERROR\n\n\n\n");
        exit(1);
    }

    

    while (fread(agendamento, sizeof(Agendamento), 1, fp_agendamentos) == 1) {
        if (agendamento->status) {
            exibirAgendamento(agendamento);
        }
    }

    fclose(fp_agendamentos);
    free(agendamento);

    return;
} 

Ingressos* ColetarDadosIngressos(void) {
    int valido = 0;
    int encontrado = 0;
    int quantidadeIngressosValidado = 0;
    int quantidadeSolicitada = 0;
    float precoDoIngresso = 0;
    Ingressos* ingresso;
    ingresso = (Ingressos*)malloc(sizeof(Ingressos));
    FILE* fp_agendamentos;
    Agendamento* agendamento;
    agendamento = (Agendamento*)malloc(sizeof(Agendamento));
    while (!valido) {
        printf("\n   CPF do Cliente: ");
        fgets(ingresso->cpfCliente, sizeof(ingresso->cpfCliente), stdin);
        ingresso->cpfCliente[strcspn(ingresso->cpfCliente, "\n")] = '\0';
        valido = validarCPF(ingresso->cpfCliente);
        if (!valido) {
            printf("CPF inválido. Tente novamente.\n");
        }
    }
    valido = 0;
    printf("\nAgendamentos Ativos\n");
    ExibirTodosAgendamentos();
    while (!valido) {
        printf("\nSelecione o ID do espetáculo: ");
        scanf(" %d", &ingresso->idEspetaculo);
        getchar();
        fp_agendamentos = fopen("Agendamentos/agendamento.dat", "r+b");
        while (fread(agendamento, sizeof(Agendamento), 1, fp_agendamentos)) {
            if (ingresso->idEspetaculo == agendamento->id && agendamento->status) {
                valido = 1;
            }
        }
        fclose(fp_agendamentos);
        if (!valido) {
            printf("ID inválido. Tente novamente.\n");
        }
    }
    ingresso->id = IngressoMaiorID() + 1;
    ingresso->status = 1;
    ingresso->quantidadeIngressos = 0;
    fp_agendamentos = fopen("Agendamentos/agendamento.dat", "r+b");
    while (fread(agendamento, sizeof(Agendamento), 1, fp_agendamentos)) {
        if (ingresso->idEspetaculo == agendamento->id && agendamento->status) {
            encontrado = 1;
            precoDoIngresso = agendamento->precoIngresso;
            printf("Preco do Ingresso: %.2f\n", precoDoIngresso);
        }
    }
    if (encontrado) {
        while (!quantidadeIngressosValidado) {
            printf("Quantidade de ingressos que deseja comprar: ");
            scanf(" %d", &quantidadeSolicitada);
            getchar();
            if (validarQuantidadeIngressos(agendamento, quantidadeSolicitada) && quantidadeSolicitada > 0) {
                quantidadeIngressosValidado = 1;
                ingresso->quantidadeIngressos = quantidadeSolicitada;
                agendamento->quantIngressosVend += ingresso->quantidadeIngressos;
                fseek(fp_agendamentos, (-1) * sizeof(Agendamento), SEEK_CUR);
                fwrite(agendamento, sizeof(Agendamento), 1, fp_agendamentos);
            } else {
                printf("Quantidade solicitada excede a capacidade disponível. Tente novamente.\n");
            }
        }
        ingresso->valorTotal = precoDoIngresso * ingresso->quantidadeIngressos;
        printf("\nValor Total: %.2f", ingresso->valorTotal);
        printf("\nForma de pagamento: \n1 - PIX\n2 - Dinheiro");
        scanf(" %d", &ingresso->formaPag);
        getchar();
    } else {
        printf("Espetáculo nao localizado.");
    }

    free(agendamento);
    fclose(fp_agendamentos);
    return ingresso;
}

void ExibirIngresso(Ingressos* ingresso) {
    printf("\n==============================================================================\n");
    printf("\nDados do Ingresso: \n");
    printf("\nCPF do Cliente: %s\n", ingresso->cpfCliente);
    printf("\nQuantidade de Ingressos: %d\n", ingresso->quantidadeIngressos);
    printf("\nID do Espetáculo: %d\n", ingresso->idEspetaculo);
    printf("\nID do Ingresso: %d\n", ingresso->id);
    printf("\nValor Total: %f\n", ingresso->valorTotal);
    printf("\n==============================================================================\n");
}

int IngressoMaiorID(void) {
    FILE* fp_ingresso;
    Ingressos temp;
    int maiorID;
    fp_ingresso = fopen("Ingressos/ingressos.dat", "rb");
    if (fp_ingresso == NULL) {
        printf("ËRROR!");
        exit(1);
    }
    maiorID = 0;
    while (fread(&temp, sizeof(Ingressos), 1, fp_ingresso) == True) {
        if (temp.id > maiorID) {
            maiorID = temp.id;
        }
    }
    fclose(fp_ingresso);
    return maiorID;
}

void ConfirmarCadastroIngresso(Ingressos* ingresso) {
    int opcao;
    FILE* fp_ingresso;

    printf("\nConfirmar cadastro (1)\nRecusar Cadastro(0)\n ");
    scanf( "%d", &opcao);
    getchar();

    switch (opcao) {
        case 0:
            printf("Cadastro Cancelado!");
            free(ingresso);
            break;
        case 1:
            fp_ingresso = fopen("Ingressos/ingressos.dat", "ab");

            if (fp_ingresso == NULL) {
                printf("\n\nERROR!\n\n");
                exit(1);
            }

            SalvarIngresso(fp_ingresso, ingresso);
            free(ingresso);
            fclose(fp_ingresso);
            printf("Cadastro Concluído!");
            break;
        
    }

}

void SalvarIngresso(FILE* fp_ingresso, Ingressos* ingresso) {
    fwrite(ingresso, sizeof(Ingressos), 1, fp_ingresso);
}

void deletarIngressoPermanentemente(void){
    limparTela();
    Ingressos* ingresso;
    FILE* fp_ingresso;
    FILE* fp_temp;
    FILE* fp_agendamentos;
    char confirma;
    int encontrado;
    int idVenda;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||             ~ ~ ~ Deletar Venda de Ingressos Permanentemente ~ ~ ~       ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");

    ingresso = (Ingressos*)malloc(sizeof(Ingressos));

    printf("\n   Informe o ID da Venda que deseja deletar permanentemente: ");
    scanf("%d", &idVenda);
    getchar();

    fp_ingresso = fopen("Ingressos/ingressos.dat", "rb");
    fp_temp = fopen("Ingressos/temp.dat", "wb");

    if (fp_ingresso == NULL || fp_temp == NULL) {
        printf("\n\nERROR!\n\n");
        exit(1);
    }

    encontrado = 0;

    while (fread(ingresso, sizeof(Ingressos), 1, fp_ingresso)) {
        if ((ingresso->id == idVenda)) {
            encontrado = True;
            ExibirIngresso(ingresso);
            confirma = confirmarExclusao("Ingresso Permanentemente");
            if (confirma == False) {
                fwrite(ingresso, sizeof(Ingressos), 1, fp_temp);
            } else {
                fp_agendamentos = fopen("Agendamentos/agendamento.dat", "r+b");
                Agendamento* agendamento;
                agendamento = (Agendamento*)malloc(sizeof(Agendamento));
                while (fread(agendamento, sizeof(Agendamento), 1, fp_agendamentos)) {
                    if (ingresso->idEspetaculo == agendamento->id && agendamento->status) {
                        agendamento->quantIngressosVend -= ingresso->quantidadeIngressos;
                        fseek(fp_agendamentos, (-1) * sizeof(Agendamento), SEEK_CUR);
                        fwrite(agendamento, sizeof(Agendamento), 1, fp_agendamentos);
                    }
                }
                free(agendamento);
                fclose(fp_agendamentos);
            }
        } else {
            fwrite(ingresso, sizeof(Ingressos), 1, fp_temp);
        }
    }

    fclose(fp_ingresso);
    fclose(fp_temp);
    free(ingresso);

    remove("Ingressos/ingressos.dat");
    rename("Ingressos/temp.dat", "Ingressos/ingressos.dat");

    if(!encontrado){
        printf("\n  Ingresso não encontrado\n");
    }

}
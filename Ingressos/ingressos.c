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

    FILE* arqIngressos;
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

    arqIngressos = fopen("Ingressos/ingressos.dat", "r+b");
    if (arqIngressos == NULL) {
        printf("ERROR!");
        exit(1);
    }

    encontrado = 0;

    while (fread(ingresso, sizeof(Ingressos), 1, arqIngressos)) {
        if (strcmp(ingresso->cpfCliente, cpfInput) == 0 && ingresso->status) {
            encontrado = 1;
            ExibirIngresso(ingresso);
        }
    }

    fclose(arqIngressos);
    free(ingresso);
    if (!encontrado) {
        printf("Ingresso nao encontrado...");
    }
    return;
}


void reembolsarVendaIngresso(void){
    limparTela();
    Ingressos* ingresso;
    FILE* arqIngressos;
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

    arqIngressos = fopen("Ingressos/ingressos.dat", "r+b");

    if (arqIngressos == NULL) {
        printf("\n\nERROR!\n\n");
        exit(1);
    }

    encontrado = 0;

    while (fread(ingresso, sizeof(Ingressos), 1, arqIngressos)) {
        if ((ingresso->id == idVenda) && ingresso->status) {
            encontrado = True;
            ExibirIngresso(ingresso);
            confirma = confirmarExclusao("Ingresso");
            if (confirma) {
                ingresso->status = 0;
                fseek(arqIngressos,(-1)*sizeof(Ingressos), SEEK_CUR);
                fwrite(ingresso,sizeof(Ingressos),1,arqIngressos);
            }
        }
    }

    fclose(arqIngressos);
    free(ingresso);
    if(!encontrado){
        printf("\n   Venda não encontrado\n");
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
            getchar();
        }

        if (opcaoVendaIngresso != '0') {
            printf("\nPressione ENTER para continuar...");
            getchar();   
        }

    }while(opcaoVendaIngresso != '0');
}

void ExibirTodosAgendamentos(void) {
    FILE* arqAgendamentos;
    Agendamento* agendamento;

    agendamento = (Agendamento*)malloc(sizeof(Agendamento));

    arqAgendamentos = fopen("Agendamentos/agendamento.dat", "rb");

    if (arqAgendamentos == NULL) {
        printf("\n\n\n\nERROR\n\n\n\n");
        exit(1);
    }

    

    while (fread(agendamento, sizeof(Agendamento), 1, arqAgendamentos) == 1) {
        if (agendamento->status) {
            exibirAgendamento(agendamento);
        }
    }

    fclose(arqAgendamentos);
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
    FILE* arqAgendamentos;
    Agendamento* agendamento;
    agendamento = (Agendamento*)malloc(sizeof(Agendamento));
    lerCPF(ingresso->cpfCliente, 12);
    valido = 0;
    printf("\nAgendamentos Ativos\n");
    ExibirTodosAgendamentos();
    while (!valido) {
        printf("\nSelecione o ID do espetáculo: ");
        scanf(" %d", &ingresso->idEspetaculo);
        getchar();
        arqAgendamentos = fopen("Agendamentos/agendamento.dat", "r+b");
        while (fread(agendamento, sizeof(Agendamento), 1, arqAgendamentos)) {
            if (ingresso->idEspetaculo == agendamento->id && agendamento->status) {
                valido = 1;
            }
        }
        fclose(arqAgendamentos);
        if (!valido) {
            printf("ID inválido. Tente novamente.\n");
        }
    }
    ingresso->id = IngressoMaiorID() + 1;
    ingresso->status = 1;
    ingresso->quantidadeIngressos = 0;
    arqAgendamentos = fopen("Agendamentos/agendamento.dat", "r+b");
    while (fread(agendamento, sizeof(Agendamento), 1, arqAgendamentos)) {
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
                fseek(arqAgendamentos, (-1) * sizeof(Agendamento), SEEK_CUR);
                fwrite(agendamento, sizeof(Agendamento), 1, arqAgendamentos);
            } else {
                printf("Quantidade solicitada excede a capacidade disponível. Tente novamente.\n");
            }
        }
        ingresso->valorTotal = precoDoIngresso * ingresso->quantidadeIngressos;
        printf("\nValor Total: %.2f", ingresso->valorTotal);
        lerFormaDePagamento(ingresso->formaPag);
    } else {
        printf("Espetáculo nao localizado.");
    }

    free(agendamento);
    fclose(arqAgendamentos);
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
    FILE* arqIngressos;
    Ingressos temp;
    int maiorID;
    arqIngressos = fopen("Ingressos/ingressos.dat", "rb");
    if (arqIngressos == NULL) {
        printf("ËRROR!");
        exit(1);
    }
    maiorID = 0;
    while (fread(&temp, sizeof(Ingressos), 1, arqIngressos) == True) {
        if (temp.id > maiorID) {
            maiorID = temp.id;
        }
    }
    fclose(arqIngressos);
    return maiorID;
}

void ConfirmarCadastroIngresso(Ingressos* ingresso) {
    int opcao;
    FILE* arqIngressos;

    printf("\nConfirmar cadastro (1)\nRecusar Cadastro(0)\n ");
    scanf( "%d", &opcao);
    getchar();

    switch (opcao) {
        case 0:
            printf("Cadastro Cancelado!");
            free(ingresso);
            break;
        case 1:
            arqIngressos = fopen("Ingressos/ingressos.dat", "ab");

            if (arqIngressos == NULL) {
                printf("\n\nERROR!\n\n");
                exit(1);
            }

            SalvarIngresso(arqIngressos, ingresso);
            free(ingresso);
            fclose(arqIngressos);
            printf("Cadastro Concluído!");
            break;
        
    }

}

void SalvarIngresso(FILE* arqIngressos, Ingressos* ingresso) {
    fwrite(ingresso, sizeof(Ingressos), 1, arqIngressos);
}

void deletarIngressoPermanentemente(void){
    limparTela();
    Ingressos* ingresso;
    FILE* arqIngressos;
    FILE* arqTemp;
    FILE* arqAgendamentos;
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
    scanf(" %d", &idVenda);
    getchar();

    arqIngressos = fopen("Ingressos/ingressos.dat", "rb");
    arqTemp = fopen("Ingressos/temp.dat", "wb");

    if (arqIngressos == NULL || arqTemp == NULL) {
        printf("\n\nERROR!\n\n");
        exit(1);
    }

    encontrado = 0;

    while (fread(ingresso, sizeof(Ingressos), 1, arqIngressos)) {
        if ((ingresso->id == idVenda)) {
            encontrado = True;
            ExibirIngresso(ingresso);
            confirma = confirmarExclusao("Ingresso Permanentemente");
            if (confirma == False) {
                fwrite(ingresso, sizeof(Ingressos), 1, arqTemp);
            } else {
                arqAgendamentos = fopen("Agendamentos/agendamento.dat", "r+b");
                Agendamento* agendamento;
                agendamento = (Agendamento*)malloc(sizeof(Agendamento));
                while (fread(agendamento, sizeof(Agendamento), 1, arqAgendamentos)) {
                    if (ingresso->idEspetaculo == agendamento->id && agendamento->status) {
                        agendamento->quantIngressosVend -= ingresso->quantidadeIngressos;
                        fseek(arqAgendamentos, (-1) * sizeof(Agendamento), SEEK_CUR);
                        fwrite(agendamento, sizeof(Agendamento), 1, arqAgendamentos);
                    }
                }
                free(agendamento);
                fclose(arqAgendamentos);
            }
        } else {
            fwrite(ingresso, sizeof(Ingressos), 1, arqTemp);
        }
    }

    fclose(arqIngressos);
    fclose(arqTemp);
    free(ingresso);

    remove("Ingressos/ingressos.dat");
    rename("Ingressos/temp.dat", "Ingressos/ingressos.dat");

    if(!encontrado){
        printf("\n  Ingresso não encontrado\n");
    }

}
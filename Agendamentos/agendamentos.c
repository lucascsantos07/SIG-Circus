#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendamentos.h"
#include "../Utilitarios/utilitarios.h"

void exibirModuloAgendamentos(void){
    char opcaoAgendamento;
    do{

        menuAgendamentos();
        scanf(" %c", &opcaoAgendamento);
        getchar();

        if(opcaoAgendamento == '1'){
            telaCadastroAgendamento();
        }else if (opcaoAgendamento == '2'){
            consultarAgendamento();
        }else if(opcaoAgendamento == '3'){
            alterarAgendamento();
        }else if(opcaoAgendamento == '4'){
            excluirAgendamento();
        }else if(opcaoAgendamento == '5'){
            listarTodosAgendamentos();
        }else if(opcaoAgendamento != '0'){
            printf("\nOpção inválida! Tente novamente.\n");
        }

        if (opcaoAgendamento != '0') {
            printf("\nPressione ENTER para continuar...");
            getchar(); 
            //Depois de selecionar uma opção mostra essa mensagem
        }

    }while(opcaoAgendamento != '0');
}

void menuAgendamentos(void){
    limparTela();
    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||             Universidade Federal do Rio Grande do Norte                  ||\n");
    printf("||                 Centro de Ensino Superior do Seridó                      ||\n");
    printf("||               Departamento de Computação e Tecnologia                    ||\n");
    printf("||                  Disciplina DCT1106 -- Programação                       ||\n");
    printf("||                         Projeto SIG-Circus                               ||\n");
    printf("||             Developed by @lucascsantos07 -- since Aug, 2025              ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||               ~ ~ ~ Sistema de Gestão Para Um Circo ~ ~ ~                ||\n");
    printf("||                                                                          ||\n");
    printf("||                           -- Agendamentos --                             ||\n");
    printf("||                                                                          ||\n");
    printf("||             1. Cadastrar Espetaculo                                      ||\n");
    printf("||             2. Consultar Espetaculo                                      ||\n");
    printf("||             3. Alterar Espetaculo                                        ||\n");
    printf("||             4. Cancelar Espetaculo                                       ||\n");
    printf("||             5. Listar Todos os Agendamentos Futuros                      ||\n");
    printf("||             0. Voltar Menu Principal                                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}

void telaCadastroAgendamento(void){
    limparTela();
    char data[12], cpfResponsavel[20], cidade[50], horario[7];
    int capacidadeMax;
    float precoIngresso;

    FILE *arq_agendamentos;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                    ~ ~ ~ Agendamento de Espetáculo ~ ~ ~                 ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    printf("\n   Data (DD/MM/AAAA): ");
    fgets(data, 12, stdin);
    data[strcspn(data, "\n")] = 0;

    printf("\n   Horário(HH:MM): ");
    fgets(horario, 7, stdin);
    horario[strcspn(horario, "\n")] = 0;

    printf("\n   Cidade que será realizado o espetáculo: ");
    fgets(cidade, 50, stdin);
    cidade[strcspn(cidade, "\n")] = 0;

    printf("\n   Capacidade Maxima de Publico: ");
    scanf(" %d", &capacidadeMax);
    getchar();

    printf("\n   Preço do Ingresso: ");
    scanf(" %f", &precoIngresso);
    getchar();

    printf("\n   CPF do Responsável pelo Agendamento: ");
    fgets(cpfResponsavel, 20, stdin);
    cpfResponsavel[strcspn(cpfResponsavel, "\n")] = 0;

    arq_agendamentos = fopen("Agendamentos/agendamentos.csv","at");

    if (arq_agendamentos == NULL){
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }

    fprintf(arq_agendamentos, "%s;", data);
    fprintf(arq_agendamentos,"%s;",horario);
    fprintf(arq_agendamentos,"%s;",cidade);
    fprintf(arq_agendamentos,"%d;",capacidadeMax);
    fprintf(arq_agendamentos,"%.2f;",precoIngresso);
    fprintf(arq_agendamentos,"%s\n",cpfResponsavel);
    fclose(arq_agendamentos);
    

    printf("\n==============================================================================\n");
    printf("||                             Cadastro concluído                           ||\n");
    printf("==============================================================================\n");

}

void alterarAgendamento(void){
    limparTela();

    int codAgendamento, capacidadeMax;
    float precoIngresso;
    char data[12], cpf_busca[20], cidade[50], horario[7];

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                 ~ ~ ~ Alteracao de Agendamento ~ ~ ~                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    printf("\n   Informe CPF do Responsavel pelo Agendamento: ");
    fgets(cpf_busca, sizeof(cpf_busca), stdin);

    printf("\n   Lista dos Agendamentos do Responsável Informado: \n");

    printf("\n   Digite o código do Agendamento que deseja alterar: ");
    scanf(" %d", &codAgendamento);
    getchar();

    printf("\n   Data (DD/MM/AAAA)                   : ");
    fgets(data, sizeof(data), stdin);

    printf("\n   Horário(HH:MM): ");
    fgets(horario, sizeof(horario), stdin);

    printf("\n   Cidade que será realizado o espetáculo: ");
    fgets(cidade, sizeof(cidade), stdin);

    printf("\n   Capacidade Maxima de Publico        : ");
    scanf(" %d", &capacidadeMax);
    getchar();

    printf("\n   Preço do Ingresso: ");
    scanf(" %f", &precoIngresso);
    getchar();

    confirmarAlteracao();

}


void excluirAgendamento(void){
    limparTela();

    int codAgendamento;
    char cpf_busca[20];


    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                  ~ ~ ~ Exclusao de Espetaculo ~ ~ ~                      ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    printf("\n   Informe CPF do Responsavel pelo Agendamento: ");
    fgets(cpf_busca, sizeof(cpf_busca), stdin);

    printf("\n   Lista dos Agendamentos do Responsável Informado: \n");

    printf("\n   Digite o código do Agendamento que deseja excluir: ");
    scanf(" %d", &codAgendamento);
    getchar();

    printf("\n==============================================================================\n");
    printf("\nAGENDAMENTO \n");
    printf("Data: \n");
    printf("Horario: \n");
    printf("Local: \n");
    printf("Capacidade: \n");
    printf("Preço: \n");
    printf("CPF Responsavel: \n");
    printf("\n==============================================================================\n");

    confirmarExclusao("Agendamento");

}


void listarTodosAgendamentos(void){
    limparTela();

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                             ~ ~ ~ Agenda ~ ~ ~                           ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    printf("\n>> Segunda Feira (27/10/2025) \n");

    printf("\n==============================================================================\n");
    printf("\n|| Horario: 20:00\n");
    printf("|| Local: Parelhas\n");
    printf("|| Capacidade: 500\n");
    printf("|| CPF Responsavel: 123.456.789-12\n");
    printf("\n==============================================================================\n");

    printf("\n>> Terça Feira (28/10/2025) \n");

    printf("\n==============================================================================\n");
    printf("\n|| Horario: 09:00\n");
    printf("|| Local: Caicó\n");
    printf("|| Capacidade: 0\n");
    printf("|| CPF Responsavel: 123.444.777-99\n");
    printf("\n==============================================================================\n");
}

void consultarAgendamento(void){
    limparTela();

    int escolha;
    FILE *arq_agendamentos;
    char data[12], cpfResponsavel[20], cidade[50], horario[7], dataLida[12], cpfLido[20];
    int capacidadeMax;
    float precoIngresso;
    char linha[255];
    char resto[255];

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                   ~ ~ ~ Consultar Agendamentos ~ ~ ~                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    printf("\n   Deseja Pesquisar Por \n");
    printf("\n      1 - Data ");
    printf("\n      2 - Responsavel \n");
    printf("\n   Digite sua opcao: ");
    scanf("%d", &escolha);
    getchar();

    if(escolha == 1){
        printf("\n   Informe a Data (DD/MM/AAAA): ");
        fgets(dataLida, 12, stdin);
        dataLida[strcspn(dataLida, "\n")] = '\0';

        arq_agendamentos= fopen("Agendamentos/agendamentos.csv","rt");

        if (arq_agendamentos == NULL){
            printf("Erro na criacao do arquivo\n!");
            exit(1);
        }

        int encontrado = 0;

        printf("\nLista de Agendamentos encontrados na data %s:\n", dataLida);

        while(fscanf(arq_agendamentos,"%[^\n]",linha) == 1){
            
            fgetc(arq_agendamentos);

            sscanf(linha, "%[^;];%[^\n]", data, resto);

            sscanf(resto, "%[^;];%[^\n]", horario, resto);

            sscanf(resto, "%[^;];%[^\n]", cidade, resto);

            sscanf(resto, "%d;%[^\n]", &capacidadeMax, resto);

            sscanf(resto, "%f;%[^\n]", &precoIngresso, resto);

            sscanf(resto, "%[^\n]", cpfResponsavel);

            if(strcmp(data,dataLida)==0){
                printf("\n==============================================================================\n");
                printf("\nData: %s\n",data);
                printf("Horário: %s\n",horario);
                printf("Cidade: %s\n",cidade);
                printf("Capacidade Máxima de Público: %d\n",capacidadeMax);
                printf("Preço do Ingresso: %.2f\n",precoIngresso);
                printf("CPF do Responsável: %s\n",cpfResponsavel);
                printf("\n==============================================================================\n");
                encontrado++;
            }
        }

        if(encontrado==0){
            printf("\nNenhum espetáculo marcado para esta data\n");
        }

        fclose(arq_agendamentos);

    }else if(escolha == 2){
        printf("\n   Informe a CPF do Responsavel: ");
        fgets(cpfLido, 20, stdin);
        cpfLido[strcspn(cpfLido, "\n")] = '\0';

        arq_agendamentos= fopen("Agendamentos/agendamentos.csv","rt");

        if (arq_agendamentos == NULL){
            printf("Erro na criacao do arquivo\n!");
            exit(1);
        }

        int encontrado = 0;

        printf("\nLista de Agendamentos cadastrado pelo responsável %s\n", cpfLido);

        while(fscanf(arq_agendamentos,"%[^\n]",linha) == 1){
            
            fgetc(arq_agendamentos);

            sscanf(linha, "%[^;];%[^\n]", data, resto);

            sscanf(resto, "%[^;];%[^\n]", horario, resto);

            sscanf(resto, "%[^;];%[^\n]", cidade, resto);

            sscanf(resto, "%d;%[^\n]", &capacidadeMax, resto);

            sscanf(resto, "%f;%[^\n]", &precoIngresso, resto);

            sscanf(resto, "%[^\n]", cpfResponsavel);

            if(strcmp(cpfResponsavel,cpfLido)==0){
                printf("\n==============================================================================\n");
                printf("\nData: %s\n",data);
                printf("Horário: %s\n",horario);
                printf("Cidade: %s\n",cidade);
                printf("Capacidade Máxima de Público: %d\n",capacidadeMax);
                printf("Preço do Ingresso: %.2f\n",precoIngresso);
                printf("CPF do Responsável: %s\n",cpfResponsavel);
                printf("\n==============================================================================\n");
                encontrado++;
            }
        }

        if(encontrado==0){
            printf("\nNenhum espetáculo marcado por esse responsavel\n");
        }

        fclose(arq_agendamentos);

    }else{
        printf("\nOpção inválida! Tente novamente.\n");
    }

}
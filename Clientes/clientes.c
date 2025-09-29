#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "../Utilitarios/utilitarios.h"

void menuCliente(void) {
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
    printf("||                           -- Menu Cliente --                             ||\n");
    printf("||                                                                          ||\n");
    printf("||             1. Cadastra-se                                               ||\n");
    printf("||             2. Listar dados pessoais                                     ||\n");
    printf("||             3. Editar dados pessoais                                     ||\n");
    printf("||             4. Excluir conta                                             ||\n");
    printf("||             0. Voltar Menu Principal                                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}



void telaCadastroCliente(void){
    limparTela();
    char nome[50];
    char dataNascimento[20];
    char email[100];
    char cpf[20];

    FILE *arq_cliente;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Cadastro de Cliente ~ ~ ~                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");
    
    printf("\n   CPF: ");
    fgets(cpf, 20, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';
    printf("\n   Nome Completo: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    printf("\n   Email: ");
    fgets(email, 100, stdin);
    email[strcspn(email, "\n")] = '\0';
    printf("\n   Data de Nascimento: ");
    fgets(dataNascimento, 20, stdin);
    dataNascimento[strcspn(dataNascimento, "\n")] = '\0';

    arq_cliente = fopen("Clientes/clientes.csv","at");

    if (arq_cliente == NULL){
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }
    
    fprintf(arq_cliente,"%s;",cpf);
    fprintf(arq_cliente,"%s;",nome);
    fprintf(arq_cliente,"%s;",email);
    fprintf(arq_cliente,"%s\n",dataNascimento);
    fclose(arq_cliente);

    printf("\n==============================================================================\n");
    printf("||                             Cadastro concluído                           ||\n");
    printf("==============================================================================\n");

}


void listarDadosCliente(void){
    limparTela();
    char cpf[20];
    char nome[50];
    char dataNascimento[20];
    char email[100];
    
    char cpf_lido[20];
    FILE *arq_cliente;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                        ~ ~ ~ Dados Pessoais ~ ~ ~                        ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    printf("\nInforme o seu CPF: ");
    fgets(cpf_lido, 20, stdin);
    cpf_lido[strcspn(cpf_lido, "\n")] = '\0';

    arq_cliente= fopen("Clientes/clientes.csv","rt");

    if (arq_cliente == NULL){
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }

    while(!feof(arq_cliente)){
        fscanf(arq_cliente, "%[^;]",cpf);
        fgetc(arq_cliente);
        fscanf(arq_cliente, "%[^;]",nome);
        fgetc(arq_cliente);
        fscanf(arq_cliente, "%[^;]",email);
        fgetc(arq_cliente);
        fscanf(arq_cliente, "%[^\n]",dataNascimento);
        fgetc(arq_cliente);
        if(strcmp(cpf,cpf_lido)==0){
            printf("\n==============================================================================\n");
            printf("\nCPF: %s\n",cpf);
            printf("Nome: %s\n",nome);
            printf("Email: %s\n",email);
            printf("Data de Nascimento: %s",dataNascimento);
            printf("\n==============================================================================\n");
            fclose(arq_cliente);
            return;
        }
    }
    fclose(arq_cliente);
    printf("Cliente não encontrado");
}



void editarDadoscliente(void){
    limparTela();

    char cpf_busca[20];
    char novoNome[50];
    char novaDataNascimento[20];
    char novoEmail[100];
    char novoCpf[20];

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Editando seus Dados ~ ~ ~                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    printf("\n   Informe o seu CPF: ");
    fgets(cpf_busca, sizeof(cpf_busca), stdin);

    printf("\n   Nome Completo       : ");
    fgets(novoNome, sizeof(novoNome), stdin);
    printf("\n   Data de Nascimento  : ");
    fgets(novaDataNascimento, sizeof(novaDataNascimento), stdin);
    printf("\n   Email               : ");
    fgets(novoEmail, sizeof(novoEmail), stdin);
    printf("\n   CPF                 : ");
    fgets(novoCpf, sizeof(novoCpf), stdin);

    confirmarAlteracao();

}


void excluirContacliente(void){
    limparTela();

    char cpf_busca[20];

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                        ~ ~ ~ Excluir Conta ~ ~ ~                         ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    printf("\n   Informe o seu CPF: ");
    fgets(cpf_busca, sizeof(cpf_busca), stdin);

    printf("\n==============================================================================\n");
    printf("\nSeus Dados Cadastrados: \n");
    printf("\nNome Completo: \n");
    printf("Data de Nascimento: \n");
    printf("Email: \n");
    printf("CPF: \n");
    printf("\n==============================================================================\n");

    confirmarExclusao("Cliente");

}

void exibirModuloClientes(void){
    char opcaoCliente;
    do{

        menuCliente();
        scanf(" %c", &opcaoCliente);
        getchar();
        if(opcaoCliente == '1'){
            telaCadastroCliente();
        }else if (opcaoCliente == '2'){
            listarDadosCliente();
        }else if(opcaoCliente == '3'){
            editarDadoscliente();
        }else if(opcaoCliente == '4'){
            excluirContacliente();
        }else if(opcaoCliente != '0'){
            printf("\nOpção inválida! Tente novamente.\n");
        }

        if (opcaoCliente != '0') {
            printf("\nPressione ENTER para continuar...");
            getchar(); 
            //Depois de selecionar uma opção mostra essa mensagem
        }

    }while(opcaoCliente != '0');
}
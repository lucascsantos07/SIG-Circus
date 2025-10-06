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

    Cliente cliente;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Cadastro de Cliente ~ ~ ~                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");
    
    cliente = coletarDadosCliente();

    exibirCliente(&cliente);

    confirmacaoCadastroCliente(&cliente);

}


void listarDadosCliente(void){
    limparTela();

    Cliente cliente;

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
        fscanf(arq_cliente, "%[^;]",cliente.cpf);
        fgetc(arq_cliente);
        fscanf(arq_cliente, "%[^;]",cliente.nome);
        fgetc(arq_cliente);
        fscanf(arq_cliente, "%[^;]",cliente.email);
        fgetc(arq_cliente);
        fscanf(arq_cliente, "%[^\n]",cliente.dataNascimento);
        fgetc(arq_cliente);
        if(strcmp(cliente.cpf,cpf_lido)==0){
            exibirCliente(&cliente);
            fclose(arq_cliente);
            return;
        }
    }
    fclose(arq_cliente);
    printf("\nCliente não encontrado\n");
}



void editarDadoscliente(void){
    limparTela();

    char cpf_busca[20];

    Cliente cliente;
    char novoNome[50], novaDataNascimento[20], novoEmail[100], novoCpf[20];

    FILE *arqCliente;
    FILE *arqClienteTemp;

    char opcao;

    int retorno, encontrado;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Editando seus Dados ~ ~ ~                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    printf("\n   Informe o seu CPF: ");
    fgets(cpf_busca, 20, stdin);
    cpf_busca[strcspn(cpf_busca, "\n")] = '\0';

    arqCliente= fopen("Clientes/clientes.csv","rt");
    arqClienteTemp = fopen("Clientes/clientesTemp.csv","wt");

    if (arqCliente == NULL){
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }

    if (arqClienteTemp == NULL){
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }

    encontrado = 0;

    while(fscanf(arqCliente, "%[^;]",cliente.cpf) == 1){
        fgetc(arqCliente);
        fscanf(arqCliente, "%[^;]",cliente.nome);
        fgetc(arqCliente);
        fscanf(arqCliente, "%[^;]",cliente.email);
        fgetc(arqCliente);
        fscanf(arqCliente, "%[^\n]",cliente.dataNascimento);
        fgetc(arqCliente);

        if(strcmp(cliente.cpf,cpf_busca)==0){

            encontrado = 1;

            printf("\nQual dado deseja alterar: \n");
            printf("\n1 - CPF");
            printf("\n2 - Nome");
            printf("\n3 - Email");
            printf("\n4 - Data de Nascimento\n");

            printf("\nDigite seu opção: ");
            scanf("%c", &opcao);
            getchar();

            switch (opcao){

                case '1':

                    printf("\n   CPF: ");
                    fgets(novoCpf, 20, stdin);
                    novoCpf[strcspn(novoCpf, "\n")] = '\0';

                    printf("\n==============================================================================\n");
                    printf("\nSeus Dados: \n");
                    printf("\nNome Completo: %s\n", cliente.nome);
                    printf("Data de Nascimento: %s\n", cliente.dataNascimento);
                    printf("Email: %s\n", cliente.email);
                    printf("CPF: %s\n", novoCpf);
                    printf("\n==============================================================================\n");

                    retorno = confirmarAlteracao();
                    
                    if(retorno == 1){
                        strcpy(cliente.cpf, novoCpf);
                        salvarCliente(arqClienteTemp, &cliente);

                    }else if(retorno == 0){
                        salvarCliente(arqClienteTemp, &cliente);
                    }

                    break;

                case '2':
        
                    printf("\n   Nome Completo: ");
                    fgets(novoNome, 50, stdin);
                    novoNome[strcspn(novoNome, "\n")] = '\0';

                    printf("\n==============================================================================\n");
                    printf("\nSeus Dados: \n");
                    printf("\nNome Completo: %s\n", novoNome);
                    printf("Data de Nascimento: %s\n", cliente.dataNascimento);
                    printf("Email: %s\n", cliente.email);
                    printf("CPF: %s\n", cliente.cpf);
                    printf("\n==============================================================================\n");

                    retorno = confirmarAlteracao();
                    
                    if(retorno == 1){
                        strcpy(cliente.nome, novoNome);
                        salvarCliente(arqClienteTemp, &cliente);
                    }else if(retorno == 0){
                        salvarCliente(arqClienteTemp, &cliente);
                    }
                    break;

                case '3':

                    printf("\n   Email: ");
                    fgets(novoEmail, 100, stdin);
                    novoEmail[strcspn(novoEmail, "\n")] = '\0';

                    printf("\n==============================================================================\n");
                    printf("\nSeus Dados: \n");
                    printf("\nNome Completo: %s\n", cliente.nome);
                    printf("Data de Nascimento: %s\n", cliente.dataNascimento);
                    printf("Email: %s\n", novoEmail);
                    printf("CPF: %s\n", cliente.cpf);
                    printf("\n==============================================================================\n");

                    retorno = confirmarAlteracao();
                    
                    if(retorno == 1){
                        strcpy(cliente.email, novoEmail);
                        salvarCliente(arqClienteTemp, &cliente);
                    }else if(retorno == 0){
                        salvarCliente(arqClienteTemp, &cliente);
                    }

                    break;

                case '4':

                    printf("\n   Data de Nascimento: ");
                    fgets(novaDataNascimento, 20, stdin);
                    novaDataNascimento[strcspn(novaDataNascimento, "\n")] = '\0';

                    printf("\n==============================================================================\n");
                    printf("\nSeus Dados: \n");
                    printf("\nNome Completo: %s\n", cliente.nome);
                    printf("Data de Nascimento: %s\n", novaDataNascimento);
                    printf("Email: %s\n", cliente.email);
                    printf("CPF: %s\n", cliente.cpf);
                    printf("\n==============================================================================\n");

                    retorno = confirmarAlteracao();
                    
                    if(retorno == 1){
                        strcpy(cliente.dataNascimento, novaDataNascimento);
                        salvarCliente(arqClienteTemp, &cliente);
                    }else if(retorno == 0){
                        salvarCliente(arqClienteTemp, &cliente);
                    }

                    break;

                default:

                    printf("Opção inválida");
                    break;

            }


        }else{
            salvarCliente(arqClienteTemp, &cliente);
        }
    }

    if(encontrado == 0){
        printf("\nCliente não encontrado\n");
    }

    fclose(arqCliente);
    fclose(arqClienteTemp);
    
    remove("Clientes/clientes.csv");
    rename("Clientes/clientesTemp.csv", "Clientes/clientes.csv");

}


void excluirContacliente(void){
    limparTela();

    char cpf_busca[20];
    Cliente cliente;
    int retorno, encontrado;
    FILE *arqCliente;
    FILE *arqClienteTemp;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                        ~ ~ ~ Excluir Conta ~ ~ ~                         ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    printf("\n   Informe o seu CPF: ");
    fgets(cpf_busca, 20, stdin);
    cpf_busca[strcspn(cpf_busca, "\n")] = '\0';

    arqCliente= fopen("Clientes/clientes.csv","rt");
    arqClienteTemp = fopen("Clientes/clientesTemp.csv","wt");

    if (arqCliente == NULL){
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }

    if (arqClienteTemp == NULL){
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }

    encontrado = 0;

    while(fscanf(arqCliente, "%[^;]",cliente.cpf) == 1){
        fgetc(arqCliente);
        fscanf(arqCliente, "%[^;]",cliente.nome);
        fgetc(arqCliente);
        fscanf(arqCliente, "%[^;]",cliente.email);
        fgetc(arqCliente);
        fscanf(arqCliente, "%[^\n]",cliente.dataNascimento);
        fgetc(arqCliente);

        if(strcmp(cliente.cpf,cpf_busca)!=0){
            fprintf(arqClienteTemp,"%s;",cliente.cpf);
            fprintf(arqClienteTemp,"%s;",cliente.nome);
            fprintf(arqClienteTemp,"%s;",cliente.email);
            fprintf(arqClienteTemp,"%s\n",cliente.dataNascimento);
        }else{

            encontrado = 1;

            printf("\n==============================================================================\n");
            printf("\nSeus Dados Cadastrados: \n");
            printf("\nNome Completo: %s\n", cliente.nome);
            printf("Data de Nascimento: %s\n", cliente.dataNascimento);
            printf("Email: %s\n", cliente.email);
            printf("CPF: %s\n", cliente.cpf);
            printf("\n==============================================================================\n");

            retorno = confirmarExclusao("Cliente");
            if(retorno == 0){
                fprintf(arqClienteTemp,"%s;",cliente.cpf);
                fprintf(arqClienteTemp,"%s;",cliente.nome);
                fprintf(arqClienteTemp,"%s;",cliente.email);
                fprintf(arqClienteTemp,"%s\n",cliente.dataNascimento);
            }
        }
    }

    if(encontrado == 0){
        printf("\nCliente não encontrado\n");
    }

    fclose(arqCliente);
    fclose(arqClienteTemp);
    
    remove("Clientes/clientes.csv");
    rename("Clientes/clientesTemp.csv", "Clientes/clientes.csv");

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

Cliente coletarDadosCliente(void){
    Cliente cliente;
    printf("\n   CPF: ");
    fgets(cliente.cpf, 20, stdin);
    cliente.cpf[strcspn(cliente.cpf, "\n")] = '\0';
    printf("\n   Nome Completo: ");
    fgets(cliente.nome, 50, stdin);
    cliente.nome[strcspn(cliente.nome, "\n")] = '\0';
    printf("\n   Email: ");
    fgets(cliente.email, 100, stdin);
    cliente.email[strcspn(cliente.email, "\n")] = '\0';
    printf("\n   Data de Nascimento: ");
    fgets(cliente.dataNascimento, 20, stdin);
    cliente.dataNascimento[strcspn(cliente.dataNascimento, "\n")] = '\0';
    return cliente;
}

void exibirCliente(Cliente *cliente){
    printf("\n==============================================================================\n");
    printf("\nSeus Dados Cadastrados: \n");
    printf("\nNome Completo: %s\n", cliente->nome);
    printf("Data de Nascimento: %s\n", cliente->dataNascimento);
    printf("Email: %s\n", cliente->email);
    printf("CPF: %s\n", cliente->cpf);
    printf("\n==============================================================================\n");
}

void salvarCliente(FILE *arqCliente, Cliente *cliente){

    fprintf(arqCliente,"%s;",cliente->cpf);
    fprintf(arqCliente,"%s;",cliente->nome);
    fprintf(arqCliente,"%s;",cliente->email);
    fprintf(arqCliente,"%s\n",cliente->dataNascimento);

}

void confirmacaoCadastroCliente(Cliente *cliente){
    char opcao;
    FILE *arqCliente;

    printf("\nDigite 1 para confirmar cadastro\n");
    printf("Digite 2 para cancelar cadastro\n");
    printf("\nOpção: ");
    scanf("%c",&opcao);
    getchar();

    if(opcao == '1'){
        arqCliente = fopen("Clientes/clientes.csv","at");

        if (arqCliente == NULL){
            printf("Erro na criacao do arquivo\n!");
            exit(1);
        }

        salvarCliente(arqCliente, cliente);
        fclose(arqCliente);

        printf("\n==============================================================================\n");
        printf("||                             Cadastro concluído                           ||\n");
        printf("==============================================================================\n");
    }else if(opcao == '2'){
        printf("\n==============================================================================\n");
        printf("||                             Cadastro cancelado                           ||\n");
        printf("==============================================================================\n");
    }else{
        printf("\nOpção inválida\n");
    }
    
}
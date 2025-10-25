#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "../Ingressos/ingressos.h"
#include "../Utilitarios/utilitarios.h"
#include "../Validacao/validacao.h"

#define True 1
#define False 0

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
    printf("||             5. Excluir conta Permanentemente                             ||\n");
    printf("||             0. Voltar Menu Principal                                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}



void telaCadastroCliente(void){
    limparTela();

    Cliente* cliente;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Cadastro de Cliente ~ ~ ~                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");
    
    cliente = coletarDadosCliente();

    exibirCliente(cliente);

    confirmacaoCadastroCliente(cliente);

}


void listarDadosCliente(void){
    limparTela();

    Cliente* cliente;

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

    cliente = (Cliente*) malloc(sizeof(Cliente));
    printf("\n  Informe o seu CPF: ");
    fgets(cpf_lido, 20, stdin);
    cpf_lido[strcspn(cpf_lido, "\n")] = '\0';

    arq_cliente= fopen("Clientes/clientes.dat","rb");

    if (arq_cliente == NULL){
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }

    while(fread(cliente, sizeof(Cliente),1,arq_cliente)){
        if((cliente->status)&&(strcmp(cpf_lido,cliente->cpf)==0)){
            exibirCliente(cliente);
            return;
        }
    }

    fclose(arq_cliente);
    free(cliente);
    printf("\n  Cliente não encontrado\n");

}


void editarDadoscliente(void){
    limparTela();

    char cpfBusca[20];
    Cliente* cliente;
    char novoNome[50], novaDataNascimento[20], novoEmail[100], novoCpf[20];
    FILE* arqCliente;
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

    cliente = (Cliente*) malloc(sizeof(Cliente)); 

    printf("\n  Informe o seu CPF: ");
    fgets(cpfBusca, 20, stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = '\0';

    arqCliente= fopen("Clientes/clientes.dat","r+b");

    if (arqCliente == NULL){
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }

    encontrado = False;

    while(fread(cliente, sizeof(Cliente),1,arqCliente)&&(!encontrado)){
        if((strcmp(cpfBusca,cliente->cpf)==0) && (cliente->status)){
            encontrado=True;
            exibirCliente(cliente);

            printf("\n  Qual dado deseja alterar: \n");
            printf("\n  1 - CPF");
            printf("\n  2 - Nome");
            printf("\n  3 - Email");
            printf("\n  4 - Data de Nascimento\n");

            printf("\n  Digite seu opção: ");
            scanf("%c", &opcao);
            getchar();

            switch (opcao){
                case '1':
                    printf("\n   CPF: ");
                    fgets(novoCpf, 20, stdin);
                    novoCpf[strcspn(novoCpf, "\n")] = '\0';

                    retorno = confirmarAlteracao();
                    if(retorno==1){
                        strcpy(cliente->cpf,novoCpf);
                        fseek(arqCliente,(-1)*sizeof(Cliente), SEEK_CUR);
                        fwrite(cliente,sizeof(Cliente),1,arqCliente);
                    }

                    break;
                
                case '2':
                    printf("\n   Nome: ");
                    fgets(novoNome, 20, stdin);
                    novoNome[strcspn(novoNome, "\n")] = '\0';

                    retorno = confirmarAlteracao();
                    if(retorno==1){
                        strcpy(cliente->nome,novoNome);
                        fseek(arqCliente,(-1)*sizeof(Cliente), SEEK_CUR);
                        fwrite(cliente,sizeof(Cliente),1,arqCliente);
                    }

                    break;
                
                case '3':
                    printf("\n   Email: ");
                    fgets(novoEmail, 20, stdin);
                    novoEmail[strcspn(novoEmail, "\n")] = '\0';

                    retorno = confirmarAlteracao();
                    if(retorno==1){
                        strcpy(cliente->email,novoEmail);
                        fseek(arqCliente,(-1)*sizeof(Cliente), SEEK_CUR);
                        fwrite(cliente,sizeof(Cliente),1,arqCliente);
                    }

                    break;

                case '4':
                    printf("\n   Data Nascimento: ");
                    fgets(novaDataNascimento, 20, stdin);
                    novaDataNascimento[strcspn(novaDataNascimento, "\n")] = '\0';

                    retorno = confirmarAlteracao();
                    if(retorno==1){
                        strcpy(cliente->dataNascimento,novaDataNascimento);
                        fseek(arqCliente,(-1)*sizeof(Cliente), SEEK_CUR);
                        fwrite(cliente,sizeof(Cliente),1,arqCliente);
                    }

                    break;
                
                default:
                    printf("\n  Opção Inválida\n");
                    break;
            }
        }
    }

    fclose(arqCliente);
    free(cliente);
    if(!encontrado){
        printf("\n  Cliente não encontrado\n");
    }

}


void excluirContacliente(void){
    limparTela();

    char cpfBusca[20];
    Cliente* cliente;
    int retorno, encontrado;
    FILE* arqCliente;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                        ~ ~ ~ Excluir Conta ~ ~ ~                         ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    cliente = (Cliente*) malloc(sizeof(Cliente)); 

    printf("\n  Informe o seu CPF: ");
    fgets(cpfBusca, 20, stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = '\0';

    arqCliente= fopen("Clientes/clientes.dat","r+b");

    if (arqCliente == NULL){
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }

    encontrado = False;

    while(fread(cliente, sizeof(Cliente),1,arqCliente)&&(!encontrado)){
        if((strcmp(cpfBusca,cliente->cpf)==0) && (cliente->status)){
            encontrado=True;
            exibirCliente(cliente);
            retorno = confirmarExclusao("Cliente");
            if(retorno==1){
                cliente->status = False;
                fseek(arqCliente,(-1)*sizeof(Cliente), SEEK_CUR);
                fwrite(cliente,sizeof(Cliente),1,arqCliente);
            }
        }
    }

    fclose(arqCliente);
    free(cliente);
    if(!encontrado){
        printf("\n  Cliente não encontrado\n");
    }

}

void excluirClientePermanente(void) {
    limparTela();

    char cpfBusca[20];
    Cliente* cliente;
    Ingressos* ingresso;
    int encontrado = False;
    int temIngresso = False;
    int retorno;

    FILE* arqCliente;
    FILE* arqTemp;
    FILE* arqIngressos;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                ~ ~ ~ Excluir Cliente Permanentemente ~ ~ ~               ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n");
    printf("==============================================================================\n");

    cliente = (Cliente*) malloc(sizeof(Cliente));
    ingresso = (Ingressos*) malloc(sizeof(Ingressos));
    if (cliente == NULL || ingresso == NULL) {
        printf("Erro de memória!\n");
        exit(1);
    }

    printf("\n  Informe o CPF do cliente: ");
    fgets(cpfBusca, 20, stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = '\0';

    arqIngressos = fopen("Ingressos/ingressos.dat", "rb");
    if (arqIngressos != NULL) {
        while (fread(ingresso, sizeof(Ingressos), 1, arqIngressos) == 1) {
            if (strcmp(cpfBusca, ingresso->cpfCliente) == 0 && ingresso->status == 1) {
                temIngresso = True;
                break;
            }
        }
        fclose(arqIngressos);
    }

    if (temIngresso) {
        printf("\n  Exclusão não permitida: o cliente possui ingressos comprados.\n");
        free(cliente);
        free(ingresso);
        return;
    }

    arqCliente = fopen("Clientes/clientes.dat", "rb");
    arqTemp = fopen("Clientes/temp.dat", "wb");

    if (arqCliente == NULL || arqTemp == NULL) {
        printf("Erro na abertura dos arquivos!\n");
        free(cliente);
        free(ingresso);
        exit(1);
    }

    while (fread(cliente, sizeof(Cliente), 1, arqCliente) == 1) {
        int deveGravar = True;
        if (strcmp(cliente->cpf, cpfBusca) == 0 && cliente->status == 1) {
            encontrado = True;
            exibirCliente(cliente);
            retorno = confirmarExclusao("Cliente");

            if (retorno == 1) {
                deveGravar = False;
            }
        }

        if(deveGravar){
            fwrite(cliente, sizeof(Cliente), 1, arqTemp);
        }
    }

    fclose(arqCliente);
    fclose(arqTemp);
    free(cliente);
    free(ingresso);

    if (encontrado) {
        remove("Clientes/clientes.dat");
        rename("Clientes/temp.dat", "Clientes/clientes.dat");
    } else {
        remove("Clientes/temp.dat");
        printf("\n  Cliente não encontrado.\n");
    }
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
        }else if(opcaoCliente == '5'){
            excluirClientePermanente();
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

Cliente* coletarDadosCliente(void){
    Cliente* cliente;
    
    cliente = (Cliente*) malloc(sizeof(Cliente));

    lerCPF(cliente->cpf, 20);

    lerNome(cliente->nome, 50);

    lerEmail(cliente->email,50);

    lerData(cliente->dataNascimento,20);

    cliente->status=True;

    return cliente;
}

void exibirCliente(Cliente *cliente){

    printf("\n==============================================================================\n");
    printf("\n  Seus Dados: \n");
    printf("\n  Nome Completo: %s\n", cliente->nome);
    printf("  Data de Nascimento: %s\n", cliente->dataNascimento);
    printf("  Email: %s\n", cliente->email);
    printf("  CPF: %s\n", cliente->cpf);
    printf("\n==============================================================================\n");
    
}

void salvarCliente(FILE *arqCliente, Cliente *cliente){

    fwrite(cliente, sizeof(Cliente), 1, arqCliente);

}

void confirmacaoCadastroCliente(Cliente *cliente){
    char opcao;
    FILE *arqCliente;

    printf("\n   <-------------  Digite 1 para confirmar cadastro --------------------->\n");
    printf("   <-------------  Digite 2 para cancelar cadastro  --------------------->\n");
    printf("\n  Opção: ");
    scanf("%c",&opcao);
    getchar();

    if(opcao == '1'){
        arqCliente = fopen("Clientes/clientes.dat","ab");

        if (arqCliente == NULL){
            printf("Erro na criacao do arquivo\n!");
            exit(1);
        }

        salvarCliente(arqCliente, cliente);
        fclose(arqCliente);
        free(cliente);

        printf("\n==============================================================================\n");
        printf("||                             Cadastro concluído                           ||\n");
        printf("==============================================================================\n");
    }else if(opcao == '2'){
        printf("\n==============================================================================\n");
        printf("||                             Cadastro cancelado                           ||\n");
        printf("==============================================================================\n");
        free(cliente);
    }else{
        printf("\n  Opção inválida\n");
    }
    
}
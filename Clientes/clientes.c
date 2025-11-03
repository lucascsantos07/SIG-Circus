#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "../Ingressos/ingressos.h"
#include "../Utilitarios/utilitarios.h"
#include "../Validacao/validacao.h"

#define True 1
#define False 0

char menuCliente(void) {
    limparTela();
    char opcaoCliente;
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
    scanf("%c", &opcaoCliente);
    limparBuffer();
    return opcaoCliente;
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
    char cpfLido[20];
    FILE *arq_cliente;
    int encontrado;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                        ~ ~ ~ Dados Pessoais ~ ~ ~                        ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    cliente = (Cliente*) malloc(sizeof(Cliente));
    
    lerCPF(cpfLido,20);
    
    arq_cliente= fopen("Clientes/clientes.dat","rb");

    if (arq_cliente == NULL){
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }

    encontrado=False;
    while(fread(cliente, sizeof(Cliente),1,arq_cliente)){
        if((cliente->status)&&(strcmp(cpfLido,cliente->cpf)==0)){
            encontrado=True;
            exibirCliente(cliente);
            break;
        }
    }

    fclose(arq_cliente);
    free(cliente);
    if(!encontrado){
        printf("\n   Cliente não encontrado\n");
    }
}


void editarDadoscliente(void){
    limparTela();

    char cpfBusca[20];
    Cliente* cliente;
    FILE* arqCliente;
    char opcao;
    int encontrado;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Editando seus Dados ~ ~ ~                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    cliente = (Cliente*) malloc(sizeof(Cliente)); 

    lerCPF(cpfBusca,20);

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

            opcao = escolherDado();

            alterarDado(opcao, cliente, arqCliente);

        }
    }

    fclose(arqCliente);
    free(cliente);
    if(!encontrado){
        printf("\n   Cliente não encontrado\n");
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

    lerCPF(cpfBusca, 20);

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
        printf("\n   Cliente não encontrado\n");
    }

}

void excluirClientePermanente(void) {
    limparTela();

    char cpfBusca[20];
    Cliente* cliente;
    int encontrado = False;
    int temIngresso;
    int excluiu = False;

    FILE* arqCliente;
    FILE* arqTemp;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                ~ ~ ~ Excluir Cliente Permanentemente ~ ~ ~               ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n");
    printf("==============================================================================\n");

    cliente = (Cliente*) malloc(sizeof(Cliente));

    lerCPF(cpfBusca,20);

    temIngresso = verificarTemIngresso(cpfBusca);

    if(temIngresso){
        return;
    }

    arqCliente = fopen("Clientes/clientes.dat", "rb");
    arqTemp = fopen("Clientes/temp.dat", "wb");

    if (arqCliente == NULL || arqTemp == NULL) {
        printf("Erro na abertura dos arquivos!\n");
        free(cliente);
        exit(1);
    }

    while (fread(cliente, sizeof(Cliente), 1, arqCliente) == 1) {
        if (strcmp(cliente->cpf, cpfBusca) == 0 && cliente->status == 1) {
            encontrado = True;
            exibirCliente(cliente);

            if (confirmarExclusao("Cliente")) {
                excluiu = True;
                continue;
            }

        }
        fwrite(cliente,sizeof(Cliente),1,arqTemp);
    }

    fclose(arqCliente);
    fclose(arqTemp);
     if (excluiu) {
        remove("Clientes/clientes.dat");
        rename("Clientes/temp.dat", "Clientes/clientes.dat");
    } else {
        remove("Clientes/temp.dat");

        if(!encontrado){
            printf("\n  Cliente não encontrado.\n");
        }
    }
}

void exibirModuloClientes(void){
    char opcaoCliente;
    do{

        opcaoCliente = menuCliente();

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
            printf("Erro na criacao do arquivo!\n");
            exit(1);
        }

        fwrite(cliente, sizeof(Cliente), 1, arqCliente);
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

void alterarDado(char opcao, Cliente* cliente, FILE* arqCliente){

    char novoNome[50], novaDataNascimento[20], novoEmail[50], novoCpf[20];
    int retorno;
    
    switch (opcao){
        case '1':

            lerCPF(novoCpf,20);
            retorno = confirmarAlteracao();
            if(retorno==1){
                strcpy(cliente->cpf,novoCpf);
            }

            break;
        
        case '2':

            lerNome(novoNome,50);
            retorno = confirmarAlteracao();
            if(retorno==1){
                strcpy(cliente->nome,novoNome);
            }

            break;
        
        case '3':

            lerEmail(novoEmail,50);
            retorno = confirmarAlteracao();
            if(retorno==1){
                strcpy(cliente->email,novoEmail);
            }

            break;

        case '4':

            lerData(novaDataNascimento,20); 
            retorno = confirmarAlteracao();
            if(retorno==1){
                strcpy(cliente->dataNascimento,novaDataNascimento);
            }

            break;

        case '5':

            printf("\n  Voltando para menu...\n");
            return;

        default:
            printf("\n  Opção Inválida\n");
            break;
    }

    if(retorno==1){
        fseek(arqCliente,(-1)*sizeof(Cliente), SEEK_CUR);
        fwrite(cliente,sizeof(Cliente),1,arqCliente);
    }

}

char escolherDado(void){
    char opcao;
    do {

        printf("\n  Qual dado deseja alterar: \n");
        printf("\n  1 - CPF");
        printf("\n  2 - Nome");
        printf("\n  3 - Email");
        printf("\n  4 - Data de Nascimento");
        printf("\n  5 - Cancelar\n");
        printf("\n  Digite sua opção: ");
        scanf(" %c", &opcao);

        limparBuffer();
        
        if (!isdigit(opcao) || opcao < '1' || opcao > '5') {
            printf("\n   Opção inválida! Digite um número de 1 a 5\n");
        }

    } while (!isdigit(opcao) || opcao < '1' || opcao > '5');
    return opcao;
}

int verificarTemIngresso(char cpf[]){

    Ingressos* ingresso;
    FILE* arqIngressos;
    int temIngresso = False;
    ingresso = (Ingressos*) malloc(sizeof(Ingressos));

    if (ingresso == NULL) {
        printf("Erro de memória!\n");
        exit(1);
    }

    arqIngressos = fopen("Ingressos/ingressos.dat", "rb");
    if (arqIngressos != NULL) {
        while (fread(ingresso, sizeof(Ingressos), 1, arqIngressos) == 1) {
            if (strcmp(cpf, ingresso->cpfCliente) == 0 && ingresso->status == 1) {
                temIngresso = True;
                break;
            }
        }
        fclose(arqIngressos);
    }

    if (temIngresso) {
        printf("\n  Exclusão não permitida: o cliente possui ingressos comprados.\n");
        free(ingresso);
        return 1;
    }else{
        return 0;
    }
}
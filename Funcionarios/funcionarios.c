#include <stdio.h>
#include <stdlib.h>
#include "funcionarios.h"
#include "../Utilitarios/utilitarios.h"


void menuFuncionarios(void) {
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
    printf("||               ~ ~ ~ Módulo de Gestão de Funcionários ~ ~ ~               ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||             1. Cadastrar funcionário                                     ||\n");
    printf("||             2. Listar dados do funcionário                               ||\n");
    printf("||             3. Editar dados do funcionário                               ||\n");
    printf("||             4. Excluir funcionário                                       ||\n");
    printf("||             0. Voltar ao menu principal                                  ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}


void telaCadastroFuncionario(void) {
    limparTela();
    char nome[50];
    char dataNascimento[20];
    char email[100];
    char cpf[20];
    char sexo;
    char endereco[100];
    char telefone[15];
    char salario[25];
    char cargo[30];
    char setor[30];

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                     ~ ~ ~ Cadastro de Funcionário ~ ~ ~                  ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");
    
    printf("\n   Nome Completo       : ");
    fgets(nome, sizeof(nome), stdin);
    printf("\n   Data de Nascimento  : ");
    fgets(dataNascimento, sizeof(dataNascimento), stdin);
    printf("\n   Email               : ");
    fgets(email, sizeof(email), stdin);
    printf("\n   CPF                 : ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("\n   Sexo (m/f)          : ");
    scanf(" %c", &sexo);
    getchar();
    printf("\n   Endereço            : ");
    fgets(endereco, sizeof(endereco), stdin);
    printf("\n   Telefone            : ");
    fgets(telefone, sizeof(telefone), stdin);
    printf("\n   Salário             : ");
    fgets(salario, sizeof(salario), stdin);
    printf("\n   Cargo               : ");
    fgets(cargo, sizeof(cargo), stdin);
    printf("\n   Setor               : ");
    fgets(setor, sizeof(setor), stdin);

    printf("\n================================================================================\n");
    printf("||                             Cadastro concluído                             ||\n");
    printf("================================================================================\n");

}


void listarDadosFuncionario(void) {
    limparTela();
    char cpf[20];

    FILE *fp;
    char linha[255];

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Dados do Funcionário ~ ~ ~                    ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");

    printf("\nInforme o CPF do funcionário: ");
    fgets(cpf, sizeof(cpf), stdin);

    fp = fopen("Funcionarios/funcionarios.txt","rt");
    if (fp == NULL){
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }
    while (fscanf(fp,"%[^\n]",linha) == 1) {
        
        printf("%s\n",linha);
        fgetc(fp);
    }
    fclose(fp);
}


void editarDadosFuncionario(void) {
    limparTela();
    char cpf_busca[20];
    char novoNome[50];
    char novaDataNascimento[20];
    char novoEmail[100];
    char novoCpf[20];
    char novoSexo;
    char novoEndereco[100];
    char novoTelefone[15];
    char novoSalario[25];
    char novoCargo[30];
    char novoSetor[30];

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                    ~ ~ ~ Editar Dados do Funcionário ~ ~ ~               ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");

    printf("\n   Informe o CPF do funcionário: ");
    fgets(cpf_busca, sizeof(cpf_busca), stdin);

    printf("\n   Nome Completo       : ");
    fgets(novoNome, sizeof(novoNome), stdin);
    printf("\n   Data de Nascimento  : ");
    fgets(novaDataNascimento, sizeof(novaDataNascimento), stdin);
    printf("\n   Email               : ");
    fgets(novoEmail, sizeof(novoEmail), stdin);
    printf("\n   CPF                 : ");
    fgets(novoCpf, sizeof(novoCpf), stdin);
    printf("\n   Sexo (m/f)          : ");
    scanf(" %c", &novoSexo);
    getchar();
    printf("\n   Endereço            : ");
    fgets(novoEndereco, sizeof(novoEndereco), stdin);
    printf("\n   Telefone            : ");
    fgets(novoTelefone, sizeof(novoTelefone), stdin);
    printf("\n   Salário             : ");
    fgets(novoSalario, sizeof(novoSalario), stdin);
    printf("\n   Cargo               : ");
    fgets(novoCargo, sizeof(novoCargo), stdin);
    printf("\n   Setor               : ");
    fgets(novoSetor, sizeof(novoSetor), stdin);

    confirmarAlteracao();
}


void excluirFuncionario(void) {
    limparTela();
    char cpf[20];

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                     ~ ~ ~ Excluir Funcionário ~ ~ ~                      ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");

    printf("\n   Informe o CPF do funcionário: ");
    fgets(cpf, sizeof(cpf), stdin);

    printf("\n==============================================================================\n");
    printf("\nNome Completo: \n");
    printf("Data de Nascimento: \n");
    printf("Email: \n");
    printf("CPF: \n");
    printf("Sexo(m/f): \n");
    printf("Endereço: \n");
    printf("Telefone: \n");
    printf("Salário: \n");
    printf("Cargo: \n");
    printf("Setor: \n");
    printf("\n==============================================================================\n");

    confirmarExclusao("Funcionário");
}


void exibirModuloFuncionarios(void){
    char opcaoFuncionario;
    do{

        menuFuncionarios();
        scanf(" %c", &opcaoFuncionario);
        getchar();
        if(opcaoFuncionario == '1'){
            telaCadastroFuncionario();
        }else if (opcaoFuncionario == '2'){
            listarDadosFuncionario();
        }else if(opcaoFuncionario == '3'){
            editarDadosFuncionario();
        }else if(opcaoFuncionario == '4'){
            excluirFuncionario();
        }else if(opcaoFuncionario != '0'){
            printf("\nOpção inválida! Tente novamente.\n");
        }

        if (opcaoFuncionario != '0') {
            printf("\nPressione ENTER para continuar...");
            getchar();   
        }

    }while(opcaoFuncionario != '0');
}
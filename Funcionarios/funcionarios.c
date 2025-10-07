#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    Funcionarios fun;

    char linha[1000];

    FILE *arqFuncionarios;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                     ~ ~ ~ Cadastro de Funcionário ~ ~ ~                  ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");
    
    printf("\n   Nome Completo       : ");
    fgets(fun.nome, 50, stdin);
    fun.nome[strcspn(fun.nome, "\n")] = '\0';
    printf("\n   Data de Nascimento  : ");
    fgets(fun.dataNascimento, 20, stdin);
    fun.dataNascimento[strcspn(fun.dataNascimento, "\n")] = '\0';
    printf("\n   Email               : ");
    fgets(fun.email, 100, stdin);
    fun.email[strcspn(fun.email, "\n")] = '\0';
    printf("\n   CPF                 : ");
    fgets(fun.cpf, 20, stdin);
    fun.cpf[strcspn(fun.cpf, "\n")] = '\0';
    printf("\n   Sexo (m/f)          : ");
    fgets(fun.sexo, 12, stdin);
    fun.sexo[strcspn(fun.sexo, "\n")] = '\0';
    printf("\n   Endereço            : ");
    fgets(fun.endereco, 100, stdin);
    fun.endereco[strcspn(fun.endereco, "\n")] = '\0';
    printf("\n   Telefone            : ");
    fgets(fun.telefone, 15, stdin);
    fun.telefone[strcspn(fun.telefone, "\n")] = '\0';
    printf("\n   Salário             : ");
    fgets(fun.salario, 10, stdin);
    fun.salario[strcspn(fun.salario, "\n")] = '\0';
    printf("\n   Cargo               : ");
    fgets(fun.cargo, 30, stdin);
    fun.cargo[strcspn(fun.cargo, "\n")] = '\0';
    printf("\n   Setor               : ");
    fgets(fun.setor, 30, stdin);
    fun.setor[strcspn(fun.setor, "\n")] = '\0';

    arqFuncionarios = fopen("Funcionarios/funcionarios.csv", "at");

    if (arqFuncionarios == NULL) {
        printf("FAIL");
        exit(1);
    }

    fprintf(arqFuncionarios, "%s;", fun.cpf);
    fprintf(arqFuncionarios, "%s;", fun.nome);
    fprintf(arqFuncionarios, "%s;", fun.dataNascimento);
    fprintf(arqFuncionarios, "%s;", fun.email);
    fprintf(arqFuncionarios, "%s;", fun.sexo);
    fprintf(arqFuncionarios, "%s;", fun.endereco);
    fprintf(arqFuncionarios, "%s;", fun.telefone);
    fprintf(arqFuncionarios, "%s;", fun.salario);
    fprintf(arqFuncionarios, "%s;", fun.cargo);
    fprintf(arqFuncionarios, "%s\n", fun.setor);

    fclose(arqFuncionarios);

    printf("\n================================================================================\n");
    printf("||                             Cadastro concluído                             ||\n");
    printf("================================================================================\n");

}


void listarDadosFuncionario(void) {
    limparTela();

    char cpf_input[12];
    char linha[1000];
    Funcionarios fun;

    FILE *fp_funcionario;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Dados do Funcionário ~ ~ ~                    ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");

    printf("\nInforme o CPF do funcionário: ");
    fgets(cpf_input, sizeof(cpf_input), stdin);
    cpf_input[strcspn(cpf_input, "\n")] = 0;

    fp_funcionario = fopen("Funcionarios/funcionarios.csv", "rt");
    if (fp_funcionario == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    while (fgets(linha, sizeof(linha), fp_funcionario)) {
        sscanf(linha, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;\n]",
               fun.cpf, fun.nome, fun.dataNascimento, fun.email, fun.sexo, fun.endereco, fun.telefone, fun.salario, fun.cargo, fun.setor);

        if (strcmp(cpf_input, fun.cpf) == 0) {
            printf("\n==============================================================================\n");
            printf("\nNome Completo: %s \n", fun.nome);
            printf("Data de Nascimento: %s \n", fun.dataNascimento);
            printf("Email: %s \n", fun.email);
            printf("CPF: %s \n"), fun.cpf;
            printf("Sexo(m/f): %s \n", fun.sexo);
            printf("Endereço: %s \n", fun.endereco);
            printf("Telefone: %s \n", fun.telefone);
            printf("Salário: %s \n", fun.salario);
            printf("Cargo: %s \n", fun.cargo);
            printf("Setor: %s \n", fun.setor);
            printf("\n==============================================================================\n");
        }
    }

    fclose(fp_funcionario);
}



void editarDadosFuncionario(void) {
    limparTela();
    Funcionarios fun;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                    ~ ~ ~ Editar Dados do Funcionário ~ ~ ~               ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");

    printf("\n   Informe o CPF do funcionário: ");
    fgets(fun.cpf_busca, sizeof(fun.cpf_busca), stdin);

    printf("\n   Nome Completo       : ");
    fgets(fun.nome, sizeof(fun.nome), stdin);
    printf("\n   Data de Nascimento  : ");
    fgets(fun.dataNascimento, sizeof(fun.dataNascimento), stdin);
    printf("\n   Email               : ");
    fgets(fun.email, sizeof(fun.email), stdin);
    printf("\n   CPF                 : ");
    fgets(fun.cpf, sizeof(fun.cpf), stdin);
    printf("\n   Sexo (m/f)          : ");
    fgets(fun.sexo, sizeof(fun.sexo), stdin);
    printf("\n   Endereço            : ");
    fgets(fun.endereco, sizeof(fun.endereco), stdin);
    printf("\n   Telefone            : ");
    fgets(fun.telefone, sizeof(fun.telefone), stdin);
    printf("\n   Salário             : ");
    fgets(fun.salario, sizeof(fun.salario), stdin);
    printf("\n   Cargo               : ");
    fgets(fun.cargo, sizeof(fun.cargo), stdin);
    printf("\n   Setor               : ");
    fgets(fun.setor, sizeof(fun.setor), stdin);

    confirmarAlteracao();
}


void excluirFuncionario(void) {
    limparTela();
    Funcionarios fun;
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
    fgets(fun.cpf, sizeof(fun.cpf), stdin);

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
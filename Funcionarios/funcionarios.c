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
    char sexo[12];
    char endereco[100];
    char telefone[15];
    char salario[25];
    char cargo[30];
    char setor[30];

    FILE *fp_funcionario;

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
    nome[strcspn(nome, "\n")] = 0;
    printf("\n   Data de Nascimento  : ");
    fgets(dataNascimento, sizeof(dataNascimento), stdin);
    dataNascimento[strcspn(dataNascimento, "\n")] = 0;
    printf("\n   Email               : ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0;
    printf("\n   CPF                 : ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;
    printf("\n   Sexo (m/f)          : ");
    fgets(sexo, sizeof(sexo), stdin);
    sexo[strcspn(sexo, "\n")] = 0;
    printf("\n   Endereço            : ");
    fgets(endereco, sizeof(endereco), stdin);
    endereco[strcspn(endereco, "\n")] = 0;
    printf("\n   Telefone            : ");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strcspn(telefone, "\n")] = 0;
    printf("\n   Salário             : ");
    fgets(salario, sizeof(salario), stdin);
    salario[strcspn(salario, "\n")] = 0;
    printf("\n   Cargo               : ");
    fgets(cargo, sizeof(cargo), stdin);
    cargo[strcspn(cargo, "\n")] = 0;
    printf("\n   Setor               : ");
    fgets(setor, sizeof(setor), stdin);
    setor[strcspn(setor, "\n")] = 0;

    fp_funcionario = fopen("Funcionarios/funcionarios.csv", "at");

    if (fp_funcionario == NULL) {
        printf("FAIL");
        exit(1);
    }

    if (ftell(fp_funcionario) == 0) {
        fprintf(fp_funcionario, "%s;", cpf);
    } else {
        fprintf(fp_funcionario, "\n%s;", cpf);
    }

    fprintf(fp_funcionario, "%s;", nome);
    fprintf(fp_funcionario, "%s;", dataNascimento);
    fprintf(fp_funcionario, "%s;", email);
    fprintf(fp_funcionario, "%s;", sexo);
    fprintf(fp_funcionario, "%s;", endereco);
    fprintf(fp_funcionario, "%s;", telefone);
    fprintf(fp_funcionario, "%s;", salario);
    fprintf(fp_funcionario, "%s;", cargo);
    fprintf(fp_funcionario, "%s;", setor);

    fclose(fp_funcionario);

    printf("\n================================================================================\n");
    printf("||                             Cadastro concluído                             ||\n");
    printf("================================================================================\n");

}


void listarDadosFuncionario(void) {
    limparTela();
    char cpf_input[20];
    char cpf_info[20];
    char nome[50];
    char dataNascimento[20];
    char email[100];
    char sexo[12];
    char endereco[100];
    char telefone[15];
    char salario[25];
    char cargo[30];
    char setor[30];
    char linha[1000];

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

    while (fgets(linha, sizeof(linha), fp_funcionario)) {
    sscanf(linha, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;\n]",
           cpf_info, nome, dataNascimento, email, sexo, endereco, telefone, salario, cargo, setor);


        if (strcmp(cpf_input, cpf_info) == 0) {

            printf("\n==============================================================================\n");
            printf("\nNome Completo: %s \n", nome);
            printf("Data de Nascimento: %s \n", dataNascimento);
            printf("Email: %s \n", email);
            printf("CPF: %s \n", cpf_info);
            printf("Sexo(m/f): %s \n", sexo);
            printf("Endereço: %s \n", endereco);
            printf("Telefone: %s \n", telefone);
            printf("Salário: %s \n", salario);
            printf("Cargo: %s \n", cargo);
            printf("Setor: %s \n", setor);
            printf("\n==============================================================================\n");

        }
    }
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
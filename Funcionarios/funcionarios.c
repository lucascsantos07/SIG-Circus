#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionarios.h"
#include "../Utilitarios/utilitarios.h"
#include "../Validacao/validacao.h"

#define True 1
#define False 0


char menuFuncionarios(void) {
    limparTela();
    char opcaoFunc;
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
    printf("||             4. Deletar Funcionário Permanentemente                       ||\n");
    printf("||             5. Excluir funcionário                                       ||\n");
    printf("||             0. Voltar ao menu principal                                  ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
    scanf("%c", &opcaoFunc);
    limparBuffer();
    return opcaoFunc;
}


void telaCadastroFuncionario(void) {
    limparTela();

    Funcionarios* funcionarios;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                     ~ ~ ~ Cadastro de Funcionário ~ ~ ~                  ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");
    
    funcionarios = ColetarDadosFuncionario();
    ExibirFuncionario(funcionarios);
    ConfirmarCadastroFuncionario(funcionarios);

    
}


void listarDadosFuncionario(void) {
    limparTela();

    Funcionarios* funcionario;
    char cpfLido[20];

    FILE *arqFuncionarios;
    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Dados do Funcionário ~ ~ ~                    ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");

    funcionario = (Funcionarios*)malloc(sizeof(Funcionarios));

    lerCPF(cpfLido,20);

    arqFuncionarios = fopen("Funcionarios/funcionarios.dat", "rb");
    if (arqFuncionarios == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    while (fread(funcionario, sizeof(Funcionarios), 1, arqFuncionarios)) {
        if (strcmp(funcionario->cpf, cpfLido) == 0 && funcionario->status) {
            ExibirFuncionario(funcionario);
            return;
        }
    }

    fclose(arqFuncionarios);
    free(funcionario);
    printf("\n   Funcionario não encontrado!\n");
}



void editarDadosFuncionario(void) {
    limparTela();
    Funcionarios* funcionario;
    char cpfBusca[20];
    FILE* arqFuncionarios;
    int opcao, encontrado;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                    ~ ~ ~ Editar Dados do Funcionário ~ ~ ~               ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");

    funcionario = (Funcionarios*)malloc(sizeof(Funcionarios));

    lerCPF(cpfBusca,20);

    arqFuncionarios = fopen("Funcionarios/funcionarios.dat", "r+b");

    if (arqFuncionarios == NULL) {
        printf("Erro ao abrir arquivo.");
        exit(1);
    }

    encontrado = False;

    while (fread(funcionario, sizeof(Funcionarios), 1, arqFuncionarios) && (encontrado==0)) {
        if (strcmp(cpfBusca, funcionario->cpf) == 0 && funcionario->status) {

            encontrado = True;
            ExibirFuncionario(funcionario);

            opcao = escolherDadoFunc();

            alterarDadoFunc(opcao, funcionario, arqFuncionarios);
            
        }
    }

    fclose(arqFuncionarios);
    free(funcionario);
    if(!encontrado){
        printf("\n   Funcionario não encontrado\n");
    }
}


void excluirFuncionario(void) {
    limparTela();
    FILE* arqFuncionarios;
    Funcionarios* funcionario;
    int retorno, encontrado;
    char cpfBusca[20];

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                     ~ ~ ~ Excluir Funcionário ~ ~ ~                      ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    funcionario = (Funcionarios*)malloc(sizeof(Funcionarios));

    lerCPF(cpfBusca,20);

    arqFuncionarios = fopen("Funcionarios/funcionarios.dat", "r+b");

    if (arqFuncionarios == NULL) {
        printf("ERROR!");
        exit(1);
    }

    encontrado = False;

    while (fread(funcionario, sizeof(Funcionarios), 1, arqFuncionarios) && (!encontrado)) {
        if (strcmp(funcionario->cpf, cpfBusca) == 0 && funcionario->status) {
            encontrado = True;
            ExibirFuncionario(funcionario);
            retorno = confirmarExclusao("Funcionário");

            if (retorno == 1) {
                funcionario->status = False;
                fseek(arqFuncionarios,(-1)*sizeof(Funcionarios), SEEK_CUR);
                fwrite(funcionario,sizeof(Funcionarios),1,arqFuncionarios);
            }
        }
    }

    fclose(arqFuncionarios);
    free(funcionario);
    if(!encontrado){
        printf("\n  Funcionário não encontrado\n");
    }

}


void exibirModuloFuncionarios(void){
    char opcaoFunc;
    do{

        opcaoFunc = menuFuncionarios();
        
        if(opcaoFunc == '1'){
            telaCadastroFuncionario();
        }else if (opcaoFunc == '2'){
            listarDadosFuncionario();
        }else if(opcaoFunc == '3'){
            editarDadosFuncionario();
        }else if(opcaoFunc == '4'){
            deletarFuncionarioPermanentemente();
        }else if(opcaoFunc == '5'){
            excluirFuncionario();
        }else if(opcaoFunc != '0'){
            printf("\nOpção inválida! Tente novamente.\n");
        }

        if (opcaoFunc != '0') {
            printf("\nPressione ENTER para continuar...");
            getchar();   
        }

    }while(opcaoFunc != '0');
}

Funcionarios* ColetarDadosFuncionario(void) {
    Funcionarios* funcionarios;

    funcionarios = (Funcionarios*)malloc(sizeof(Funcionarios));

    lerNome(funcionarios->nome, 50);
    lerData(funcionarios->dataNascimento, 20);
    lerEmail(funcionarios->email, 50);
    lerCPF(funcionarios->cpf, 20);
    lerSexo(funcionarios->sexo, 12);
    lerEndereco(funcionarios->endereco, 100);
    lerTelefone(funcionarios->telefone, 15);
    lerSalario(funcionarios->salario);
    lerCargo(funcionarios->cargo, 30);
    lerSetor(funcionarios->setor, 30);
    funcionarios->status = True;
    return funcionarios;

}   

void ConfirmarCadastroFuncionario(Funcionarios* funcionario) {
    char opcao;
    FILE* arqFuncionarios;
    
    printf("\n   <-------------  Digite 1 para confirmar cadastro --------------------->\n");
    printf("   <-------------  Digite 2 para cancelar cadastro  --------------------->\n");
    printf("\n  Opção: ");
    scanf("%c",&opcao);
    getchar();

    if(opcao == '1'){
        arqFuncionarios = fopen("Funcionarios/funcionarios.dat","ab");

        if (arqFuncionarios == NULL){
            printf("Erro na criação do arquivo!\n");
            exit(1);
        }

        fwrite(funcionario,sizeof(Funcionarios),1,arqFuncionarios);
        fclose(arqFuncionarios);
        free(funcionario);

        printf("\n==============================================================================\n");
        printf("||                             Cadastro concluído                           ||\n");
        printf("==============================================================================\n");
    }else if(opcao == '2'){
        printf("\n==============================================================================\n");
        printf("||                             Cadastro cancelado                           ||\n");
        printf("==============================================================================\n");
        free(funcionario);
    }else{
        printf("\n  Opção inválida\n");
    }
}

void ExibirFuncionario(Funcionarios* funcionario) {
    printf("\n==============================================================================\n");
    printf("\n  Seus Dados: \n");
    printf("  Nome: %s\n", funcionario->nome);
    printf("  Data de Nascimento: %s\n", funcionario->dataNascimento);
    printf("  Email: %s\n", funcionario->email);
    printf("  CPF: %s\n", funcionario->cpf);
    printf("  Sexo: %s\n", funcionario->sexo);
    printf("  Endereco: %s\n", funcionario->endereco);
    printf("  Telefone: %s\n", funcionario->telefone);
    printf("  Salário: %s\n", funcionario->salario);
    printf("  Cargo: %s\n", funcionario->cargo);
    printf("  Setor: %s\n", funcionario->setor);
    printf("\n==============================================================================\n");
}
void deletarFuncionarioPermanentemente(void){
    limparTela();
    FILE* arqFuncionarios;
    FILE* arqTemp;
    Funcionarios* funcionario;
    char confirma;
    int encontrado;
    char cpfBusca[20];

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||               ~ ~ ~ Deletar Funcionário Permanentemente ~ ~ ~           ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");

    funcionario = (Funcionarios*)malloc(sizeof(Funcionarios));

    lerCPF(cpfBusca,20);

    arqFuncionarios = fopen("Funcionarios/funcionarios.dat", "rb");
    arqTemp = fopen("Funcionarios/temp.dat", "wb");

    if (arqFuncionarios == NULL || arqTemp == NULL) {
        printf("\nERROR!\n");
        exit(1);
    }

    encontrado = 0;

    while (fread(funcionario, sizeof(Funcionarios), 1, arqFuncionarios)) {
        if (strcmp(funcionario->cpf, cpfBusca) == 0 && funcionario->status == 1) {
            encontrado = True;
            ExibirFuncionario(funcionario);
            confirma = confirmarExclusao("Funcionário");
            if (confirma == False) {
                fwrite(funcionario, sizeof(Funcionarios), 1, arqTemp);
            }
        } else {
            fwrite(funcionario, sizeof(Funcionarios), 1, arqTemp);
        }
    }

    fclose(arqFuncionarios);
    fclose(arqTemp);
    remove("Funcionarios/funcionarios.dat");
    rename("Funcionarios/temp.dat", "Funcionarios/funcionarios.dat");
    free(funcionario);
    if (!encontrado){
        printf("\n   Funcionário nao encontrado\n");
    }
    return;
}

int escolherDadoFunc(void) {
    int opcao;
    int leituraValida;

    do {
        printf("\n  Qual dado deseja alterar: \n");
        printf("\n  1 - Nome");
        printf("\n  2 - Data de Nascimento");
        printf("\n  3 - Email");
        printf("\n  4 - CPF");
        printf("\n  5 - Sexo");
        printf("\n  6 - Endereço");
        printf("\n  7 - Telefone");
        printf("\n  8 - Salário");
        printf("\n  9 - Cargo");
        printf("\n  10 - Setor");
        printf("\n  11 - Cancelar\n");

        printf("\n  Digite sua opção: ");

        leituraValida = scanf("%d", &opcao);

        limparBuffer();

        if (leituraValida != 1 || opcao < 1 || opcao > 11) {
            printf("\n   Opção inválida! Digite um número de 1 a 11.\n");
        }

    } while (leituraValida != 1 || opcao < 1 || opcao > 11);

    return opcao;
}

void alterarDadoFunc(int opcao, Funcionarios* funcionario, FILE* arqFuncionarios){

    char novoCpf[20];
    char novaDataNascimento[20];
    char novoEmail[50];
    char novoNome[50];
    char novoSexo[12];
    char novoEndereco[100];
    char novoTelefone[15];
    char novoSalario[20];
    char novoCargo[30];
    char novoSetor[30];
    int retorno;

    switch (opcao) {
        case 1:

            lerNome(novoNome, 50);

            retorno = confirmarAlteracao();

            if (retorno) {
                strcpy(funcionario->nome, novoNome);
            }

            break;
        case 2:
            
            lerData(novaDataNascimento, 20);

            retorno = confirmarAlteracao();

            if (retorno) {
                strcpy(funcionario->dataNascimento, novaDataNascimento);
            }

            break;
        case 4:
            
            lerCPF(novoCpf, 20);

            retorno = confirmarAlteracao();

            if (retorno) {
                strcpy(funcionario->cpf, novoCpf);
            }

            break;
        case 3:

            lerEmail(novoEmail, 50);

            retorno = confirmarAlteracao();

            if (retorno) {
                strcpy(funcionario->email, novoEmail);
            }

            break;
        case 5:
            
            lerSexo(novoSexo, 12);

            retorno = confirmarAlteracao();

            if (retorno) {
                strcpy(funcionario->sexo, novoSexo);
            }

            break;
        case 6:
            
            lerEndereco(novoEndereco, 100);

            retorno = confirmarAlteracao();

            if (retorno) {
                strcpy(funcionario->endereco, novoEndereco);
            }

            break;
        case 7:
            
            lerTelefone(novoTelefone, 15);

            retorno = confirmarAlteracao();

            if (retorno) {
                strcpy(funcionario->telefone, novoTelefone);
            }

            break;
        case 8:
            
            lerSalario(novoSalario);

            retorno = confirmarAlteracao();

            if (retorno) {
                strcpy(funcionario->salario, novoSalario);
            }

            break;
        case 9:

            lerCargo(novoCargo, 30);

            retorno = confirmarAlteracao();

            if (retorno) {
                strcpy(funcionario->cargo, novoCargo);
            }

            break;
        case 10:
            
            lerSetor(novoSetor, 30);

            retorno = confirmarAlteracao();

            if (retorno) {
                strcpy(funcionario->setor, novoSetor);
            }

            break;
        default:
            printf("Opcao Inválida!\n");
            break;
    }

    if(retorno){
        fseek(arqFuncionarios, (-1)*sizeof(Funcionarios), SEEK_CUR);
        fwrite(funcionario, sizeof(Funcionarios), 1, arqFuncionarios);
    }
}

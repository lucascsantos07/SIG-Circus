#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionarios.h"
#include "../Utilitarios/utilitarios.h"
#include "../Validacao/validacao.h"

#define True 1
#define False 0


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
    printf("||             4. Deletar Funcionário Permanentemente                       ||\n");
    printf("||             5. Excluir funcionário                                       ||\n");
    printf("||             0. Voltar ao menu principal                                  ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}


void telaCadastroFuncionario(void) {
    limparTela();

    Funcionarios* funcionarios;

    FILE *arqFuncionarios;

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
    char cpfInput[20];

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

    printf("\nInforme o CPF do funcionário: ");
    fgets(cpfInput, sizeof(cpfInput), stdin);
    cpfInput[strcspn(cpfInput, "\n")] = 0;

    arqFuncionarios = fopen("Funcionarios/funcionarios.dat", "rb");
    if (arqFuncionarios == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    while (fread(funcionario, sizeof(Funcionarios), 1, arqFuncionarios)) {
        if (strcmp(funcionario->cpf, cpfInput) == 0 && funcionario->status) {
            ExibirFuncionario(funcionario);
            return;
        }
    }

    fclose(arqFuncionarios);
    free(funcionario);
    printf("Funcionario nao encontrado...");
}



void editarDadosFuncionario(void) {
    limparTela();
    Funcionarios* funcionario;
    char nome_busca[20];
    char novoCpf[20];
    char novoDataNascimento[20];
    char novoEmail[100];
    char novoNome[50];
    char novoSexo[12];
    char novoEndereco[100];
    char novoTelefone[15];
    char novoSalario[20];
    char novoCargo[30];
    char novoSetor[30];
    FILE* arqFuncionarios;
    int opcao, retorno, encontrado;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                    ~ ~ ~ Editar Dados do Funcionário ~ ~ ~               ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");

    funcionario = (Funcionarios*)malloc(sizeof(Funcionarios));

    printf("\n   Informe o Nome do funcionário: ");
    fgets(nome_busca, sizeof(nome_busca), stdin);
    nome_busca[strcspn(nome_busca, "\n")] = 0;

    arqFuncionarios = fopen("Funcionarios/funcionarios.dat", "r+b");

    if (arqFuncionarios == NULL) {
        printf("Erro ao abrir arquivo.");
        exit(1);
    }

    encontrado = False;

    while (fread(funcionario, sizeof(Funcionarios), 1, arqFuncionarios) && (encontrado==0)) {
        if (strcmp(nome_busca, funcionario->nome) == 0 && funcionario->status) {
            encontrado = True;
            ExibirFuncionario(funcionario);

            printf("\n  Qual dado deseja alterar: \n");
            printf("\n  1 - Nome");
            printf("\n  2 - Data de Nascimento\n");
            printf("\n  3 - Email");
            printf("\n  4 - CPF");
            printf("\n  5 - Sexo");
            printf("\n  6 - Endereço");
            printf("\n  7 - Telefone");
            printf("\n  8 - Salário");
            printf("\n  9 - Cargo");
            printf("\n  10 - Setor\n");

            printf("\n  Digite seu opção: ");
            scanf(" %d", &opcao);
            getchar();

            switch (opcao) {
                case 1:
                    printf("Novo Nome: ");
                    fgets(novoNome, 50, stdin);
                    novoNome[strcspn(novoNome, "\n")] = '\0';

                    retorno = confirmarAlteracao();

                    if (retorno) {
                        strcpy(funcionario->nome, novoNome);
                        fseek(arqFuncionarios, (-1)*sizeof(Funcionarios), SEEK_CUR);
                        fwrite(funcionario, sizeof(Funcionarios), 1, arqFuncionarios);
                    }

                    break;
                case 2:
                    printf("Nova Data de Nascimento: ");
                    fgets(novoDataNascimento, 20, stdin);
                    novoDataNascimento[strcspn(novoDataNascimento, "\n")] = '\0';

                    retorno = confirmarAlteracao();

                    if (retorno) {
                        strcpy(funcionario->dataNascimento, novoDataNascimento);
                        fseek(arqFuncionarios, (-1)*sizeof(Funcionarios), SEEK_CUR);
                        fwrite(funcionario, sizeof(Funcionarios), 1, arqFuncionarios);
                    }

                    break;
                case 4:
                    printf("Novo CPF: ");
                    fgets(novoCpf, 20, stdin);
                    novoCpf[strcspn(novoCpf, "\n")] = '\0';

                    retorno = confirmarAlteracao();

                    if (retorno) {
                        strcpy(funcionario->cpf, novoCpf);
                        fseek(arqFuncionarios, (-1)*sizeof(Funcionarios), SEEK_CUR);
                        fwrite(funcionario, sizeof(Funcionarios), 1, arqFuncionarios);
                    }

                    break;
                case 3:
                    printf("Novo Email: ");
                    fgets(novoEmail, 100, stdin);
                    novoEmail[strcspn(novoEmail, "\n")] = '\0';

                    retorno = confirmarAlteracao();

                    if (retorno) {
                        strcpy(funcionario->email, novoEmail);
                        fseek(arqFuncionarios, (-1)*sizeof(Funcionarios), SEEK_CUR);
                        fwrite(funcionario, sizeof(Funcionarios), 1, arqFuncionarios);
                    }

                    break;
                case 5:
                    printf("Novo Sexo: ");
                    fgets(novoSexo, 12, stdin);
                    novoSexo[strcspn(novoSexo, "\n")] = '\0';

                    retorno = confirmarAlteracao();

                    if (retorno) {
                        strcpy(funcionario->sexo, novoSexo);
                        fseek(arqFuncionarios, (-1)*sizeof(Funcionarios), SEEK_CUR);
                        fwrite(funcionario, sizeof(Funcionarios), 1, arqFuncionarios);
                    }

                    break;
                case 6:
                    printf("Novo Endereco: ");
                    fgets(novoEndereco, 100, stdin);
                    novoEndereco[strcspn(novoEndereco, "\n")] = '\0';

                    retorno = confirmarAlteracao();

                    if (retorno) {
                        strcpy(funcionario->endereco, novoEndereco);
                        fseek(arqFuncionarios, (-1)*sizeof(Funcionarios), SEEK_CUR);
                        fwrite(funcionario, sizeof(Funcionarios), 1, arqFuncionarios);
                    }

                    break;
                case 7:
                    printf("Novo Telefone: ");
                    fgets(novoTelefone, 15, stdin);
                    novoTelefone[strcspn(novoTelefone, "\n")] = '\0';

                    retorno = confirmarAlteracao();

                    if (retorno) {
                        strcpy(funcionario->telefone, novoTelefone);
                        fseek(arqFuncionarios, (-1)*sizeof(Funcionarios), SEEK_CUR);
                        fwrite(funcionario, sizeof(Funcionarios), 1, arqFuncionarios);
                    }

                    break;
                case 8:
                    printf("Novo Salario: ");
                    scanf(" %s", novoSalario);
                    getchar();

                    retorno = confirmarAlteracao();

                    if (retorno) {
                        strcpy(funcionario->salario, novoSalario);
                        fseek(arqFuncionarios, (-1)*sizeof(Funcionarios), SEEK_CUR);
                        fwrite(funcionario, sizeof(Funcionarios), 1, arqFuncionarios);
                    }

                    break;
                case 9:
                    printf("Novo Cargo: ");
                    fgets(novoCargo, 30, stdin);
                    novoCargo[strcspn(novoCargo, "\n")] = '\0';

                    retorno = confirmarAlteracao();

                    if (retorno) {
                        strcpy(funcionario->cargo, novoCargo);
                        fseek(arqFuncionarios, (-1)*sizeof(Funcionarios), SEEK_CUR);
                        fwrite(funcionario, sizeof(Funcionarios), 1, arqFuncionarios);
                    }

                    break;
                case 10:
                    printf("Novo Setor: ");
                    fgets(novoSetor, 30, stdin);
                    novoSetor[strcspn(novoSetor, "\n")] = '\0';

                    retorno = confirmarAlteracao();

                    if (retorno) {
                        strcpy(funcionario->setor, novoSetor);
                        fseek(arqFuncionarios, (-1)*sizeof(Funcionarios), SEEK_CUR);
                        fwrite(funcionario, sizeof(Funcionarios), 1, arqFuncionarios);
                    }

                    break;
                default:
                    printf("Opcao Inválida!\n");
                    break;
            }

            fclose(arqFuncionarios);
            free(funcionario);

            if (encontrado == 0) {
                printf("Nao Encontrado...");
            }

            return;
            
        }
    }

}


void excluirFuncionario(void) {
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

    printf("\nSelecione o CPF do Funcionário que deseja excluir: ");
    scanf(" %s", cpfBusca);
    getchar();

    arqFuncionarios = fopen("Funcionarios/funcionarios.dat", "r+b");

    if (arqFuncionarios == NULL) {
        printf("ERROR!");
        exit(1);
    }

    encontrado = False;

    while (fread(funcionario, sizeof(Funcionarios), 1, arqFuncionarios) && encontrado == 0) {
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
            deletarFuncionarioPermanentemente();
        }else if(opcaoFuncionario == '5'){
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

Funcionarios* ColetarDadosFuncionario(void) {
    Funcionarios* funcionarios;
    funcionarios = (Funcionarios*)malloc(sizeof(Funcionarios));
        lerNome(funcionarios->nome, sizeof(funcionarios->nome));
        lerData(funcionarios->dataNascimento, sizeof(funcionarios->dataNascimento));
        lerEmail(funcionarios->email, sizeof(funcionarios->email));
        lerCPF(funcionarios->cpf, sizeof(funcionarios->cpf));
        lerSexo(funcionarios->sexo, 12);
        lerEndereco(funcionarios->endereco, 100);
        lerTelefone(funcionarios->telefone, sizeof(funcionarios->telefone));
        lerSalario(funcionarios->salario);
        lerCargo(funcionarios->cargo, 30);
        lerSetor(funcionarios->setor, 30);

    funcionarios->id = FuncionarioMaiorID() + 1;
    funcionarios->status = True;
    return funcionarios;
}   

void SalvarFuncionario(FILE* arqFuncionarios, Funcionarios* funcionario) {
    fwrite(funcionario, sizeof(Funcionarios), 1, arqFuncionarios);   
}

void ConfirmarCadastroFuncionario(Funcionarios* funcionario) {
    int escolha;
    FILE* arqFuncionarios;
    
    printf("Confirmar registro (1) ou recusar registro (0)? ");
    scanf(" %d", &escolha);
    getchar();

    switch (escolha) {
        case 1:
            arqFuncionarios = fopen("Funcionarios/funcionarios.dat", "ab");
            if (arqFuncionarios == NULL) {
                printf("ERROR!");
                exit(1);
            }
            SalvarFuncionario(arqFuncionarios, funcionario);
            fclose(arqFuncionarios);
            free(funcionario);

            printf("Cadastro Concluido!");
            break;
        case 0:
            free(funcionario);
            printf("Cadastro Cancelado.");
    }
}

int FuncionarioMaiorID(void) {
    FILE* arqFuncionarios;
    Funcionarios temp;
    int maiorID;
    arqFuncionarios = fopen("Funcionarios/funcionarios.dat", "rb");
    if (arqFuncionarios == NULL) {
        printf("ËRROR!");
        exit(1);
    }
    maiorID = 0;
    while (fread(&temp, sizeof(Funcionarios), 1, arqFuncionarios) == True) {
        if (temp.id > maiorID) {
            maiorID = temp.id;
        }
    }
    fclose(arqFuncionarios);
    return maiorID;
}

void ExibirFuncionario(Funcionarios* funcionario) {
        printf("\n==============================================================================\n");
    printf("\nSeus Dados: \n");
    printf("Nome: %s\n", funcionario->nome);
    printf("Data de Nascimento: %s\n", funcionario->dataNascimento);
    printf("Email: %s\n", funcionario->email);
    printf("CPF: %s\n", funcionario->cpf);
    printf("Sexo: %s\n", funcionario->sexo);
    printf("Endereco: %s\n", funcionario->endereco);
    printf("Telefone: %s\n", funcionario->telefone);
    printf("Salário: %s\n", funcionario->salario);
    printf("Cargo: %s\n", funcionario->cargo);
    printf("Setor: %s\n", funcionario->setor);
    printf("ID: %d\n", funcionario->id);
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

    printf("\n   Informe o CPF do Funcionário que deseja deletar permanentemente: ");
    scanf(" %s", cpfBusca);
    getchar();

    arqFuncionarios = fopen("Funcionarios/funcionarios.dat", "rb");
    arqTemp = fopen("Funcionarios/temp.dat", "wb");

    if (arqFuncionarios == NULL || arqTemp == NULL) {
        printf("\n\n\nERROR!\n\n\n");
        exit(1);
    }

    encontrado = 0;

    while (fread(funcionario, sizeof(Funcionarios), 1, arqFuncionarios)) {
        if (strcmp(funcionario->cpf, cpfBusca) == 0) {
            encontrado = True;
            ExibirFuncionario(funcionario);
            confirma = confirmarExclusao("Funcionário Permanentemente");
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
    if (!encontrado) {
        printf("Funcionário nao encontrado...");
    }
    return;
}
///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///               Projeto SIG-Circus Sistema para um Circo                  ///
///        Developed by @ViniciusL07 e lucascsantos07 -- since Aug, 2025    ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 1                                 ///
///////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>


//Assinatura das Funções
void limparTela(void);
void telaPrincipal(void);
void telaSobre(void);
void telaEquipe(void);
void telaFinalizacao(void);

void menuCliente(void);
void telaCadastroCliente(void);
void listarDadosCliente(void);
void editarDadoscliente(void);
void excluirContacliente(void);
void exibirModuloClientes(void);

void menuFuncionarios(void);
void telaCadastroFuncionario(void);
void listarDadosFuncionario(void);
void editarDadosFuncionario(void);
void excluirFuncionario(void);

void menuAgendamentos(void);
void telaCadastroAgendamento(void);
int menuTiposAgendamentos(void);
int menuHorariosDisponiveis(void);
int menuLocais(void);

//Programa Principal
int main(void){

    char opcao;

    do{
        telaPrincipal();
        scanf(" %c", &opcao);
        getchar();

        if (opcao == '1') {

            exibirModuloClientes();

        } else if (opcao == '2') {
            char opcaoFuncionario;
            do{

                menuFuncionarios();
                scanf(" %c", &opcaoFuncionario);
                getchar();
                telaCadastroFuncionario();
                listarDadosFuncionario();
                editarDadosFuncionario();
                excluirFuncionario();

            }while(opcaoFuncionario != '0');

        } else if (opcao == '3') {

            char opcaoAgendamento;
            do{

                menuAgendamentos();
                scanf(" %c", &opcaoAgendamento);
                getchar();

                telaCadastroAgendamento();

            }while(opcaoAgendamento != '0');

        } else if (opcao == '4') {
            printf("\nO módulo Vendas de ingressos está em desenvolvimento...\n");
        } else if (opcao == '5') {
            printf("\nO módulo Relatórios está em desenvolvimento...\n");
        } else if (opcao == '6') {
            telaSobre();
        } else if (opcao == '7') {
            telaEquipe();
        } else if (opcao == '0') {
            telaFinalizacao();
        } else {
            printf("\nOpção inválida! Tente novamente.\n");
        }

        if (opcao != '0') {
            printf("\nPressione ENTER para continuar...");
            getchar(); 
            //Depois de selecionar uma opção mostra essa mensagem
        }
    
    } while (opcao != '0');


    return 0;
}

void limparTela(void) {
    // Peguei as ideias com o Gemini 2.5 pro
    #ifdef _WIN32
        // Se o sistema for Windows, executa o comando "cls"
        system("cls");
    #else
        // Para outros sistemas (Linux, macOS), executa o comando "clear"
        system("clear");
    #endif
}

void telaPrincipal(void) {
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
    printf("||               ~ ~ ~ Sistema de Gestão Para Um Circo ~ ~ ~                ||\n");
    printf("||                                                                          ||\n");
    printf("||                           -- Menu Principal --                           ||\n");
    printf("||                                                                          ||\n");
    printf("||             1. Clientes                                                  ||\n");
    printf("||             2. Funcionários                                              ||\n");
    printf("||             3. Agendamentos                                              ||\n");
    printf("||             4. Vendas de ingressos                                       ||\n");
    printf("||             5. Relatórios                                                ||\n");
    printf("||             6. Sobre o Projeto                                           ||\n");
    printf("||             7. Equipe de Desenvolvimento                                 ||\n");
    printf("||             0. Sair                                                      ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}

void telaSobre(void){
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
    printf("||  O SIG-Circus é um sistema desenvolvido para facilitar a gestão          ||\n");
    printf("||  completa de um circo, proporcionando controle eficiente de todas        ||\n");
    printf("||  as operações essenciais. Com uma interface intuitiva, o sistema         ||\n");
    printf("||  permite organizar clientes, funcionários, vendas de ingressos,          ||\n");
    printf("||  relatórios e toda a programação de eventos de forma prática e segura.   ||\n");
    printf("||  O objetivo do SIG-Circus é otimizar os processos internos, tornando     ||\n");
    printf("||  a administração do circo mais ágil, organizada e eficiente, oferecendo  ||\n");
    printf("||  suporte tanto para a equipe quanto para o público.                      ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\n");
}

void telaEquipe(void){
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
    printf("||  Equipe de Desenvolvimento do Projeto:                                   ||\n");
    printf("||                                                                          ||\n");
    printf("||  Lucas da Costa Santos                                                   ||\n");
    printf("||  Email: lucas.costa.123@ufrn.edu.br                                      ||\n");
    printf("||  Curso: Bacharelado em Sistemas de Informação - 2º Período               ||\n");
    printf("||                                                                          ||\n");
    printf("||  Vinícius Linhares Queiroz                                               ||\n");
    printf("||  Email: vinicius.linhares.702@ufrn.edu.br                                ||\n");
    printf("||  Curso: Bacharelado em Sistemas de Informação - 2º Período               ||\n");
    printf("||                                                                          ||\n");
    printf("||  Repositório: https://github.com/lucascsantos07/SIG-Circus.git           ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\n");
}

void telaFinalizacao(void) {
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
    printf("||               ~ ~ ~ Sistema de Gestão Para Um Circo ~ ~ ~                ||\n");
    printf("||                                                                          ||\n");
    printf("||                  Obrigado por utilizar o SIG-Circus!                     ||\n");
    printf("||                                                                          ||\n");
    printf("||                          Até a próxima!                                  ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\n");
}



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
    char sexo;
    char cidade[50];

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Cadastro de Cliente ~ ~ ~                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");
    
    printf("\n   Nome Completo       : ");
    fgets(nome, sizeof(nome), stdin);
    printf("   Data de Nascimento  : ");
    fgets(dataNascimento, sizeof(dataNascimento), stdin);
    printf("   Email               : ");
    fgets(email, sizeof(email), stdin);
    printf("   CPF                 : ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("   Sexo (m/f)          : ");
    scanf(" %c", &sexo);
    getchar();
    printf("   Cidade              : ");
    fgets(cidade, sizeof(cidade), stdin);

    printf("\n==============================================================================\n");
    printf("||                             Cadastro concluído                           ||\n");
    printf("==============================================================================\n");

}


void listarDadosCliente(void){
    limparTela();

    char cpf[20];

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                        ~ ~ ~ Dados Pessoais ~ ~ ~                        ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    printf("\nInforme o seu CPF: ");
    fgets(cpf, sizeof(cpf), stdin);

    printf("\n==============================================================================\n");
    printf("\nNome Completo: \n");
    printf("Data de Nascimento: \n");
    printf("Email: \n");
    printf("CPF: \n");
    printf("Sexo(m/f): \n");
    printf("Cidade: \n");
    printf("\n==============================================================================\n");
 
}



void editarDadoscliente(void){
    limparTela();

    char cpf_busca[20];
    char novoNome[50];
    char novaDataNascimento[20];
    char novoEmail[100];
    char novoCpf[20];
    char novoSexo;
    char novaCidade[50];
    char confirma;

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
    printf("   Data de Nascimento  : ");
    fgets(novaDataNascimento, sizeof(novaDataNascimento), stdin);
    printf("   Email               : ");
    fgets(novoEmail, sizeof(novoEmail), stdin);
    printf("   CPF                 : ");
    fgets(novoCpf, sizeof(novoCpf), stdin);
    printf("   Sexo (m/f)          : ");
    scanf(" %c", &novoSexo);
    getchar();
    printf("   Cidade              : ");
    fgets(novaCidade, sizeof(novaCidade), stdin);

    printf("\nDeseja Realmente alterar seus dados pessoais? s - sim ou n - não: ");
    scanf(" %c", &confirma);
    getchar();

    printf("\n==============================================================================\n");
    printf("||                        Dados Atualizados com sucesso                     ||\n");
    printf("==============================================================================\n");

}


void excluirContacliente(void){
    limparTela();

    char cpf_busca[20];
    char confirma;

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
    printf("Sexo(m/f): \n");
    printf("Cidade: \n");
    printf("\n==============================================================================\n");

    printf("\nDeseja Realmente Excluir sua Conta do Sistema? s - sim ou n - não: ");
    scanf(" %c", &confirma);
    getchar();

    printf("\n==============================================================================\n");
    printf("||                        Cliente Excluido Com Sucesso                      ||\n");
    printf("==============================================================================\n");

}

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
    getchar();
    
    printf("\n   Nome Completo       : ");
    fgets(nome, sizeof(nome), stdin);
    printf("   Data de Nascimento  : ");
    fgets(dataNascimento, sizeof(dataNascimento), stdin);
    printf("   Email               : ");
    fgets(email, sizeof(email), stdin);
    printf("   CPF                 : ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("   Sexo (m/f)          : ");
    scanf(" %c", &sexo);
    getchar();
    printf("   Endereço            : ");
    fgets(endereco, sizeof(endereco), stdin);
    printf("   Telefone            : ");
    fgets(telefone, sizeof(telefone), stdin);
    printf("   Salário             : ");
    fgets(salario, sizeof(salario), stdin);
    printf("   Cargo               : ");
    fgets(cargo, sizeof(cargo), stdin);
    printf("   Setor               : ");
    fgets(setor, sizeof(setor), stdin);

    printf("\n================================================================================\n");
    printf("||                             Cadastro concluído                             ||\n");
    printf("================================================================================\n");
    getchar();

}

void listarDadosFuncionario(void) {
    limparTela();
    char cpf[20];
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
    getchar();
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
    char confirma;

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
    printf("   Data de Nascimento  : ");
    fgets(novaDataNascimento, sizeof(novaDataNascimento), stdin);
    printf("   Email               : ");
    fgets(novoEmail, sizeof(novoEmail), stdin);
    printf("   CPF                 : ");
    fgets(novoCpf, sizeof(novoCpf), stdin);
    printf("   Sexo (m/f)          : ");
    scanf(" %c", &novoSexo);
    getchar();
    printf("   Endereço            : ");
    fgets(novoEndereco, sizeof(novoEndereco), stdin);
    printf("   Telefone            : ");
    fgets(novoTelefone, sizeof(novoTelefone), stdin);
    printf("   Salário             : ");
    fgets(novoSalario, sizeof(novoSalario), stdin);
    printf("   Cargo               : ");
    fgets(novoCargo, sizeof(novoCargo), stdin);
    printf("   Setor               : ");
    fgets(novoSetor, sizeof(novoSetor), stdin);

    printf("\nDeseja Realmente alterar os dados do funcionário? s - sim ou n - não: ");
    scanf(" %c", &confirma);
    getchar();

    printf("\n================================================================================\n");
    printf("||                   Dados do Funcionário Atualizados com Sucesso             ||\n");
    printf("================================================================================\n");
    getchar();
}


void excluirFuncionario(void) {
    limparTela();
    char cpf[20];
    char confirma;

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

    printf("\nDeseja realmente excluir o funcionário? s - sim ou n - não: ");
    scanf(" %c", &confirma);
    getchar();

    if (confirma == 's') {
        printf("\n================================================================================\n");
        printf("||                   Funcionário Excluído com Sucesso                         ||\n");
        printf("================================================================================\n");
    } else {
        printf("\n================================================================================\n");
        printf("||                   Exclusão de Funcionário Cancelada                        ||\n");
        printf("================================================================================\n");
    }
    getchar();
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
    printf("||             1. Cadastrar Agendamento                                     ||\n");
    printf("||             2. Consultar Agendamentos                                    ||\n");
    printf("||             3. Alterar Agendamentos                                      ||\n");
    printf("||             4. Cancelar Agendamentos                                     ||\n");
    printf("||             5. Listar Todos os Agendamentos Futuros                      ||\n");
    printf("||             0. Voltar Menu Principal                                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}

void telaCadastroAgendamento(void){
    limparTela();
    int tipoAgendamento;
    char data[12], cpfResponsavel[20];
    int horario;
    int capacidadeMax;
    int local;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Cadastro de Agendamento ~ ~ ~                 ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");
    
    tipoAgendamento = menuTiposAgendamentos();

    printf("\n   Data (DD/MM/AAAA)                   : ");
    fgets(data, sizeof(data), stdin);

    horario = menuHorariosDisponiveis();

    local = menuLocais();

    printf("\n   Capacidade Maxima de Publico        : ");
    scanf(" %d", &capacidadeMax);
    getchar();

    printf("\n   CPF do Responsável pelo Agendamento: ");
    fgets(cpfResponsavel, sizeof(cpfResponsavel), stdin);

    printf("\n==============================================================================\n");
    printf("||                             Cadastro concluído                           ||\n");
    printf("==============================================================================\n");

}

int menuTiposAgendamentos(void){

    int tipoAgendamento;

    printf("\n   Tipo de Agendamento                 \n");
    printf("\n   1 - Espetaculo                        ");
    printf("\n   2 - Ensaio                            ");
    printf("\n   3 - Manutencao                        ");
    printf("\n   4 - Evento Especial                   ");
    printf("\n   5 - Montagem de Estrutura             ");
    printf("\n   6 - Reunião Administrativa          \n");
    printf("\n   Informe sua opcao                   : ");
    scanf(" %d", &tipoAgendamento);
    getchar();

    return tipoAgendamento;
}

int menuHorariosDisponiveis(void){

    int horario;

    printf("\n   Horarios Disponiveis                   \n");
    printf("\n   1 - 07:00                                ");
    printf("\n   2 - 09:00                                ");
    printf("\n   3 - 11:00                                ");
    printf("\n   4 - 14:00                                ");
    printf("\n   5 - 16:00                                ");
    printf("\n   6 - 18:00                                ");
    printf("\n   7 - 20:00 (exclusivo para espetaculos) \n");
    printf("\n   Informe sua opcao                   : ");
    scanf(" %d", &horario);
    getchar();

    return horario;
}


int menuLocais(void){

    int local;

    printf("\n   Local                               \n");
    printf("\n   1 - Palco Principal                   ");
    printf("\n   2 - Área Externa                      ");
    printf("\n   3 - Área de Manutenção                ");
    printf("\n   4 - Sala Administrativa               ");
    printf("\n   5 - Camarins                        \n");
    printf("\n   Informe sua opcao                   : ");
    scanf(" %d", &local);
    getchar();

    return local;

}
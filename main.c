///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///               Projeto SIG-Circus Sistema para um Circo                  ///
///        Developed by @ViniciusL07 e lucascsantos07 -- since Aug, 2025    ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 2                                 ///
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

void confirmarExclusao(const char *modulo);
void confirmarAlteracao(void);

void menuFuncionarios(void);
void telaCadastroFuncionario(void);
void listarDadosFuncionario(void);
void editarDadosFuncionario(void);
void excluirFuncionario(void);
void exibirModuloFuncionarios(void);

void menuAgendamentos(void);
void telaCadastroAgendamento(void);
void alterarAgendamento(void);
void excluirAgendamento(void);
void consultarAgendamento(void);
void listarTodosAgendamentos(void);
int menuTiposAgendamentos(void);
int menuHorariosDisponiveis(void);
int menuLocais(void);
void exibirModuloAgendamentos(void);

void menuVendasIngressos(void);
void telaCadastroVendaIngresso(void);
void consultarVendaIngresso(void);

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

            exibirModuloFuncionarios();

        } else if (opcao == '3') {

            exibirModuloAgendamentos();
            
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
    printf("Sexo(m/f): \n");
    printf("Cidade: \n");
    printf("\n==============================================================================\n");

    confirmarExclusao("Cliente");

}

void confirmarExclusao(const char *modulo){

    char confirma;

    printf("\nDeseja Realmente Excluir este dado do Sistema? s - sim ou n - não: ");
    scanf(" %c", &confirma);
    getchar();
    if(confirma == 's'){
        printf("\n==============================================================================\n");
        printf("                        %s Excluido Com Sucesso                      \n", modulo);
        printf("==============================================================================\n");
    }else if(confirma == 'n'){
        printf("\n==============================================================================\n");
        printf("||                            Exclusao Cancelado                            ||\n");
        printf("==============================================================================\n");
    }else{
        printf("\nOpção inválida! Tente novamente.\n");
    }

}

void confirmarAlteracao(){

    char confirma;

    printf("\nDeseja Realmente alterar esse(s) dado(s)? s - sim ou n - não: ");
    scanf(" %c", &confirma);
    getchar();

    if(confirma == 's'){
        printf("\n==============================================================================\n");
        printf("||                     Dado(s) Atualizado(s) com sucesso                    ||\n");
        printf("==============================================================================\n");
    }else if(confirma == 'n'){
        printf("\n==============================================================================\n");
        printf("||                           Alteracao Cancelado                            ||\n");
        printf("==============================================================================\n");
    }else{
        printf("\nOpção inválida! Tente novamente.\n");
    }

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

    confirmarAlteracao();
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

void exibirModuloAgendamentos(void){
    char opcaoAgendamento;
    do{

        menuAgendamentos();
        scanf(" %c", &opcaoAgendamento);
        getchar();

        if(opcaoAgendamento == '1'){
            telaCadastroAgendamento();
        }else if (opcaoAgendamento == '2'){
            consultarAgendamento();
        }else if(opcaoAgendamento == '3'){
            alterarAgendamento();
        }else if(opcaoAgendamento == '4'){
            excluirAgendamento();
        }else if(opcaoAgendamento == '5'){
            listarTodosAgendamentos();
        }else if(opcaoAgendamento != '0'){
            printf("\nOpção inválida! Tente novamente.\n");
        }

        if (opcaoAgendamento != '0') {
            printf("\nPressione ENTER para continuar...");
            getchar(); 
            //Depois de selecionar uma opção mostra essa mensagem
        }

    }while(opcaoAgendamento != '0');
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

void alterarAgendamento(void){
    limparTela();

    int codAgendamento;
    int tipoAgendamento;
    char data[12], cpf_busca[20];
    int horario;
    int capacidadeMax;
    int local;
    char confirma;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                ~ ~ ~ Alteracao de Agendamentos ~ ~ ~                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    printf("\n   Informe CPF do Responsavel pelo Agendamento: ");
    fgets(cpf_busca, sizeof(cpf_busca), stdin);

    printf("\n   Lista dos Agendamentos do Responsável Informado: \n");

    printf("\n   Digite o código do Agendamento que deseja alterar: ");
    scanf(" %d", &codAgendamento);
    getchar();

    printf("\n   Data (DD/MM/AAAA)                   : ");
    fgets(data, sizeof(data), stdin);

    horario = menuHorariosDisponiveis();

    local = menuLocais();

    printf("\n   Capacidade Maxima de Publico        : ");
    scanf(" %d", &capacidadeMax);
    getchar();

    confirmarAlteracao();

}


void excluirAgendamento(void){
    limparTela();

    int codAgendamento;
    char cpf_busca[20];
    char confirma;


    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                 ~ ~ ~ Exclusao de Agendamentos ~ ~ ~                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    printf("\n   Informe CPF do Responsavel pelo Agendamento: ");
    fgets(cpf_busca, sizeof(cpf_busca), stdin);

    printf("\n   Lista dos Agendamentos do Responsável Informado: \n");

    printf("\n   Digite o código do Agendamento que deseja alterar: ");
    scanf(" %d", &codAgendamento);
    getchar();

    printf("\n==============================================================================\n");
    printf("\nAGENDAMENTO \n");
    printf("\nTipo: \n");
    printf("Data: \n");
    printf("Horario: \n");
    printf("Local: \n");
    printf("Capacidade: \n");
    printf("CPF Responsavel: \n");
    printf("\n==============================================================================\n");

    confirmarExclusao("Agendamento");

}


void listarTodosAgendamentos(void){
    limparTela();

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                             ~ ~ ~ Agenda ~ ~ ~                           ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    printf("\n>> Segunda Feira (27/10/2025) \n");

    printf("\n==============================================================================\n");
    printf("\n|| Tipo: Espetaculo\n");
    printf("|| Horario: 20:00\n");
    printf("|| Local: Palco Principal\n");
    printf("|| Capacidade: 500\n");
    printf("|| CPF Responsavel: 123.456.789-12\n");
    printf("\n==============================================================================\n");

    printf("\n>> Terça Feira (28/10/2025) \n");

    printf("\n==============================================================================\n");
    printf("\n|| Tipo: Ensaio\n");
    printf("|| Horario: 09:00\n");
    printf("|| Local: Area Externa\n");
    printf("|| Capacidade: 0\n");
    printf("|| CPF Responsavel: 123.444.777-99\n");
    printf("\n==============================================================================\n");
}

void consultarAgendamento(void){
    limparTela();

    int escolha, tipoAgendamento;
    char data[12], cpfResponsavel[20];

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                   ~ ~ ~ Consultar Agendamentos ~ ~ ~                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    printf("\n   Deseja Pesquisar Por \n");
    printf("\n      1 - Data ");
    printf("\n      2 - Tipo ");
    printf("\n      3 - Responsavel \n");
    printf("\n   Digite sua opcao: ");
    scanf(" %d", &escolha);
    getchar();

    if(escolha == 1){
        printf("\n   Informe a Data (DD/MM/AAAA): ");
        fgets(data, sizeof(data), stdin);
        printf("\n   Agendamentos encontrados para a data %s\n", data);
    }else if(escolha == 2){
        tipoAgendamento = menuTiposAgendamentos();
        printf("\n   Agendamentos encontrados do tipo selecionado: \n");
    }else if(escolha == 3){
        printf("\n   Informe a CPF do Responsavel: ");
        fgets(cpfResponsavel, sizeof(cpfResponsavel), stdin);
        printf("\n   Agendamentos encontrados para o responsável %s\n", cpfResponsavel);
    }else{
        printf("\nOpção inválida! Tente novamente.\n");
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


void menuVendasIngressos(void) {
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
    printf("||                        -- Venda de Ingressos --                          ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||             1. Cadastrar Venda de Ingresso                               ||\n");
    printf("||             2. Consultar Venda de Ingresso                               ||\n");
    printf("||             3. Alterar Venda de Ingresso                                 ||\n");
    printf("||             4. Cancelar Venda de Ingresso                                ||\n");
    printf("||             0. Voltar Menu Principal                                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}


void telaCadastroVendaIngresso(void) {
    limparTela();
    char cpfCliente[20];
    char listaEspetaculos[100];
    int quantidadeIngressos;
    float valorTotal;
    float precoIngresso;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Venda de Ingressos ~ ~ ~                      ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @ViniciusL07 -- since Aug, 2025               ||\n");
    printf("==============================================================================\n");
    
    printf("\n   CPF do Cliente        : ");
    fgets(cpfCliente, sizeof(cpfCliente), stdin);
    printf("   Lista de Espetáculos  : ");
    printf("   Digite o valor do ingresso: ");
    scanf(" %f", &precoIngresso);
    getchar();
    printf("   Valor do ingresso: R$ %.2f", precoIngresso);
    printf("   Digite a Quantidade de Ingressos: ");
    scanf(" %d", &quantidadeIngressos);
    getchar();
    valorTotal = quantidadeIngressos * precoIngresso;
    printf("   Valor Total           : R$ %.2f", valorTotal);
    getchar();

    printf("\n==============================================================================\n");
    printf("||                           Venda concluída                                ||\n");
    printf("==============================================================================\n");

}


void consultarVendaIngresso(void) {
    limparTela();
    int escolha;
    char data[12], cpfCliente[20];

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                      ~ ~ ~ Consultar Vendas ~ ~ ~                        ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||                   Developed by @ViniciusL07 -- since Aug, 2025           ||\n");
    printf("==============================================================================\n");

    printf("\n   Deseja Pesquisar Por \n");
    printf("\n      1 - Data ");
    printf("\n      2 - Espetaculo ");
    printf("\n      3 - Cliente \n");
    printf("\n   Digite sua opcao: ");
    scanf(" %d", &escolha);
    getchar();

    if(escolha == 1){
        printf("\n   Informe a Data (DD/MM/AAAA): ");
        fgets(data, sizeof(data), stdin);
        printf("\n   Vendas encontradas para a data %s\n", data);
    }else if(escolha == 2){
        printf("\n   Vendas encontradas para o espetáculo selecionado: \n");
    }else if(escolha == 3){
        printf("\n   Informe a CPF do Cliente: ");
        fgets(cpfCliente, sizeof(cpfCliente), stdin);
        printf("\n   Vendas encontradas para o cliente %s\n", cpfCliente);
    }else{
        printf("\nOpção inválida! Tente novamente.\n");
    }

}
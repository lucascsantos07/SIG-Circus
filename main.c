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


//Programa Principal
int main(void){

    char opcao;

    do{
        telaPrincipal();
        scanf(" %c", &opcao);
        getchar(); //Bloqueia o uso do programa até digitar alguma coisa e pressionar enter

        if (opcao == '1') {
            printf("\nO módulo Clientes está em desenvolvimento...\n");
        } else if (opcao == '2') {
            printf("\nO módulo Funcionários está em desenvolvimento...\n");
        } else if (opcao == '3') {
            printf("\nO módulo Agendamentos está em desenvolvimento...\n");
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
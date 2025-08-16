#include <stdio.h>
#include <windows.h>


//Assinatura das Funções
void telaSobre(void);
void telaEquipe(void);


//Programa Principal
int main(void){

    SetConsoleOutputCP(65001); // UTF-8
    SetConsoleCP(65001);

    telaSobre();
    telaEquipe();
    return 0;
}

void telaSobre(void){
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

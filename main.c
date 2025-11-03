///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///               Projeto SIG-Circus Sistema para um Circo                  ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "./Clientes/clientes.h"
#include "./Utilitarios/utilitarios.h"
#include "./Agendamentos/agendamentos.h"
#include "./Funcionarios/funcionarios.h"
#include "./Informacoes/informacoes.h"
#include "./Ingressos/ingressos.h"
#include "./Interfaces/interface.h"

//Programa Principal
int main(void){

    char opcao;

    do{
        
        opcao = telaPrincipal();

        if (opcao == '1') {

            exibirModuloClientes();

        } else if (opcao == '2') {

            exibirModuloFuncionarios();

        } else if (opcao == '3') {

            exibirModuloAgendamentos();
            
        } else if (opcao == '4') {

            exibirModuloVendasIngressos();

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
        }
    
    } while (opcao != '0');

    return 0;
    
}






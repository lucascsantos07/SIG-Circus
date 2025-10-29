#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "agendamentos.h"
#include "../Utilitarios/utilitarios.h"
#include "../Validacao/validacao.h"
#include "../Funcionarios/funcionarios.h"

#define True 1
#define False 0

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
            cancelarAgendamento();
        }else if(opcaoAgendamento == '5'){
            excluirPermanenteAgendamento();
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
    printf("||             1. Cadastrar Espetaculo                                      ||\n");
    printf("||             2. Consultar Espetaculo                                      ||\n");
    printf("||             3. Alterar Espetaculo                                        ||\n");
    printf("||             4. Cancelar Espetaculo                                       ||\n");
    printf("||             5. Excluir Espetaculo Permanentemente                        ||\n");
    printf("||             0. Voltar Menu Principal                                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("\nDigite sua opção: ");
}

void telaCadastroAgendamento(void){
    limparTela();

    Agendamento* agendamento;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                    ~ ~ ~ Agendamento de Espetáculo ~ ~ ~                 ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    agendamento = coletarDadosAgendamentos();

    if(agendamento == NULL){
        return;
    }

    exibirAgendamento(agendamento);

    confirmarCadastroAgendamento(agendamento);

}

void alterarAgendamento(void){
    limparTela();

    int codAgendamento, retorno, encontrado, novaCapacidade;
    float novoPreco;
    char cpfBusca[20];
    char novaData[12], novoHorario[7];
    char opcao;
    Agendamento* agendamento;
    FILE* arqAgendamentos;
    Agendamento temp;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                 ~ ~ ~ Alteracao de Agendamento ~ ~ ~                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    agendamento = (Agendamento*) malloc(sizeof(Agendamento));

    retorno = lerCpfResponsavel(cpfBusca);
    if(retorno == 0){
        return;
    }

    listarAgendamentosResponsavel(cpfBusca);

    int leituraValida;
    do {
        printf("\n  Digite o código do Agendamento que deseja alterar: ");

        leituraValida = scanf("%d", &codAgendamento);

        if (leituraValida != 1) {
            printf("\n  Valor inválido! Digite apenas números.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

    } while (leituraValida != 1);

    arqAgendamentos = fopen("Agendamentos/agendamento.dat", "r+b");
    if (arqAgendamentos == NULL){
        printf("Erro na abertura do arquivo\n");
        free(agendamento);
        exit(1);
    }

    encontrado = False;

    while(fread(agendamento, sizeof(Agendamento), 1, arqAgendamentos) == 1){
        if(agendamento->id == codAgendamento && agendamento->status){
            encontrado = True;
            exibirAgendamento(agendamento);

            do {

                printf("\n  Qual dado deseja alterar: \n");
                printf("\n  1 - Data");
                printf("\n  2 - Horário");
                printf("\n  3 - Quantidade de Ingressos");
                printf("\n  4 - Preço\n");

                printf("\n  Digite seu opção: ");
                scanf("%c", &opcao);
                
                if (!isdigit(opcao) || opcao < '1' || opcao > '4') {
                    printf("\n   Opção inválida! Digite um número de 1 a 4\n");
                }

                int c;
                while((c = getchar()) != '\n' && c != EOF);

            } while (!isdigit(opcao) || opcao < '1' || opcao > '4');

            switch (opcao){
                case '1':

                    lerDataEspetaculo(novaData,12);

                    retorno = confirmarAlteracao();
                    if(retorno==1){
                        strcpy(agendamento->data,novaData);
                    }

                    break;
                
                case '2':

                    lerHora(novoHorario,7);

                    retorno = confirmarAlteracao();
                    if(retorno==1){
                        strcpy(agendamento->horario,novoHorario);
                    }

                    break;
                
                case '3':

                    lerCapacidade(&novaCapacidade);

                    retorno = confirmarAlteracao();
                    if(retorno==1){
                        agendamento->capacidade=novaCapacidade;
                    }

                    break;

                case '4':

                    lerPreco(&novoPreco);

                    retorno = confirmarAlteracao();
                    if(retorno==1){
                        agendamento->precoIngresso=novoPreco;
                    }

                    break;
                
                default:
                    printf("\n  Opção Inválida\n");
                    break;
            }
            if (retorno == 1) {
                fseek(arqAgendamentos, -sizeof(Agendamento), SEEK_CUR);
                fwrite(agendamento, sizeof(Agendamento), 1, arqAgendamentos);
                fclose(arqAgendamentos);
                return;
            }
        }
    }

    fclose(arqAgendamentos);
    free(agendamento);

    if(!encontrado){
        printf("\nAgendamento não encontrado\n");
    }

    getchar();

}


void cancelarAgendamento(void){
    limparTela();

    int codAgendamento, retorno, encontrado;
    char cpfBusca[20];
    FILE* arqAgendamentos;
    Agendamento* agendamento;
    Agendamento temp;

    printf("\n==============================================================================\n");
    printf("||                     ~ ~ ~ Cancelar Espetaculo ~ ~ ~                      ||\n");
    printf("==============================================================================\n");

    agendamento = (Agendamento*) malloc(sizeof(Agendamento));
    if (agendamento == NULL){
        printf("Erro de memoria!\n");
        exit(1);
    }

    retorno = lerCpfResponsavel(cpfBusca);
    if(retorno == 0){
        return;
    }

    listarAgendamentosResponsavel(cpfBusca);

    int leituraValida;
    do {
        printf("\n  Digite o código do Agendamento que deseja excluir: ");

        leituraValida = scanf("%d", &codAgendamento);

        if (leituraValida != 1) {
            printf("\n  Valor inválido! Digite apenas números.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

    } while (leituraValida != 1);

    arqAgendamentos = fopen("Agendamentos/agendamento.dat", "r+b");
    if (arqAgendamentos == NULL){
        printf("Erro na abertura do arquivo\n");
        free(agendamento);
        exit(1);
    }

    encontrado = 0;

    while(fread(agendamento, sizeof(Agendamento), 1, arqAgendamentos) == 1){
        if(agendamento->id == codAgendamento && agendamento->status){
            encontrado = True;
            exibirAgendamento(agendamento);
            retorno = confirmarExclusao("Agendamento");
            if(retorno == 1){
                agendamento->status = False;
                fseek(arqAgendamentos, -sizeof(Agendamento), SEEK_CUR);
                fwrite(agendamento, sizeof(Agendamento), 1, arqAgendamentos);
            }
            break;
        }
    }

    fclose(arqAgendamentos);
    free(agendamento);

    if(!encontrado){
        printf("\n  Agendamento não encontrado\n");
    }

    getchar();

}



void excluirPermanenteAgendamento(void) {
    limparTela();

    int retorno, encontrado = 0;
    int codAgendamento;
    char cpfBusca[20];
    FILE *arqAgendamentos, *arqTemp;
    Agendamento *agendamento;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||               ~ ~ ~ Excluir Espetaculo Permanentemente ~ ~ ~             ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n");
    printf("==============================================================================\n");

    agendamento = (Agendamento*) malloc(sizeof(Agendamento));
    if (agendamento == NULL) {
        printf("Erro de memória!\n");
        exit(1);
    }

    retorno = lerCpfResponsavel(cpfBusca);
    if(retorno == 0){
        return;
    }

    listarAgendamentosResponsavel(cpfBusca);

    int leituraValida;
    do {
        printf("\n  Digite o código do Agendamento que deseja excluir: ");

        leituraValida = scanf("%d", &codAgendamento);

        if (leituraValida != 1) {
            printf("\n  Valor inválido! Digite apenas números.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

    } while (leituraValida != 1);

    arqAgendamentos = fopen("Agendamentos/agendamento.dat", "rb");

    if (arqAgendamentos == NULL) {
        printf("\n  Nenhum agendamento cadastrado ainda.\n");
        free(agendamento);
        return;
    }

    arqTemp = fopen("Agendamentos/temp.dat", "wb");
    if (arqTemp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(arqAgendamentos);
        free(agendamento);
        return;
    }

    while (fread(agendamento, sizeof(Agendamento), 1, arqAgendamentos) == 1) {
        int deveGravar = True;

        if (agendamento->id == codAgendamento && agendamento->status) {
            encontrado = True;
            exibirAgendamento(agendamento);

            int comparacao = compararDataComHoje(agendamento->data);
            if (comparacao <= 0) {
                printf("\n  Este agendamento já ocorreu ou é hoje. Exclusão física não permitida.\n");
            } else {
                retorno = confirmarExclusao("Agendamento");
                if (retorno == 1) {
                    deveGravar = False;
                }
            }
        }

        if (deveGravar) {
            fwrite(agendamento, sizeof(Agendamento), 1, arqTemp);
        }
    }

    fclose(arqAgendamentos);
    fclose(arqTemp);

    if (encontrado) {
        remove("Agendamentos/agendamento.dat");
        rename("Agendamentos/temp.dat", "Agendamentos/agendamento.dat");
    } else {
        remove("Agendamentos/temp.dat");
        printf("\n  Agendamento não encontrado.\n");
    }

    free(agendamento);

    getchar();
}



void consultarAgendamento(void){
    limparTela();

    char escolha;
    int encontrado;
    FILE* arqAgendamentos;
    char cpfLido[20], dataLida[12];
    Agendamento* agendamento;

    printf("\n");
    printf("==============================================================================\n");
    printf("||                                                                          ||\n");
    printf("||                   ~ ~ ~ Consultar Agendamentos ~ ~ ~                     ||\n");
    printf("||                                                                          ||\n");
    printf("==============================================================================\n");
    printf("||               Developed by @lucascsantos07 -- since Aug, 2025            ||\n"); 
    printf("==============================================================================\n");

    agendamento = (Agendamento*) malloc(sizeof(Agendamento));

    do {

        printf("\n  Deseja Pesquisar Por \n");
        printf("\n    1 - Data ");
        printf("\n    2 - Responsavel \n");
        printf("\n  Digite sua opcao: ");
        scanf(" %c", &escolha);
        
        if (!isdigit(escolha) || escolha < '1' || escolha > '2') {
            printf("\n   Opção inválida! Digite o número de 1 ou 2\n");
        }

        int c;
        while((c = getchar()) != '\n' && c != EOF);

    } while (!isdigit(escolha) || escolha < '1' || escolha > '2');

    if(escolha == '1'){
   
        lerData(dataLida,20);

        arqAgendamentos = fopen("Agendamentos/agendamento.dat","rb");

        if (arqAgendamentos == NULL){
            printf("\n   Nenhum agendamento cadastrado ainda.\n");
            free(agendamento);
            return;
        }

        encontrado = False;

        printf("\n  Lista de Agendamentos encontrados na data %s:\n", dataLida);

        while(fread(agendamento, sizeof(Agendamento),1,arqAgendamentos)){
            if((agendamento->status)&&(strcmp(dataLida,agendamento->data)==0)){
                encontrado = True;
                exibirAgendamento(agendamento);
            }
        }

        fclose(arqAgendamentos);
        free(agendamento);
        if(!encontrado){
            printf("\n  Agendamento não encontrado\n");
        }

    }else if(escolha == '2'){

        int retorno = lerCpfResponsavel(cpfLido);
        if(retorno == 0){
            return;
        }

        arqAgendamentos = fopen("Agendamentos/agendamento.dat","rb");

        if (arqAgendamentos == NULL){
            printf("\n   Nenhum agendamento cadastrado ainda.\n");
            free(agendamento);
            return; 
        }

        encontrado = False;

        printf("\n  Lista de Agendamentos encontrados do responsável %s:\n", cpfLido);

        while(fread(agendamento, sizeof(Agendamento),1,arqAgendamentos)){
            if((agendamento->status)&&(strcmp(cpfLido,agendamento->cpfResponsavel)==0)){
                encontrado = True;
                exibirAgendamento(agendamento);
            }
        }

        fclose(arqAgendamentos);
        free(agendamento);
        if(!encontrado){
            printf("\n  Agendamento(s) não encontrado\n");
        }

    }else{
        printf("\nOpção inválida! Tente novamente.\n");
    }
}

Agendamento* coletarDadosAgendamentos(void){

    Agendamento* agendamento;

    agendamento = (Agendamento*) malloc(sizeof(Agendamento));

    lerDataEspetaculo(agendamento->data, 12);

    lerHora(agendamento->horario, 7);

    lerCidade(agendamento->cidade, 50);

    lerCapacidade(&agendamento->capacidade);

    lerPreco(&agendamento->precoIngresso);

    int retorno = lerCpfResponsavel(agendamento->cpfResponsavel);
    if(retorno == 0){
        return NULL;
    }

    agendamento->id = gerarIdAgendamento();

    agendamento->quantIngressosVend = 0;

    agendamento->status = True;

    return agendamento;

}

void exibirAgendamento(Agendamento* agendamento){
    printf("\n==============================================================================\n");
    printf("\n  Dados do Agendamento: \n");
    printf("\n  ID: %d\n", agendamento->id);
    printf("  Data: %s\n", agendamento->data);
    printf("  Horario: %s\n", agendamento->horario);
    printf("  Cidade: %s\n", agendamento->cidade);
    printf("  Quantidade de Ingressos Disponíveis: %d\n", agendamento->capacidade);
    printf("  Preço do Ingresso: %.2f\n", agendamento->precoIngresso);
    printf("  Quantidade de Ingressos Vendidos: %d\n", agendamento->quantIngressosVend);
    printf("  CPF do Responsável: %s\n", agendamento->cpfResponsavel);
    printf("\n==============================================================================\n");
}

void confirmarCadastroAgendamento(Agendamento* agendamento){
    char opcao;
    FILE *arqAgendamento;

    printf("\n   <-------------  Digite 1 para confirmar cadastro --------------------->\n");
    printf("   <-------------  Digite 2 para cancelar cadastro  --------------------->\n");
    printf("\n  Opção: ");
    scanf("%c",&opcao);
    getchar();

    if(opcao == '1'){
        arqAgendamento = fopen("Agendamentos/agendamento.dat","ab");

        if (arqAgendamento == NULL){
            printf("Erro na criacao do arquivo\n!");
            exit(1);
        }

        fwrite(agendamento, sizeof(Agendamento), 1, arqAgendamento);
        fclose(arqAgendamento);
        free(agendamento);

        printf("\n==============================================================================\n");
        printf("||                             Cadastro concluído                           ||\n");
        printf("==============================================================================\n");
    }else if(opcao == '2'){
        printf("\n==============================================================================\n");
        printf("||                             Cadastro cancelado                           ||\n");
        printf("==============================================================================\n");
        free(agendamento);
    }else{
        printf("\nOpção inválida\n");
    }
    
}

// Créditos: GPT-5
int compararDataComHoje(const char *dataAgendamento) {
    int dia, mes, ano;
    sscanf(dataAgendamento, "%d/%d/%d", &dia, &mes, &ano);

    // Data atual
    time_t t = time(NULL);
    struct tm *hoje = localtime(&t);

    int diaAtual = hoje->tm_mday;
    int mesAtual = hoje->tm_mon + 1;
    int anoAtual = hoje->tm_year + 1900;

    if (ano > anoAtual) return 1;
    if (ano < anoAtual) return -1;

    if (mes > mesAtual) return 1;
    if (mes < mesAtual) return -1;

    if (dia > diaAtual) return 1;
    if (dia < diaAtual) return -1;

    return 0; // mesma data
}

int validarQuantidadeIngressos(Agendamento* agendamento, int quantidadeSolicitada) {
    int ingressosTotais = quantidadeSolicitada + agendamento->quantIngressosVend;
    if (ingressosTotais > agendamento->capacidade) {
        return False;
} else {
        return True;
    }
}

int lerCpfResponsavel(char cpf[20]){

    Funcionarios* funcionario;
    FILE *fp_funcionario;
    int encontrado;
    char escolha;
    funcionario = (Funcionarios*) malloc(sizeof(Funcionarios));

    do{
        lerCPF(cpf, 20);

        encontrado = 0;

        fp_funcionario = fopen("Funcionarios/funcionarios.dat", "rb");
        if (fp_funcionario == NULL) {
            printf("\n   Nenhum funcionário cadastrado ainda!\n");
            free(funcionario);
            return False;
        }
        
        while (fread(funcionario, sizeof(Funcionarios), 1, fp_funcionario)) {
            if (strcmp(funcionario->cpf, cpf) == 0 && funcionario->status) {
                encontrado=1;
                break;
            }
        }

        fclose(fp_funcionario);

        if(encontrado==0){
            printf("\n   Funcionário não encontrado\n");
            printf("\n   Deseja Continuar? (s/n) ");
            scanf(" %c", &escolha);
            getchar();
            if(escolha=='n'){
                free(funcionario);
                return False;
            }
        }

    }while(encontrado==0);

    free(funcionario);
    return False;
}

int gerarIdAgendamento(void){

    Agendamento temp;
    int maiorID;
    FILE* arqAgendamento;

    maiorID=0;
    arqAgendamento = fopen("Agendamentos/agendamento.dat", "rb");
    if (arqAgendamento != NULL) {
        while (fread(&temp, sizeof(Agendamento),1,arqAgendamento) == 1) {
            if (temp.id > maiorID) {
                maiorID = temp.id;
            }
        }
        fclose(arqAgendamento);
    }

    return maiorID + 1;

}

void listarAgendamentosResponsavel(char cpf[20]){

    FILE *arqAgendamentos, *arqTemp;
    Agendamento temp;

    printf("\n  Lista dos Agendamentos do Responsável Informado:\n");

    arqAgendamentos = fopen("Agendamentos/agendamento.dat", "rb");
    if (arqAgendamentos == NULL) {
        printf("\n   Nenhum agendamento cadastrado ainda!\n");
        return;
    }

    printf("\nID    | Data         | Hora     | Cidade               | Capacidade | Preço   | Ingressos Vendidos | CPF Responsável\n");
    printf("---------------------------------------------------------------------------------------------------------------------------\n");
    while(fread(&temp, sizeof(Agendamento), 1, arqAgendamentos) == 1){
        if(temp.status && strcmp(temp.cpfResponsavel, cpf) == 0){
            printf("%-5d | %-12s | %-8s | %-20s | %-10d | %-9.2f| %-19d| %-15s\n",
                   temp.id, temp.data, temp.horario, temp.cidade,
                   temp.capacidade, temp.precoIngresso,temp.quantIngressosVend, temp.cpfResponsavel);
        }
    }
    fclose(arqAgendamentos);

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacao.h"
#include "../Agendamentos/agendamentos.h"
#include "../Ingressos/ingressos.h"
#include "../Utilitarios/utilitarios.h"
#include "../Funcionarios/funcionarios.h"
#include "../Clientes/clientes.h"

#define True 1
#define False 0

int validarNome(char nome[]) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (isdigit((unsigned char)nome[i]) || ispunct((unsigned char)nome[i])) {
            return 0; // falso
        }
    }
    return 1; // verdadeiro
}


void lerNome(char nome[], int tamanho){

    do {

        printf("\n   Digite seu nome: ");
        fgets(nome, tamanho, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        if(!validarNome(nome)) {
            printf("\n   Nome inválido! Apenas letras e espaços são permitidos.\n");
        }

    } while(!validarNome(nome));

}

//Créditos: GPT-5
int validarEmail(const char email[]) {
    int tamanho = strlen(email);
    if (tamanho < 6) return False; // mínimo razoável

    // precisa conter exatamente um '@'
    int contArroba = 0;
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') contArroba++;
    }
    if (contArroba != 1) return False;

    char *arroba = strchr(email, '@');
    if (arroba == email) return False; // não pode começar com @

    // precisa ter algo antes e depois do '@'
    if (arroba == NULL || strlen(arroba + 1) < 3) return False;

    char *ponto = strrchr(email, '.');
    if (ponto == NULL) return False;      // precisa ter ponto
    if (ponto < arroba) return False;     // ponto precisa vir depois do @
    if (strlen(ponto + 1) < 2) return False; // deve ter algo depois do ponto (.com, .br etc.)

    // não pode ter ponto logo antes ou depois do '@'
    if (*(arroba - 1) == '.' || *(arroba + 1) == '.') return False;

    // verificar caracteres inválidos
    for (int i = 0; email[i] != '\0'; i++) {
        char c = email[i];
        if (!(isalnum(c) || c == '@' || c == '.' || c == '_' || c == '-'))
            return False;
    }

    return True;
}



void lerEmail(char email[], int tamanho){

    do{
        printf("\n   Digite seu Email: ");
        fgets(email, tamanho, stdin);
        email[strcspn(email,"\n")] = '\0';

        if(!validarEmail(email)){
            printf("\n   Email inválido!\n");
        }

    }while(!validarEmail(email));

}

//Créditos: GPT-5
int validarCPF(char cpf[]) {
    char numeros[12];
    int j = 0;

    for (int i = 0; cpf[i] != '\0'; i++) {
        if (isdigit(cpf[i])) {
            numeros[j++] = cpf[i];
        }
    }
    numeros[j] = '\0';
    if (strlen(numeros) != 11)
        return False;

    int iguais = 1;
    for (int i = 1; i < 11; i++) {
        if (numeros[i] != numeros[0]) {
            iguais = 0;
            break;
        }
    }
    if (iguais) return False;

    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (numeros[i] - '0') * (10 - i);
    }

    int resto = soma % 11;
    int digito1 = (resto < 2) ? 0 : 11 - resto;

    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (numeros[i] - '0') * (11 - i);
    }

    resto = soma % 11;
    int digito2 = (resto < 2) ? 0 : 11 - resto;

    if (digito1 == (numeros[9] - '0') && digito2 == (numeros[10] - '0'))
        return True;
    else
        return False;

}

void lerCPF(char cpf[], int tamanho, char usuario){

    int cadastrado = True;

    do{
        printf("\n   Digite seu CPF: ");
        fgets(cpf, tamanho, stdin);
        cpf[strcspn(cpf,"\n")] = '\0';

        if(!validarCPF(cpf)){
            printf("\n   CPF inválido!\n");
        }

        if (usuario == 'F') {
            if (!verificarCPFUnicoFuncionario(cpf)) {
                printf("\n   CPF já cadastrado para outro funcionário!\n");
                cadastrado = True;
            } else {
                cadastrado = False;
            }
        } else if (usuario == 'C') {
            if (!verificarCPFUnicoCliente(cpf)) {
                printf("\n   CPF já cadastrado para outro cliente!\n");
                cadastrado = True;
            } else {
                cadastrado = False;
            }
        } else {
            cadastrado = False;
        }

    }while(!validarCPF(cpf) || cadastrado);

}

int verificarCPFUnicoFuncionario(const char cpf[]) {
    FILE* arqFuncionarios;
    Funcionarios* func;
    func = (Funcionarios*)malloc(sizeof(Funcionarios));


    if (func == NULL) {
        printf("Erro de memória!\n");
        exit(1);
    }
    
    arqFuncionarios = fopen("Funcionarios/funcionarios.dat", "rb");
    if (arqFuncionarios == NULL) {
        printf("\n\n\nERROR!\n\n\n");
        exit(1);
    }
    
    while (fread(func, sizeof(Funcionarios), 1, arqFuncionarios)) {
        if (strcmp(func->cpf, cpf) == 0) {
            fclose(arqFuncionarios);
            free(func);
            return False; // CPF já existe
        }
    }

    fclose(arqFuncionarios);
    free(func);
    return True; // CPF é único
}

int verificarCPFUnicoCliente(const char cpf[]) {
    FILE* arqCliente;
    Cliente* cli;
    cli = (Cliente*)malloc(sizeof(Cliente));


    if (cli == NULL) {
        printf("Erro de memória!\n");
        exit(1);
    }
    
    arqCliente = fopen("Clientes/clientes.dat", "rb");
    if (arqCliente == NULL) {
        printf("\n\n\nERROR!\n\n\n");
        exit(1);
    }
    
    
    while (fread(cli, sizeof(Cliente), 1, arqCliente)) {
        if (strcmp(cli->cpf, cpf) == 0) {
            fclose(arqCliente);
            free(cli);
            return False; // CPF já existente
        }
    }

    fclose(arqCliente);
    free(cli);
    return True; // CPF é único
}

//creditos: GPT-5
int validarData(const char data[]){
    // Verifica tamanho
    if (strlen(data) != 10) return False;

    // Verifica separadores
    if (data[2] != '/' || data[5] != '/') return False;

    // Verifica se os outros caracteres são números
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue; // ignora '/'
        if (!isdigit(data[i])) return False;
    }

    // Extrair dia, mês e ano
    int dia = (data[0]-'0')*10 + (data[1]-'0');
    int mes = (data[3]-'0')*10 + (data[4]-'0');
    int ano = (data[6]-'0')*1000 + (data[7]-'0')*100 + (data[8]-'0')*10 + (data[9]-'0');

    // Verifica mês
    if (mes < 1 || mes > 12) return False;

    // Dias máximos por mês
    int maxDias;
    switch(mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxDias = 31; break;
        case 4: case 6: case 9: case 11:
            maxDias = 30; break;
        case 2:
            // Verifica ano bissexto
            if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
                maxDias = 29;
            else
                maxDias = 28;
            break;
        default:
            return False;
    }

    // Verifica dia
    if (dia < 1 || dia > maxDias) return False;

    return True;
}

void lerData(char data[], int tamanho){

    do{
        printf("\n   Digite a data de nascimento (DD/MM/AAAA): ");
        fgets(data, tamanho, stdin);
        data[strcspn(data,"\n")] = '\0';

        if(!validarData(data)){
            printf("\n   Data inválido!\n");
        }

    }while(!validarData(data));

}

int validarDataEspetaculo(const char data[]){
    // Verifica tamanho
    if (strlen(data) != 10) return False;

    // Verifica separadores
    if (data[2] != '/' || data[5] != '/') return False;

    // Verifica se os outros caracteres são números
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue; // ignora '/'
        if (!isdigit(data[i])) return False;
    }

    // Extrair dia, mês e ano
    int dia = (data[0]-'0')*10 + (data[1]-'0');
    int mes = (data[3]-'0')*10 + (data[4]-'0');
    int ano = (data[6]-'0')*1000 + (data[7]-'0')*100 + (data[8]-'0')*10 + (data[9]-'0');

    if(compararDataComHoje(data) < 0){
        return False;
    }

    // Verifica mês
    if (mes < 1 || mes > 12) return False;

    // Dias máximos por mês
    int maxDias;
    switch(mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxDias = 31; break;
        case 4: case 6: case 9: case 11:
            maxDias = 30; break;
        case 2:
            // Verifica ano bissexto
            if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
                maxDias = 29;
            else
                maxDias = 28;
            break;
        default:
            return False;
    }

    // Verifica dia
    if (dia < 1 || dia > maxDias) return False;

    return True;
}

void lerDataEspetaculo(char data[], int tamanho){

    do{
        printf("\n   Digite a data: ");
        fgets(data, tamanho, stdin);
        data[strcspn(data,"\n")] = '\0';

        if(!validarDataEspetaculo(data)){
            printf("\n   Data inválido!\n");
        }

    }while(!validarDataEspetaculo(data));

}

//créditos: GPT-5
int validarHora(const char hora[]) {
    // Verifica tamanho: deve ser exatamente 5 caracteres (ex: "08:30")
    if (strlen(hora) != 5)
        return 0;

    // Verifica se o terceiro caractere é ':'
    if (hora[2] != ':')
        return 0;

    // Verifica se os outros são dígitos
    if (!isdigit(hora[0]) || !isdigit(hora[1]) ||
        !isdigit(hora[3]) || !isdigit(hora[4]))
        return 0;

    // Converte para inteiros
    int hh = (hora[0] - '0') * 10 + (hora[1] - '0');
    int mm = (hora[3] - '0') * 10 + (hora[4] - '0');

    // Verifica faixas válidas
    if (hh < 0 || hh > 23) return 0;
    if (mm < 0 || mm > 59) return 0;

    return 1; // válido
}

void lerHora(char hora[], int tamanho){

    int ok = 0;

    do{

        printf("\n   Digite o horário: ");
        fgets(hora, tamanho, stdin);
        hora[strcspn(hora,"\n")] = '\0';

        if(validarHora(hora)){
            ok = 1;
        }else{
            printf("\n   Data inválido!\n");
            if (strlen(hora) == (size_t)(tamanho - 1)) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
        }

    }while(ok == 0);

}


void lerCapacidade(int *capacidade){

    int ok;

    do{
        printf("\n   Digite a quantidade de Ingressos disponível: ");
        ok = scanf(" %d", capacidade);

        if(ok != 1){
            printf("Valor Inválido! Digite apenas números inteiros");

            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }

    }while(ok!=1);

}

void lerCidade(char nome[], int tamanho){

    do {

        printf("\n   Digite nome da cidade que será realizado: ");
        fgets(nome, tamanho, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        if(!validarNome(nome)) {
            printf("\n   Nome inválido! Apenas letras e espaços são permitidos.\n");
        }

    } while(!validarNome(nome));

}

void lerPreco(float *preco){

    int ok;
    int c;

    do{
        printf("\n   Digite o preço do ingresso: ");
        ok = scanf(" %f", preco);

        if(ok != 1){
            printf("Valor Inválido! Digite apenas números inteiros");

            while((c = getchar()) != '\n' && c != EOF);
        }else{
            while((c = getchar()) != '\n' && c != EOF);
        }

    }while(ok!=1);

}

int verificarLetraEmString(const char str[]){
    for (int i = 0; str[i] != '\0'; i++){
        if (isalpha(str[i])){
            return False;
        }
    }
    return True;
}

int verificarTamanhoMinimoString(const char str[], int tamanhoMinimo){
    if (strlen(str) < (size_t)tamanhoMinimo){
        return False;
    }
    return True;
}

void lerTelefone(char telefone[], int tamanho) {
    int valido = 0;
    while (!valido) {
        printf("\n   Digite seu telefone: ");
        fgets(telefone, tamanho, stdin);
        telefone[strcspn(telefone, "\n")] = 0;
        valido = verificarLetraEmString(telefone) * verificarTamanhoMinimoString(telefone, 7);
        if (!valido) {
            printf("\nTelefone inválido. Por favor, insira um telefone válido.\n");
        }
    }
}

void lerSalario(char salario[]) {
    int valido = 0;

    do {
        printf("\n   Digite seu salário: ");
        scanf(" %s", salario);
        getchar();

        valido = verificarLetraEmString(salario);

        if (!valido) {
            printf("Salário inválido. Por favor, insira um valor numérico válido.\n");
        }

    } while (!valido);
}


int validarSexo(char sexo[]) {

    for (int i = 0; sexo[i]; i++) {
        sexo[i] = toupper(sexo[i]);
    }

    if (strcmp(sexo, "MASCULINO") == 0 || strcmp(sexo, "FEMININO") == 0 || strcmp(sexo, "M") == 0 || strcmp(sexo, "F") == 0) {
        return 1;
    } else {
        return 0;
    }
}

void lerSexo(char sexo[], int tamanho) {
    int valido;
    valido = 0;
    while (!valido) {
        printf("\n   Digite seu sexo(M/F): ");
        fgets(sexo, tamanho, stdin);
        sexo[strcspn(sexo, "\n")] = 0;
        valido = validarSexo(sexo);
        if (!valido) {
            printf("O sexo só pode ser masculino ou feminino, tente novamente...");
        }
    }

}

void lerEndereco(char endereco[], int tamanho) {
    printf("\n   Digite seu endereço: ");
    fgets(endereco, tamanho, stdin);
    endereco[strcspn(endereco, "\n")] = 0;
}

void lerCargo(char cargo[], int tamanho) {
    printf("\n   Digite seu cargo: ");
    fgets(cargo, tamanho, stdin);
    cargo[strcspn(cargo, "\n")] = 0;
}

void lerSetor(char setor[], int tamanho) {
    printf("\n   Digite seu setor: ");
    fgets(setor, tamanho, stdin);
    setor[strcspn(setor, "\n")] = 0;
}

int validarFormaDePagamento(int pagamento) {
    if (!(pagamento == 1 || pagamento == 2)) {
        return 0;
    } else {
        return 1;
    }
}

void lerFormaDePagamento(int pagamento) {
    int valido;
    valido = 0;
    while (!valido) {
        printf("\n  Forma de pagamento: \n  1 - PIX\n  2 - Dinheiro\n  >> ");
        scanf(" %d", &pagamento);
        getchar();
        valido = validarFormaDePagamento(pagamento);
        if (!valido) {
            printf("\n  Forma de Pagamento Inválida.\n");
        }
    }
    

}

int lerIdEspetaculo(){

    int valido = 0;
    int idEspetaculo;
    FILE* arqAgendamentos;
    Agendamento* agendamento;
    agendamento = (Agendamento*)malloc(sizeof(Agendamento));

    arqAgendamentos = fopen("Agendamentos/agendamento.dat", "rb");
    if (!arqAgendamentos) {
        printf("Erro ao abrir o arquivo de agendamentos.\n");
        return -1;
    }

    while (!valido) {
        printf("\n  Selecione o ID do espetáculo: ");
        scanf(" %d", &idEspetaculo);

        limparBuffer();

        rewind(arqAgendamentos); 

        while (fread(agendamento, sizeof(Agendamento), 1, arqAgendamentos)) {
            if (idEspetaculo == agendamento->id && agendamento->status) {
                valido = 1;
                break;
            }
        }

        if (!valido) {
            printf("\n  ID inválido. Tente novamente.\n");
        }
    }
    fclose(arqAgendamentos);
    free(agendamento);
    return idEspetaculo;
}

void lerNomeEspetaculo(char nomeEspetaculo[], int tamanho){

    do {

        printf("\n   Digite o nome do espetáculo: ");
        fgets(nomeEspetaculo, tamanho, stdin);
        nomeEspetaculo[strcspn(nomeEspetaculo, "\n")] = '\0';

        if(!validarNome(nomeEspetaculo)) {
            printf("\n   Nome do Espetáculo inválido! Apenas letras e espaços são permitidos.\n");
        }

    } while(!validarNome(nomeEspetaculo));

}
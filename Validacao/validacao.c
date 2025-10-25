#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacao.h"

#define True 1
#define False 0

int validarNome(char nome[]){
    int valido = False;

    for (int i = 0; nome[i] != '\0'; i++){

        if (!isalpha(nome[i]) && nome[i] != ' ' && nome[i] != '\n'){
            return False;
        }

        if (isalpha(nome[i])){
            valido = true;
        }

    }

    return valido;

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

    // 1️⃣ Extrair apenas os números (ignora '.' e '-')
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (isdigit(cpf[i])) {
            numeros[j++] = cpf[i];
        }
    }
    numeros[j] = '\0';

    // 2️⃣ Verifica se tem 11 dígitos
    if (strlen(numeros) != 11)
        return False;

    // 3️⃣ Verifica se todos os dígitos são iguais (ex: 111.111.111-11 → inválido)
    int iguais = 1;
    for (int i = 1; i < 11; i++) {
        if (numeros[i] != numeros[0]) {
            iguais = 0;
            break;
        }
    }
    if (iguais) return False;

    // 4️⃣ Cálculo do 1º dígito verificador
    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (numeros[i] - '0') * (10 - i);
    }

    int resto = soma % 11;
    int digito1 = (resto < 2) ? 0 : 11 - resto;

    // 5️⃣ Cálculo do 2º dígito verificador
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (numeros[i] - '0') * (11 - i);
    }

    resto = soma % 11;
    int digito2 = (resto < 2) ? 0 : 11 - resto;

    // 6️⃣ Verifica se os dígitos calculados batem com os do CPF
    if (digito1 == (numeros[9] - '0') && digito2 == (numeros[10] - '0'))
        return True;
    else
        return False;

}

void lerCPF(char cpf[], int tamanho){

    do{
        printf("\n   Digite seu CPF: ");
        fgets(cpf, tamanho, stdin);
        cpf[strcspn(cpf,"\n")] = '\0';

        if(!validarCPF(cpf)){
            printf("\n   CPF inválido!\n");
        }

    }while(!validarCPF(cpf));

}

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
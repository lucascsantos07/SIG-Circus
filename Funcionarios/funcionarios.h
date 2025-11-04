#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

#include <stdio.h>
// Assinatura das funcoes do modulo funcionarios

typedef struct funcionarios Funcionarios;

struct funcionarios {
    char nome[50];
    char dataNascimento[20];
    char email[50];
    char cpf[20];
    char sexo[12];
    char endereco[100];
    char telefone[15];
    char salario[20];
    char cargo[30];
    int status;
};

char menuFuncionarios(void);
void telaCadastroFuncionario(void);
void listarDadosFuncionario(void);
void editarDadosFuncionario(void);
void deletarFuncionarioPermanentemente(void);
void excluirFuncionario(void);
void exibirModuloFuncionarios(void);

Funcionarios* ColetarDadosFuncionario(void);
void ConfirmarCadastroFuncionario(Funcionarios* funcionarios);
void ExibirFuncionario(Funcionarios* funcionarios);
int escolherDadoFunc();
void alterarDadoFunc(int opcao, Funcionarios* funcionario, FILE* arqFuncionarios);


#endif
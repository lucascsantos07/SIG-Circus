#ifndef RELATORIO_H
#define RELATORIO_H

#include "../Agendamentos/agendamentos.h"
#include "../Clientes/clientes.h"
#include "../Funcionarios/funcionarios.h"

typedef struct Ag {
    Agendamento ag;
    struct Ag* prox;
} Ag;


void exibirModuloRelatorios(void);
void exibirRelatoriosAgendamentos(void);
void exibirRelatoriosClientes(void);
void exibirRelatoriosFuncionarios(void);
void exibirRelatoriosIngressos(void);
void menuRelatorios(void);
void menuRelatoriosAgendamentos(void);
void menuRelatoriosClientes(void);
void menuRelatoriosFuncionarios(void);
void menuRelatoriosIngressos(void);
void relatorioAgendamentos(int status);
void relatorioClientes(int status);
void relatorioFuncionarios(int status);
void relatorioIngressos(int status);
void filtrarAgendamentosPorCidade(void);
void filtrarClientesPorNome(void);
void filtrarFuncionariosPorNome(void);
void filtrarIngressosPorEspetaculo(void);
int buscarAgendamentosPorCidade(const char* cidadeBuscada);
int buscarClientesPorNome(const char* nomeBuscado);
int buscarFuncionariosPorNome(const char* nomeBuscado);
int buscarIngressosPorEspetaculo(const int* EspetaculoID);
void inserirOrdenado(Ag** lista, Agendamento* novoAg);
int dataParaInt(const char* data);
void lerClientes(const char* nomeArquivo, Cliente** lista);
Cliente* encontrarClientePorCPF(char cpfParametro[]);
Agendamento* encontrarAgendamentoPorID(int idEspParametro);
Funcionarios* encontrarFuncionariosPorCpf(char cpfParametro[]);

#endif

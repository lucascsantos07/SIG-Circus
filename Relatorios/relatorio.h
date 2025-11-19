#ifndef RELATORIO_H
#define RELATORIO_H

void exibirModuloRelatorios(void);
void exibirRelatoriosAgendamentos(void);
void exibirRelatoriosClientes(void);
void exibirRelatoriosFuncionarios(void);
void exibirRelatoriosIngressos(void);
void menuRelatorios(void);
void menuRelatoriosAgendamentos(void);
void menuRelatoriosClientes(void);
void menuRelarotiosFuncionarios(void);
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
Cliente* encontrarClientePorCPF(char* cpfParametro[]);

#endif

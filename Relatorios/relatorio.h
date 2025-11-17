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
int buscarAgendamentosPorCidade(const char* cidadeBuscada);
int buscarClientesPorNome(const char* nomeBuscado);

#endif

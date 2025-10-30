#ifndef INGRESSOS_H
#define INGRESSOS_H

#include <stdio.h>
// Assinatura das funcoes do modulo vendas de ingressos


typedef struct ingressos Ingressos;

struct ingressos {
    char cpfCliente[20];
    int quantidadeIngressos, idEspetaculo, id, status;
    float valorTotal;
    char data[12], cpfResponsavel[20], cidade[50], horario[7], dataLida[12], cpfLido[20];
    int capacidadeMax;
    float precoIngresso;
    int formaPag;
};

void menuVendasIngressos(void);
void telaCadastroVendaIngresso(void);
void consultarVendaIngresso(void);
void reembolsarVendaIngresso(void);
void deletarIngressoPermanentemente(void);
void exibirModuloVendasIngressos(void);

Ingressos* ColetarDadosIngressos(void);
void ExibirIngresso(Ingressos* ingresso);
void ConfirmarCadastroIngresso(Ingressos* ingresso);
void SalvarIngresso(FILE* fp_ingressos, Ingressos* ingresso);
void ExibirTodosAgendamentos(void);
int IngressoMaiorID(void);


#endif
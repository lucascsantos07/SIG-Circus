#include <stdio.h>

// Assinaturas da Funções do Clientes

void menuCliente(void);
void telaCadastroCliente(void);
void listarDadosCliente(void);
void editarDadoscliente(void);
void excluirContacliente(void);
void exibirModuloClientes(void);

typedef struct cliente Cliente;

struct cliente{
    char nome[50];
    char dataNascimento[20];
    char email[100];
    char cpf[20];
};

Cliente coletarDadosCliente(void);
void exibirCliente(Cliente *cliente);
void confirmacaoCadastroCliente(Cliente *cliente);
void salvarCliente(FILE *arqCliente, Cliente *cliente);
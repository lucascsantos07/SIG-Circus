#include <stdio.h>

// Assinaturas da Funções do Clientes

char menuCliente(void);
void telaCadastroCliente(void);
void listarDadosCliente(void);
void editarDadoscliente(void);
void excluirContacliente(void);
void exibirModuloClientes(void);

typedef struct cliente Cliente;

struct cliente{
    char nome[50];
    char dataNascimento[20];
    char email[50];
    char cpf[20];
    int status;
};

Cliente* coletarDadosCliente(void);
void exibirCliente(Cliente *cliente);
void confirmacaoCadastroCliente(Cliente *cliente);
void salvarCliente(FILE *arqCliente, Cliente *cliente);
void excluirClientePermanente(void);
void alterarDado(char opcao, Cliente* cliente, FILE* arqCliente);
char escolherDado(void);
int verificarTemIngresso(char cpf[]);
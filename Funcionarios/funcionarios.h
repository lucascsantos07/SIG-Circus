// Assinatura das funcoes do modulo funcionarios

typedef struct funcionarios Funcionarios;

struct funcionarios {
    char nome[50];
    char dataNascimento[20];
    char email[100];
    char cpf[20];
    char sexo[12];
    char endereco[100];
    char telefone[15];
    char salario[10];
    char cargo[30];
    char setor[30];
    char cpf_busca[20];
    char novoNome[50];
    char novaDataNascimento[20];
    char novoEmail[100];
    char novoCpf[20];
    char novoSexo;
    char novoendereco[100];
    char novoTelefone[15];
    char novoSalario[25];
    char novoCargo[30];
    char novoSetor[30];
};

void menuFuncionarios(void);
void telaCadastroFuncionario(void);
void listarDadosFuncionario(void);
void editarDadosFuncionario(void);
void excluirFuncionario(void);
void exibirModuloFuncionarios(void);
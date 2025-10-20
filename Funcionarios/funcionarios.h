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
    char salario[20];
    char cargo[30];
    char setor[30];
    int id;
    int status;
};

void menuFuncionarios(void);
void telaCadastroFuncionario(void);
void listarDadosFuncionario(void);
void editarDadosFuncionario(void);
void excluirFuncionario(void);
void exibirModuloFuncionarios(void);

Funcionarios* ColetarDadosFuncionario(void);
void ConfirmarCadastroFuncionario(Funcionarios* funcionarios);
void ExibirFuncionario(Funcionarios* funcionarios);
void SalvarFuncionario(FILE* fp_funcionarios, Funcionarios* funcionarios);
int FuncionarioMaiorID(void);
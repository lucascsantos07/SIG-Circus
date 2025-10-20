// Assinaturas das Funções de Agendamentos

void menuAgendamentos(void);
void telaCadastroAgendamento(void);
void alterarAgendamento(void);
void excluirAgendamento(void);
void consultarAgendamento(void);
void listarTodosAgendamentos(void);
void exibirModuloAgendamentos(void);

typedef struct agendamento Agendamento;

struct agendamento{
    char data[12];
    char cpfResponsavel[20];
    char cidade[50];
    char horario[7];
    int capacidade;
    float precoIngresso;
    int id;
    int status;
};

Agendamento* coletarDadosAgendamentos(void);
void confirmarCadastroAgendamento(Agendamento *agendamento);
void exibirAgendamento(Agendamento* agendamento);

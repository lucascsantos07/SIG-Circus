// Assinaturas das Funções de Agendamentos

void menuAgendamentos(void);
void telaCadastroAgendamento(void);
void alterarAgendamento(void);
void cancelarAgendamento(void);
void consultarAgendamento(void);
void excluirPermanenteAgendamento(void);
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
    int quantIngressosVend;
};

Agendamento* coletarDadosAgendamentos(void);
void confirmarCadastroAgendamento(Agendamento *agendamento);
void exibirAgendamento(Agendamento* agendamento);
int compararDataComHoje(const char *dataAgendamento);
int validarQuantidadeIngressos(Agendamento* agendamento, int quantidadeSolicitada);
int lerCpfResponsavel(char cpf[20]);
int gerarIdAgendamento(void);
void listarAgendamentosResponsavel(char cpf[20]);

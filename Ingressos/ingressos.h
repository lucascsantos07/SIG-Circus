// Assinatura das funcoes do modulo vendas de ingressos

typedef struct ingressos Ingressos;

struct ingressos {
    char cpfCliente[20];
    int quantidadeIngressos, escolha, idEspetaculo, id;
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
void exibirModuloVendasIngressos(void);
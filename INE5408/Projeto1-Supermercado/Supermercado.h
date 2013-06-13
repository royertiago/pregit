/* Supermercado.h - Controla um supermercado.
 *
 * Os caixas adicionados serão considerados propriedade deste supermercado, mas não seus ouvintes.
 * O nome é copiado pelo supermercado. */

#include "CabecaDeLista.h"
class Guiche;
class Escutador;
class Caixa;

#include <random>

class Supermercado {
public:
    /* mediaTempoClientes é a média do tempo de chegada de clientes no supermercado.
     * O tempo de chegada do próximo cliente seguirá uma distribuição de
     * Poisson cuja média será mediaTempoClientes.
     *
     * Por simplicidade, o primeiro cliente entrará no supermercado exatamente
     * mediaTempoClientes após o início da simulação.
     *
     * tamanhoFila é o mínimo de clientes que pode haver em cada fila antes de ser
     * chamado um caixa temporário para trabalhar.
     * */
    Supermercado( const char* nome, double mediaTempoClientes, int tamanhoFila );
    ~Supermercado();

    // Adiciona um novo caixa e acopla todos os ouvintes do supermercado em seu guchê.
    void adicionarCaixa( Caixa* );

    // Adiciona um ouvinte ao supermercado e a todos os guichês do supermercado.
    void adicionarOuvinte( Escutador* );

    // Executa a simulação. O objeto pode não estar "usável" após ela.
    void simular( double horas );

    // Função usada para gerar as estatísticas.
    const CabecaDeLista<Guiche>& obterGuiches() const;

    const char* obterNome() const;
private:
    char* _nome;
    CabecaDeLista<Guiche> _guiches;
    CabecaDeLista<Escutador> _ouvintes;

    // Tempo de chegada do próximo cliente.
    int _tempoCliente;

    const int _tamanhoFila;

    // Distribuição usada na geração de números aleatórios.
    std::poisson_distribution<int> _distribution;

    // Adiciona um novo cliente, gera um novo tempoCliente e dispara os eventos necessários.
    void adicionarCliente();
};

inline const char* Supermercado::obterNome() const {
    return _nome;
}

inline const CabecaDeLista<Guiche>& Supermercado::obterGuiches() const {
    return _guiches;
}

/* Estatístico.h
 * Classe que escuta eventos durante a execução do programa e calcula as estatísticas.
 *
 * Por lucro líquido, entenda-se "lucro bruto subtraído do salário dos caixas".
 * Por lucro bruto, entenda-se "soma do lucro de cada produto". */

#include "Escutador.h"

class eClienteAtendido;
class eClienteAdicionado;
class eCarrinhoAbandonado;
class eCaixaContratado;
class Supermercado;

#include "CabecaDeLista.h"

#include <iostream>
using std::ostream;

// Estatísticas de um caixa.
struct Estatisticas;

class Estatistico: public Escutador {
public:
    Estatistico( int qtdeCaixas ); //Quantidade de caixas a serem controlados pelo estatístico.

    virtual void ouvirAtendimento( eClienteAtendido );
    virtual void ouvirAdicionamento( eClienteAdicionado );
    virtual void ouvirAbandono( eCarrinhoAbandonado );
    virtual void ouvirContratacao( eCaixaContratado );

    /* Imprime as estatísticas para os supermercado passado na saída passada.
     * horas é a quantidade de horas que devemos pagar aos funcionários. */
    void gerarEstatisticas( Supermercado*, double horas, ostream& );

private:
    double prejuizoAbandono;
    int qtdeAbandonos;
    CabecaDeLista<Estatisticas> _estatisticas;
};

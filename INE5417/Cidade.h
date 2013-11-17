/* A cidade é um local de batalha onde são feitos os balancamentos
 * e gerenciamento de tropas.
 *
 * Cada cidade estará em exatamente um dos seguintes estados: 
 * "protegida", "sob ataque" e "sob cerco". Toda cidade inicia
 * protegida – este é o estado padrão. Ao sofrerem ataques, as cidades
 * ficam "sob ataque"; após cinco rodadas sob ataque, elas
 * ficam sob cerco, e, neste caso, a cidade não gera recursos.
 *
 * Devido à limitações da linguagem, como a estrada possui referência
 * constante para cidades, as estradas só podem ser criadas após
 * a criação das cidades, por isso a necessidade de adicionarDestino.
 */

#ifndef CIDADE_H
#define CIDADE_H

#include <list>
#include <unordered_map>
using std::list;
using std::unordered_map;

#include "LocalDeBatalha.h"
class Estrada;
class Jogador;
class Exercito;
class ExercitoParado;

class Cidade : public LocalDeBatalha {
private:
    /* Como precisamos saber a qual estrada adicionar determinada
     * movimentação de tropas, precisamos um mapeamento entre
     * as cidades vizinhas e quais estradas levam a elas.
     *
     * Este mapeamento é a única ligação entre a cidade e seus
     * vizinhos. */
    unordered_map< Cidade*, Estrada* > destinos;

    /* A ordem de envio é constituída de um número natural, que 
     * corresponderá à quantidade de soldados enviados, e uma cidade
     * de destino. É convertida em exercitosMovendo no passar do turno,
     * se a cidade de origem não estiver sob ataque, e se a
     * movimentação não conter mais soldados do que a cidade de origem.
     * Os soldados enviados são removidos da cidade que originou a
     * movimentação. */
    struct OrdemDeEnvio {
    public:
        Jogador* jogador;
        Cidade* destino;
        int quantidade;
    };
    list< OrdemDeEnvio > ordens;

    /* Lista de exércitos. Garantiremos que não há duplicações
     * (dois exércitos do mesmo jogador). */
    list< ExercitoParado* > exercito;

    /* Quantidade de soldados produzida na rodada.
     * Por padrão, cada cidade ganha 10 soldados no passar do turno.
     * Ver alterarBalanceamento(int). */
    int producaoSoldados = 10;

    /* Nome usado para identificar a cidade de fora do mapa.
     * Não é realmente usada dentro do jogo. */
    string nome;

    /* Dono da cidade. Começa como nulo indicando que a cidade
     * "é de Gaia", no contexto de Age of Empires. */
    Jogador* dono = 0;

    // Quantidade de turnos antes de a cidade ficar sob cerco.
    static const int TurnosCerco = 5;
    enum { Protegida = 0,
           RecemConquistada = 1,
           SobAtaque = 2,
           SobCerco = TurnosCerco + 3
    };
    int estado = Protegida;
    /* Explica-se: A variável estado não codifica apenas o estado da
     * cidade, mas também a quantidade de turnos em que ela ficou 
     * sob ataque. Desta forma, pode-se fazer o teste
     *  estado <= SobCerco
     * para saber se a cidade não está sob cerco, e
     *  ++estado
     * para adicionar um turno ao cerco. */

    /* Estas duas linhas se referem à construção do grafo no qual
     * rodará o jogo. Como as estradas exigem que a cidade já esteja
     * construida ao ser criada (a menos que usemos código capaz de
     * fazer o Melga surtar simplesmente de estar na mesma sala
     * que um computador que entrou em contato com o código), 
     * o mapa criará as estradas após a criação das cidades e usará
     * esta função para registrar as conexões. */
    void adicionarDestino( Estrada* );
    friend class Mapa;

public:

    Cidade() = default;
    Cidade( string nome );
    /* Devido ao fato de as estradas exigirem cidades prontas para
     * serem construídas, não foi provido um construtor mais elaborado
     * para as cidades, já que muita informação será adicionada
     * após a construção. */

    /* Insere uma ordem de envio para o passado para a cidade passada
     * com a quantidade de tropas especificada. Esta ordem de envio
     * será convertida para um exercitoMovendo apenas se a cidade não
     * estiver em batalha e a quantidade escolhida for suficiente.
     * (No último caso, a quantidade enviada será a máxima possível).*/
    void criarOrdemDeEnvio( Jogador*, Cidade* destino, int tropas);
    
    /* Adiciona um exército nesta cidade.
     * A cidade passa a ser a "dona" do exército (responsável por
     * desalocar o ponteiro quando não for mais usado). */
    void adicionarExercito( Exercito* );
    
    /* Altera o balanceamento desta cidade, para produzir a quantidade
     * especificada de soldados no passar do turno.
     *
     * A produção de tecnologia é 10 - (produção de soldados)
     * (ou seja, se soldados = 3, tecnologia = 7.)
     *
     * Suporemos que soldados é um valor entre 0 e 10. */
    void alterarBalanceamento( int soldados );

    /* Efetua as batalhas de acordo com a seção de batalhas
     * no documento de regras. */
    void batalhar();

    /* Converte todas as ordens de envio criadas pelo método
     * criarOrdemDeEnvio( Jogador*, Cidade*, int ) em movimentações
     * de tropas e adiciona-as às estradas corretas.
     *
     * Esta ação é ignorada se a cidade estiver sob ataque.*/
    void deslocamentoDeTropas();

    /* Gera os exéricitos correspondentes desta cidade e atualiza
     * o contador de tecnologia para o dono.
     *
     * Ambas as ações são ignoradas se o dono for nulo ou se
     * a cidade for recém-conquistada. */
    void passagemDeTurno();
};

#endif // Cidade.h

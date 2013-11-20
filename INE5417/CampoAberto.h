/* Subdivisão de uma estrada.
 *
 * Para maiores informações sobre o deslocamento de tropas dentro de
 * um campo aberto, ver MovimentacaoDeTropas.txt. */

#ifndef CAMPO_ABERTO_H
#define CAMPO_ABERTO_H

#include <list>
using std::list;

#include "LocalDeBatalha.h"
class ExercitoMovendo;
class Cidade;

class CampoAberto : public LocalDeBatalha {

    enum { TransitoLivre, EmBatalha } estado;

    // Nulos por padrão para poder declarar o construtor como padrão
    Cidade* const cidadeEsquerda = 0;
    Cidade* const cidadeDireita = 0;
    CampoAberto* campoEsquerda;
    CampoAberto* campoDireita;
    list< ExercitoMovendo* > exercitosEsquerda;
    list< ExercitoMovendo* > exercitosDireita;

    /* No deslocamento de tropas, caso hajam dois times com mesmo
     * número de soldados um de frente para o outro, devido à estrutura
     * do deslocamento interno ser em duas etapas, não há um meio
     * direto de decidir quem será deslocado. A prioridade serve para
     * fazer esta decisão: é deslocado quem está num campo aberto de
     * maior prioridade.
     *
     * De acordo com as regras do jogo, esta decisão deve ser feita
     * lançando uma moeda. Este lançamento pode ser simulado alterando
     * o valor da prioridade de forma aleatória entre as rodadas. */
    int prioridade;

    // Para alterar a prioridade
    friend class ContadorDeGeiger;

    // PAra alterar o campoEsquerda e campoDireita após criação
    friend class Estrada;
public:

    CampoAberto() = default;
    CampoAberto( const CampoAberto& ) = default;
    ~CampoAberto() = default;
    
    /* Cria um campo aberto com as cidades especificadas.
     * Este construtor não determina os campos à esquerda nem à direita
     * pois eles serão criados posteriormente pela estrada. */
    CampoAberto( Cidade* esquerda, Cidade* direita );

    /* Adiciona o exéricito na lista correspondente.
     * Assumiremos que o exército possui como destino uma das cidades,
     * à esquerda ou direita. */
    void adicionarExercito( ExercitoMovendo* );

    /* Efetua a batalha com todos os exéricitos que estão neste campo.
     * Note que batalha e movimentação não ocorrem simultaneamente;
     * controlar esta exclusão mútua é responsabilidade do próprio
     * campo aberto. */
    virtual void efetuarBatalha();

    /* Efetua movimentação terminal.
     * A movimentação terminal é a transferência de exércitos que estão
     * no último campo aberto antes de uma cidade para seu destino.
     * Corresponde à primeira fase de deslocamento de tropas. */
    void movimentacaoTerminal();

    /* Efetua movimentação interna para a esquerda.
     * É deslocar todas as tropas deste campo aberto para
     * o campo aberto à esquerda deste. Corresponde à segunda fase de
     * deslocamento de tropas. */
    void movimentacaoEsquerda();

    /* Efetua movimentação interna para a direita.
     * É deslocar todas as tropas deste campo aberto para
     * o campo aberto à direita deste. Corresponde à terceira fase de
     * deslocamento de tropas. */
    void movimentacaoDireita();

    /* No deslocamento de tropas, existe a possibilidade de haver
     * choque de exéricitos; isto é, dois exércitos de dimes diferentes
     * de frente um para o outro mas em campos abertos diferentes.
     * Para que não ocorra uma idiotice de os exércitos simplesmente
     * trocarem de lugar, fica estabelecido que, neste caso, o time
     * com o maior exéricito (em quantidade de soldados) avança, e
     * o outro fica parado. (Caso as quantidades sejam as mesmas,
     * uma moeda é lançada; ver prioridade.)
     *
     * Dado um time, este método conta a quantidade de soldados que
     * existem em times inimigos a este. */
    int enumerarInimigos( Time* );

protected:
    /* Atualiza o estado atual de acordo com os exércitos nas listas.
     * Adicionalmente, qualquer exército que não possua soldados
     * é removido. */
    void atualizarEstado();
};

#endif

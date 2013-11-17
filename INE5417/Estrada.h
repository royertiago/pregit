/* A estrada é o espaço entre duas cidades que é utilizado para o
 * deslocamento de tropas. Cada estrada é composta de vários campos
 * abertos em sequência, nos quais podem haver batalhas entre tropas
 * em trânsito. Movimentações de tropas deslocam-se um campo aberto
 * por turno, até chegar à cidade de destino.
 *
 * Embora esteja explicitado um início e fim na estrada, ela pode
 * ser percorrida nos dois sentidos; isto é apenas para facilitar
 * a localização dos campos abertos. O primeiro é o mais próximo
 * do início, e o último é o mais próximo do fim.
 */

#ifndef ESTRADA_H
#define ESTRADA_H

class Cidade;
class ExercitoMovendo;
#include "CampoAberto.h"

class Estrada {
private:
    CampoAberto* const campos;

public:
    Estrada() = default;
    ~Estrada(); // desalocar listaDeCampos

    Cidade * const esquerda = 0;
    Cidade * const direita = 0;
    const int comprimento; // Quantos campos abertos existem

    Estrada( Cidade* esquerda, Cidade* direita, int comprimento );

    /* Insere o exéricitoMovendo no campo aberto correspondente
     * (de acordo com seu destino). */
    void adicionarExercito( ExercitoMovendo* );

    /* Desloca todos os exércitos que estão em campos finais da estrada
     * para a cidade de destino correspondente.
     *
     * Nas regras, esta etapa corresponde à etapa "Agrupamento de
     * exércitos". */
    void movimentacaoTerminal();

    /* Desloca todas as tropas que não estavam em batalha para
     * as cidades seguintes. 
     *
     * Nas regras, esta etapa corresponde à etapa "Deslocamento
     * de Tropas".*/
    void movimentacaoInterna();

    /* Propaga a chamada aos campos abertos internos. */
    void batalhar();
};


#endif // Estrada.h

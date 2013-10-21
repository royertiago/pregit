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
#include "CampoAberto.h"

#include <list>
#include <utility>

class Estrada {
private:
    Cidade * inicio;
    Cidade * fim;
    list< std::pair< CampoAberto, list< MovimentacaoDeTropas > > > 
            campos;
    list< OrdemDeEnvio > ordens;
public:
    Estrada();

    /* Adiciona uma movimentação de tropas ao primeiro campo aberto
     * da caminhada. */
    void adicionarMovimentacaoDeTropas( MovimentacaoDeTropas );

    /* Desloca todas as tropas que não estavam em batalha para
     * as cidades seguintes. */
    void deslocarTropas();

    /* Desloca todos os exércitos que estão em campos finais da estrada
     * para a cidade de destino correspondente. */
    void agruparExercitos();
};


#endif // Estrada.h

/* A cidade é um campo de batalha onde são feitos os balanceamentos
 * e gerenciamento de tropas.
 */

#ifndef CIDADE_H
#define CIDADE_H

#include "CampoDeBatalha.h"

class Cidade : public CampoDeBatalha {
public:
    void mesclarMovimentacaoDeTropas( MovimentacaoDeTropas m );

    void alterarBalanceamento( int quantidade );
    
    void gerarOrdemDeEnvio( Jogador* ordenador, Cidade* destino,
            int quantidade );


};

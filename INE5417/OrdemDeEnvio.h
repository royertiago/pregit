/* A ordem de envio é constituída de um número natural, que
 * corresponderá à quantidade de soldados enviados, e uma cidade de
 * destino. É convertida numa movimentação de tropas no passar do 
 * turno, se a cidade de origem não estiver sob ataque, e se a
 * movimentação não conter mais soldados do que a cidade de origem.
 * Os soldados enviados são removidos da cidade que originou a
 * movimentação.
 */

#ifndef ORDEM_DE_ENVIO_H
#define ORDEM_DE_ENVIO_H

#include "MovimentacaoDeTropas.h"

class Cidade;

class OrdemDeEnvio {
public:
    OrdemDeEnvio( Cidade*, int, Exercito* );

    // Cidade de destino da ordem de envio.
    const Cidade* const destino;

    // Quantidade de tropas que irão na movimentação de tropas.
    const int quantidade;

    // Exército do qual serão subtraídas as tropas.
    Exercito* const alvo;
};
#endif // OrdemDeEnvio.h

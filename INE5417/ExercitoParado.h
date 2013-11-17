/* Um ExercitoParado é um exéricito que possui a capacidade de entrar
 * em movimento (gerar um ExercitoMovendo a partir de parte de si).
 */

#ifndef EXERCITO_PARADO_H
#define EXERCITO_PARADO_H

#include "Exercito.h"
class ExercitoMovendo;

class ExercitoParado : public Exercito {
public:
    using Exercito::Exercito;

    /* Gera um ExercitoMovendo com o referido destino,
     * com a quantidade de tropas passadas.
     * Este total é deduzido da quantidade de tropas deste exército.
     * A responsabilidade de deletar o ponteiro é da função chamadora. 
     */
    ExercitoMovendo* moverTropas( int tropas, const Cidade* destino );
};
#endif // ExercitoMovendo.h

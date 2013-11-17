/* Um exercitoMovendo, além de fazer tudo o que um exército faz,
 * possui, como atributo adicional, sua cidade de destino.
 *
 * Exércitos parados podem gerar exércitos em movimento. */

#ifndef EXERCITO_MOVENDO_H
#define EXERCITO_MOVENDO_H

class Cidade;
#include "Exercito.h"

class ExercitoMovendo : public Exercito {
public:
    const Cidade * const destino = 0;

    ExercitoMovendo() = default;
    ExercitoMovendo( const ExercitoMovendo& ) = default;
    ~ExercitoMovendo() = delete;

    // Cria um exército de acordo com os parâmetros passados.
    ExercitoMovendo( int quantidade, Jogador* dono, 
            const Cidade* destino );

    // Copia os dados do exército passado.
    ExercitoMovendo( const ExercitoMovendo& );
};

#endif // EXERCITOMOVENDO_H
